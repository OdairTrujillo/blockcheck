#include "sales.h"
#include "dbhandler.h"

#include "userlib/filterquotations.h"
#include "userlib/filterproposals.h"
#include "userlib/filterserviceorders.h"
#include "userlib/tools.h"
#include "userlib/bcnamespace.h"
#include "userlib/logger.h"


void SalesForm::fillQuotControls()
{

    // NOTE: Llenado de valores por defecto para la cotizacion

    oldTabIndex=salesTabWidget->currentIndex();
    findComboBox->addItem(trUtf8("Nit o CC"));
    findComboBox->addItem(trUtf8("Propuesta"));
    findComboBox->addItem(trUtf8("Orden de Servicio"));

    nextButton->setEnabled(false);
    prevButton->setEnabled(false);
    updateButton->setEnabled(false);
    deleteButton->setEnabled(false);

    found=0;

    if (DbHandler::getStates(statesData)) {
        quotStateComboBox->addItems(statesData.at(2));
        thrdStateComboBox->addItems(statesData.at(2)); // en la posicion [1] estan los nombres en la [0] los id
    } else {
        quotStateComboBox->addItem("Sin Datos");
        thrdStateComboBox->addItem("Sin Datos");
    }

    if (DbHandler::getCities(statesData.at(0).at(0), quotCitiesData)) {  // [0][0] se refiere la primer columna y el primer registro
        thrdCitiesData=quotCitiesData; // Me evito llamar dos veces a la función getCities
        quotCityComboBox->addItems(quotCitiesData.at(2));
        thrdCityComboBox->addItems(quotCitiesData.at(2));
    } else {
        quotCityComboBox->addItem("Sin Datos");
        thrdCityComboBox->addItem("Sin Datos");
    }

    // Lleno el listwidget con los procesos existentes
    if (DbHandler::getProcesses(processesData))
        processesListWidget->addItems(processesData.at(1));
    else
        processesListWidget->addItem("Sin Datos");

    if (DbHandler::getUses(usesData))
        useTypeComboBox->addItems(usesData.at(1));
    else
        useTypeComboBox->addItem("Sin Datos");

    quotDateEdit->setDate(QDate::currentDate());

    quot_position=0;
    // Esto se hace para evitar un crash en autoFindSometing cuando no se han buscado datos
    quotsData.append(QStringList("0"));
}

// NOTE: Llenado de valores por defectos en Propuesta comercial
void SalesForm::fillPropControls()
{
    if (DbHandler::getUsers(usersData))
        // Cargo el nombre largo
        propSoldByComboBox->addItems(usersData.at(3));
    else
        propSoldByComboBox->addItem("Sin Datos");

    propDateEdit->setDate(QDate::currentDate());

    propPayWayComboBox->addItem(trUtf8("50% - 50%"));
    propPayWayComboBox->addItem(trUtf8("100%"));
    propPayWayComboBox->addItem(trUtf8("A Convenir"));

    // propValueModel es miembro de la clase y sirve para mostrar los datos
    // de precios de la propuesta comercial en forma de tabla.
    int ncol=2, nrow=4;

    propValueModel = new QStandardItemModel(nrow, ncol);
    propValueModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Detalle")));
    propValueModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Valor")));
    // haciendo ajuste automatico de ancho de columna
    propValueTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //llenado de los valores del modelo
    propValueModel->setItem(0, 0, new QStandardItem(QString::fromUtf8("Inspección")));
    propValueModel->setItem(1, 0, new QStandardItem(QString::fromUtf8("IVA")));
    propValueModel->setItem(2, 0, new QStandardItem(QString::fromUtf8("Viáticos")));
    propValueModel->setItem(3, 0, new QStandardItem(QString::fromUtf8("TOTAL")));
    propValueModel->setItem(0, 1, new QStandardItem(QString::fromUtf8("")));
    propValueModel->setItem(1, 1, new QStandardItem(QString::fromUtf8("")));
    propValueModel->setItem(2, 1, new QStandardItem(QString::fromUtf8("")));
    propValueModel->setItem(3, 1, new QStandardItem(QString::fromUtf8("")));

     // aplico estilos a los items
    QFont font("Dejavu Sans");
    font.setBold(true);

    propValueModel->item(3,0)->setFont(font);
    propValueModel->item(3,1)->setFont(font);
    // Poniendo no editable la columna 0 del modelo.
    for (int i=0; i<propValueModel->rowCount(); i++)
        propValueModel->item(i,0)->setFlags(propValueModel->item(i,0)->flags() & ~Qt::ItemIsEditable);
    // No editable el IVA y Total
    propValueModel->item(1,1)->setFlags(propValueModel->item(1,1)->flags() & ~Qt::ItemIsEditable);
    propValueModel->item(3,1)->setFlags(propValueModel->item(3,1)->flags() & ~Qt::ItemIsEditable);

    propValueTableView->setModel(propValueModel);


    spinBoxDelegate = new SpinBoxDelegate("money");
    propValueTableView->setItemDelegateForColumn(1, spinBoxDelegate);

    prop_position=0;
    // Esto se hace para evitar un crash en autoFindSometing cuando no se han buscado datos
    propsData.append(QStringList("0"));

    // Obtengo la lista de documentos a ser marcados posteriormente
    if (DbHandler::getDocuments(documentsData, QString("RETIE")))
        for (int i=0; i<documentsData.at(1).size();i++) {
            propDocsListWidget->addItem(documentsData.at(1).at(i));
            propDocsListWidget->item(i)->setToolTip(documentsData.at(1).at(i));
            propDocsListWidget->item(i)->setSizeHint(QSize(320, 18));
        }
    else
        propDocsListWidget->addItem("Sin Datos");

}

// NOTE: Llenado de controles de ordenes de servicio
void SalesForm::fillSoControls()
{
    if (DbHandler::getInspectors(inspectorsData, "Disponibles"))
        soInspectorsComboBox->addItems(inspectorsData.at(1));
    else
        soInspectorsComboBox->addItem("Sin Datos");

    // Obtengo los distintos folios o AZ
    if (!DbHandler::getRecords(recordsData))
        recordsData.append(QStringList("Sin Datos"));
    for (int i=0; i<recordsData.at(1).size();i++) {
        QListWidgetItem *item = new QListWidgetItem;
        item->setData( Qt::DisplayRole, recordsData.at(1).at(i));
        item->setData( Qt::CheckStateRole, Qt::Unchecked);
        recordFoilListWidget->addItem( item );
    }
}

// NOTE: Crea y aplica validadores
void SalesForm::setValidators()
{
    QValidator *intValidator = new QDoubleValidator(0, 9999999999, 0, this);

    //thrdRepIdLineEdit->setValidator(intValidator);
}

// NOTE: Llenado de datos de la cotizacion
void SalesForm::fillQuotData()
{

    QStringList procsIds;
    DbHandler::getProcesses(quotsData.at(0).at(quot_position), procsIds);

    thrdNitLineEdit->setText(thrdData.at(1));
    thrdNameLineEdit->setText(thrdData.at(2));
    thrdRepLineEdit->setText(thrdData.at(3));
    //thrdRepIdLineEdit->setText(thrdData.at(4));
    thrdAddressLineEdit->setText(thrdData.at(5));
    thrdMailLineEdit->setText(thrdData.at(6));
    thrdPhoneLineEdit->setText(thrdData.at(7));
    thrdFaxLineEdit->setText(thrdData.at(8));
    thrdStateComboBox->setCurrentIndex(thrdStateComboBox->findText(thrdData.at(9)));
    thrdCityComboBox->setCurrentIndex(thrdCityComboBox->findText(thrdData.at(10)));

    quotDateEdit->setDate(QDate::fromString(quotsData.at(1).at(quot_position), "yyyy-MM-dd"));
    quotNameLineEdit->setText(quotsData.at(2).at(quot_position));
    quotScopeTextEdit->setText(quotsData.at(3).at(quot_position));
    quotContactLineEdit->setText(quotsData.at(4).at(quot_position));
    quotAddressLineEdit->setText(quotsData.at(5).at(quot_position));
    quotMailLineEdit->setText(quotsData.at(6).at(quot_position));
    quotPhoneLineEdit->setText(quotsData.at(7).at(quot_position));
    quotFaxLineEdit->setText(quotsData.at(8).at(quot_position));
    // findText devuelve la posicion en la que coincide el texto
    quotStateComboBox->setCurrentIndex(quotStateComboBox->findText(quotsData.at(9).at(quot_position)));
    quotCityComboBox->setCurrentIndex(quotCityComboBox->findText(quotsData.at(10).at(quot_position)));
    useTypeComboBox->setCurrentIndex(useTypeComboBox->findText(quotsData.at(11).at(quot_position)));
    inspecTypeComboBox->setCurrentIndex(inspecTypeComboBox->findText(quotsData.at(12).at(quot_position)));

    int index;
    processesListWidget->clearSelection();
    for (int i=0; i<procsIds.size();i++) {
        index=processesData.at(0).indexOf(procsIds.at(i));
        processesListWidget->item(index)->setSelected(true);
    }



}
// NOTE: Llenado de datos de la propuesta
void SalesForm::fillPropData()
{

    // TODO: dependiendo del pedido del cliente agregar a la DB viaticos e iva por separado
    propIdLineEdit->setText(propsData.at(Props::Id).at(0));
    propScopeTextEdit->setText(propsData.at(Props::Scope).at(0));
    propDateEdit->setDate(QDate::fromString(propsData.at(Props::Date).at(0), "yyyy-MM-dd"));
    propPayWayComboBox->setCurrentIndex(propPayWayComboBox->findText(propsData.at(Props::PayWay).at(0)));
    propUserPercSpinBox->setValue(propsData.at(Props::UserPerc).at(0).toDouble()*100);
    propStateLineEdit->setText(propsData.at(Props::PState).at(0));
    propStateDetailLineEdit->setText(propsData.at(Props::Aproval).at(0));
    propLocalizationLineEdit->setText(propsData.at(Props::Addrs).at(0) + " - " + propsData.at(Props::City).at(0));
    propInstNameLineEdit->setText(propsData.at(Props::InstName).at(0));
    propSoldByComboBox->setCurrentIndex(propSoldByComboBox->findText(propsData.at(Props::UserLName).at(0)));

    // Obtengo los documentos de la propuesta para ser marcados en la lista
    // que se obtuvo al preparar los controles de propuesta
    QStringList propDocsIds;
    if (DbHandler::getPropDocuments(propsData.at(Props::Id).at(0), propDocsIds)) {
        int index;
        propDocsListWidget->clearSelection();
        for (int i=0; i<propDocsIds.size();i++) {
            // usando el indice correspondiente a la lista de documentos, marco el
            // documento en el listWidget
            index=documentsData.at(0).indexOf(propDocsIds.at(i));
            propDocsListWidget->item(index)->setSelected(true);
        }
    } else
        QMessageBox::critical(this, trUtf8("Sin Datos"),
                              trUtf8("No hay documentos seleccionados para la propuesta" +
                                     findLineEdit->text().toUtf8()),
                              QMessageBox::Cancel);

    propThrdNameLineEdit->setText(propsData.at(Props::thrdName).at(prop_position));
    propObservTextEdit->setText(propsData.at(Props::Observ).at(prop_position));

    propValueModel->setItem(0,1, new QStandardItem(propsData.at(Props::ValueMoney).at(prop_position))); // inpeccion
    propValueModel->setItem(1,1, new QStandardItem(propsData.at(Props::Iva).at(prop_position))); // iva
    propValueModel->setItem(2,1, new QStandardItem(propsData.at(Props::Viatic).at(prop_position))); // viaticos
    propValueModel->setItem(3,1, new QStandardItem(propsData.at(Props::TotVal).at(prop_position))); // total

    //propOutWebView->setHtml("");


}

// NOTE: Llenado de datos de orden de servicio
void SalesForm::fillSoData()
{
    soIdLineEdit->setText(sosData.at(Sos::Id).at(0));
    soDateEdit->setDate(QDate::fromString(sosData.at(Sos::Date).at(0), "yyyy-MM-dd"));
    soScopeTextEdit->setText(sosData.at(Sos::Scope).at(0));
    soObservTextEdit->setText(sosData.at(Sos::Observ).at(0));
    soInspectorsComboBox->setCurrentIndex(soInspectorsComboBox->findText(sosData.at(Sos::InspName).at(0)));
    soInspPercSpinBox->setValue(sosData.at(Sos::InspPerc).at(0).toFloat()*100);
    soAssignDateEdit->setDate(QDate::fromString(sosData.at(Sos::AssignD).at(0), "yyyy-MM-dd"));
    soAccStateLineEdit->setText(sosData.at(Sos::AccProc).at(0));
    soAdmObservTextEdit->setText(sosData.at(Sos::AdmObserv).at(0));

    // Deschequear primero para luego seleccionar las AZ.
    for (int i=0; i<recordFoilListWidget->count(); i++)
        recordFoilListWidget->item(i)->setCheckState(Qt::Unchecked);

    QStringList recordsIds;
    DbHandler::getSoRecords(sosData.at(Sos::Id).at(0), recordsIds);
    int index;

    for (int i=0; i<recordsIds.size();i++) {
        index=recordsData.at(0).indexOf(recordsIds.at(i));
        recordFoilListWidget->item(index)->setCheckState(Qt::Checked);
    }

    //soOutWebView->setHtml("");
//    propValueModel->item(1,1)->setFlags(propValueModel->item(1,1)->flags() & ~Qt::ItemIsEditable);
//    propValueModel->item(3,1)->setFlags(propValueModel->item(3,1)->flags() & ~Qt::ItemIsEditable);

}

// NOTE: Limpia los controles del tercero para una nueva insercion
void SalesForm::clearThrdQuotControls()
{
    quotNameLineEdit->clear();
    quotAddressLineEdit->clear();
    quotContactLineEdit->clear();
    quotDateEdit->setDate(QDate::currentDate());
    quotMailLineEdit->clear();
    quotPhoneLineEdit->clear();
    quotPhoneLineEdit->clear();
    quotScopeTextEdit->clear();
    quotFaxLineEdit->clear();
    quotLCD->display(0);
    foundLCD->display(0);

    thrdAddressLineEdit->clear();
    thrdFaxLineEdit->clear();
    thrdMailLineEdit->clear();
    thrdMailLineEdit->clear();
    thrdNameLineEdit->clear();
    thrdNitLineEdit->clear();
    thrdPhoneLineEdit->clear();
    //thrdRepIdLineEdit->clear();
    thrdRepLineEdit->clear();

    thrdStateComboBox->setCurrentIndex(0);
    setThrdCity(0);
    quotStateComboBox->setCurrentIndex(0);
    setQuotCity(0);
    inspecTypeComboBox->setCurrentIndex(0);
    useTypeComboBox->setCurrentIndex(0);
    processesListWidget->clearSelection();

    quotNameLineEdit->setFocus();
}
// NOTE: Limpiar controles de cotizacion para insertar una nueva
void SalesForm::clearQuotControls()
{
    quotNameLineEdit->clear();
    quotAddressLineEdit->clear();
    quotContactLineEdit->clear();
    quotDateEdit->setDate(QDate::currentDate());
    quotMailLineEdit->clear();
    quotPhoneLineEdit->clear();
    quotPhoneLineEdit->clear();
    quotScopeTextEdit->clear();
    quotFaxLineEdit->clear();

    quotStateComboBox->setCurrentIndex(0);
    setQuotCity(0);
    inspecTypeComboBox->setCurrentIndex(0);
    useTypeComboBox->setCurrentIndex(0);
    processesListWidget->clearSelection();



}

// NOTE: Limpiar controles de propuesta comercial
void SalesForm::clearPropControls()
{

    propDateEdit->setDate(QDate::currentDate());
    propThrdNameLineEdit->clear();
    propInstNameLineEdit->clear();
    propLocalizationLineEdit->clear();
    propIdLineEdit->clear();
    propScopeTextEdit->clear();
    propDocsListWidget->clearSelection();
    propObservTextEdit->clear();
    //propOutWebView->setHtml("");

    for (int i=0; i<propValueModel->rowCount(); i++)
        propValueModel->setItem(i,1, new QStandardItem(QString::fromUtf8("")));

    propPayWayComboBox->setCurrentIndex(0);
    propSoldByComboBox->setCurrentIndex(0);
    propUserPercSpinBox->setValue(20);
    propStateLineEdit->clear();
    propStateDetailLineEdit->clear();

    propApprovButton->setEnabled(false);
    propRejectButton->setEnabled(false);



}

// NOTE: Limpiar controles de orden de servicio
void SalesForm::clearSoControls()
{
    soDateEdit->setDate(QDate::currentDate());
    soIdLineEdit->clear();
    // Deschequear primero para luego seleccionar las AZ.
    for (int i=0; i<recordFoilListWidget->count(); i++)
        recordFoilListWidget->item(i)->setCheckState(Qt::Unchecked);
    soScopeTextEdit->clear();
    soObservTextEdit->clear();
    soInspectorsComboBox->setCurrentIndex(0);
    soInspPercSpinBox->setValue(20);
    soAssignDateEdit->setDate(QDate::currentDate());
    soAccStateLineEdit->clear();
    soAdmObservTextEdit->clear();
    //soOutWebView->setHtml("");
}

// NOTE: Preparar controles de propuesta comercial
void SalesForm::preparePropControls()
{
    propDateEdit->setDate(QDate::currentDate());
    propThrdNameLineEdit->setText(thrdRepLineEdit->text());
    propInstNameLineEdit->setText(quotNameLineEdit->text());
    propLocalizationLineEdit->setText(quotCityComboBox->currentText() + " - " + quotAddressLineEdit->text());
    propIdLineEdit->clear();
    propUserPercSpinBox->setValue(20);
    propScopeTextEdit->setText(quotScopeTextEdit->toPlainText());
    propDocsListWidget->selectAll();
    //propOutWebView->setHtml("");

    for (int i=0; i<propValueModel->rowCount(); i++)
        propValueModel->setItem(i,1, new QStandardItem(QString::fromUtf8("")));

    propPayWayComboBox->setCurrentIndex(0);
    propSoldByComboBox->setCurrentIndex(0);
    propUserPercSpinBox->setValue(20);
    propStateLineEdit->clear();
    propStateDetailLineEdit->clear();

    propApprovButton->setEnabled(false);
    propRejectButton->setEnabled(false);

    propScopeTextEdit->setFocus();

}

// NOTE: Preparar controles de orden de servicio
void SalesForm::prepareSoControls()
{
    soDateEdit->setDate(QDate::currentDate());
    soIdLineEdit->clear();
    // Deschequear primero para luego seleccionar las AZ.
    for (int i=0; i<recordFoilListWidget->count(); i++)
        recordFoilListWidget->item(i)->setCheckState(Qt::Unchecked);
    soInspectorsComboBox->setCurrentIndex(0);
    soAssignDateEdit->setDate(QDate::currentDate());
    soAccStateLineEdit->clear();
    soObservTextEdit->clear();
    soAdmObservTextEdit->clear();
    //soOutWebView->setHtml("");

    soScopeTextEdit->setText(propScopeTextEdit->toPlainText());

    soScopeTextEdit->setFocus();
}

// NOTE:validar que los datos existan y tengan el formato correcto
// TODO: validar el formato de los telefonos o aplicarles mascara
bool SalesForm::validateQuotData()
{

    if (quotNameLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El nombre de la instalación es obligatorio"),
                             QMessageBox::Ok);
        scrollArea->verticalScrollBar()->setValue(0);
        quotNameLineEdit->setFocus();
        return false;
    }
    if (quotAddressLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("La dirección de la instalación es obligatoria"),
                             QMessageBox::Ok);
        scrollArea->verticalScrollBar()->setValue(0);
        quotAddressLineEdit->setFocus();
        return false;
    }
    if (quotContactLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("La persona de contacto es obligatoria"),
                             QMessageBox::Ok);
        scrollArea->verticalScrollBar()->setValue(0);
        quotContactLineEdit->setFocus();
        return false;
    }
    if (quotPhoneLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El teléfono de contacto es obligatorio"),
                             QMessageBox::Ok);
        scrollArea->verticalScrollBar()->setValue(0);
        quotPhoneLineEdit->setFocus();
        return false;
    }

    if (quotFaxLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El teléfono de contacto es obligatorio"),
                             QMessageBox::Ok);
        scrollArea->verticalScrollBar()->setValue(0);
        quotFaxLineEdit->setFocus();
        return false;
    }

    if (quotScopeTextEdit->toPlainText()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El alcance es obligatorio"),
                             QMessageBox::Ok);
        scrollArea->verticalScrollBar()->setValue(0);
        quotScopeTextEdit->setFocus();
        return false;
    }
    if (thrdNameLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El nombre de la empresa es obligatorio"),
                             QMessageBox::Ok);
        thrdNameLineEdit->setFocus();
        return false;
    }
    if (thrdNitLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El NIT de la empresa es obligatorio"),
                             QMessageBox::Ok);
        thrdNitLineEdit->setFocus();
        return false;
    }

    // Se retiran por petición del cliente
//    if (thrdPhoneLineEdit->text()=="") {
//        QMessageBox::warning(this, trUtf8("Faltan Datos"),
//                             trUtf8("El teléfono de la empresa es obligatorio"),
//                             QMessageBox::Ok);
//        thrdPhoneLineEdit->setFocus();
//        return false;
//    }
//    if (thrdRepIdLineEdit->text()=="") {
//        QMessageBox::warning(this, trUtf8("Faltan Datos"),
//                             trUtf8("La cédula del representante es obligatorio"),
//                             QMessageBox::Ok);
//        thrdRepIdLineEdit->setFocus();
//        return false;
//    }
//    if (thrdRepLineEdit->text()=="") {
//        QMessageBox::warning(this, trUtf8("Faltan Datos"),
//                             trUtf8("El nombre del representante es obligatorio"),
//                             QMessageBox::Ok);
//        thrdRepLineEdit->setFocus();
//        return false;
//    }

    QModelIndexList processesIndexes = processesListWidget->selectionModel()->selectedIndexes();
    if (processesIndexes.size() == 0) {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("Es obligatorio por lo menos un proceso"),
                             QMessageBox::Ok);
        processesListWidget->setFocus();
        return false;
    }


    return true;
 }

//NOTE: Validar los datos de la propuesta
bool SalesForm::validatePropData()
{
    if (propThrdNameLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El representante legal es obligatorio"),
                             QMessageBox::Ok);
        propThrdNameLineEdit->setFocus();
        return false;
    }

    if (propInstNameLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El nombre de la instalación es obligatorio"),
                             QMessageBox::Ok);
        propInstNameLineEdit->setFocus();
        return false;
    }

    if (propValueModel->data(propValueModel->index(0,1), Qt::EditRole).toString()==""
            || propValueModel->data(propValueModel->index(0,1), Qt::EditRole).toString()=="0") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El Valor de La inspección es obligatorio"),
                             QMessageBox::Ok);
        return false;
    }


    if (propScopeTextEdit->toPlainText()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El alcance es obligatorio"),
                             QMessageBox::Ok);
        propScopeTextEdit->setFocus();
        return false;
    }

    if (propDocsListWidget->selectionModel()->selectedIndexes().size()<5) {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("Faltan requerimientos por seleccionar"),
                             QMessageBox::Ok);
        propDocsListWidget->setFocus();
        return false;
    }

    return true;

}

// NOTE: Validar datos de orden de servicio
bool SalesForm::validateSoData()
{
    if (soScopeTextEdit->toPlainText()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El alcance es obligatorio"),
                             QMessageBox::Ok);
        soScopeTextEdit->setFocus();
        return false;
    }

    if (soDateEdit->date() >  soAssignDateEdit->date()) {
        QMessageBox::warning(this, trUtf8("Fechas inválidas"),
                             trUtf8("La fecha de la OS debe ser menor a la\n"
                                    " fecha programada de inspección"),
                             QMessageBox::Ok);
        soAssignDateEdit->setFocus();
        return false;
    }

    return true;

}


// NOTE: Encontrar por id de tercero, fucion mas de uso interno
int SalesForm::findByThrdId(QString thrdId)
{
    found=0;
    // Devuelve los QList modificados
    // el cuarto parametro es searchOption para que la funcion busque en el campo adecuado
    if (DbHandler::getQuotations(thrdId, thrdData, quotsData, "thrd_id")) {
       found = 1; // Significa que encontro cotizaciones
       if (DbHandler::getProposals(quotsData.at(0).at(0), propsData, "quot_id")) {
           found = 2; // Significa que econtro cotizaciones y propuesta
           if (DbHandler::getServiceOrders(propsData.at(0).at(0), sosData, "prop_id"))
               found = 3; // Significa que encontro cotizacion, propuesta y orden de servicio
       }
       return found;  // hasta aqui se sabe que econtro una cotizacion
    }
    found = 0;
    return found;
}

// NOTE: Encontrar por nit
int SalesForm::findByNit(QString thrdNit)
{
    found=0;
    // Devuelve los QList modificados
    // el cuarto parametro es searchOption para que la funcion busque en el campo adecuado
    if (DbHandler::getQuotations(thrdNit, thrdData, quotsData, "thrd_nit")) {
       found = 1; // Significa que encontro cotizaciones
       if (DbHandler::getProposals(quotsData.at(0).at(0), propsData, "quot_id")) {
           found = 2; // Significa que econtro cotizaciones y propuesta
           if (DbHandler::getServiceOrders(propsData.at(0).at(0), sosData, "prop_id"))
               found = 3; // Significa que encontro cotizacion, propuesta y orden de servicio
       }
       return found;  // hasta aqui se sabe que econtro una cotizacion
    }
    found = 0;
    return found;
}

// NOTE: Encuentra por id de propuesta
int SalesForm::findByPropId(QString propId)
{
    found=0;
    // Devuelve los QList modificados
    if (DbHandler::getProposals(propId, propsData, "prop_id")) {
       foundLCD->display(propsData.at(Props::Id).size());
       found=2; // Significa que econtro propuesta por tanto cotizacion
       DbHandler::getQuotations(propsData.at(Props::thrdNit).at(0), thrdData, quotsData, "thrd_nit"); // 13 es thrd_nit
       if (DbHandler::getServiceOrders(propId, sosData, "prop_id"))
           found=3; // Significa que encontro cotizacion, propuesta y orden de servicio
       return found;
    }
    found = 0;
    return found;
}

// NOTE: Encuentra por id de orden de servicio
int SalesForm::findBySoId(QString soId)
{

    found=0;
    // Devuelve los QList modificados
    if (DbHandler::getServiceOrders(soId, sosData, "so_id")) {
       foundLCD->display(sosData.at(0).size());
       DbHandler::getProposals(sosData.at(Sos::propId).at(0), propsData, "prop_id");
       DbHandler::getQuotations(propsData.at(Props::thrdNit).at(0), thrdData, quotsData, "thrd_nit");// 13 es thrd_nit
       found=3;
       return found;
    }
    found = 0;
    return found;
}

// NOTE: Insertar cotizacion

int SalesForm::insertQuotation(int opt)
{
    QStringList quotData;
    QStringList processesIds;
    quotData.append(quotDateEdit->date().toString("yyyy-MM-dd"));
    quotData.append(quotNameLineEdit->text());
    quotData.append(quotScopeTextEdit->toPlainText());
    quotData.append(quotContactLineEdit->text());
    quotData.append(quotAddressLineEdit->text());
    quotData.append(quotMailLineEdit->text());
    quotData.append(quotPhoneLineEdit->text());
    quotData.append(quotFaxLineEdit->text());
    //El index del combobox es el mismo para el QList donde esta guardado el id del departamento
    quotData.append(quotCitiesData.at(0).at(quotCityComboBox->currentIndex()));
    quotData.append(usesData.at(0).at(useTypeComboBox->currentIndex()));
    quotData.append(inspecTypeComboBox->currentText());

    thrdData.clear(); // Es necesario limpiar el QStringList ya que es miembro
    thrdData.append("0");
    thrdData.append(thrdNitLineEdit->text());
    thrdData.append(thrdNameLineEdit->text());
    thrdData.append(thrdRepLineEdit->text());
    //thrdData.append(thrdRepIdLineEdit->text());
    thrdData.append(thrdAddressLineEdit->text());
    thrdData.append(thrdMailLineEdit->text());
    thrdData.append(thrdPhoneLineEdit->text());
    thrdData.append(thrdFaxLineEdit->text());
    thrdData.append(thrdCitiesData.at(0).at(thrdCityComboBox->currentIndex()));

    QModelIndexList processesIndexes = processesListWidget->selectionModel()->selectedIndexes();
    for (int i=0; i< processesIndexes.size(); i++)
        // ProcessesData es un Qlist<QStringList>, 0 es la primera lista, osea la de Ids
        // processesIndexes.at(i).row() indican el registro en cuestion, así coincide
        // lo seleccionado en el listWidget con lo guardado en el QList.
        processesIds.append(processesData.at(0).at(processesIndexes.at(i).row()));
        // Con esto quedan los ids de los procesos seleccionados y guardados.

    bool isUniqueViolation = false;

    switch (opt) {
    case QMessageBox::Yes: // Se pidio crear cotizacion y cliente
        if (DbHandler::insertQuotation(thrdData, quotData, processesIds, isUniqueViolation)) {
            Logger::insertQuotation(userName, thrdNitLineEdit->text(), quotData.at(Quots::NewId));
            return 0;
        }
        else {
            if (isUniqueViolation == true) {
                int ret=QMessageBox::question(this, trUtf8("Cliente ya existe"),
                                              trUtf8("El cliente ya existe,\n"
                                                     "¿desea agregar una nueva cotización?"),
                                              QMessageBox::Ok | QMessageBox::Cancel);
                switch (ret) {
                case QMessageBox::Ok:
                    if (DbHandler::insertQuotation(thrdData.at(1), quotData, processesIds)) {
                        Logger::insertQuotation(userName, thrdData.at(1), quotData.at(Quots::NewId));
                        findByNit(thrdData.at(1));
                        return 0; // se inserto correctamente la cotizacion
                    }
                    else
                        return 2; // si falla insertQuotation
                    break;
                case QMessageBox::Cancel:
                    return 1; // el usuario no desea introducir esa cotizacion
                    break;
                }
            }
            return 3;
        }
    break;

    case QMessageBox::No: // se pidio insertar contizacion en el cliente
        if (DbHandler::insertQuotation(thrdData[1], quotData, processesIds)) {
            Logger::insertQuotation(userName, thrdData.at(1), quotData.at(Quots::NewId));
            return 0;
        }
        else
            return 2; // si falla insertQuotation
        break;
    }

    return false;

}

// NOTE: Insertar propuesta comercial

int SalesForm::insertProposal()
{
    QStringList propData;
    QStringList documentsIds;
    bool isUniqueViolation = false;

    propData.append(propDateEdit->date().toString("yyyy-MM-dd"));
    propData.append(propScopeTextEdit->toPlainText());
    propData.append("Sin Aprobar");
    propData.append(propPayWayComboBox->currentText());
    propData.append(QString::number(propUserPercSpinBox->value()/100));
    propData.append(propObservTextEdit->toPlainText());
    // El index del combobox se usa como index del qlist.
    propData.append(QString::number(money2float(propValueModel->data(propValueModel->index(0,1), Qt::DisplayRole).toString())));
    propData.append(QString::number(money2float(propValueModel->data(propValueModel->index(1,1), Qt::DisplayRole).toString())));
    propData.append(QString::number(money2float(propValueModel->data(propValueModel->index(2,1), Qt::DisplayRole).toString())));
    propData.append(QString::number(money2float(propValueModel->data(propValueModel->index(3,1), Qt::DisplayRole).toString())));
    propData.append(quotsData.at(0).at(quot_position)); // quot_id
    propData.append(usersData.at(0).at(propSoldByComboBox->currentIndex())); // user_id

    // Agregar los ducumentos seleccionados
    QModelIndexList documentsIndexes = propDocsListWidget->selectionModel()->selectedIndexes();
    for (int i=0; i< documentsIndexes.size(); i++)
        // propDocumentsData es un Qlist<QStringList>, 0 es la primera lista, osea la de Ids
        // documentsIndexes.at(i).row() indican el registro en cuestion, así coincide
        // lo seleccionado en el listWidget con lo guardado en el QList.
        documentsIds.append(documentsData.at(0).at(documentsIndexes.at(i).row()));
        // Con esto quedan los ids de los documentos seleccionados y guardados.

    if (DbHandler::insertProposal(propData, documentsIds, isUniqueViolation)) {
        Logger::insertProposal(userName, thrdData.at(1), quotsData.at(Quots::Id).at(quot_position), propData.at(Props::Id));
        findByPropId(propData.at(Props::Id)); // Lo hago buscar por propuesta para actualizar los campos correctamente
        fillPropData();
        return 0;
    } else {
        if (isUniqueViolation == true) {
            qDebug() << "La propuesta ya existe, se retorna 1";
            return 1;
        }
    }
    return 2;
}

// NOTE: Insertar orden de servicio
int SalesForm::insertServiceOrder()
{
    QStringList soData;
    bool isUniqueViolation;

    soData.append(soDateEdit->date().toString("yyyy-MM-dd"));
    soData.append(soScopeTextEdit->toPlainText());
    soData.append(soObservTextEdit->toPlainText());
    soData.append(QString::number(soInspPercSpinBox->value()/100));
    soData.append(soAssignDateEdit->date().toString("yyyy-MM-dd"));
    soData.append(inspectorsData.at(0).at(soInspectorsComboBox->currentIndex()));
    soData.append(propsData.at(Props::Id).at(prop_position));

    if (DbHandler::insertServiceOrder(soData, isUniqueViolation)) {
        Logger::insertServiceOrder(userName, thrdData.at(1), quotsData.at(Quots::Id).at(quot_position),
                                   propsData.at(Props::Id).at(prop_position), soData.at(Sos::Id));
        findBySoId(soData.at(Sos::Id));
        fillSoData();
        return 0;
    } else {
        if (isUniqueViolation == true) {
            qDebug() << "La orden de servicio ya existe, se retorna 1";
            return 1;
        }
    }
    return 2;
}


// NOTE: Actualizar cotizacion
bool SalesForm::updateQuotation()
{
    QStringList quotData;
    QStringList processesIds;
    quotData.append(quotsData.at(0).at(quot_position));
    quotData.append(quotDateEdit->date().toString("yyyy-MM-dd"));
    quotData.append(quotNameLineEdit->text());
    quotData.append(quotScopeTextEdit->toPlainText());
    quotData.append(quotContactLineEdit->text());
    quotData.append(quotAddressLineEdit->text());
    quotData.append(quotMailLineEdit->text());
    quotData.append(quotPhoneLineEdit->text());
    quotData.append(quotFaxLineEdit->text());

    quotData.append(quotCitiesData.at(0).at(quotCityComboBox->currentIndex()));
    quotData.append(usesData.at(0).at(useTypeComboBox->currentIndex()));
    quotData.append(inspecTypeComboBox->currentText());

    QModelIndexList processesIndexes = processesListWidget->selectionModel()->selectedIndexes();
    for (int i=0; i< processesIndexes.size(); i++)
        // ProcessesData es un Qlist<QStringList>, 0 es la primera lista, osea la de Ids
        // processesIndexes.at(i).row() indican el registro en cuestion, así coincide
        // el lo seleccionado en el listWidget con lo guardado en el QList.
        processesIds.append(processesData.at(0).at(processesIndexes.at(i).row()));
        // Con esto quedan los ids de los procesos seleccionados guardados.
    if (!DbHandler::updateQuotation(quotData, processesIds)) {
        qDebug() << trUtf8("updateQuotation devolvió 'false', intentando actualizar la cotización: ")
                    + quotsData.at(0).at(quot_position);
        return false;
    } else {
       findByNit(thrdData.at(1));
       return true;
    }

    return false;
}

// NOTE: Actualizar propuesta
bool SalesForm::updateProposal()
{
    QStringList propData;
    QStringList documentsIds;
    propData.append(propsData.at(Props::Id).at(0));
    propData.append(propDateEdit->date().toString("yyyy-MM-dd"));
    propData.append(propScopeTextEdit->toPlainText());
    propData.append(propPayWayComboBox->currentText());
    propData.append(propStateLineEdit->text());
    propData.append(QString::number(propUserPercSpinBox->value()/100));
    propData.append(propObservTextEdit->toPlainText());
    // El index del combobox se usa como index ddel qlist.
    propData.append(usersData.at(0).at(propSoldByComboBox->currentIndex()));
    // Convierto el valor que halla a entero para quitar el formato de moneda y luego a qstring para poderlo manejar
    propData.append(QString::number(money2float(propValueModel->data(propValueModel->index(0,1), Qt::DisplayRole).toString())));
    propData.append(QString::number(money2float(propValueModel->data(propValueModel->index(1,1), Qt::DisplayRole).toString())));
    propData.append(QString::number(money2float(propValueModel->data(propValueModel->index(2,1), Qt::DisplayRole).toString())));
    propData.append(QString::number(money2float(propValueModel->data(propValueModel->index(3,1), Qt::DisplayRole).toString())));

    QModelIndexList documentsIndexes = propDocsListWidget->selectionModel()->selectedIndexes();
    for (int i=0; i< documentsIndexes.size(); i++)
        // propDocumentsData es un Qlist<QStringList>, 0 es la primera lista, osea la de Ids
        // documentsIndexes.at(i).row() indican el registro en cuestion, así coincide
        // lo seleccionado en el listWidget con lo guardado en el QList.
        documentsIds.append(documentsData.at(0).at(documentsIndexes.at(i).row()));
        // Con esto quedan los ids de los documentos seleccionados y guardados.

    if (!DbHandler::updateProposal(propData, documentsIds)) {
        qDebug() << trUtf8("updateProposal devolvió 'false', intentando actualizar la propuesta: "
                           + propsData.at(0).at(0).toUtf8());
        return false;
    } else {
        findByPropId(propsData.at(0).at(0));
        return true;
    }


}

// NOTE: Actualizar orden de servicio
bool SalesForm::updateServiceOrder()
{
    QStringList soData;

    soData.append(sosData.at(Sos::Id).at(0)); //  id
    soData.append(soDateEdit->date().toString("yyyy-MM-dd")); // fecha
    soData.append(soScopeTextEdit->toPlainText()); // alcance
    soData.append(soObservTextEdit->toPlainText()); // observaciones
    soData.append(QString::number(soInspPercSpinBox->value()/100)); // porcentaje de inspector
    soData.append(soAssignDateEdit->date().toString("yyyy-MM-dd"));
    soData.append(inspectorsData.at(0).at(soInspectorsComboBox->currentIndex())); // id inspector

    if (!DbHandler::updateServiceOrder(soData)) {
        qDebug() << trUtf8("updateServiceOrder devolvió 'false', intentando actualizar la orden de servicio: "
                           +sosData.at(Sos::Id).at(0).toUtf8());
        return false;
    } else {
        findBySoId(sosData.at(Sos::Id).at(0));
        return true;
    }
}

// NOTE: Eliminar cotizacion
int SalesForm::deleteQuotation()
{
    bool isFkViolation=false;
    if (DbHandler::deleteQuotation(quotsData.at(0).at(quot_position), isFkViolation)) {
        quot_position=0;
        switch (findByNit(thrdData.at(1))) {
        case 0: // No encuentra datos ya porque se ha eliminado la cotización.
            clearThrdQuotControls();
            break;

        case 1: // Solo encontro cotizacion
            fillQuotData();
            quotGenButton->setEnabled(false);
            updateButton->setEnabled(true);
            deleteButton->setEnabled(true);
            salesTabWidget->setCurrentIndex(0);
            break;

        case 2:
            fillQuotData();
            fillPropData();
            quotGenButton->setEnabled(false);
            propGenButton->setEnabled(false);
            updateButton->setEnabled(true);
            deleteButton->setEnabled(true);
            propApprovButton->setEnabled(true);
            propRejectButton->setEnabled(true);
            salesTabWidget->setCurrentIndex(0);
            break;

        case 3:
            fillQuotData();
            fillPropData();
            fillSoData();
            quotGenButton->setEnabled(false);
            propGenButton->setEnabled(false);
            soGenButton->setEnabled(false);
            updateButton->setEnabled(true);
            deleteButton->setEnabled(true);
            propApprovButton->setEnabled(false);
            propRejectButton->setEnabled(false);
            salesTabWidget->setCurrentIndex(0);
            break;

        }

        prevButton->setEnabled(false);
        if (quotsData.at(0).size()==1)
            nextButton->setEnabled(false);
        else
            nextButton->setEnabled(true);

        foundLCD->display(quotsData[0].size());
        quotLCD->display(quot_position+1);
        return 0;
    } else {
        if (isFkViolation) {
            qDebug() << trUtf8("Violación de llave foranea se retorna 1");
            return 1;
        } else
            return 2; // Error desconocido, revidar DbHandler::deleteQuotation
    }
}



// NOTE: Eliminar propuesta comercial
int SalesForm::deleteProposal()
{
    bool isFkViolation=false;
    if (DbHandler::deleteProposal(propsData.at(0).at(prop_position), isFkViolation)) {
        clearPropControls();
        clearSoControls();
        return 0;
    } else {
        if (isFkViolation) {
            qDebug() << trUtf8("Violación de llave foranea se retorna 1");
            return 1;
        } else
            return 2; // Error desconocido, revidar DbHandler::deleteProposal
    }

}

// NOTE: Eliminar orden de servicio
int SalesForm::deleteServiceOrder()
{
    bool isFkViolation=false;
    if (DbHandler::deleteServiceOrder(sosData.at(0).at(so_position), isFkViolation)) {
        clearSoControls();
        propApprovButton->setEnabled(true);
        propRejectButton->setEnabled(true);
        return 0;
    } else {
        if (isFkViolation) {
            qDebug() << trUtf8("Violación de llave foranea se retorna 1");
            return 1;
        } else
            return 2; // Error desconocido, revidar DbHandler::deleteProposal
    }

}

// NOTE: Listar las cotizaciones

void SalesForm::listQuotations()
{

    FilterQuotationsForm filterForm(this);
    filterForm.exec();
    if (!filterForm.thrd_nit.isEmpty()) {
        findLineEdit->setText(filterForm.thrd_nit);
        findComboBox->setCurrentIndex(0);
        findButton->click();
    }

}

// NOTE: Listar las propuestas
void SalesForm::listProposals()
{
    FilterProposalsForm filterForm(this);
    filterForm.exec();
    if (!filterForm.prop_id.isEmpty()) {
        findLineEdit->setText(filterForm.prop_id);
        findComboBox->setCurrentIndex(1);
        findButton->click();
    }
}

// NOTE: Listar las ordenes de servicio
void SalesForm::listServiceOrders()
{
    FilterServiceOrdersForm filterForm(this);
    filterForm.exec();
    if (!filterForm.so_id.isEmpty()) {
        findLineEdit->setText(filterForm.so_id);
        findComboBox->setCurrentIndex(2);
        findButton->click();
    }
}


// NOTE: Suma el total de la propuesta
void SalesForm::propTotalSum(void)
{

    float InstValue=0, Viatical=0, PropTotal=0, Iva=0;
    QString instValue("0");
    QString viatical("0");

    instValue=propValueModel->data(propValueModel->index(0,1), Qt::DisplayRole).toString();
    viatical=propValueModel->data(propValueModel->index(2,1), Qt::DisplayRole).toString();

    InstValue=money2float(instValue);
    Viatical=money2float(viatical);

    Iva=InstValue*0.16;
    PropTotal=InstValue+Iva+Viatical;


    propValueModel->setItem(1,1, new QStandardItem(float2money(Iva)));
    propValueModel->setItem(3,1, new QStandardItem(float2money(PropTotal)));

    // No editable el IVA y Total
    propValueModel->item(1,1)->setFlags(propValueModel->item(1,1)->flags() & ~Qt::ItemIsEditable);
    propValueModel->item(3,1)->setFlags(propValueModel->item(3,1)->flags() & ~Qt::ItemIsEditable);


}

// NOTE: Llena datos de prueba para cotizacion
void SalesForm::testQuotation()
{
    soInspPercLabel->hide();
    soInspPercSpinBox->hide();
//    quotNameLineEdit->setText(trUtf8("Instalación de prueba rápida"));
//    quotAddressLineEdit->setText("Avenida de prueba con Calle de Prueba");
//    quotStateComboBox->setCurrentIndex(6);
//    inspecTypeComboBox->setCurrentIndex(0);
//    quotContactLineEdit->setText("Fulano de Contacto");
//    quotCityComboBox->setCurrentIndex(7);
//    quotPhoneLineEdit->setText("2272525");
//    quotMailLineEdit->setText("testcontact@test.com");
//    quotFaxLineEdit->setText("2253698");
//    useTypeComboBox->setCurrentIndex(0);
//    quotScopeTextEdit->setHtml(trUtf8("Alcance de prueba para determinar si el campo tiene los suficientes"
//                               "caracteres para probar que el software funcione correctamente y no"
//                               "tenga problemas a la hora de guardar un alcance largo."));

//    processesListWidget->clearSelection();
//    processesListWidget->item(1)->setSelected(true);

//    thrdNameLineEdit->setText("Tercero de Prueba");
//    thrdNitLineEdit->setText("98989878-2");
//    thrdAddressLineEdit->setText(trUtf8("Dirección de prueba para el tercero"));
//    thrdStateComboBox->setCurrentIndex(4);
//    thrdCityComboBox->setCurrentIndex(5);
//    thrdRepLineEdit->setText("Peranito Representante Legal");
//    thrdRepIdLineEdit->setText("45454545");
//    thrdMailLineEdit->setText("testrepre@test.com");
//    thrdPhoneLineEdit->setText("3103103102");
//    thrdFaxLineEdit->setText("2021365");

}

// NOTE: Llena datos de prueba para propuesta
void SalesForm::testProposal()
{
//    propInspectorsComboBox->setCurrentIndex(3);
//    propScopeTextEdit->setHtml(trUtf8("Modificando el Alcance de prueba para determinar si el campo tiene los suficientes"
//                               "caracteres para probar que el software funcione correctamente y no"
//                               "tenga problemas a la hora de guardar un alcance largo."));

//    propDocsListWidget->clearSelection();
//    for (int i=0; i<10;i++)
//        propDocsListWidget->item(i)->setSelected(true);

//    propUserPercSpinBox->setValue(30);
//    propInspPercSpinBox->setValue(25);

//    propValueModel->setItem(0,1, new QStandardItem("100000"));
//    propValueModel->setItem(1,1, new QStandardItem("16000"));
//    propValueModel->setItem(2,1, new QStandardItem("40000"));
//    propValueModel->setItem(3,1, new QStandardItem("156000"));

//    propPayWayComboBox->setCurrentIndex(1);
//    propSoldByComboBox->setCurrentIndex(3);
//    propObservTextEdit->setHtml("Algunas observaciones con respecto a la propuesta comercial que permitan determinar"
//                                "como se dijo anteriormente en el alcance, si el tamaño del campo cumple con las"
//                                "necesidades para la propuesta");

    soInspPercLabel->show();
    soInspPercSpinBox->show();
}





















