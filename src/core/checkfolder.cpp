#include "checkfolder.h"
#include "dbhandler.h"
#include "sotracking.h"
#include "userlib/filterserviceorders.h"
#include "userlib/bcnamespace.h"
#include "userlib/outsideactions.h"

CheckFolderForm::CheckFolderForm(QWidget *parent)
    : QDialog(parent)
{
    // TODO: Crear ventana de tracking.
    setupUi(this);

    connect(findButton, SIGNAL(clicked()),
            this, SLOT(findServiceOrder()));

    connect(saveButton, SIGNAL(clicked()),
            this, SLOT(updateServiceOrder()));

    connect(listButton, SIGNAL(clicked()),
            this, SLOT(listServiceOrders()));

    connect(storeButton, SIGNAL(clicked()),
            this, SLOT(storeServiceOrder()));

    connect(createFoilButton, SIGNAL(clicked()),
            this, SLOT(createFoil()));

    connect(soTrackingButton, SIGNAL(clicked()),
            this, SLOT(showSoTracking()));

    connect(saveEngObservsButton, SIGNAL(clicked()),
            this, SLOT(saveEngObservs()));

    soDateEdit->setDate(QDate::currentDate());
    saveEngObservsButton->hide(); // Se oculta porque solo puede ser visible desde el módulo de ingeniería.

    // Obtengo los distintos folios o AZ
    if (!DbHandler::getRecords(recordsData))
        recordsData.append(QStringList("Sin Datos"));
    for (int i=0; i<recordsData.at(1).size();i++) {
        QListWidgetItem *item = new QListWidgetItem;
        item->setData( Qt::DisplayRole, recordsData.at(1).at(i));
        item->setData( Qt::CheckStateRole, Qt::Unchecked);
        recordFoilListWidget->addItem( item );
    }


    // Consulto las OS's Sin Procesar o con documentos incompletos
    checkDocsState();

    // Es necesario un widget para asignarle un Layout
    QWidget *temp = new QWidget(this);
    // Un Vertical Layout donde voy a agregar los checkbox
    QVBoxLayout *docsLayout = new QVBoxLayout;

    if (DbHandler::getDocuments(documentsData, "RIG")) {
        for (int i=0; i < documentsData.at(0).size(); i++) {
            // Cada documento creo un checkbox nuevo y le asigno de texto el nombre del documento
            QCheckBox *docCheckBox = new QCheckBox;
            docCheckBox->setText(documentsData.at(1).at(i));
            docCheckBox->setFont(QFont("Dejavu Sans",12));
            // Guardo esos checkbox en una lista
            docsCheckBoxes.append(docCheckBox);
            // Agrego los documentos a el Vertical Layout
            docsLayout->addWidget(docCheckBox);

        }
        // Asigno el layout a el widget
        temp->setLayout(docsLayout);
        // Asigno el widget a el scroll area
        scrollArea->setWidget(temp);
    }

    QTimer *timer = new QTimer(this);
         connect(timer, SIGNAL(timeout()), this, SLOT(checkDocsState()));
         timer->start(OutsideActions::readUpdateTimeConf());


}

// NOTE: Encuentra por id de orden de servicio
void CheckFolderForm::findServiceOrder()
{
    for (int i=0; i<docsCheckBoxes.size(); i++)
        docsCheckBoxes.at(i)->setChecked(false);

    // Devuelve los QList modificados
    if (DbHandler::getServiceOrders(findLineEdit->text(), sosData, "so_id")) {
        // Se debe verificar que la os a procesar esté inspeccionada ya

        if (QDate::fromString(sosData.at(Sos::AssignD).at(0), "yyyy-MM-dd") < QDate::currentDate()) {

            QStringList soDocsIds;
            DbHandler::getSoDocuments(sosData.at(Sos::Id).at(0), soDocsIds);

            int index;
            for (int i=0; i<soDocsIds.size();i++) {
                // indexOf me entrega la posición en la que está el id del documento, con esa posición
                // reemplazo el string vacío por el nombre del documento
                index=documentsData.at(0).indexOf(soDocsIds.at(i));
                if (index >=0) // para prevenir el -1 al no encontrar el Id
                    docsCheckBoxes.at(index)->setChecked(true);
            }

            fillSoData();
            saveButton->setEnabled(true);
            storeButton->setEnabled(true);
            soTrackingButton->setEnabled(true);
            saveEngObservsButton->setEnabled(true);
        } else {
            QMessageBox::warning(this, trUtf8("Fechas"),
                                 trUtf8("No es posible procesar un expediente con fecha\n"
                                        "de inspección mayor a la fecha actual"),
                                 QMessageBox::Cancel);
        }

    } else {
        QMessageBox::warning(this, trUtf8("Sin Datos"),
                             trUtf8("No se encontraron datos con: " + findLineEdit->text().toUtf8()),
                             QMessageBox::Cancel);
        saveButton->setEnabled(false);
        storeButton->setEnabled(false);
        soTrackingButton->setEnabled(false);
        saveEngObservsButton->setEnabled(false);
    }
}

// NOTE: Actualiza documentos
void CheckFolderForm::updateServiceOrder()
{
    QString soDocState;
    // Almacenar lista de documentos chequeados
    QStringList documentsIds;
    // Debo recorrer la lista de checkbox

    for (int i=0; i<docsCheckBoxes.size(); i++)
        // Revisar si está chequeado ....
        if (docsCheckBoxes.at(i)->isChecked()==true)
            // ... si lo está introducir el id de documento chequeado
            documentsIds.append(documentsData.at(0).at(i));
        else {
            soDocState="Incompleta";
        }

    if (soDocState == "Incompleta") {
        int ret=QMessageBox::question(this, trUtf8("Documentación Incompleta"),
                                      trUtf8("¿Desea guardar este expediente como incompleto?"),
                                      QMessageBox::Yes | QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Yes:
            // TODO: Insertar registro de incompleta en el Log BlockCheck
            if (DbHandler::updateSoDocState(sosData.at(Sos::Id).at(0), soDocState)) {
                DbHandler::updateSoDocuments(sosData.at(Sos::Id).at(0), documentsIds);
            }
            else
                QMessageBox::warning(this, trUtf8("Error"),
                                           trUtf8("Error actualizando estado de documentos, revise la consola"),
                                                  QMessageBox::Ok);
            break;

        case QMessageBox::Cancel:
            findLineEdit->setFocus();
            break;
        }
    } else {
        // Se guarda sin novedad
        soDocState="Revisada";
        if (DbHandler::updateSoDocState(sosData.at(Sos::Id).at(0), soDocState)) {
            DbHandler::updateSoDocuments(sosData.at(Sos::Id).at(0), documentsIds);
            QMessageBox::information(this, trUtf8("Actualizado con éxito"),
                                                  trUtf8("Documentos actualizados con éxito"),
                                                  QMessageBox::Ok);
        }
        else
            QMessageBox::warning(this, trUtf8("Error"),
                                       trUtf8("Error actualizando estado de documentos, revise la consola"),
                                              QMessageBox::Ok);
    }
    findServiceOrder();
    checkDocsState();
}

// NOTE: Archiva la orden de servicio o expediente en las AZ
void CheckFolderForm::storeServiceOrder()
{
    QStringList soTrackingData;
    if(DbHandler::getSoTracking(sosData.at(Sos::Id).at(0), soTrackingData)) {

        // Almacenar lista de az chequeada
        QStringList recordsIds;
        for (int i=0; i<recordFoilListWidget->count(); i++)
            // Revisar si está chequeado ....
            if (recordFoilListWidget->item(i)->checkState()==Qt::Checked)
                // ... si lo está introducir el id de la az chequeada
                recordsIds.append(recordsData.at(0).at(i));
        if(recordsIds.isEmpty())
            recordsIds.append("1"); // Con esto se asigna a no archivada
        else // Se hace para quitar Sin Archivar en caso de estar checado una az
            if(recordsIds.size()>1 && recordsIds.at(0)=="1")
                recordsIds.removeAt(0);

        if (!DbHandler::updateSoRecords(sosData.at(Sos::Id).at(0), recordsIds))
            qDebug()<< trUtf8("updateSoRecords devolvió false al intentar actualizar la OS");
        else {
            QMessageBox::information(this, trUtf8("Archivando"),
                                     trUtf8("Orden de Servicio archivada con éxito"),
                                     QMessageBox::Ok);
            findServiceOrder();
            checkDocsState();
        }
    } else {
        QMessageBox::warning(this, trUtf8("Falta Radicado"),
                             trUtf8("Debe radicar el expediente para poder archivarlo"),
                             QMessageBox::Ok);
    }
}


// NOTE: Llenado de datos de orden de servicio
void CheckFolderForm::fillSoData()
{
    soIdLineEdit->setText(sosData.at(Sos::Id).at(0));
    soDateEdit->setDate(QDate::fromString(sosData.at(Sos::Date).at(0), "yyyy-MM-dd"));
    soScopeTextEdit->setText(sosData.at(Sos::Scope).at(0));
    soStateLineEdit->setText(sosData.at(Sos::AccProc).at(0));
    soAssignDateEdit->setDate(QDate::fromString(sosData.at(Sos::AssignD).at(0), "yyyy-MM-dd"));

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

    folderStateLineEdit->setText(sosData.at(Sos::DocProc).at(0));
    engObservsTextEdit->setText(sosData.at(Sos::EngObserv).at(0));
    admObservsTextEdit->setText(sosData.at(Sos::AdmObserv).at(0));
}

// NOTE: Limpiar controles de orden de servicio
void CheckFolderForm::clearSoControls()
{
    soDateEdit->setDate(QDate::currentDate());
    soAssignDateEdit->setDate(QDate::currentDate());
    // Deschequear primero para luego seleccionar las AZ.
    for (int i=0; i<recordFoilListWidget->count(); i++)
        recordFoilListWidget->item(i)->setCheckState(Qt::Unchecked);
    soScopeTextEdit->clear();
    soStateLineEdit->clear();
    folderStateLineEdit->clear();
    engObservsTextEdit->clear();
    admObservsTextEdit->clear();
}

// NOTE: Lista las ordenes de servicio
void CheckFolderForm::listServiceOrders()
{
    // creo el diálogo de filtrado
    FilterServiceOrdersForm filterForm(this);
    filterForm.exec();
    // siempre y cuando halla una orden de servicio encontrada por FilterForm, se cargan los
    // datos llamando a findButton->click()
    if (!filterForm.so_id.isEmpty()) {
        findLineEdit->setText(filterForm.so_id);
        findButton->click();
    }
}

// NOTE: Revisa si hay OS's con documentos incompletos o sin revisar
void CheckFolderForm::checkDocsState()
{
    if (DbHandler::getServiceOrders("Sin Procesar", sosData2, "so_doc_processed"))
        noCheckedLcdNumber->display(sosData2.at(Sos::Id).size());
    else {
        noCheckedLcdNumber->display(0);
       // qDebug()<< trUtf8("getServiceOrder devolvió false al intentar obtener OS's Sin Procesar");
    }

    if (DbHandler::getServiceOrders("Incompleta", sosData2, "so_doc_processed"))
        incompleteLcdNumber->display(sosData2.at(Sos::Id).size());
    else {
        incompleteLcdNumber->display(0);
       // qDebug()<< trUtf8("getServiceOrder devolvió false al intentar obtener OS's Incompletas");
    }

    if (DbHandler::getServiceOrders("Observada", sosData2, "so_doc_processed"))
        observedLcdNumber->display(sosData2.at(Sos::Id).size());
    else {
        observedLcdNumber->display(0);
       // qDebug()<< trUtf8("getServiceOrder devolvió false al intentar obtener OS's Incompletas");
    }
}

// NOTE: Crea nuevos Folios o AZ
void CheckFolderForm::createFoil()
{
    bool ok;
    QString newFoil = QInputDialog::getText(this, tr("Ingrese Nombre"),
                                         trUtf8("Nombre del Folio o AZ:"), QLineEdit::Normal,
                                         "", &ok);
    if (ok && !newFoil.isEmpty()) {
        newFoil.toUpper();
        if (DbHandler::insertRecordFoil(newFoil)) {
            DbHandler::getRecords(recordsData); // Actualizo la lista desde la DB
            QListWidgetItem *item = new QListWidgetItem; // Agrego el item nuevo desde newFoil, no desde la lista
            item->setData( Qt::DisplayRole, newFoil);
            item->setData( Qt::CheckStateRole, Qt::Checked);
            recordFoilListWidget->addItem( item );
        } else
            qDebug() << trUtf8("DbHandler::insertRecordFoil() devolvió false al tratar de crear el folio");
    }
}

// NOTE: Muestra ventana de tracking
void CheckFolderForm::showSoTracking()
{
    // creo el diálogo de filtrado
    SoTrackingForm soTrackingForm(this, sosData.at(Sos::Id).at(0));
    // La siguiente comprobación se hace por si el módulo se cargó desde el de ingeniería
    if (saveButton->isVisible()==false)
        soTrackingForm.saveButton->setVisible(false);
    soTrackingForm.exec();

}

// NOTE: Guarda observacion de ingenieria
void CheckFolderForm::saveEngObservs()
{
    // Al guardar la observación, esta puede estar vacía por lo que el estado sería el original, así que
    // hay que chequear su estado y volverlo a guardar
    QString soDocState;
    if (engObservsTextEdit->toPlainText()=="") {
        soDocState="Revisada";
        for (int i=0; i<docsCheckBoxes.size(); i++)
            // Revisar si no está chequeado ....
            if (docsCheckBoxes.at(i)->isChecked()==false)
                soDocState="Incompleta";
    }
    else
        soDocState="Observada";
    if (!DbHandler::updateSoEngObservations(sosData.at(Sos::Id).at(0), engObservsTextEdit->toPlainText())) {
        QMessageBox::warning(this, trUtf8("Actualizando Datos"),
                             trUtf8("No se ha podido actualizar las observaciones\n"
                                    "Ejecute el programa bajo consola y revise los mensajes"),
                             QMessageBox::Cancel);
        qDebug() << "DbHandler::updateSoEngObservations ha devuelto false";
    } else {
        DbHandler::updateSoDocState(sosData.at(Sos::Id).at(0), soDocState);
        QMessageBox::information(this, trUtf8("Actualizando Datos"),
                                 trUtf8("Observaciones actualizadas con éxito"),
                                 QMessageBox::Ok);
    }
    findServiceOrder(); // Para actualizar los estados
}
