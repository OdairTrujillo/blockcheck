#include "filesomething.h"

#include "../src/core/dbhandler.h"
#include "bcnamespace.h"

FileSomething::FileSomething(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fileSomethingDialog)
{
    ui->setupUi(this);

    // Obtengo los distintos folios o AZ
    if (!DbHandler::getRecords(recordsData))
        recordsData.append(QStringList("Sin Datos"));
    for (int i=0; i<recordsData.at(1).size();i++) {
        QListWidgetItem *item = new QListWidgetItem;
        item->setData( Qt::DisplayRole, recordsData.at(1).at(i));
        item->setData( Qt::CheckStateRole, Qt::Unchecked);
        ui->recordFoilListWidget->addItem(item);
    }

    // Deschequear primero para luego seleccionar las AZ.
    for (int i=0; i<ui->recordFoilListWidget->count(); i++)
        ui->recordFoilListWidget->item(i)->setCheckState(Qt::Unchecked);

    QStringList recordsIds;
    DbHandler::getSoRecords(sosData.at(Sos::Id).at(0), recordsIds);
    int index;

    for (int i=0; i<recordsIds.size();i++) {
        index=recordsData.at(0).indexOf(recordsIds.at(i));
        ui->recordFoilListWidget->item(index)->setCheckState(Qt::Checked);
    }
}

FileSomething::~FileSomething()
{
    delete ui;
}
