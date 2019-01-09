#include "sostate.h"
#include "ui_sostate.h"

#include "dbhandler.h"
#include "userlib/bcnamespace.h"

#include <QSqlQuery>

SoStateForm::SoStateForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SoStateForm)
{
    ui->setupUi(this);

    connect(ui->findButton, SIGNAL(clicked()),
            this, SLOT(findServiceOrder(void)));

    connect(ui->saveObservsButton, SIGNAL(clicked()),
            this, SLOT(saveObservartions(void)));

    clearControls();
}

void SoStateForm::findServiceOrder()
{
    clearControls();
    searchString=ui->findLineEdit->text();
    QStringList soState, dictums;
    QString searchOption;

    if (ui->findByComboBox->currentIndex()==0)
        searchOption="tblTHIRDPARTIES.thrd_nit";
    else
        searchOption="tblSERVICEORDERS.so_id";

    if (DbHandler::getSoState(searchString, soState, dictums, searchOption)) {
        if (soState.size()==0) {
            QMessageBox::information(this, trUtf8("Localizando OS"),
                                     trUtf8("No se encontraron datos para: ") + ui->findLineEdit->text().toUtf8(),
                                     QMessageBox::Ok);
        } else {
            enableControls();

            ui->scopeTextEdit->setText(trUtf8("De Cotización: ")+soState.at(SoState::QScope) + "\n\n" +
                                       trUtf8("De Propuesta: ")+soState.at(SoState::PScope) + "\n\n" +
                                       trUtf8("De OS: ")+soState.at(SoState::SScope));

            ui->propCheckBox->setChecked(!soState.at(SoState::PropId).isEmpty());
            ui->propLineEdit->setText(soState.at(SoState::PropId));
            ui->propLineEdit->setEnabled(!soState.at(SoState::PropId).isEmpty());
            ui->propDateEdit->setDate(QDate::fromString(soState.at(SoState::PropDate), "yyyy-MM-dd"));
            ui->propDateEdit->setEnabled(!soState.at(SoState::PropDate).isEmpty());

            ui->soCheckBox->setChecked(!soState.at(SoState::SoId).isEmpty());
            ui->soLineEdit->setText(soState.at(SoState::SoId));
            ui->soLineEdit->setEnabled(!soState.at(SoState::SoId).isEmpty());
            ui->soDateEdit->setDate(QDate::fromString(soState.at(SoState::SoDate), "yyyy-MM-dd"));
            ui->soDateEdit->setEnabled(!soState.at(SoState::SoDate).isEmpty());

            ui->inspectorCheckBox->setChecked(!soState.at(SoState::InspName).isEmpty());
            ui->inspectorLineEdit->setText(soState.at(SoState::InspName));
            ui->inspectorLineEdit->setEnabled(!soState.at(SoState::InspName).isEmpty());
            ui->assignDateEdit->setDate(QDate::fromString(soState.at(SoState::ADate), "yyyy-MM-dd"));
            ui->assignDateEdit->setEnabled(!soState.at(SoState::ADate).isEmpty());

            ui->receivedCheckBox->setChecked(!soState.at(SoState::RDate).isEmpty());
            ui->receivedDateEdit->setDate(QDate::fromString(soState.at(SoState::RDate), "yyyy-MM-dd"));
            ui->receivedDateEdit->setEnabled(!soState.at(SoState::RDate).isEmpty());

            ui->docProccLineEdit->setText(soState.at(SoState::DocProc));
            ui->docProccCheckBox->setChecked(!soState.at(SoState::DocProc).contains("Sin Procesar"));
            ui->docProccLineEdit->setEnabled(!soState.at(SoState::DocProc).contains("Sin Procesar"));

            ui->accProccLineEdit->setText(soState.at(SoState::AccProc));
            ui->accProccCheckBox->setChecked(!soState.at(SoState::AccProc).contains("Sin Procesar"));
            ui->accProccLineEdit->setEnabled(!soState.at(SoState::AccProc).contains("Sin Procesar"));

            ui->engProccLineEdit->setText(soState.at(SoState::EngProc));
            ui->engProccCheckBox->setChecked(!soState.at(SoState::EngProc).contains("Sin Procesar"));
            ui->engProccLineEdit->setEnabled(!soState.at(SoState::EngProc).contains("Sin Procesar"));

            ui->dictumsComboBox->addItems(dictums);
            ui->dictumsCheckBox->setChecked(!dictums.isEmpty());
            ui->dictumsComboBox->setEnabled(!dictums.isEmpty());

            ui->shippedDateEdit->setDate(QDate::fromString(soState.at(SoState::SDate), "yyyy-MM-dd"));
            ui->shippedCheckBox->setChecked(!soState.at(SoState::SDate).isEmpty());
            ui->shippedDateEdit->setEnabled(!soState.at(SoState::SDate).isEmpty());

            ui->engObservCheckBox->setChecked(!soState.at(SoState::EngObserv).isEmpty());
            ui->engObservTextEdit->setText(soState.at(SoState::EngObserv));
            ui->engObservTextEdit->setEnabled(!soState.at(SoState::EngObserv).isEmpty());

            ui->admObservTextEdit->setText(soState.at(SoState::AdmObserv));

            ui->propTotValueLineEdit->setText(soState.at(SoState::PropTValue));
            ui->propTotValueLineEdit->setEnabled(!soState.at(SoState::PropTValue).isEmpty());
        }
    } else {
        QMessageBox::warning(this, trUtf8("Error"),
                             trUtf8("Ocurrió un error obteniendo el estado de la OS.\n"
                                    "Ejecute el programa bajo consola y revise los mensajes"),
                             QMessageBox::Ok);

        qDebug() << "DbHandler::getSoState devolvió false al tratar de obtener el estado de la OS";

    }
}

void SoStateForm::saveObservartions()
{
    if (!ui->soLineEdit->text().isEmpty()) {
        if (DbHandler::updateSoAdmObservations(ui->soLineEdit->text(), ui->admObservTextEdit->toPlainText()))
            QMessageBox::information(this, trUtf8("Actualizando OS"),
                                     trUtf8("Orden de servicio actualizada con éxito"),
                                     QMessageBox::Ok);
        else {
            QMessageBox::warning(this, trUtf8("Error"),
                                 trUtf8("Ocurrió un error actualizando la OS.\n"
                                        "Ejecute el programa bajo consola y revise los mensajes"),
                                 QMessageBox::Ok);
            qDebug() << "DbHandler::updateSoAdmObservations devolvió false al tratar de actualizar la OS";
        }
    } else
        QMessageBox::warning(this, trUtf8("Error"),
                             trUtf8("Solo se pueden hacer observaciones cuando \n"
                                    "existe una Orden de Servicio."),
                             QMessageBox::Ok);

}
void SoStateForm::clearControls()
{
    ui->scopeTextEdit->setEnabled(false);

    ui->propCheckBox->setEnabled(false);
    ui->propLineEdit->setEnabled(false);
    ui->propDateEdit->setEnabled(false);

    ui->soCheckBox->setEnabled(false);
    ui->soLineEdit->setEnabled(false);
    ui->soDateEdit->setEnabled(false);

    ui->inspectorLineEdit->setEnabled(false);
    ui->inspectorCheckBox->setEnabled(false);
    ui->assignDateEdit->setEnabled(false);

    ui->receivedCheckBox->setEnabled(false);
    ui->receivedDateEdit->setEnabled(false);

    ui->docProccLineEdit->setEnabled(false);
    ui->docProccCheckBox->setEnabled(false);

    ui->accProccLineEdit->setEnabled(false);
    ui->accProccCheckBox->setEnabled(false);

    ui->engProccLineEdit->setEnabled(false);
    ui->engProccCheckBox->setEnabled(false);

    ui->dictumsComboBox->setEnabled(false);
    ui->dictumsCheckBox->setEnabled(false);

    ui->shippedDateEdit->setEnabled(false);
    ui->shippedCheckBox->setEnabled(false);

    ui->engObservCheckBox->setEnabled(false);
    ui->engObservTextEdit->setEnabled(false);

    ui->admObservTextEdit->setEnabled(false);

    ui->propTotValueLineEdit->setEnabled(false);

// ---------------------------------------
    ui->propCheckBox->setChecked(false);
    ui->propLineEdit->clear();

    ui->soCheckBox->setChecked(false);
    ui->soLineEdit->clear();

    ui->scopeTextEdit->clear();
    ui->inspectorLineEdit->clear();
    ui->inspectorCheckBox->setChecked(false);

    ui->receivedCheckBox->setChecked(false);

    ui->docProccLineEdit->clear();
    ui->docProccCheckBox->setChecked(false);

    ui->accProccLineEdit->clear();
    ui->accProccCheckBox->setChecked(false);

    ui->engProccLineEdit->clear();
    ui->engProccCheckBox->setChecked(false);

    ui->dictumsComboBox->clear();
    ui->dictumsCheckBox->setChecked(false);

    ui->shippedCheckBox->setChecked(false);

    ui->engObservTextEdit->clear();
    ui->engObservCheckBox->setChecked(false);

    ui->admObservTextEdit->clear();

    ui->propTotValueLineEdit->clear();

    ui->saveObservsButton->setEnabled(false);
}

void SoStateForm::enableControls()
{
    ui->propCheckBox->setEnabled(true);
    ui->soCheckBox->setEnabled(true);
    ui->scopeTextEdit->setEnabled(true);
    ui->inspectorCheckBox->setEnabled(true);
    ui->receivedCheckBox->setEnabled(true);
    ui->docProccCheckBox->setEnabled(true);
    ui->accProccCheckBox->setEnabled(true);
    ui->engProccCheckBox->setEnabled(true);
    ui->dictumsCheckBox->setEnabled(true);
    ui->shippedCheckBox->setEnabled(true);
    ui->admObservTextEdit->setEnabled(true);
    ui->saveObservsButton->setEnabled(true);
}


SoStateForm::~SoStateForm()
{
    delete ui;
}
