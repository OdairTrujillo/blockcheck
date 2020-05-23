#include "editpersons.h"
#include "dbhandler.h"
#include "userlib/logger.h"

EditPersonsForm::EditPersonsForm(int person_Type, QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    personType=person_Type;

    connect(updateButton, SIGNAL(clicked()),
            this, SLOT(updatePerson()));

    connect(newButton, SIGNAL(clicked()),
            this, SLOT(newPerson()));

    connect(saveButton, SIGNAL(clicked()),
            this, SLOT(savePerson()));

    connect(removeButton, SIGNAL(clicked()),
            this, SLOT(removePerson()));

    passwordLineEdit->setEchoMode(QLineEdit::Password);

    setDialogType();

}

// NOTE: Rellenar los controles de acuerdo al tipo de edicion que se requiera
void EditPersonsForm::setDialogType()
{
    personsComboBox->blockSignals(true);
    personsComboBox->clear();

    switch (personType) {

    case BcNames::EditUsers:
        styleWithStaff();

        this->setWindowTitle(trUtf8("Editar Usuarios"));
        if (!DbHandler::getUsers(usersData))
            usersData.append(QStringList("Sin Datos"));
        else {
            personsComboBox->addItems(usersData.at(1));

            connect(personsComboBox, SIGNAL(currentIndexChanged(int)),
                    this, SLOT(fillUserData(int)));
            fillUserData(0);
        }
        break;

    case BcNames::EditInspectors:
        styleWithStaff();

        this->setWindowTitle(trUtf8("Editar Inspectores"));
        if (!DbHandler::getInspectors(inspectorsData, "Todos"))
            inspectorsData.append(QStringList("Sin Datos"));
        else {
            personsComboBox->addItems(inspectorsData.at(1));

            connect(personsComboBox, SIGNAL(currentIndexChanged(int)),
                    this, SLOT(fillInspectorData(int)));

            // Se ocultan controles adicionales que no corresponden a inspector
            passwordLabel->hide();
            passwordLineEdit->hide();
            longNameLabel->hide();
            longNameLineEdit->hide();
            chargeLabel->hide();
            chargeComboBox->hide();
            levelLabel->hide();
            levelSpinBox->hide();
            percentageSpinBox->setEnabled(false);

            fillInspectorData(0);
        }
        break;

    case BcNames::EditDesigners:
        styleWithThrds();

        this->setWindowTitle(trUtf8("Editar Diseñadores"));

        if (!DbHandler::getDesigners(designersData, "designer_name"))
            designersData.append(QStringList("Sin Datos"));
        else {
            personsComboBox->addItems(designersData.at(1));

            connect(personsComboBox, SIGNAL(currentIndexChanged(int)),
                    this, SLOT(fillDesignerData(int)));
            fillDesignerData(0);
        }
        break;

    case BcNames::EditConstructors:
        styleWithThrds();

        this->setWindowTitle(trUtf8("Editar Constructores"));
        if (!DbHandler::getConstructors(constructorsData, "constructor_name"))
            constructorsData.append(QStringList("Sin Datos"));
        else {
            personsComboBox->addItems(constructorsData.at(1));

            connect(personsComboBox, SIGNAL(currentIndexChanged(int)),
                    this, SLOT(fillConstructorData(int)));
            fillConstructorData(0);
        }
        break;

    case BcNames::EditAuditors:
        styleWithThrds();

        this->setWindowTitle(trUtf8("Editar Interventores"));
        if (!DbHandler::getAuditors(auditorsData, "auditor_name"))
            auditorsData.append(QStringList("Sin Datos"));
        else {
            personsComboBox->addItems(auditorsData.at(1));

            connect(personsComboBox, SIGNAL(currentIndexChanged(int)),
                    this, SLOT(fillAuditorData(int)));
            fillAuditorData(0);
        }
        break;

    default:
        QMessageBox::critical(this, "Error", trUtf8("Opción no válida para editar personas"),
                                                    QMessageBox::Cancel);
        break;
    }

    personsComboBox->blockSignals(false);

}

// NOTE: Llenar datos de Interventor
void EditPersonsForm::fillUserData(int index)
{
    passwordLineEdit->setText(usersData.at(Users::Passwd).at(index));
    longNameLineEdit->setText(usersData.at(Users::LName).at(index));
    chargeComboBox->setCurrentIndex(chargeComboBox->findText(usersData.at(Users::Charge).at(index)));
    levelSpinBox->setValue(usersData.at(Users::Level).at(index).toInt());
    addressLineEdit->setText(usersData.at(Users::Addrs).at(index));
    mailLineEdit->setText(usersData.at(Users::Mail).at(index));
    celLineEdit->setText(usersData.at(Users::Cel).at(index));
    phoneLineEdit->setText(usersData.at(Users::Tel).at(index));
    availibleComboBox->setCurrentIndex(availibleComboBox->findText(usersData.at(Users::Availb).at(index)));
    percentageSpinBox->setValue(usersData.at(Users::Perc).at(index).toDouble()*100);
    nitLineEdit->setText(usersData.at(Users::Nit).at(index));

    if (chargeComboBox->currentText()!="Comercial") {
        percentageSpinBox->setEnabled(false);
        percentageSpinBox->setValue(0);
    } else {
        percentageSpinBox->setEnabled(true);
    }

}

// NOTE: Llenar datos de Interventor
void EditPersonsForm::fillInspectorData(int index)
{
    mpLineEdit->setText(inspectorsData.at(Insp::Mp).at(index));
    addressLineEdit->setText(inspectorsData.at(Insp::Addrs).at(index));
    mailLineEdit->setText(inspectorsData.at(Insp::Mail).at(index));
    celLineEdit->setText(inspectorsData.at(Insp::Cel).at(index));
    phoneLineEdit->setText(inspectorsData.at(Insp::Tel).at(index));
    availibleComboBox->setCurrentIndex(availibleComboBox->findText(inspectorsData.at(Insp::Availb).at(index)));
    percentageSpinBox->setValue(inspectorsData.at(Insp::Perc).at(index).toDouble()*100);
    nitLineEdit->setText(inspectorsData.at(Insp::Nit).at(index));
}

// NOTE: Llenar datos de disenador
void EditPersonsForm::fillDesignerData(int index)
{
    if (index==0)
        disableControls();
    else
        enableControls();
    mpLineEdit->setText(designersData.at(2).at(index));
    mailLineEdit->setText(designersData.at(3).at(index));
    celLineEdit->setText(designersData.at(4).at(index));
    nitLineEdit->setText(designersData.at(5).at(index));
}

// NOTE: Llenar datos de constructor
void EditPersonsForm::fillConstructorData(int index)
{
    if (index==0)
        disableControls();
    else
        enableControls();
    mpLineEdit->setText(constructorsData.at(2).at(index));
    mailLineEdit->setText(constructorsData.at(3).at(index));
    celLineEdit->setText(constructorsData.at(4).at(index));
    nitLineEdit->setText(constructorsData.at(5).at(index));
}

// NOTE: Llenar datos de Interventor
void EditPersonsForm::fillAuditorData(int index)
{
    if (index==0)
        disableControls();
    else
        enableControls();
    mpLineEdit->setText(auditorsData.at(2).at(index));
    mailLineEdit->setText(auditorsData.at(3).at(index));
    celLineEdit->setText(auditorsData.at(4).at(index));
    nitLineEdit->setText(auditorsData.at(5).at(index));
}

// NOTE: Actualizar una persona
void EditPersonsForm::updatePerson()
{
    QStringList inspDetailData;
    bool ok;
    if (validateData()) {

        QStringList userData;
        QStringList inspectorData;
        QStringList designerData;
        QStringList constructorData;
        QStringList auditorData;

        switch(personType) {

        case BcNames::EditUsers:

            userData.append(usersData.at(0).at(personsComboBox->currentIndex()));
            userData.append(personsComboBox->lineEdit()->text());
            userData.append(passwordLineEdit->text());
            userData.append(longNameLineEdit->text());
            userData.append(chargeComboBox->currentText());
            userData.append(QString::number(levelSpinBox->value()));
            userData.append(addressLineEdit->text());
            userData.append(mailLineEdit->text());
            userData.append(celLineEdit->text());
            userData.append(phoneLineEdit->text());
            userData.append(availibleComboBox->currentText());
            userData.append(QString::number(percentageSpinBox->value()/100));
            userData.append(nitLineEdit->text());

            if (!DbHandler::updateUser(userData)) {
                QMessageBox::critical(this, trUtf8("Error actualizando datos"),
                                      trUtf8("Error actualizando usuario, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::updateUser devolvió false al tratar de actualizar el usuario");
                break;
            } else {
                setDialogType();
                personsComboBox->setCurrentIndex(usersData.at(1).indexOf(userData.at(1)));
                Logger::updateUser(userName, longNameLineEdit->text());
                QMessageBox::information(this, trUtf8("Actualizando Usuario"),
                                         trUtf8("Usuario actualizado con éxito"),
                                         QMessageBox::Ok);
            }
            break;

        case BcNames::EditInspectors:

            // Pregunto si ha cambiado el estado del inspector
            if ((availibleComboBox->currentText())!=(inspectorsData.at(Insp::Availb).at(personsComboBox->currentIndex()))) {
                QString inspDetail = QInputDialog::getText(this, trUtf8("Razón de Cambio de Estado"),
                                                     trUtf8("Escriba la razón por la cual se cambia el estado del inspecctor,\n "
                                                            "o presione cancelar para no actualizar el inspector:"),
                                                     QLineEdit::Normal, "", &ok);
                if (inspDetail.isEmpty()) {
                    QMessageBox::warning(this, trUtf8("Inspector no Actualizado"),
                                             trUtf8("Es necesario ingresar un motivo"),
                                             QMessageBox::Ok);
                    availibleComboBox->setCurrentIndex(availibleComboBox->findText(inspectorsData.at(Insp::Availb).at(0)));
                    break;
                }
                if (!ok)
                   break;

                inspDetailData.append(availibleComboBox->currentText());
                inspDetailData.append(inspDetail);
                inspDetailData.append(inspectorsData.at(Insp::Id).at(personsComboBox->currentIndex()));
            }

            inspectorData.append(inspectorsData.at(0).at(personsComboBox->currentIndex()));
            inspectorData.append(personsComboBox->lineEdit()->text());
            inspectorData.append(mpLineEdit->text());
            inspectorData.append(addressLineEdit->text());
            inspectorData.append(mailLineEdit->text());
            inspectorData.append(celLineEdit->text());
            inspectorData.append(phoneLineEdit->text());
            inspectorData.append(availibleComboBox->currentText());
            inspectorData.append(QString::number(percentageSpinBox->value()/100));
            inspectorData.append(nitLineEdit->text());

            if (!DbHandler::updateInspector(inspectorData, inspDetailData)) {
                QMessageBox::critical(this, trUtf8("Error actualizando datos"),
                                      trUtf8("Error actualizando inspector, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::updateInspector devolvió false al tratar de actualizar el inspector");
                break;
            } else {
                setDialogType();
                Logger::updateInspector(userName, personsComboBox->lineEdit()->text());
                personsComboBox->setCurrentIndex(inspectorsData.at(1).indexOf(inspectorData.at(1)));
                QMessageBox::information(this, trUtf8("Actualizando Inspector"),
                                         trUtf8("Inspector actualizado con éxito"),
                                         QMessageBox::Ok);
            }
            break;

        case BcNames::EditDesigners:

            designerData.append(designersData.at(0).at(personsComboBox->currentIndex()));
            designerData.append(personsComboBox->lineEdit()->text());
            designerData.append(mpLineEdit->text());
            designerData.append(mailLineEdit->text());
            designerData.append(celLineEdit->text());
            designerData.append(nitLineEdit->text());

            if (!DbHandler::updateDesigner(designerData)) {
                QMessageBox::critical(this, trUtf8("Error obteniendo datos"),
                                      trUtf8("Error actualizando diseñador, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::updateDesigner devolvió false al tratar de actualizar el diseñador");
                break;
            } else {
                setDialogType();
                personsComboBox->setCurrentIndex(designersData.at(1).indexOf(designerData.at(1)));
                QMessageBox::information(this, trUtf8("Actualizando Diseñador"),
                                         trUtf8("Diseñador actualizado con éxito"),
                                         QMessageBox::Ok);
            }
            break;

        case BcNames::EditConstructors:

            constructorData.append(constructorsData.at(0).at(personsComboBox->currentIndex()));
            constructorData.append(personsComboBox->lineEdit()->text());
            constructorData.append(mpLineEdit->text());
            constructorData.append(mailLineEdit->text());
            constructorData.append(celLineEdit->text());
            constructorData.append(nitLineEdit->text());

            if (!DbHandler::updateConstructor(constructorData)) {
                QMessageBox::critical(this, trUtf8("Error obteniendo datos"),
                                      trUtf8("Error actualizando constructor, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::updateConstructor devolvió false al tratar de actualizar el constructor");
                break;
            } else {
                setDialogType();
                personsComboBox->setCurrentIndex(constructorsData.at(1).indexOf(constructorData.at(1)));
                QMessageBox::information(this, trUtf8("Actualizando Constructor"),
                                         trUtf8("Constructor actualizado con éxito"),
                                         QMessageBox::Ok);
            }
            break;

        case BcNames::EditAuditors:

            auditorData.append(auditorsData.at(0).at(personsComboBox->currentIndex()));
            auditorData.append(personsComboBox->lineEdit()->text());
            auditorData.append(mpLineEdit->text());
            auditorData.append(mailLineEdit->text());
            auditorData.append(celLineEdit->text());
            auditorData.append(nitLineEdit->text());

            if (!DbHandler::updateAuditor(auditorData)) {
                QMessageBox::critical(this, trUtf8("Error obteniendo datos"),
                                      trUtf8("Error actualizando Interventor, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::updateAuditor devolvió false al tratar de actualizar el interventor");
                break;
            } else {
                setDialogType();
                personsComboBox->setCurrentIndex(auditorsData.at(1).indexOf(auditorData.at(1)));
                QMessageBox::information(this, trUtf8("Actualizando Interventor"),
                                         trUtf8("Interventor actualizado con éxito"),
                                         QMessageBox::Ok);
            }
            break;

        }
    }
}

// NOTE: Preparar controles para nueva persona
void EditPersonsForm::newPerson()
{
    clearControls();
    enableControls();
    personsComboBox->setFocus();
    saveButton->show();
    newButton->hide();
    updateButton->setEnabled(false);
    removeButton->setEnabled(false);
}

// NOTE: Guardar nueva persona
void EditPersonsForm::savePerson()
{
    if (validateData()) {

        QStringList userData;
        QStringList inspectorData;
        QStringList designerData;
        QStringList constructorData;
        QStringList auditorData;

        switch(personType) {

        case BcNames::EditUsers:

            userData.append(personsComboBox->lineEdit()->text());
            userData.append(passwordLineEdit->text());
            userData.append(longNameLineEdit->text());
            userData.append(chargeComboBox->currentText());
            userData.append(QString::number(levelSpinBox->value()));
            userData.append(addressLineEdit->text());
            userData.append(mailLineEdit->text());
            userData.append(celLineEdit->text());
            userData.append(phoneLineEdit->text());
            userData.append(availibleComboBox->currentText());
            userData.append(QString::number(percentageSpinBox->value()/100));
            userData.append(nitLineEdit->text());

            if (!DbHandler::insertUser(userData)) {
                QMessageBox::critical(this, trUtf8("Error insertando datos"),
                                      trUtf8("Error insertando usuario, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::insertUser devolvió false al tratar de insertar el usuario");
                break;
            } else {
                setDialogType();
                personsComboBox->setCurrentIndex(usersData.at(1).indexOf(userData.at(0)));
                QMessageBox::information(this, trUtf8("Creando Usuario"),
                                         trUtf8("Usuario creado con éxito"),
                                         QMessageBox::Ok);
            }
            break;

        case BcNames::EditInspectors:

            inspectorData.append(personsComboBox->lineEdit()->text());
            inspectorData.append(mpLineEdit->text());
            inspectorData.append(addressLineEdit->text());
            inspectorData.append(mailLineEdit->text());
            inspectorData.append(celLineEdit->text());
            inspectorData.append(phoneLineEdit->text());
            inspectorData.append(availibleComboBox->currentText());
            inspectorData.append(QString::number(percentageSpinBox->value()/100));
            inspectorData.append(nitLineEdit->text());

            if (!DbHandler::insertInspector(inspectorData)) {
                QMessageBox::critical(this, trUtf8("Error insertando datos"),
                                      trUtf8("Error insertando inspector, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::insertInspector devolvió false al tratar de actualizar el inspector");
                break;
            } else {
                setDialogType();
                personsComboBox->setCurrentIndex(inspectorsData.at(1).indexOf(inspectorData.at(0)));
                QMessageBox::information(this, trUtf8("Creando Inspector"),
                                         trUtf8("Inspector creado con éxito"),
                                         QMessageBox::Ok);
            }
            break;

        case BcNames::EditDesigners:

            designerData.append(personsComboBox->lineEdit()->text());
            designerData.append(mpLineEdit->text());
            designerData.append(mailLineEdit->text());
            designerData.append(celLineEdit->text());
            designerData.append(nitLineEdit->text());

            if (!DbHandler::insertDesigner(designerData)) {
                QMessageBox::critical(this, trUtf8("Error insertando datos"),
                                      trUtf8("Error creando diseñador, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::insertDesigner devolvió false al tratar de insertar el diseñador");
                break;
            } else {
                setDialogType();
                newButton->show();
                saveButton->hide();
                updateButton->setEnabled(true);
                removeButton->setEnabled(true);
                personsComboBox->setCurrentIndex(designersData.at(1).indexOf(designerData.at(0)));
                QMessageBox::information(this, trUtf8("Creando Diseñador"),
                                         trUtf8("Diseñador creado con éxito"),
                                         QMessageBox::Ok);
                break;
            }

        case BcNames::EditConstructors:

            constructorData.append(personsComboBox->lineEdit()->text());
            constructorData.append(mpLineEdit->text());
            constructorData.append(mailLineEdit->text());
            constructorData.append(celLineEdit->text());
            constructorData.append(nitLineEdit->text());

            if (!DbHandler::insertConstructor(constructorData)) {
                QMessageBox::critical(this, trUtf8("Error insertando datos"),
                                      trUtf8("Error creando constructor, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::insertConstructor devolvió false al tratar de insertar el constructor");
                break;
            } else {
                setDialogType();
                newButton->show();
                saveButton->hide();
                updateButton->setEnabled(true);
                removeButton->setEnabled(true);
                personsComboBox->setCurrentIndex(constructorsData.at(1).indexOf(constructorData.at(0)));
                QMessageBox::information(this, trUtf8("Creando Constructor"),
                                         trUtf8("Constructor creado con éxito"),
                                         QMessageBox::Ok);
                break;
            }

        case BcNames::EditAuditors:

            auditorData.append(personsComboBox->lineEdit()->text());
            auditorData.append(mpLineEdit->text());
            auditorData.append(mailLineEdit->text());
            auditorData.append(celLineEdit->text());
            auditorData.append(nitLineEdit->text());

            if (!DbHandler::insertAuditor(auditorData)) {
                QMessageBox::critical(this, trUtf8("Error insertando datos"),
                                      trUtf8("Error creando Interventor, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::insertAuditor devolvió false al tratar de insertar el interventor");
                break;
            } else {
                setDialogType();
                newButton->show();
                saveButton->hide();
                updateButton->setEnabled(true);
                removeButton->setEnabled(true);
                personsComboBox->setCurrentIndex(auditorsData.at(1).indexOf(auditorData.at(0)));
                QMessageBox::information(this, trUtf8("Creando Interventor"),
                                         trUtf8("Interventor creado con éxito"),
                                         QMessageBox::Ok);
                break;
            }
        }
    }
}

void EditPersonsForm::removePerson()
{
    if (validateData()) {
        bool fkViolation;

        switch(personType) {

        case BcNames::EditUsers:

            if (!DbHandler::deleteUser(usersData.at(0).at(personsComboBox->currentIndex()),fkViolation)) {
                QMessageBox::critical(this, trUtf8("Error eliminando datos"),
                                      trUtf8("Error eliminando Usuario, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::deleteUser devolvió false al tratar de eliminar el usuario");
                break;
            } else {
                if (fkViolation) {
                    QMessageBox::warning(this, trUtf8("Error eliminando usuario"),
                                         trUtf8("El Usuario tiene inspecciones asociadas\n"
                                                "elimine estas inspecciones para poder eliminarlo\n"),
                                         QMessageBox::Ok);
                } else {
                    setDialogType();
                    QMessageBox::information(this, trUtf8("Eliminando Usuario"),
                                             trUtf8("Usuario eliminado con éxito"),
                                             QMessageBox::Ok);
                }
                break;
            }

        case BcNames::EditInspectors:

            if (!DbHandler::deleteInspector(inspectorsData.at(0).at(personsComboBox->currentIndex()),fkViolation)) {
                QMessageBox::critical(this, trUtf8("Error eliminando datos"),
                                      trUtf8("Error eliminando Inspector, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::deleteInspector devolvió false al tratar de eliminar el inspector");
                break;
            } else {
                if (fkViolation) {
                    QMessageBox::warning(this, trUtf8("Error eliminando inspector"),
                                         trUtf8("El Inspector tiene inspecciones asociadas\n"
                                                "elimine estas inspecciones para poder eliminarlo\n"),
                                         QMessageBox::Ok);
                } else {
                    setDialogType();
                    QMessageBox::information(this, trUtf8("Eliminando Inspector"),
                                             trUtf8("Inspector eliminado con éxito"),
                                             QMessageBox::Ok);
                }
                break;
            }

        case BcNames::EditDesigners:

            if (!DbHandler::deleteDesigner(designersData.at(0).at(personsComboBox->currentIndex()),fkViolation)) {
                QMessageBox::critical(this, trUtf8("Error eliminando datos"),
                                      trUtf8("Error eliminando Diseñador, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::deleteDesigner devolvió false al tratar de eliminar el diseñador");
                break;
            } else {
                if (fkViolation) {
                    QMessageBox::warning(this, trUtf8("Error eliminando diseñador"),
                                         trUtf8("El Diseñador tiene inspecciones asociadas\n"
                                                "elimine estas inspecciones para poder eliminarlo\n"),
                                         QMessageBox::Ok);
                } else {
                    setDialogType();
                    QMessageBox::information(this, trUtf8("Eliminando Diseñador"),
                                             trUtf8("Diseñador eliminado con éxito"),
                                             QMessageBox::Ok);
                }
                break;
            }

        case BcNames::EditConstructors:

            if (!DbHandler::deleteConstructor(constructorsData.at(0).at(personsComboBox->currentIndex()),fkViolation)) {
                QMessageBox::critical(this, trUtf8("Error eliminando datos"),
                                      trUtf8("Error eliminando Constructor, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::deleteConstructor devolvió false al tratar de eliminar el constructor");
                break;
            } else {
                if (fkViolation) {
                    QMessageBox::warning(this, trUtf8("Error eliminando Constructor"),
                                         trUtf8("El Constructor tiene inspecciones asociadas\n"
                                                "elimine estas inspecciones para poder eliminarlo\n"),
                                         QMessageBox::Ok);
                } else {
                    setDialogType();
                    QMessageBox::information(this, trUtf8("Eliminando Constructor"),
                                             trUtf8("Constructor eliminado con éxito"),
                                             QMessageBox::Ok);
                }
                break;
            }


        case BcNames::EditAuditors:

            if (!DbHandler::deleteAuditor(auditorsData.at(0).at(personsComboBox->currentIndex()),fkViolation)) {
                QMessageBox::critical(this, trUtf8("Error eliminando datos"),
                                      trUtf8("Error eliminando Interventor, ejecute\n"
                                             "el programa bajo consola y revise los mensajes"),
                                      QMessageBox::Cancel);
                qDebug() << trUtf8("DbHandler::deleteAuditor devolvió false al tratar de eliminar el auditor");
                break;
            } else {
                if (fkViolation) {
                    QMessageBox::warning(this, trUtf8("Error eliminando Interventor"),
                                         trUtf8("El Interventor tiene inspecciones asociadas\n"
                                                "elimine estas inspecciones para poder eliminarlo\n"),
                                         QMessageBox::Ok);
                } else {
                    setDialogType();
                    QMessageBox::information(this, trUtf8("Eliminando Interventor"),
                                             trUtf8("Interventor eliminado con éxito"),
                                             QMessageBox::Ok);
                }

            }
            break;
        }
    }
}

void EditPersonsForm::clearControls()
{
    personsComboBox->blockSignals(true);
    personsComboBox->clear();

    mpLineEdit->clear();
    mailLineEdit->clear();
    celLineEdit->clear();
    nitLineEdit->clear();

    percentageSpinBox->setValue(0);
    passwordLineEdit->clear();
    longNameLineEdit->clear();
    availibleComboBox->setCurrentIndex(0);
    chargeComboBox->setCurrentIndex(0);
    levelSpinBox->setValue(0);
    phoneLineEdit->clear();
    addressLineEdit->clear();
}

void EditPersonsForm::styleWithThrds()
{
    this->setMaximumSize(266, 226);
    nitLineEdit->setMinimumWidth(256);
    saveButton->hide();
    percentageLabel->hide();
    percentageSpinBox->hide();
    passwordLabel->hide();
    passwordLineEdit->hide();
    longNameLabel->hide();
    longNameLineEdit->hide();
    chargeLabel->hide();
    chargeComboBox->hide();
    levelLabel->hide();
    levelSpinBox->hide();
    availibleLabel->hide();
    availibleComboBox->hide();
    phoneLabel->hide();
    phoneLineEdit->hide();
    addressLabel->hide();
    addressLineEdit->hide();
}

void EditPersonsForm::styleWithStaff()
{
    //this->setMaximumSize(266, 226);
    //nitLineEdit->setMinimumWidth(256);
    saveButton->hide();
}

void EditPersonsForm::enableControls()
{
    mpLineEdit->setEnabled(true);
    mailLineEdit->setEnabled(true);
    celLineEdit->setEnabled(true);
    nitLineEdit->setEnabled(true);

    percentageSpinBox->setEnabled(true);
    passwordLineEdit->setEnabled(true);
    longNameLineEdit->setEnabled(true);
    chargeComboBox->setEnabled(true);
    levelSpinBox->setEnabled(true);
    phoneLineEdit->setEnabled(true);
    addressLineEdit->setEnabled(true);
    updateButton->setEnabled(true);
    removeButton->setEnabled(true);

}

void EditPersonsForm::disableControls()
{
    mpLineEdit->setEnabled(false);
    mailLineEdit->setEnabled(false);
    celLineEdit->setEnabled(false);
    nitLineEdit->setEnabled(false);

    percentageSpinBox->setEnabled(false);
    passwordLineEdit->setEnabled(false);
    longNameLineEdit->setEnabled(false);
    chargeComboBox->setEnabled(false);
    levelSpinBox->setEnabled(false);
    phoneLineEdit->setEnabled(false);
    addressLineEdit->setEnabled(false);
    updateButton->setEnabled(false);
    removeButton->setEnabled(false);
}

bool EditPersonsForm::validateData()
{
    if (personsComboBox->lineEdit()->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El nombre es obligatorio"),
                             QMessageBox::Ok);
        personsComboBox->setFocus();
        return false;
    }

    if (celLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El número de celular es obligatorio"),
                             QMessageBox::Ok);
        celLineEdit->setFocus();
        return false;
    }

    if (nitLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El NIT es obligatoria"),
                             QMessageBox::Ok);
        nitLineEdit->setFocus();
        return false;
    }

    switch (personType) {
    case BcNames::EditDesigners: case BcNames::EditConstructors: case BcNames::EditAuditors:

        if (mpLineEdit->text()=="") {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("La matrícula profesional es obligatoria"),
                                 QMessageBox::Ok);
            mpLineEdit->setFocus();
            return false;
        }
        break;

    case BcNames::EditInspectors:

        if (mpLineEdit->text()=="") {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("La matrícula profesional es obligatoria"),
                                 QMessageBox::Ok);
            mpLineEdit->setFocus();
            return false;
        }

        if (percentageSpinBox->value()==0) {

            if (personType==BcNames::EditInspectors)

            QMessageBox::information(this, trUtf8("Información"),
                                 trUtf8("El porcentaje del inspector quedará en cero"),
                                 QMessageBox::Ok);
        }

        if (addressLineEdit->text()=="0") {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("La dirección es obligatoria"),
                                 QMessageBox::Ok);
            percentageSpinBox->setFocus();
            return false;
        }
        break;

    case BcNames::EditUsers:

        if (longNameLineEdit->text()=="") {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("El nombre completo es obligatorio"),
                                 QMessageBox::Ok);
            longNameLineEdit->setFocus();
            return false;
        }

        if (percentageSpinBox->value()==0) {

            if (chargeComboBox->currentText()=="Comercial" )

            QMessageBox::information(this, trUtf8("Información"),
                                 trUtf8("El porcentaje del comercial quedará en cero"),
                                 QMessageBox::Ok);
        }

        if (addressLineEdit->text()=="0") {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("La dirección es obligatoria"),
                                 QMessageBox::Ok);
            percentageSpinBox->setFocus();
            return false;
        }
        break;
    }
    return true;
}
