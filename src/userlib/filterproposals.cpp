#include <QtWidgets>
#include <QSqlQueryModel>

#include "filterproposals.h"

FilterProposalsForm::FilterProposalsForm(QDialog *parent)
    : QDialog(parent)
{
    setupUi(this);

    // Centrar el widget en la mitad del escritorio
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    QSqlQueryModel *modelProposals= new QSqlQueryModel;
    modelProposals->setQuery("SELECT prop_id, prop_date, "
                          "tblQUOTATIONS.quot_name, prop_scope, tblTHIRDPARTIES.thrd_name, "
                          "prop_value::money, prop_state, tblUSERS.user_lname "
                          "FROM tblPROPOSALS INNER JOIN tblQUOTATIONS ON (tblQUOTATIONS.quot_id=tblPROPOSALS.quot_id) "
                          "INNER JOIN tblTHIRDPARTIES ON (tblTHIRDPARTIES.thrd_id=tblQUOTATIONS.thrd_id) "
                          "INNER JOIN tblUSERS ON (tblUSERS.user_id=tblPROPOSALS.user_id) "
                          "ORDER BY tblPROPOSALS.prop_id ASC");

    // Estableciendo nombre de cabeceras
    modelProposals->setHeaderData(0, Qt::Horizontal, trUtf8("Propuesta"));
    modelProposals->setHeaderData(1, Qt::Horizontal, trUtf8("Fecha"));
    modelProposals->setHeaderData(2, Qt::Horizontal, trUtf8("Nombre Instalación"));
    modelProposals->setHeaderData(3, Qt::Horizontal, trUtf8("Alcance"));
    modelProposals->setHeaderData(4, Qt::Horizontal, trUtf8("Cliente"));
    modelProposals->setHeaderData(5, Qt::Horizontal, trUtf8("Valor"));
    modelProposals->setHeaderData(6, Qt::Horizontal, trUtf8("Estado"));
    modelProposals->setHeaderData(7, Qt::Horizontal, trUtf8("Vendedor"));

    // Modelo intermediario para ordenar y filtrar
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(modelProposals);
    // Bloqueo el redimensionado de cabecera
    proposalsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    // Estableciendo tamaño de las cabeceras para coincidir con los edits
    proposalsTableView->setModel(proxyModel);

    proposalsTableView->horizontalHeader()->resizeSection(0,101);
    proposalsTableView->horizontalHeader()->resizeSection(1,93);
    proposalsTableView->horizontalHeader()->resizeSection(2,224);
    proposalsTableView->horizontalHeader()->resizeSection(3,215);
    proposalsTableView->horizontalHeader()->resizeSection(4,156);
    proposalsTableView->horizontalHeader()->resizeSection(5,112);
    proposalsTableView->horizontalHeader()->resizeSection(6,104);
    proposalsTableView->horizontalHeader()->resizeSection(7,165);

    // Activo ordenado por columna 0 ascendentemente
    proposalsTableView->setSortingEnabled(true);
    proposalsTableView->sortByColumn(0, Qt::AscendingOrder);


    // NOTE: Conexión de Señales y Slots
    connect(filterByPropIdLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setPropIdRegExp(QString)));

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

    connect(filterByStateLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setStateRegExp(QString)));

    connect(filterByUserLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(setUserRegExp(QString)));

    connect(goRecordButton, SIGNAL(clicked()),
            this, SLOT(sendAndClose(void)));

}

// NOTE: Slots para filtrado automático
void FilterProposalsForm::setPropIdRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(0);
}

void FilterProposalsForm::setDateRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(1);
}

void FilterProposalsForm::setInstNameRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(2);
}

void FilterProposalsForm::setScopeRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(3);
}

void FilterProposalsForm::setNameRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(4);
}

void FilterProposalsForm::setValueRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(5);
}

void FilterProposalsForm::setStateRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(6);
}

void FilterProposalsForm::setUserRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(7);
}


void FilterProposalsForm::sendAndClose()
{
    // Obtendo el id de propuesta, se obtiene el índice de la columna cero en la fila seleccionada
    QModelIndex index;
    if (!proposalsTableView->selectionModel()->selectedRows().isEmpty()) {
        index=proposalsTableView->selectionModel()->selectedRows(0).first();
        prop_id=proposalsTableView->model()->data(index, Qt::DisplayRole).toString();
    }
    this->close();
}
