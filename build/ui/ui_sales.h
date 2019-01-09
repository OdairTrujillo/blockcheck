/********************************************************************************
** Form generated from reading UI file 'sales.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALES_H
#define UI_SALES_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "qwebengineview.h"

QT_BEGIN_NAMESPACE

class Ui_salesForm
{
public:
    QGridLayout *gridLayout_20;
    QGroupBox *menuGroupBox;
    QGridLayout *gridLayout;
    QPushButton *findButton;
    QLabel *label_45;
    QPushButton *newButton;
    QPushButton *listButton;
    QPushButton *nextButton;
    QPushButton *prevButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;
    QSpacerItem *horizontalSpacer_10;
    QLCDNumber *quotLCD;
    QComboBox *findComboBox;
    QLineEdit *findLineEdit;
    QTabWidget *salesTabWidget;
    QWidget *quotationsTab;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QGroupBox *thirdPartyGroupBox;
    QGridLayout *gridLayout_15;
    QGridLayout *gridLayout_2;
    QLabel *label_15;
    QLabel *label_18;
    QLineEdit *thrdNameLineEdit;
    QLineEdit *thrdNitLineEdit;
    QLabel *label_16;
    QLabel *label_19;
    QLabel *label_21;
    QLineEdit *thrdAddressLineEdit;
    QComboBox *thrdCityComboBox;
    QLabel *label_20;
    QLabel *label_17;
    QLineEdit *thrdRepLineEdit;
    QLineEdit *thrdRepIdLineEdit;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLineEdit *thrdMailLineEdit;
    QLineEdit *thrdPhoneLineEdit;
    QLineEdit *thrdFaxLineEdit;
    QComboBox *thrdStateComboBox;
    QPushButton *quotGenButton;
    QGroupBox *instalationGroupBox;
    QGridLayout *gridLayout_14;
    QTextEdit *quotScopeTextEdit;
    QGridLayout *gridLayout_12;
    QLabel *label_39;
    QComboBox *inspecTypeComboBox;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *quotAddressLineEdit;
    QLineEdit *quotNameLineEdit;
    QLabel *label_5;
    QComboBox *quotStateComboBox;
    QLabel *label_4;
    QLineEdit *quotContactLineEdit;
    QLabel *label_6;
    QComboBox *quotCityComboBox;
    QLabel *label_10;
    QLineEdit *quotFaxLineEdit;
    QLabel *label_8;
    QLineEdit *quotPhoneLineEdit;
    QLabel *label_7;
    QLabel *label_12;
    QLineEdit *quotMailLineEdit;
    QComboBox *useTypeComboBox;
    QLabel *label_11;
    QListWidget *processesListWidget;
    QLabel *label_29;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_25;
    QDateEdit *quotDateEdit;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_44;
    QLCDNumber *foundLCD;
    QWidget *proposalsTab;
    QGridLayout *gridLayout_11;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_2;
    QDateEdit *propDateEdit;
    QSpacerItem *horizontalSpacer_14;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_7;
    QGroupBox *propDataGroupBox;
    QGridLayout *gridLayout_17;
    QGridLayout *gridLayout_16;
    QLabel *label_42;
    QLabel *label_36;
    QTableView *propValueTableView;
    QComboBox *propSoldByComboBox;
    QLabel *label_14;
    QComboBox *propPayWayComboBox;
    QLabel *label_37;
    QSpacerItem *verticalSpacer;
    QPushButton *propApprovButton;
    QPushButton *propRejectButton;
    QDoubleSpinBox *propUserPercSpinBox;
    QLabel *label_13;
    QLineEdit *propStateLineEdit;
    QLabel *label_47;
    QLineEdit *propStateDetailLineEdit;
    QTextEdit *propObservTextEdit;
    QGridLayout *gridLayout_5;
    QLabel *label_26;
    QLabel *label_32;
    QLineEdit *propThrdNameLineEdit;
    QLineEdit *propIdLineEdit;
    QLineEdit *propLocalizationLineEdit;
    QLineEdit *propInstNameLineEdit;
    QLabel *label_27;
    QLabel *label_31;
    QLabel *label_28;
    QTextEdit *propScopeTextEdit;
    QLabel *label_30;
    QLabel *label_9;
    QListWidget *propDocsListWidget;
    QGroupBox *propOutGroupBox;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *propPrintButton;
    QPushButton *propGenButton;
    QFrame *propOutFrame;
    QGridLayout *gridLayout_18;
    QWebEngineView *propOutWebView;
    QPushButton *propPreviewButton;
    QWidget *serviceOrdersTab;
    QGridLayout *gridLayout_13;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_40;
    QDateEdit *soDateEdit;
    QSpacerItem *horizontalSpacer_15;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_8;
    QGroupBox *osOutGroupBox_2;
    QGridLayout *gridLayout_10;
    QFrame *soFrame;
    QGridLayout *gridLayout_19;
    QWebEngineView *soOutWebView;
    QHBoxLayout *horizontalLayout_22;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *soPrintButton;
    QPushButton *soGenButton;
    QPushButton *soPreviewButton;
    QGroupBox *orderDataGroupBox_2;
    QGridLayout *gridLayout_21;
    QTextEdit *soAdmObservTextEdit;
    QLabel *label_43;
    QTextEdit *soScopeTextEdit;
    QLabel *label_41;
    QTextEdit *soObservTextEdit;
    QLabel *label_46;
    QGridLayout *gridLayout_9;
    QLineEdit *soAccStateLineEdit;
    QLabel *label_33;
    QLabel *label_35;
    QLineEdit *soIdLineEdit;
    QLabel *label_38;
    QLabel *soInspPercLabel;
    QSpacerItem *verticalSpacer_2;
    QComboBox *soInspectorsComboBox;
    QDateEdit *soAssignDateEdit;
    QListWidget *recordFoilListWidget;
    QLabel *soInspPercLabel_2;
    QDoubleSpinBox *soInspPercSpinBox;
    QLabel *label_34;

    void setupUi(QDialog *salesForm)
    {
        if (salesForm->objectName().isEmpty())
            salesForm->setObjectName(QString::fromUtf8("salesForm"));
        salesForm->setWindowModality(Qt::ApplicationModal);
        salesForm->resize(830, 609);
        salesForm->setMinimumSize(QSize(830, 609));
        salesForm->setMaximumSize(QSize(830, 655));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/sales.png"), QSize(), QIcon::Normal, QIcon::Off);
        salesForm->setWindowIcon(icon);
        gridLayout_20 = new QGridLayout(salesForm);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        gridLayout_20->setContentsMargins(2, 2, 2, 2);
        menuGroupBox = new QGroupBox(salesForm);
        menuGroupBox->setObjectName(QString::fromUtf8("menuGroupBox"));
        menuGroupBox->setMinimumSize(QSize(0, 45));
        menuGroupBox->setMaximumSize(QSize(16777215, 70));
        menuGroupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        menuGroupBox->setFlat(false);
        menuGroupBox->setCheckable(false);
        gridLayout = new QGridLayout(menuGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        findButton = new QPushButton(menuGroupBox);
        findButton->setObjectName(QString::fromUtf8("findButton"));
        findButton->setMinimumSize(QSize(30, 30));
        findButton->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/go.png"), QSize(), QIcon::Normal, QIcon::Off);
        findButton->setIcon(icon1);

        gridLayout->addWidget(findButton, 0, 5, 1, 1);

        label_45 = new QLabel(menuGroupBox);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        QFont font;
        font.setPointSize(12);
        label_45->setFont(font);
        label_45->setMargin(3);
        label_45->setIndent(0);

        gridLayout->addWidget(label_45, 0, 0, 1, 1);

        newButton = new QPushButton(menuGroupBox);
        newButton->setObjectName(QString::fromUtf8("newButton"));
        newButton->setEnabled(true);
        newButton->setMinimumSize(QSize(30, 30));
        newButton->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton->setIcon(icon2);

        gridLayout->addWidget(newButton, 0, 11, 1, 1);

        listButton = new QPushButton(menuGroupBox);
        listButton->setObjectName(QString::fromUtf8("listButton"));
        listButton->setMinimumSize(QSize(30, 30));
        listButton->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/list.png"), QSize(), QIcon::Normal, QIcon::Off);
        listButton->setIcon(icon3);

        gridLayout->addWidget(listButton, 0, 9, 1, 1);

        nextButton = new QPushButton(menuGroupBox);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setMinimumSize(QSize(30, 30));
        nextButton->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/go-next.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon4);

        gridLayout->addWidget(nextButton, 0, 8, 1, 1);

        prevButton = new QPushButton(menuGroupBox);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        prevButton->setMinimumSize(QSize(30, 30));
        prevButton->setMaximumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/go-previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevButton->setIcon(icon5);

        gridLayout->addWidget(prevButton, 0, 6, 1, 1);

        deleteButton = new QPushButton(menuGroupBox);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(true);
        deleteButton->setMinimumSize(QSize(30, 30));
        deleteButton->setMaximumSize(QSize(30, 30));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon6);

        gridLayout->addWidget(deleteButton, 0, 13, 1, 1);

        updateButton = new QPushButton(menuGroupBox);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setEnabled(true);
        updateButton->setMinimumSize(QSize(30, 30));
        updateButton->setMaximumSize(QSize(30, 30));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/icons/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        updateButton->setIcon(icon7);

        gridLayout->addWidget(updateButton, 0, 12, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(185, 27, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 0, 10, 1, 1);

        quotLCD = new QLCDNumber(menuGroupBox);
        quotLCD->setObjectName(QString::fromUtf8("quotLCD"));
        quotLCD->setMinimumSize(QSize(35, 0));
        quotLCD->setMaximumSize(QSize(35, 16777215));
        quotLCD->setSmallDecimalPoint(false);
        quotLCD->setDigitCount(2);
        quotLCD->setSegmentStyle(QLCDNumber::Filled);
        quotLCD->setProperty("intValue", QVariant(0));

        gridLayout->addWidget(quotLCD, 0, 7, 1, 1);

        findComboBox = new QComboBox(menuGroupBox);
        findComboBox->setObjectName(QString::fromUtf8("findComboBox"));
        findComboBox->setMinimumSize(QSize(150, 24));
        QFont font1;
        font1.setPointSize(11);
        findComboBox->setFont(font1);

        gridLayout->addWidget(findComboBox, 0, 3, 1, 1);

        findLineEdit = new QLineEdit(menuGroupBox);
        findLineEdit->setObjectName(QString::fromUtf8("findLineEdit"));
        findLineEdit->setMinimumSize(QSize(0, 24));
        findLineEdit->setMaximumSize(QSize(200, 16777215));
        findLineEdit->setFont(font1);

        gridLayout->addWidget(findLineEdit, 0, 1, 1, 1);


        gridLayout_20->addWidget(menuGroupBox, 0, 0, 1, 1);

        salesTabWidget = new QTabWidget(salesForm);
        salesTabWidget->setObjectName(QString::fromUtf8("salesTabWidget"));
        salesTabWidget->setFont(font);
        quotationsTab = new QWidget();
        quotationsTab->setObjectName(QString::fromUtf8("quotationsTab"));
        gridLayout_4 = new QGridLayout(quotationsTab);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        scrollArea = new QScrollArea(quotationsTab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 783, 650));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 650));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        thirdPartyGroupBox = new QGroupBox(scrollAreaWidgetContents);
        thirdPartyGroupBox->setObjectName(QString::fromUtf8("thirdPartyGroupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(thirdPartyGroupBox->sizePolicy().hasHeightForWidth());
        thirdPartyGroupBox->setSizePolicy(sizePolicy1);
        thirdPartyGroupBox->setMinimumSize(QSize(0, 0));
        thirdPartyGroupBox->setMaximumSize(QSize(16777215, 16777215));
        thirdPartyGroupBox->setFont(font);
        gridLayout_15 = new QGridLayout(thirdPartyGroupBox);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(6);
        gridLayout_2->setVerticalSpacing(0);
        label_15 = new QLabel(thirdPartyGroupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font1);
        label_15->setIndent(4);

        gridLayout_2->addWidget(label_15, 0, 0, 1, 3);

        label_18 = new QLabel(thirdPartyGroupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font1);
        label_18->setIndent(4);

        gridLayout_2->addWidget(label_18, 0, 3, 1, 1);

        thrdNameLineEdit = new QLineEdit(thirdPartyGroupBox);
        thrdNameLineEdit->setObjectName(QString::fromUtf8("thrdNameLineEdit"));
        thrdNameLineEdit->setMinimumSize(QSize(0, 24));

        gridLayout_2->addWidget(thrdNameLineEdit, 1, 0, 1, 3);

        thrdNitLineEdit = new QLineEdit(thirdPartyGroupBox);
        thrdNitLineEdit->setObjectName(QString::fromUtf8("thrdNitLineEdit"));
        thrdNitLineEdit->setMinimumSize(QSize(0, 24));

        gridLayout_2->addWidget(thrdNitLineEdit, 1, 3, 1, 1);

        label_16 = new QLabel(thirdPartyGroupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font1);
        label_16->setIndent(4);

        gridLayout_2->addWidget(label_16, 2, 0, 1, 1);

        label_19 = new QLabel(thirdPartyGroupBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font1);
        label_19->setIndent(4);

        gridLayout_2->addWidget(label_19, 2, 1, 1, 1);

        label_21 = new QLabel(thirdPartyGroupBox);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font1);
        label_21->setIndent(4);

        gridLayout_2->addWidget(label_21, 2, 2, 1, 1);

        thrdAddressLineEdit = new QLineEdit(thirdPartyGroupBox);
        thrdAddressLineEdit->setObjectName(QString::fromUtf8("thrdAddressLineEdit"));
        thrdAddressLineEdit->setMinimumSize(QSize(0, 24));

        gridLayout_2->addWidget(thrdAddressLineEdit, 3, 0, 1, 1);

        thrdCityComboBox = new QComboBox(thirdPartyGroupBox);
        thrdCityComboBox->setObjectName(QString::fromUtf8("thrdCityComboBox"));
        thrdCityComboBox->setMinimumSize(QSize(0, 24));

        gridLayout_2->addWidget(thrdCityComboBox, 3, 2, 1, 1);

        label_20 = new QLabel(thirdPartyGroupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font1);
        label_20->setIndent(4);

        gridLayout_2->addWidget(label_20, 4, 3, 1, 1);

        label_17 = new QLabel(thirdPartyGroupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setIndent(4);

        gridLayout_2->addWidget(label_17, 4, 0, 1, 3);

        thrdRepLineEdit = new QLineEdit(thirdPartyGroupBox);
        thrdRepLineEdit->setObjectName(QString::fromUtf8("thrdRepLineEdit"));
        thrdRepLineEdit->setMinimumSize(QSize(0, 24));

        gridLayout_2->addWidget(thrdRepLineEdit, 5, 0, 1, 3);

        thrdRepIdLineEdit = new QLineEdit(thirdPartyGroupBox);
        thrdRepIdLineEdit->setObjectName(QString::fromUtf8("thrdRepIdLineEdit"));
        thrdRepIdLineEdit->setMinimumSize(QSize(0, 24));

        gridLayout_2->addWidget(thrdRepIdLineEdit, 5, 3, 1, 1);

        label_22 = new QLabel(thirdPartyGroupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font1);
        label_22->setIndent(4);

        gridLayout_2->addWidget(label_22, 6, 0, 1, 1);

        label_23 = new QLabel(thirdPartyGroupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font1);
        label_23->setIndent(4);

        gridLayout_2->addWidget(label_23, 6, 1, 1, 1);

        label_24 = new QLabel(thirdPartyGroupBox);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setFont(font1);
        label_24->setIndent(4);

        gridLayout_2->addWidget(label_24, 6, 2, 1, 1);

        thrdMailLineEdit = new QLineEdit(thirdPartyGroupBox);
        thrdMailLineEdit->setObjectName(QString::fromUtf8("thrdMailLineEdit"));
        thrdMailLineEdit->setMinimumSize(QSize(0, 24));

        gridLayout_2->addWidget(thrdMailLineEdit, 7, 0, 1, 1);

        thrdPhoneLineEdit = new QLineEdit(thirdPartyGroupBox);
        thrdPhoneLineEdit->setObjectName(QString::fromUtf8("thrdPhoneLineEdit"));
        thrdPhoneLineEdit->setMinimumSize(QSize(0, 24));

        gridLayout_2->addWidget(thrdPhoneLineEdit, 7, 1, 1, 1);

        thrdFaxLineEdit = new QLineEdit(thirdPartyGroupBox);
        thrdFaxLineEdit->setObjectName(QString::fromUtf8("thrdFaxLineEdit"));
        thrdFaxLineEdit->setMinimumSize(QSize(0, 24));

        gridLayout_2->addWidget(thrdFaxLineEdit, 7, 2, 1, 1);

        thrdStateComboBox = new QComboBox(thirdPartyGroupBox);
        thrdStateComboBox->setObjectName(QString::fromUtf8("thrdStateComboBox"));
        thrdStateComboBox->setMinimumSize(QSize(0, 24));

        gridLayout_2->addWidget(thrdStateComboBox, 3, 1, 1, 1);


        gridLayout_15->addLayout(gridLayout_2, 0, 0, 1, 1);

        quotGenButton = new QPushButton(thirdPartyGroupBox);
        quotGenButton->setObjectName(QString::fromUtf8("quotGenButton"));
        quotGenButton->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/icons/generate.png"), QSize(), QIcon::Normal, QIcon::Off);
        quotGenButton->setIcon(icon8);

        gridLayout_15->addWidget(quotGenButton, 1, 0, 1, 1);


        gridLayout_3->addWidget(thirdPartyGroupBox, 7, 0, 1, 2);

        instalationGroupBox = new QGroupBox(scrollAreaWidgetContents);
        instalationGroupBox->setObjectName(QString::fromUtf8("instalationGroupBox"));
        sizePolicy1.setHeightForWidth(instalationGroupBox->sizePolicy().hasHeightForWidth());
        instalationGroupBox->setSizePolicy(sizePolicy1);
        instalationGroupBox->setMinimumSize(QSize(0, 0));
        instalationGroupBox->setMaximumSize(QSize(16777215, 16777215));
        instalationGroupBox->setFont(font);
        gridLayout_14 = new QGridLayout(instalationGroupBox);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(4, 4, 4, 4);
        quotScopeTextEdit = new QTextEdit(instalationGroupBox);
        quotScopeTextEdit->setObjectName(QString::fromUtf8("quotScopeTextEdit"));
        quotScopeTextEdit->setMaximumSize(QSize(16777215, 200));
        quotScopeTextEdit->setFont(font);
        quotScopeTextEdit->setFrameShape(QFrame::StyledPanel);
        quotScopeTextEdit->setFrameShadow(QFrame::Sunken);
        quotScopeTextEdit->setLineWidth(1);
        quotScopeTextEdit->setMidLineWidth(0);
        quotScopeTextEdit->setTabChangesFocus(true);
        quotScopeTextEdit->setHtml(QString::fromUtf8("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans';\"><br /></span></p></body></html>"));
        quotScopeTextEdit->setAcceptRichText(false);

        gridLayout_14->addWidget(quotScopeTextEdit, 4, 0, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_12->setHorizontalSpacing(6);
        gridLayout_12->setVerticalSpacing(1);
        gridLayout_12->setContentsMargins(1, 1, 2, 6);
        label_39 = new QLabel(instalationGroupBox);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setFont(font1);
        label_39->setIndent(4);

        gridLayout_12->addWidget(label_39, 2, 2, 1, 1);

        inspecTypeComboBox = new QComboBox(instalationGroupBox);
        inspecTypeComboBox->addItem(QString());
        inspecTypeComboBox->addItem(QString());
        inspecTypeComboBox->addItem(QString());
        inspecTypeComboBox->setObjectName(QString::fromUtf8("inspecTypeComboBox"));

        gridLayout_12->addWidget(inspecTypeComboBox, 3, 2, 1, 1);

        label_3 = new QLabel(instalationGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setIndent(4);

        gridLayout_12->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(instalationGroupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);
        label->setIndent(4);

        gridLayout_12->addWidget(label, 0, 0, 1, 3);

        quotAddressLineEdit = new QLineEdit(instalationGroupBox);
        quotAddressLineEdit->setObjectName(QString::fromUtf8("quotAddressLineEdit"));
        quotAddressLineEdit->setMinimumSize(QSize(200, 24));

        gridLayout_12->addWidget(quotAddressLineEdit, 3, 0, 1, 1);

        quotNameLineEdit = new QLineEdit(instalationGroupBox);
        quotNameLineEdit->setObjectName(QString::fromUtf8("quotNameLineEdit"));
        quotNameLineEdit->setMinimumSize(QSize(480, 24));

        gridLayout_12->addWidget(quotNameLineEdit, 1, 0, 1, 3);

        label_5 = new QLabel(instalationGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setIndent(4);

        gridLayout_12->addWidget(label_5, 4, 0, 1, 1);

        quotStateComboBox = new QComboBox(instalationGroupBox);
        quotStateComboBox->setObjectName(QString::fromUtf8("quotStateComboBox"));
        quotStateComboBox->setMinimumSize(QSize(0, 24));

        gridLayout_12->addWidget(quotStateComboBox, 5, 0, 1, 1);

        label_4 = new QLabel(instalationGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setIndent(4);

        gridLayout_12->addWidget(label_4, 2, 1, 1, 1);

        quotContactLineEdit = new QLineEdit(instalationGroupBox);
        quotContactLineEdit->setObjectName(QString::fromUtf8("quotContactLineEdit"));
        quotContactLineEdit->setMinimumSize(QSize(0, 24));

        gridLayout_12->addWidget(quotContactLineEdit, 3, 1, 1, 1);

        label_6 = new QLabel(instalationGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 20));
        label_6->setFont(font1);
        label_6->setIndent(4);

        gridLayout_12->addWidget(label_6, 6, 0, 1, 1);

        quotCityComboBox = new QComboBox(instalationGroupBox);
        quotCityComboBox->setObjectName(QString::fromUtf8("quotCityComboBox"));
        quotCityComboBox->setMinimumSize(QSize(0, 24));

        gridLayout_12->addWidget(quotCityComboBox, 7, 0, 1, 1);

        label_10 = new QLabel(instalationGroupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);
        label_10->setIndent(4);

        gridLayout_12->addWidget(label_10, 4, 1, 1, 1);

        quotFaxLineEdit = new QLineEdit(instalationGroupBox);
        quotFaxLineEdit->setObjectName(QString::fromUtf8("quotFaxLineEdit"));
        quotFaxLineEdit->setMinimumSize(QSize(0, 24));
        quotFaxLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_12->addWidget(quotFaxLineEdit, 5, 1, 1, 1);

        label_8 = new QLabel(instalationGroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 0));
        label_8->setFont(font1);
        label_8->setIndent(4);

        gridLayout_12->addWidget(label_8, 6, 1, 1, 1);

        quotPhoneLineEdit = new QLineEdit(instalationGroupBox);
        quotPhoneLineEdit->setObjectName(QString::fromUtf8("quotPhoneLineEdit"));
        quotPhoneLineEdit->setMinimumSize(QSize(0, 24));

        gridLayout_12->addWidget(quotPhoneLineEdit, 7, 1, 1, 1);

        label_7 = new QLabel(instalationGroupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setIndent(4);

        gridLayout_12->addWidget(label_7, 8, 0, 1, 1);

        label_12 = new QLabel(instalationGroupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);
        label_12->setIndent(4);

        gridLayout_12->addWidget(label_12, 8, 1, 1, 1);

        quotMailLineEdit = new QLineEdit(instalationGroupBox);
        quotMailLineEdit->setObjectName(QString::fromUtf8("quotMailLineEdit"));
        quotMailLineEdit->setMinimumSize(QSize(0, 24));
        quotMailLineEdit->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_12->addWidget(quotMailLineEdit, 9, 0, 3, 1);

        useTypeComboBox = new QComboBox(instalationGroupBox);
        useTypeComboBox->setObjectName(QString::fromUtf8("useTypeComboBox"));
        useTypeComboBox->setMinimumSize(QSize(0, 24));
        useTypeComboBox->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_12->addWidget(useTypeComboBox, 9, 1, 3, 1);

        label_11 = new QLabel(instalationGroupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(0, 20));
        label_11->setFont(font1);
        label_11->setIndent(4);

        gridLayout_12->addWidget(label_11, 4, 2, 1, 1);

        processesListWidget = new QListWidget(instalationGroupBox);
        processesListWidget->setObjectName(QString::fromUtf8("processesListWidget"));
        QPalette palette;
        QBrush brush(QColor(48, 103, 158, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        QBrush brush1(QColor(132, 160, 184, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        QBrush brush2(QColor(155, 155, 155, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        processesListWidget->setPalette(palette);
        processesListWidget->setFont(font);
        processesListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        processesListWidget->setAlternatingRowColors(false);
        processesListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

        gridLayout_12->addWidget(processesListWidget, 5, 2, 7, 1);


        gridLayout_14->addLayout(gridLayout_12, 2, 0, 1, 1);

        label_29 = new QLabel(instalationGroupBox);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font1);
        label_29->setIndent(4);

        gridLayout_14->addWidget(label_29, 3, 0, 1, 1);


        gridLayout_3->addWidget(instalationGroupBox, 2, 0, 2, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_4->addWidget(scrollArea, 1, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_25 = new QLabel(quotationsTab);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font1);

        horizontalLayout_11->addWidget(label_25);

        quotDateEdit = new QDateEdit(quotationsTab);
        quotDateEdit->setObjectName(QString::fromUtf8("quotDateEdit"));
        quotDateEdit->setAccelerated(false);
        quotDateEdit->setCalendarPopup(true);

        horizontalLayout_11->addWidget(quotDateEdit);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);

        label_44 = new QLabel(quotationsTab);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setFont(font1);

        horizontalLayout_11->addWidget(label_44);

        foundLCD = new QLCDNumber(quotationsTab);
        foundLCD->setObjectName(QString::fromUtf8("foundLCD"));
        foundLCD->setMinimumSize(QSize(35, 30));
        foundLCD->setMaximumSize(QSize(35, 16777215));
        foundLCD->setSmallDecimalPoint(false);
        foundLCD->setDigitCount(2);
        foundLCD->setSegmentStyle(QLCDNumber::Filled);
        foundLCD->setProperty("intValue", QVariant(0));

        horizontalLayout_11->addWidget(foundLCD);


        gridLayout_4->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        salesTabWidget->addTab(quotationsTab, QString());
        proposalsTab = new QWidget();
        proposalsTab->setObjectName(QString::fromUtf8("proposalsTab"));
        gridLayout_11 = new QGridLayout(proposalsTab);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_2 = new QLabel(proposalsTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout_20->addWidget(label_2);

        propDateEdit = new QDateEdit(proposalsTab);
        propDateEdit->setObjectName(QString::fromUtf8("propDateEdit"));
        propDateEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        propDateEdit->setCalendarPopup(true);
        propDateEdit->setDate(QDate(2000, 1, 1));

        horizontalLayout_20->addWidget(propDateEdit);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_14);


        gridLayout_11->addLayout(horizontalLayout_20, 0, 0, 1, 1);

        scrollArea_2 = new QScrollArea(proposalsTab);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setMinimumSize(QSize(600, 0));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 783, 1334));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_2->setSizePolicy(sizePolicy2);
        scrollAreaWidgetContents_2->setMinimumSize(QSize(0, 0));
        gridLayout_7 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        propDataGroupBox = new QGroupBox(scrollAreaWidgetContents_2);
        propDataGroupBox->setObjectName(QString::fromUtf8("propDataGroupBox"));
        propDataGroupBox->setMinimumSize(QSize(0, 0));
        propDataGroupBox->setMaximumSize(QSize(16777215, 950));
        propDataGroupBox->setFont(font);
        gridLayout_17 = new QGridLayout(propDataGroupBox);
        gridLayout_17->setSpacing(0);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(4, 4, 4, 0);
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setHorizontalSpacing(6);
        gridLayout_16->setVerticalSpacing(0);
        gridLayout_16->setContentsMargins(-1, -1, 0, -1);
        label_42 = new QLabel(propDataGroupBox);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setFont(font1);
        label_42->setIndent(4);

        gridLayout_16->addWidget(label_42, 5, 1, 1, 1);

        label_36 = new QLabel(propDataGroupBox);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setFont(font1);

        gridLayout_16->addWidget(label_36, 0, 0, 1, 1);

        propValueTableView = new QTableView(propDataGroupBox);
        propValueTableView->setObjectName(QString::fromUtf8("propValueTableView"));
        propValueTableView->setMinimumSize(QSize(360, 150));
        propValueTableView->setMaximumSize(QSize(16777215, 150));
        propValueTableView->setFont(font);
        propValueTableView->setAlternatingRowColors(true);

        gridLayout_16->addWidget(propValueTableView, 1, 0, 8, 1);

        propSoldByComboBox = new QComboBox(propDataGroupBox);
        propSoldByComboBox->setObjectName(QString::fromUtf8("propSoldByComboBox"));
        propSoldByComboBox->setMinimumSize(QSize(0, 24));

        gridLayout_16->addWidget(propSoldByComboBox, 4, 1, 1, 1);

        label_14 = new QLabel(propDataGroupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);
        label_14->setIndent(4);

        gridLayout_16->addWidget(label_14, 3, 1, 1, 1);

        propPayWayComboBox = new QComboBox(propDataGroupBox);
        propPayWayComboBox->setObjectName(QString::fromUtf8("propPayWayComboBox"));
        propPayWayComboBox->setMinimumSize(QSize(200, 24));
        propPayWayComboBox->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_16->addWidget(propPayWayComboBox, 2, 1, 1, 1);

        label_37 = new QLabel(propDataGroupBox);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setFont(font1);
        label_37->setIndent(4);

        gridLayout_16->addWidget(label_37, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_16->addItem(verticalSpacer, 7, 1, 1, 1);

        propApprovButton = new QPushButton(propDataGroupBox);
        propApprovButton->setObjectName(QString::fromUtf8("propApprovButton"));
        propApprovButton->setEnabled(true);
        propApprovButton->setMinimumSize(QSize(0, 0));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/icons/approb.png"), QSize(), QIcon::Normal, QIcon::Off);
        propApprovButton->setIcon(icon9);

        gridLayout_16->addWidget(propApprovButton, 8, 1, 1, 1);

        propRejectButton = new QPushButton(propDataGroupBox);
        propRejectButton->setObjectName(QString::fromUtf8("propRejectButton"));
        propRejectButton->setEnabled(true);
        propRejectButton->setMinimumSize(QSize(0, 0));
        propRejectButton->setIcon(icon6);

        gridLayout_16->addWidget(propRejectButton, 8, 2, 1, 1);

        propUserPercSpinBox = new QDoubleSpinBox(propDataGroupBox);
        propUserPercSpinBox->setObjectName(QString::fromUtf8("propUserPercSpinBox"));
        propUserPercSpinBox->setMinimumSize(QSize(180, 24));
        propUserPercSpinBox->setDecimals(0);
        propUserPercSpinBox->setValue(20.000000000000000);

        gridLayout_16->addWidget(propUserPercSpinBox, 6, 1, 1, 1);

        label_13 = new QLabel(propDataGroupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);
        label_13->setIndent(4);

        gridLayout_16->addWidget(label_13, 1, 2, 1, 1);

        propStateLineEdit = new QLineEdit(propDataGroupBox);
        propStateLineEdit->setObjectName(QString::fromUtf8("propStateLineEdit"));
        propStateLineEdit->setEnabled(true);
        propStateLineEdit->setMaximumSize(QSize(16777215, 16777215));
        propStateLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        propStateLineEdit->setReadOnly(true);

        gridLayout_16->addWidget(propStateLineEdit, 2, 2, 1, 1);

        label_47 = new QLabel(propDataGroupBox);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setFont(font1);
        label_47->setIndent(4);

        gridLayout_16->addWidget(label_47, 3, 2, 1, 1);

        propStateDetailLineEdit = new QLineEdit(propDataGroupBox);
        propStateDetailLineEdit->setObjectName(QString::fromUtf8("propStateDetailLineEdit"));
        propStateDetailLineEdit->setEnabled(true);
        propStateDetailLineEdit->setMaximumSize(QSize(16777215, 16777215));
        propStateDetailLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        propStateDetailLineEdit->setReadOnly(true);

        gridLayout_16->addWidget(propStateDetailLineEdit, 4, 2, 1, 1);


        gridLayout_17->addLayout(gridLayout_16, 5, 0, 1, 1);

        propObservTextEdit = new QTextEdit(propDataGroupBox);
        propObservTextEdit->setObjectName(QString::fromUtf8("propObservTextEdit"));
        propObservTextEdit->setMaximumSize(QSize(16777215, 90));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        propObservTextEdit->setFont(font2);
        propObservTextEdit->setTabChangesFocus(true);
        propObservTextEdit->setAcceptRichText(false);

        gridLayout_17->addWidget(propObservTextEdit, 7, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_26 = new QLabel(propDataGroupBox);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font1);

        gridLayout_5->addWidget(label_26, 0, 0, 1, 1);

        label_32 = new QLabel(propDataGroupBox);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setFont(font1);

        gridLayout_5->addWidget(label_32, 0, 1, 1, 1);

        propThrdNameLineEdit = new QLineEdit(propDataGroupBox);
        propThrdNameLineEdit->setObjectName(QString::fromUtf8("propThrdNameLineEdit"));
        propThrdNameLineEdit->setMinimumSize(QSize(0, 24));

        gridLayout_5->addWidget(propThrdNameLineEdit, 1, 0, 1, 1);

        propIdLineEdit = new QLineEdit(propDataGroupBox);
        propIdLineEdit->setObjectName(QString::fromUtf8("propIdLineEdit"));
        propIdLineEdit->setMinimumSize(QSize(0, 24));
        QPalette palette1;
        QBrush brush3(QColor(200, 200, 200, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        propIdLineEdit->setPalette(palette1);
        propIdLineEdit->setAutoFillBackground(false);
        propIdLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        propIdLineEdit->setFrame(true);
        propIdLineEdit->setReadOnly(true);

        gridLayout_5->addWidget(propIdLineEdit, 1, 1, 1, 1);

        propLocalizationLineEdit = new QLineEdit(propDataGroupBox);
        propLocalizationLineEdit->setObjectName(QString::fromUtf8("propLocalizationLineEdit"));
        propLocalizationLineEdit->setMinimumSize(QSize(0, 24));

        gridLayout_5->addWidget(propLocalizationLineEdit, 4, 0, 2, 1);

        propInstNameLineEdit = new QLineEdit(propDataGroupBox);
        propInstNameLineEdit->setObjectName(QString::fromUtf8("propInstNameLineEdit"));
        propInstNameLineEdit->setMinimumSize(QSize(200, 24));
        propInstNameLineEdit->setFrame(true);

        gridLayout_5->addWidget(propInstNameLineEdit, 4, 1, 2, 1);

        label_27 = new QLabel(propDataGroupBox);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font1);

        gridLayout_5->addWidget(label_27, 2, 1, 2, 1);

        label_31 = new QLabel(propDataGroupBox);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font1);

        gridLayout_5->addWidget(label_31, 2, 0, 2, 1);


        gridLayout_17->addLayout(gridLayout_5, 0, 0, 1, 1);

        label_28 = new QLabel(propDataGroupBox);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font1);

        gridLayout_17->addWidget(label_28, 1, 0, 1, 1);

        propScopeTextEdit = new QTextEdit(propDataGroupBox);
        propScopeTextEdit->setObjectName(QString::fromUtf8("propScopeTextEdit"));
        propScopeTextEdit->setMinimumSize(QSize(0, 0));
        propScopeTextEdit->setMaximumSize(QSize(16777215, 90));
        propScopeTextEdit->setFont(font);
        propScopeTextEdit->setTabChangesFocus(true);
        propScopeTextEdit->setAcceptRichText(false);

        gridLayout_17->addWidget(propScopeTextEdit, 2, 0, 1, 1);

        label_30 = new QLabel(propDataGroupBox);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setFont(font1);

        gridLayout_17->addWidget(label_30, 3, 0, 1, 1);

        label_9 = new QLabel(propDataGroupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        gridLayout_17->addWidget(label_9, 6, 0, 1, 1);

        propDocsListWidget = new QListWidget(propDataGroupBox);
        propDocsListWidget->setObjectName(QString::fromUtf8("propDocsListWidget"));
        propDocsListWidget->setMinimumSize(QSize(0, 250));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        propDocsListWidget->setPalette(palette2);
        QFont font3;
        font3.setPointSize(11);
        font3.setItalic(true);
        propDocsListWidget->setFont(font3);
        propDocsListWidget->setMouseTracking(true);
        propDocsListWidget->setAlternatingRowColors(true);
        propDocsListWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        propDocsListWidget->setTextElideMode(Qt::ElideRight);
        propDocsListWidget->setFlow(QListView::TopToBottom);
        propDocsListWidget->setProperty("isWrapping", QVariant(true));
        propDocsListWidget->setSpacing(1);
        propDocsListWidget->setViewMode(QListView::ListMode);
        propDocsListWidget->setUniformItemSizes(true);
        propDocsListWidget->setWordWrap(false);
        propDocsListWidget->setSelectionRectVisible(true);

        gridLayout_17->addWidget(propDocsListWidget, 4, 0, 1, 1);


        gridLayout_7->addWidget(propDataGroupBox, 0, 0, 1, 1);

        propOutGroupBox = new QGroupBox(scrollAreaWidgetContents_2);
        propOutGroupBox->setObjectName(QString::fromUtf8("propOutGroupBox"));
        propOutGroupBox->setCheckable(false);
        gridLayout_6 = new QGridLayout(propOutGroupBox);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 1);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_9);

        propPrintButton = new QPushButton(propOutGroupBox);
        propPrintButton->setObjectName(QString::fromUtf8("propPrintButton"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/icons/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        propPrintButton->setIcon(icon10);

        horizontalLayout_17->addWidget(propPrintButton);


        gridLayout_6->addLayout(horizontalLayout_17, 3, 0, 1, 1);

        propGenButton = new QPushButton(propOutGroupBox);
        propGenButton->setObjectName(QString::fromUtf8("propGenButton"));
        propGenButton->setEnabled(false);
        propGenButton->setIcon(icon8);

        gridLayout_6->addWidget(propGenButton, 0, 0, 1, 1);

        propOutFrame = new QFrame(propOutGroupBox);
        propOutFrame->setObjectName(QString::fromUtf8("propOutFrame"));
        propOutFrame->setMinimumSize(QSize(0, 500));
        propOutFrame->setMaximumSize(QSize(16777215, 16777215));
        propOutFrame->setFrameShape(QFrame::StyledPanel);
        propOutFrame->setFrameShadow(QFrame::Sunken);
        gridLayout_18 = new QGridLayout(propOutFrame);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(1, 1, 1, 1);
        propOutWebView = new QWebEngineView(propOutFrame);
        propOutWebView->setObjectName(QString::fromUtf8("propOutWebView"));
        propOutWebView->setMaximumSize(QSize(16777215, 16777215));
        propOutWebView->setProperty("url", QVariant(QUrl(QString::fromUtf8("about:blank"))));
        propOutWebView->setProperty("zoomFactor", QVariant(1.000000000000000));

        gridLayout_18->addWidget(propOutWebView, 0, 0, 1, 1);


        gridLayout_6->addWidget(propOutFrame, 2, 0, 1, 1);

        propPreviewButton = new QPushButton(propOutGroupBox);
        propPreviewButton->setObjectName(QString::fromUtf8("propPreviewButton"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/icons/preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        propPreviewButton->setIcon(icon11);

        gridLayout_6->addWidget(propPreviewButton, 1, 0, 1, 1);


        gridLayout_7->addWidget(propOutGroupBox, 2, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_11->addWidget(scrollArea_2, 1, 0, 1, 1);

        salesTabWidget->addTab(proposalsTab, QString());
        serviceOrdersTab = new QWidget();
        serviceOrdersTab->setObjectName(QString::fromUtf8("serviceOrdersTab"));
        gridLayout_13 = new QGridLayout(serviceOrdersTab);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_40 = new QLabel(serviceOrdersTab);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setFont(font1);

        horizontalLayout_23->addWidget(label_40);

        soDateEdit = new QDateEdit(serviceOrdersTab);
        soDateEdit->setObjectName(QString::fromUtf8("soDateEdit"));
        soDateEdit->setCalendarPopup(true);

        horizontalLayout_23->addWidget(soDateEdit);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_15);


        gridLayout_13->addLayout(horizontalLayout_23, 0, 0, 1, 1);

        scrollArea_3 = new QScrollArea(serviceOrdersTab);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setMinimumSize(QSize(0, 0));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 783, 1146));
        scrollAreaWidgetContents_3->setMinimumSize(QSize(0, 0));
        gridLayout_8 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        osOutGroupBox_2 = new QGroupBox(scrollAreaWidgetContents_3);
        osOutGroupBox_2->setObjectName(QString::fromUtf8("osOutGroupBox_2"));
        osOutGroupBox_2->setCheckable(false);
        gridLayout_10 = new QGridLayout(osOutGroupBox_2);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 1);
        soFrame = new QFrame(osOutGroupBox_2);
        soFrame->setObjectName(QString::fromUtf8("soFrame"));
        soFrame->setMinimumSize(QSize(0, 600));
        soFrame->setFrameShape(QFrame::StyledPanel);
        soFrame->setFrameShadow(QFrame::Sunken);
        gridLayout_19 = new QGridLayout(soFrame);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setContentsMargins(1, 1, 1, 1);
        soOutWebView = new QWebEngineView(soFrame);
        soOutWebView->setObjectName(QString::fromUtf8("soOutWebView"));
        soOutWebView->setProperty("url", QVariant(QUrl(QString::fromUtf8("about:blank"))));

        gridLayout_19->addWidget(soOutWebView, 0, 0, 1, 1);


        gridLayout_10->addWidget(soFrame, 7, 0, 1, 1);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_12);

        soPrintButton = new QPushButton(osOutGroupBox_2);
        soPrintButton->setObjectName(QString::fromUtf8("soPrintButton"));
        soPrintButton->setIcon(icon10);

        horizontalLayout_22->addWidget(soPrintButton);


        gridLayout_10->addLayout(horizontalLayout_22, 9, 0, 1, 1);

        soGenButton = new QPushButton(osOutGroupBox_2);
        soGenButton->setObjectName(QString::fromUtf8("soGenButton"));
        soGenButton->setEnabled(false);
        soGenButton->setIcon(icon8);

        gridLayout_10->addWidget(soGenButton, 5, 0, 1, 1);

        soPreviewButton = new QPushButton(osOutGroupBox_2);
        soPreviewButton->setObjectName(QString::fromUtf8("soPreviewButton"));
        soPreviewButton->setIcon(icon11);

        gridLayout_10->addWidget(soPreviewButton, 6, 0, 1, 1);


        gridLayout_8->addWidget(osOutGroupBox_2, 1, 0, 1, 1);

        orderDataGroupBox_2 = new QGroupBox(scrollAreaWidgetContents_3);
        orderDataGroupBox_2->setObjectName(QString::fromUtf8("orderDataGroupBox_2"));
        orderDataGroupBox_2->setMaximumSize(QSize(16777215, 16777215));
        orderDataGroupBox_2->setFont(font2);
        gridLayout_21 = new QGridLayout(orderDataGroupBox_2);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_21->setContentsMargins(4, 4, 4, 4);
        soAdmObservTextEdit = new QTextEdit(orderDataGroupBox_2);
        soAdmObservTextEdit->setObjectName(QString::fromUtf8("soAdmObservTextEdit"));
        soAdmObservTextEdit->setMinimumSize(QSize(0, 0));
        soAdmObservTextEdit->setMaximumSize(QSize(16777215, 16777215));
        soAdmObservTextEdit->setFont(font);
        soAdmObservTextEdit->setTabChangesFocus(true);
        soAdmObservTextEdit->setReadOnly(true);
        soAdmObservTextEdit->setAcceptRichText(false);

        gridLayout_21->addWidget(soAdmObservTextEdit, 6, 0, 1, 1);

        label_43 = new QLabel(orderDataGroupBox_2);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setFont(font1);
        label_43->setIndent(4);

        gridLayout_21->addWidget(label_43, 1, 0, 1, 1);

        soScopeTextEdit = new QTextEdit(orderDataGroupBox_2);
        soScopeTextEdit->setObjectName(QString::fromUtf8("soScopeTextEdit"));
        soScopeTextEdit->setMinimumSize(QSize(0, 100));
        soScopeTextEdit->setFont(font);
        soScopeTextEdit->setTabChangesFocus(true);
        soScopeTextEdit->setAcceptRichText(false);

        gridLayout_21->addWidget(soScopeTextEdit, 2, 0, 1, 1);

        label_41 = new QLabel(orderDataGroupBox_2);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setFont(font1);
        label_41->setIndent(4);

        gridLayout_21->addWidget(label_41, 3, 0, 1, 1);

        soObservTextEdit = new QTextEdit(orderDataGroupBox_2);
        soObservTextEdit->setObjectName(QString::fromUtf8("soObservTextEdit"));
        soObservTextEdit->setMinimumSize(QSize(0, 0));
        soObservTextEdit->setMaximumSize(QSize(16777215, 16777215));
        soObservTextEdit->setFont(font);
        soObservTextEdit->setTabChangesFocus(true);
        soObservTextEdit->setAcceptRichText(false);

        gridLayout_21->addWidget(soObservTextEdit, 4, 0, 1, 1);

        label_46 = new QLabel(orderDataGroupBox_2);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setFont(font1);
        label_46->setIndent(4);

        gridLayout_21->addWidget(label_46, 5, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        soAccStateLineEdit = new QLineEdit(orderDataGroupBox_2);
        soAccStateLineEdit->setObjectName(QString::fromUtf8("soAccStateLineEdit"));
        soAccStateLineEdit->setMinimumSize(QSize(150, 24));
        soAccStateLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        soAccStateLineEdit->setReadOnly(true);

        gridLayout_9->addWidget(soAccStateLineEdit, 1, 2, 1, 3);

        label_33 = new QLabel(orderDataGroupBox_2);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font1);

        gridLayout_9->addWidget(label_33, 0, 2, 1, 3);

        label_35 = new QLabel(orderDataGroupBox_2);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setMaximumSize(QSize(16777215, 16777215));
        label_35->setFont(font1);

        gridLayout_9->addWidget(label_35, 0, 6, 1, 1);

        soIdLineEdit = new QLineEdit(orderDataGroupBox_2);
        soIdLineEdit->setObjectName(QString::fromUtf8("soIdLineEdit"));
        soIdLineEdit->setMinimumSize(QSize(180, 24));
        soIdLineEdit->setMaximumSize(QSize(16777215, 16777215));
        soIdLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        soIdLineEdit->setReadOnly(true);

        gridLayout_9->addWidget(soIdLineEdit, 1, 0, 1, 2);

        label_38 = new QLabel(orderDataGroupBox_2);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setMaximumSize(QSize(16777215, 16777215));
        label_38->setFont(font1);

        gridLayout_9->addWidget(label_38, 0, 0, 1, 2);

        soInspPercLabel = new QLabel(orderDataGroupBox_2);
        soInspPercLabel->setObjectName(QString::fromUtf8("soInspPercLabel"));
        soInspPercLabel->setFont(font1);

        gridLayout_9->addWidget(soInspPercLabel, 2, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_2, 3, 0, 1, 6);

        soInspectorsComboBox = new QComboBox(orderDataGroupBox_2);
        soInspectorsComboBox->setObjectName(QString::fromUtf8("soInspectorsComboBox"));
        soInspectorsComboBox->setMinimumSize(QSize(180, 24));

        gridLayout_9->addWidget(soInspectorsComboBox, 2, 1, 1, 3);

        soAssignDateEdit = new QDateEdit(orderDataGroupBox_2);
        soAssignDateEdit->setObjectName(QString::fromUtf8("soAssignDateEdit"));
        soAssignDateEdit->setMinimumSize(QSize(150, 24));
        soAssignDateEdit->setCalendarPopup(true);

        gridLayout_9->addWidget(soAssignDateEdit, 1, 5, 1, 1);

        recordFoilListWidget = new QListWidget(orderDataGroupBox_2);
        recordFoilListWidget->setObjectName(QString::fromUtf8("recordFoilListWidget"));
        recordFoilListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        recordFoilListWidget->setSortingEnabled(false);

        gridLayout_9->addWidget(recordFoilListWidget, 1, 6, 3, 1);

        soInspPercLabel_2 = new QLabel(orderDataGroupBox_2);
        soInspPercLabel_2->setObjectName(QString::fromUtf8("soInspPercLabel_2"));
        soInspPercLabel_2->setFont(font1);

        gridLayout_9->addWidget(soInspPercLabel_2, 0, 5, 1, 1);

        soInspPercSpinBox = new QDoubleSpinBox(orderDataGroupBox_2);
        soInspPercSpinBox->setObjectName(QString::fromUtf8("soInspPercSpinBox"));
        soInspPercSpinBox->setMinimumSize(QSize(0, 24));
        soInspPercSpinBox->setDecimals(0);
        soInspPercSpinBox->setValue(20.000000000000000);

        gridLayout_9->addWidget(soInspPercSpinBox, 2, 5, 1, 1);

        label_34 = new QLabel(orderDataGroupBox_2);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setMaximumSize(QSize(60, 16777215));
        label_34->setFont(font1);

        gridLayout_9->addWidget(label_34, 2, 0, 1, 1);


        gridLayout_21->addLayout(gridLayout_9, 0, 0, 1, 1);


        gridLayout_8->addWidget(orderDataGroupBox_2, 0, 0, 1, 1);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_13->addWidget(scrollArea_3, 1, 0, 1, 1);

        salesTabWidget->addTab(serviceOrdersTab, QString());

        gridLayout_20->addWidget(salesTabWidget, 1, 0, 1, 1);

        QWidget::setTabOrder(findButton, listButton);
        QWidget::setTabOrder(listButton, newButton);
        QWidget::setTabOrder(newButton, updateButton);
        QWidget::setTabOrder(updateButton, deleteButton);
        QWidget::setTabOrder(deleteButton, salesTabWidget);
        QWidget::setTabOrder(salesTabWidget, quotDateEdit);
        QWidget::setTabOrder(quotDateEdit, scrollArea);
        QWidget::setTabOrder(scrollArea, quotNameLineEdit);
        QWidget::setTabOrder(quotNameLineEdit, quotAddressLineEdit);
        QWidget::setTabOrder(quotAddressLineEdit, quotStateComboBox);
        QWidget::setTabOrder(quotStateComboBox, quotCityComboBox);
        QWidget::setTabOrder(quotCityComboBox, quotMailLineEdit);
        QWidget::setTabOrder(quotMailLineEdit, quotContactLineEdit);
        QWidget::setTabOrder(quotContactLineEdit, quotFaxLineEdit);
        QWidget::setTabOrder(quotFaxLineEdit, quotPhoneLineEdit);
        QWidget::setTabOrder(quotPhoneLineEdit, useTypeComboBox);
        QWidget::setTabOrder(useTypeComboBox, inspecTypeComboBox);
        QWidget::setTabOrder(inspecTypeComboBox, processesListWidget);
        QWidget::setTabOrder(processesListWidget, quotScopeTextEdit);
        QWidget::setTabOrder(quotScopeTextEdit, thrdNameLineEdit);
        QWidget::setTabOrder(thrdNameLineEdit, thrdNitLineEdit);
        QWidget::setTabOrder(thrdNitLineEdit, thrdAddressLineEdit);
        QWidget::setTabOrder(thrdAddressLineEdit, thrdStateComboBox);
        QWidget::setTabOrder(thrdStateComboBox, thrdRepLineEdit);
        QWidget::setTabOrder(thrdRepLineEdit, thrdRepIdLineEdit);
        QWidget::setTabOrder(thrdRepIdLineEdit, thrdMailLineEdit);
        QWidget::setTabOrder(thrdMailLineEdit, thrdPhoneLineEdit);
        QWidget::setTabOrder(thrdPhoneLineEdit, thrdFaxLineEdit);
        QWidget::setTabOrder(thrdFaxLineEdit, quotGenButton);
        QWidget::setTabOrder(quotGenButton, scrollArea_2);
        QWidget::setTabOrder(scrollArea_2, propThrdNameLineEdit);
        QWidget::setTabOrder(propThrdNameLineEdit, propIdLineEdit);
        QWidget::setTabOrder(propIdLineEdit, propLocalizationLineEdit);
        QWidget::setTabOrder(propLocalizationLineEdit, propInstNameLineEdit);
        QWidget::setTabOrder(propInstNameLineEdit, propScopeTextEdit);
        QWidget::setTabOrder(propScopeTextEdit, propDocsListWidget);
        QWidget::setTabOrder(propDocsListWidget, propValueTableView);
        QWidget::setTabOrder(propValueTableView, propPayWayComboBox);
        QWidget::setTabOrder(propPayWayComboBox, propSoldByComboBox);
        QWidget::setTabOrder(propSoldByComboBox, propApprovButton);
        QWidget::setTabOrder(propApprovButton, propRejectButton);
        QWidget::setTabOrder(propRejectButton, propObservTextEdit);
        QWidget::setTabOrder(propObservTextEdit, propGenButton);
        QWidget::setTabOrder(propGenButton, propPreviewButton);
        QWidget::setTabOrder(propPreviewButton, propOutWebView);
        QWidget::setTabOrder(propOutWebView, propPrintButton);
        QWidget::setTabOrder(propPrintButton, scrollArea_3);
        QWidget::setTabOrder(scrollArea_3, soScopeTextEdit);
        QWidget::setTabOrder(soScopeTextEdit, soObservTextEdit);
        QWidget::setTabOrder(soObservTextEdit, soAdmObservTextEdit);
        QWidget::setTabOrder(soAdmObservTextEdit, soGenButton);
        QWidget::setTabOrder(soGenButton, soPreviewButton);
        QWidget::setTabOrder(soPreviewButton, soOutWebView);
        QWidget::setTabOrder(soOutWebView, soPrintButton);
        QWidget::setTabOrder(soPrintButton, soDateEdit);
        QWidget::setTabOrder(soDateEdit, propDateEdit);
        QWidget::setTabOrder(propDateEdit, prevButton);
        QWidget::setTabOrder(prevButton, thrdCityComboBox);
        QWidget::setTabOrder(thrdCityComboBox, nextButton);

        retranslateUi(salesForm);

        salesTabWidget->setCurrentIndex(0);
        propDocsListWidget->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(salesForm);
    } // setupUi

    void retranslateUi(QDialog *salesForm)
    {
        salesForm->setWindowTitle(QApplication::translate("salesForm", "Ventas", nullptr));
        menuGroupBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        findButton->setToolTip(QApplication::translate("salesForm", "Ir", nullptr));
#endif // QT_NO_TOOLTIP
        findButton->setText(QString());
        label_45->setText(QApplication::translate("salesForm", "Localizar", nullptr));
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QApplication::translate("salesForm", "Nuevo", nullptr));
#endif // QT_NO_TOOLTIP
        newButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        listButton->setToolTip(QApplication::translate("salesForm", "Listar todas", nullptr));
#endif // QT_NO_TOOLTIP
        listButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        nextButton->setToolTip(QApplication::translate("salesForm", "Siguiente", nullptr));
#endif // QT_NO_TOOLTIP
        nextButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        prevButton->setToolTip(QApplication::translate("salesForm", "Anterior", nullptr));
#endif // QT_NO_TOOLTIP
        prevButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        deleteButton->setToolTip(QApplication::translate("salesForm", "Borrar", nullptr));
#endif // QT_NO_TOOLTIP
        deleteButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        updateButton->setToolTip(QApplication::translate("salesForm", "Actualizar", nullptr));
#endif // QT_NO_TOOLTIP
        updateButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        quotLCD->setToolTip(QApplication::translate("salesForm", "Cotizaci\303\263n N\302\272", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        findComboBox->setToolTip(QApplication::translate("salesForm", "Selecciones Criterio de Localizaci\303\263n", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        findLineEdit->setToolTip(QApplication::translate("salesForm", "Introduzca Dato a Localizar", nullptr));
#endif // QT_NO_TOOLTIP
        thirdPartyGroupBox->setTitle(QApplication::translate("salesForm", "Persona o Empresa Responsable del Pago de la Factura y del Contrato de Prestaci\303\263n de Servicios", nullptr));
        label_15->setText(QApplication::translate("salesForm", "Raz\303\263n Social", nullptr));
        label_18->setText(QApplication::translate("salesForm", "CC o NIT", nullptr));
        thrdNameLineEdit->setText(QString());
        thrdNitLineEdit->setText(QString());
        label_16->setText(QApplication::translate("salesForm", "Direcci\303\263n", nullptr));
        label_19->setText(QApplication::translate("salesForm", "Departamento", nullptr));
        label_21->setText(QApplication::translate("salesForm", "Ciudad", nullptr));
        thrdAddressLineEdit->setText(QString());
        label_20->setText(QApplication::translate("salesForm", "CC", nullptr));
        label_17->setText(QApplication::translate("salesForm", "Representante Legal", nullptr));
        thrdRepLineEdit->setText(QString());
        thrdRepIdLineEdit->setText(QString());
        label_22->setText(QApplication::translate("salesForm", "Correo Electr\303\263nico", nullptr));
        label_23->setText(QApplication::translate("salesForm", "Celular", nullptr));
        label_24->setText(QApplication::translate("salesForm", "Tel\303\251fono o Fax", nullptr));
        thrdMailLineEdit->setText(QString());
        thrdPhoneLineEdit->setText(QString());
        thrdFaxLineEdit->setText(QString());
        quotGenButton->setText(QApplication::translate("salesForm", "Generar Cotizaci\303\263n", nullptr));
        instalationGroupBox->setTitle(QApplication::translate("salesForm", "Datos de la instalaci\303\263n", nullptr));
        label_39->setText(QApplication::translate("salesForm", "Tipo de Inspecci\303\263n", nullptr));
        inspecTypeComboBox->setItemText(0, QApplication::translate("salesForm", "RETIE", nullptr));
        inspecTypeComboBox->setItemText(1, QApplication::translate("salesForm", "RETILAP", nullptr));
        inspecTypeComboBox->setItemText(2, QApplication::translate("salesForm", "NORMAS VOLUNTARIAS", nullptr));

        label_3->setText(QApplication::translate("salesForm", "Direcci\303\263n", nullptr));
        label->setText(QApplication::translate("salesForm", "Nombre de la Instalaci\303\263n", nullptr));
        quotAddressLineEdit->setText(QString());
        quotNameLineEdit->setText(QString());
        label_5->setText(QApplication::translate("salesForm", "Departamento", nullptr));
        label_4->setText(QApplication::translate("salesForm", "Persona de Contacto", nullptr));
        quotContactLineEdit->setText(QString());
        label_6->setText(QApplication::translate("salesForm", "Ciudad", nullptr));
        label_10->setText(QApplication::translate("salesForm", "Tel\303\251fono-Fax", nullptr));
        quotFaxLineEdit->setText(QString());
        label_8->setText(QApplication::translate("salesForm", "Celular", nullptr));
        quotPhoneLineEdit->setText(QString());
        label_7->setText(QApplication::translate("salesForm", "Correo Electr\303\263nico", nullptr));
        label_12->setText(QApplication::translate("salesForm", "Tipo de Uso", nullptr));
        quotMailLineEdit->setText(QString());
        label_11->setText(QApplication::translate("salesForm", "Tipo de Proceso", nullptr));
        label_29->setText(QApplication::translate("salesForm", "Alcance", nullptr));
        label_25->setText(QApplication::translate("salesForm", "Fecha de Cotizaci\303\263n", nullptr));
        quotDateEdit->setDisplayFormat(QApplication::translate("salesForm", "dd/MM/yyyy", nullptr));
        label_44->setText(QApplication::translate("salesForm", "Cotizaciones Encontradas", nullptr));
#ifndef QT_NO_TOOLTIP
        foundLCD->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        salesTabWidget->setTabText(salesTabWidget->indexOf(quotationsTab), QApplication::translate("salesForm", "Cotizaci\303\263n", nullptr));
        label_2->setText(QApplication::translate("salesForm", "Fecha de Propuesta", nullptr));
        propDateEdit->setDisplayFormat(QApplication::translate("salesForm", "dd/MM/yyyy", nullptr));
        propDataGroupBox->setTitle(QApplication::translate("salesForm", "Configuraci\303\263n de la Propuesta Comercial", nullptr));
        label_42->setText(QApplication::translate("salesForm", "Porcentaje Vendedor", nullptr));
        label_36->setText(QApplication::translate("salesForm", "Valor", nullptr));
        label_14->setText(QApplication::translate("salesForm", "Vendida Por", nullptr));
        label_37->setText(QApplication::translate("salesForm", "Forma de pago", nullptr));
#ifndef QT_NO_TOOLTIP
        propApprovButton->setToolTip(QApplication::translate("salesForm", "Agregar Selecci\303\263n de inspector", nullptr));
#endif // QT_NO_TOOLTIP
        propApprovButton->setText(QApplication::translate("salesForm", "Aprobar", nullptr));
#ifndef QT_NO_TOOLTIP
        propRejectButton->setToolTip(QApplication::translate("salesForm", "Agregar Selecci\303\263n de inspector", nullptr));
#endif // QT_NO_TOOLTIP
        propRejectButton->setText(QApplication::translate("salesForm", "Rechazar", nullptr));
        propUserPercSpinBox->setSuffix(QApplication::translate("salesForm", "%", nullptr));
        label_13->setText(QApplication::translate("salesForm", "Estado", nullptr));
        propStateLineEdit->setText(QApplication::translate("salesForm", "Aprobada", nullptr));
        label_47->setText(QApplication::translate("salesForm", "Detalle del estado", nullptr));
        propStateDetailLineEdit->setText(QString());
        label_26->setText(QApplication::translate("salesForm", "Raz\303\263n Social", nullptr));
        label_32->setText(QApplication::translate("salesForm", "Propuesta Comercialo N\302\272", nullptr));
        label_27->setText(QApplication::translate("salesForm", "Localizaci\303\263n", nullptr));
        label_31->setText(QApplication::translate("salesForm", "Nombre del Proyecto", nullptr));
        label_28->setText(QApplication::translate("salesForm", "Alcance", nullptr));
        propScopeTextEdit->setHtml(QApplication::translate("salesForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans'; font-size:9pt;\"><br /></span></p></body></html>", nullptr));
        label_30->setText(QApplication::translate("salesForm", "Requerimientos Generales", nullptr));
        label_9->setText(QApplication::translate("salesForm", "Observaciones", nullptr));
        propOutGroupBox->setTitle(QString());
        propPrintButton->setText(QApplication::translate("salesForm", "Imprimir Propuesta Comercial", nullptr));
        propGenButton->setText(QApplication::translate("salesForm", "Generar Propuesta Comercial", nullptr));
        propPreviewButton->setText(QApplication::translate("salesForm", "Previsualizar Propuesta", nullptr));
        salesTabWidget->setTabText(salesTabWidget->indexOf(proposalsTab), QApplication::translate("salesForm", "Propuesta Comercial", nullptr));
        label_40->setText(QApplication::translate("salesForm", "Fecha de la OS", nullptr));
        soDateEdit->setDisplayFormat(QApplication::translate("salesForm", "dd/MM/yyyy", nullptr));
        osOutGroupBox_2->setTitle(QString());
        soPrintButton->setText(QApplication::translate("salesForm", "Imprimir Orden de Servicio", nullptr));
        soGenButton->setText(QApplication::translate("salesForm", "Generar OS", nullptr));
        soPreviewButton->setText(QApplication::translate("salesForm", "Previsualizar Orden de Servicio", nullptr));
        orderDataGroupBox_2->setTitle(QApplication::translate("salesForm", "Configuraci\303\263n de la OS", nullptr));
        label_43->setText(QApplication::translate("salesForm", "Alcance", nullptr));
        label_41->setText(QApplication::translate("salesForm", "Observaciones", nullptr));
        label_46->setText(QApplication::translate("salesForm", "Observaciones de Gerencia", nullptr));
        label_33->setText(QApplication::translate("salesForm", "Estado", nullptr));
        label_35->setText(QApplication::translate("salesForm", "Archivo N\302\272", nullptr));
        label_38->setText(QApplication::translate("salesForm", "OS N\302\272", nullptr));
        soInspPercLabel->setText(QApplication::translate("salesForm", "Porcentaje Inspector", nullptr));
        soAssignDateEdit->setDisplayFormat(QApplication::translate("salesForm", "dd/MM/yyyy", nullptr));
        soInspPercLabel_2->setText(QApplication::translate("salesForm", "Fecha de Inspecci\303\263n", nullptr));
        soInspPercSpinBox->setSuffix(QApplication::translate("salesForm", "%", nullptr));
        label_34->setText(QApplication::translate("salesForm", "Inspector", nullptr));
        salesTabWidget->setTabText(salesTabWidget->indexOf(serviceOrdersTab), QApplication::translate("salesForm", "Orden de Servicio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class salesForm: public Ui_salesForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALES_H
