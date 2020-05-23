#include "sotracking.h"
#include "dbhandler.h"

SoTrackingForm::SoTrackingForm(QDialog *parent, QString soId)
    : QDialog(parent)
{
    setupUi(this);
    soNumberLineEdit->setText(soId);

    // contecto el cambio de departamento con el cambio de ciudad
    connect(shippingStateComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(setShippingCity(int)));

    // conectar el botón de guardar con insertar o actualizar
    connect(saveButton, SIGNAL(clicked()),
            this, SLOT(insertOrUpdateShipping(void)));

    if (DbHandler::getStates(statesData)) {
        shippingStateComboBox->addItems(statesData.at(2));
    } else {
        shippingStateComboBox->addItem("Sin Datos");
    }

    if (DbHandler::getCities(statesData.at(0).at(0), citiesData)) {
        shippingCityComboBox->addItems(citiesData.at(2));
    } else {
        shippingCityComboBox->addItem("Sin Datos");
    }

    if (DbHandler::getUsers(usersData)) {
        receiverNameComboBox->addItems(usersData.at(3));
        receiverNameComboBox->addItem("No Recibido");
        shipperNameComboBox->addItems(usersData.at(3));
        shipperNameComboBox->addItem("No Enviado");
    }
    else {
        receiverNameComboBox->addItem("Sin Datos");
        shipperNameComboBox->addItem("Sin Datos");
    }

    if(DbHandler::getSoTracking(soId, soTrackingData)) {
        receiptDateEdit->setDate(QDate::fromString(soTrackingData.at(0), "yyyy-MM-dd"));
        receiverNameComboBox->setCurrentIndex(receiverNameComboBox->findText(soTrackingData.at(1)));
        shippingDateEdit->setDate(QDate::fromString(soTrackingData.at(2), "yyyy-MM-dd"));
        shipperNameComboBox->setCurrentIndex(shipperNameComboBox->findText(soTrackingData.at(3)));
        shippingNameLineEdit->setText(soTrackingData.at(4));
        shippingCompany->setText(soTrackingData.at(5));
        guideNumberLineEdit->setText(soTrackingData.at(6));
        observationsTextEdit->setHtml(soTrackingData.at(7));
        shippingStateComboBox->setCurrentIndex(shippingStateComboBox->findText(soTrackingData.at(8)));
        shippingCityComboBox->setCurrentIndex(shippingCityComboBox->findText(soTrackingData.at(9)));
        recordExist=true;
    }
    else {
        receiptDateEdit->setDate(QDate::currentDate());
        receiverNameComboBox->setCurrentIndex(receiverNameComboBox->count()-1); // Seleccionar el último
        shippingDateEdit->setDate(QDate::currentDate());
        shipperNameComboBox->setCurrentIndex(shipperNameComboBox->count()-1);
        shippingNameLineEdit->setText("");
        shippingCompany->setText("");
        guideNumberLineEdit->setText("");
        observationsTextEdit->setHtml("");
        shippingStateComboBox->setCurrentIndex(shippingStateComboBox->count()-1);
        shippingCityComboBox->setCurrentIndex(shippingCityComboBox->count()-1);
        recordExist=false;
    }
}

void SoTrackingForm::setShippingCity(int index)
{
    shippingCityComboBox->clear();
    if (DbHandler::getCities(statesData.at(0).at(index), citiesData))
        shippingCityComboBox->addItems(citiesData.at(2));
    else
        shippingCityComboBox->addItem("Sin Datos");
}

void SoTrackingForm::insertOrUpdateShipping(void)
{
    soTrackingData.clear();

    soTrackingData.append(soNumberLineEdit->text());
    soTrackingData.append(receiptDateEdit->date().toString("yyyy-MM-dd"));
    soTrackingData.append(receiverNameComboBox->currentText());
    soTrackingData.append(shippingDateEdit->date().toString("yyyy-MM-dd"));
    soTrackingData.append(shipperNameComboBox->currentText());
    soTrackingData.append(shippingNameLineEdit->text());
    soTrackingData.append(shippingCompany->text());
    soTrackingData.append(guideNumberLineEdit->text());
    soTrackingData.append(observationsTextEdit->toPlainText());
    soTrackingData.append(citiesData.at(0).at(shippingCityComboBox->currentIndex()));

    if (recordExist) {
        if (DbHandler::updateSoTracking(soTrackingData))
            QMessageBox::information(this, trUtf8("Actualización"),
                                     trUtf8("Datos actualizados con éxito\n"
                                            "Presione ESC para Salir"),
                                     QMessageBox::Ok);
    } else
        if (DbHandler::insertSoTracking(soTrackingData))
            QMessageBox::information(this, trUtf8("Inserción"),
                                     trUtf8("Nuevos Datos guardados con éxito\n"
                                            "Presione ESC para Salir"),
                                     QMessageBox::Ok);
}

//SoTrackingForm::~SoTrackingForm()
//{
//    delete this;
//}
