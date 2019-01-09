#include "subdictum.h"
#include "dbhandler.h"
#include "subdictumslist.h"

#include <QtSql>

SubDictumForm::SubDictumForm(QString subDictumOption, int index, QList<QStringList> subDictums_Data,
                             QStringList dictumData,  QList<QStringList> dictumReqsData, QDialog *parent) :
    QDialog(parent)
{
    setupUi(this);

    connect(updateSubDictumButton, SIGNAL(clicked()),
            this, SLOT(updateSubDictumAction()));

    connect(saveSubDictumButton, SIGNAL(clicked()),
            this, SLOT(saveSubDictum()));


    connect(prepareListButton, SIGNAL(clicked()),
            this, SLOT(processSubDictum()));

    if (!DbHandler::getProcesses(processesData))
        processesData.append(QStringList("Sin Datos"));

    subDictumsData=subDictums_Data;

    dictumId=dictumData.at(0);
    dictumNumber=dictumData.at(1);
    processId=dictumData.at(2);
    scope=dictumData.at(3);
    observations=dictumData.at(4);
    subDictumIndex=index;

    meetsClicks=0;
    noMeetsClicks=0;

    tableWidget->setColumnCount(5);
    tableWidget->setHorizontalHeaderLabels(QString("Item;Aspecto a Evaluar;Aplica;Cumple;No Cumple").split(";"));
    tableWidget->verticalHeader()->hide();
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    tableWidget->horizontalHeader()->resizeSection(0,35);
    tableWidget->horizontalHeader()->resizeSection(1,485);
    tableWidget->horizontalHeader()->resizeSection(2,50);
    tableWidget->horizontalHeader()->resizeSection(3,50);
    tableWidget->horizontalHeader()->resizeSection(4,70);

    if (!DbHandler::getRequirements(processId, requirementsData)) {
        QMessageBox::critical(this, trUtf8("Sin Datos"),
                              trUtf8("Error obteniendo los requerimientos\n"
                                     "ejecute el programa bajo consola y \n"
                                     "revise los mensajes"),
                              QMessageBox::Cancel);
    } else {
        tableWidget->setRowCount(requirementsData.at(1).size()); // Creo tantas filas como tamaño tengan los requerimientos

        for (int i=0; i < requirementsData.at(1).size(); i++) {
            // Cada documento creo un checkbox nuevo y le asigno de texto el nombre del documento
            QCheckBox *applyCheckBox = new QCheckBox;
            QCheckBox *meetsCheckBox = new QCheckBox;
            QCheckBox *noMeetsCheckBox = new QCheckBox;

            QSignalMapper* signalMapper1 = new QSignalMapper(this); // Necesario usar mapeo de la señal de cada CheckBox
            QSignalMapper* signalMapper2 = new QSignalMapper(this);
            QSignalMapper* signalMapper3 = new QSignalMapper(this);
            // Conectando la señal de cambio de estado con el slot del signalMapper
            connect(applyCheckBox, SIGNAL(toggled(bool)), signalMapper1, SLOT(map())) ;
            connect(meetsCheckBox, SIGNAL(toggled(bool)), signalMapper2, SLOT(map())) ;
            connect(noMeetsCheckBox, SIGNAL(toggled(bool)), signalMapper3, SLOT(map())) ;
            // Ligando el índice del checkbox en la lista con sigo mismo para enviarlo a través del signalMapper
            signalMapper1->setMapping(applyCheckBox, i) ;
            signalMapper2->setMapping(meetsCheckBox, i);
            signalMapper3->setMapping(noMeetsCheckBox, i);
            // Conectando el signalMapper con el slot para ajustar los checkbox de la otra lista
            connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(setAllMeetsCheckboxes(int))) ;
            connect(signalMapper2, SIGNAL(mapped(int)), this, SLOT(setNoMeetsCheckboxes(int))) ;
            connect(signalMapper3, SIGNAL(mapped(int)), this, SLOT(setMeetsCheckboxes(int))) ;

            applyCheckBoxes.append(applyCheckBox);
            meetsCheckBoxes.append(meetsCheckBox);
            noMeetsCheckBoxes.append(noMeetsCheckBox);

            tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
            tableWidget->setItem(i,1,new QTableWidgetItem(requirementsData.at(1).at(i)));
            tableWidget->setCellWidget(i,2,applyCheckBoxes.at(i));
            tableWidget->setCellWidget(i,3,meetsCheckBoxes.at(i));
            tableWidget->setCellWidget(i,4,noMeetsCheckBoxes.at(i));
        }
    }

    if (subDictumOption == "newSubDictum") {
        // Se rellenan los requerimientos igual que el están en el dictamen
        int index;
        for (int i=0; i<dictumReqsData.at(0).size();i++) {
            // indexOf me entrega la posición en la que está el id del documento, con esa posición
            // reemplazo el string vacío por el nombre del documento
            index=requirementsData.at(0).indexOf(dictumReqsData.at(0).at(i));
            if (index >=0) { // para prevenir el -1 al no encontrar el Id
                applyCheckBoxes.at(index)->setChecked(true);

                if (dictumReqsData.at(1).at(i) == "_")
                    meetsCheckBoxes.at(index)->setChecked(false);
                // No es necesario checkear el no cumple ya que está controlado por el disparo de la señal
            }
        }
        styleWithoutData();
        newSubDictum();
    }
     else {
        // Hay que llenar los controles
        styleWithData();
        fillSubDictumData();
    }

}

// NOTE: Funciones para manejar el comportamiento de los CheckBox
void SubDictumForm::setAllMeetsCheckboxes(int i)
{
    meetsCheckBoxes.at(i)->blockSignals(true);
    noMeetsCheckBoxes.at(i)->blockSignals(true);

    if (applyCheckBoxes.at(i)->checkState()==Qt::Checked) {
        meetsCheckBoxes.at(i)->setChecked(true);
        noMeetsCheckBoxes.at(i)->setChecked(false);
    } else {
        meetsCheckBoxes.at(i)->setChecked(false);
        noMeetsCheckBoxes.at(i)->setChecked(false);
    }

    meetsCheckBoxes.at(i)->blockSignals(false);
    noMeetsCheckBoxes.at(i)->blockSignals(false);
}

void SubDictumForm::setNoMeetsCheckboxes(int i)
{

    noMeetsCheckBoxes.at(i)->blockSignals(true);
    meetsCheckBoxes.at(i)->blockSignals(true);

    if (applyCheckBoxes.at(i)->checkState()==Qt::Checked) {
        if (meetsCheckBoxes.at(i)->checkState()==Qt::Checked)
            noMeetsCheckBoxes.at(i)->setChecked(false);
        else
            noMeetsCheckBoxes.at(i)->setChecked(true);
    } else {
        noMeetsClicks+=1;
        if (noMeetsClicks > 3) {
            QMessageBox::information(this, trUtf8("Ayuda"),
                                  trUtf8("El requerimiento debe aplicar para\n"
                                         "poder marcarlo como 'No Cumple'"),
                                  QMessageBox::Ok);
            noMeetsClicks=0;
        }
        meetsCheckBoxes.at(i)->setChecked(false);
        noMeetsCheckBoxes.at(i)->setChecked(false);
    }

    noMeetsCheckBoxes.at(i)->blockSignals(false);
    meetsCheckBoxes.at(i)->blockSignals(false);
}

void SubDictumForm::setMeetsCheckboxes(int i)
{
    noMeetsCheckBoxes.at(i)->blockSignals(true);
    meetsCheckBoxes.at(i)->blockSignals(true);

    if (applyCheckBoxes.at(i)->checkState()==Qt::Checked) {
        if (noMeetsCheckBoxes.at(i)->checkState()==Qt::Checked)
            meetsCheckBoxes.at(i)->setChecked(false);
        else
            meetsCheckBoxes.at(i)->setChecked(true);
    } else {
        meetsClicks+=1;
        if (meetsClicks > 3) {
            QMessageBox::information(this, trUtf8("Ayuda"),
                                  trUtf8("El requerimiento debe aplicar para\n"
                                         "poder marcarlo como 'Cumple'"),
                                  QMessageBox::Ok);
            meetsClicks=0;
        }
        meetsCheckBoxes.at(i)->setChecked(false);
        noMeetsCheckBoxes.at(i)->setChecked(false);
    }

    noMeetsCheckBoxes.at(i)->blockSignals(false);
    meetsCheckBoxes.at(i)->blockSignals(false);
}


// NOTE: Ajustar todo para un nuevo dictamen
void SubDictumForm::newSubDictum()
{
    subDictumStateLineEdit->setText("En Proceso");
    subDictumInstRateDoubleSpinBox->setValue(8.3);
    subDictumInstVoltageLineEdit->setText("120/208");
    subDictumInstRateDoubleSpinBox->setValue(4.3);
    subDictumDateEdit->setDate(QDate::currentDate());
    subDictumScopeTextEdit->setText(scope);
    subDictumObservTextEdit->setText(observations);
}

// NOTE: Procesar dictamen.
void SubDictumForm::processSubDictum()
{
    if (validateData()) {
        QStringList reqIds, reqMeets, reqNoMeets;
        bool agree;

        // Se recorren hasta que se encuentre algún No Cumple chequeado
        for (int i=0; i<noMeetsCheckBoxes.size();i++) {
            if (noMeetsCheckBoxes.at(i)->checkState() == Qt::Checked) {
                agree=false;
                break;
            } else
                agree=true;
        }

        // Se guardan los ids de los requerimientos y su estado
        for (int i=0; i<applyCheckBoxes.size();i++) {
            if (applyCheckBoxes.at(i)->checkState() == Qt::Checked) {
                reqIds.append(requirementsData.at(0).at(i));

                if (meetsCheckBoxes.at(i)->checkState() == Qt::Checked)
                    reqMeets.append("X");
                else
                    reqMeets.append("_");

                if (noMeetsCheckBoxes.at(i)->checkState() == Qt::Checked)
                    reqNoMeets.append("X");
                else
                    reqNoMeets.append("_");
                // Se guardan tal como deben quedar en el dictamen
            }
        }

        if (agree) {
            int ret1=QMessageBox::information(this, trUtf8("Consecutivos Conformes"),
                                              trUtf8("Los consecutivos se guardará como \"Conformes\"\n"
                                                     "Presione Si para guardarlo o Cancelar para corregir"),
                                              QMessageBox::Yes | QMessageBox::Cancel);
            if (ret1==QMessageBox::Yes)
                prepareSubDictumList("Conforme", reqIds, reqMeets, reqNoMeets);
        } else {
            int ret2=QMessageBox::warning(this, trUtf8("Consecutivos No Conforme"),
                                          trUtf8("Los consecutivos se crearán como \"No Conformes\"\n"
                                                 "Presione Si para guardarlo o Cancelar para corregir"),
                                          QMessageBox::Yes | QMessageBox::Cancel);
            if (ret2==QMessageBox::Yes)
                prepareSubDictumList("No Conforme", reqIds, reqMeets, reqNoMeets);
        }
    }

}

// NOTE: insercion de subdictamen
void SubDictumForm::prepareSubDictumList(QString techState, QStringList reqIds, QStringList reqMeets, QStringList reqNoMeets)
{
    QStringList subDictumData;
    QList<QStringList> reqResults;
    int start;

    reqResults.append(reqIds);
    reqResults.append(reqMeets);
    reqResults.append(reqNoMeets);

    subDictumData.append(dictumNumber);
    subDictumData.append(subDictumDateEdit->date().toString("yyyy-MM-dd"));
    subDictumData.append("Finalizada");
    subDictumData.append(techState);
    subDictumData.append(subDictumScopeTextEdit->toPlainText());
    subDictumData.append(subDictumObservTextEdit->toPlainText());
    subDictumData.append(subDictumTypeLineEdit->text());
    subDictumData.append(subDictumIdentifierLineEdit->text());
    subDictumData.append(subDictumLocationLineEdit->text());
    subDictumData.append(QString::number(subDictumInstRateDoubleSpinBox->value()));
    subDictumData.append(subDictumInstVoltageLineEdit->text());
    subDictumData.append(QString::number(subDictumInstResDoubleSpinBox->value()));
    subDictumData.append(dictumId);

        // Con esto se sabe cuantos consecutivos hay para empezar desde el último, en caso de
    // añadir consectivos a un dictamen.
    if (subDictumsData.size()!=0)
        start=subDictumsData.at(0).size()+1;
    else
        start=1; // Si no hay consecutivos se arranca en 1.

    SubDictumsListForm subDictumListForm(subDictumData, reqResults, start, subDictumsNumberSpinBox->value());
    subDictumListForm.exec();

    if (subDictumListForm.success) {

            QString subTopId, subDictumNumber;

            subDictumNumber=dictumNumber + "-" + QString::number(start);
            subTopId=dictumNumber + "-" + QString::number(start + subDictumsNumberSpinBox->value()-1);

            subDictumNumberLineEdit->setText(subDictumNumber);
            subDictumTechStateLineEdit->setText(techState);

            QMessageBox::information(this, trUtf8("Consecutivos Guardados"),
                                     trUtf8("Se han guardado los consecutivos " + subDictumNumber.toUtf8() +
                                            " al "+ subTopId.toUtf8() + " correctamente"),
                                     QMessageBox::Ok);
            styleWithData();

            subDictumsNumberSpinBox->setEnabled(false);
            prepareListButton->setEnabled(false);
            updateSubDictumButton->setEnabled(false); // Se desactiva para obligar a cerrar la ventana si se quiere actualizar.
            updateSubDictumButton->setToolTip("Si desea actualizar datos es necesario cerrar esta ventana");
        }
}

// NOTE: Guardar cambios de dictamen.
void SubDictumForm::saveSubDictum()
{
    if (validateData()) {
        QStringList reqIds, reqMeets, reqNoMeets;
        bool agree;

        // Se recorren hasta que se encuentre algún No Cumple chequeado
        for (int i=0; i<noMeetsCheckBoxes.size();i++) {
            if (noMeetsCheckBoxes.at(i)->checkState() == Qt::Checked) {
                agree=false;
                break;
            } else
                agree=true;
        }

        // Se guardan los ids de los requerimientos y su estado
        for (int i=0; i<applyCheckBoxes.size();i++) {
            if (applyCheckBoxes.at(i)->checkState() == Qt::Checked) {
                reqIds.append(requirementsData.at(0).at(i));

                if (meetsCheckBoxes.at(i)->checkState() == Qt::Checked)
                    reqMeets.append("X");
                else
                    reqMeets.append("_");

                if (noMeetsCheckBoxes.at(i)->checkState() == Qt::Checked)
                    reqNoMeets.append("X");
                else
                    reqNoMeets.append("_");
                // Se guardan tal como deben quedar en el dictamen
            }
        }

        if (agree) {
            int ret1=QMessageBox::information(this, trUtf8("Consecutivo Conforme"),
                                              trUtf8("El consecutivo se actualizará como Conforme\n"
                                                     "Presione Si para actualizarlo o Cancelar para corregir"),
                                              QMessageBox::Yes | QMessageBox::Cancel);
            if (ret1==QMessageBox::Yes) {
               updateSubDictum("Conforme", reqIds, reqMeets, reqNoMeets);
               subDictumTechStateLineEdit->setText("Conforme");
               styleWithData();
            }
        } else {
            int ret2=QMessageBox::warning(this, trUtf8("Consecutivo No Conforme"),
                                          trUtf8("El consecutivo se actualizará como No Conforme\n"
                                                 "Presione Si para actualizarlo o Cancelar para corregir"),
                                          QMessageBox::Yes | QMessageBox::Cancel);
            if (ret2==QMessageBox::Yes) {
                updateSubDictum("No Conforme", reqIds, reqMeets, reqNoMeets);
                subDictumTechStateLineEdit->setText("No Conforme");
                styleWithData();
            }
        }
    }

}

// NOTE: actualizar dictamen
void SubDictumForm::updateSubDictum(QString techState, QStringList reqIds, QStringList reqMeets, QStringList reqNoMeets)
{
    QStringList subDictumData;
    QList<QStringList> reqResults;

    reqResults.append(reqIds);
    reqResults.append(reqMeets);
    reqResults.append(reqNoMeets);

    subDictumData.append(subDictumsData.at(0).at(subDictumIndex));
    subDictumData.append(subDictumDateEdit->date().toString("yyyy-MM-dd"));
    subDictumData.append("Finalizada");
    subDictumData.append(techState);
    subDictumData.append(subDictumScopeTextEdit->toPlainText());
    subDictumData.append(subDictumObservTextEdit->toPlainText());
    subDictumData.append(subDictumTypeLineEdit->text());
    subDictumData.append(subDictumIdentifierLineEdit->text());
    subDictumData.append(subDictumLocationLineEdit->text());
    subDictumData.append(QString::number(subDictumInstRateDoubleSpinBox->value()));
    subDictumData.append(subDictumInstVoltageLineEdit->text());
    subDictumData.append(QString::number(subDictumInstResDoubleSpinBox->value()));

    if (!DbHandler::updateSubDictum(subDictumData, reqResults))
        QMessageBox::warning(this, trUtf8("Error actualizando datos"),
                             trUtf8("Error actualizando el dictamen. Ejecute el\n"
                                    "programa bajo consola y revise los mensajes"),
                             QMessageBox::Cancel);
    else {
            QMessageBox::information(this, trUtf8("Dictamen Actualizado"),
                                     trUtf8("Se ha actualizado el dictamen " + subDictumNumberLineEdit->text().toUtf8() + " correctamente"),
                                     QMessageBox::Ok);
        }
}

// NOTE: llenado de datos del dictamen
void SubDictumForm::fillSubDictumData()
{
    QList<QStringList> subDictumReqsData;

    subDictumNumberLineEdit->setText(subDictumsData.at(1).at(subDictumIndex));
    subDictumDateEdit->setDate(QDate::fromString(subDictumsData.at(2).at(subDictumIndex), "yyyy-MM-dd"));
    subDictumStateLineEdit->setText(subDictumsData.at(3).at(subDictumIndex));
    subDictumTechStateLineEdit->setText(subDictumsData.at(4).at(subDictumIndex));
    subDictumScopeTextEdit->setHtml(subDictumsData.at(5).at(subDictumIndex));
    subDictumObservTextEdit->setHtml(subDictumsData.at(6).at(subDictumIndex));
    subDictumTypeLineEdit->setText(subDictumsData.at(7).at(subDictumIndex));
    subDictumIdentifierLineEdit->setText(subDictumsData.at(8).at(subDictumIndex));
    subDictumLocationLineEdit->setText(subDictumsData.at(9).at(subDictumIndex));
    subDictumInstRateDoubleSpinBox->setValue(subDictumsData.at(10).at(subDictumIndex).toDouble());
    subDictumInstVoltageLineEdit->setText(subDictumsData.at(11).at(subDictumIndex));
    subDictumInstResDoubleSpinBox->setValue(subDictumsData.at(12).at(subDictumIndex).toDouble());

    if (!DbHandler::getSubDictumReqs(subDictumsData.at(0).at(subDictumIndex), subDictumReqsData))
        QMessageBox::warning(this, trUtf8("Error obteniendo datos"),
                             trUtf8("Error obteniendo requerimientos guardados. Ejecute el\n"
                                    "programa bajo consola y revise los mensajes"),
                             QMessageBox::Cancel);
    else {
        int index;
        for (int i=0; i<subDictumReqsData.at(0).size();i++) {
            // indexOf me entrega la posición en la que está el id del documento, con esa posición
            // reemplazo el string vacío por el nombre del documento
            index=requirementsData.at(0).indexOf(subDictumReqsData.at(0).at(i));
            if (index >=0) { // para prevenir el -1 al no encontrar el Id
                applyCheckBoxes.at(index)->setChecked(true);

                if (subDictumReqsData.at(1).at(i) == "_")
                    meetsCheckBoxes.at(index)->setChecked(false);

                // No es necesario checkear el no cumple ya que está controlado por el disparo de la señal
            }
        }
    }
}

// Valida que los datos de entrada esten completos
bool SubDictumForm::validateData()
{
    if (subDictumTypeLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El tipo de unidad es obligatorio"),
                             QMessageBox::Ok);
        subDictumTypeLineEdit->setFocus();
        return false;
    }

    if (subDictumIdentifierLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El identificador es obligatorio"),
                             QMessageBox::Ok);
        subDictumIdentifierLineEdit->setFocus();
        return false;
    }

    if (subDictumLocationLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("La localización es obligatoria"),
                             QMessageBox::Ok);
        subDictumLocationLineEdit->setFocus();
        return false;
    }

    if (subDictumInstRateDoubleSpinBox->value()==0) {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("La potencia no debe ser cero"),
                             QMessageBox::Ok);
        subDictumInstRateDoubleSpinBox->setFocus();
        return false;
    }

    if (subDictumInstVoltageLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("La tensión no debe ser cero"),
                             QMessageBox::Ok);
        subDictumInstVoltageLineEdit->setFocus();
        return false;
    }

    if (subDictumScopeTextEdit->toPlainText()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El alcance es obligatorio"),
                             QMessageBox::Ok);
        subDictumScopeTextEdit->setFocus();
        return false;
    }

    return true;
}

void SubDictumForm::updateSubDictumAction()
{
    styleWithoutData();
    saveSubDictumButton->setEnabled(true);
}



void SubDictumForm::styleWithData()
{
    subDictumTypeLineEdit->setStyleSheet("background-color: rgb(200, 200, 200);\n"
                                         "font: 75 oblique 10pt \"DejaVu Sans\";");
    subDictumIdentifierLineEdit->setStyleSheet("background-color: rgb(200, 200, 200);\n"
                                               "font: 75 oblique 10pt \"DejaVu Sans\";");
    subDictumLocationLineEdit->setStyleSheet("background-color: rgb(200, 200, 200);\n"
                                             "font: 75 oblique 10pt \"DejaVu Sans\";");
    subDictumNumberLineEdit->setStyleSheet("background-color: rgb(200, 200, 200);\n"
                                           "font: 75 oblique 10pt \"DejaVu Sans\";");
    subDictumInstRateDoubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                              "font: 75 oblique 10pt \"DejaVu Sans\";"));
    subDictumInstVoltageLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                                  "font: 75 oblique 10pt \"DejaVu Sans\";"));
    subDictumInstResDoubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                              "font: 75 oblique 10pt \"DejaVu Sans\";"));
    subDictumDateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                       "font: 75 oblique 10pt \"DejaVu Sans\";"));

    subDictumTypeLineEdit->setReadOnly(true);
    subDictumIdentifierLineEdit->setReadOnly(true);
    subDictumLocationLineEdit->setReadOnly(true);
    subDictumNumberLineEdit->setReadOnly(true);
    subDictumInstRateDoubleSpinBox->setReadOnly(true);
    subDictumInstVoltageLineEdit->setReadOnly(true);
    subDictumInstResDoubleSpinBox->setReadOnly(true);
    subDictumDateEdit->setReadOnly(true);

    subDictumScopeTextEdit->setReadOnly(true);
    subDictumObservTextEdit->setReadOnly(true);
    labelSubDictums->hide();
    subDictumsNumberSpinBox->hide();
    prepareListButton->hide();

    updateSubDictumButton->setEnabled(true);
    saveSubDictumButton->setEnabled(false);

    for (int i=0; i<requirementsData.at(0).size();i++) {
        applyCheckBoxes.at(i)->setEnabled(false);
        meetsCheckBoxes.at(i)->setEnabled(false);
        noMeetsCheckBoxes.at(i)->setEnabled(false);
    }

}

void SubDictumForm::styleWithoutData()
{
    subDictumTypeLineEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    subDictumIdentifierLineEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    subDictumLocationLineEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    subDictumInstRateDoubleSpinBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    subDictumInstVoltageLineEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    subDictumInstResDoubleSpinBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    subDictumDateEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");

    subDictumTypeLineEdit->setReadOnly(false);
    subDictumIdentifierLineEdit->setReadOnly(false);
    subDictumLocationLineEdit->setReadOnly(false);
    subDictumInstRateDoubleSpinBox->setReadOnly(false);
    subDictumInstVoltageLineEdit->setReadOnly(false);
    subDictumInstResDoubleSpinBox->setReadOnly(false);
    subDictumDateEdit->setReadOnly(false);

    subDictumScopeTextEdit->setReadOnly(false);
    subDictumObservTextEdit->setReadOnly(false);

    updateSubDictumButton->setEnabled(false);
    saveSubDictumButton->setEnabled(false);

    for (int i=0; i<requirementsData.at(0).size();i++) {
        applyCheckBoxes.at(i)->setEnabled(true);
        meetsCheckBoxes.at(i)->setEnabled(true);
        noMeetsCheckBoxes.at(i)->setEnabled(true);
    }
}
