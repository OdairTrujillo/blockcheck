#include "engineering.h"
#include "engineeringutils.h"
#include "dbhandler.h"
#include "accounting.h"
#include "checkfolder.h"
#include "dictum.h"
#include "userlib/filterserviceorders.h"
#include "userlib/bcnamespace.h"
#include "userlib/outsideactions.h"

EngineeringForm::EngineeringForm(QWidget *parent)
    : QDialog(parent)
{
    // Se construyen los controles gráficos
    setupUi(this);

    // Creación de conexiónes entre señales y slots
    connect(findButton, SIGNAL(clicked()),
            this, SLOT(findServiceOrder()));

    connect(inspectionStateComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(setInspectionCity(int)));

    connect(processesComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(getDictums(void)));

    connect(checkFolderButton, SIGNAL(clicked()),
            this, SLOT(showCheckFolderForm()));

    connect(processInspectionButton, SIGNAL(clicked()),
            this, SLOT(processInspection()));

    connect(newDictumButton, SIGNAL(clicked()),
            this, SLOT(newDictum()));

    connect(goDictumButton, SIGNAL(clicked()),
            this, SLOT(goToDictum()));

    connect(inspectionUpdateButton, SIGNAL(clicked()),
            this, SLOT(updateInspectionAction()));

    connect(inspectionSaveButton, SIGNAL(clicked()),
            this, SLOT(saveInspectionChanges()));

    connect(listButton, SIGNAL(clicked()),
            this, SLOT(listServiceOrders()));

    connect(inspectionEndButton, SIGNAL(clicked()),
            this, SLOT(endInspection()));

    // Lleno los controles de la UI de ingenieria.
    prepareEngControls();

    // Consulto las OS's Sin Procesar
    checkEngState();
    QTimer *timer = new QTimer(this);
         connect(timer, SIGNAL(timeout()), this, SLOT(checkEngState()));
         timer->start(OutsideActions::readUpdateTimeConf());
}

// NOTE: Slots para cambiar las ciudades de acuerdo al departamento
void EngineeringForm::setInspectionCity(int index)
{
    inspectionCityComboBox->clear();
    if (DbHandler::getCities(statesData.at(0).at(index), citiesData))
        inspectionCityComboBox->addItems(citiesData.at(2));
    else
        inspectionCityComboBox->addItem("Sin Datos");
}

// NOTE: Encuentra por id de orden de servicio
void EngineeringForm::findServiceOrder()
{
    clearControls();
    // La función devuelve falso al no encontrar o verdadero el encontrar
    if (DbHandler::getServiceOrders(findLineEdit->text(), sosData, "so_id")) {
        // si encuentra entonces se obteiene la propuesta, la cotización y los pagos.
        // Se debe verificar que la os a procesar tenga fecha menor a la actual, osea que se haya inspeccionado en campo.
        if (QDate::fromString(sosData.at(Sos::AssignD).at(0), "yyyy-MM-dd") < QDate::currentDate()) {

            DbHandler::getProposals(sosData.at(Sos::propId).at(0), propsData, "prop_id");
            DbHandler::getQuotations(propsData.at(Props::thrdNit).at(0), thrdData, quotsData, "thrd_nit");
            DbHandler::getProcesses(quotsData.at(Quots::Id).at(0), procsIds);

            // Al encontrar los datos con fecha válidad de procesamiento, se llenan los controles.
            fillData();

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
        clearControls();
    }
}

// NOTE: Actualizar alcance o procesos
void EngineeringForm::processInspection()
{
    if (QMessageBox::information(this, trUtf8("Procesar Orden de Servicio"),
                                 trUtf8("¿Desea procesar esta Orden de Servicio?"),
                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        if (validateData()) {
            if (!updateServiceOrder("En Proceso") || !updateQuotation() || !insertInspection())
                QMessageBox::critical(this, trUtf8("Error procesando Orden de Servicio"),
                                      trUtf8("No se pudieron actualizar los datos \n"
                                             "Ejecute  el programa bajo consola y \n"
                                             "revise   los  mensajes   de   error"),
                                      QMessageBox::Cancel);
            else {
                QMessageBox::information(this, trUtf8("Procesando Orden de Servicio"),
                                         trUtf8("Orden de Servicio procesada con éxito"),
                                         QMessageBox::Ok);
                findServiceOrder();
            }
        }

    }
}


void EngineeringForm::showCheckFolderForm(void)
{
    CheckFolderForm checkFolderForm(this);
    checkFolderForm.saveButton->hide();
    checkFolderForm.storeButton->hide();
    checkFolderForm.createFoilButton->hide();
    checkFolderForm.engObservsTextEdit->setReadOnly(false);
    checkFolderForm.findLineEdit->setText(findLineEdit->text());
    checkFolderForm.findButton->click();
    checkFolderForm.saveEngObservsButton->show();

    checkFolderForm.exec();
}

void EngineeringForm::getDictums(void)
{
    QString processId;
    int index=processesData.at(1).indexOf(processesComboBox->currentText());
    if (index!=-1) {
        processId = processesData.at(0).at(index);

        if (!DbHandler::getDictums(inspectionsData.at(0).at(0), dictumsData, processId)) {
            dictumsComboBox->clear();
            dictumsComboBox->addItem("Sin Dictamen");
            dictumsComboBox->setEnabled(false);
            goDictumButton->setEnabled(false);
            newDictumButton->setEnabled(true);

            QMessageBox::information(this, trUtf8("No existen Datos"),
                                     trUtf8("No se encontró dictamen para este proceso\n"
                                            "intente con otro proeso o cree un dictamen nuevo"),
                                     QMessageBox::Ok);
        } else {
            dictumsComboBox->clear();
            dictumsComboBox->addItems(dictumsData.at(1));
            dictumsComboBox->setEnabled(true);
            goDictumButton->setEnabled(true);
            newDictumButton->setEnabled(true);
        }
    }

}

// NOTE: nuevo dictamen
void EngineeringForm::newDictum()
{
// TODO: validateData aqui
    int index=processesData.at(1).indexOf(processesComboBox->currentText());
    if (index!=-1) {

        QStringList inspectionData, dictumData;

        inspectionData.append(inspectionId); // id de la inspección
        inspectionData.append(processesData.at(0).at(index)); // id del proceso
        inspectionData.append(processesComboBox->currentText()); // nombre del proceso
        inspectionData.append(inspectionScopeTextEdit->toPlainText()); // alcance
        inspectionData.append(inspectionObservTextEdit->toPlainText()); // observaciones
        inspectionData.append(inspectionStateLineEdit->text()); // estado de la inspección
        inspectionData.append(inspectionAddressLineEdit->text()); // direccion
        inspectionData.append(propietaryNameLineEdit->text()); // propietario
        inspectionData.append(inspectionStateComboBox->currentText()); // departamento
        inspectionData.append(inspectionCityComboBox->currentText()); // ciudad
        inspectionData.append(citiesData.at(1).at(inspectionCityComboBox->currentIndex())); // codigo dane
        inspectionData.append(constructorNameComboBox->currentText()); // nombre constructor
        inspectionData.append(constructorsData.at(2).at(constructorNameComboBox->currentIndex())); // mp constructor
        inspectionData.append(auditorNameComboBox->currentText()); // nombre internventor
        inspectionData.append(auditorsData.at(2).at(auditorNameComboBox->currentIndex())); // mp interventor
        inspectionData.append(inspectionsData.at(13).at(0)); // id de orden de servicio
        inspectionData.append(sosData.at(Sos::AssignD).at(0));

        DictumForm dictumForm("newDictum", dictumData, inspectionData, this);
        dictumForm.exec();
        getDictums(); // Aquí es necesario para refrescar el lineedit del número de dictamen.
    } else
        QMessageBox::information(this, trUtf8("Ayuda"),
                                 trUtf8("Seleccione un proceso"),
                                 QMessageBox::Ok);
}

void EngineeringForm::goToDictum()
{

    int index=processesData.at(1).indexOf(processesComboBox->currentText());
    if (index!=-1) {

        QStringList inspectionData, dictumData;

        inspectionData.append(inspectionId); // id de la inspección
        inspectionData.append(processesData.at(0).at(index)); // id del proceso
        inspectionData.append(processesComboBox->currentText()); // nombre del proceso
        inspectionData.append(inspectionScopeTextEdit->toPlainText()); // alcance
        inspectionData.append(inspectionObservTextEdit->toPlainText()); // observaciones
        inspectionData.append(inspectionStateLineEdit->text()); // estado de la inspección
        inspectionData.append(inspectionAddressLineEdit->text()); // direccion
        inspectionData.append(propietaryNameLineEdit->text()); // propietario
        inspectionData.append(inspectionStateComboBox->currentText()); // departamento
        inspectionData.append(inspectionCityComboBox->currentText()); // ciudad
        inspectionData.append(citiesData.at(1).at(inspectionCityComboBox->currentIndex())); // codigo dane
        inspectionData.append(constructorNameComboBox->currentText()); // nombre constructor
        inspectionData.append(constructorsData.at(2).at(constructorNameComboBox->currentIndex())); // mp constructor
        inspectionData.append(auditorNameComboBox->currentText()); // nombre internventor
        inspectionData.append(auditorsData.at(2).at(auditorNameComboBox->currentIndex())); // mp interventor
        inspectionData.append(inspectionsData.at(13).at(0)); // id de orden de servicio

        // Se envían solo los datos del dictamen seleccionado
        for (int i=0; i<dictumsData.size(); i++)
            dictumData.append(dictumsData.at(i).at(dictumsComboBox->currentIndex()));

        DictumForm dictumForm("getDictum", dictumData, inspectionData, this);
        dictumForm.exec();
        getDictums(); // Aquí es necesario para refrescar el lineedit del número de dictamen.
    } else
        QMessageBox::information(this, trUtf8("Ayuda"),
                                 trUtf8("Seleccione un proceso"),
                                 QMessageBox::Ok);
}


void EngineeringForm::updateInspectionAction()
{
    styleWithoutData();
    inspectionSaveButton->setEnabled(true);
    processInspectionButton->setEnabled(false);
}

void EngineeringForm::saveInspectionChanges()
{
    if (QMessageBox::information(this, trUtf8("Actualizar Inspección"),
                                 trUtf8("¿Desea actualizar esta Inspección?"),
                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        if (validateData()) {
            if (!updateServiceOrder(inspectionStateLineEdit->text()) || !updateQuotation() || !updateInspection())
                QMessageBox::critical(this, trUtf8("Error actualizando Inspección"),
                                      trUtf8("No se pudieron actualizar los datos \n"
                                             "Ejecute  el programa bajo consola y \n"
                                             "revise   los  mensajes   de   error"),
                                      QMessageBox::Cancel);
            else {
                QMessageBox::information(this, trUtf8("Actualizando Inspección"),
                                         trUtf8("Inspección actualizada con éxito"),
                                         QMessageBox::Ok);
                findServiceOrder();
            }
        }

    }
}

// NOTE: Lista las ordenes de servicio
void EngineeringForm::listServiceOrders()
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

// NOTE: Finalizar Inspeccion
void EngineeringForm::endInspection(void)
{
        if (dictumsData.at(0).size()==0) {
            int ret=QMessageBox::question(this, trUtf8("Finalizar Inspección"),
                                          trUtf8("¿Desea marcar como No Dictaminada esta inspección?"),
                                          QMessageBox::Yes | QMessageBox::Cancel);
            if (ret==QMessageBox::Yes) {
                if (!DbHandler::updateInspectionState(inspectionsData.at(0).at(0), "No Dictaminada")) {
                    QMessageBox::critical(this, trUtf8("Error Actualizando"),
                                          trUtf8("Error actualizando inspección, ejecute el\n"
                                                 "programa bajo consola y revise los mensajes"),
                                          QMessageBox::Cancel);
                } else {
                    QMessageBox::information(this, trUtf8("Actualización"),
                                             trUtf8("Inspección marcada como \"No Dictaminada\".\n"
                                                    "No se podrán agregar dictámenes hasta\n"
                                                    "cambiar su estado a \"En Proceso\""),
                                             QMessageBox::Ok);
                    inspectionStateLineEdit->setText("No Dictaminada");
                    inspectionEndButton->setEnabled(false);
                    changeInspectionStateAct->blockSignals(false);
                    newDictumButton->hide();
                }
            }


        } else {
            int ret=QMessageBox::question(this, trUtf8("Finalizar Inspección"),
                                          trUtf8("¿Desea marcar como Finalizada esta inspección?"),
                                          QMessageBox::Yes | QMessageBox::Cancel);
            if (ret==QMessageBox::Yes) {
                if (!DbHandler::updateInspectionState(inspectionsData.at(0).at(0), "Finalizada")) {
                    QMessageBox::critical(this, trUtf8("Error Actualizando"),
                                          trUtf8("Error actualizando inspección, ejecute el\n"
                                                 "programa bajo consola y revise los mensajes"),
                                          QMessageBox::Cancel);
                } else {
                    QMessageBox::information(this, trUtf8("Actualización"),
                                             trUtf8("Inspección marcada como \"Finalizada\".\n"
                                                    "No se podrán agregar dictámenes hasta\n"
                                                    "cambiar su estado a \"En Proceso\""),
                                             QMessageBox::Ok);
                    inspectionStateLineEdit->setText("Finalizada");
                    inspectionEndButton->setEnabled(false);
                    changeInspectionStateAct->blockSignals(false);
                    newDictumButton->hide();
                }
            }
        }
}

