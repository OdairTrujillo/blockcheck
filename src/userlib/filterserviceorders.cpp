#include <QtWidgets>
#include <QSqlQueryModel>

#include "filterserviceorders.h"

FilterServiceOrdersForm::FilterServiceOrdersForm(QDialog *parent)
    : QDialog(parent)
{
    setupUi(this);

    // Centrar el widget en la mitad del escritorio
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    // NOTE: Conexión de Señales y Slots
    connect(filterBySoIdLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setSoIdRegExp(QString)));

    connect(filterByDateLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setDateRegExp(QString)));

    connect(filterByInstNameLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setInstNameRegExp(QString)));

    connect(filterByScopeLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setScopeRegExp(QString)));

    connect(filterByNameLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setNameRegExp(QString)));

    connect(filterByValueLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setValueRegExp(QString)));

    connect(filterByAssignDateLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setAssignDateRegExp(QString)));

    connect(filterByProcessedLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setProcessedRegExp(QString)));

    connect(filterByDocProcessedLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setDocProcessedRegExp(QString)));

    connect(goRecordButton, SIGNAL(clicked()),
            this, SLOT(sendAndClose(void)));

    QSqlQueryModel *modelServiceOrders= new QSqlQueryModel;
    modelServiceOrders->setQuery("SELECT so_id, so_date, tblQUOTATIONS.quot_name, so_scope, "
                                 "tblTHIRDPARTIES.thrd_name, tblPROPOSALS.prop_value::money, so_assign_date, "
                                 "so_acc_processed, so_doc_processed, so_eng_processed "
                                 "FROM tblSERVICEORDERS INNER JOIN tblPROPOSALS ON (tblSERVICEORDERS.prop_id=tblPROPOSALS.prop_id) "
                                 "INNER JOIN tblQUOTATIONS ON (tblPROPOSALS.quot_id=tblQUOTATIONS.quot_id) "
                                 "INNER JOIN tblTHIRDPARTIES ON (tblTHIRDPARTIES.thrd_id=tblQUOTATIONS.thrd_id) "
                                 "ORDER BY tblSERVICEORDERS.so_id ASC");

    modelServiceOrders->setHeaderData(0, Qt::Horizontal, trUtf8("OS Nº"));
    modelServiceOrders->setHeaderData(1, Qt::Horizontal, trUtf8("Fecha"));
    modelServiceOrders->setHeaderData(2, Qt::Horizontal, trUtf8("Nombre Instalación"));
    modelServiceOrders->setHeaderData(3, Qt::Horizontal, trUtf8("Alcance"));
    modelServiceOrders->setHeaderData(4, Qt::Horizontal, trUtf8("Cliente"));
    modelServiceOrders->setHeaderData(5, Qt::Horizontal, trUtf8("Valor"));
    modelServiceOrders->setHeaderData(6, Qt::Horizontal, trUtf8("Fecha Insp"));
    modelServiceOrders->setHeaderData(7, Qt::Horizontal, trUtf8("Contable"));
    modelServiceOrders->setHeaderData(8, Qt::Horizontal, trUtf8("Documentos"));
    modelServiceOrders->setHeaderData(9, Qt::Horizontal, trUtf8("Ingeniería"));


    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(modelServiceOrders);

    serviceOrdersTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    serviceOrdersTableView->setModel(proxyModel);

    serviceOrdersTableView->horizontalHeader()->resizeSection(0,70);
    serviceOrdersTableView->horizontalHeader()->resizeSection(1,70);
    serviceOrdersTableView->horizontalHeader()->resizeSection(2,185);
    serviceOrdersTableView->horizontalHeader()->resizeSection(3,215);
    serviceOrdersTableView->horizontalHeader()->resizeSection(4,165);
    serviceOrdersTableView->horizontalHeader()->resizeSection(5,110);
    serviceOrdersTableView->horizontalHeader()->resizeSection(6,100);
    serviceOrdersTableView->horizontalHeader()->resizeSection(7,105);
    serviceOrdersTableView->horizontalHeader()->resizeSection(8,105);
    serviceOrdersTableView->horizontalHeader()->resizeSection(9,95);

    serviceOrdersTableView->setSortingEnabled(true);
    serviceOrdersTableView->sortByColumn(0, Qt::AscendingOrder);
}

// NOTE: Slots para filtrado automático
void FilterServiceOrdersForm::setSoIdRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(0);
}

void FilterServiceOrdersForm::setDateRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(1);
}

void FilterServiceOrdersForm::setInstNameRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(2);
}

void FilterServiceOrdersForm::setScopeRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(3);
}

void FilterServiceOrdersForm::setNameRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(4);
}

void FilterServiceOrdersForm::setValueRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(5);
}

void FilterServiceOrdersForm::setAssignDateRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(6);
}

void FilterServiceOrdersForm::setProcessedRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(7);
}

void FilterServiceOrdersForm::setDocProcessedRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(8);
}

void FilterServiceOrdersForm::setEngProcessedRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(9);
}

void FilterServiceOrdersForm::sendAndClose()
{
    // Obteniendo el id de os, se obtiene el índice de la columna cero en la fila seleccionada
    QModelIndex index;
    if (!serviceOrdersTableView->selectionModel()->selectedRows().isEmpty()) {
        index=serviceOrdersTableView->selectionModel()->selectedRows(0).first();
        so_id=serviceOrdersTableView->model()->data(index, Qt::DisplayRole).toString();
    }
    this->close();
}
