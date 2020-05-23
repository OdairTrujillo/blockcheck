/********************************************************************************
** Form generated from reading UI file 'dictum.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICTUM_H
#define UI_DICTUM_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_dictumForm
{
public:
    QGridLayout *gridLayout;
    QPushButton *processDictumButton;
    QGridLayout *alExtGridLayout;
    QLabel *alExtLumNumberLabel;
    QLabel *alExtMeasureSystemLabel;
    QLabel *alExtInstObjectLabel;
    QLabel *alExtLengthLabel;
    QLabel *alExtAreaLabel;
    QSpinBox *alExtLumNumberSpinBox;
    QComboBox *alExtMeasureSystemComboBox;
    QComboBox *alExtInstObjectComboBox;
    QSpinBox *alExtLengthSpinBox;
    QSpinBox *alExtAreaSpinBox;
    QGridLayout *genGridLayout;
    QSpinBox *genSesNumberSpinBox;
    QComboBox *genAssociatedProcsComboBox;
    QComboBox *genSeTypeComboBox;
    QLabel *genAssociatedProcsLabel;
    QLabel *genSeTypeLabel;
    QLabel *genSesNumberLabel;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_15;
    QTextEdit *dictumObservTextEdit;
    QTextEdit *dictumScopeTextEdit;
    QLabel *label_14;
    QGroupBox *reqOutGroupBox;
    QGridLayout *gridLayout_4;
    QTableWidget *tableWidget;
    QLineEdit *dictumCodeLineEdit;
    QGridLayout *transfGridLayout;
    QLabel *transfRateLabel;
    QLabel *transfTransfNumberLabel;
    QDoubleSpinBox *transfRateSpinBox;
    QSpinBox *transfTransfNumberSpinBox;
    QComboBox *transfAssociatedProcsComboBox;
    QLabel *transfAssociatedProcsLabel;
    QLabel *transfSeTypeLabel;
    QComboBox *transfSeTypeComboBox;
    QGridLayout *distGridLayout;
    QLabel *distLenghtLabel;
    QLabel *distWiresTypeLabel;
    QLabel *distStructsNumberLabel;
    QLabel *distConfLabel;
    QLabel *distMaterialLabel;
    QLineEdit *distMaterialLineEdit;
    QSpinBox *distStructsNumberSpinBox;
    QLineEdit *distWiresTypeLineEdit;
    QSpinBox *distLengthSpinbox;
    QComboBox *distConfComboBox;
    QGroupBox *menuGroupBox;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *dictumNumberLineEdit;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *updateDictumButton;
    QPushButton *saveDictumButton;
    QPushButton *previewDictumButton;
    QGridLayout *buttonsGridLayout;
    QLabel *subDictumsLabel;
    QComboBox *subDictumsComboBox;
    QPushButton *goSubDictumButton;
    QPushButton *newSubDictumButton;
    QGridLayout *transmGridLayout;
    QLabel *transmLengthLabel;
    QLineEdit *transmWiresTypeLineEdit;
    QLabel *transmConfLabel;
    QLabel *transmWiresTypeLabel;
    QComboBox *transmAssociatedProcsComboBox;
    QLabel *transmAssociatedProcsLineEdit;
    QLineEdit *transmConfLineEdit;
    QSpinBox *transmLengthSpinbox;
    QLabel *transmLineDetailsLabel;
    QLineEdit *transmLineDetailsLineEdit;
    QLabel *transmMaterialLabel;
    QLineEdit *transmMaterialLineEdit;
    QLabel *transmStructsNumberLabel;
    QSpinBox *transmStructsNumberSpinBox;
    QGridLayout *fusGridLayout;
    QLabel *label_12;
    QLabel *label_11;
    QLineEdit *dictumProcessLineEdit;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label;
    QLabel *label_6;
    QDateEdit *dictumDateEdit;
    QDateEdit *dictumInstDateEdit;
    QLineEdit *dictumStateLineEdit;
    QLineEdit *dictumInstVoltageLineEdit;
    QLineEdit *dictumTechStateLineEdit;
    QDoubleSpinBox *dictumInstResDoubleSpinBox;
    QDoubleSpinBox *dictumInstRateDoubleSpinBox;
    QLabel *label_7;
    QLabel *label_13;
    QLineEdit *dictumUseSpecialNameLineEdit;
    QLabel *label_4;
    QComboBox *dictumUsesComboBox;

    void setupUi(QDialog *dictumForm)
    {
        if (dictumForm->objectName().isEmpty())
            dictumForm->setObjectName(QString::fromUtf8("dictumForm"));
        dictumForm->resize(785, 993);
        gridLayout = new QGridLayout(dictumForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        processDictumButton = new QPushButton(dictumForm);
        processDictumButton->setObjectName(QString::fromUtf8("processDictumButton"));
        processDictumButton->setMinimumSize(QSize(0, 25));
        QFont font;
        font.setPointSize(9);
        processDictumButton->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/approb.png"), QSize(), QIcon::Normal, QIcon::Off);
        processDictumButton->setIcon(icon);

        gridLayout->addWidget(processDictumButton, 12, 0, 1, 2);

        alExtGridLayout = new QGridLayout();
        alExtGridLayout->setObjectName(QString::fromUtf8("alExtGridLayout"));
        alExtLumNumberLabel = new QLabel(dictumForm);
        alExtLumNumberLabel->setObjectName(QString::fromUtf8("alExtLumNumberLabel"));
        QFont font1;
        font1.setPointSize(10);
        alExtLumNumberLabel->setFont(font1);
        alExtLumNumberLabel->setIndent(4);

        alExtGridLayout->addWidget(alExtLumNumberLabel, 0, 0, 1, 1);

        alExtMeasureSystemLabel = new QLabel(dictumForm);
        alExtMeasureSystemLabel->setObjectName(QString::fromUtf8("alExtMeasureSystemLabel"));
        alExtMeasureSystemLabel->setFont(font1);
        alExtMeasureSystemLabel->setIndent(4);

        alExtGridLayout->addWidget(alExtMeasureSystemLabel, 0, 1, 1, 1);

        alExtInstObjectLabel = new QLabel(dictumForm);
        alExtInstObjectLabel->setObjectName(QString::fromUtf8("alExtInstObjectLabel"));
        alExtInstObjectLabel->setFont(font1);
        alExtInstObjectLabel->setIndent(4);

        alExtGridLayout->addWidget(alExtInstObjectLabel, 0, 2, 1, 1);

        alExtLengthLabel = new QLabel(dictumForm);
        alExtLengthLabel->setObjectName(QString::fromUtf8("alExtLengthLabel"));
        alExtLengthLabel->setFont(font1);
        alExtLengthLabel->setIndent(4);

        alExtGridLayout->addWidget(alExtLengthLabel, 0, 3, 1, 1);

        alExtAreaLabel = new QLabel(dictumForm);
        alExtAreaLabel->setObjectName(QString::fromUtf8("alExtAreaLabel"));
        alExtAreaLabel->setFont(font1);
        alExtAreaLabel->setIndent(4);

        alExtGridLayout->addWidget(alExtAreaLabel, 0, 4, 1, 1);

        alExtLumNumberSpinBox = new QSpinBox(dictumForm);
        alExtLumNumberSpinBox->setObjectName(QString::fromUtf8("alExtLumNumberSpinBox"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(9);
        alExtLumNumberSpinBox->setFont(font2);
        alExtLumNumberSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        alExtLumNumberSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        alExtLumNumberSpinBox->setMaximum(999999999);

        alExtGridLayout->addWidget(alExtLumNumberSpinBox, 1, 0, 1, 1);

        alExtMeasureSystemComboBox = new QComboBox(dictumForm);
        alExtMeasureSystemComboBox->addItem(QString());
        alExtMeasureSystemComboBox->addItem(QString());
        alExtMeasureSystemComboBox->setObjectName(QString::fromUtf8("alExtMeasureSystemComboBox"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(9);
        alExtMeasureSystemComboBox->setFont(font3);

        alExtGridLayout->addWidget(alExtMeasureSystemComboBox, 1, 1, 1, 1);

        alExtInstObjectComboBox = new QComboBox(dictumForm);
        alExtInstObjectComboBox->addItem(QString());
        alExtInstObjectComboBox->addItem(QString());
        alExtInstObjectComboBox->setObjectName(QString::fromUtf8("alExtInstObjectComboBox"));
        alExtInstObjectComboBox->setFont(font3);

        alExtGridLayout->addWidget(alExtInstObjectComboBox, 1, 2, 1, 1);

        alExtLengthSpinBox = new QSpinBox(dictumForm);
        alExtLengthSpinBox->setObjectName(QString::fromUtf8("alExtLengthSpinBox"));
        alExtLengthSpinBox->setFont(font2);
        alExtLengthSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        alExtLengthSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        alExtLengthSpinBox->setMinimum(0);
        alExtLengthSpinBox->setMaximum(999999999);
        alExtLengthSpinBox->setSingleStep(10);
        alExtLengthSpinBox->setValue(0);

        alExtGridLayout->addWidget(alExtLengthSpinBox, 1, 3, 1, 1);

        alExtAreaSpinBox = new QSpinBox(dictumForm);
        alExtAreaSpinBox->setObjectName(QString::fromUtf8("alExtAreaSpinBox"));
        alExtAreaSpinBox->setFont(font2);
        alExtAreaSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        alExtAreaSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        alExtAreaSpinBox->setMinimum(0);
        alExtAreaSpinBox->setMaximum(999999999);
        alExtAreaSpinBox->setSingleStep(100);
        alExtAreaSpinBox->setValue(0);

        alExtGridLayout->addWidget(alExtAreaSpinBox, 1, 4, 1, 1);


        gridLayout->addLayout(alExtGridLayout, 7, 0, 1, 2);

        genGridLayout = new QGridLayout();
        genGridLayout->setObjectName(QString::fromUtf8("genGridLayout"));
        genSesNumberSpinBox = new QSpinBox(dictumForm);
        genSesNumberSpinBox->setObjectName(QString::fromUtf8("genSesNumberSpinBox"));
        genSesNumberSpinBox->setFont(font2);
        genSesNumberSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        genSesNumberSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        genSesNumberSpinBox->setMinimum(0);
        genSesNumberSpinBox->setValue(0);

        genGridLayout->addWidget(genSesNumberSpinBox, 2, 3, 1, 1);

        genAssociatedProcsComboBox = new QComboBox(dictumForm);
        genAssociatedProcsComboBox->setObjectName(QString::fromUtf8("genAssociatedProcsComboBox"));
        genAssociatedProcsComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));

        genGridLayout->addWidget(genAssociatedProcsComboBox, 2, 0, 1, 2);

        genSeTypeComboBox = new QComboBox(dictumForm);
        genSeTypeComboBox->addItem(QString());
        genSeTypeComboBox->addItem(QString());
        genSeTypeComboBox->addItem(QString());
        genSeTypeComboBox->addItem(QString());
        genSeTypeComboBox->setObjectName(QString::fromUtf8("genSeTypeComboBox"));
        genSeTypeComboBox->setFont(font3);

        genGridLayout->addWidget(genSeTypeComboBox, 2, 2, 1, 1);

        genAssociatedProcsLabel = new QLabel(dictumForm);
        genAssociatedProcsLabel->setObjectName(QString::fromUtf8("genAssociatedProcsLabel"));
        genAssociatedProcsLabel->setFont(font1);
        genAssociatedProcsLabel->setIndent(4);

        genGridLayout->addWidget(genAssociatedProcsLabel, 0, 0, 2, 2);

        genSeTypeLabel = new QLabel(dictumForm);
        genSeTypeLabel->setObjectName(QString::fromUtf8("genSeTypeLabel"));
        genSeTypeLabel->setFont(font1);
        genSeTypeLabel->setIndent(4);

        genGridLayout->addWidget(genSeTypeLabel, 0, 2, 2, 1);

        genSesNumberLabel = new QLabel(dictumForm);
        genSesNumberLabel->setObjectName(QString::fromUtf8("genSesNumberLabel"));
        genSesNumberLabel->setFont(font1);
        genSesNumberLabel->setIndent(4);

        genGridLayout->addWidget(genSesNumberLabel, 0, 3, 2, 1);


        gridLayout->addLayout(genGridLayout, 3, 0, 1, 2);

        groupBox = new QGroupBox(dictumForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(16777215, 140));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setHorizontalSpacing(6);
        gridLayout_2->setVerticalSpacing(0);
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font1);
        label_15->setIndent(4);

        gridLayout_2->addWidget(label_15, 2, 0, 1, 1);

        dictumObservTextEdit = new QTextEdit(groupBox);
        dictumObservTextEdit->setObjectName(QString::fromUtf8("dictumObservTextEdit"));
        dictumObservTextEdit->setMinimumSize(QSize(0, 0));
        dictumObservTextEdit->setFont(font1);
        dictumObservTextEdit->setFrameShape(QFrame::StyledPanel);
        dictumObservTextEdit->setFrameShadow(QFrame::Sunken);
        dictumObservTextEdit->setLineWidth(1);
        dictumObservTextEdit->setMidLineWidth(0);
        dictumObservTextEdit->setTabChangesFocus(true);
        dictumObservTextEdit->setAcceptRichText(false);

        gridLayout_2->addWidget(dictumObservTextEdit, 3, 0, 1, 2);

        dictumScopeTextEdit = new QTextEdit(groupBox);
        dictumScopeTextEdit->setObjectName(QString::fromUtf8("dictumScopeTextEdit"));
        dictumScopeTextEdit->setMinimumSize(QSize(0, 0));
        dictumScopeTextEdit->setFont(font1);
        dictumScopeTextEdit->setFrameShape(QFrame::StyledPanel);
        dictumScopeTextEdit->setFrameShadow(QFrame::Sunken);
        dictumScopeTextEdit->setLineWidth(1);
        dictumScopeTextEdit->setMidLineWidth(0);
        dictumScopeTextEdit->setTabChangesFocus(true);
        dictumScopeTextEdit->setAcceptRichText(false);

        gridLayout_2->addWidget(dictumScopeTextEdit, 1, 0, 1, 2);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);
        label_14->setMargin(0);
        label_14->setIndent(4);

        gridLayout_2->addWidget(label_14, 0, 0, 1, 2);


        gridLayout->addWidget(groupBox, 9, 0, 1, 2);

        reqOutGroupBox = new QGroupBox(dictumForm);
        reqOutGroupBox->setObjectName(QString::fromUtf8("reqOutGroupBox"));
        reqOutGroupBox->setMinimumSize(QSize(0, 230));
        reqOutGroupBox->setCheckable(false);
        gridLayout_4 = new QGridLayout(reqOutGroupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tableWidget = new QTableWidget(reqOutGroupBox);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_4->addWidget(tableWidget, 0, 0, 1, 1);

        dictumCodeLineEdit = new QLineEdit(reqOutGroupBox);
        dictumCodeLineEdit->setObjectName(QString::fromUtf8("dictumCodeLineEdit"));
        dictumCodeLineEdit->setMinimumSize(QSize(0, 24));
        dictumCodeLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));

        gridLayout_4->addWidget(dictumCodeLineEdit, 1, 0, 1, 1);


        gridLayout->addWidget(reqOutGroupBox, 10, 0, 1, 2);

        transfGridLayout = new QGridLayout();
        transfGridLayout->setObjectName(QString::fromUtf8("transfGridLayout"));
        transfRateLabel = new QLabel(dictumForm);
        transfRateLabel->setObjectName(QString::fromUtf8("transfRateLabel"));
        transfRateLabel->setFont(font1);
        transfRateLabel->setIndent(4);

        transfGridLayout->addWidget(transfRateLabel, 0, 3, 1, 1);

        transfTransfNumberLabel = new QLabel(dictumForm);
        transfTransfNumberLabel->setObjectName(QString::fromUtf8("transfTransfNumberLabel"));
        transfTransfNumberLabel->setFont(font1);
        transfTransfNumberLabel->setIndent(4);

        transfGridLayout->addWidget(transfTransfNumberLabel, 0, 4, 1, 1);

        transfRateSpinBox = new QDoubleSpinBox(dictumForm);
        transfRateSpinBox->setObjectName(QString::fromUtf8("transfRateSpinBox"));
        transfRateSpinBox->setFont(font2);
        transfRateSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        transfRateSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        transfRateSpinBox->setMaximum(999999999.990000009536743);
        transfRateSpinBox->setSingleStep(100.000000000000000);

        transfGridLayout->addWidget(transfRateSpinBox, 1, 3, 1, 1);

        transfTransfNumberSpinBox = new QSpinBox(dictumForm);
        transfTransfNumberSpinBox->setObjectName(QString::fromUtf8("transfTransfNumberSpinBox"));
        transfTransfNumberSpinBox->setFont(font2);
        transfTransfNumberSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        transfTransfNumberSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        transfTransfNumberSpinBox->setMinimum(0);
        transfTransfNumberSpinBox->setMaximum(999);
        transfTransfNumberSpinBox->setValue(0);

        transfGridLayout->addWidget(transfTransfNumberSpinBox, 1, 4, 1, 1);

        transfAssociatedProcsComboBox = new QComboBox(dictumForm);
        transfAssociatedProcsComboBox->setObjectName(QString::fromUtf8("transfAssociatedProcsComboBox"));
        transfAssociatedProcsComboBox->setMinimumSize(QSize(300, 0));
        transfAssociatedProcsComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));

        transfGridLayout->addWidget(transfAssociatedProcsComboBox, 1, 0, 1, 1);

        transfAssociatedProcsLabel = new QLabel(dictumForm);
        transfAssociatedProcsLabel->setObjectName(QString::fromUtf8("transfAssociatedProcsLabel"));
        transfAssociatedProcsLabel->setFont(font1);
        transfAssociatedProcsLabel->setIndent(4);

        transfGridLayout->addWidget(transfAssociatedProcsLabel, 0, 0, 1, 1);

        transfSeTypeLabel = new QLabel(dictumForm);
        transfSeTypeLabel->setObjectName(QString::fromUtf8("transfSeTypeLabel"));
        transfSeTypeLabel->setFont(font1);
        transfSeTypeLabel->setIndent(4);

        transfGridLayout->addWidget(transfSeTypeLabel, 0, 1, 1, 2);

        transfSeTypeComboBox = new QComboBox(dictumForm);
        transfSeTypeComboBox->addItem(QString());
        transfSeTypeComboBox->addItem(QString());
        transfSeTypeComboBox->addItem(QString());
        transfSeTypeComboBox->addItem(QString());
        transfSeTypeComboBox->setObjectName(QString::fromUtf8("transfSeTypeComboBox"));
        transfSeTypeComboBox->setFont(font3);

        transfGridLayout->addWidget(transfSeTypeComboBox, 1, 1, 1, 2);


        gridLayout->addLayout(transfGridLayout, 5, 0, 1, 2);

        distGridLayout = new QGridLayout();
        distGridLayout->setObjectName(QString::fromUtf8("distGridLayout"));
        distLenghtLabel = new QLabel(dictumForm);
        distLenghtLabel->setObjectName(QString::fromUtf8("distLenghtLabel"));
        distLenghtLabel->setFont(font1);
        distLenghtLabel->setIndent(4);

        distGridLayout->addWidget(distLenghtLabel, 0, 1, 1, 1);

        distWiresTypeLabel = new QLabel(dictumForm);
        distWiresTypeLabel->setObjectName(QString::fromUtf8("distWiresTypeLabel"));
        distWiresTypeLabel->setFont(font1);
        distWiresTypeLabel->setIndent(4);

        distGridLayout->addWidget(distWiresTypeLabel, 0, 2, 1, 1);

        distStructsNumberLabel = new QLabel(dictumForm);
        distStructsNumberLabel->setObjectName(QString::fromUtf8("distStructsNumberLabel"));
        distStructsNumberLabel->setFont(font1);
        distStructsNumberLabel->setIndent(4);

        distGridLayout->addWidget(distStructsNumberLabel, 0, 3, 1, 1);

        distConfLabel = new QLabel(dictumForm);
        distConfLabel->setObjectName(QString::fromUtf8("distConfLabel"));
        distConfLabel->setFont(font1);
        distConfLabel->setIndent(4);

        distGridLayout->addWidget(distConfLabel, 0, 0, 1, 1);

        distMaterialLabel = new QLabel(dictumForm);
        distMaterialLabel->setObjectName(QString::fromUtf8("distMaterialLabel"));
        distMaterialLabel->setFont(font1);
        distMaterialLabel->setIndent(4);

        distGridLayout->addWidget(distMaterialLabel, 0, 4, 1, 1);

        distMaterialLineEdit = new QLineEdit(dictumForm);
        distMaterialLineEdit->setObjectName(QString::fromUtf8("distMaterialLineEdit"));
        distMaterialLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        distMaterialLineEdit->setMaxLength(32767);

        distGridLayout->addWidget(distMaterialLineEdit, 1, 4, 2, 1);

        distStructsNumberSpinBox = new QSpinBox(dictumForm);
        distStructsNumberSpinBox->setObjectName(QString::fromUtf8("distStructsNumberSpinBox"));
        distStructsNumberSpinBox->setFont(font2);
        distStructsNumberSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        distStructsNumberSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        distStructsNumberSpinBox->setMinimum(0);
        distStructsNumberSpinBox->setSingleStep(10);
        distStructsNumberSpinBox->setValue(0);

        distGridLayout->addWidget(distStructsNumberSpinBox, 1, 3, 2, 1);

        distWiresTypeLineEdit = new QLineEdit(dictumForm);
        distWiresTypeLineEdit->setObjectName(QString::fromUtf8("distWiresTypeLineEdit"));
        distWiresTypeLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        distWiresTypeLineEdit->setMaxLength(32767);

        distGridLayout->addWidget(distWiresTypeLineEdit, 1, 2, 2, 1);

        distLengthSpinbox = new QSpinBox(dictumForm);
        distLengthSpinbox->setObjectName(QString::fromUtf8("distLengthSpinbox"));
        distLengthSpinbox->setFont(font2);
        distLengthSpinbox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        distLengthSpinbox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        distLengthSpinbox->setMinimum(0);
        distLengthSpinbox->setMaximum(999999999);
        distLengthSpinbox->setSingleStep(100);
        distLengthSpinbox->setValue(0);

        distGridLayout->addWidget(distLengthSpinbox, 1, 1, 2, 1);

        distConfComboBox = new QComboBox(dictumForm);
        distConfComboBox->addItem(QString());
        distConfComboBox->addItem(QString());
        distConfComboBox->setObjectName(QString::fromUtf8("distConfComboBox"));
        distConfComboBox->setFont(font);

        distGridLayout->addWidget(distConfComboBox, 1, 0, 2, 1);


        gridLayout->addLayout(distGridLayout, 6, 0, 1, 2);

        menuGroupBox = new QGroupBox(dictumForm);
        menuGroupBox->setObjectName(QString::fromUtf8("menuGroupBox"));
        menuGroupBox->setMinimumSize(QSize(0, 45));
        menuGroupBox->setMaximumSize(QSize(16777215, 40));
        menuGroupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        menuGroupBox->setFlat(false);
        menuGroupBox->setCheckable(false);
        gridLayout_3 = new QGridLayout(menuGroupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(menuGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setIndent(4);

        horizontalLayout->addWidget(label_5);

        dictumNumberLineEdit = new QLineEdit(menuGroupBox);
        dictumNumberLineEdit->setObjectName(QString::fromUtf8("dictumNumberLineEdit"));
        dictumNumberLineEdit->setMinimumSize(QSize(150, 24));
        dictumNumberLineEdit->setMaximumSize(QSize(120, 16777215));
        dictumNumberLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        dictumNumberLineEdit->setMaxLength(32767);
        dictumNumberLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(dictumNumberLineEdit);

        horizontalSpacer_11 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        updateDictumButton = new QPushButton(menuGroupBox);
        updateDictumButton->setObjectName(QString::fromUtf8("updateDictumButton"));
        updateDictumButton->setEnabled(true);
        updateDictumButton->setMinimumSize(QSize(30, 30));
        updateDictumButton->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        updateDictumButton->setIcon(icon1);

        horizontalLayout->addWidget(updateDictumButton);

        saveDictumButton = new QPushButton(menuGroupBox);
        saveDictumButton->setObjectName(QString::fromUtf8("saveDictumButton"));
        saveDictumButton->setEnabled(true);
        saveDictumButton->setMinimumSize(QSize(30, 30));
        saveDictumButton->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveDictumButton->setIcon(icon2);

        horizontalLayout->addWidget(saveDictumButton);

        previewDictumButton = new QPushButton(menuGroupBox);
        previewDictumButton->setObjectName(QString::fromUtf8("previewDictumButton"));
        previewDictumButton->setEnabled(true);
        previewDictumButton->setMinimumSize(QSize(30, 30));
        previewDictumButton->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        previewDictumButton->setIcon(icon3);

        horizontalLayout->addWidget(previewDictumButton);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout->addWidget(menuGroupBox, 0, 0, 1, 2);

        buttonsGridLayout = new QGridLayout();
        buttonsGridLayout->setObjectName(QString::fromUtf8("buttonsGridLayout"));
        subDictumsLabel = new QLabel(dictumForm);
        subDictumsLabel->setObjectName(QString::fromUtf8("subDictumsLabel"));
        subDictumsLabel->setFont(font1);
        subDictumsLabel->setIndent(4);

        buttonsGridLayout->addWidget(subDictumsLabel, 0, 0, 1, 2);

        subDictumsComboBox = new QComboBox(dictumForm);
        subDictumsComboBox->setObjectName(QString::fromUtf8("subDictumsComboBox"));
        subDictumsComboBox->setEnabled(true);
        subDictumsComboBox->setMinimumSize(QSize(150, 24));
        subDictumsComboBox->setFont(font1);

        buttonsGridLayout->addWidget(subDictumsComboBox, 1, 0, 1, 2);

        goSubDictumButton = new QPushButton(dictumForm);
        goSubDictumButton->setObjectName(QString::fromUtf8("goSubDictumButton"));
        goSubDictumButton->setEnabled(true);
        goSubDictumButton->setMinimumSize(QSize(0, 26));
        goSubDictumButton->setFont(font);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/go-next.png"), QSize(), QIcon::Normal, QIcon::Off);
        goSubDictumButton->setIcon(icon4);

        buttonsGridLayout->addWidget(goSubDictumButton, 2, 0, 1, 1);

        newSubDictumButton = new QPushButton(dictumForm);
        newSubDictumButton->setObjectName(QString::fromUtf8("newSubDictumButton"));
        newSubDictumButton->setEnabled(true);
        newSubDictumButton->setMinimumSize(QSize(0, 26));
        newSubDictumButton->setFont(font);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/new_dict.png"), QSize(), QIcon::Normal, QIcon::Off);
        newSubDictumButton->setIcon(icon5);

        buttonsGridLayout->addWidget(newSubDictumButton, 2, 1, 1, 1);


        gridLayout->addLayout(buttonsGridLayout, 1, 1, 1, 1);

        transmGridLayout = new QGridLayout();
        transmGridLayout->setObjectName(QString::fromUtf8("transmGridLayout"));
        transmLengthLabel = new QLabel(dictumForm);
        transmLengthLabel->setObjectName(QString::fromUtf8("transmLengthLabel"));
        transmLengthLabel->setFont(font1);
        transmLengthLabel->setIndent(4);

        transmGridLayout->addWidget(transmLengthLabel, 2, 4, 1, 3);

        transmWiresTypeLineEdit = new QLineEdit(dictumForm);
        transmWiresTypeLineEdit->setObjectName(QString::fromUtf8("transmWiresTypeLineEdit"));
        transmWiresTypeLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        transmWiresTypeLineEdit->setMaxLength(32767);

        transmGridLayout->addWidget(transmWiresTypeLineEdit, 3, 0, 1, 1);

        transmConfLabel = new QLabel(dictumForm);
        transmConfLabel->setObjectName(QString::fromUtf8("transmConfLabel"));
        transmConfLabel->setFont(font1);
        transmConfLabel->setIndent(4);

        transmGridLayout->addWidget(transmConfLabel, 0, 4, 1, 3);

        transmWiresTypeLabel = new QLabel(dictumForm);
        transmWiresTypeLabel->setObjectName(QString::fromUtf8("transmWiresTypeLabel"));
        transmWiresTypeLabel->setFont(font1);
        transmWiresTypeLabel->setIndent(4);

        transmGridLayout->addWidget(transmWiresTypeLabel, 2, 0, 1, 1);

        transmAssociatedProcsComboBox = new QComboBox(dictumForm);
        transmAssociatedProcsComboBox->setObjectName(QString::fromUtf8("transmAssociatedProcsComboBox"));
        transmAssociatedProcsComboBox->setMinimumSize(QSize(300, 0));
        transmAssociatedProcsComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));

        transmGridLayout->addWidget(transmAssociatedProcsComboBox, 1, 0, 1, 1);

        transmAssociatedProcsLineEdit = new QLabel(dictumForm);
        transmAssociatedProcsLineEdit->setObjectName(QString::fromUtf8("transmAssociatedProcsLineEdit"));
        transmAssociatedProcsLineEdit->setFont(font1);
        transmAssociatedProcsLineEdit->setIndent(4);

        transmGridLayout->addWidget(transmAssociatedProcsLineEdit, 0, 0, 1, 1);

        transmConfLineEdit = new QLineEdit(dictumForm);
        transmConfLineEdit->setObjectName(QString::fromUtf8("transmConfLineEdit"));
        transmConfLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        transmConfLineEdit->setMaxLength(32767);

        transmGridLayout->addWidget(transmConfLineEdit, 1, 4, 1, 3);

        transmLengthSpinbox = new QSpinBox(dictumForm);
        transmLengthSpinbox->setObjectName(QString::fromUtf8("transmLengthSpinbox"));
        transmLengthSpinbox->setFont(font2);
        transmLengthSpinbox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        transmLengthSpinbox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        transmLengthSpinbox->setMaximum(999999999);
        transmLengthSpinbox->setSingleStep(100);

        transmGridLayout->addWidget(transmLengthSpinbox, 3, 4, 1, 3);

        transmLineDetailsLabel = new QLabel(dictumForm);
        transmLineDetailsLabel->setObjectName(QString::fromUtf8("transmLineDetailsLabel"));
        transmLineDetailsLabel->setFont(font1);
        transmLineDetailsLabel->setIndent(4);

        transmGridLayout->addWidget(transmLineDetailsLabel, 0, 1, 1, 3);

        transmLineDetailsLineEdit = new QLineEdit(dictumForm);
        transmLineDetailsLineEdit->setObjectName(QString::fromUtf8("transmLineDetailsLineEdit"));
        transmLineDetailsLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        transmLineDetailsLineEdit->setMaxLength(32767);

        transmGridLayout->addWidget(transmLineDetailsLineEdit, 1, 1, 1, 3);

        transmMaterialLabel = new QLabel(dictumForm);
        transmMaterialLabel->setObjectName(QString::fromUtf8("transmMaterialLabel"));
        transmMaterialLabel->setFont(font1);
        transmMaterialLabel->setIndent(4);

        transmGridLayout->addWidget(transmMaterialLabel, 2, 3, 1, 1);

        transmMaterialLineEdit = new QLineEdit(dictumForm);
        transmMaterialLineEdit->setObjectName(QString::fromUtf8("transmMaterialLineEdit"));
        transmMaterialLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        transmMaterialLineEdit->setMaxLength(32767);

        transmGridLayout->addWidget(transmMaterialLineEdit, 3, 3, 1, 1);

        transmStructsNumberLabel = new QLabel(dictumForm);
        transmStructsNumberLabel->setObjectName(QString::fromUtf8("transmStructsNumberLabel"));
        transmStructsNumberLabel->setFont(font1);
        transmStructsNumberLabel->setIndent(4);

        transmGridLayout->addWidget(transmStructsNumberLabel, 2, 1, 1, 2);

        transmStructsNumberSpinBox = new QSpinBox(dictumForm);
        transmStructsNumberSpinBox->setObjectName(QString::fromUtf8("transmStructsNumberSpinBox"));
        transmStructsNumberSpinBox->setFont(font2);
        transmStructsNumberSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        transmStructsNumberSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        transmStructsNumberSpinBox->setMaximum(9999999);
        transmStructsNumberSpinBox->setSingleStep(10);

        transmGridLayout->addWidget(transmStructsNumberSpinBox, 3, 1, 1, 2);


        gridLayout->addLayout(transmGridLayout, 4, 0, 1, 2);

        fusGridLayout = new QGridLayout();
        fusGridLayout->setObjectName(QString::fromUtf8("fusGridLayout"));
        fusGridLayout->setVerticalSpacing(6);
        label_12 = new QLabel(dictumForm);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);
        label_12->setIndent(4);

        fusGridLayout->addWidget(label_12, 0, 1, 1, 1);

        label_11 = new QLabel(dictumForm);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);
        label_11->setIndent(4);

        fusGridLayout->addWidget(label_11, 0, 0, 1, 1);

        dictumProcessLineEdit = new QLineEdit(dictumForm);
        dictumProcessLineEdit->setObjectName(QString::fromUtf8("dictumProcessLineEdit"));
        dictumProcessLineEdit->setFont(font2);
        dictumProcessLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        dictumProcessLineEdit->setReadOnly(false);

        fusGridLayout->addWidget(dictumProcessLineEdit, 1, 0, 1, 1);

        label_8 = new QLabel(dictumForm);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setIndent(4);

        fusGridLayout->addWidget(label_8, 2, 1, 1, 1);

        label_9 = new QLabel(dictumForm);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);
        label_9->setIndent(4);

        fusGridLayout->addWidget(label_9, 4, 0, 1, 1);

        label = new QLabel(dictumForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);
        label->setIndent(4);

        fusGridLayout->addWidget(label, 2, 0, 1, 1);

        label_6 = new QLabel(dictumForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);
        label_6->setIndent(4);

        fusGridLayout->addWidget(label_6, 0, 3, 1, 2);

        dictumDateEdit = new QDateEdit(dictumForm);
        dictumDateEdit->setObjectName(QString::fromUtf8("dictumDateEdit"));
        dictumDateEdit->setFont(font2);
        dictumDateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        dictumDateEdit->setCalendarPopup(true);

        fusGridLayout->addWidget(dictumDateEdit, 3, 3, 1, 2);

        dictumInstDateEdit = new QDateEdit(dictumForm);
        dictumInstDateEdit->setObjectName(QString::fromUtf8("dictumInstDateEdit"));
        dictumInstDateEdit->setFont(font2);
        dictumInstDateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        dictumInstDateEdit->setCalendarPopup(false);
        dictumInstDateEdit->setDate(QDate(2013, 1, 1));

        fusGridLayout->addWidget(dictumInstDateEdit, 1, 3, 1, 2);

        dictumStateLineEdit = new QLineEdit(dictumForm);
        dictumStateLineEdit->setObjectName(QString::fromUtf8("dictumStateLineEdit"));
        dictumStateLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        dictumStateLineEdit->setReadOnly(false);

        fusGridLayout->addWidget(dictumStateLineEdit, 3, 0, 1, 1);

        dictumInstVoltageLineEdit = new QLineEdit(dictumForm);
        dictumInstVoltageLineEdit->setObjectName(QString::fromUtf8("dictumInstVoltageLineEdit"));
        dictumInstVoltageLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        dictumInstVoltageLineEdit->setReadOnly(false);

        fusGridLayout->addWidget(dictumInstVoltageLineEdit, 1, 2, 1, 1);

        dictumTechStateLineEdit = new QLineEdit(dictumForm);
        dictumTechStateLineEdit->setObjectName(QString::fromUtf8("dictumTechStateLineEdit"));
        dictumTechStateLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        dictumTechStateLineEdit->setReadOnly(true);

        fusGridLayout->addWidget(dictumTechStateLineEdit, 3, 1, 1, 1);

        dictumInstResDoubleSpinBox = new QDoubleSpinBox(dictumForm);
        dictumInstResDoubleSpinBox->setObjectName(QString::fromUtf8("dictumInstResDoubleSpinBox"));
        dictumInstResDoubleSpinBox->setFont(font2);
        dictumInstResDoubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        dictumInstResDoubleSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        dictumInstResDoubleSpinBox->setMaximum(9999.989999999999782);

        fusGridLayout->addWidget(dictumInstResDoubleSpinBox, 3, 2, 1, 1);

        dictumInstRateDoubleSpinBox = new QDoubleSpinBox(dictumForm);
        dictumInstRateDoubleSpinBox->setObjectName(QString::fromUtf8("dictumInstRateDoubleSpinBox"));
        dictumInstRateDoubleSpinBox->setFont(font2);
        dictumInstRateDoubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        dictumInstRateDoubleSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        dictumInstRateDoubleSpinBox->setMaximum(999999999.990000009536743);

        fusGridLayout->addWidget(dictumInstRateDoubleSpinBox, 1, 1, 1, 1);

        label_7 = new QLabel(dictumForm);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setIndent(4);

        fusGridLayout->addWidget(label_7, 2, 2, 1, 1);

        label_13 = new QLabel(dictumForm);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);
        label_13->setIndent(4);

        fusGridLayout->addWidget(label_13, 0, 2, 1, 1);

        dictumUseSpecialNameLineEdit = new QLineEdit(dictumForm);
        dictumUseSpecialNameLineEdit->setObjectName(QString::fromUtf8("dictumUseSpecialNameLineEdit"));
        dictumUseSpecialNameLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        dictumUseSpecialNameLineEdit->setReadOnly(true);

        fusGridLayout->addWidget(dictumUseSpecialNameLineEdit, 4, 3, 1, 2);

        label_4 = new QLabel(dictumForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setIndent(4);

        fusGridLayout->addWidget(label_4, 2, 3, 1, 2);

        dictumUsesComboBox = new QComboBox(dictumForm);
        dictumUsesComboBox->addItem(QString());
        dictumUsesComboBox->setObjectName(QString::fromUtf8("dictumUsesComboBox"));

        fusGridLayout->addWidget(dictumUsesComboBox, 4, 1, 1, 2);


        gridLayout->addLayout(fusGridLayout, 1, 0, 2, 1);

        QWidget::setTabOrder(dictumNumberLineEdit, dictumInstRateDoubleSpinBox);
        QWidget::setTabOrder(dictumInstRateDoubleSpinBox, dictumInstVoltageLineEdit);
        QWidget::setTabOrder(dictumInstVoltageLineEdit, dictumInstResDoubleSpinBox);
        QWidget::setTabOrder(dictumInstResDoubleSpinBox, dictumInstDateEdit);
        QWidget::setTabOrder(dictumInstDateEdit, dictumDateEdit);
        QWidget::setTabOrder(dictumDateEdit, genAssociatedProcsComboBox);
        QWidget::setTabOrder(genAssociatedProcsComboBox, genSeTypeComboBox);
        QWidget::setTabOrder(genSeTypeComboBox, genSesNumberSpinBox);
        QWidget::setTabOrder(genSesNumberSpinBox, transmAssociatedProcsComboBox);
        QWidget::setTabOrder(transmAssociatedProcsComboBox, transmLineDetailsLineEdit);
        QWidget::setTabOrder(transmLineDetailsLineEdit, transmConfLineEdit);
        QWidget::setTabOrder(transmConfLineEdit, transmWiresTypeLineEdit);
        QWidget::setTabOrder(transmWiresTypeLineEdit, transmLengthSpinbox);
        QWidget::setTabOrder(transmLengthSpinbox, transfAssociatedProcsComboBox);
        QWidget::setTabOrder(transfAssociatedProcsComboBox, transfSeTypeComboBox);
        QWidget::setTabOrder(transfSeTypeComboBox, transfRateSpinBox);
        QWidget::setTabOrder(transfRateSpinBox, transfTransfNumberSpinBox);
        QWidget::setTabOrder(transfTransfNumberSpinBox, distLengthSpinbox);
        QWidget::setTabOrder(distLengthSpinbox, distWiresTypeLineEdit);
        QWidget::setTabOrder(distWiresTypeLineEdit, distStructsNumberSpinBox);
        QWidget::setTabOrder(distStructsNumberSpinBox, distMaterialLineEdit);
        QWidget::setTabOrder(distMaterialLineEdit, alExtLumNumberSpinBox);
        QWidget::setTabOrder(alExtLumNumberSpinBox, alExtMeasureSystemComboBox);
        QWidget::setTabOrder(alExtMeasureSystemComboBox, alExtInstObjectComboBox);
        QWidget::setTabOrder(alExtInstObjectComboBox, alExtLengthSpinBox);
        QWidget::setTabOrder(alExtLengthSpinBox, alExtAreaSpinBox);
        QWidget::setTabOrder(alExtAreaSpinBox, dictumScopeTextEdit);
        QWidget::setTabOrder(dictumScopeTextEdit, dictumObservTextEdit);
        QWidget::setTabOrder(dictumObservTextEdit, tableWidget);
        QWidget::setTabOrder(tableWidget, dictumCodeLineEdit);
        QWidget::setTabOrder(dictumCodeLineEdit, processDictumButton);
        QWidget::setTabOrder(processDictumButton, subDictumsComboBox);
        QWidget::setTabOrder(subDictumsComboBox, goSubDictumButton);
        QWidget::setTabOrder(goSubDictumButton, newSubDictumButton);
        QWidget::setTabOrder(newSubDictumButton, updateDictumButton);
        QWidget::setTabOrder(updateDictumButton, saveDictumButton);
        QWidget::setTabOrder(saveDictumButton, previewDictumButton);
        QWidget::setTabOrder(previewDictumButton, dictumProcessLineEdit);
        QWidget::setTabOrder(dictumProcessLineEdit, dictumStateLineEdit);
        QWidget::setTabOrder(dictumStateLineEdit, dictumTechStateLineEdit);

        retranslateUi(dictumForm);

        dictumUsesComboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(dictumForm);
    } // setupUi

    void retranslateUi(QDialog *dictumForm)
    {
        dictumForm->setWindowTitle(QApplication::translate("dictumForm", "Dictamen", nullptr));
        processDictumButton->setText(QApplication::translate("dictumForm", "Procesar Dictamen", nullptr));
        alExtLumNumberLabel->setText(QApplication::translate("dictumForm", "Luminarias", nullptr));
        alExtMeasureSystemLabel->setText(QApplication::translate("dictumForm", "Sistema de Medida", nullptr));
        alExtInstObjectLabel->setText(QApplication::translate("dictumForm", "Objeto Instalaci\303\263n", nullptr));
        alExtLengthLabel->setText(QApplication::translate("dictumForm", "Longitud Total", nullptr));
        alExtAreaLabel->setText(QApplication::translate("dictumForm", "\303\201rea Total", nullptr));
        alExtMeasureSystemComboBox->setItemText(0, QApplication::translate("dictumForm", "Si", nullptr));
        alExtMeasureSystemComboBox->setItemText(1, QApplication::translate("dictumForm", "No", nullptr));

        alExtInstObjectComboBox->setItemText(0, QApplication::translate("dictumForm", "Parque", nullptr));
        alExtInstObjectComboBox->setItemText(1, QApplication::translate("dictumForm", "V\303\255as", nullptr));

        alExtLengthSpinBox->setSuffix(QApplication::translate("dictumForm", " m", nullptr));
        genAssociatedProcsComboBox->setProperty("defaultText", QVariant(QString()));
        genSeTypeComboBox->setItemText(0, QApplication::translate("dictumForm", "En Poste", nullptr));
        genSeTypeComboBox->setItemText(1, QApplication::translate("dictumForm", "De Patio", nullptr));
        genSeTypeComboBox->setItemText(2, QApplication::translate("dictumForm", "Pedestal", nullptr));
        genSeTypeComboBox->setItemText(3, QApplication::translate("dictumForm", "Encapsulada", nullptr));

        genAssociatedProcsLabel->setText(QApplication::translate("dictumForm", "Procesos Asociados", nullptr));
        genSeTypeLabel->setText(QApplication::translate("dictumForm", "Tipo de Subestaci\303\263n", nullptr));
        genSesNumberLabel->setText(QApplication::translate("dictumForm", "N\303\272mero de SE's", nullptr));
        groupBox->setTitle(QString());
        label_15->setText(QApplication::translate("dictumForm", "Observaciones", nullptr));
        label_14->setText(QApplication::translate("dictumForm", "Alcance", nullptr));
        reqOutGroupBox->setTitle(QString());
        transfRateLabel->setText(QApplication::translate("dictumForm", "Potencia", nullptr));
        transfTransfNumberLabel->setText(QApplication::translate("dictumForm", "N\303\272mero de Trafos", nullptr));
        transfRateSpinBox->setSuffix(QApplication::translate("dictumForm", " kVA", nullptr));
        transfAssociatedProcsLabel->setText(QApplication::translate("dictumForm", "Procesos Asociados", nullptr));
        transfSeTypeLabel->setText(QApplication::translate("dictumForm", "Tipo de Subestaci\303\263n", nullptr));
        transfSeTypeComboBox->setItemText(0, QApplication::translate("dictumForm", "En Poste", nullptr));
        transfSeTypeComboBox->setItemText(1, QApplication::translate("dictumForm", "De Patio", nullptr));
        transfSeTypeComboBox->setItemText(2, QApplication::translate("dictumForm", "Pedestal", nullptr));
        transfSeTypeComboBox->setItemText(3, QApplication::translate("dictumForm", "Encapsulada", nullptr));

        distLenghtLabel->setText(QApplication::translate("dictumForm", "Longitud de L\303\255nea", nullptr));
        distWiresTypeLabel->setText(QApplication::translate("dictumForm", "Tipo de Conductores", nullptr));
        distStructsNumberLabel->setText(QApplication::translate("dictumForm", "N\303\272mero de Apoyos", nullptr));
        distConfLabel->setText(QApplication::translate("dictumForm", "Tipo de Configuraci\303\263n", nullptr));
        distMaterialLabel->setText(QApplication::translate("dictumForm", "Material Estructural", nullptr));
        distMaterialLineEdit->setInputMask(QString());
        distMaterialLineEdit->setText(QString());
        distWiresTypeLineEdit->setInputMask(QString());
        distWiresTypeLineEdit->setText(QString());
        distLengthSpinbox->setSuffix(QApplication::translate("dictumForm", " m", nullptr));
        distConfComboBox->setItemText(0, QApplication::translate("dictumForm", "Monof\303\241sica", nullptr));
        distConfComboBox->setItemText(1, QApplication::translate("dictumForm", "Trif\303\241sica", nullptr));

        menuGroupBox->setTitle(QString());
        label_5->setText(QApplication::translate("dictumForm", "Dict\303\241men - Hoja N\302\272", nullptr));
        dictumNumberLineEdit->setInputMask(QString());
        dictumNumberLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        updateDictumButton->setToolTip(QApplication::translate("dictumForm", "Actualizar", nullptr));
#endif // QT_NO_TOOLTIP
        updateDictumButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveDictumButton->setToolTip(QApplication::translate("dictumForm", "Guardar Cambios", nullptr));
#endif // QT_NO_TOOLTIP
        saveDictumButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        previewDictumButton->setToolTip(QApplication::translate("dictumForm", "Vista Previa", nullptr));
#endif // QT_NO_TOOLTIP
        previewDictumButton->setText(QString());
        subDictumsLabel->setText(QApplication::translate("dictumForm", "Consecutivos", nullptr));
        goSubDictumButton->setText(QApplication::translate("dictumForm", "Ir", nullptr));
        newSubDictumButton->setText(QApplication::translate("dictumForm", "A\303\261adir", nullptr));
        transmLengthLabel->setText(QApplication::translate("dictumForm", "Longitud de L\303\255nea", nullptr));
        transmConfLabel->setText(QApplication::translate("dictumForm", "Tipo de Configuraci\303\263n", nullptr));
        transmWiresTypeLabel->setText(QApplication::translate("dictumForm", "Tipo de Conductores", nullptr));
        transmAssociatedProcsComboBox->setProperty("defaultText", QVariant(QString()));
        transmAssociatedProcsLineEdit->setText(QApplication::translate("dictumForm", "Procesos Asociados", nullptr));
        transmConfLineEdit->setInputMask(QString());
        transmConfLineEdit->setText(QString());
        transmLengthSpinbox->setSuffix(QApplication::translate("dictumForm", " m", nullptr));
        transmLineDetailsLabel->setText(QApplication::translate("dictumForm", "Identificaci\303\263n Plena de la L\303\255nea", nullptr));
        transmLineDetailsLineEdit->setInputMask(QString());
        transmLineDetailsLineEdit->setText(QString());
        transmMaterialLabel->setText(QApplication::translate("dictumForm", "Material Estructural", nullptr));
        transmMaterialLineEdit->setInputMask(QString());
        transmMaterialLineEdit->setText(QString());
        transmStructsNumberLabel->setText(QApplication::translate("dictumForm", "N\303\272mero de Apoyos", nullptr));
        label_12->setText(QApplication::translate("dictumForm", "Potencia", nullptr));
        label_11->setText(QApplication::translate("dictumForm", "Para el proceso", nullptr));
        dictumProcessLineEdit->setText(QString());
        label_8->setText(QApplication::translate("dictumForm", "Estado T\303\251cnico", nullptr));
        label_9->setText(QApplication::translate("dictumForm", "Uso de la Instalaci\303\263n:", nullptr));
        label->setText(QApplication::translate("dictumForm", "Estado", nullptr));
        label_6->setText(QApplication::translate("dictumForm", "A\303\261o de Instalaci\303\263n", nullptr));
        dictumDateEdit->setDisplayFormat(QApplication::translate("dictumForm", "dd 'de' MMM 'de' yyyy", nullptr));
        dictumInstDateEdit->setDisplayFormat(QApplication::translate("dictumForm", "yyyy", nullptr));
        dictumStateLineEdit->setText(QString());
        dictumInstVoltageLineEdit->setText(QString());
        dictumTechStateLineEdit->setText(QString());
        dictumInstResDoubleSpinBox->setSuffix(QApplication::translate("dictumForm", " Ohms", nullptr));
        dictumInstRateDoubleSpinBox->setSuffix(QApplication::translate("dictumForm", " kVA", nullptr));
        label_7->setText(QApplication::translate("dictumForm", "R del SPT", nullptr));
        label_13->setText(QApplication::translate("dictumForm", "Tensi\303\263n (Voltios)", nullptr));
#ifndef QT_NO_TOOLTIP
        dictumUseSpecialNameLineEdit->setToolTip(QApplication::translate("dictumForm", "Detalle para Especiales", nullptr));
#endif // QT_NO_TOOLTIP
        dictumUseSpecialNameLineEdit->setText(QString());
        label_4->setText(QApplication::translate("dictumForm", "Fecha de Expedici\303\263n", nullptr));
        dictumUsesComboBox->setItemText(0, QApplication::translate("dictumForm", "Agregar \303\263 editar usos ...", nullptr));

    } // retranslateUi

};

namespace Ui {
    class dictumForm: public Ui_dictumForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICTUM_H
