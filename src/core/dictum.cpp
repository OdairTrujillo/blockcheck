#include "dictum.h"
#include "dbhandler.h"
#include "subdictum.h"
#include "userlib/renderdictum.h"
#include "userlib/bcnamespace.h"

#include <QtSql>

DictumForm::DictumForm(QString dictumOption, QStringList dictum_Data,  QStringList inspection_Data, QDialog *parent) :
    QDialog(parent)
{
    // Se crean los controles de la UI
    setupUi(this);

    // Creación de señales y slots
    connect(processDictumButton, SIGNAL(clicked()),
            this, SLOT(processDictum()));

    connect(updateDictumButton, SIGNAL(clicked()),
            this, SLOT(updateDictumAction()));

    connect(saveDictumButton, SIGNAL(clicked()),
            this, SLOT(saveDictum()));

    connect(newSubDictumButton, SIGNAL(clicked()),
            this, SLOT(newSubDictum()));

    connect(goSubDictumButton, SIGNAL(clicked()),
            this, SLOT(goSubDictum()));

    connect(dictumUsesComboBox, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(launchUsesFilter(QString)));

    connect(previewDictumButton, SIGNAL(clicked()),
            this, SLOT(previewDictum()));

    if (!DbHandler::getProcesses(processesData))
        processesData.append(QStringList("Sin Datos"));

    if (!DbHandler::getUses(usesData))
        usesData.append(QStringList("Sin Datos"));

    dictumUsesComboBox->addItems(usesData.at(1));

    genAssociatedProcsComboBox->addItems(processesData.at(1));
//    genAssociatedProcsComboBox->lineEdit()->setText("Selecciones los Procesos");

    transmAssociatedProcsComboBox->addItems(processesData.at(1));
//    transmAssociatedProcsComboBox->lineEdit()->setText("Selecciones los Procesos");

    transfAssociatedProcsComboBox->addItems(processesData.at(1));
//    transfAssociatedProcsComboBox->lineEdit()->setText("Selecciones los Procesos");

    inspectionData=inspection_Data;
    dictumData=dictum_Data;

    filterUsesDialog = new QDialog(this);
    filterUsesDialog->setModal(true);
    QLineEdit *filterUsesLineEdit;
    filterUsesLineEdit = new QLineEdit(filterUsesDialog);

    connect(filterUsesLineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeFilterRegExp(QString)));

    // inicializando
    filterListView = new QListView(this);

    QStandardItemModel *filterUsesModel;
    filterUsesModel = new QStandardItemModel(this);

    foreach(QString items, usesData.at(1))
        filterUsesModel->appendRow(new QStandardItem(items));

    filterListView->setSelectionMode(QAbstractItemView::ExtendedSelection);

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(filterUsesModel);

    filterListView->setModel(proxyModel);

    QVBoxLayout *filterUsesLayout = new QVBoxLayout(filterUsesDialog);
    filterUsesLayout->addWidget(filterUsesLineEdit);
    filterUsesLayout->addWidget(filterListView);

    filterUsesDialog->setLayout(filterUsesLayout);




    // Se lee el proceso y de acuerdo con esto se ocultan los widgets asodicados a otros procesos
    // y se destruye el layout que los contiene
    switch (inspectionData.at(1).toInt()) {
    case BcProcs::Generacion:
        // Se recorren los widgets del layout ocultándolos y luego se destruye el layout
        for (int i=0; i<transmGridLayout->rowCount();i++)
            for (int j=0; j<transmGridLayout->columnCount();j++)
                if (!transmGridLayout->itemAtPosition(i,j)->isEmpty())
                    transmGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete transmGridLayout;

        for (int i=0; i<transfGridLayout->rowCount();i++)
            for (int j=0; j<transfGridLayout->columnCount();j++)
                if (!transfGridLayout->itemAtPosition(i,j)->isEmpty())
                    transfGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete transfGridLayout;

        for (int i=0; i<distGridLayout->rowCount();i++)
            for (int j=0; j<distGridLayout->columnCount();j++)
                if (!distGridLayout->itemAtPosition(i,j)->isEmpty())
                    distGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete distGridLayout;

        for (int i=0; i<alExtGridLayout->rowCount();i++)
            for (int j=0; j<alExtGridLayout->columnCount();j++)
                if (!alExtGridLayout->itemAtPosition(i,j)->isEmpty())
                    alExtGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete alExtGridLayout;
        dictumUseSpecialNameLineEdit->hide();

        break;

    case BcProcs::Transmision:
        for (int i=0; i<genGridLayout->rowCount();i++)
            for (int j=0; j<genGridLayout->columnCount();j++)
                if (!genGridLayout->itemAtPosition(i,j)->isEmpty())
                    genGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete genGridLayout;

        for (int i=0; i<transfGridLayout->rowCount();i++)
            for (int j=0; j<transfGridLayout->columnCount();j++)
                if (!transfGridLayout->itemAtPosition(i,j)->isEmpty())
                    transfGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete transfGridLayout;

        for (int i=0; i<distGridLayout->rowCount();i++)
            for (int j=0; j<distGridLayout->columnCount();j++)
                if (!distGridLayout->itemAtPosition(i,j)->isEmpty())
                    distGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete distGridLayout;

        for (int i=0; i<alExtGridLayout->rowCount();i++)
            for (int j=0; j<alExtGridLayout->columnCount();j++)
                if (!alExtGridLayout->itemAtPosition(i,j)->isEmpty())
                    alExtGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete alExtGridLayout;
        dictumUseSpecialNameLineEdit->hide();

        break;

    case BcProcs::Transformacion:
        for (int i=0; i<transmGridLayout->rowCount();i++)
            for (int j=0; j<transmGridLayout->columnCount();j++)
                if (!transmGridLayout->itemAtPosition(i,j)->isEmpty())
                    transmGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete transmGridLayout;

        for (int i=0; i<genGridLayout->rowCount();i++)
            for (int j=0; j<genGridLayout->columnCount();j++)
                if (!genGridLayout->itemAtPosition(i,j)->isEmpty())
                    genGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete genGridLayout;

        for (int i=0; i<distGridLayout->rowCount();i++)
            for (int j=0; j<distGridLayout->columnCount();j++)
                if (!distGridLayout->itemAtPosition(i,j)->isEmpty())
                    distGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete distGridLayout;

        for (int i=0; i<alExtGridLayout->rowCount();i++)
            for (int j=0; j<alExtGridLayout->columnCount();j++)
                if (!alExtGridLayout->itemAtPosition(i,j)->isEmpty())
                    alExtGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete alExtGridLayout;
        dictumUseSpecialNameLineEdit->hide();

        break;

    case BcProcs::Distribucion:
        for (int i=0; i<transmGridLayout->rowCount();i++)
            for (int j=0; j<transmGridLayout->columnCount();j++)
                if (!transmGridLayout->itemAtPosition(i,j)->isEmpty())
                    transmGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete transmGridLayout;

        for (int i=0; i<transfGridLayout->rowCount();i++)
            for (int j=0; j<transfGridLayout->columnCount();j++)
                if (!transfGridLayout->itemAtPosition(i,j)->isEmpty())
                    transfGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete transfGridLayout;

        for (int i=0; i<genGridLayout->rowCount();i++)
            for (int j=0; j<genGridLayout->columnCount();j++)
                if (!genGridLayout->itemAtPosition(i,j)->isEmpty())
                    genGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete genGridLayout;

        for (int i=0; i<alExtGridLayout->rowCount();i++)
            for (int j=0; j<alExtGridLayout->columnCount();j++)
                if (!alExtGridLayout->itemAtPosition(i,j)->isEmpty())
                    alExtGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete alExtGridLayout;
        dictumUseSpecialNameLineEdit->hide();

        break;

    case BcProcs::AlumbradoExt:
        for (int i=0; i<transmGridLayout->rowCount();i++)
            for (int j=0; j<transmGridLayout->columnCount();j++)
                if (!transmGridLayout->itemAtPosition(i,j)->isEmpty())
                    transmGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete transmGridLayout;

        for (int i=0; i<transfGridLayout->rowCount();i++)
            for (int j=0; j<transfGridLayout->columnCount();j++)
                if (!transfGridLayout->itemAtPosition(i,j)->isEmpty())
                    transfGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete transfGridLayout;

        for (int i=0; i<distGridLayout->rowCount();i++)
            for (int j=0; j<distGridLayout->columnCount();j++)
                if (!distGridLayout->itemAtPosition(i,j)->isEmpty())
                    distGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete distGridLayout;

        for (int i=0; i<genGridLayout->rowCount();i++)
            for (int j=0; j<genGridLayout->columnCount();j++)
                if (!genGridLayout->itemAtPosition(i,j)->isEmpty())
                    genGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete genGridLayout;
        dictumUseSpecialNameLineEdit->hide();

        break;

    default:
        for (int i=0; i<transmGridLayout->rowCount();i++)
            for (int j=0; j<transmGridLayout->columnCount();j++)
                if (!transmGridLayout->itemAtPosition(i,j)->isEmpty())
                    transmGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete transmGridLayout;

        for (int i=0; i<transfGridLayout->rowCount();i++)
            for (int j=0; j<transfGridLayout->columnCount();j++)
                if (!transfGridLayout->itemAtPosition(i,j)->isEmpty())
                    transfGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete transfGridLayout;

        for (int i=0; i<distGridLayout->rowCount();i++)
            for (int j=0; j<distGridLayout->columnCount();j++)
                if (!distGridLayout->itemAtPosition(i,j)->isEmpty())
                    distGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete distGridLayout;

        for (int i=0; i<genGridLayout->rowCount();i++)
            for (int j=0; j<genGridLayout->columnCount();j++)
                if (!genGridLayout->itemAtPosition(i,j)->isEmpty())
                    genGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete genGridLayout;

        for (int i=0; i<alExtGridLayout->rowCount();i++)
            for (int j=0; j<alExtGridLayout->columnCount();j++)
                if (!alExtGridLayout->itemAtPosition(i,j)->isEmpty())
                    alExtGridLayout->itemAtPosition(i,j)->widget()->hide();
        delete alExtGridLayout;
        break;
    }

    if (inspectionData.at(2)!="Uso Final") {
        subDictumsLabel->hide();
        subDictumsComboBox->hide();
        goSubDictumButton->hide();
        newSubDictumButton->hide();
    }

    if (inspectionData.at(5)=="Finalizada" || inspectionData.at(5)=="No Dictaminada")
        newSubDictumButton->hide();

    meetsClicks=0;
    noMeetsClicks=0;

    tableWidget->setColumnCount(5);
    tableWidget->setHorizontalHeaderLabels(QString("Item;Aspecto a Evaluar;Aplica;Cumple;No Cumple").split(";"));
    tableWidget->verticalHeader()->hide();
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    tableWidget->horizontalHeader()->resizeSection(0,35);
    tableWidget->horizontalHeader()->resizeSection(1,495);
    tableWidget->horizontalHeader()->resizeSection(2,50);
    tableWidget->horizontalHeader()->resizeSection(3,50);
    tableWidget->horizontalHeader()->resizeSection(4,70);

    if (!DbHandler::getRequirements(inspectionData.at(1), requirementsData)) {
        QMessageBox::critical(this, trUtf8("Sin Datos"),
                              trUtf8("Error obteniendo los requerimientos\n"
                                     "ejecute el programa bajo consola y \n"
                                     "revise los mensajes"),
                              QMessageBox::Cancel);
    } else {
        tableWidget->setRowCount(requirementsData.at(1).size()); // Creo tantas filas como tamaño tengan los requerimientos

        for (int i=0; i < requirementsData.at(1).size(); i++) {
            // Cada documento creo un checkbox nuevo y le asigno de texto el nombre del documento
            QCheckBox *applyCheckBox = new QCheckBox;
            QCheckBox *meetsCheckBox = new QCheckBox;
            QCheckBox *noMeetsCheckBox = new QCheckBox;

            applyCheckBox->setChecked(true);
            meetsCheckBox->setChecked(true);

            QSignalMapper* signalMapper1 = new QSignalMapper(this); // Necesario usar mapeo de la señal de cada CheckBox
            QSignalMapper* signalMapper2 = new QSignalMapper(this);
            QSignalMapper* signalMapper3 = new QSignalMapper(this);
            // Conectando la señal de cambio de estado con el slot del signalMapper
            connect(applyCheckBox, SIGNAL(toggled(bool)), signalMapper1, SLOT(map())) ;
            connect(meetsCheckBox, SIGNAL(toggled(bool)), signalMapper2, SLOT(map())) ;
            connect(noMeetsCheckBox, SIGNAL(toggled(bool)), signalMapper3, SLOT(map())) ;
            // Ligando el índice del checkbox en la lista con sigo mismo para enviarlo a través del signalMapper
            signalMapper1->setMapping(applyCheckBox, i) ;
            signalMapper2->setMapping(meetsCheckBox, i);
            signalMapper3->setMapping(noMeetsCheckBox, i);
            // Conectando el signalMapper con el slot para ajustar los checkbox de la otra lista
            connect(signalMapper1, SIGNAL(mapped(int)), this, SLOT(setAllMeetsCheckboxes(int))) ;
            connect(signalMapper2, SIGNAL(mapped(int)), this, SLOT(setNoMeetsCheckboxes(int))) ;
            connect(signalMapper3, SIGNAL(mapped(int)), this, SLOT(setMeetsCheckboxes(int))) ;

            applyCheckBoxes.append(applyCheckBox);
            meetsCheckBoxes.append(meetsCheckBox);
            noMeetsCheckBoxes.append(noMeetsCheckBox);

            tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
            tableWidget->setItem(i,1,new QTableWidgetItem(requirementsData.at(1).at(i)));
            tableWidget->setCellWidget(i,2,applyCheckBoxes.at(i));
            tableWidget->setCellWidget(i,3,meetsCheckBoxes.at(i));
            tableWidget->setCellWidget(i,4,noMeetsCheckBoxes.at(i));
        }
    }

    if (dictumOption == "newDictum") {
        styleWithoutData();
        newDictum(inspectionData.at(2));
    }
     else {
        // Hay que obtener los datos extra y llenar los controles
        if (!DbHandler::getExtraData(dictumData.at(0), inspectionData.at(1), extraData))
            qDebug() << trUtf8("DbHandler::getExtraData devolvió false al intentar obtener los datos extra");
        styleWithData();
        fillDictumData();
    }

}

// NOTE: Funciones para manejar el comportamiento de los CheckBox
void DictumForm::setAllMeetsCheckboxes(int i)
{
    meetsCheckBoxes.at(i)->blockSignals(true);
    noMeetsCheckBoxes.at(i)->blockSignals(true);

    if (applyCheckBoxes.at(i)->checkState()==Qt::Checked) {
        meetsCheckBoxes.at(i)->setChecked(true);
        noMeetsCheckBoxes.at(i)->setChecked(false);
    } else {
        meetsCheckBoxes.at(i)->setChecked(false);
        noMeetsCheckBoxes.at(i)->setChecked(false);
    }

    meetsCheckBoxes.at(i)->blockSignals(false);
    noMeetsCheckBoxes.at(i)->blockSignals(false);
}

void DictumForm::setNoMeetsCheckboxes(int i)
{

    noMeetsCheckBoxes.at(i)->blockSignals(true);
    meetsCheckBoxes.at(i)->blockSignals(true);

    if (applyCheckBoxes.at(i)->checkState()==Qt::Checked) {
        if (meetsCheckBoxes.at(i)->checkState()==Qt::Checked)
            noMeetsCheckBoxes.at(i)->setChecked(false);
        else
            noMeetsCheckBoxes.at(i)->setChecked(true);
    } else {
        noMeetsClicks+=1;
        if (noMeetsClicks > 3) {
            QMessageBox::information(this, trUtf8("Ayuda"),
                                  trUtf8("El requerimiento debe aplicar para\n"
                                         "poder marcarlo como 'Cumple'"),
                                  QMessageBox::Ok);
            noMeetsClicks=0;
        }
        meetsCheckBoxes.at(i)->setChecked(false);
        noMeetsCheckBoxes.at(i)->setChecked(false);
    }

    noMeetsCheckBoxes.at(i)->blockSignals(false);
    meetsCheckBoxes.at(i)->blockSignals(false);
}

void DictumForm::setMeetsCheckboxes(int i)
{
    noMeetsCheckBoxes.at(i)->blockSignals(true);
    meetsCheckBoxes.at(i)->blockSignals(true);

    if (applyCheckBoxes.at(i)->checkState()==Qt::Checked) {
        if (noMeetsCheckBoxes.at(i)->checkState()==Qt::Checked)
            meetsCheckBoxes.at(i)->setChecked(false);
        else
            meetsCheckBoxes.at(i)->setChecked(true);
    } else {
        meetsClicks+=1;
        if (meetsClicks > 3) {
            QMessageBox::information(this, trUtf8("Ayuda"),
                                  trUtf8("El requerimiento debe aplicar para\n"
                                         "poder marcarlo como 'No Cumple'"),
                                  QMessageBox::Ok);
            meetsClicks=0;
        }
        meetsCheckBoxes.at(i)->setChecked(false);
        noMeetsCheckBoxes.at(i)->setChecked(false);
    }

    noMeetsCheckBoxes.at(i)->blockSignals(false);
    meetsCheckBoxes.at(i)->blockSignals(false);
}


// NOTE: Ajustar todo para un nuevo dictamen
void DictumForm::newDictum(QString processName)
{
    dictumNumberLineEdit->setText("RIG-IE-");
    dictumProcessLineEdit->setText(processName);
    dictumStateLineEdit->setText("En Proceso");
    dictumInstRateDoubleSpinBox->setValue(8.3);
    dictumInstVoltageLineEdit->setText("110/220");
    dictumInstResDoubleSpinBox->setValue(4.7);
    dictumDateEdit->setDate(QDate::currentDate());
    dictumInstDateEdit->setDate(QDate::currentDate());
    subDictumsComboBox->clear();
    dictumScopeTextEdit->setText(inspectionData.at(3));
    dictumObservTextEdit->setText(inspectionData.at(4));
    previewDictumButton->setEnabled(false);
}

// NOTE: Procesar dictamen.
void DictumForm::processDictum()
{
    if (validateData()) {
        QStringList reqIds, reqMeets, reqNoMeets;
        bool agree=false;

        // Se recorren hasta que se encuentre algún No Cumple chequeado
        for (int i=0; i<noMeetsCheckBoxes.size();i++) {
            if (noMeetsCheckBoxes.at(i)->checkState() == Qt::Checked) {
                agree=false;
                break;
            } else
                agree=true;
        }

        // Se guardan los ids de los requerimientos y su estado
        for (int i=0; i<applyCheckBoxes.size();i++) {
            if (applyCheckBoxes.at(i)->checkState() == Qt::Checked) {
                reqIds.append(requirementsData.at(0).at(i));

                if (meetsCheckBoxes.at(i)->checkState() == Qt::Checked)
                    reqMeets.append("X");
                else
                    reqMeets.append("_");

                if (noMeetsCheckBoxes.at(i)->checkState() == Qt::Checked)
                    reqNoMeets.append("X");
                else
                    reqNoMeets.append("_");
                // Se guardan tal como deben quedar en el dictamen
            }
        }

        if (agree) {
            int ret1=QMessageBox::information(this, trUtf8("Dictamen Conforme"),
                                              trUtf8("El dictamen se guardará como Conforme\n"
                                                     "Presione Si para guardarlo o Cancelar para corregir"),
                                              QMessageBox::Yes | QMessageBox::Cancel);
            if (ret1==QMessageBox::Yes)
                insertDictum("Conforme", reqIds, reqMeets, reqNoMeets);
        } else {
            int ret2=QMessageBox::warning(this, trUtf8("Dictamen No Conforme"),
                                          trUtf8("El dictamen se guardará como No Conforme\n"
                                                 "Presione Si para guardarlo o Cancelar para corregir"),
                                          QMessageBox::Yes | QMessageBox::Cancel);
            if (ret2==QMessageBox::Yes)
                insertDictum("No Conforme", reqIds, reqMeets, reqNoMeets);
        }
    }

}

// NOTE: insercion de dictamen
void DictumForm::insertDictum(QString techState, QStringList reqIds, QStringList reqMeets, QStringList reqNoMeets)
{
    QString dictumId, dictumCode;
    QStringList dictumInsertData, usedData;
    QList<QStringList> reqResults;
    bool isPkViolation;

    reqResults.append(reqIds);
    reqResults.append(reqMeets);
    reqResults.append(reqNoMeets);

    dictumReqsData=reqResults;

    dictumInsertData.append(dictumNumberLineEdit->text());
    dictumInsertData.append(dictumDateEdit->date().toString("yyyy-MM-dd"));
    dictumInsertData.append("Finalizada");
    dictumInsertData.append(techState);
    dictumInsertData.append(dictumScopeTextEdit->toPlainText());
    dictumInsertData.append(dictumObservTextEdit->toPlainText());
    dictumInsertData.append(QString::number(dictumInstRateDoubleSpinBox->value()));
    dictumInsertData.append(dictumInstVoltageLineEdit->text());
    dictumInsertData.append(QString::number(dictumInstResDoubleSpinBox->value()));
    dictumInsertData.append(dictumInstDateEdit->date().toString("yyyy-MM-dd"));
    dictumInsertData.append(inspectionData.at(1)); // id de proceso
    dictumInsertData.append(inspectionData.at(0)); // id de inspección

    // Bloque para almacenar lista de usos para cualquier uso de red o instalación
    QStringList dictumUseIds;
    QStringList dictumUseSnames;

    QList<QStringList> dictumUseData;
//    for (int i=0; i<dictumUseComboBox->count(); i++)
//        // Revisar si está chequeado ....
//        if (dictumUseComboBox->itemCheckState(i)==Qt::Checked) {
//        // ... si lo está introducir el id del uso chequeado
//            dictumUseIds.append(usesData.at(0).at(i));
//            if (usesData.at(1).at(i)=="Especiales")
//                dictumUseSnames.append(dictumUseSnameLineEdit->text());
//            else
//                dictumUseSnames.append(""); // Si no es Especiales lleva vacío
//        }
    dictumUseData.append(dictumUseIds);
    dictumUseData.append(dictumUseSnames);

    // Bloque para almacenar datos para distintos procesos
    QStringList dictumProcIds;
    QStringList genInsertData, transmInsertData, transfInsertData, distInsertData, alExtInsertData;
    QStringList extraData;

    switch (inspectionData.at(1).toInt()) {
    case BcProcs::Generacion:
        // Se almacenan los procesos asociados
//        for (int i=0; i<genAssociatedProcsComboBox->count(); i++)
//            // Revisar si está chequeado ....
//            if (genAssociatedProcsComboBox->itemCheckState(i)==Qt::Checked) {
//            // ... si lo está introducir el id del uso chequeado
//                dictumProcIds.append(processesData.at(0).at(i));
//            }
        // Se almacenan datos adicionales respectivos de Generación
        genInsertData.append(genSeTypeComboBox->currentText());
        genInsertData.append(QString::number(genSesNumberSpinBox->value()));

        extraData=genInsertData;
        break;

    case BcProcs::Transmision:
        // Se almacenan los procesos asociados
//        for (int i=0; i<transmAssociatedProcsComboBox->count(); i++)
//            // Revisar si está chequeado ....
//            if (transmAssociatedProcsComboBox->itemCheckState(i)==Qt::Checked) {
//            // ... si lo está introducir el id del uso chequeado
//                dictumProcIds.append(processesData.at(0).at(i));
//            }
        // Se almacenan datos adicionales respectivos de Transmisión
        transmInsertData.append(transmLineDetailsLineEdit->text());
        transmInsertData.append(transmConfLineEdit->text());
        transmInsertData.append(QString::number(transmLengthSpinbox->value()));
        transmInsertData.append(transmWiresTypeLineEdit->text());
        transmInsertData.append(transmMaterialLineEdit->text());
        transmInsertData.append(QString::number(transmStructsNumberSpinBox->value()));

        extraData=transmInsertData;
        break;

    case BcProcs::Transformacion:
        // Se almacenan los procesos asociados
//        for (int i=0; i<transfAssociatedProcsComboBox->count(); i++)
//            // Revisar si está chequeado ....
//            if (transfAssociatedProcsComboBox->itemCheckState(i)==Qt::Checked) {
//            // ... si lo está introducir el id del uso chequeado
//                dictumProcIds.append(processesData.at(0).at(i));
//            }
        // Se almacenan datos adicionales respectivos de Transformación
        transfInsertData.append(transfSeTypeComboBox->currentText());
        transfInsertData.append(QString::number(transfRateSpinBox->value()));
        transfInsertData.append(QString::number(transfTransfNumberSpinBox->value()));

        extraData=transfInsertData;
        break;

    case BcProcs::Distribucion:
        distInsertData.append(distConfComboBox->currentText());
        distInsertData.append(QString::number(distLengthSpinbox->value()));
        distInsertData.append(distWiresTypeLineEdit->text());
        distInsertData.append(distMaterialLineEdit->text());
        distInsertData.append(QString::number(distStructsNumberSpinBox->value()));

        extraData=distInsertData;
        break;

    case BcProcs::AlumbradoExt:
        alExtInsertData.append(QString::number(alExtLumNumberSpinBox->value()));
        alExtInsertData.append(alExtMeasureSystemComboBox->currentText());
        alExtInsertData.append(alExtInstObjectComboBox->currentText());
        alExtInsertData.append(QString::number(alExtLengthSpinBox->value()));
        alExtInsertData.append(QString::number(alExtAreaSpinBox->value()));

        extraData=alExtInsertData;
        break;

    }

    if (!DbHandler::insertDictum(dictumInsertData, extraData, reqResults, dictumId,
                                 isPkViolation, dictumCode, usedData, dictumUseData, dictumProcIds))
        if (isPkViolation) {
            QMessageBox::warning(this, trUtf8("Dictamen ya existe"),
                                 trUtf8("El número de Hoja o Dictamen ya está en uso por la Órden \n"
                                        "de Servicio:" + usedData.at(0).toUtf8() + ", en la Inspección: "
                                        + usedData.at(1).toUtf8() + ", para el proceso de:" + usedData.at(2).toUtf8()),
                                 QMessageBox::Ok);
        } else
            QMessageBox::critical(this, trUtf8("Error insertanto datos"),
                                  trUtf8("Error insertando el dictamen. Ejecute el\n"
                                         "programa bajo consola y revise los mensajes"),
                                  QMessageBox::Cancel);
    else {
        styleWithData();
        freshDictumId=dictumId;
        dictumData=dictumInsertData;
        // Completo la lista con los valores que no se conocían antes de insertar, esto envía la lista completa a rendeo
        dictumData.prepend(dictumId);
        dictumData.insert(1, dictumCodeLineEdit->text());
        dictumCodeLineEdit->setText("RI-"+dictumCode);
        dictumTechStateLineEdit->setText(techState);
        getSubDictums();
        QMessageBox::information(this, trUtf8("Dictamen Guardado"),
                                 trUtf8("Se ha guardado el dictamen " + dictumNumberLineEdit->text().toUtf8() + " correctamente"),
                                 QMessageBox::Ok);
    }
}

// NOTE: Guardar cambios de dictamen.
void DictumForm::saveDictum()
{
    if (validateData()) {
        QStringList reqIds, reqMeets, reqNoMeets;
        bool agree=false;

        // Se recorren hasta que se encuentre algún No Cumple chequeado
        for (int i=0; i<noMeetsCheckBoxes.size();i++) {
            if (noMeetsCheckBoxes.at(i)->checkState() == Qt::Checked) {
                agree=false;
                break;
            } else
                agree=true;
        }

        // Se guardan los ids de los requerimientos y su estado
        for (int i=0; i<applyCheckBoxes.size();i++) {
            if (applyCheckBoxes.at(i)->checkState() == Qt::Checked) {
                reqIds.append(requirementsData.at(0).at(i));

                if (meetsCheckBoxes.at(i)->checkState() == Qt::Checked)
                    reqMeets.append("X");
                else
                    reqMeets.append("_");

                if (noMeetsCheckBoxes.at(i)->checkState() == Qt::Checked)
                    reqNoMeets.append("X");
                else
                    reqNoMeets.append("_");
                // Se guardan tal como deben quedar en el dictamen
            }
        }

        if (agree) {
            int ret1=QMessageBox::information(this, trUtf8("Dictamen Conforme"),
                                              trUtf8("El dictamen se actualizará como Conforme\n"
                                                     "Presione Si para actualizarlo o Cancelar para corregir"),
                                              QMessageBox::Yes | QMessageBox::Cancel);
            if (ret1==QMessageBox::Yes)
               updateDictum("Conforme", reqIds, reqMeets, reqNoMeets);
        } else {
            int ret2=QMessageBox::warning(this, trUtf8("Dictamen No Conforme"),
                                          trUtf8("El dictamen se actualizará como No Conforme\n"
                                                 "Presione Si para actualizarlo o Cancelar para corregir"),
                                          QMessageBox::Yes | QMessageBox::Cancel);
            if (ret2==QMessageBox::Yes)
                updateDictum("No Conforme", reqIds, reqMeets, reqNoMeets);
        }
    }

}

// NOTE: actualizar dictamen
void DictumForm::updateDictum(QString techState, QStringList reqIds, QStringList reqMeets, QStringList reqNoMeets)
{
    QStringList dictumUpdateData;
    QList<QStringList> reqResults;

    reqResults.append(reqIds);
    reqResults.append(reqMeets);
    reqResults.append(reqNoMeets);

    dictumReqsData=reqResults;

    dictumUpdateData.append(dictumData.at(0));
    dictumUpdateData.append(dictumDateEdit->date().toString("yyyy-MM-dd"));
    dictumUpdateData.append("Finalizado");
    dictumUpdateData.append(techState);
    dictumUpdateData.append(dictumScopeTextEdit->toPlainText());
    dictumUpdateData.append(dictumObservTextEdit->toPlainText());
    dictumUpdateData.append(QString::number(dictumInstRateDoubleSpinBox->value()));
    dictumUpdateData.append(dictumInstVoltageLineEdit->text());
    dictumUpdateData.append(QString::number(dictumInstResDoubleSpinBox->value()));
    dictumUpdateData.append(dictumInstDateEdit->date().toString("yyyy-MM-dd"));
    dictumUpdateData.append(inspectionData.at(1));

    // Bloque para almacenar lista de usos
    QStringList dictumUseIds;
    QStringList dictumUseSnames;

    QList<QStringList> dictumUseData;

//    for (int i=0; i<dictumUseComboBox->count(); i++)
//        // Revisar si está chequeado ....
//        if (dictumUseComboBox->itemCheckState(i)==Qt::Checked) {
//        // ... si lo está introducir el id del uso chequeado
//            dictumUseIds.append(usesData.at(0).at(i));
//            if (usesData.at(1).at(i)=="Especiales")
//                dictumUseSnames.append(dictumUseSnameLineEdit->text());
//            else
//                dictumUseSnames.append(""); // Si no es Especiales lleva vacío
//        }
    dictumUseData.append(dictumUseIds);
    dictumUseData.append(dictumUseSnames);

    // Bloque para almacenar datos para distintos procesos
    QStringList dictumProcIds;
    QStringList genUpdateData, transmUpdateData, transfUpdateData, distUpdateData, alExtUpdateData;
    QStringList extraData;

    switch (inspectionData.at(1).toInt()) {
    case BcProcs::Generacion:
        // Se almacenan los procesos asociados
//        for (int i=0; i<genAssociatedProcsComboBox->count(); i++)
//            // Revisar si está chequeado ....
//            if (genAssociatedProcsComboBox->itemCheckState(i)==Qt::Checked) {
//            // ... si lo está introducir el id del uso chequeado
//                dictumProcIds.append(processesData.at(0).at(i));
//            }
        // Se almacenan datos adicionales respectivos de Generación
        genUpdateData.append(genSeTypeComboBox->currentText());
        genUpdateData.append(QString::number(genSesNumberSpinBox->value()));

        extraData=genUpdateData;
        break;

    case BcProcs::Transmision:
        // Se almacenan los procesos asociados
//        for (int i=0; i<transmAssociatedProcsComboBox->count(); i++)
//            // Revisar si está chequeado ....
//            if (transmAssociatedProcsComboBox->itemCheckState(i)==Qt::Checked) {
//            // ... si lo está introducir el id del uso chequeado
//                dictumProcIds.append(processesData.at(0).at(i));
//            }

        // Se almacenan datos adicionales respectivos de Transmisión
        transmUpdateData.append(transmLineDetailsLineEdit->text());
        transmUpdateData.append(transmConfLineEdit->text());
        transmUpdateData.append(QString::number(transmLengthSpinbox->value()));
        transmUpdateData.append(transmWiresTypeLineEdit->text());
        transmUpdateData.append(transmMaterialLineEdit->text());
        transmUpdateData.append(QString::number(transmStructsNumberSpinBox->value()));

        extraData=transmUpdateData;
        break;

    case BcProcs::Transformacion:
//        // Se almacenan los procesos asociados
//        for (int i=0; i<transfAssociatedProcsComboBox->count(); i++)
//            // Revisar si está chequeado ....
//            if (transfAssociatedProcsComboBox->itemCheckState(i)==Qt::Checked) {
//            // ... si lo está introducir el id del uso chequeado
//                dictumProcIds.append(processesData.at(0).at(i));
//            }
        // Se almacenan datos adicionales respectivos de Transformación
        transfUpdateData.append(transfSeTypeComboBox->currentText());
        transfUpdateData.append(QString::number(transfRateSpinBox->value()));
        transfUpdateData.append(QString::number(transfTransfNumberSpinBox->value()));

        extraData=transfUpdateData;
        break;

    case BcProcs::Distribucion:
        distUpdateData.append(distConfComboBox->currentText());
        distUpdateData.append(QString::number(distLengthSpinbox->value()));
        distUpdateData.append(distWiresTypeLineEdit->text());
        distUpdateData.append(distMaterialLineEdit->text());
        distUpdateData.append(QString::number(distStructsNumberSpinBox->value()));

        extraData=distUpdateData;
        break;

    case BcProcs::AlumbradoExt:
        alExtUpdateData.append(QString::number(alExtLumNumberSpinBox->value()));
        alExtUpdateData.append(alExtMeasureSystemComboBox->currentText());
        alExtUpdateData.append(alExtInstObjectComboBox->currentText());
        alExtUpdateData.append(QString::number(alExtLengthSpinBox->value()));
        alExtUpdateData.append(QString::number(alExtAreaSpinBox->value()));

        extraData=alExtUpdateData;
        break;

    }

    if (!DbHandler::updateDictum(dictumUpdateData, extraData, reqResults, dictumUseData, dictumProcIds))
        QMessageBox::warning(this, trUtf8("Error actualizando datos"),
                             trUtf8("Error actualizando el dictamen. Ejecute el\n"
                                    "programa bajo consola y revise los mensajes"),
                             QMessageBox::Cancel);
    else {
        dictumData=dictumUpdateData;
        // Completo la lista con los valores que no se actualizan, esto envía la lista completa a rendeo
        dictumData.insert(1, dictumNumberLineEdit->text());
        dictumData.insert(2, dictumCodeLineEdit->text());
        dictumTechStateLineEdit->setText(techState);
        styleWithData();
        QMessageBox::information(this, trUtf8("Dictamen Actualizado"),
                                 trUtf8("Se ha actualizado el dictamen " + dictumNumberLineEdit->text().toUtf8() + " correctamente"),
                                 QMessageBox::Ok);
        }
}

// NOTE: llenado de datos del dictamen
void DictumForm::fillDictumData()
{
    dictumNumberLineEdit->setText(dictumData.at(1));
    dictumCodeLineEdit->setText("RI-"+dictumData.at(2));
    dictumDateEdit->setDate(QDate::fromString(dictumData.at(3), "yyyy-MM-dd"));
    dictumStateLineEdit->setText(dictumData.at(4));
    dictumTechStateLineEdit->setText(dictumData.at(5));
    dictumScopeTextEdit->setHtml(dictumData.at(6));
    dictumObservTextEdit->setHtml(dictumData.at(7));
    dictumInstRateDoubleSpinBox->setValue(dictumData.at(8).toDouble());
    dictumInstVoltageLineEdit->setText(dictumData.at(9));
    dictumInstResDoubleSpinBox->setValue(dictumData.at(10).toDouble());
    dictumInstDateEdit->setDate(QDate::fromString(dictumData.at(11), "yyyy-MM-dd"));
    dictumProcessLineEdit->setText(processesData.at(1).at(processesData.at(0).indexOf(dictumData.at(13)))); // Id de proceso

    // En este caso
    switch (inspectionData.at(1).toInt()) {
    case BcProcs::Generacion:
        genSeTypeComboBox->setCurrentIndex(genSeTypeComboBox->findText(extraData.at(0)));
        genSesNumberSpinBox->setValue(extraData.at(1).toInt());

        break;

    case BcProcs::Transmision:
        transmLineDetailsLineEdit->setText(extraData.at(0));
        transmConfLineEdit->setText(extraData.at(1));
        transmLengthSpinbox->setValue(extraData.at(2).toInt());
        transmWiresTypeLineEdit->setText(extraData.at(3));
        transmMaterialLineEdit->setText(extraData.at(4));
        transmStructsNumberSpinBox->setValue(extraData.at(5).toInt());

        break;

    case BcProcs::Transformacion:
        transfSeTypeComboBox->setCurrentIndex(transfSeTypeComboBox->findText(extraData.at(0)));
        transfRateSpinBox->setValue(extraData.at(1).toDouble());
        transfTransfNumberSpinBox->setValue(extraData.at(2).toInt());

        break;

    case BcProcs::Distribucion:
        distConfComboBox->setCurrentIndex(distConfComboBox->findText(extraData.at(0)));
        distLengthSpinbox->setValue(extraData.at(1).toInt());
        distWiresTypeLineEdit->setText(extraData.at(2));
        distMaterialLineEdit->setText(extraData.at(3));
        distStructsNumberSpinBox->setValue(extraData.at(4).toInt());

        break;

    case BcProcs::AlumbradoExt:
        alExtLumNumberSpinBox->setValue(extraData.at(0).toInt());
        alExtMeasureSystemComboBox->setCurrentIndex(alExtMeasureSystemComboBox->findText(extraData.at(1)));
        alExtInstObjectComboBox->setCurrentIndex(alExtInstObjectComboBox->findText(extraData.at(2)));
        alExtLengthSpinBox->setValue(extraData.at(3).toInt());
        alExtAreaSpinBox->setValue(extraData.at(4).toInt());

    default:
        break; // Para los demás procesos no es neceario.

    }

    // boque para el marcado de usos

//    QList<QStringList> dictumUseData;
//    DbHandler::getDictumUses(dictumData.at(0), dictumUseData);
//    int index;
//    for (int i=0; i<dictumUseData.at(0).size();i++) {
//        index=usesData.at(0).indexOf(dictumUseData.at(0).at(i));
//        dictumUsesComboBox->item(index)->setSelected(true);
//        if (usesData.at(1).at(index)=="Especiales")
//            dictumUseSpecialNameLineEdit->setText(dictumUseData.at(1).at(i));
//    }


    // boque para el marcado de procesos de dictamen
    QStringList dictumProcIds;
    DbHandler::getDictumProcs(dictumData.at(0), dictumProcIds);

//    for (int i=0; i<dictumProcIds.size();i++) {
//        index=processesData.at(0).indexOf(dictumProcIds.at(i));
//        // Los chequeo todos sin importar que se estén mostrando o no de acuerdo al proceso.
//        genAssociatedProcsComboBox->setItemCheckState(index, Qt::Checked);
//        transmAssociatedProcsComboBox->setItemCheckState(index, Qt::Checked);
//        transfAssociatedProcsComboBox->setItemCheckState(index, Qt::Checked);
//    }

    if (!DbHandler::getDictumReqs(dictumData.at(0), dictumReqsData))
        QMessageBox::warning(this, trUtf8("Error obteniendo datos"),
                             trUtf8("Error obteniendo requerimientos guardados. Ejecute el\n"
                                    "programa bajo consola y revise los mensajes"),
                             QMessageBox::Cancel);
    else {
        int index;
        for (int i=0; i<dictumReqsData.at(0).size();i++) {
            // indexOf me entrega la posición en la que está el id del documento, con esa posición
            // reemplazo el string vacío por el nombre del documento
            index=requirementsData.at(0).indexOf(dictumReqsData.at(0).at(i));
            if (index >=0) { // para prevenir el -1 al no encontrar el Id
                applyCheckBoxes.at(index)->setChecked(true);

                if (dictumReqsData.at(1).at(i) == "_")
                    meetsCheckBoxes.at(index)->setChecked(false);

                // No es necesario checkear el no cumple ya que está controlado por el disparo de la señal
            }
        }
        getSubDictums();
    }
}

// Obtiene subdicamen o consecutivos
void DictumForm::getSubDictums()
{
    QString dictumId;
    if (freshDictumId.size()!=0) // Su tamaño será sero en caso de tratarse de dictamen existente
        dictumId=freshDictumId;
    else
        dictumId=dictumData.at(0);

    if(!DbHandler::getSubDictums(dictumId, subDictumsData)) {
        subDictumsComboBox->clear();
        subDictumsComboBox->addItem("Sin Consecutivos");
        subDictumsComboBox->setEnabled(false);
        goSubDictumButton->setEnabled(false);
        newSubDictumButton->setEnabled(true);

    } else {
        subDictumsComboBox->clear();
        subDictumsComboBox->addItems(subDictumsData.at(1));
        subDictumsComboBox->setEnabled(true);
        goSubDictumButton->setEnabled(true);
        newSubDictumButton->setEnabled(true);
    }
}

// Valida que los datos de entrada esten completos
bool DictumForm::validateData()
{
    if (dictumNumberLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El Número de Dictamen u Hoja es obligatorio"),
                             QMessageBox::Ok);
        dictumNumberLineEdit->setFocus();
        return false;
    }

    // Comrobando el formato del número de la hoja
    QString text(dictumNumberLineEdit->text());
    if (!text.startsWith("RIG-IE-") || text.size() < 8) {
        QMessageBox::warning(this, trUtf8("Formato Incorrecto"),
                             trUtf8("El formato de la hoja debe empezar\n"
                                    "con RIG-IE- seguido de números enteros"),
                             QMessageBox::Ok);
        dictumNumberLineEdit->setFocus();
        return false;
    } else
        for (int i=7; i < text.size(); i++)
            if (!text.at(i).isNumber()) {
                QMessageBox::warning(this, trUtf8("Formato Incorrecto"),
                                     trUtf8("Solo se admiten números enteros después de RIG-IE-"),
                                     QMessageBox::Ok);
                dictumNumberLineEdit->setFocus();
                return false;
            }

    if (dictumInstRateDoubleSpinBox->value()==0) {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("La potencia no debe ser cero"),
                             QMessageBox::Ok);
        dictumInstRateDoubleSpinBox->setFocus();
        return false;
    }

    if (dictumInstVoltageLineEdit->text()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("La tensión no debe ser cero"),
                             QMessageBox::Ok);
        dictumInstVoltageLineEdit->setFocus();
        return false;
    }

    if (dictumInstResDoubleSpinBox->value()==0) {
        QMessageBox::warning(this, trUtf8("Información"),
                             trUtf8("Resistencia cero implica que la medida no se tomó"),
                             QMessageBox::Ok);
    }

    if (dictumDateEdit->date().year() < dictumInstDateEdit->date().year()) {
        QMessageBox::warning(this, trUtf8("Fechas inválidas"),
                             trUtf8("La fecha de dictamen debe ser mayor o igual al\n"
                                    " año de terminación de la instalación"),
                             QMessageBox::Ok);
        dictumDateEdit->setFocus();
        return false;
    }

    if (dictumDateEdit->date() < QDate::fromString(inspectionData.at(16), "yyyy-MM-dd")) {
        QMessageBox::warning(this, trUtf8("Fechas inválidas"),
                             trUtf8("La fecha de dictamen debe ser mayor o igual a la\n"
                                    "fecha de asignada de inspección de la obra"),
                             QMessageBox::Ok);
        dictumDateEdit->setFocus();
        return false;
    }

    if (dictumScopeTextEdit->toPlainText()=="") {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("El alcance es obligatorio"),
                             QMessageBox::Ok);
        dictumScopeTextEdit->setFocus();
        return false;
    }



    switch (inspectionData.at(1).toInt()) {

    case BcProcs::Generacion:
//        if (genAssociatedProcsComboBox->checkedItems().size()==0) {
//            QMessageBox::warning(this, trUtf8("Faltan Datos"),
//                                 trUtf8("Al menos un proceso asociado debe estar marcado"),
//                                 QMessageBox::Ok);
//            genAssociatedProcsComboBox->setFocus();
//            return false;
//        }

        if (genSesNumberSpinBox->value()==0) {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("El número de subestaciones no puede ser cero"),
                                 QMessageBox::Ok);
            genSesNumberSpinBox->setFocus();
            return false;
        }
        break;

    case BcProcs::Transmision:
//        if (transmAssociatedProcsComboBox->checkedItems().size()==0) {
//            QMessageBox::warning(this, trUtf8("Faltan Datos"),
//                                 trUtf8("Al menos un proceso asociado debe estar marcado"),
//                                 QMessageBox::Ok);
//            transmAssociatedProcsComboBox->setFocus();
//            return false;
//        }

        if (transmLineDetailsLineEdit->text()=="") {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("La descripción de la línea es obligatoria"),
                                 QMessageBox::Ok);
            transmLineDetailsLineEdit->setFocus();
            return false;
        }

        if (transmConfLineEdit->text()=="") {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("La configuración de la línea es obligatoria"),
                                 QMessageBox::Ok);
            transmConfLineEdit->setFocus();
            return false;
        }

        if (transmWiresTypeLineEdit->text()=="") {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("El tipo de conductores de la línea es obligatorio"),
                                 QMessageBox::Ok);
            transmWiresTypeLineEdit->setFocus();
            return false;
        }

        if (transmMaterialLineEdit->text()=="") {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("El tipo de material de las estructuras es obligatorio"),
                                 QMessageBox::Ok);
            transmMaterialLineEdit->setFocus();
            return false;
        }


        if (transmStructsNumberSpinBox->value()==0) {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("El número de apoyos no puede ser cero"),
                                 QMessageBox::Ok);
            transmStructsNumberSpinBox->setFocus();
            return false;
        }

        if (transmLengthSpinbox->value()==0) {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("La longitud de la línea no puede ser cero"),
                                 QMessageBox::Ok);
            transmLengthSpinbox->setFocus();
            return false;
        }

        break;

    case BcProcs::Transformacion:
//        if (transfAssociatedProcsComboBox->checkedItems().size()==0) {
//            QMessageBox::warning(this, trUtf8("Faltan Datos"),
//                                 trUtf8("Al menos un proceso asociado debe estar marcado"),
//                                 QMessageBox::Ok);
//            transfAssociatedProcsComboBox->setFocus();
//            return false;
//        }

        if (transfRateSpinBox->value()==0) {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("La potencia no puede ser cero"),
                                 QMessageBox::Ok);
            transfRateSpinBox->setFocus();
            return false;
        }

        if (transfTransfNumberSpinBox->value()==0) {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("El número de transformadores no puede ser cero"),
                                 QMessageBox::Ok);
            transfTransfNumberSpinBox->setFocus();
            return false;
        }
        break;

    case BcProcs::Distribucion:

        if (distLengthSpinbox->value()==0) {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("La longitud de la red no puede ser cero"),
                                 QMessageBox::Ok);
            distLengthSpinbox->setFocus();
            return false;
        }

        if (distWiresTypeLineEdit->text()=="") {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("El tipo de conductores de la red es obligatorio"),
                                 QMessageBox::Ok);
            distWiresTypeLineEdit->setFocus();
            return false;
        }

        if (distMaterialLineEdit->text()=="") {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("El tipo de material de las estructuras es obligatorio"),
                                 QMessageBox::Ok);
            distMaterialLineEdit->setFocus();
            return false;
        }


        if (distStructsNumberSpinBox->value()==0) {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("El número de apoyos no puede ser cero"),
                                 QMessageBox::Ok);
            distStructsNumberSpinBox->setFocus();
            return false;
        }
        break;

    case BcProcs::AlumbradoExt:
        if (alExtLumNumberSpinBox->value()==0) {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("El número de luminarias no puede ser cero"),
                                 QMessageBox::Ok);
            alExtLumNumberSpinBox->setFocus();
            return false;
        }

        if (alExtLengthSpinBox->value()==0) {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("La longitud total no puede ser cero"),
                                 QMessageBox::Ok);
            alExtLengthSpinBox->setFocus();
            return false;
        }

        if (alExtAreaSpinBox->value()==0) {
            QMessageBox::warning(this, trUtf8("Faltan Datos"),
                                 trUtf8("El área total no puede ser cero"),
                                 QMessageBox::Ok);
            alExtAreaSpinBox->setFocus();
            return false;
        }
        break;

    default:
        break;

    }

    return true;
}

// NOTE: slot para el boton de actualizar
void DictumForm::updateDictumAction()
{
    styleWithoutData();
    saveDictumButton->setEnabled(true);
    processDictumButton->setEnabled(false);
}


// NOTE: configurar estilos si no se retornan datos
void DictumForm::styleWithData()
{
    dictumNumberLineEdit->setStyleSheet("background-color: rgb(200, 200, 200);\n"
                                        "font: 75 oblique 10pt \"DejaVu Sans\";");
    dictumInstRateDoubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                           "font: 75 oblique 10pt \"DejaVu Sans\";"));
    dictumInstVoltageLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                              "font: 75 oblique 10pt \"DejaVu Sans\";"));
    dictumInstResDoubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                          "font: 75 oblique 10pt \"DejaVu Sans\";"));
    dictumDateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                    "font: 75 oblique 10pt \"DejaVu Sans\";"));
    dictumInstDateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                        "font: 75 oblique 10pt \"DejaVu Sans\";"));
    dictumUsesComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                            "font: 75 oblique 10pt \"DejaVu Sans\";"));
    dictumUseSpecialNameLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                            "font: 75 oblique 10pt \"DejaVu Sans\";"));
    genAssociatedProcsComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                                "font: 75 oblique 10pt \"DejaVu Sans\";"));
    genSesNumberSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                         "font: 75 oblique 10pt \"DejaVu Sans\";"));
    transmAssociatedProcsComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                                   "font: 75 oblique 10pt \"DejaVu Sans\";"));
    transmLineDetailsLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                               "font: 75 oblique 10pt \"DejaVu Sans\";"));
    transmConfLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                        "font: 75 oblique 10pt \"DejaVu Sans\";"));
    transmWiresTypeLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                             "font: 75 oblique 10pt \"DejaVu Sans\";"));
    transmMaterialLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                            "font: 75 oblique 10pt \"DejaVu Sans\";"));
    transmStructsNumberSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                                "font: 75 oblique 10pt \"DejaVu Sans\";"));
    transmLengthSpinbox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                         "font: 75 oblique 10pt \"DejaVu Sans\";"));
    transfAssociatedProcsComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                                   "font: 75 oblique 10pt \"DejaVu Sans\";"));
    transfRateSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                       "font: 75 oblique 10pt \"DejaVu Sans\";"));
    transfTransfNumberSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                               "font: 75 oblique 10pt \"DejaVu Sans\";"));
    distLengthSpinbox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                       "font: 75 oblique 10pt \"DejaVu Sans\";"));
    distWiresTypeLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                           "font: 75 oblique 10pt \"DejaVu Sans\";"));
    distMaterialLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                          "font: 75 oblique 10pt \"DejaVu Sans\";"));
    distStructsNumberSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                              "font: 75 oblique 10pt \"DejaVu Sans\";"));
    alExtLumNumberSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                           "font: 75 oblique 10pt \"DejaVu Sans\";"));
    alExtLengthSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                        "font: 75 oblique 10pt \"DejaVu Sans\";"));
    alExtAreaSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
                                                      "font: 75 oblique 10pt \"DejaVu Sans\";"));

    transmLineDetailsLineEdit->setReadOnly(true);
    transmConfLineEdit->setReadOnly(true);
    transmWiresTypeLineEdit->setReadOnly(true);
    transmMaterialLineEdit->setReadOnly(true);
    distWiresTypeLineEdit->setReadOnly(true);
    distMaterialLineEdit->setReadOnly(true);
    dictumNumberLineEdit->setReadOnly(true);
    dictumInstRateDoubleSpinBox->setReadOnly(true);
    dictumInstVoltageLineEdit->setReadOnly(true);
    dictumInstResDoubleSpinBox->setReadOnly(true);
    dictumDateEdit->setReadOnly(true);
    dictumInstDateEdit->setReadOnly(true);
    dictumUseSpecialNameLineEdit->setReadOnly(true);

    dictumScopeTextEdit->setReadOnly(true);
    dictumObservTextEdit->setReadOnly(true);
    processDictumButton->setEnabled(false);

    updateDictumButton->setEnabled(true);
    saveDictumButton->setEnabled(false);
    previewDictumButton->setEnabled(true);
    processDictumButton->setEnabled(false);

    for (int i=0; i<requirementsData.at(0).size();i++) {
        applyCheckBoxes.at(i)->setEnabled(false);
        meetsCheckBoxes.at(i)->setEnabled(false);
        noMeetsCheckBoxes.at(i)->setEnabled(false);
    }

}

void DictumForm::styleWithoutData()
{
    dictumNumberLineEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    dictumInstRateDoubleSpinBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    dictumInstVoltageLineEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    dictumInstResDoubleSpinBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    dictumDateEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    dictumInstDateEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    dictumUsesComboBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    dictumUseSpecialNameLineEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    genAssociatedProcsComboBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    genSesNumberSpinBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    transmAssociatedProcsComboBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    transmLineDetailsLineEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    transmConfLineEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    transmWiresTypeLineEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    transmMaterialLineEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    transmStructsNumberSpinBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    transmLengthSpinbox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    transfAssociatedProcsComboBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    transfRateSpinBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    transfTransfNumberSpinBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    distLengthSpinbox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    distWiresTypeLineEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    distMaterialLineEdit->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    distStructsNumberSpinBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    alExtLumNumberSpinBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    alExtLengthSpinBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");
    alExtAreaSpinBox->setStyleSheet("font: 10pt \"DejaVu Sans\";");

    transmLineDetailsLineEdit->setReadOnly(false);
    transmConfLineEdit->setReadOnly(false);
    transmWiresTypeLineEdit->setReadOnly(false);
    transmMaterialLineEdit->setReadOnly(false);
    distWiresTypeLineEdit->setReadOnly(false);
    distMaterialLineEdit->setReadOnly(false);
    dictumNumberLineEdit->setReadOnly(false);
    dictumInstRateDoubleSpinBox->setReadOnly(false);
    dictumInstVoltageLineEdit->setReadOnly(false);
    dictumInstResDoubleSpinBox->setReadOnly(false);
    dictumDateEdit->setReadOnly(false);
    dictumInstDateEdit->setReadOnly(false);
    dictumUseSpecialNameLineEdit->setReadOnly(false);

    dictumScopeTextEdit->setReadOnly(false);
    dictumObservTextEdit->setReadOnly(false);
    processDictumButton->setEnabled(true);
    previewDictumButton->setEnabled(false);

    updateDictumButton->setEnabled(false);
    saveDictumButton->setEnabled(false);

    for (int i=0; i<requirementsData.at(0).size();i++) {
        applyCheckBoxes.at(i)->setEnabled(true);
        meetsCheckBoxes.at(i)->setEnabled(true);
        noMeetsCheckBoxes.at(i)->setEnabled(true);
    }

    subDictumsComboBox->setEnabled(false);
    goSubDictumButton->setEnabled(false);
    newSubDictumButton->setEnabled(false);
}

// NOTE: nuevo subdictamen
void DictumForm::newSubDictum()
{
    QStringList dictum_Data;

    if (freshDictumId.size()!=0)  // Su tamaño será sero en caso de tratarse de dictamen existente
        dictum_Data.append(freshDictumId);
    else
        dictum_Data.append(dictumData.at(0));

    dictum_Data.append(dictumNumberLineEdit->text());
    dictum_Data.append(inspectionData.at(1));
    dictum_Data.append(dictumScopeTextEdit->toPlainText());
    dictum_Data.append(dictumObservTextEdit->toPlainText());

    SubDictumForm subDictumForm("newSubDictum", subDictumsComboBox->currentIndex(), subDictumsData, dictum_Data, dictumReqsData, this);
    subDictumForm.exec();
    getSubDictums(); // Aquí es necesario para refrescar el lineedit del número de dictamen.
}

// NOTE: ir a subdictamen
void DictumForm::goSubDictum()
{
    QStringList dictum_Data;

    if (freshDictumId.size()!=0)  // Su tamaño será sero en caso de tratarse de dictamen existente
        dictum_Data.append(freshDictumId);
    else
        dictum_Data.append(dictumData.at(0));

    dictum_Data.append(dictumNumberLineEdit->text());
    dictum_Data.append(inspectionData.at(1));
    dictum_Data.append(dictumScopeTextEdit->toPlainText());
    dictum_Data.append(dictumObservTextEdit->toPlainText());
    dictum_Data.append(inspectionData.at(5));

    SubDictumForm subDictumForm("goSubDictum", subDictumsComboBox->currentIndex(), subDictumsData, dictum_Data, dictumReqsData, this);
    subDictumForm.exec();
    subDictumForm.labelSubDictums->hide();
    subDictumForm.subDictumsNumberSpinBox->hide();
    subDictumForm.prepareListButton->hide();
    getSubDictums(); // Aquí es necesario para refrescar el lineedit del número de dictamen.
}

void DictumForm::previewDictum()
{
    RenderDictumForm renderDictumForm(inspectionData, dictumData, dictumReqsData, this);
    renderDictumForm.exec();
}

void DictumForm::launchUsesFilter(QString itemStr)
{
    if (itemStr == QString("Agregar ó editar usos ..."))

        filterUsesDialog->exec();
}

void DictumForm::changeFilterRegExp(QString RegExp)
{
    proxyModel->setFilterRegExp(QRegExp(RegExp, Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(0);
}
