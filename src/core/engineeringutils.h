#include "engineering.h"
#include "dbhandler.h"
#include "editpersons.h"

// NOTE: Preparar controles de la ui
void EngineeringForm::prepareEngControls()
{

    // Limpiar hojas de estilo
    // voidStyle();

    // Agregar acciones de menú contextual (Tooltip)
    editDesignersAct = new QAction(QIcon(":icons/icons/add-user.png"), trUtf8("Editar Diseñadores..."), this);
    editDesignersAct->setStatusTip(trUtf8("Editar Los diseñador de la base de datos"));
    connect(editDesignersAct, SIGNAL(triggered()), this, SLOT(editDesigners()));
    designersListWidget->addAction(editDesignersAct);

    editConstructorsAct = new QAction(QIcon(":icons/icons/add-user.png"), trUtf8("Editar Constructores..."), this);
    editConstructorsAct->setStatusTip(trUtf8("Editar Los constructores de la base de datos"));
    connect(editConstructorsAct, SIGNAL(triggered()), this, SLOT(editConstructors()));
    constructorNameComboBox->addAction(editConstructorsAct);

    editAuditorsAct = new QAction(QIcon(":icons/icons/add-user.png"), trUtf8("Editar Interventores..."), this);
    editAuditorsAct->setStatusTip(trUtf8("Editar Los interventores de la base de datos"));
    connect(editAuditorsAct, SIGNAL(triggered()), this, SLOT(editAuditors()));
    auditorNameComboBox->addAction(editAuditorsAct);

    changeInspectionStateAct = new QAction(QIcon(":icons/icons/edit-state.png"), trUtf8("Cambiar Estado..."), this);
    changeInspectionStateAct->setStatusTip(trUtf8("Cambiar el estado de la inspección"));
    connect(changeInspectionStateAct, SIGNAL(triggered()), this, SLOT(changeInspectionState()));
    inspectionStateLineEdit->addAction(changeInspectionStateAct);
    changeInspectionStateAct->blockSignals(true);

    // Llenado de objetos de datos
    if (!DbHandler::getProcesses(processesData))
        processesData.append(QStringList("Sin Datos"));

    if (!DbHandler::getUsers(usersData))
        usersData.append(QStringList("Sin Datos"));

    if (!DbHandler::getDesigners(designersData, "desinger_id"))
        designersListWidget->addItem("Sin Datos");
    else
        designersListWidget->addItems(designersData.at(1));

    if (!DbHandler::getConstructors(constructorsData, "constructor_id")) {
        constructorsData.append(QStringList("Sin Datos"));
        constructorNameComboBox->addItem("Sin Datos");
    } else
        constructorNameComboBox->addItems(constructorsData.at(1));
    constructorNameComboBox->lineEdit()->clear();

    if (!DbHandler::getAuditors(auditorsData, "auditor_id")) {
        auditorsData.append(QStringList("Sin Datos"));
        auditorNameComboBox->addItem("Sin Datos");
    } else
        auditorNameComboBox->addItems(auditorsData.at(1));
    auditorNameComboBox->lineEdit()->clear();

    if (!DbHandler::getRecords(recordsData))
        recordsData.append(QStringList("Sin Datos"));

    if (!DbHandler::getUses(usesData))
        usesData.append(QStringList("Sin Datos"));

    if (DbHandler::getStates(statesData))
        inspectionStateComboBox->addItems(statesData.at(2));
    else
        inspectionStateComboBox->addItem("Sin Datos");

    // Lleno el listwidget con los procesos existentes
    if (DbHandler::getProcesses(processesData))
        processesListWidget->addItems(processesData.at(1));
    else
        processesListWidget->addItem("Sin Datos");


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

    inspectionDateEdit->setDate(QDate::currentDate());
    findLineEdit->setFocus();

    QTimer *timer = new QTimer(this);
         connect(timer, SIGNAL(timeout()), this, SLOT(checkEngState()));
         timer->start(1800000); // Se ejecuta cada 30 miutos
}

// NOTE: Llenado de datos de orden de servicio
void EngineeringForm::fillData()
{
    // Primero se llenan los datos que no cambian
    soDateEdit->setDate(QDate::fromString(sosData.at(Sos::Date).at(0), "yyyy-MM-dd"));
    soAssignDateEdit->setDate(QDate::fromString(sosData.at(Sos::AssignD).at(0), "yyyy-MM-dd"));
    soAccStateLineEdit->setText(sosData.at(Sos::AccProc).at(0));
    soDocStateLineEdit->setText(sosData.at(Sos::DocProc).at(0));
    userNameLineEdit->setText(propsData.at(Props::LName).at(0));
    inspectorNameLineEdit->setText(sosData.at(Sos::InspName).at(0));

    propValueModel->setItem(0,1, new QStandardItem(propsData.at(Props::Value).at(0)));
    propValueModel->setItem(1,1, new QStandardItem(propsData.at(Props::Iva).at(0)));
    propValueModel->setItem(2,1, new QStandardItem(propsData.at(Props::Viat).at(0)));
    propValueModel->setItem(3,1, new QStandardItem(propsData.at(Props::TotVal).at(0)));

    // Después de editarlos hay que ponerlos no editables
    propValueModel->item(0,1)->setFlags(propValueModel->item(0,1)->flags() & ~Qt::ItemIsEditable);
    propValueModel->item(1,1)->setFlags(propValueModel->item(1,1)->flags() & ~Qt::ItemIsEditable);
    propValueModel->item(2,1)->setFlags(propValueModel->item(2,1)->flags() & ~Qt::ItemIsEditable);
    propValueModel->item(3,1)->setFlags(propValueModel->item(3,1)->flags() & ~Qt::ItemIsEditable);

    // Llenado de procesos
    processesListWidget->clearSelection();
    processesComboBox->blockSignals(true);
    processesComboBox->addItem("Seleccione el proceso");
    int index; // declaro un índice para hacer entendible el siguiete bloque
    for (int i=0; i<procsIds.size();i++) {
        index=processesData.at(0).indexOf(procsIds.at(i));
        processesListWidget->item(index)->setSelected(true);
        // Se añaden los nombre de los procesos seleccionados al combobox de proceso a trabajar
        processesComboBox->addItem(processesListWidget->item(index)->text());
    }
    processesComboBox->blockSignals(false);

    // Luego, si está sin procesar, se pueden llenar los datos que cambian, leyéndolos de la orden de servicio
    if (sosData.at(Sos::EngProc).at(0)=="Sin Procesar") { // no se ha procedado por tanto debe hacerse
        inspectionScopeTextEdit->setText(sosData.at(Sos::Scope).at(0));
        inspectionObservTextEdit->setText(sosData.at(Sos::Observ).at(0));
        inspectionStateLineEdit->setText("Sin Procesar");
        inspectionStateComboBox->setCurrentIndex(inspectionStateComboBox->findText(quotsData.at(Quots::State).at(0)));
        inspectionCityComboBox->setCurrentIndex(inspectionCityComboBox->findText(quotsData.at(Quots::City).at(0)));
        inspectionUpdateButton->setEnabled(false); // Por ahora no se permite actualizar la inspección si no se ha procesado
        inspectionSaveButton->setEnabled(false);
        processInspectionButton->setEnabled(true);

        // se debe preguntar si tine observaciones para lanzar una advertencia
        if (sosData.at(5).at(0)=="Observada")
            QMessageBox::warning(this, trUtf8("Información"),
                                  trUtf8("Expediente con observaciones en sus documentos\n"
                                         "revise su estado en el Módulo de Documentos."),
                                  QMessageBox::Ok);
        // Si viene Sin Revisar o Incompleto en el módulo de documentos no se puede procesar.
        if (sosData.at(Sos::DocProc).at(0)=="Sin Procesar" || sosData.at(Sos::DocProc).at(0)=="Incompleta") {
            QMessageBox::critical(this, trUtf8("Información"),
                                  trUtf8("Expediente sin procesar o incompleto, revise\n"
                                         "su estado con el personal de Documentos"),
                                  QMessageBox::Cancel);
            voidStyle();
        } else {
            styleWithoutData();
        }

    } // Si ya está procesada, entonces se debe llenar de los datos provenientes de la inspección
    else {
        if (!DbHandler::getInspections(sosData.at(Sos::Id).at(0), inspectionsData)) // En este caso siempre debe haber datos
            QMessageBox::critical(this, trUtf8("Error obteniendo la inspección"),
                                  trUtf8("Ejecute el programa bajo consola y revise los mensajes"),
                                  QMessageBox::Cancel);
        else { // Se procede a llenar datos desde la inspección
            styleWithData();
            // se debe preguntar si tine observaciones para lanzar una advertencia
            if (sosData.at(Sos::EngObserv).at(0)=="Observada")
                QMessageBox::warning(this, trUtf8("Información"),
                                      trUtf8("Expediente con observaciones en sus documentos\n"
                                             "revise su estado en el Módulo de Documentos."),
                                      QMessageBox::Ok);

            inspectionScopeTextEdit->setText(sosData.at(Sos::Scope).at(0));
            inspectionId=inspectionsData.at(0).at(0);
            inspectionDateEdit->setDate(QDate::fromString(inspectionsData.at(1).at(0), "yyyy-MM-dd"));
            inspectionStateLineEdit->setText(inspectionsData.at(2).at(0));
            inspectionObservTextEdit->setText(inspectionsData.at(3).at(0));
            inspectionAddressLineEdit->setText(inspectionsData.at(4).at(0));
            propietaryNameLineEdit->setText(inspectionsData.at(5).at(0));
            inspectionStateComboBox->setCurrentIndex(inspectionStateComboBox->findText(inspectionsData.at(6).at(0)));
            inspectionCityComboBox->setCurrentIndex(inspectionCityComboBox->findText(inspectionsData.at(7).at(0)));

            // bloque para el marcado de diseñadores
            QStringList inspectionDesignersIds;
            if (!DbHandler::getInspectionDesigners(inspectionsData.at(0).at(0), inspectionDesignersIds))
                    qDebug() << QString("DbHandler::getInspectionDesigners devolvió false al tratar de obtener los diseñadores").toUtf8();
            else {
                int index; // declaro un índice para hacer entendible el siguiente bloque de código
                for (int i=0; i<inspectionDesignersIds.size();i++) {
                    index=designersData.at(0).indexOf(inspectionDesignersIds.at(i));
                    designersListWidget->item(index)->setSelected(true);
                    }
            }

            constructorNameComboBox->setCurrentIndex(constructorNameComboBox->findText(inspectionsData.at(8).at(0)));
            auditorNameComboBox->setCurrentIndex(auditorNameComboBox->findText(inspectionsData.at(10).at(0)));
            if (inspectionStateLineEdit->text()=="Finalizada" || inspectionStateLineEdit->text()=="No Dictaminada") {
                newDictumButton->hide();
                inspectionEndButton->setEnabled(false);
                changeInspectionStateAct->blockSignals(false);
            } else {
                newDictumButton->show();
                inspectionEndButton->setEnabled(true);
            }
            getDictums();
        }

    }

}

// NOTE: Borrado de controles
void EngineeringForm::clearControls()
{
    soDateEdit->setDate(QDate::currentDate());
    soAssignDateEdit->setDate(QDate::currentDate());
    inspectionDateEdit->setDate(QDate::currentDate());
    soAccStateLineEdit->clear();
    soDocStateLineEdit->clear();
    inspectionScopeTextEdit->setHtml("");
    inspectionObservTextEdit->setHtml("");
    inspectionStateLineEdit->clear();
    userNameLineEdit->clear();
    inspectorNameLineEdit->clear();
    processesListWidget->clearSelection();
    processesComboBox->blockSignals(true);
    processesComboBox->clear();
    dictumsComboBox->clear();


    inspectionStateLineEdit->clear();
    inspectionAddressLineEdit->clear();
    propietaryNameLineEdit->clear();
    inspectionStateComboBox->setCurrentIndex(0);
    designersListWidget->clear();
    designersListWidget->addItems(designersData.at(1));
    constructorNameComboBox->setCurrentIndex(constructorNameComboBox->findText("No Asignado"));
    auditorNameComboBox->setCurrentIndex(auditorNameComboBox->findText("No Asignado"));

    processInspectionButton->setEnabled(false);
    processesComboBox->setEnabled(false);
    dictumsComboBox->setEnabled(false);
    goDictumButton->setEnabled(false);
    newDictumButton->setEnabled(false);

    for (int i=0; i<propValueModel->rowCount(); i++)
        propValueModel->setItem(i,1, new QStandardItem(QString::fromUtf8("")));

}

// NOTE: Chequear estado de orden de servicio
void EngineeringForm::checkEngState()
{
    QList<QStringList> sosDataForState;
    // El tercer parámetro es serachOption, para buscar por parámetro aquí se añade so_doc_processed='Revisada'
    // pero so_eng_processed sigue siendo el bindValue del QSqlQuery
    if (DbHandler::getServiceOrders("Sin Procesar", sosDataForState, "so_doc_processed='Revisada' AND tblSERVICEORDERS.so_eng_processed"))
        noProcessedLcdNumber->display(sosDataForState.at(0).size());
    else {
        noProcessedLcdNumber->display(0);
        qDebug()<< trUtf8("DbHandler::getServiceOrders devolvió false al intentar obtener OS's Sin Procesar");
    }
}

// NOTE: Validar datos de orden de servicio
bool EngineeringForm::validateData()
{
    if (inspectionScopeTextEdit->toPlainText()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El alcance es obligatorio"),
                             QMessageBox::Ok);
        inspectionScopeTextEdit->setFocus();
        return false;
    }

    QModelIndexList processesIndexes = processesListWidget->selectionModel()->selectedIndexes();
    if (processesIndexes.size() == 0) {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("Es obligatorio por lo menos un proceso"),
                             QMessageBox::Ok);
        processesListWidget->setFocus();
        return false;
    }

    if (propietaryNameLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El nombre del propietario es obligatorio"),
                             QMessageBox::Ok);
        propietaryNameLineEdit->setFocus();
        return false;
    }

    if (inspectionAddressLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("La dirección es obligatorio"),
                             QMessageBox::Ok);
        inspectionAddressLineEdit->setFocus();
        return false;
    }

    QModelIndexList designersIndexes = designersListWidget->selectionModel()->selectedIndexes();
    if (designersIndexes.size() == 0) {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("Debe asignar diseñador o seleccionar No Aplica"),
                             QMessageBox::Ok);
        designersListWidget->setFocus();
        return false;
    }

    if (constructorNameComboBox->currentIndex()==-1) {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("Debe asignar un constructor o seleccionar No Aplica"),
                             QMessageBox::Ok);
        constructorNameComboBox->setFocus();
        return false;
    }

    if (auditorNameComboBox->currentIndex()==-1) {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("Debe asignar un interventor o seleccionar No Aplica"),
                             QMessageBox::Ok);
        auditorNameComboBox->setFocus();
        return false;
    }

    if (soDateEdit->date() >  inspectionDateEdit->date()) {
        QMessageBox::warning(this, trUtf8("Fechas inválidas"),
                             trUtf8("La fecha de la OS debe ser menor a la\n"
                                    " fecha de inspección de la obra"),
                             QMessageBox::Ok);
        inspectionDateEdit->setFocus();
        return false;
    }

    if (soAssignDateEdit->date() > inspectionDateEdit->date()) {
        QMessageBox::warning(this, trUtf8("Fechas inválidas"),
                             trUtf8("La fecha de Procesamiento debe ser mayor a la\n"
                                    "fecha de inspección de la obra"),
                             QMessageBox::Ok);
        inspectionDateEdit->setFocus();
        return false;
    }
    return true;
}

// NOTE: Actualizar orden de servicio
bool EngineeringForm::updateServiceOrder(QString state)
{

    if (!DbHandler::updateSoEngState(sosData.at(Sos::Id).at(0), state)) {
        qDebug() << trUtf8("updateSoEngState devolvió 'false', intentando actualizar la orden de servicio: "
                           +sosData.at(Sos::Id).at(0).toUtf8());
        return false;
    } else
        return true;
}

// NOTE: Actualizar cotizacion
bool EngineeringForm::updateQuotation()
{

    // Es necesario actualizar con los mismos valores obtenidos y modificar solo los procesos.
    QStringList quotData;
    QStringList processesIds;
    quotData.append(quotsData.at(Quots::Id).at(0)); // Id
    quotData.append(quotsData.at(Quots::Date).at(0)); // Fecha
    quotData.append(quotsData.at(Quots::Name).at(0)); // Nombre
    quotData.append(quotsData.at(Quots::Scope).at(0)); // Alcance
    quotData.append(quotsData.at(Quots::Ctact).at(0)); // Persona Contacto
    quotData.append(quotsData.at(Quots::Addrs).at(0)); // Dirección
    quotData.append(quotsData.at(Quots::Mail).at(0)); // Correo
    quotData.append(quotsData.at(Quots::Cel).at(0)); // Celular
    quotData.append(citiesData.at(0).at(inspectionCityComboBox->currentIndex())); // Id de la ciudad
    quotData.append(usesData.at(0).at(usesData.at(1).indexOf(quotsData.at(Quots::Use).at(0)))); // Id del uso
    quotData.append(quotsData.at(Quots::InspTyp).at(0)); // Tipo de inspección


    // Este QModelIndexList sirve para guardar los índices de los ítems seleccionados del QListWidget
    QModelIndexList processesIndexes = processesListWidget->selectionModel()->selectedIndexes();
    for (int i=0; i< processesIndexes.size(); i++)
        // ProcessesData es un Qlist<QStringList>, 0 es la primera lista, osea la de Ids
        // processesIndexes.at(i).row() indican el registro en cuestion, así coincide
        // lo seleccionado en el QListWidget con lo guardado en el QList.
        processesIds.append(processesData.at(0).at(processesIndexes.at(i).row()));
        // Con esto quedan los ids de los procesos seleccionados guardados.
    if (!DbHandler::updateQuotation(quotData, processesIds)) {
        qDebug() << trUtf8("updateQuotation devolvió 'false', intentando actualizar los procesos: ")
                    + quotsData.at(Quots::Id).at(0);
        return false;
    } else
       return true;
}

// NOTE: Insertar datos de inspeccion
bool EngineeringForm::insertInspection()
{
    QStringList inspectionData;
    inspectionData.append(inspectionDateEdit->date().toString("yyyy-MM-dd"));
    inspectionData.append("En Proceso"); // Estado de la inspección
    inspectionData.append(inspectionObservTextEdit->toPlainText()); // Observaciones
    inspectionData.append(inspectionAddressLineEdit->text()); // Dirección real
    inspectionData.append(propietaryNameLineEdit->text()); // Propietario
    inspectionData.append(citiesData.at(0).at(inspectionCityComboBox->currentIndex())); // Id ciudad
    inspectionData.append(sosData.at(Sos::Id).at(0)); // Orden de servicio
    inspectionData.append(constructorsData.at(0).at(constructorNameComboBox->currentIndex())); // Id constructor
    inspectionData.append(auditorsData.at(0).at(auditorNameComboBox->currentIndex())); // Id auditor

    // Bloque para almacenar lista de diseñadores
    // Este QModelIndexList sirve para guardar los índices de los ítems seleccionados del QListWidget
    QStringList inspectionDesignersIds;
    QModelIndexList designersIndexes = designersListWidget->selectionModel()->selectedIndexes();
    for (int i=0; i< designersIndexes.size(); i++)
        // ProcessesData es un Qlist<QStringList>, 0 es la primera lista, osea la de Ids
        // processesIndexes.at(i).row() indican el registro en cuestion, así coincide
        // lo seleccionado en el QListWidget con lo guardado en el QList.
        inspectionDesignersIds.append(designersData.at(0).at(designersIndexes.at(i).row()));
        // Con esto quedan los ids de los diseñadores seleccionados guardados.
        // Si terminando el ciclo no hay seleccionados indica que queda como No Aplica
    if(inspectionDesignersIds.isEmpty())
        inspectionDesignersIds.append("1"); // Con esto se asigna a No Aplica
    else // Se hace para quitar No Aplica en caso de estar checado un diseñador y No Aplica a la vez
        if(inspectionDesignersIds.size()>1 && inspectionDesignersIds.at(0)=="1")
            inspectionDesignersIds.removeAt(0);

    // Al insertar una nueva inspección devuelve el id para usarlo en la creación de dictámenes.
    if (!DbHandler::insertInspection(inspectionData, inspectionId, inspectionDesignersIds)) {
        qDebug() << trUtf8("DbHandler::insertInspection devolvió false al tratar de insertar los datos");
        return false;
    }
    else {
        processesComboBox->setEnabled(true);
        inspectionEndButton->setEnabled(true);
        return true;
    }
}

bool EngineeringForm::updateInspection()
{
    QStringList inspectionData;

    inspectionData.append(inspectionId);
    inspectionData.append(inspectionDateEdit->date().toString("yyyy-MM-dd"));
    inspectionData.append(inspectionStateLineEdit->text()); // Estado de la inspección
    inspectionData.append(inspectionObservTextEdit->toPlainText()); // Observaciones
    inspectionData.append(inspectionAddressLineEdit->text()); // Dirección real
    inspectionData.append(propietaryNameLineEdit->text()); // Propietario
    inspectionData.append(citiesData.at(0).at(inspectionCityComboBox->currentIndex())); // Id ciudad
    inspectionData.append(sosData.at(Quots::Id).at(0)); // Orden de servicio
    inspectionData.append(constructorsData.at(0).at(constructorNameComboBox->currentIndex())); // Id constructor
    inspectionData.append(auditorsData.at(0).at(auditorNameComboBox->currentIndex())); // Id auditor

    // Bloque para actualizar lista de diseñadores
    // Este QModelIndexList sirve para guardar los índices de los ítems seleccionados del QListWidget
    QStringList inspectionDesignersIds;
    QModelIndexList designersIndexes = designersListWidget->selectionModel()->selectedIndexes();
    for (int i=0; i< designersIndexes.size(); i++)
        // inspectionData es un Qlist<QStringList>, 0 es la primera lista, osea la de Ids.
        // designersIndexes.at(i).row() indican el registro en cuestion, así coincide
        // lo seleccionado en el QListWidget con lo guardado en el QList<QStringList>.
        inspectionDesignersIds.append(designersData.at(0).at(designersIndexes.at(i).row()));
        // Con esto quedan los ids de los diseñadores seleccionados guardados.
        // Si terminando el ciclo no hay seleccionados indica que queda como No Aplica
    if(inspectionDesignersIds.isEmpty())
        inspectionDesignersIds.append("1"); // Con esto se asigna a No Aplica
    else // Se hace para quitar No Aplica en caso de estar checado un diseñador y No Aplica a la vez
        if(inspectionDesignersIds.size()>1 && inspectionDesignersIds.at(0)=="1")
            inspectionDesignersIds.removeAt(0);

    if (!DbHandler::updateInspection(inspectionData, inspectionDesignersIds)) {
        qDebug() << trUtf8("DbHandler::updateInspection devolvió false al tratar de insertar los datos");
        return false;
    }
    else {
        processesComboBox->setEnabled(true);
        return true;
    }
}



void EngineeringForm::editDesigners()
{
    int ret=QMessageBox::question(this, trUtf8("Pregunta"),
                                  trUtf8("¿Desea editar los diseñadores de la Base de Datos?"),
                                  QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        EditPersonsForm editPersonsForm(BcNames::EditDesigners);
        editPersonsForm.exec();

        if (!DbHandler::getDesigners(designersData, "desinger_id")) {
            designersData.append(QStringList("Sin Datos"));
            designersListWidget->addItem("Sin Datos");
        } else {
            designersListWidget->clear();
            designersListWidget->addItems(designersData.at(1));
        }

    }

}

void EngineeringForm::editConstructors()
{
    int ret=QMessageBox::question(this, trUtf8("Pregunta"),
                                  trUtf8("¿Desea editar los constructores de la Base de Datos?"),
                                  QMessageBox::Yes | QMessageBox::No);
    if (ret==QMessageBox::Yes) {
        EditPersonsForm editPersonsForm(BcNames::EditConstructors);
        editPersonsForm.exec();

        if (!DbHandler::getConstructors(constructorsData, "constructor_id")) {
            constructorsData.append(QStringList("Sin Datos"));
            constructorNameComboBox->addItem("Sin Datos");
        } else {
            constructorNameComboBox->clear();
            constructorNameComboBox->addItems(constructorsData.at(1));
            constructorNameComboBox->lineEdit()->setText("Asigne Constructor");
        }
    }
}

void EngineeringForm::editAuditors()
{
    int ret=QMessageBox::question(this, trUtf8("Pregunta"),
                                  trUtf8("¿Desea editar los interventores de la Base de Datos?"),
                                  QMessageBox::Yes | QMessageBox::No);
    if (ret==QMessageBox::Yes) {
        EditPersonsForm editPersonsForm(BcNames::EditAuditors);
        editPersonsForm.exec();

        if (!DbHandler::getAuditors(auditorsData, "auditor_id")) {
            auditorsData.append(QStringList("Sin Datos"));
            auditorNameComboBox->addItem("Sin Datos");
        } else {
            auditorNameComboBox->clear();
            auditorNameComboBox->addItems(auditorsData.at(1));
            auditorNameComboBox->lineEdit()->setText("Asigne Interventor");
        }
    }
}

void EngineeringForm::changeInspectionState()
{
    int ret=QMessageBox::question(this, trUtf8("Pregunta"),
                                  trUtf8("¿Desea cambiar el estado de la inspección a \"En Proceso\"?"),
                                  QMessageBox::Yes | QMessageBox::No);

    if (ret==QMessageBox::Yes) {
        if (!DbHandler::updateInspectionState(inspectionsData.at(0).at(0), "En Proceso")) {
            QMessageBox::critical(this, trUtf8("Error Actualizando"),
                                  trUtf8("Error actualizando inspección, ejecute el\n"
                                         "programa bajo consola y revise los mensajes"),
                                  QMessageBox::Cancel);
        } else {
            QMessageBox::information(this, trUtf8("Actualización"),
                                     trUtf8("Inspección marcada como \"En Proceso\".\n"
                                            "ahora podrá agregar dictámenes"),
                                     QMessageBox::Ok);
            findServiceOrder();
        }
    }
}

// NOTE: Estilo de los controles al haber datos
void EngineeringForm::styleWithData()
{
    processesComboBox->setEnabled(true);

}

// NOTE: Estilo de los controles al no haber datos
void EngineeringForm::styleWithoutData()
{



}

// NOTE: Estilo de los controles por defecto.
void EngineeringForm::voidStyle()
{
/* SE IGNORA POR EL MOMENTO
    QList<QLineEdit *> childrenLineEdits = inspectionGroupBox->findChildren<QLineEdit *>(QString(), Qt::FindDirectChildrenOnly);
    foreach(QLineEdit *lineEdit, childrenLineEdits) {
        lineEdit->setEnabled(false);
        lineEdit->setToolTip("");
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                                 "font: 75 oblique 10pt \"DejaVu Sans\";"));
    }


    QList<QComboBox *> childrenComboBoxes = inspectionGroupBox->findChildren<QComboBox *>(QString(), Qt::FindDirectChildrenOnly);
    foreach(QComboBox *comboBox, childrenComboBoxes) {
        comboBox->setEnabled(false);
        comboBox->setToolTip("");
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                                 "font: 75 oblique 10pt \"DejaVu Sans\";"));
    }

    QList<QPushButton *> childrenButtons = this->findChildren<QPushButton *>(QString(), Qt::FindDirectChildrenOnly);
    foreach(QPushButton *pushButton, childrenButtons) {
        pushButton->setEnabled(false);
        pushButton->setToolTip("");
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                                 "font: 75 oblique 10pt \"DejaVu Sans\";"));
    }

    inspectionDateEdit->setToolTip("");
    inspectionDateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                        "font: 75 oblique 10pt \"DejaVu Sans\";"));
    designersListWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                        "font: 75 oblique 10pt \"DejaVu Sans\";"));
    dictumsComboBox->setEnabled(true);
*/
}
