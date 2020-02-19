#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

#include "accounting.h"
#include "dbhandler.h"
#include "userlib/filterserviceorders.h"
#include "userlib/filteraccountinginfo.h"
#include "userlib/bcnamespace.h"
#include "userlib/outsideactions.h"

AccountingForm::AccountingForm(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    connect(findButton, SIGNAL(clicked()),
            this, SLOT(findServiceOrder()));

    connect(billedButton, SIGNAL(clicked()),
            this, SLOT(billedServiceOrder()));

    connect(listButton, SIGNAL(clicked()),
            this, SLOT(listServiceOrders()));

    connect(accountingListButton, SIGNAL(clicked()),
            this, SLOT(listAccountingInfo()));

    connect(payThrdButton, SIGNAL(clicked()),
            this, SLOT(payThrd()));

    connect(payUserButton, SIGNAL(clicked()),
            this, SLOT(payUser()));

    connect(payInspectorButton, SIGNAL(clicked()),
            this, SLOT(payInspector()));

    connect(printSoButton, SIGNAL(clicked()),
            this, SLOT(printServiceOrder()));

    clearSoControls();
    billedButton->setEnabled(false);

    if (!DbHandler::getProcesses(processesData))
        processesData.append(QStringList("Sin Datos"));

    if (!DbHandler::getUsers(usersData))
        usersData.append(QStringList("Sin Datos"));

    if (!DbHandler::getInspectors(inspectorsData, "Todos"))
        inspectorsData.append(QStringList("Sin Datos"));

    // Obtengo los distintos folios o AZ
    if (!DbHandler::getRecords(recordsData))
        recordsData.append(QStringList("Sin Datos"));
    for (int i=0; i<recordsData.at(1).size();i++) {
        QListWidgetItem *item = new QListWidgetItem;
        item->setData( Qt::DisplayRole, recordsData.at(1).at(i));
        item->setData( Qt::CheckStateRole, Qt::Unchecked);
        recordFoilListWidget->addItem( item );
    }



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

    // Consulto las OS's Sin Procesar

    checkAccountingState();

    QTimer *timer = new QTimer(this);
         connect(timer, SIGNAL(timeout()), this, SLOT(checkAccountingState()));
         timer->start(OutsideActions::readUpdateTimeConf());
}

// NOTE: Encuentra por id de orden de servicio
void AccountingForm::findServiceOrder()
{
    // La función devuelve falso al no encontrar o verdadero el encontrar
    if (DbHandler::getServiceOrders(findLineEdit->text(), sosData, "so_id")) {
        // si encuentra entonces se obteiene la propuesta, la cotización y los pagos.
        DbHandler::getProposals(sosData.at(Sos::propId).at(0), propsData, "prop_id");
        DbHandler::getQuotations(thrdData.at(Thrds::Nit).at(0), quotsData, "thrd_nit");// 13 es thrd_nit

        thrdPaysData.clear();   // Nit del cliente                  // Número OS                  // Datos
        DbHandler::getThrdPays(thrdData.at(Thrds::Nit).at(0), sosData.at(Sos::Id).at(0), thrdPaysData);

        userPaysData.clear();  // Nit del comercial
        DbHandler::getUserPays(usersData.at(Users::Nit).at(usersData.at(Users::LName).indexOf(propsData.at(Props::LName).at(0))),
                               // Número OS             // Datos
                               sosData.at(Sos::Id).at(0), userPaysData);

        inspectorPaysData.clear();  // Nit del inspector
        DbHandler::getInspectorPays(inspectorsData.at(Insp::Nit).at(inspectorsData.at(Insp::Name).indexOf(sosData.at(Sos::InspName).at(0))),
                                    // Número OS             // Datos
                                    sosData.at(Sos::Id).at(0), inspectorPaysData);
        DbHandler::getProcesses(quotsData.at(Quots::Id).at(0), procsIds);
        clearSoControls();
        fillSoData();

        // hay que comprobar si ya está facturada o pagada para desabilitar el botón
        if (soStateLineEdit->text()=="Facturada" || soStateLineEdit->text()=="Pagada")
            billedButton->setEnabled(false);
        else
            billedButton->setEnabled(true);

        // hay que comprobar si está totalmente pagada para desabilitar el botón.
        if (thrdBalanceSpinBox->value()==0 || soStateLineEdit->text()=="Sin Procesar")
            payThrdButton->setEnabled(false);
        else
            payThrdButton->setEnabled(true);

        if (inspectorBalanceSpinBox->value()==0 || soStateLineEdit->text()=="Sin Procesar")
            payInspectorButton->setEnabled(false);
        else
            payInspectorButton->setEnabled(true);

        if (userBalanceSpinBox->value()==0 || soStateLineEdit->text()=="Sin Procesar")
            payUserButton->setEnabled(false);
        else
            payUserButton->setEnabled(true);

        renderServiceOrder();


    } else {
        QMessageBox::warning(this, "Sin Datos",
                             "No se encontraron datos con: " + findLineEdit->text().toUtf8(),
                             QMessageBox::Cancel);
        billedButton->setEnabled(false);
        payThrdButton->setEnabled(false);
        payUserButton->setEnabled(false);
        payInspectorButton->setEnabled(false);
    }
}


// NOTE: Llenado de datos de orden de servicio
void AccountingForm::fillSoData()
{
    soIdLineEdit->setText(sosData.at(Sos::Id).at(0));
    soDateEdit->setDate(QDate::fromString(sosData.at(Sos::Date).at(0), "yyyy-MM-dd"));
    soStateLineEdit->setText(sosData.at(Sos::AccProc).at(0));

    // Deschequear primero para luego seleccionar las AZ.
    for (int i=0; i<recordFoilListWidget->count(); i++)
        recordFoilListWidget->item(i)->setCheckState(Qt::Unchecked);

    // Seleccion de los checkbox que corresponden a las AZ usadas
    QStringList recordsIds;
    DbHandler::getSoRecords(sosData.at(Sos::Id).at(0), recordsIds);
    int index;

    for (int i=0; i<recordsIds.size();i++) {
        index=recordsData.at(0).indexOf(recordsIds.at(i));
        recordFoilListWidget->item(index)->setCheckState(Qt::Checked);
    }

    folderStateLineEdit->setText(sosData.at(Sos::DocProc).at(0));
    propIdLineEdit->setText(propsData.at(Props::Id).at(0));

    soValues.clear();
    DbHandler::getSoValues(sosData.at(Sos::Id).at(0), soValues);

    userNameLineEdit->setText(propsData.at(Props::LName).at(0));
    userValueSpinBox->setValue(soValues.at(SoValue::User).toInt());
    inspectorNameLineEdit->setText(sosData.at(Sos::InspName).at(0));
    inspectorValueSpinBox->setValue(soValues.at(SoValue::Insp).toInt());

    billNumberLineEdit->setText(sosData.at(Sos::BillNumb).at(0));
    approvMethodLineEdit->setText(propsData.at(Props::Aprov).at(0));

    propValueModel->setItem(0,1, new QStandardItem(propsData.at(Props::Value).at(0)));
    propValueModel->setItem(1,1, new QStandardItem(propsData.at(Props::Iva).at(0)));
    propValueModel->setItem(2,1, new QStandardItem(propsData.at(Props::Viat).at(0)));
    propValueModel->setItem(3,1, new QStandardItem(propsData.at(Props::TotVal).at(0)));

    // Después de editarlos hay que ponerlos no editables
    propValueModel->item(0,1)->setFlags(propValueModel->item(0,1)->flags() & ~Qt::ItemIsEditable);
    propValueModel->item(1,1)->setFlags(propValueModel->item(1,1)->flags() & ~Qt::ItemIsEditable);
    propValueModel->item(2,1)->setFlags(propValueModel->item(2,1)->flags() & ~Qt::ItemIsEditable);
    propValueModel->item(3,1)->setFlags(propValueModel->item(3,1)->flags() & ~Qt::ItemIsEditable);

    // Calcular los saldos restando a los valores de la OS, los valores de movimientos a favor
    // del tercero, del comercial y del inspector.

    thrdBalanceSpinBox->setValue(propsData.at(Props::Value).at(0).toInt() - thrdPaysData.at(1).toInt());
    userBalanceSpinBox->setValue(soValues.at(SoValue::User).toInt() - userPaysData.at(1).toInt());
    inspectorBalanceSpinBox->setValue(soValues.at(SoValue::Insp).toInt() - inspectorPaysData.at(1).toInt());


}

// NOTE: Marca como facturada la orden de servicio
void AccountingForm::billedServiceOrder()
{
    // Pido el dato por inputdialog, si no lo intruducen se hace nada
    bool ok;
    QString billNumber = QInputDialog::getText(this, trUtf8("Numero de Factura"),
                                               trUtf8("Ingrese el Numero de la factura"), QLineEdit::Normal,
                                               "Sin Factura", &ok);
    if (ok && !billNumber.isEmpty()) {
        billNumberLineEdit->setText(billNumber);
                if (DbHandler::updateSoAccountingState(sosData.at(Sos::Id).at(0), "Facturada", billNumberLineEdit->text())) {
            QMessageBox::information(this, trUtf8("Actualización"),
                                     trUtf8("Orden de Servicio \n"
                                            "Facturada con éxito"),
                                     QMessageBox::Ok);
            findLineEdit->setText(sosData.at(Sos::Id).at(0));
            findServiceOrder();
            checkAccountingState();

        }
        else {
            qDebug()<< trUtf8("updateSoAccountingState devolvió false al intentar actualizar la OS");
            findLineEdit->setFocus();

        }
    } else
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El numero de la factura es obligatorio"),
                             QMessageBox::Ok);
}

// NOTE: Realizar pagos a la orden de servicio o tercero
void AccountingForm::payThrd()
{
    if (validateThrdPayFields()) {
        // Antes de hacer el pago se debe verificar que la cantidad no supere el saldo.
        if (thrdPayValueSpinBox->value() <= thrdBalanceSpinBox->value()) {
            QStringList payThrdData;
            payThrdData.append(thrdDateTimeEdit->dateTime().toString("yyyy-MM-dd  hh:mm:ss")); // fecha y hora
            payThrdData.append("PAGO FACTURA");
            payThrdData.append(sosData.at(Sos::Id).at(0)); // so_id
            payThrdData.append(thrdTicketLineEdit->text().toUpper()); // documment
            //payThrdData.append(propsData.at(Props::thrdName).at(0)); // thrd_name
            //payThrdData.append(propsData.at(Props::thrdNit).at(0)); // thrd_nit
            payThrdData.append(QString::number(thrdPayValueSpinBox->value())); // valor
            payThrdData.append(thrdObservLineEdit->text()); // observations

            if (!DbHandler::insertThrdPay(payThrdData)) {
                QMessageBox::critical(this, trUtf8("Error Pagando Factura"),
                                      trUtf8("No se pudieron insertar los datos de pago\n"
                                             "Revise los mensajes de consola"),
                                      QMessageBox::Cancel);
            } else {
                // Vuelvo a hacer la búsqueda para actualizar valores. Me aseguro de tener la OS
                // en el campo de búsqueda.
                findLineEdit->setText(sosData.at(Sos::Id).at(0));
                findServiceOrder();
                // Calcular el saldos restando a el valores de la OS, al valor de movimientos a favor del tercero.

                int balance=propsData.at(Props::Value).at(0).toInt() - thrdPaysData.at(1).toInt();
                thrdBalanceSpinBox->setValue(balance);
                if (balance==0) {
                    DbHandler::updateSoAccountingState(sosData.at(Sos::Id).at(0), "Pagada", billNumberLineEdit->text());
                    QMessageBox::information(this, trUtf8("Pago Realizado"),
                                             trUtf8("Factura en saldo cero."),
                                             QMessageBox::Ok);
                    payThrdButton->setEnabled(false);
                    soStateLineEdit->setText("PAGADA");
                }
                else {
                    DbHandler::updateSoAccountingState(sosData.at(Sos::Id).at(0), "Abonada", billNumberLineEdit->text());
                    QMessageBox::information(this, trUtf8("Abono Realizado"),
                                             trUtf8("Abono a factura\n"
                                                    "realizado con éxito"),
                                             QMessageBox::Ok);
                    soStateLineEdit->setText("ABONADA");
                }

            }
        } else {
            QMessageBox::critical(this, trUtf8("Valor Mayor que Saldo"),
                                  trUtf8("El valor abonado es mayor al saldo\n"
                                         "Se ajustará la cantidad"),
                                  QMessageBox::Cancel);
            thrdPayValueSpinBox->setValue(thrdBalanceSpinBox->value());
        }
    }

}




// NOTE: Realizar pagos a Inspectores
void AccountingForm::payInspector()
{
    if (validateInspectorPayFields()) {
        // Antes de hacer el pago se debe verificar que la cantidad no supere el saldo.
        if (inspectorPayValueSpinBox->value() <= inspectorBalanceSpinBox->value()) {
            QStringList payInspectorData;
            payInspectorData.append(inspectorDateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss")); // fecha
            payInspectorData.append("PAGO INSPECTOR");
            payInspectorData.append(sosData.at(Sos::Id).at(0)); // so_id
            payInspectorData.append(inspectorTicketLineEdit->text().toUpper()); // documment
            payInspectorData.append(sosData.at(Sos::InspName).at(0)); // inspector_name
            payInspectorData.append(inspectorsData.at(Insp::Nit).at(inspectorsData.at(Insp::Name).indexOf(sosData.at(Sos::InspName).at(0)))); // inspector_nit
            payInspectorData.append(QString::number(inspectorPayValueSpinBox->value())); // inspector_value
            payInspectorData.append(inspectorObservLineEdit->text()); // observations

            if (!DbHandler::insertInspectorPay(payInspectorData)) {
                QMessageBox::critical(this, trUtf8("Error Pagando Inspector"),
                                      trUtf8("No se pudieron insertar los datos de pago\n"
                                             "Revise los mensajes de consola"),
                                      QMessageBox::Cancel);
            } else {
                // Esta búsqueda se repite para actualizar los campos
                // Hay que asegurarse que findLineEdit contenga la os que esetamos abonando
                findLineEdit->setText(sosData.at(Sos::Id).at(0));
                findServiceOrder();

                // Calcular el saldos restando al valor del inspector en la OS, el valor de movimientos a favor del inspector.
                int balance=soValues.at(SoValue::Insp).toInt() - inspectorPaysData.at(1).toInt();
                inspectorBalanceSpinBox->setValue(balance);
                if (balance==0) {
                    QMessageBox::information(this, trUtf8("Pago Realizado"),
                                             trUtf8("Inspector en saldo cero."),
                                             QMessageBox::Ok);
                    payInspectorButton->setEnabled(false);
                }
                else
                    QMessageBox::information(this, trUtf8("Abono Realizado"),
                                             trUtf8("Abono a Inspector \n"
                                                    "Realizado con éxito"),
                                             QMessageBox::Ok);
            }
        } else {
            QMessageBox::critical(this, trUtf8("Valor Mayor que Saldo"),
                                  trUtf8("El valor abonado es mayor al saldo\n"
                                         "Se ajustará la cantidad"),
                                  QMessageBox::Cancel);
            inspectorPayValueSpinBox->setValue(inspectorBalanceSpinBox->value());
        }
    }

}

// NOTE: Realizar pagos a usuarios o vendendores
void AccountingForm::payUser()
{
    if (validateUserPayFields()) {
        // Antes de hacer el pago se debe verificar que la cantidad no supere el saldo.
        if (userPayValueSpinBox->value() <= userBalanceSpinBox->value()) {
            QStringList payUserData;
            payUserData.append(userDateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss")); // fecha y hora
            payUserData.append("PAGO COMERCIAL");
            payUserData.append(sosData.at(Sos::Id).at(0)); // so_id
            payUserData.append(userTicketLineEdit->text().toUpper()); // documment
            payUserData.append(propsData.at(Props::LName).at(0)); // user_name
            payUserData.append(usersData.at(Users::Nit).at(usersData.at(Users::LName).indexOf(propsData.at(Props::LName).at(0)))); // user_nit
            payUserData.append(QString::number(userPayValueSpinBox->value())); // user_value
            payUserData.append(userObservLineEdit->text()); // observations

            if (!DbHandler::insertUserPay(payUserData)) {
                QMessageBox::critical(this, trUtf8("Error Pagando Usuario"),
                                      trUtf8("No se pudieron insertar los datos de pago\n"
                                             "Revise los mensajes de consola"),
                                      QMessageBox::Cancel);
            } else {
                // Esta búsqueda se repite para actualizar los campos
                // Hay que asegurarse que findLineEdit contenga la os que esetamos abonando
                findLineEdit->setText(sosData.at(Sos::Id).at(0));
                findServiceOrder();

                // Calcular el saldos restando al valor del comercial en la OS, el valor de movimientos a favor del comercial.
                int balance=soValues.at(SoValue::User).toInt() - userPaysData.at(1).toInt();
                userBalanceSpinBox->setValue(balance);
                if (balance==0) {
                    QMessageBox::information(this, trUtf8("Pago Realizado"),
                                             trUtf8("Comercial en saldo cero."),
                                             QMessageBox::Ok);
                    payUserButton->setEnabled(false);
                }
                else
                    QMessageBox::information(this, trUtf8("Abono Realizado"),
                                             trUtf8("Abono a Comercial \n"
                                                    "Realizado con éxito"),
                                             QMessageBox::Ok);

            }
        } else {
            QMessageBox::critical(this, trUtf8("Valor Mayor que Saldo"),
                                  trUtf8("El valor abonado es mayor al saldo\n"
                                         "Se ajustará la cantidad"),
                                  QMessageBox::Cancel);
            userPayValueSpinBox->setValue(userBalanceSpinBox->value());
        }
    }

}

// NOTE: Validar campos de tercero
bool AccountingForm::validateThrdPayFields()
{
    if (thrdPayValueSpinBox->value()==0) {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("No se puede realizar abono de cero pesos"),
                             QMessageBox::Ok);
        thrdPayValueSpinBox->setFocus();
        return false;
    }

    if (thrdTicketLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("Debe escribir un número de comprobante"),
                             QMessageBox::Ok);
        thrdTicketLineEdit->setFocus();
        return false;
    }

    return true;
}

// NOTE: Validar campos de tercero
bool AccountingForm::validateInspectorPayFields()
{

    if (inspectorPayValueSpinBox->value()==0) {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("No se puede realizar abono de cero pesos"),
                             QMessageBox::Ok);
        inspectorPayValueSpinBox->setFocus();
        return false;
    }

    if (inspectorTicketLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("Debe escribir un número de comprobante"),
                             QMessageBox::Ok);
        inspectorTicketLineEdit->setFocus();
        return false;
    }

    return true;
}

// NOTE: Validar campos de tercero
bool AccountingForm::validateUserPayFields()
{

    if (userPayValueSpinBox->value()==0) {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("No se puede realizar abono de cero pesos"),
                             QMessageBox::Ok);
        userPayValueSpinBox->setFocus();
        return false;
    }

    if (userTicketLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("Debe escribir un número de comprobante"),
                             QMessageBox::Ok);
        userTicketLineEdit->setFocus();
        return false;
    }


    return true;
}

// NOTE: Limpiar controles de orden de servicio
void AccountingForm::clearSoControls()
{
    soDateEdit->setDate(QDate::currentDate());
    soIdLineEdit->clear();
    // Deschequear primero para luego seleccionar las AZ.
    for (int i=0; i<recordFoilListWidget->count(); i++)
        recordFoilListWidget->item(i)->setCheckState(Qt::Unchecked);
    soOutWebView->setHtml("");
    soStateLineEdit->clear();
    folderStateLineEdit->clear();

    payThrdButton->setEnabled(false);
    thrdDateTimeEdit->setDateTime(QDateTime::currentDateTime());
    thrdPayValueSpinBox->setValue(0);
    thrdBalanceSpinBox->setValue(0);
    thrdTicketLineEdit->clear();
    thrdObservLineEdit->setText("");

    payUserButton->setEnabled(false);
    userDateTimeEdit->setDateTime(QDateTime::currentDateTime());
    userPayValueSpinBox->setValue(0);
    userBalanceSpinBox->setValue(0);
    userTicketLineEdit->clear();
    userObservLineEdit->setText("");

    payInspectorButton->setEnabled(false);
    inspectorDateTimeEdit->setDateTime(QDateTime::currentDateTime());
    inspectorPayValueSpinBox->setValue(0);
    inspectorBalanceSpinBox->setValue(0);
    inspectorTicketLineEdit->clear();
    inspectorObservLineEdit->setText("");

    billNumberLineEdit->clear();
    approvMethodLineEdit->clear();
}

// NOTE: Lista las ordenes de servicio
void AccountingForm::listServiceOrders()
{
    FilterServiceOrdersForm filterForm(this);
    //filterForm.setParent(this);
    filterForm.exec();
    if (!filterForm.so_id.isEmpty()) {
        findLineEdit->setText(filterForm.so_id);
        findButton->click();
    }
}

// NOTE: Lista la informacion de contabilidad
void AccountingForm::listAccountingInfo()
{
    FilterAccountingInfoForm filterForm(this);
    //filterForm.setParent(this);
    filterForm.exec();
    if (!filterForm.so_id.isEmpty()) {
        findLineEdit->setText(filterForm.so_id);
        findButton->click();
    }
}

// NOTE: Revisa si hay OS's con documentos incompletos o sin revisar
void AccountingForm::checkAccountingState()
{
    if (DbHandler::getServiceOrders("Sin Procesar", sosData2, "so_acc_processed"))
        noProcessedLcdNumber->display(sosData2.at(0).size());
    else {
        noProcessedLcdNumber->display(0);
       // qDebug()<< trUtf8("getServiceOrder devolvió false al intentar obtener OS's Sin Procesar");
    }
}

// NOTE: Renderizar la orden de servicio en el QWebView
void AccountingForm::renderServiceOrder()
{
    QString currDir;
    currDir=QDir::currentPath();
#ifdef Q_OS_LINUX
    currDir="file://" + QDir::currentPath();
#endif

    QString fileName = QDir::currentPath() + "/templates/so_template.html";
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, trUtf8("Error Abriendo Plantilla"),
                             trUtf8("No se puedo abrir '%1'").arg(fileName));
    } else {
        QStringList selectedProcs(processesData.at(1)); // Creo una copia de los nombre de procesos
        for (int i=0;i<selectedProcs.size();i++)
            selectedProcs.replace(i, QString("")); // Primero los borro todos

        int index;
        for (int i=0; i<procsIds.size();i++) {
            index=processesData.at(0).indexOf(procsIds.at(i));
            selectedProcs.replace(i, processesData.at(1).at(index));
        }


        // Primero se carga el archivo a un stream de texto
        QTextStream stream(&file);
        QString htmlString;
        htmlString = stream.readAll();

        htmlString.replace("_logo", currDir + "/templates/logorig.png");
        htmlString.replace("_fecha", QDate::fromString(sosData.at(Sos::Date).at(0), "yyyy-MM-dd").toString("dd 'de' MMMM 'de' yyyy"));
        htmlString.replace("_osNumero", sosData.at(Sos::Id).at(0));
        htmlString.replace("_propNumero", propsData.at(Props::Id).at(0));
        htmlString.replace("_nombreTercero", thrdData.at(Thrds::LRep));
        htmlString.replace("_nit", thrdData.at(Thrds::Nit));
        htmlString.replace("_direccion", thrdData.at(Thrds::Addrs));
        htmlString.replace("_celular", thrdData.at(Thrds::Cel));
        htmlString.replace("_ciudadTercero", thrdData.at(Thrds::City));
        htmlString.replace("_departTercero", thrdData.at(Thrds::State));
        htmlString.replace("_nombreContacto", quotsData.at(Quots::Ctact).at(0));
        htmlString.replace("_nombreInstal", quotsData.at(Quots::Name).at(0));
        htmlString.replace("_ciudadInstal", quotsData.at(Quots::City).at(0));
        htmlString.replace("_departInstal", quotsData.at(Quots::State).at(0));
        htmlString.replace("_ubicacionInst", quotsData.at(Quots::Addrs).at(0));
        htmlString.replace("_alcance", sosData.at(Sos::Scope).at(0));
        htmlString.replace("_tiposProceso", selectedProcs.at(0)
                           +" "+ selectedProcs.at(1)
                           +" "+ selectedProcs.at(2)
                           +" "+ selectedProcs.at(3)
                           +" "+ selectedProcs.at(4)
                           +" "+ selectedProcs.at(5));
                htmlString.replace("_tipoUso", quotsData.at(Quots::Use).at(0));
        htmlString.replace("_observ", sosData.at(Sos::Observ).at(0));
        htmlString.replace("_nombreInspect", sosData.at(Sos::InspName).at(0));
        htmlString.replace("_fInsp", QDate::fromString(sosData.at(Sos::AssignD).at(0), "yyyy-MM-dd").toString("dd 'de' MMMM 'de' yyyy"));

        soOutWebView->setHtml(htmlString);
        soOutWebView->setZoomFactor(0.755);
        soOutWebView->setLocale(QLocale("utf8"));
    }
}

// NOTE: Imprimir orden de servicio
void AccountingForm::printServiceOrder()
{
    if (soIdLineEdit->text()!="") {
        QPrinter printer;
        printer.setDocName(trUtf8("OS - %1 - %2").arg(sosData.at(0).at(0)).arg(propsData.at(14).at(0)));
        printer.setPaperSize(QPrinter::A4);
        printer.setPageMargins(10,10,10,10,QPrinter::Millimeter);

#ifdef Q_OS_LINUX
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(QDir::homePath() +"/"+ printer.docName() + ".pdf");
#endif

        QPrintDialog *dialog = new QPrintDialog(&printer, this);
        dialog->setWindowTitle(trUtf8("Imprimir Orden de Servicio"));
        if ( dialog->exec() == QDialog::Accepted) {
            soOutWebView->setZoomFactor(1);
            //soOutWebView->page()->print(&printer, true);
            soOutWebView->setZoomFactor(0.73);
        }
    } else
        QMessageBox::warning(this, trUtf8("Imprimir Orden de Servicio"),
                             trUtf8("No hay Orden de Servicio para imprimir"));
}
