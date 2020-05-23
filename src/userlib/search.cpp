#include "search.h"

#include "../src/core/dbhandler.h"
#include "bcnamespace.h"

Search::Search(QWidget *parent, const int salesFindComboBoxIndex) :
    QDialog(parent),
    ui(new Ui::searchDialog)
{
    ui->setupUi(this);

    connect(ui->searchButton, SIGNAL(clicked()),
            this, SLOT(doSearch(void)));

    connect(ui->goRecordButton, SIGNAL(clicked()),
            this, SLOT(sendAndClose(void)));

    queryModel = new QSqlQueryModel;

    salesFindOption = salesFindComboBoxIndex;
    switch (salesFindOption) {

    case 0 ... 1: // En el formulario Sales findComboBox estaba ubicado en la opción de NIT (cotizaciones)

        ui->searchByComboBox->addItem("Nombre del cliente");
        ui->searchByComboBox->addItem("Nombre de instalación");
        ui->searchByComboBox->addItem("Alcance cotizado");
        ui->searchByComboBox->addItem("Departamento");
        ui->searchByComboBox->addItem("Ciudad"); // TODO: poner un total de registros, sería util saber cuántas cotizaciones por ciudad
        ui->searchByComboBox->addItem("Dirección");

        queryString = "SELECT quot_date, quot_name, quot_scope, tblTHIRDPARTIES.thrd_name, "
                      "tblTHIRDPARTIES.thrd_nit, quot_cel, tblSTATES.state_name, tblCITIES.city_name, "
                      "quot_address, quot_inspect_type "
                      "FROM tblQUOTATIONS, tblTHIRDPARTIES, tblSTATES, tblCITIES, tblUSES "
                      "WHERE tblCITIES.city_id=tblQUOTATIONS.city_id "
                      "AND tblSTATES.state_id=tblCITIES.state_id "
                      "AND tblUSES.use_id=tblQUOTATIONS.use_id "
                      "AND tblTHIRDPARTIES.thrd_id=tblQUOTATIONS.thrd_id "
                      "AND %1 ILIKE :search_string "
                      "ORDER BY tblQUOTATIONS.quot_id ASC";
        break;

    case 2: // En el formulario Sales findComboBox estaba ubicado en la opción de propuesta comercial

        ui->searchByComboBox->addItem("Nombre del cliente");
        ui->searchByComboBox->addItem("Nombre de intalación");
        ui->searchByComboBox->addItem("Alcance propuesto");
        ui->searchByComboBox->addItem("Atendido por");
        ui->searchByComboBox->addItem("Departamento");
        ui->searchByComboBox->addItem("Ciudad"); // TODO: poner un total de registros, sería util saber cuántas propuestas hay por ciudad o departamento

        queryString = "SELECT prop_id, prop_date, prop_scope, tblQUOTATIONS.quot_name, tblTHIRDPARTIES.thrd_name, "
                      "prop_total_value::money, tblUSERS.user_lname, tblSTATES.state_name, tblCITIES.city_name "
                      "FROM tblPROPOSALS, tblUSERS, tblQUOTATIONS, tblTHIRDPARTIES, tblSTATES, tblCITIES "
                      "WHERE tblCITIES.city_id=tblQUOTATIONS.city_id "
                      "AND tblSTATES.state_id=tblCITIES.state_id "
                      "AND tblUSERS.user_id=tblPROPOSALS.user_id "
                      "AND tblTHIRDPARTIES.thrd_id=tblQUOTATIONS.thrd_id "
                      "AND tblQUOTATIONS.quot_id=tblPROPOSALS.quot_id "
                      "AND %1 ILIKE :search_string "
                      "ORDER BY tblPROPOSALS.prop_id ASC";
        break;
    case 3: // En el formulario Sales findComboBox estaba ubicado en la opción de ordenes de servicio
        ui->searchByComboBox->addItem("Nombre del cliente");
        ui->searchByComboBox->addItem("Nombre de intalación");
        ui->searchByComboBox->addItem("Alcance contratado");
        ui->searchByComboBox->addItem("Inspector");
        ui->searchByComboBox->addItem("Departamento");
        ui->searchByComboBox->addItem("Ciudad"); // TODO: poner un total de registros, sería util saber cuántas órdenes de servicio hay por ciudad o departamento

        queryString = "SELECT so_id, so_date, so_scope, tblINSPECTORS.inspector_name, tblQUOTATIONS.quot_name, tblTHIRDPARTIES.thrd_name, "
                      "tblSTATES.state_name, tblCITIES.city_name "
                      "FROM tblSERVICEORDERS, tblPROPOSALS, tblQUOTATIONS, tblTHIRDPARTIES, tblSTATES, tblCITIES "
                      "WHERE tblCITIES.city_id=tblQUOTATIONS.city_id "
                      "AND tblSTATES.state_id=tblCITIES.state_id "
                      "AND tblINSPECTORS.inspector_id=tblSERVICEORDERS.inspector_id "
                      "AND tblTHIRDPARTIES.thrd_id=tblQUOTATIONS.thrd_id "
                      "AND tblQUOTATIONS.quot_id=tblPROPOSALS.quot_id "
                      "AND tblPROPOSALS.prop_id=tblSERVICEORDERS.prop_id "
                      "AND %1 ILIKE :search_string "
                      "ORDER BY tblSERVICEORDERS.so_id ASC";
        break;
    }

 }

void Search::doSearch()
{
    switch (salesFindOption) {

    case 0 ... 1: // Se busca desde opción cotización
        switch (ui->searchByComboBox->currentIndex()) {

        case 0:
            searchString = "tblTHIRDPARTIES.thrd_name";
            break;
        case 1:
            searchString = "tblQUOTATIONS.quot_name";
            break;
        case 2:
            searchString = "tblQUOTATIONS.quot_scope";
            break;
        case 3:
            searchString = "tblSTATES.state_name";
            break;
        case 4:
            searchString = "tblCITIES.city_name";
            break;
        case 5:
            searchString = "tblQUOTATIONS.quot_address";
            break;
          }
        // Establezco nombres de las caberecas
        queryModel->setHeaderData(0, Qt::Horizontal, "Fecha");
        queryModel->setHeaderData(1, Qt::Horizontal, "Nombre Instalación");
        queryModel->setHeaderData(2, Qt::Horizontal, "Alcance");
        queryModel->setHeaderData(3, Qt::Horizontal, "Cliente");
        queryModel->setHeaderData(4, Qt::Horizontal, "Nit");
        queryModel->setHeaderData(5, Qt::Horizontal, "Departamento");
        queryModel->setHeaderData(6, Qt::Horizontal, "Ciudad");
        queryModel->setHeaderData(7, Qt::Horizontal, "Dirección");
        queryModel->setHeaderData(8, Qt::Horizontal, "Tipo Inspec");
        break;

    case 2: // se busca desde la opción propuesta comercial
        switch (ui->searchByComboBox->currentIndex()) {

        case 0:
            searchString = "tblTHIRDPARTIES.thrd_name";
            break;
        case 1:
            searchString = "tblQUOTATIONS.quot_name";
            break;
        case 2:
            searchString = "tblPROPOSALS.prop_scope";
            break;
        case 3:
            searchString = "tblUSERS.user_lname";
            break;
        case 4:
            searchString = "tblSTATES.state_name";
            break;
        case 5:
            searchString = "tblCITIES.city_name";
            break;
          }

        // Establezco nombres de las caberecas
        queryModel->setHeaderData(0, Qt::Horizontal, "Cotización");
        queryModel->setHeaderData(1, Qt::Horizontal, "Fecha");
        queryModel->setHeaderData(2, Qt::Horizontal, "Alcance");
        queryModel->setHeaderData(3, Qt::Horizontal, "Instalación");
        queryModel->setHeaderData(4, Qt::Horizontal, "Cliente");
        queryModel->setHeaderData(5, Qt::Horizontal, "Valor total");
        queryModel->setHeaderData(6, Qt::Horizontal, "Atentido por");
        queryModel->setHeaderData(7, Qt::Horizontal, "Departamento");
        queryModel->setHeaderData(8, Qt::Horizontal, "Ciudad");
        qDebug() << queryForModel.lastQuery().toUtf8();
        break;

    case 3: // se busca desde la opción órden de servicio
        switch (ui->searchByComboBox->currentIndex()) {

        case 0:
            searchString = "tblTHIRDPARTIES.thrd_name";
            break;
        case 1:
            searchString = "tblQUOTATIONS.quot_name";
            break;
        case 2:
            searchString = "tblSERVICEORDERS.so_scope";
            break;
        case 3:
            searchString = "tblINSPECTORS.inspector_name";
            break;
        case 4:
            searchString = "tblSTATES.state_name";
            break;
        case 5:
            searchString = "tblCITIES.city_name";
            break;
          }

        // Establezco nombres de las caberecas
        queryModel->setHeaderData(0, Qt::Horizontal, "Órden de servicio");
        queryModel->setHeaderData(1, Qt::Horizontal, "Fecha");
        queryModel->setHeaderData(2, Qt::Horizontal, "Alcance");
        queryModel->setHeaderData(3, Qt::Horizontal, "Inspector");
        queryModel->setHeaderData(4, Qt::Horizontal, "Instalación");
        queryModel->setHeaderData(5, Qt::Horizontal, "Cliente");
        queryModel->setHeaderData(6, Qt::Horizontal, "Departamento");
        queryModel->setHeaderData(7, Qt::Horizontal, "Ciudad");
        qDebug() << queryForModel.lastQuery().toUtf8();
        break;
    }

    queryForModel.prepare(queryString.arg(searchString));
    queryForModel.bindValue(":search_string", ("%" + ui->searchLineEdit->text() + "%"));

    if(!queryForModel.exec()) {
        qDebug() << "Error en queryForModel, buscando por " + queryForModel.lastError().text();
        qDebug() << "La consulta fue: " << queryForModel.lastQuery().toUtf8();
    }

    qDebug() << queryForModel.boundValue(0).toString();

    queryModel->setQuery(queryForModel);

    ui->queryResultTableView->setModel(queryModel);
}

void Search::sendAndClose()
{
    // Obteniendo el nit del cliente con el indice de la columna 5 en la fila seleccionada
    QModelIndex index;
    if (!ui->queryResultTableView->selectionModel()->selectedRows().isEmpty()) {
        index=ui->queryResultTableView->selectionModel()->selectedRows(4).first();
        valueToSend=ui->queryResultTableView->model()->data(index, Qt::DisplayRole).toString();
        qDebug() << "Falta devolver de acuerdo al caso, la columna cuyo valor de registro seleccionado se deba enviar";
    }
    this->close();
}

Search::~Search()
{
    delete ui;
}
