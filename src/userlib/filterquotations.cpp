#include <QtWidgets>
#include <QSqlQueryModel>

#include "filterquotations.h"

FilterQuotationsForm::FilterQuotationsForm(QDialog *parent)
    : QDialog(parent)
{
    setupUi(this);

    // Centrar el widget en la mitad del escritorio
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    QSqlQueryModel *modelQuotations= new QSqlQueryModel;
    modelQuotations->setQuery("SELECT quot_date, quot_name, quot_scope, tblTHIRDPARTIES.thrd_name, "
                          "tblTHIRDPARTIES.thrd_nit, quot_cel, quot_tel, tblSTATES.state_name, tblCITIES.city_name, "
                          "quot_inspect_type "
                          "FROM tblQUOTATIONS, tblTHIRDPARTIES, tblSTATES, tblCITIES, tblUSES "
                          "WHERE tblCITIES.city_id=tblQUOTATIONS.city_id "
                          "AND tblSTATES.state_id=tblCITIES.state_id "
                          "AND tblUSES.use_id=tblQUOTATIONS.use_id "
                          "AND tblTHIRDPARTIES.thrd_id=tblQUOTATIONS.thrd_id "
                          "ORDER BY tblQUOTATIONS.quot_id ASC");

    // Establezco nombres de las caberecas
    modelQuotations->setHeaderData(0, Qt::Horizontal, trUtf8("Fecha"));
    modelQuotations->setHeaderData(1, Qt::Horizontal, trUtf8("Nombre Instalación"));
    modelQuotations->setHeaderData(2, Qt::Horizontal, trUtf8("Alcance"));
    modelQuotations->setHeaderData(3, Qt::Horizontal, trUtf8("Cliente"));
    modelQuotations->setHeaderData(4, Qt::Horizontal, trUtf8("Nit"));
    modelQuotations->setHeaderData(5, Qt::Horizontal, trUtf8("Celular"));
    modelQuotations->setHeaderData(6, Qt::Horizontal, trUtf8("Teléfono"));
    modelQuotations->setHeaderData(7, Qt::Horizontal, trUtf8("Departamento"));
    modelQuotations->setHeaderData(8, Qt::Horizontal, trUtf8("Ciudad"));
    modelQuotations->setHeaderData(9, Qt::Horizontal, trUtf8("Tipo Inspec"));

    // Creo un intermediario para ordenado y filtrado
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(modelQuotations);

    // Fijo el ancho de las cabeceras
    quotationsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    quotationsTableView->setModel(proxyModel);
    // Los siguientes son los anchos de cabecera para coincidir con loso anchos de edits
    quotationsTableView->horizontalHeader()->resizeSection(0,90);
    quotationsTableView->horizontalHeader()->resizeSection(1,162);
    quotationsTableView->horizontalHeader()->resizeSection(2,205);
    quotationsTableView->horizontalHeader()->resizeSection(3,154);
    quotationsTableView->horizontalHeader()->resizeSection(4,102);
    quotationsTableView->horizontalHeader()->resizeSection(5,104);
    quotationsTableView->horizontalHeader()->resizeSection(6,104);
    quotationsTableView->horizontalHeader()->resizeSection(7,105);
    quotationsTableView->horizontalHeader()->resizeSection(8,102);
    quotationsTableView->horizontalHeader()->resizeSection(9,88);
    // Activo ordenado
    quotationsTableView->setSortingEnabled(true);
    quotationsTableView->sortByColumn(0, Qt::AscendingOrder);




    // NOTE: Conexión de Señales y Slots
    connect(filterByDateLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setDateRegExp(QString)));

    connect(filterByInstNameLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setInstNameRegExp(QString)));

    connect(filterByScopeLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setScopeRegExp(QString)));

    connect(filterByNameLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setNameRegExp(QString)));

    connect(filterByNitLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setNitRegExp(QString)));

    connect(filterByCelLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setCelRegExp(QString)));

    connect(filterByPhoneLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setPhoneRegExp(QString)));

    connect(filterByStateLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setStateRegExp(QString)));

    connect(filterByCityLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setCityRegExp(QString)));

    connect(filterByInstTypeLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setInstTypeRegExp(QString)));

    connect(goRecordButton, SIGNAL(clicked()),
            this, SLOT(sendAndClose(void)));

}

// NOTE: Slots para filtrado automático
void FilterQuotationsForm::setDateRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(0);
}

void FilterQuotationsForm::setInstNameRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(1);
}

void FilterQuotationsForm::setScopeRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(2);
}

void FilterQuotationsForm::setNameRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(3);
}

void FilterQuotationsForm::setNitRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(4);
}


void FilterQuotationsForm::setCelRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(5);
}

void FilterQuotationsForm::setPhoneRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(6);
}

void FilterQuotationsForm::setStateRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(7);
}

void FilterQuotationsForm::setCityRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(8);
}

void FilterQuotationsForm::setInstTypeRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(9);
}

void FilterQuotationsForm::sendAndClose()
{
    // Obteniendo el nit del cliente con el indice de la columna 5 en la fila seleccionada
    QModelIndex index;
    if (!quotationsTableView->selectionModel()->selectedRows().isEmpty()) {
        index=quotationsTableView->selectionModel()->selectedRows(4).first();
        thrd_nit=quotationsTableView->model()->data(index, Qt::DisplayRole).toString();
    }
    this->close();
}
