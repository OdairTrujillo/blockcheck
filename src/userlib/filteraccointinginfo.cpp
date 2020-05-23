#include <QtWidgets>
#include <QSqlQueryModel>

#include "filteraccountinginfo.h"

FilterAccountingInfoForm::FilterAccountingInfoForm(QDialog *parent)
    : QDialog(parent)
{
    setupUi(this);

    // Centrar el widget en la mitad del escritorio
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    // NOTE: Conexión de Señales y Slots
    connect(filterBySoIdLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setSoIdRegExp(QString)));

    connect(filterByMovTypeLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setMovTypeRegExp(QString)));

    connect(filterByMovDocummentLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setMovDocummentRegExp(QString)));

    connect(filterByMovDateLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setMovDateRegExp(QString)));

    connect(filterByMovNameLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setMovNameRegExp(QString)));

    connect(filterByMovNitLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setMovNitRegExp(QString)));

    connect(filterByMovObservationsLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setMovObservationsRegExp(QString)));

    connect(goRecordButton, SIGNAL(clicked()),
            this, SLOT(sendAndClose(void)));

    QSqlQueryModel *accountingInfoModel= new QSqlQueryModel;
    accountingInfoModel->setQuery("SELECT tblMOVEMENTS.so_id, tblPROPOSALS.prop_value::money,  mov_type, "
                                  "mov_documment, mov_date, mov_name, mov_nit, mov_value::money, mov_observations "
                                  "FROM tblMOVEMENTS INNER JOIN tblSERVICEORDERS ON (tblMOVEMENTS.so_id=tblSERVICEORDERS.so_id) "
                                  "INNER JOIN tblPROPOSALS ON (tblSERVICEORDERS.prop_id=tblPROPOSALS.prop_id) "
                                  "ORDER BY mov_date ASC");

    accountingInfoModel->setHeaderData(0, Qt::Horizontal, trUtf8("OS Nº"));
    accountingInfoModel->setHeaderData(1, Qt::Horizontal, trUtf8("Valor OS"));
    accountingInfoModel->setHeaderData(2, Qt::Horizontal, trUtf8("Tipo Movimiento"));
    accountingInfoModel->setHeaderData(3, Qt::Horizontal, trUtf8("Documento"));
    accountingInfoModel->setHeaderData(4, Qt::Horizontal, trUtf8("Fecha"));
    accountingInfoModel->setHeaderData(5, Qt::Horizontal, trUtf8("Nombre"));
    accountingInfoModel->setHeaderData(6, Qt::Horizontal, trUtf8("NIT"));
    accountingInfoModel->setHeaderData(7, Qt::Horizontal, trUtf8("Valor Movimiento"));
    accountingInfoModel->setHeaderData(8, Qt::Horizontal, trUtf8("Observaciones"));

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(accountingInfoModel);

    accountingInfoTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    accountingInfoTableView->setModel(proxyModel);


    accountingInfoTableView->horizontalHeader()->resizeSection(0,95);
    accountingInfoTableView->horizontalHeader()->resizeSection(1,110);
    accountingInfoTableView->horizontalHeader()->resizeSection(2,120);
    accountingInfoTableView->horizontalHeader()->resizeSection(3,100);
    accountingInfoTableView->horizontalHeader()->resizeSection(4,90);
    accountingInfoTableView->horizontalHeader()->resizeSection(5,180);
    accountingInfoTableView->horizontalHeader()->resizeSection(6,100);
    accountingInfoTableView->horizontalHeader()->resizeSection(7,120);
    accountingInfoTableView->horizontalHeader()->resizeSection(8,235);

    accountingInfoTableView->setSortingEnabled(true);
    accountingInfoTableView->sortByColumn(4, Qt::DescendingOrder);

}
// TODO: Filtrar por mas de una columna
// NOTE: Slots para filtrado automático
void FilterAccountingInfoForm::setSoIdRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(0);
}

void FilterAccountingInfoForm::setMovTypeRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(2);
}

void FilterAccountingInfoForm::setMovDocummentRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(3);
}

void FilterAccountingInfoForm::setMovDateRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(4);
}

void FilterAccountingInfoForm::setMovNameRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(5);
}

void FilterAccountingInfoForm::setMovNitRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(6);
}

void FilterAccountingInfoForm::setMovObservationsRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(8);
}



void FilterAccountingInfoForm::sendAndClose()
{
    // Obteniendo el id de os, se obtiene el índice de la columna cero en la fila seleccionada
    QModelIndex index;
    if (!accountingInfoTableView->selectionModel()->selectedRows().isEmpty()) {
        index=accountingInfoTableView->selectionModel()->selectedRows(0).first();
        so_id=accountingInfoTableView->model()->data(index, Qt::DisplayRole).toString();
    }
    this->close();
}

