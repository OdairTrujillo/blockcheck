#include <QtWidgets>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

#include "renderdictum.h"
#include "../core/dbhandler.h"
#include "../userlib/bcnamespace.h"

RenderDictumForm::RenderDictumForm(QStringList inspectionData, QStringList dictumData, QList<QStringList> dictumReqsData, QDialog *parent) :
    QDialog(parent)
{
    setupUi(this);

    connect(printDictumButton, SIGNAL(clicked()),
            this, SLOT(printDictum()));

    dictumNumber=dictumData.at(1);

    QList<QStringList> designersData, designers, requirementsData, uses;
    QStringList designerIds, designerMps, reqsApply, reqsMeets, reqsNoMeets, inspectionDesignersIds, inspector;
    QStringList useIds, useNames;
    QString useSName("&nbsp;");

    if (!DbHandler::getDesigners(designersData, "designer_id")) {
        qDebug() << QString("DbHandler::getDesigners ha devuelto false al tratar de obtener los diseñadores").toUtf8();
        designersData.append(QStringList("Sin Datos"));
    }

    if (!DbHandler::getInspectionDesigners(inspectionData.at(0), inspectionDesignersIds)) {
        qDebug() << QString("DbHandler::getInspectionDesigners ha devuelto false al tratar de obtener los diseñadores").toUtf8();
        inspectionDesignersIds.append("Sin Datos");
    }
    else {
        int index;
        for (int i=0; i<inspectionDesignersIds.size();i++) {
            index=designersData.at(0).indexOf(inspectionDesignersIds.at(i));
            designerIds.append(designersData.at(1).at(index));
            designerMps.append(designersData.at(2).at(index));
        }
        designers.append(designerIds);
        designers.append(designerMps);
    }

    if (!DbHandler::getRequirements(inspectionData.at(1), requirementsData)) {
        qDebug() << "DbHandler::getRequirements ha devuelto false al tratar de obtener los requerimientos";
        requirementsData.append(QStringList("Sin Datos"));
    }

    if (!DbHandler::getInspector(inspectionData.at(0), inspector)) {
        qDebug() << "DbHandler::getInspector ha devuelto false al tratar de obtener el inspector asociado";
        inspector.append("Sin Datos");
    }


    QList<QStringList> usesData;
    if (!DbHandler::getUses(usesData)) {
        qDebug() << "DbHandler::getUses ha devuelto false al tratar de obtener los usos";
    }

    // boque para el marcado de tipos de instalación
    QList<QStringList> dictumUseData;
    if (!DbHandler::getDictumUses(dictumData.at(0), dictumUseData)) {
        qDebug() << "DbHandler::getDictumUses ha devuelto false al tratar de obtener los usos del dictamen";
        dictumUseData.append(QStringList("Sin Datos"));
    } else {
        int index;
        for (int i=0; i<dictumUseData.at(0).size(); i++) {
            index=usesData.at(0).indexOf(dictumUseData.at(0).at(i));
            useIds.append(usesData.at(0).at(index));
            useNames.append(usesData.at(1).at(index));
            if (usesData.at(1).at(index)=="Especiales")
                useSName=dictumUseData.at(1).at(i);
        }
        uses.append(useIds);
        uses.append(useNames);
    }

    // boque para el marcado de procesos de dictamen
    QStringList dictumProcIds;
    if (!DbHandler::getDictumProcs(dictumData.at(0), dictumProcIds))
        qDebug() << "DbHandler::getDictumProcs ha devuleto false al tratar de obtener los procesos involucrados.";

    // TODO: entregar el qlist<qstringlist> de diseñadores seleccionados desde el dbhandler, también para los otros módulos

    // Se obtiene la ruta actual de trabajo
    QString currDir;
    currDir=QDir::currentPath();
    // Si es en linux debe agregarse file://
#ifdef Q_OS_LINUX
    currDir="file://" + QDir::currentPath();
#endif

    QStringList extraData;
    QString fileName, htmlString;
    QFile file;

    switch (inspectionData.at(1).toInt()) {

    // NOTE: BLOQUE PARA USO GENERACION
    case BcProcs::Generacion:
        // Se obtienen los datos extra
        if (!DbHandler::getExtraData(dictumData.at(0), inspectionData.at(1), extraData))
            qDebug() << trUtf8("DbHandler::getExtraData(), ha devulto false al tratar de obtener "
                               "datos extra, se cerrará el programa");

        fileName = QDir::currentPath() + "/templates/gen_dictum_template.html";
        file.setFileName(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, trUtf8("Error Abriendo Plantilla"),
                                 trUtf8("No se puedo abrir '%1'").arg(fileName));
        } else {
            // En este punto se empieza a preparar el html, se generan las colmnas
            QTextStream stream(&file);
            htmlString.clear();
            htmlString = stream.readAll();
            // Deben llenarse de guiones bajos que indican que no están chequeados
            for (int i=0; i<requirementsData.at(0).size();i++) {
                reqsApply.append("_");
                reqsMeets.append("_");
                reqsNoMeets.append("_");
            }

            // Se recorren los ids para chequear lo que aplica, cumple o no cumple reemplazando el _ con una X
            int index;
            for (int i=0; i<dictumReqsData.at(0).size();i++) {
                // indexOf me entrega la posición en la que está el id del documento, con esa posición
                // reemplazo el string vacío por el nombre del documento
                index=requirementsData.at(0).indexOf(dictumReqsData.at(0).at(i));
                if (index >=0) { // para prevenir el -1 al no encontrar el Id
                    reqsApply.replace(index, "X");
                    if (dictumReqsData.at(1).at(i) == "X")
                        reqsMeets.replace(index, "X"); // Cumple
                    else
                        reqsNoMeets.replace(index, "X"); // No cumple
                }

            }

            // Es necesario añadir las 3 columnas de aplica, cumple, no cumple
            requirementsData.append(reqsApply);
            requirementsData.append(reqsMeets);
            requirementsData.append(reqsNoMeets);

            QString htmlReqRows; // En este se acumularán las filas
            // Teniendo los requerimientos completos y debidamente marcados, se procede a generar las filas de requerimientos
            for (int i=0; i<requirementsData.at(0).size();i++) {
                // Se parte de un string nuevo en cada fila
                QString htmlReqRow = QString("<tr>"
                                             "<td style=\"text-align: center\">%1</td>"
                                             "<td>%2</td>"
                                             "<td style=\"text-align: center\">%3</td>"
                                             "<td style=\"text-align: center\">%4</td>"
                                             "<td style=\"text-align: center\">%5</td>"
                                             "</tr>")
                        .arg(QString::number(i+1))
                        .arg(requirementsData.at(1).at(i))
                        .arg(requirementsData.at(2).at(i))
                        .arg(requirementsData.at(3).at(i))
                        .arg(requirementsData.at(4).at(i));

                // Se añaden no en lista sino en cadena continua ya que es un htmlReqRows es un QString no un QStringList
                htmlReqRows.append(htmlReqRow);
            }

            htmlString.replace("_dynamicReqRows", htmlReqRows);

            htmlString.replace("_lugarFechaExp", "Bogot&aacute;, D.C, " + QDate::fromString(dictumData.at(3), "yyyy-MM-dd").toString("dd 'de' MMMM 'de' yyyy"));
            htmlString.replace("_numeroDictamen", dictumData.at(1));
            htmlString.replace("_nombreRazonSocial", inspectionData.at(7));
            htmlString.replace("_dirInstalacion", inspectionData.at(6) + ", " + inspectionData.at(8) + ", " + inspectionData.at(9));
            htmlString.replace("_codDANE", inspectionData.at(10));

            // Se busca en los procesos si contienen alguno de los mencionados y entonces se llenan con la X
            QString transmision("&nbsp;"), distribucion("&nbsp;"), usoFinal("&nbsp;"), otro("&nbsp;"), ninguno("&nbsp;");
            if (dictumProcIds.contains(QString::number(BcProcs::Transmision)))
                transmision="X";
            if (dictumProcIds.contains(QString::number(BcProcs::Distribucion)))
                distribucion="X";
            if (dictumProcIds.contains(QString::number(BcProcs::UsoFinal)))
                usoFinal="X";
            if (transmision!="X" && distribucion!="X" && usoFinal!="X")
                otro="X";

            htmlString.replace("_XTrm", transmision);
            htmlString.replace("_XDis", distribucion);
            htmlString.replace("_XUsf", usoFinal);
            htmlString.replace("_XOtr", otro);
            htmlString.replace("_XNin", ninguno);

            htmlString.replace("_capacidad", dictumData.at(8));
            htmlString.replace("_tension", dictumData.at(9));
            htmlString.replace("_tipoSubestacion", extraData.at(0));
            htmlString.replace("_numeroTrafos", extraData.at(1));
            htmlString.replace("_terminacion", QString::number(QDate::fromString(dictumData.at(11), "yyyy-MM-dd").year()));

            QString designersString, designersMpString;
            for (int i=0;i<designers.at(0).size();i++) {
                designersString.append(designers.at(0).at(i) + ", ");
                designersMpString.append(designers.at(1).at(i) + ", ");
            }
            designersString.remove(designersString.size()-2,2); // Remuevo la coma (,) y el espacio
            designersMpString.remove(designersMpString.size()-2,2);

            htmlString.replace("_disenador", designersString);
            htmlString.replace("_matriculaDis", designersMpString);
            htmlString.replace("_constructor", inspectionData.at(11));
            htmlString.replace("_matriculaCons", inspectionData.at(12));
            htmlString.replace("_interventor", inspectionData.at(13));
            htmlString.replace("_matriculaInt", inspectionData.at(14));
            htmlString.replace("_alcance", dictumData.at(6));

            QString aprobada("&nbsp;"), noAprobada("&nbsp;");
            if (dictumData.at(5) == "Conforme")
                aprobada="X";
            else
                noAprobada="X";

            htmlString.replace("_XAprob", aprobada);
            htmlString.replace("_XNoAprob", noAprobada);
            htmlString.replace("_inspector", inspector.at(0));
            htmlString.replace("_matriculaInsp", inspector.at(1));
        }
        break;

        // NOTE: BLOQUE PARA TRANSMISION
    case BcProcs::Transmision:
        // Se obtienen los datos extra
        if (!DbHandler::getExtraData(dictumData.at(0), inspectionData.at(1), extraData))
            qDebug() << trUtf8("DbHandler::getExtraData(), ha devulto false al tratar de obtener "
                               "datos extra, se cerrará el programa");

        fileName = QDir::currentPath() + "/templates/transm_dictum_template.html";
        file.setFileName(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, trUtf8("Error Abriendo Plantilla"),
                                 trUtf8("No se puedo abrir '%1'").arg(fileName));
        } else {
            // En este punto se empieza a preparar el html, se generan las colmnas
            QTextStream stream(&file);
            htmlString.clear();
            htmlString = stream.readAll();
            // Deben llenarse de guiones bajos que indican que no están chequeados
            for (int i=0; i<requirementsData.at(0).size();i++) {
                reqsApply.append("_");
                reqsMeets.append("_");
                reqsNoMeets.append("_");
            }

            // Se recorren los ids para chequear lo que aplica, cumple o no cumple reemplazando el _ con una X
            int index;
            for (int i=0; i<dictumReqsData.at(0).size();i++) {
                // indexOf me entrega la posición en la que está el id del documento, con esa posición
                // reemplazo el string vacío por el nombre del documento
                index=requirementsData.at(0).indexOf(dictumReqsData.at(0).at(i));
                if (index >=0) { // para prevenir el -1 al no encontrar el Id
                    reqsApply.replace(index, "X");
                    if (dictumReqsData.at(1).at(i) == "X")
                        reqsMeets.replace(index, "X"); // Cumple
                    else
                        reqsNoMeets.replace(index, "X"); // No cumple
                }

            }

            // Es necesario añadir las 3 columnas de aplica, cumple, no cumple
            requirementsData.append(reqsApply);
            requirementsData.append(reqsMeets);
            requirementsData.append(reqsNoMeets);

            QString htmlReqRows; // En este se acumularán las columnas
            // Teniendo los requerimientos completos y debidamente marcados, se procede a generar las filas de requerimientos
            for (int i=0; i<requirementsData.at(0).size();i++) {
                // Se parte de un string nuevo en cada fila
                QString htmlReqRow = QString("<tr>"
                                             "<td style=\"text-align: center\">%1</td>"
                                             "<td>%2</td>"
                                             "<td style=\"text-align: center\">%3</td>"
                                             "<td style=\"text-align: center\">%4</td>"
                                             "<td style=\"text-align: center\">%5</td>"
                                             "</tr>")
                        .arg(QString::number(i+1))
                        .arg(requirementsData.at(1).at(i))
                        .arg(requirementsData.at(2).at(i))
                        .arg(requirementsData.at(3).at(i))
                        .arg(requirementsData.at(4).at(i));

                // Se añaden no en lista sino en cadena continua ya que es un htmlReqRows es un QString no un QStringList
                htmlReqRows.append(htmlReqRow);
            }

            htmlString.replace("_dynamicReqRows", htmlReqRows);

            htmlString.replace("_lugarFechaExp", "Bogot&aacute;, D.C, " + QDate::fromString(dictumData.at(3), "yyyy-MM-dd").toString("dd 'de' MMMM 'de' yyyy"));
            htmlString.replace("_expedienteNumero", inspectionData.at(15));
            htmlString.replace("_nombreRazonSocial", inspectionData.at(7));
            htmlString.replace("_dirInstalacion", inspectionData.at(6) + ", " + inspectionData.at(8) + ", " + inspectionData.at(9));
            htmlString.replace("_codDANE", inspectionData.at(10));

            // Se busca en los procesos si contienen alguno de los mencionados y entonces se llenan con la X
            QString transformacion("&nbsp;"), generacion("&nbsp;"), usoFinal("&nbsp;"), otro("&nbsp;"), servicioGeneral("&nbsp;"),
                    servicioExclusivo("&nbsp;");
            if (dictumProcIds.contains(QString::number(BcProcs::Transformacion)))
                transformacion="X";
            if (dictumProcIds.contains(QString::number(BcProcs::Generacion)))
                generacion="X";
            if (dictumProcIds.contains(QString::number(BcProcs::UsoFinal)))
                usoFinal="X";
            if (uses.at(0).contains(QString::number(BcUses::ServicioPublico)))
                servicioGeneral="X";
            if (uses.at(0).contains(QString::number(BcUses::ServicioPrivado)))
                servicioExclusivo="X";
            if (transformacion!="X" && generacion!="X" && usoFinal!="X" && servicioGeneral!="X" && servicioExclusivo!="X")
                otro="X";

            QString rural("&nbsp;"), residencial("&nbsp;"), industrial("&nbsp;"), aislada("&nbsp;");
            if (uses.at(0).contains(QString::number(BcUses::Rural)))
                rural="X";
            if (uses.at(0).contains(QString::number(BcUses::Residencial)))
                residencial="X";
            if (uses.at(0).contains(QString::number(BcUses::Industrial)))
                industrial="X";
            if (uses.at(0).contains(QString::number(BcUses::AisladaDelSIN)))
                aislada="X";

            htmlString.replace("_XGen", generacion);
            htmlString.replace("_XTrf", transformacion);
            htmlString.replace("_XOtr", otro);
            htmlString.replace("_XUsf", usoFinal);
            htmlString.replace("_XSgn", servicioGeneral);
            htmlString.replace("_XSex", servicioExclusivo);


            htmlString.replace("_XRur", rural);
            htmlString.replace("_XRes", residencial);
            htmlString.replace("_XInd", industrial);
            htmlString.replace("_XAsl", aislada);

            htmlString.replace("_capacidad", dictumData.at(8));
            htmlString.replace("_tension", dictumData.at(9));
            htmlString.replace("_terminacion", QString::number(QDate::fromString(dictumData.at(11), "yyyy-MM-dd").year()));

            htmlString.replace("_detalleLinea", extraData.at(0));
            htmlString.replace("_conf", extraData.at(1));
            htmlString.replace("_longitud", extraData.at(2));
            htmlString.replace("_conductores", extraData.at(3));
            htmlString.replace("_material", extraData.at(4));
            htmlString.replace("_estructNumero", extraData.at(5));

            QString designersString, designersMpString;
            for (int i=0;i<designers.at(0).size();i++) {
                designersString.append(designers.at(0).at(i) + ", ");
                designersMpString.append(designers.at(1).at(i) + ", ");
            }
            designersString.remove(designersString.size()-2,2); // Remuevo la coma (,) y el espacio
            designersMpString.remove(designersMpString.size()-2,2);

            htmlString.replace("_disenador", designersString);
            htmlString.replace("_matriculaDis", designersMpString);
            htmlString.replace("_constructor", inspectionData.at(11));
            htmlString.replace("_matriculaCons", inspectionData.at(12));
            htmlString.replace("_interventor", inspectionData.at(13));
            htmlString.replace("_matriculaInt", inspectionData.at(14));
            htmlString.replace("_alcance", dictumData.at(6));

            QString aprobada("&nbsp;"), noAprobada("&nbsp;");
            if (dictumData.at(5) == "Conforme")
                aprobada="X";
            else
                noAprobada="X";

            htmlString.replace("_XAprob", aprobada);
            htmlString.replace("_XNoAprob", noAprobada);
            htmlString.replace("_inspector", inspector.at(0));
            htmlString.replace("_matriculaInsp", inspector.at(1));
        }
        break;


        // NOTE: BLOQUE PARA USO TRANSFORMACION
    case BcProcs::Transformacion:
        // Se obtienen los datos extra
        if (!DbHandler::getExtraData(dictumData.at(0), inspectionData.at(1), extraData))
            qDebug() << trUtf8("DbHandler::getExtraData(), ha devulto false al tratar de obtener "
                               "datos extra, se cerrará el programa");

        fileName = QDir::currentPath() + "/templates/transf_dictum_template.html";
        file.setFileName(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, trUtf8("Error Abriendo Plantilla"),
                                 trUtf8("No se puedo abrir '%1'").arg(fileName));
        } else {
            // En este punto se empieza a preparar el html, se generan las colmnas
            QTextStream stream(&file);
            htmlString.clear();
            htmlString = stream.readAll();
            // Deben llenarse de guiones bajos que indican que no están chequeados
            for (int i=0; i<requirementsData.at(0).size();i++) {
                reqsApply.append("_");
                reqsMeets.append("_");
                reqsNoMeets.append("_");
            }

            // Se recorren los ids para chequear lo que aplica, cumple o no cumple reemplazando el _ con una X
            int index;
            for (int i=0; i<dictumReqsData.at(0).size();i++) {
                // indexOf me entrega la posición en la que está el id del documento, con esa posición
                // reemplazo el string vacío por el nombre del documento
                index=requirementsData.at(0).indexOf(dictumReqsData.at(0).at(i));
                if (index >=0) { // para prevenir el -1 al no encontrar el Id
                    reqsApply.replace(index, "X");
                    if (dictumReqsData.at(1).at(i) == "X")
                        reqsMeets.replace(index, "X"); // Cumple
                    else
                        reqsNoMeets.replace(index, "X"); // No cumple
                }

            }

            // Es necesario añadir las 3 columnas de aplica, cumple, no cumple
            requirementsData.append(reqsApply);
            requirementsData.append(reqsMeets);
            requirementsData.append(reqsNoMeets);

            QString htmlReqRows; // En este se acumularán las columnas
            // Teniendo los requerimientos completos y debidamente marcados, se procede a generar las filas de requerimientos
            for (int i=0; i<requirementsData.at(0).size();i++) {
                // Se parte de un string nuevo en cada fila
                QString htmlReqRow = QString("<tr>"
                                             "<td style=\"text-align: center\">%1</td>"
                                             "<td>%2</td>"
                                             "<td style=\"text-align: center\">%3</td>"
                                             "<td style=\"text-align: center\">%4</td>"
                                             "<td style=\"text-align: center\">%5</td>"
                                             "</tr>")
                        .arg(QString::number(i+1))
                        .arg(requirementsData.at(1).at(i))
                        .arg(requirementsData.at(2).at(i))
                        .arg(requirementsData.at(3).at(i))
                        .arg(requirementsData.at(4).at(i));

                // Se añaden no en lista sino en cadena continua ya que es un htmlReqRows es un QString no un QStringList
                htmlReqRows.append(htmlReqRow);
            }

            htmlString.replace("_dynamicReqRows", htmlReqRows);

            htmlString.replace("_lugarFechaExp", "Bogot&aacute;, D.C, " + QDate::fromString(dictumData.at(3), "yyyy-MM-dd").toString("dd 'de' MMMM 'de' yyyy"));
            htmlString.replace("_expedienteNumero", inspectionData.at(15));
            htmlString.replace("_nombreRazonSocial", inspectionData.at(7));
            htmlString.replace("_dirInstalacion", inspectionData.at(6) + ", " + inspectionData.at(8) + ", " + inspectionData.at(9));
            htmlString.replace("_codDANE", inspectionData.at(10));

            // Se busca en los procesos si contienen alguno de los mencionados y entonces se llenan con la X
            QString generacion("&nbsp;"), transmision("&nbsp;"), distribucion("&nbsp;"), usoFinal("&nbsp;");
            if (dictumProcIds.contains(QString::number(BcProcs::Generacion)))
                generacion="X";
            if (dictumProcIds.contains(QString::number(BcProcs::Transmision)))
                transmision="X";
            if (dictumProcIds.contains(QString::number(BcProcs::Distribucion)))
                distribucion="X";
            if (dictumProcIds.contains(QString::number(BcProcs::UsoFinal)))
                usoFinal="X";

            htmlString.replace("_XGen", generacion);
            htmlString.replace("_XTrm", transmision);
            htmlString.replace("_XDis", distribucion);
            htmlString.replace("_XUsf", usoFinal);

            QString residencial("&nbsp;"), comercial("&nbsp;"), industrial("&nbsp;"), oficial("&nbsp;");
            if (uses.at(0).contains(QString::number(BcUses::Residencial)))
                residencial="X";
            if (uses.at(0).contains(QString::number(BcUses::Comercial)))
                comercial="X";
            if (uses.at(0).contains(QString::number(BcUses::Industrial)))
                industrial="X";
            if (uses.at(0).contains(QString::number(BcUses::Oficial)))
                oficial="X";

            htmlString.replace("_XRes", residencial);
            htmlString.replace("_XCom", comercial);
            htmlString.replace("_XInd", industrial);
            htmlString.replace("_XOfc", oficial);

            htmlString.replace("_capacidad", dictumData.at(8));
            htmlString.replace("_tension", dictumData.at(9));
            htmlString.replace("_terminacion", QString::number(QDate::fromString(dictumData.at(11), "yyyy-MM-dd").year()));

            htmlString.replace("_tipoSe", extraData.at(0));
            htmlString.replace("_kapacidadSe", extraData.at(1));
            htmlString.replace("_numeroTransf", extraData.at(2));

            QString designersString, designersMpString;
            for (int i=0;i<designers.at(0).size();i++) {
                designersString.append(designers.at(0).at(i) + ", ");
                designersMpString.append(designers.at(1).at(i) + ", ");
            }
            designersString.remove(designersString.size()-2,2); // Remuevo la coma (,) y el espacio
            designersMpString.remove(designersMpString.size()-2,2);

            htmlString.replace("_disenador", designersString);
            htmlString.replace("_matriculaDis", designersMpString);
            htmlString.replace("_constructor", inspectionData.at(11));
            htmlString.replace("_matriculaCons", inspectionData.at(12));
            htmlString.replace("_interventor", inspectionData.at(13));
            htmlString.replace("_matriculaInt", inspectionData.at(14));
            htmlString.replace("_alcance", dictumData.at(6));

            QString aprobada("&nbsp;"), noAprobada("&nbsp;");
            if (dictumData.at(5) == "Conforme")
                aprobada="X";
            else
                noAprobada="X";

            htmlString.replace("_XAprob", aprobada);
            htmlString.replace("_XNoAprob", noAprobada);
            htmlString.replace("_inspector", inspector.at(0));
            htmlString.replace("_matriculaInsp", inspector.at(1));
        }
        break;


        // NOTE: BLOQUE PARA DISTRIBUCION
    case BcProcs::Distribucion:
        // Se obtienen los datos extra
        if (!DbHandler::getExtraData(dictumData.at(0), inspectionData.at(1), extraData))
            qDebug() << trUtf8("DbHandler::getExtraData(), ha devulto false al tratar de obtener "
                               "datos extra, se cerrará el programa");

        fileName = QDir::currentPath() + "/templates/dist_dictum_template.html";
        file.setFileName(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, trUtf8("Error Abriendo Plantilla"),
                                 trUtf8("No se puedo abrir '%1'").arg(fileName));
        } else {
            // En este punto se empieza a preparar el html, se generan las colmnas
            QTextStream stream(&file);
            htmlString.clear();
            htmlString = stream.readAll();
            // Deben llenarse de guiones bajos que indican que no están chequeados
            for (int i=0; i<requirementsData.at(0).size();i++) {
                reqsApply.append("_");
                reqsMeets.append("_");
                reqsNoMeets.append("_");
            }

            // Se recorren los ids para chequear lo que aplica, cumple o no cumple reemplazando el _ con una X
            int index;
            for (int i=0; i<dictumReqsData.at(0).size();i++) {
                // indexOf me entrega la posición en la que está el id del documento, con esa posición
                // reemplazo el string vacío por el nombre del documento
                index=requirementsData.at(0).indexOf(dictumReqsData.at(0).at(i));
                if (index >=0) { // para prevenir el -1 al no encontrar el Id
                    reqsApply.replace(index, "X");
                    if (dictumReqsData.at(1).at(i) == "X")
                        reqsMeets.replace(index, "X"); // Cumple
                    else
                        reqsNoMeets.replace(index, "X"); // No cumple
                }

            }

            // Es necesario añadir las 3 columnas de aplica, cumple, no cumple
            requirementsData.append(reqsApply);
            requirementsData.append(reqsMeets);
            requirementsData.append(reqsNoMeets);

            QString htmlReqRows; // En este se acumularán las columnas
            // Teniendo los requerimientos completos y debidamente marcados, se procede a generar las filas de requerimientos
            for (int i=0; i<requirementsData.at(0).size();i++) {
                // Se parte de un string nuevo en cada fila
                QString htmlReqRow = QString("<tr>"
                                             "<td style=\"text-align: center\">%1</td>"
                                             "<td>%2</td>"
                                             "<td style=\"text-align: center\">%3</td>"
                                             "<td style=\"text-align: center\">%4</td>"
                                             "<td style=\"text-align: center\">%5</td>"
                                             "</tr>")
                        .arg(QString::number(i+1))
                        .arg(requirementsData.at(1).at(i))
                        .arg(requirementsData.at(2).at(i))
                        .arg(requirementsData.at(3).at(i))
                        .arg(requirementsData.at(4).at(i));

                // Se añaden no en lista sino en cadena continua ya que es un htmlReqRows es un QString no un QStringList
                htmlReqRows.append(htmlReqRow);
            }

            htmlString.replace("_dynamicReqRows", htmlReqRows);

            htmlString.replace("_lugarFechaExp", "Bogot&aacute;, D.C, " + QDate::fromString(dictumData.at(3), "yyyy-MM-dd").toString("dd 'de' MMMM 'de' yyyy"));
            htmlString.replace("_expedienteNumero", inspectionData.at(15));
            htmlString.replace("_nombreRazonSocial", inspectionData.at(7));
            htmlString.replace("_dirInstalacion", inspectionData.at(6) + ", " + inspectionData.at(8) + ", " + inspectionData.at(9));
            htmlString.replace("_codDANE", inspectionData.at(10));

            // Se busca en los procesos si contienen alguno de los mencionados y entonces se llenan con la X
            QString usoGeneral("&nbsp;"), usoExclusivo("&nbsp;"), alumbradoPublico("&nbsp;"), usoFinal("&nbsp;"),
                    rural("&nbsp;"), residencial("&nbsp;"), industrial("&nbsp;"), aislada("&nbsp;");

            if (uses.at(0).contains(QString::number(BcUses::UsoGeneral)))
                usoGeneral="X";
            if (uses.at(0).contains(QString::number(BcUses::UsoExclusivo)))
                usoExclusivo="X";
            if (dictumProcIds.contains(QString::number(BcProcs::AlumbradoExt)))
                alumbradoPublico="X";
            if (dictumProcIds.contains(QString::number(BcProcs::UsoFinal)))
                usoFinal="X";
            if (uses.at(0).contains(QString::number(BcUses::Rural)))
                rural="X";
            if (uses.at(0).contains(QString::number(BcUses::Residencial)))
                residencial="X";
            if (uses.at(0).contains(QString::number(BcUses::Industrial)))
                industrial="X";
            if (uses.at(0).contains(QString::number(BcUses::AisladaDelSIN)))
                aislada="X";

            htmlString.replace("_XUgn", usoGeneral);
            htmlString.replace("_XUex", usoExclusivo);
            htmlString.replace("_XAlp", alumbradoPublico);
            htmlString.replace("_XUsf", usoFinal);
            htmlString.replace("_XRur", rural);
            htmlString.replace("_XRes", residencial);
            htmlString.replace("_XInd", industrial);
            htmlString.replace("_XAsl", aislada);

            htmlString.replace("_capacidad", dictumData.at(8));
            htmlString.replace("_tension", dictumData.at(9));
            htmlString.replace("_terminacion", QString::number(QDate::fromString(dictumData.at(11), "yyyy-MM-dd").year()));

            QString monofasica("&nbsp;"), trifasica("&nbsp;");
            if (extraData.at(0).contains("Mono"))
                monofasica="X";
            else
                trifasica="X";
            htmlString.replace("_XMon", monofasica);
            htmlString.replace("_XTrf", trifasica);
            htmlString.replace("_longitud", extraData.at(1));
            htmlString.replace("_conductores", extraData.at(2));
            htmlString.replace("_material", extraData.at(3));
            htmlString.replace("_estructNumero", extraData.at(4));

            QString designersString, designersMpString;
            for (int i=0;i<designers.at(0).size();i++) {
                designersString.append(designers.at(0).at(i) + ", ");
                designersMpString.append(designers.at(1).at(i) + ", ");
            }
            designersString.remove(designersString.size()-2,2); // Remuevo la coma (,) y el espacio
            designersMpString.remove(designersMpString.size()-2,2);

            htmlString.replace("_disenador", designersString);
            htmlString.replace("_matriculaDis", designersMpString);
            htmlString.replace("_constructor", inspectionData.at(11));
            htmlString.replace("_matriculaCons", inspectionData.at(12));
            htmlString.replace("_interventor", inspectionData.at(13));
            htmlString.replace("_matriculaInt", inspectionData.at(14));
            htmlString.replace("_alcance", dictumData.at(6));

            QString aprobada("&nbsp;"), noAprobada("&nbsp;");
            if (dictumData.at(5) == "Conforme")
                aprobada="X";
            else
                noAprobada="X";

            htmlString.replace("_XAprob", aprobada);
            htmlString.replace("_XNoAprob", noAprobada);
            htmlString.replace("_inspector", inspector.at(0));
            htmlString.replace("_matriculaInsp", inspector.at(1));
        }
        break;


        // NOTE: BLOQUE PARA USO FINAL
    case BcProcs::UsoFinal:

        fileName = QDir::currentPath() + "/templates/usof_dictum_template.html";
        file.setFileName(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, trUtf8("Error Abriendo Plantilla"),
                                 trUtf8("No se puedo abrir '%1'").arg(fileName));
        } else {

            // En este punto se empieza a preparar el html, se generan las colmnas
            QTextStream stream(&file);
            htmlString.clear();
            htmlString = stream.readAll();
            // Deben llenarse de guiones bajos que indican que no están chequeados
            for (int i=0; i<requirementsData.at(0).size();i++) {
                reqsApply.append("_");
                reqsMeets.append("_");
                reqsNoMeets.append("_");
            }

            // Se recorren los ids para chequear lo que aplica, cumple o no cumple reemplazando el _ con una X
            int index;
            for (int i=0; i<dictumReqsData.at(0).size();i++) {
                // indexOf me entrega la posición en la que está el id del documento, con esa posición
                // reemplazo el string vacío por el nombre del documento
                index=requirementsData.at(0).indexOf(dictumReqsData.at(0).at(i));
                if (index >=0) { // para prevenir el -1 al no encontrar el Id
                    reqsApply.replace(index, "X");
                    if (dictumReqsData.at(1).at(i) == "X")
                        reqsMeets.replace(index, "X"); // Cumple
                    else
                        reqsNoMeets.replace(index, "X"); // No cumple
                }

            }

            // Es necesario añadir las 3 columnas de aplica, cumple, no cumple
            requirementsData.append(reqsApply);
            requirementsData.append(reqsMeets);
            requirementsData.append(reqsNoMeets);

            QString htmlReqRows; // En este se acumularán las columnas
            // Teniendo los requerimientos completos y debidamente marcados, se procede a generar las filas de requerimientos
            for (int i=0; i<requirementsData.at(0).size();i++) {
                // Se parte de un string nuevo en cada fila
                QString htmlReqRow = QString("<tr>"
                                             "<td style=\"text-align: center\">%1</td>"
                                             "<td>%2</td>"
                                             "<td style=\"text-align: center\">%3</td>"
                                             "<td style=\"text-align: center\">%4</td>"
                                             "<td style=\"text-align: center\">%5</td>"
                                             "</tr>")
                        .arg(QString::number(i+1))
                        .arg(requirementsData.at(1).at(i))
                        .arg(requirementsData.at(2).at(i))
                        .arg(requirementsData.at(3).at(i))
                        .arg(requirementsData.at(4).at(i));

                // Se añaden no en lista sino en cadena continua ya que es un htmlReqRows es un QString no un QStringList
                htmlReqRows.append(htmlReqRow);
            }

            htmlString.replace("_dynamicReqRows", htmlReqRows);

            htmlString.replace("_lugarFechaExp", "Bogot&aacute;, D.C, " + QDate::fromString(dictumData.at(3), "yyyy-MM-dd").toString("dd 'de' MMMM 'de' yyyy"));
            htmlString.replace("_expedienteNumero", inspectionData.at(15));
            htmlString.replace("_nombreRazonSocial", inspectionData.at(7));
            htmlString.replace("_dirInstalacion", inspectionData.at(6) + ", " + inspectionData.at(8) + ", " + inspectionData.at(9));
            htmlString.replace("_codDANE", inspectionData.at(10));

            QString residencial("&nbsp;"), comercial("&nbsp;"), industrial("&nbsp;");
            if (uses.at(0).contains(QString::number(BcUses::Residencial)))
                residencial="X";
            if (uses.at(0).contains(QString::number(BcUses::Comercial)))
                comercial="X";
            if (uses.at(0).contains(QString::number(BcUses::Industrial)))
                industrial="X";

            htmlString.replace("_XRes", residencial);
            htmlString.replace("_XCom", comercial);
            htmlString.replace("_XInd", industrial);
            htmlString.replace("_especialTipo", useSName);

            htmlString.replace("_capacidad", dictumData.at(8));
            htmlString.replace("_tension", dictumData.at(9));
            htmlString.replace("_terminacion", QString::number(QDate::fromString(dictumData.at(11), "yyyy-MM-dd").year()));

            QString designersString, designersMpString;
            for (int i=0;i<designers.at(0).size();i++) {
                designersString.append(designers.at(0).at(i) + ", ");
                designersMpString.append(designers.at(1).at(i) + ", ");
            }
            designersString.remove(designersString.size()-2,2); // Remuevo la , y el espacio
            designersMpString.remove(designersMpString.size()-2,2);

            htmlString.replace("_disenador", designersString);
            htmlString.replace("_matriculaDis", designersMpString);
            htmlString.replace("_constructor", inspectionData.at(11));
            htmlString.replace("_matriculaCons", inspectionData.at(12));
            htmlString.replace("_interventor", inspectionData.at(13));
            htmlString.replace("_matriculaInt", inspectionData.at(14));
            htmlString.replace("_alcance", dictumData.at(6));

            QString aprobada("&nbsp;"), noAprobada("&nbsp;");
            if (dictumData.at(5) == "Conforme")
                aprobada="X";
            else
                noAprobada="X";

            htmlString.replace("_XAprob", aprobada);
            htmlString.replace("_XNoAprob", noAprobada);
            htmlString.replace("_inspector", inspector.at(0));
            htmlString.replace("_matriculaInsp", inspector.at(1));

        }
        break;


        // NOTE: BLOQUE PARA ALUMBRADO EXTERIOR
    case BcProcs::AlumbradoExt:
        // Se obtienen los datos extra
        if (!DbHandler::getExtraData(dictumData.at(0), inspectionData.at(1), extraData))
            qDebug() << trUtf8("DbHandler::getExtraData(), ha devulto false al tratar de obtener "
                               "datos extra, se cerrará el programa");

        fileName = QDir::currentPath() + "/templates/alext_dictum_template.html";
        file.setFileName(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, trUtf8("Error Abriendo Plantilla"),
                                 trUtf8("No se puedo abrir '%1'").arg(fileName));
        } else {
            // En este punto se empieza a preparar el html, se generan las colmnas
            QTextStream stream(&file);
            htmlString.clear();
            htmlString = stream.readAll();
            // Deben llenarse de guiones bajos que indican que no están chequeados
            for (int i=0; i<requirementsData.at(0).size();i++) {
                reqsApply.append("_");
                reqsMeets.append("_");
                reqsNoMeets.append("_");
            }

            // Se recorren los ids para chequear lo que aplica, cumple o no cumple reemplazando el _ con una X
            int index;
            for (int i=0; i<dictumReqsData.at(0).size();i++) {
                // indexOf me entrega la posición en la que está el id del documento, con esa posición
                // reemplazo el string vacío por el nombre del documento
                index=requirementsData.at(0).indexOf(dictumReqsData.at(0).at(i));
                if (index >=0) { // para prevenir el -1 al no encontrar el Id
                    reqsApply.replace(index, "X");
                    if (dictumReqsData.at(1).at(i) == "X")
                        reqsMeets.replace(index, "X"); // Cumple
                    else
                        reqsNoMeets.replace(index, "X"); // No cumple
                }

            }

            // Es necesario añadir las 3 columnas de aplica, cumple, no cumple
            requirementsData.append(reqsApply);
            requirementsData.append(reqsMeets);
            requirementsData.append(reqsNoMeets);

            QString htmlReqRows; // En este se acumularán las columnas
            // Teniendo los requerimientos completos y debidamente marcados, se procede a generar las filas de requerimientos
            for (int i=0; i<requirementsData.at(0).size();i++) {
                // Se parte de un string nuevo en cada fila
                QString htmlReqRow = QString("<tr>"
                                             "<td style=\"text-align: center\">%1</td>"
                                             "<td>%2</td>"
                                             "<td style=\"text-align: center\">%3</td>"
                                             "<td style=\"text-align: center\">%4</td>"
                                             "<td style=\"text-align: center\">%5</td>"
                                             "</tr>")
                        .arg(QString::number(i+1))
                        .arg(requirementsData.at(1).at(i))
                        .arg(requirementsData.at(2).at(i))
                        .arg(requirementsData.at(3).at(i))
                        .arg(requirementsData.at(4).at(i));

                // Se añaden no en lista sino en cadena continua ya que es un htmlReqRows es un QString no un QStringList
                htmlReqRows.append(htmlReqRow);
            }

            htmlString.replace("_dynamicReqRows", htmlReqRows);

            htmlString.replace("_lugarFechaExp", "Bogot&aacute;, D.C, " + QDate::fromString(dictumData.at(3), "yyyy-MM-dd").toString("dd 'de' MMMM 'de' yyyy"));
            htmlString.replace("_expedienteNumero", inspectionData.at(15));
            htmlString.replace("_nombreRazonSocial", inspectionData.at(7));
            htmlString.replace("_dirInstalacion", inspectionData.at(6) + ", " + inspectionData.at(8) + ", " + inspectionData.at(9));
            htmlString.replace("_codDANE", inspectionData.at(10));

            // Se busca en los procesos si contienen alguno de los mencionados y entonces se llenan con la X
            QString usoGeneral("&nbsp;"), circuitoExclusivo("&nbsp;"), residencial("&nbsp;"), industrial("&nbsp;");

            if (uses.at(0).contains(QString::number(BcUses::Residencial)))
                residencial="X";
            if (uses.at(0).contains(QString::number(BcUses::Industrial)))
                industrial="X";
            if (uses.at(0).contains(QString::number(BcUses::UsoExclusivo)))
                circuitoExclusivo="X";
            if (uses.at(0).contains(QString::number(BcUses::UsoGeneral)))
                usoGeneral="X";


            htmlString.replace("_XRes", residencial);
            htmlString.replace("_XInd", industrial);
            htmlString.replace("_XCex", circuitoExclusivo);
            htmlString.replace("_XUgn", usoGeneral);

            htmlString.replace("_capacidad", dictumData.at(8));
            htmlString.replace("_tension", dictumData.at(9));
            htmlString.replace("_terminacion", QString::number(QDate::fromString(dictumData.at(11), "yyyy-MM-dd").year()));

            htmlString.replace("_totalLuminarias", extraData.at(0));

            QString medidaSi("&nbsp;"), medidaNo("&nbsp;");
            if (extraData.at(1).contains("Si"))
                medidaSi="X";
            else
                medidaNo="X";

            htmlString.replace("_XSi", medidaSi);
            htmlString.replace("_XNo", medidaNo);

            QString parque("&nbsp;"), vias("&nbsp;");
            if (extraData.at(2).contains("Parque"))
                parque="X";
            else
                vias="X";

            htmlString.replace("_XPar", parque);
            htmlString.replace("_XVia", vias);

            htmlString.replace("_longitud", extraData.at(3));
            htmlString.replace("_area", extraData.at(4));

            QString designersString, designersMpString;
            for (int i=0;i<designers.at(0).size();i++) {
                designersString.append(designers.at(0).at(i) + ", ");
                designersMpString.append(designers.at(1).at(i) + ", ");
            }
            designersString.remove(designersString.size()-2,2); // Remuevo la coma (,) y el espacio
            designersMpString.remove(designersMpString.size()-2,2);

            htmlString.replace("_disenador", designersString);
            htmlString.replace("_matriculaDis", designersMpString);
            htmlString.replace("_constructor", inspectionData.at(11));
            htmlString.replace("_matriculaCons", inspectionData.at(12));
            htmlString.replace("_interventor", inspectionData.at(13));
            htmlString.replace("_matriculaInt", inspectionData.at(14));
            htmlString.replace("_alcance", dictumData.at(6));

            QString aprobada("&nbsp;"), noAprobada("&nbsp;");
            if (dictumData.at(5) == "Conforme")
                aprobada="X";
            else
                noAprobada="X";

            htmlString.replace("_XAprob", aprobada);
            htmlString.replace("-XNoAprob", noAprobada);
            htmlString.replace("_inspector", inspector.at(0));
            htmlString.replace("_matriculaInsp", inspector.at(1));
        }
        break;


        // NOTE: BLOQUE PARA ALUMBRADO INTERIOR
    case BcProcs::AlumbradoInt:
        // Se obtienen los datos extra
        if (!DbHandler::getExtraData(dictumData.at(0), inspectionData.at(1), extraData))
            qDebug() << trUtf8("DbHandler::getExtraData(), ha devulto false al tratar de obtener "
                               "datos extra, se cerrará el programa");

        fileName = QDir::currentPath() + "/templates/alint_dictum_template.html";
        file.setFileName(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, trUtf8("Error Abriendo Plantilla"),
                                 trUtf8("No se puedo abrir '%1'").arg(fileName));
        } else {
            // En este punto se empieza a preparar el html, se generan las colmnas
            QTextStream stream(&file);
            htmlString.clear();
            htmlString = stream.readAll();
            // Deben llenarse de guiones bajos que indican que no están chequeados
            for (int i=0; i<requirementsData.at(0).size();i++) {
                reqsApply.append("_");
                reqsMeets.append("_");
                reqsNoMeets.append("_");
            }

            // Se recorren los ids para chequear lo que aplica, cumple o no cumple reemplazando el _ con una X
            int index;
            for (int i=0; i<dictumReqsData.at(0).size();i++) {
                // indexOf me entrega la posición en la que está el id del documento, con esa posición
                // reemplazo el string vacío por el nombre del documento
                index=requirementsData.at(0).indexOf(dictumReqsData.at(0).at(i));
                if (index >=0) { // para prevenir el -1 al no encontrar el Id
                    reqsApply.replace(index, "X");
                    if (dictumReqsData.at(1).at(i) == "X")
                        reqsMeets.replace(index, "X"); // Cumple
                    else
                        reqsNoMeets.replace(index, "X"); // No cumple
                }

            }

            // Es necesario añadir las 3 columnas de aplica, cumple, no cumple
            requirementsData.append(reqsApply);
            requirementsData.append(reqsMeets);
            requirementsData.append(reqsNoMeets);

            QString htmlReqRows; // En este se acumularán las columnas
            // Teniendo los requerimientos completos y debidamente marcados, se procede a generar las filas de requerimientos
            for (int i=0; i<requirementsData.at(0).size();i++) {
                // Se parte de un string nuevo en cada fila
                QString htmlReqRow = QString("<tr>"
                                             "<td style=\"text-align: center\">%1</td>"
                                             "<td>%2</td>"
                                             "<td style=\"text-align: center\">%3</td>"
                                             "<td style=\"text-align: center\">%4</td>"
                                             "<td style=\"text-align: center\">%5</td>"
                                             "</tr>")
                        .arg(QString::number(i+1))
                        .arg(requirementsData.at(1).at(i))
                        .arg(requirementsData.at(2).at(i))
                        .arg(requirementsData.at(3).at(i))
                        .arg(requirementsData.at(4).at(i));

                // Se añaden no en lista sino en cadena continua ya que es un htmlReqRows es un QString no un QStringList
                htmlReqRows.append(htmlReqRow);
            }

            htmlString.replace("_dynamicReqRows", htmlReqRows);

            htmlString.replace("_lugarFechaExp", "Bogot&aacute;, D.C, " + QDate::fromString(dictumData.at(3), "yyyy-MM-dd").toString("dd 'de' MMMM 'de' yyyy"));
            htmlString.replace("_expedienteNumero", inspectionData.at(15));
            htmlString.replace("_nombreRazonSocial", inspectionData.at(7));
            htmlString.replace("_dirInstalacion", inspectionData.at(6) + ", " + inspectionData.at(8) + ", " + inspectionData.at(9));
            htmlString.replace("_codDANE", inspectionData.at(10));

            // Se busca en los procesos si contienen alguno de los mencionados y entonces se llenan con la X
            QString residencial("&nbsp;"), industrial("&nbsp;"), comercial("&nbsp;"), servicioPublico("&nbsp;"),
                    servicioPrivado("&nbsp;"), rural("&nbsp;"), urbano("&nbsp;"), aislada("&nbsp;");

            if (uses.at(0).contains(QString::number(BcUses::Residencial)))
                residencial="X";
            if (uses.at(0).contains(QString::number(BcUses::Industrial)))
                industrial="X";
            if (uses.at(0).contains(QString::number(BcUses::Comercial)))
                comercial="X";
            if (uses.at(0).contains(QString::number(BcUses::ServicioPublico)))
                servicioPublico="X";
            if (uses.at(0).contains(QString::number(BcUses::ServicioPrivado)))
                servicioPrivado="X";
            if (uses.at(0).contains(QString::number(BcUses::Rural)))
                rural="X";
            if (uses.at(0).contains(QString::number(BcUses::Urbano)))
                urbano="X";
            if (uses.at(0).contains(QString::number(BcUses::AisladaDelSIN)))
                aislada="X";

            htmlString.replace("_XRes", residencial);
            htmlString.replace("_XInd", industrial);
            htmlString.replace("_XCom", comercial);
            htmlString.replace("_XSpu", servicioPublico);
            htmlString.replace("_XSpr", servicioPrivado);
            htmlString.replace("_XRur", rural);
            htmlString.replace("_XUrb", urbano);
            htmlString.replace("_XAis", aislada);

            htmlString.replace("_capacidad", dictumData.at(8));
            htmlString.replace("_tension", dictumData.at(9));
            htmlString.replace("_terminacion", QString::number(QDate::fromString(dictumData.at(11), "yyyy-MM-dd").year()));

            QString designersString, designersMpString;
            for (int i=0;i<designers.at(0).size();i++) {
                designersString.append(designers.at(0).at(i) + ", ");
                designersMpString.append(designers.at(1).at(i) + ", ");
            }
            designersString.remove(designersString.size()-2,2); // Remuevo la coma (,) y el espacio
            designersMpString.remove(designersMpString.size()-2,2);

            htmlString.replace("_disenador", designersString);
            htmlString.replace("_matriculaDis", designersMpString);
            htmlString.replace("_constructor", inspectionData.at(11));
            htmlString.replace("_matriculaCons", inspectionData.at(12));
            htmlString.replace("_interventor", inspectionData.at(13));
            htmlString.replace("_matriculaInt", inspectionData.at(14));
            htmlString.replace("_alcance", dictumData.at(6));

            QString aprobada("&nbsp;"), noAprobada("&nbsp;");
            if (dictumData.at(5) == "Conforme")
                aprobada="X";
            else
                noAprobada="X";

            htmlString.replace("_XAprob", aprobada);
            htmlString.replace("_XNoAprob", noAprobada);
            htmlString.replace("_inspector", inspector.at(0));
            htmlString.replace("_matriculaInsp", inspector.at(1));
        }
        break;
    }

    htmlString.replace("_RSPT", dictumData.at(8) + " Ohms");
    webView->setHtml(htmlString);
    webView->setZoomFactor(0.73);

}

void RenderDictumForm::printDictum()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setDocName(trUtf8("Dictamen - %1").arg(dictumNumber));
    printer.setPaperSize(QPrinter::A4);
    printer.setPageMargins(10,10,10,10,QPrinter::Millimeter);

#ifdef Q_OS_LINUX
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(QDir::homePath() +"/"+ printer.docName() + ".pdf");
#endif
    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    dialog->setWindowTitle(trUtf8("Imprimir Dictamen"));
    if ( dialog->exec() == QDialog::Accepted) {
        webView->setZoomFactor(1);
        //webView->page()->print(&printer, true);
        webView->setZoomFactor(0.73);
    }
}
