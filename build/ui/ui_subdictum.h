/********************************************************************************
** Form generated from reading UI file 'subdictum.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBDICTUM_H
#define UI_SUBDICTUM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
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

class Ui_subDictumForm
{
public:
    QGridLayout *gridLayout_5;
    QGroupBox *reqOutGroupBox;
    QGridLayout *gridLayout_4;
    QTableWidget *tableWidget;
    QGroupBox *menuGroupBox;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *subDictumNumberLineEdit;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *updateSubDictumButton;
    QPushButton *saveSubDictumButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_15;
    QTextEdit *subDictumObservTextEdit;
    QTextEdit *subDictumScopeTextEdit;
    QLabel *label_14;
    QGridLayout *gridLayout;
    QLabel *label_12;
    QDoubleSpinBox *subDictumInstRateDoubleSpinBox;
    QLabel *label_8;
    QLabel *label_4;
    QDateEdit *subDictumDateEdit;
    QLabel *label_10;
    QLineEdit *subDictumTypeLineEdit;
    QLineEdit *subDictumTechStateLineEdit;
    QLabel *label_16;
    QSpinBox *subDictumsNumberSpinBox;
    QPushButton *prepareListButton;
    QLineEdit *subDictumLocationLineEdit;
    QLineEdit *subDictumStateLineEdit;
    QLabel *label_9;
    QLineEdit *subDictumInstVoltageLineEdit;
    QLabel *label_13;
    QLabel *labelSubDictums;
    QDoubleSpinBox *subDictumInstResDoubleSpinBox;
    QLabel *label_6;
    QLabel *label;
    QLineEdit *subDictumIdentifierLineEdit;

    void setupUi(QDialog *subDictumForm)
    {
        if (subDictumForm->objectName().isEmpty())
            subDictumForm->setObjectName(QString::fromUtf8("subDictumForm"));
        subDictumForm->resize(750, 722);
        gridLayout_5 = new QGridLayout(subDictumForm);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        reqOutGroupBox = new QGroupBox(subDictumForm);
        reqOutGroupBox->setObjectName(QString::fromUtf8("reqOutGroupBox"));
        reqOutGroupBox->setMinimumSize(QSize(0, 300));
        reqOutGroupBox->setCheckable(false);
        gridLayout_4 = new QGridLayout(reqOutGroupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tableWidget = new QTableWidget(reqOutGroupBox);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_4->addWidget(tableWidget, 0, 0, 1, 1);


        gridLayout_5->addWidget(reqOutGroupBox, 3, 0, 1, 1);

        menuGroupBox = new QGroupBox(subDictumForm);
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
        QFont font;
        font.setPointSize(10);
        label_5->setFont(font);
        label_5->setIndent(4);

        horizontalLayout->addWidget(label_5);

        subDictumNumberLineEdit = new QLineEdit(menuGroupBox);
        subDictumNumberLineEdit->setObjectName(QString::fromUtf8("subDictumNumberLineEdit"));
        subDictumNumberLineEdit->setMinimumSize(QSize(0, 24));
        subDictumNumberLineEdit->setMaximumSize(QSize(120, 16777215));
        subDictumNumberLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        subDictumNumberLineEdit->setMaxLength(32767);

        horizontalLayout->addWidget(subDictumNumberLineEdit);

        horizontalSpacer_11 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        updateSubDictumButton = new QPushButton(menuGroupBox);
        updateSubDictumButton->setObjectName(QString::fromUtf8("updateSubDictumButton"));
        updateSubDictumButton->setEnabled(true);
        updateSubDictumButton->setMinimumSize(QSize(30, 30));
        updateSubDictumButton->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        updateSubDictumButton->setIcon(icon);

        horizontalLayout->addWidget(updateSubDictumButton);

        saveSubDictumButton = new QPushButton(menuGroupBox);
        saveSubDictumButton->setObjectName(QString::fromUtf8("saveSubDictumButton"));
        saveSubDictumButton->setEnabled(true);
        saveSubDictumButton->setMinimumSize(QSize(30, 30));
        saveSubDictumButton->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveSubDictumButton->setIcon(icon1);

        horizontalLayout->addWidget(saveSubDictumButton);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_5->addWidget(menuGroupBox, 0, 0, 1, 1);

        groupBox = new QGroupBox(subDictumForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(16777215, 170));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(6);
        gridLayout_2->setVerticalSpacing(0);
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);
        label_15->setIndent(4);

        gridLayout_2->addWidget(label_15, 2, 0, 1, 1);

        subDictumObservTextEdit = new QTextEdit(groupBox);
        subDictumObservTextEdit->setObjectName(QString::fromUtf8("subDictumObservTextEdit"));
        subDictumObservTextEdit->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(12);
        subDictumObservTextEdit->setFont(font1);
        subDictumObservTextEdit->setFrameShape(QFrame::StyledPanel);
        subDictumObservTextEdit->setFrameShadow(QFrame::Sunken);
        subDictumObservTextEdit->setLineWidth(1);
        subDictumObservTextEdit->setMidLineWidth(0);
        subDictumObservTextEdit->setTabChangesFocus(true);
        subDictumObservTextEdit->setAcceptRichText(false);

        gridLayout_2->addWidget(subDictumObservTextEdit, 3, 0, 1, 2);

        subDictumScopeTextEdit = new QTextEdit(groupBox);
        subDictumScopeTextEdit->setObjectName(QString::fromUtf8("subDictumScopeTextEdit"));
        subDictumScopeTextEdit->setMinimumSize(QSize(0, 0));
        subDictumScopeTextEdit->setFont(font1);
        subDictumScopeTextEdit->setFrameShape(QFrame::StyledPanel);
        subDictumScopeTextEdit->setFrameShadow(QFrame::Sunken);
        subDictumScopeTextEdit->setLineWidth(1);
        subDictumScopeTextEdit->setMidLineWidth(0);
        subDictumScopeTextEdit->setTabChangesFocus(true);
        subDictumScopeTextEdit->setAcceptRichText(false);

        gridLayout_2->addWidget(subDictumScopeTextEdit, 1, 0, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);
        label_14->setMargin(0);
        label_14->setIndent(4);

        gridLayout_2->addWidget(label_14, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_12 = new QLabel(subDictumForm);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);
        label_12->setIndent(4);

        gridLayout->addWidget(label_12, 3, 3, 1, 1);

        subDictumInstRateDoubleSpinBox = new QDoubleSpinBox(subDictumForm);
        subDictumInstRateDoubleSpinBox->setObjectName(QString::fromUtf8("subDictumInstRateDoubleSpinBox"));
        subDictumInstRateDoubleSpinBox->setMinimumSize(QSize(0, 24));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(9);
        subDictumInstRateDoubleSpinBox->setFont(font2);
        subDictumInstRateDoubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        subDictumInstRateDoubleSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        subDictumInstRateDoubleSpinBox->setMaximum(999999999.990000009536743);
        subDictumInstRateDoubleSpinBox->setSingleStep(5.000000000000000);
        subDictumInstRateDoubleSpinBox->setValue(8.300000000000001);

        gridLayout->addWidget(subDictumInstRateDoubleSpinBox, 4, 3, 5, 1);

        label_8 = new QLabel(subDictumForm);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setIndent(4);

        gridLayout->addWidget(label_8, 3, 0, 1, 2);

        label_4 = new QLabel(subDictumForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setIndent(4);

        gridLayout->addWidget(label_4, 0, 5, 1, 2);

        subDictumDateEdit = new QDateEdit(subDictumForm);
        subDictumDateEdit->setObjectName(QString::fromUtf8("subDictumDateEdit"));
        subDictumDateEdit->setMinimumSize(QSize(0, 24));
        subDictumDateEdit->setFont(font2);
        subDictumDateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        subDictumDateEdit->setCalendarPopup(true);

        gridLayout->addWidget(subDictumDateEdit, 1, 5, 2, 2);

        label_10 = new QLabel(subDictumForm);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
        label_10->setIndent(4);

        gridLayout->addWidget(label_10, 0, 3, 1, 1);

        subDictumTypeLineEdit = new QLineEdit(subDictumForm);
        subDictumTypeLineEdit->setObjectName(QString::fromUtf8("subDictumTypeLineEdit"));
        subDictumTypeLineEdit->setMinimumSize(QSize(0, 24));
        subDictumTypeLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        subDictumTypeLineEdit->setReadOnly(false);

        gridLayout->addWidget(subDictumTypeLineEdit, 1, 2, 2, 1);

        subDictumTechStateLineEdit = new QLineEdit(subDictumForm);
        subDictumTechStateLineEdit->setObjectName(QString::fromUtf8("subDictumTechStateLineEdit"));
        subDictumTechStateLineEdit->setMinimumSize(QSize(0, 24));
        subDictumTechStateLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        subDictumTechStateLineEdit->setReadOnly(true);

        gridLayout->addWidget(subDictumTechStateLineEdit, 4, 0, 5, 2);

        label_16 = new QLabel(subDictumForm);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);
        label_16->setIndent(4);

        gridLayout->addWidget(label_16, 3, 2, 1, 1);

        subDictumsNumberSpinBox = new QSpinBox(subDictumForm);
        subDictumsNumberSpinBox->setObjectName(QString::fromUtf8("subDictumsNumberSpinBox"));
        subDictumsNumberSpinBox->setMinimumSize(QSize(0, 24));
        subDictumsNumberSpinBox->setFont(font);
        subDictumsNumberSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        subDictumsNumberSpinBox->setMinimum(1);
        subDictumsNumberSpinBox->setMaximum(99999);

        gridLayout->addWidget(subDictumsNumberSpinBox, 4, 5, 5, 1);

        prepareListButton = new QPushButton(subDictumForm);
        prepareListButton->setObjectName(QString::fromUtf8("prepareListButton"));
        prepareListButton->setMinimumSize(QSize(0, 25));
        QFont font3;
        font3.setPointSize(9);
        prepareListButton->setFont(font3);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/prepare.png"), QSize(), QIcon::Normal, QIcon::Off);
        prepareListButton->setIcon(icon2);

        gridLayout->addWidget(prepareListButton, 4, 6, 5, 1);

        subDictumLocationLineEdit = new QLineEdit(subDictumForm);
        subDictumLocationLineEdit->setObjectName(QString::fromUtf8("subDictumLocationLineEdit"));
        subDictumLocationLineEdit->setMinimumSize(QSize(0, 24));
        subDictumLocationLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        subDictumLocationLineEdit->setReadOnly(false);

        gridLayout->addWidget(subDictumLocationLineEdit, 1, 3, 2, 1);

        subDictumStateLineEdit = new QLineEdit(subDictumForm);
        subDictumStateLineEdit->setObjectName(QString::fromUtf8("subDictumStateLineEdit"));
        subDictumStateLineEdit->setMinimumSize(QSize(0, 24));
        subDictumStateLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        subDictumStateLineEdit->setReadOnly(true);

        gridLayout->addWidget(subDictumStateLineEdit, 1, 0, 2, 2);

        label_9 = new QLabel(subDictumForm);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setIndent(4);

        gridLayout->addWidget(label_9, 0, 2, 1, 1);

        subDictumInstVoltageLineEdit = new QLineEdit(subDictumForm);
        subDictumInstVoltageLineEdit->setObjectName(QString::fromUtf8("subDictumInstVoltageLineEdit"));
        subDictumInstVoltageLineEdit->setMinimumSize(QSize(0, 24));
        subDictumInstVoltageLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        subDictumInstVoltageLineEdit->setReadOnly(false);

        gridLayout->addWidget(subDictumInstVoltageLineEdit, 1, 4, 2, 1);

        label_13 = new QLabel(subDictumForm);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);
        label_13->setIndent(4);

        gridLayout->addWidget(label_13, 0, 4, 1, 1);

        labelSubDictums = new QLabel(subDictumForm);
        labelSubDictums->setObjectName(QString::fromUtf8("labelSubDictums"));
        labelSubDictums->setFont(font);
        labelSubDictums->setIndent(4);

        gridLayout->addWidget(labelSubDictums, 3, 5, 1, 2);

        subDictumInstResDoubleSpinBox = new QDoubleSpinBox(subDictumForm);
        subDictumInstResDoubleSpinBox->setObjectName(QString::fromUtf8("subDictumInstResDoubleSpinBox"));
        subDictumInstResDoubleSpinBox->setMinimumSize(QSize(0, 24));
        subDictumInstResDoubleSpinBox->setFont(font2);
        subDictumInstResDoubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        subDictumInstResDoubleSpinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        subDictumInstResDoubleSpinBox->setMaximum(1000.990000000000009);
        subDictumInstResDoubleSpinBox->setSingleStep(0.500000000000000);
        subDictumInstResDoubleSpinBox->setValue(6.000000000000000);

        gridLayout->addWidget(subDictumInstResDoubleSpinBox, 4, 4, 5, 1);

        label_6 = new QLabel(subDictumForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setIndent(4);

        gridLayout->addWidget(label_6, 3, 4, 1, 1);

        label = new QLabel(subDictumForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setIndent(4);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        subDictumIdentifierLineEdit = new QLineEdit(subDictumForm);
        subDictumIdentifierLineEdit->setObjectName(QString::fromUtf8("subDictumIdentifierLineEdit"));
        subDictumIdentifierLineEdit->setMinimumSize(QSize(0, 24));
        subDictumIdentifierLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        subDictumIdentifierLineEdit->setMaxLength(32767);

        gridLayout->addWidget(subDictumIdentifierLineEdit, 4, 2, 5, 1);


        gridLayout_5->addLayout(gridLayout, 1, 0, 1, 1);

        QWidget::setTabOrder(subDictumTypeLineEdit, subDictumIdentifierLineEdit);
        QWidget::setTabOrder(subDictumIdentifierLineEdit, subDictumLocationLineEdit);
        QWidget::setTabOrder(subDictumLocationLineEdit, subDictumInstRateDoubleSpinBox);
        QWidget::setTabOrder(subDictumInstRateDoubleSpinBox, subDictumInstVoltageLineEdit);
        QWidget::setTabOrder(subDictumInstVoltageLineEdit, subDictumInstResDoubleSpinBox);
        QWidget::setTabOrder(subDictumInstResDoubleSpinBox, subDictumScopeTextEdit);
        QWidget::setTabOrder(subDictumScopeTextEdit, subDictumObservTextEdit);
        QWidget::setTabOrder(subDictumObservTextEdit, tableWidget);
        QWidget::setTabOrder(tableWidget, subDictumDateEdit);
        QWidget::setTabOrder(subDictumDateEdit, subDictumsNumberSpinBox);
        QWidget::setTabOrder(subDictumsNumberSpinBox, prepareListButton);
        QWidget::setTabOrder(prepareListButton, updateSubDictumButton);
        QWidget::setTabOrder(updateSubDictumButton, saveSubDictumButton);
        QWidget::setTabOrder(saveSubDictumButton, subDictumTechStateLineEdit);
        QWidget::setTabOrder(subDictumTechStateLineEdit, subDictumStateLineEdit);
        QWidget::setTabOrder(subDictumStateLineEdit, subDictumNumberLineEdit);

        retranslateUi(subDictumForm);

        QMetaObject::connectSlotsByName(subDictumForm);
    } // setupUi

    void retranslateUi(QDialog *subDictumForm)
    {
        subDictumForm->setWindowTitle(QApplication::translate("subDictumForm", "Consecutivos", nullptr));
        reqOutGroupBox->setTitle(QString());
        menuGroupBox->setTitle(QString());
        label_5->setText(QApplication::translate("subDictumForm", "Dict\303\241men Consecutivo N\302\272", nullptr));
        subDictumNumberLineEdit->setInputMask(QString());
        subDictumNumberLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        updateSubDictumButton->setToolTip(QApplication::translate("subDictumForm", "Actualizar Consecutivo", nullptr));
#endif // QT_NO_TOOLTIP
        updateSubDictumButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveSubDictumButton->setToolTip(QApplication::translate("subDictumForm", "Guardar Cambios", nullptr));
#endif // QT_NO_TOOLTIP
        saveSubDictumButton->setText(QString());
        groupBox->setTitle(QString());
        label_15->setText(QApplication::translate("subDictumForm", "Observaciones", nullptr));
        subDictumObservTextEdit->setHtml(QApplication::translate("subDictumForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'DejaVu Sans';\"><br /></p></body></html>", nullptr));
        label_14->setText(QApplication::translate("subDictumForm", "Alcance", nullptr));
        label_12->setText(QApplication::translate("subDictumForm", "Carga", nullptr));
        subDictumInstRateDoubleSpinBox->setPrefix(QString());
        subDictumInstRateDoubleSpinBox->setSuffix(QApplication::translate("subDictumForm", " kVA", nullptr));
        label_8->setText(QApplication::translate("subDictumForm", "Estado T\303\251cnico", nullptr));
        label_4->setText(QApplication::translate("subDictumForm", "Fecha de Expedici\303\263n", nullptr));
        subDictumDateEdit->setDisplayFormat(QApplication::translate("subDictumForm", "dd 'de' MMM 'de' yyyy", nullptr));
        label_10->setText(QApplication::translate("subDictumForm", "Ubicaci\303\263n", nullptr));
        subDictumTypeLineEdit->setText(QString());
        subDictumTechStateLineEdit->setText(QString());
        label_16->setText(QApplication::translate("subDictumForm", "Identificador", nullptr));
        subDictumsNumberSpinBox->setSuffix(QString());
        prepareListButton->setText(QApplication::translate("subDictumForm", "Preparar", nullptr));
        subDictumLocationLineEdit->setText(QString());
        subDictumStateLineEdit->setText(QString());
        label_9->setText(QApplication::translate("subDictumForm", "Tipo", nullptr));
        subDictumInstVoltageLineEdit->setText(QApplication::translate("subDictumForm", "120/208", nullptr));
        label_13->setText(QApplication::translate("subDictumForm", "Tensi\303\263n (Volts)", nullptr));
        labelSubDictums->setText(QApplication::translate("subDictumForm", "Cantidad de Consecutivos", nullptr));
        subDictumInstResDoubleSpinBox->setSuffix(QApplication::translate("subDictumForm", " Ohms", nullptr));
        label_6->setText(QApplication::translate("subDictumForm", "Resistencia", nullptr));
        label->setText(QApplication::translate("subDictumForm", "Estado", nullptr));
        subDictumIdentifierLineEdit->setInputMask(QString());
        subDictumIdentifierLineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class subDictumForm: public Ui_subDictumForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBDICTUM_H
