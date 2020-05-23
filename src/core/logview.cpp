#include "logview.h"
#include "ui_logview.h"
#include "dbhandler.h"

#include <QSqlQueryModel>
#include <QSqlQuery>

LogViewForm::LogViewForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogViewForm)
{
    ui->setupUi(this);

    connect(ui->filterButton, SIGNAL(clicked()),
            this, SLOT(filterData()));

    // Se obtienen los datos y se agrega Todos junto con el comodín para
    // escoger filtrado de Todos, se hace aquí para no hacerlo en la DB
    if (!DbHandler::getEventType(eventTypeData))
        ui->eventTypeComboBox->addItem("Sin Datos");
    else {
        eventId=eventTypeData.at(0);
        eventName=eventTypeData.at(1);
        eventId.prepend("1");
        eventName.prepend("Todos");
        ui->eventTypeComboBox->addItems(eventName);
    }

    if (!DbHandler::getUsers(usersData))
        ui->userComboBox->addItem("Sin Datos");
    else {
        userName=usersData.at(1);
        userName.prepend("%");
        ui->userComboBox->addItem("Todos");
        ui->userComboBox->addItems(usersData.at(1));
    }

    idType.append("");
    idType.append("quot_id");
    idType.append("prop_id");
    idType.append("so_id");
    idType.append("inspection_id");
    idType.append("dictum_id");
    idType.append("subdictum_id");

    idTypeName.append("Todos");
    idTypeName.append(trUtf8("Cotización"));
    idTypeName.append("Propuesta");
    idTypeName.append("Orden de Servicio");
    idTypeName.append(trUtf8("Inspección"));
    idTypeName.append("Dictamen");
    idTypeName.append("Consecutivo");

    ui->byIdComboBox->addItems(idTypeName);

    ui->startDateTimeEdit->setDateTime(QDateTime::currentDateTime().addDays(-1));
    ui->endDateTimeEdit->setDateTime(QDateTime::currentDateTime());

}

void LogViewForm::filterData()
{
    // Si se selecciona Todos, debe usarse >= para los enterios
    QString argument1, argument2;

    if (ui->eventTypeComboBox->currentIndex()==0)
        argument1=">=";
    else
        argument1="=";

    if (ui->byIdComboBox->currentIndex()==0)
        argument2=""; // Vacío para no incluir algún id en la consulta
    else
        // Se llena el tipo de id que se quiere con .arg()
        argument2=QString(" AND %1=:id").arg(idType.at(ui->byIdComboBox->currentIndex()));

    // Se prepara la consulta para el modelo.
    QSqlQuery modelQuery;
    modelQuery.prepare(QString("SELECT log_date_time, log_user_name, log_detail, quot_id, prop_id, "
                               "so_id, inspection_id, dictum_id, subdictum_id "
                               "FROM tblEVENTS "
                               "WHERE log_date_time >= :start_date AND log_date_time <= :end_date "
                               "AND event_type_id %1 :event_type_id "
                               "AND log_user_name LIKE :log_user_name"
                               "%2").arg(argument1).arg(argument2));

    modelQuery.bindValue(":start_date", ui->startDateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"));
    modelQuery.bindValue(":end_date", ui->endDateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"));
    modelQuery.bindValue(":event_type_id", eventId.at(ui->eventTypeComboBox->currentIndex()).toInt());
    modelQuery.bindValue(":log_user_name", userName.at(ui->userComboBox->currentIndex()));
    if (ui->byIdComboBox->currentIndex()!=0) // Si no es todos, debo atar el :id
        modelQuery.bindValue(":id", ui->idLineEdit->text().toInt());

    if (!modelQuery.exec())
        qDebug() << "Error en modelQuery: " + modelQuery.lastError().text();

    else {
        QSqlQueryModel *logDataModel= new QSqlQueryModel;
        logDataModel->setQuery(modelQuery); // Asigno la consulta al modelo

        logDataModel->setHeaderData(0, Qt::Horizontal, trUtf8("Fecha y Hora"));
        logDataModel->setHeaderData(1, Qt::Horizontal, trUtf8("Usuario"));
        logDataModel->setHeaderData(2, Qt::Horizontal, trUtf8("Detalles"));
        logDataModel->setHeaderData(3, Qt::Horizontal, trUtf8("Cotización"));
        logDataModel->setHeaderData(4, Qt::Horizontal, trUtf8("Propuesta"));
        logDataModel->setHeaderData(5, Qt::Horizontal, trUtf8("OS"));
        logDataModel->setHeaderData(6, Qt::Horizontal, trUtf8("Inspección"));
        logDataModel->setHeaderData(7, Qt::Horizontal, trUtf8("Dictamen"));
        logDataModel->setHeaderData(8, Qt::Horizontal, trUtf8("Consecutivo"));

        proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(logDataModel);

        ui->logTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

        ui->logTableView->setModel(proxyModel);


        ui->logTableView->horizontalHeader()->resizeSection(0,120);
        ui->logTableView->horizontalHeader()->resizeSection(1,80);
        ui->logTableView->horizontalHeader()->resizeSection(2,350);
        ui->logTableView->horizontalHeader()->resizeSection(3,95);
        ui->logTableView->horizontalHeader()->resizeSection(4,95);
        ui->logTableView->horizontalHeader()->resizeSection(5,95);
        ui->logTableView->horizontalHeader()->resizeSection(6,95);
        ui->logTableView->horizontalHeader()->resizeSection(7,95);
        ui->logTableView->horizontalHeader()->resizeSection(8,95);

        ui->logTableView->setSortingEnabled(true);
        ui->logTableView->sortByColumn(0, Qt::AscendingOrder);
    }
}

LogViewForm::~LogViewForm()
{
    delete ui;
}
