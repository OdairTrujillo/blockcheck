#include "subdictumslist.h"
#include "dbhandler.h"


SubDictumsListForm::SubDictumsListForm(QStringList subDictum_Data, QList<QStringList> req_Results,
                                       int start, int end,  QDialog *parent) :
    QDialog(parent)
{
    setupUi(this);

    subDictumData=subDictum_Data;
    subDictumIndex=start;
    subDictumsEnd=end;
    reqResults=req_Results;
    success=false; // Inicio en false ya que solo cambia a true cuando tuvo éxito.

    connect(processSubDictumsButton, SIGNAL(clicked()),
            this, SLOT(processDictums()));

    // dictumsListModel es miembro de la clase y sirve para mostrar los datos
    // de precios de la propuesta comercial en forma de tabla.
    int ncol=6, nrow=end;

    tableWidget->setColumnCount(ncol);
    tableWidget->setRowCount(nrow);
    tableWidget->setHorizontalHeaderLabels(QString("Tipo;Identificador;Ubicacion;Carga;Tension;Resistencia").split(";"));
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    spinBoxKVA = new SpinBoxDelegate("kva");
    spinBoxOhms = new SpinBoxDelegate("ohms");
    tableWidget->setItemDelegateForColumn(3, spinBoxKVA);
    tableWidget->setItemDelegateForColumn(5, spinBoxOhms);

//    tableWidget->horizontalHeader()->resizeSection(0,35);
//    tableWidget->horizontalHeader()->resizeSection(1,485);
//    tableWidget->horizontalHeader()->resizeSection(2,50);
//    tableWidget->horizontalHeader()->resizeSection(3,50);
//    tableWidget->horizontalHeader()->resizeSection(4,70);

    // setItem para texto o números, setCellWidget es para algún widget como un checkbox o un combobox
    for (int i=0;i<tableWidget->rowCount();i++) {
        tableWidget->setItem(i,0,new QTableWidgetItem(subDictumData.at(6)));
        tableWidget->setItem(i,1,new QTableWidgetItem(subDictumData.at(7)));
        tableWidget->setItem(i,2,new QTableWidgetItem(subDictumData.at(8)));
        tableWidget->setItem(i,3,new QTableWidgetItem(subDictumData.at(9)));
        tableWidget->setItem(i,4,new QTableWidgetItem(subDictumData.at(10)));
        tableWidget->setItem(i,5,new QTableWidgetItem(subDictumData.at(11)));
    }
//    tableWidget->setCellWidget(i,2,applyCheckBoxes.at(i));
//    tableWidget->setCellWidget(i,3,meetsCheckBoxes.at(i));
//    tableWidget->setCellWidget(i,4,noMeetsCheckBoxes.at(i));
}

void SubDictumsListForm::processDictums()
{
    int ret1=QMessageBox::information(this, trUtf8("Procesar"),
                                      trUtf8("Presione Si guardar estos consectuvos o Cancelar para corregir"),
                                      QMessageBox::Yes | QMessageBox::Cancel);
    if (ret1==QMessageBox::Yes) {

        QProgressDialog progress("Creando consecutivos...", "Abortar", 0, subDictumsEnd, this);
        progress.setMinimum(0);
        progress.setWindowModality(Qt::WindowModal);
        progress.show();

        for (int i=0; i < subDictumsEnd; i++) {
            QApplication::processEvents();
            progress.setValue(i);
            if (progress.wasCanceled())
                break;
            subDictumData.replace(6, tableWidget->item(i,0)->text());
            subDictumData.replace(7, tableWidget->item(i,1)->text());
            subDictumData.replace(8, tableWidget->item(i,2)->text());
            subDictumData.replace(9, tableWidget->item(i,3)->text());
            subDictumData.replace(10, tableWidget->item(i,4)->text());
            subDictumData.replace(11, tableWidget->item(i,5)->text());

            if (!DbHandler::insertSubDictum(subDictumData, reqResults, QString::number(subDictumIndex+i))) {
                QMessageBox::warning(this, trUtf8("Error insertando datos"),
                                     trUtf8("Error al insertar los consecutivos. Ejecute el\n"
                                            "programa bajo consola y revise los mensajes"),
                                     QMessageBox::Cancel);
                qDebug() << "DbHandler::insertSubDictum devolvió false al intentar insertar un dictamen";
                break;
            }
            else {
                success=true;
            }
        }
        progress.setValue(subDictumsEnd);
        this->close();
    }
}

