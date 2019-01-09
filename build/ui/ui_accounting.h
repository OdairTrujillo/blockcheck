/********************************************************************************
** Form generated from reading UI file 'accounting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTING_H
#define UI_ACCOUNTING_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFormLayout>
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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qwebengineview.h>

QT_BEGIN_NAMESPACE

class Ui_accountingForm
{
public:
    QFormLayout *formLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QWebEngineView *soOutWebView;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *printSoButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_3;
    QDateTimeEdit *thrdDateTimeEdit;
    QDateTimeEdit *inspectorDateTimeEdit;
    QDateTimeEdit *userDateTimeEdit;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *thrdPayValueSpinBox;
    QSpinBox *inspectorPayValueSpinBox;
    QSpinBox *userPayValueSpinBox;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *thrdTicketLineEdit;
    QLineEdit *inspectorTicketLineEdit;
    QLineEdit *userTicketLineEdit;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *thrdObservLineEdit;
    QLineEdit *inspectorObservLineEdit;
    QLineEdit *userObservLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *payThrdButton;
    QPushButton *payInspectorButton;
    QPushButton *payUserButton;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_41;
    QLineEdit *approvMethodLineEdit;
    QVBoxLayout *verticalLayout;
    QLabel *label_40;
    QLineEdit *billNumberLineEdit;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_36;
    QSpinBox *thrdBalanceSpinBox;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_37;
    QSpinBox *inspectorBalanceSpinBox;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_39;
    QSpinBox *userBalanceSpinBox;
    QLabel *label_13;
    QTableView *propValueTableView;
    QGridLayout *gridLayout_4;
    QSpinBox *userValueSpinBox;
    QDateEdit *soDateEdit;
    QLabel *label_8;
    QLineEdit *inspectorNameLineEdit;
    QLineEdit *userNameLineEdit;
    QLineEdit *soIdLineEdit;
    QLabel *label_9;
    QLineEdit *propIdLineEdit;
    QLineEdit *folderStateLineEdit;
    QLabel *label_38;
    QLineEdit *soStateLineEdit;
    QLabel *label_33;
    QLabel *label_4;
    QSpinBox *inspectorValueSpinBox;
    QLabel *label_5;
    QLabel *label_35;
    QLabel *label_6;
    QLabel *label_7;
    QListWidget *recordFoilListWidget;
    QGroupBox *menuGroupBox;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *findLineEdit;
    QPushButton *findButton;
    QPushButton *listButton;
    QPushButton *accountingListButton;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label;
    QLCDNumber *noProcessedLcdNumber;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *billedButton;

    void setupUi(QWidget *accountingForm)
    {
        if (accountingForm->objectName().isEmpty())
            accountingForm->setObjectName(QString::fromUtf8("accountingForm"));
        accountingForm->resize(819, 796);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/billed.png"), QSize(), QIcon::Normal, QIcon::Off);
        accountingForm->setWindowIcon(icon);
        formLayout = new QFormLayout(accountingForm);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        frame = new QFrame(accountingForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 150));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        soOutWebView = new QWebEngineView(frame);
        soOutWebView->setObjectName(QString::fromUtf8("soOutWebView"));
        soOutWebView->setProperty("url", QVariant(QUrl(QString::fromUtf8("about:blank"))));

        gridLayout_2->addWidget(soOutWebView, 0, 0, 1, 1);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_9);

        printSoButton = new QPushButton(frame);
        printSoButton->setObjectName(QString::fromUtf8("printSoButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        printSoButton->setIcon(icon1);

        horizontalLayout_17->addWidget(printSoButton);


        gridLayout_2->addLayout(horizontalLayout_17, 1, 0, 1, 1);


        formLayout->setWidget(3, QFormLayout::SpanningRole, frame);

        groupBox = new QGroupBox(accountingForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(2, 2, 2, 2);
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(16777215, 24));
        QFont font;
        font.setPointSize(10);
        label_11->setFont(font);
        label_11->setFrameShape(QFrame::Box);
        label_11->setFrameShadow(QFrame::Raised);
        label_11->setTextFormat(Qt::RichText);
        label_11->setScaledContents(false);
        label_11->setMargin(2);
        label_11->setIndent(-1);

        verticalLayout_9->addWidget(label_11);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        thrdDateTimeEdit = new QDateTimeEdit(groupBox);
        thrdDateTimeEdit->setObjectName(QString::fromUtf8("thrdDateTimeEdit"));
        thrdDateTimeEdit->setMinimumSize(QSize(0, 24));
        thrdDateTimeEdit->setFont(font);
        thrdDateTimeEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        thrdDateTimeEdit->setCalendarPopup(true);

        horizontalLayout_3->addWidget(thrdDateTimeEdit);

        inspectorDateTimeEdit = new QDateTimeEdit(groupBox);
        inspectorDateTimeEdit->setObjectName(QString::fromUtf8("inspectorDateTimeEdit"));
        inspectorDateTimeEdit->setMinimumSize(QSize(0, 24));
        inspectorDateTimeEdit->setFont(font);
        inspectorDateTimeEdit->setDate(QDate(2012, 1, 1));
        inspectorDateTimeEdit->setCalendarPopup(true);

        horizontalLayout_3->addWidget(inspectorDateTimeEdit);

        userDateTimeEdit = new QDateTimeEdit(groupBox);
        userDateTimeEdit->setObjectName(QString::fromUtf8("userDateTimeEdit"));
        userDateTimeEdit->setMinimumSize(QSize(0, 24));
        userDateTimeEdit->setFont(font);
        userDateTimeEdit->setDate(QDate(2012, 1, 1));
        userDateTimeEdit->setCalendarPopup(true);

        horizontalLayout_3->addWidget(userDateTimeEdit);


        verticalLayout_9->addLayout(horizontalLayout_3);


        verticalLayout_13->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMaximumSize(QSize(16777215, 24));
        label_10->setFont(font);
        label_10->setFrameShape(QFrame::Box);
        label_10->setFrameShadow(QFrame::Raised);
        label_10->setMargin(2);
        label_10->setIndent(-1);

        verticalLayout_10->addWidget(label_10);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        thrdPayValueSpinBox = new QSpinBox(groupBox);
        thrdPayValueSpinBox->setObjectName(QString::fromUtf8("thrdPayValueSpinBox"));
        thrdPayValueSpinBox->setMinimumSize(QSize(0, 24));
        thrdPayValueSpinBox->setFont(font);
        thrdPayValueSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        thrdPayValueSpinBox->setMaximum(999999999);
        thrdPayValueSpinBox->setSingleStep(5000);

        horizontalLayout_4->addWidget(thrdPayValueSpinBox);

        inspectorPayValueSpinBox = new QSpinBox(groupBox);
        inspectorPayValueSpinBox->setObjectName(QString::fromUtf8("inspectorPayValueSpinBox"));
        inspectorPayValueSpinBox->setMinimumSize(QSize(0, 24));
        inspectorPayValueSpinBox->setFont(font);
        inspectorPayValueSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        inspectorPayValueSpinBox->setMaximum(999999999);
        inspectorPayValueSpinBox->setSingleStep(1000);

        horizontalLayout_4->addWidget(inspectorPayValueSpinBox);

        userPayValueSpinBox = new QSpinBox(groupBox);
        userPayValueSpinBox->setObjectName(QString::fromUtf8("userPayValueSpinBox"));
        userPayValueSpinBox->setMinimumSize(QSize(0, 24));
        userPayValueSpinBox->setFont(font);
        userPayValueSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        userPayValueSpinBox->setMaximum(999999999);
        userPayValueSpinBox->setSingleStep(1000);

        horizontalLayout_4->addWidget(userPayValueSpinBox);


        verticalLayout_10->addLayout(horizontalLayout_4);


        verticalLayout_13->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);
        label_12->setFrameShape(QFrame::Box);
        label_12->setFrameShadow(QFrame::Raised);
        label_12->setMargin(2);

        verticalLayout_11->addWidget(label_12);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        thrdTicketLineEdit = new QLineEdit(groupBox);
        thrdTicketLineEdit->setObjectName(QString::fromUtf8("thrdTicketLineEdit"));
        thrdTicketLineEdit->setMinimumSize(QSize(0, 24));
        thrdTicketLineEdit->setFont(font);

        horizontalLayout_5->addWidget(thrdTicketLineEdit);

        inspectorTicketLineEdit = new QLineEdit(groupBox);
        inspectorTicketLineEdit->setObjectName(QString::fromUtf8("inspectorTicketLineEdit"));
        inspectorTicketLineEdit->setMinimumSize(QSize(0, 24));
        inspectorTicketLineEdit->setFont(font);

        horizontalLayout_5->addWidget(inspectorTicketLineEdit);

        userTicketLineEdit = new QLineEdit(groupBox);
        userTicketLineEdit->setObjectName(QString::fromUtf8("userTicketLineEdit"));
        userTicketLineEdit->setMinimumSize(QSize(0, 24));
        userTicketLineEdit->setFont(font);

        horizontalLayout_5->addWidget(userTicketLineEdit);


        verticalLayout_11->addLayout(horizontalLayout_5);


        verticalLayout_13->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        QFont font1;
        font1.setPointSize(10);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        label_20->setFont(font1);
        label_20->setAutoFillBackground(false);
        label_20->setFrameShape(QFrame::Box);
        label_20->setFrameShadow(QFrame::Raised);
        label_20->setMargin(2);

        verticalLayout_12->addWidget(label_20);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        thrdObservLineEdit = new QLineEdit(groupBox);
        thrdObservLineEdit->setObjectName(QString::fromUtf8("thrdObservLineEdit"));
        thrdObservLineEdit->setMinimumSize(QSize(0, 24));
        QFont font2;
        font2.setPointSize(9);
        thrdObservLineEdit->setFont(font2);

        horizontalLayout_6->addWidget(thrdObservLineEdit);

        inspectorObservLineEdit = new QLineEdit(groupBox);
        inspectorObservLineEdit->setObjectName(QString::fromUtf8("inspectorObservLineEdit"));
        inspectorObservLineEdit->setMinimumSize(QSize(0, 24));
        inspectorObservLineEdit->setFont(font2);

        horizontalLayout_6->addWidget(inspectorObservLineEdit);

        userObservLineEdit = new QLineEdit(groupBox);
        userObservLineEdit->setObjectName(QString::fromUtf8("userObservLineEdit"));
        userObservLineEdit->setMinimumSize(QSize(0, 24));
        userObservLineEdit->setFont(font2);

        horizontalLayout_6->addWidget(userObservLineEdit);


        verticalLayout_12->addLayout(horizontalLayout_6);


        verticalLayout_13->addLayout(verticalLayout_12);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        payThrdButton = new QPushButton(groupBox);
        payThrdButton->setObjectName(QString::fromUtf8("payThrdButton"));
        payThrdButton->setEnabled(false);
        payThrdButton->setMinimumSize(QSize(0, 30));
        payThrdButton->setFont(font);

        horizontalLayout_7->addWidget(payThrdButton);

        payInspectorButton = new QPushButton(groupBox);
        payInspectorButton->setObjectName(QString::fromUtf8("payInspectorButton"));
        payInspectorButton->setEnabled(false);
        payInspectorButton->setMinimumSize(QSize(0, 30));
        payInspectorButton->setFont(font);

        horizontalLayout_7->addWidget(payInspectorButton);

        payUserButton = new QPushButton(groupBox);
        payUserButton->setObjectName(QString::fromUtf8("payUserButton"));
        payUserButton->setEnabled(false);
        payUserButton->setMinimumSize(QSize(0, 30));
        payUserButton->setFont(font);

        horizontalLayout_7->addWidget(payUserButton);


        verticalLayout_13->addLayout(horizontalLayout_7);


        gridLayout_5->addLayout(verticalLayout_13, 0, 0, 3, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_41 = new QLabel(groupBox);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setMaximumSize(QSize(16777215, 16777215));
        label_41->setFont(font);
        label_41->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_41->setMargin(0);
        label_41->setIndent(4);

        verticalLayout_2->addWidget(label_41);

        approvMethodLineEdit = new QLineEdit(groupBox);
        approvMethodLineEdit->setObjectName(QString::fromUtf8("approvMethodLineEdit"));
        approvMethodLineEdit->setMinimumSize(QSize(0, 24));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(true);
        font3.setWeight(9);
        approvMethodLineEdit->setFont(font3);
        approvMethodLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        approvMethodLineEdit->setReadOnly(true);

        verticalLayout_2->addWidget(approvMethodLineEdit);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_40 = new QLabel(groupBox);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setMaximumSize(QSize(16777215, 16777215));
        label_40->setFont(font);
        label_40->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_40->setMargin(0);
        label_40->setIndent(4);

        verticalLayout->addWidget(label_40);

        billNumberLineEdit = new QLineEdit(groupBox);
        billNumberLineEdit->setObjectName(QString::fromUtf8("billNumberLineEdit"));
        billNumberLineEdit->setMinimumSize(QSize(0, 24));
        billNumberLineEdit->setFont(font3);
        billNumberLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        billNumberLineEdit->setReadOnly(true);

        verticalLayout->addWidget(billNumberLineEdit);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_36 = new QLabel(groupBox);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setMaximumSize(QSize(16777215, 16777215));
        label_36->setFont(font);
        label_36->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_36->setMargin(0);
        label_36->setIndent(4);

        verticalLayout_6->addWidget(label_36);

        thrdBalanceSpinBox = new QSpinBox(groupBox);
        thrdBalanceSpinBox->setObjectName(QString::fromUtf8("thrdBalanceSpinBox"));
        thrdBalanceSpinBox->setMinimumSize(QSize(115, 24));
        thrdBalanceSpinBox->setFont(font3);
        thrdBalanceSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        thrdBalanceSpinBox->setReadOnly(true);
        thrdBalanceSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        thrdBalanceSpinBox->setMaximum(999999999);
        thrdBalanceSpinBox->setSingleStep(1000);

        verticalLayout_6->addWidget(thrdBalanceSpinBox);


        gridLayout->addLayout(verticalLayout_6, 1, 0, 1, 2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_37 = new QLabel(groupBox);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setMaximumSize(QSize(16777215, 16777215));
        label_37->setFont(font);
        label_37->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_37->setMargin(0);
        label_37->setIndent(4);

        verticalLayout_7->addWidget(label_37);

        inspectorBalanceSpinBox = new QSpinBox(groupBox);
        inspectorBalanceSpinBox->setObjectName(QString::fromUtf8("inspectorBalanceSpinBox"));
        inspectorBalanceSpinBox->setMinimumSize(QSize(115, 24));
        inspectorBalanceSpinBox->setFont(font3);
        inspectorBalanceSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        inspectorBalanceSpinBox->setReadOnly(true);
        inspectorBalanceSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        inspectorBalanceSpinBox->setMaximum(999999999);
        inspectorBalanceSpinBox->setSingleStep(1000);

        verticalLayout_7->addWidget(inspectorBalanceSpinBox);


        gridLayout->addLayout(verticalLayout_7, 1, 2, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_39 = new QLabel(groupBox);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setMaximumSize(QSize(16777215, 16777215));
        label_39->setFont(font);
        label_39->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_39->setMargin(0);
        label_39->setIndent(4);

        verticalLayout_8->addWidget(label_39);

        userBalanceSpinBox = new QSpinBox(groupBox);
        userBalanceSpinBox->setObjectName(QString::fromUtf8("userBalanceSpinBox"));
        userBalanceSpinBox->setMinimumSize(QSize(115, 24));
        userBalanceSpinBox->setFont(font3);
        userBalanceSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        userBalanceSpinBox->setReadOnly(true);
        userBalanceSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        userBalanceSpinBox->setMaximum(999999999);
        userBalanceSpinBox->setSingleStep(1000);

        verticalLayout_8->addWidget(userBalanceSpinBox);


        gridLayout->addLayout(verticalLayout_8, 1, 3, 1, 2);


        gridLayout_5->addLayout(gridLayout, 0, 1, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);
        label_13->setFrameShape(QFrame::NoFrame);
        label_13->setFrameShadow(QFrame::Plain);
        label_13->setMargin(2);

        gridLayout_5->addWidget(label_13, 1, 1, 1, 1);

        propValueTableView = new QTableView(groupBox);
        propValueTableView->setObjectName(QString::fromUtf8("propValueTableView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(propValueTableView->sizePolicy().hasHeightForWidth());
        propValueTableView->setSizePolicy(sizePolicy1);
        propValueTableView->setMinimumSize(QSize(0, 0));
        QFont font4;
        font4.setPointSize(12);
        propValueTableView->setFont(font4);
        propValueTableView->setAlternatingRowColors(true);

        gridLayout_5->addWidget(propValueTableView, 2, 1, 1, 1);


        formLayout->setWidget(2, QFormLayout::SpanningRole, groupBox);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, -1, -1, 0);
        userValueSpinBox = new QSpinBox(accountingForm);
        userValueSpinBox->setObjectName(QString::fromUtf8("userValueSpinBox"));
        userValueSpinBox->setMinimumSize(QSize(140, 24));
        userValueSpinBox->setFont(font3);
        userValueSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        userValueSpinBox->setReadOnly(true);
        userValueSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        userValueSpinBox->setMaximum(999999999);
        userValueSpinBox->setSingleStep(1000);

        gridLayout_4->addWidget(userValueSpinBox, 3, 3, 1, 1);

        soDateEdit = new QDateEdit(accountingForm);
        soDateEdit->setObjectName(QString::fromUtf8("soDateEdit"));
        soDateEdit->setMinimumSize(QSize(150, 0));
        soDateEdit->setFont(font3);
        soDateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        soDateEdit->setWrapping(false);
        soDateEdit->setReadOnly(true);
        soDateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        soDateEdit->setAccelerated(false);
        soDateEdit->setCurrentSection(QDateTimeEdit::DaySection);
        soDateEdit->setDate(QDate(2000, 1, 2));

        gridLayout_4->addWidget(soDateEdit, 1, 1, 1, 1);

        label_8 = new QLabel(accountingForm);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setIndent(4);

        gridLayout_4->addWidget(label_8, 0, 2, 1, 1);

        inspectorNameLineEdit = new QLineEdit(accountingForm);
        inspectorNameLineEdit->setObjectName(QString::fromUtf8("inspectorNameLineEdit"));
        inspectorNameLineEdit->setMinimumSize(QSize(160, 24));
        inspectorNameLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));

        gridLayout_4->addWidget(inspectorNameLineEdit, 1, 2, 1, 1);

        userNameLineEdit = new QLineEdit(accountingForm);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));
        userNameLineEdit->setMinimumSize(QSize(160, 24));
        userNameLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));

        gridLayout_4->addWidget(userNameLineEdit, 1, 3, 1, 1);

        soIdLineEdit = new QLineEdit(accountingForm);
        soIdLineEdit->setObjectName(QString::fromUtf8("soIdLineEdit"));
        soIdLineEdit->setMinimumSize(QSize(100, 24));
        soIdLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        soIdLineEdit->setReadOnly(true);

        gridLayout_4->addWidget(soIdLineEdit, 1, 0, 1, 1);

        label_9 = new QLabel(accountingForm);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setIndent(4);

        gridLayout_4->addWidget(label_9, 2, 2, 1, 1);

        propIdLineEdit = new QLineEdit(accountingForm);
        propIdLineEdit->setObjectName(QString::fromUtf8("propIdLineEdit"));
        propIdLineEdit->setMinimumSize(QSize(0, 24));
        propIdLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));

        gridLayout_4->addWidget(propIdLineEdit, 3, 0, 1, 1);

        folderStateLineEdit = new QLineEdit(accountingForm);
        folderStateLineEdit->setObjectName(QString::fromUtf8("folderStateLineEdit"));
        folderStateLineEdit->setMinimumSize(QSize(0, 24));
        folderStateLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));

        gridLayout_4->addWidget(folderStateLineEdit, 1, 4, 1, 1);

        label_38 = new QLabel(accountingForm);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setMaximumSize(QSize(16777215, 16777215));
        label_38->setFont(font);
        label_38->setIndent(4);

        gridLayout_4->addWidget(label_38, 0, 0, 1, 1);

        soStateLineEdit = new QLineEdit(accountingForm);
        soStateLineEdit->setObjectName(QString::fromUtf8("soStateLineEdit"));
        soStateLineEdit->setMinimumSize(QSize(0, 24));
        soStateLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        soStateLineEdit->setReadOnly(true);

        gridLayout_4->addWidget(soStateLineEdit, 3, 1, 1, 1);

        label_33 = new QLabel(accountingForm);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font);
        label_33->setIndent(4);

        gridLayout_4->addWidget(label_33, 2, 1, 1, 1);

        label_4 = new QLabel(accountingForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setIndent(4);

        gridLayout_4->addWidget(label_4, 0, 1, 1, 1);

        inspectorValueSpinBox = new QSpinBox(accountingForm);
        inspectorValueSpinBox->setObjectName(QString::fromUtf8("inspectorValueSpinBox"));
        inspectorValueSpinBox->setMinimumSize(QSize(0, 24));
        inspectorValueSpinBox->setFont(font3);
        inspectorValueSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        inspectorValueSpinBox->setReadOnly(true);
        inspectorValueSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        inspectorValueSpinBox->setMaximum(999999999);
        inspectorValueSpinBox->setSingleStep(1000);

        gridLayout_4->addWidget(inspectorValueSpinBox, 3, 2, 1, 1);

        label_5 = new QLabel(accountingForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setIndent(4);

        gridLayout_4->addWidget(label_5, 2, 0, 1, 1);

        label_35 = new QLabel(accountingForm);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setMaximumSize(QSize(16777215, 16777215));
        label_35->setFont(font);
        label_35->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_35->setMargin(0);
        label_35->setIndent(4);

        gridLayout_4->addWidget(label_35, 0, 4, 1, 1);

        label_6 = new QLabel(accountingForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setIndent(4);

        gridLayout_4->addWidget(label_6, 0, 3, 1, 1);

        label_7 = new QLabel(accountingForm);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setIndent(4);

        gridLayout_4->addWidget(label_7, 2, 3, 1, 1);

        recordFoilListWidget = new QListWidget(accountingForm);
        recordFoilListWidget->setObjectName(QString::fromUtf8("recordFoilListWidget"));
        recordFoilListWidget->setMinimumSize(QSize(0, 0));
        recordFoilListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        recordFoilListWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_4->addWidget(recordFoilListWidget, 2, 4, 3, 1);


        formLayout->setLayout(1, QFormLayout::SpanningRole, gridLayout_4);

        menuGroupBox = new QGroupBox(accountingForm);
        menuGroupBox->setObjectName(QString::fromUtf8("menuGroupBox"));
        menuGroupBox->setMinimumSize(QSize(0, 50));
        menuGroupBox->setMaximumSize(QSize(16777215, 40));
        menuGroupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        menuGroupBox->setFlat(false);
        menuGroupBox->setCheckable(false);
        gridLayout_3 = new QGridLayout(menuGroupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(menuGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        findLineEdit = new QLineEdit(menuGroupBox);
        findLineEdit->setObjectName(QString::fromUtf8("findLineEdit"));
        findLineEdit->setMinimumSize(QSize(130, 25));
        findLineEdit->setMaximumSize(QSize(100, 16777215));
        findLineEdit->setFont(font);

        horizontalLayout->addWidget(findLineEdit);

        findButton = new QPushButton(menuGroupBox);
        findButton->setObjectName(QString::fromUtf8("findButton"));
        findButton->setMinimumSize(QSize(30, 30));
        findButton->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/go.png"), QSize(), QIcon::Normal, QIcon::Off);
        findButton->setIcon(icon2);

        horizontalLayout->addWidget(findButton);

        listButton = new QPushButton(menuGroupBox);
        listButton->setObjectName(QString::fromUtf8("listButton"));
        listButton->setMinimumSize(QSize(30, 30));
        listButton->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/list.png"), QSize(), QIcon::Normal, QIcon::Off);
        listButton->setIcon(icon3);

        horizontalLayout->addWidget(listButton);

        accountingListButton = new QPushButton(menuGroupBox);
        accountingListButton->setObjectName(QString::fromUtf8("accountingListButton"));
        accountingListButton->setMinimumSize(QSize(30, 30));
        accountingListButton->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/list2.png"), QSize(), QIcon::Normal, QIcon::Off);
        accountingListButton->setIcon(icon4);

        horizontalLayout->addWidget(accountingListButton);

        horizontalSpacer_10 = new QSpacerItem(180, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        label = new QLabel(menuGroupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        noProcessedLcdNumber = new QLCDNumber(menuGroupBox);
        noProcessedLcdNumber->setObjectName(QString::fromUtf8("noProcessedLcdNumber"));
        noProcessedLcdNumber->setMinimumSize(QSize(40, 25));
        noProcessedLcdNumber->setFont(font2);
        noProcessedLcdNumber->setDigitCount(2);

        horizontalLayout->addWidget(noProcessedLcdNumber);

        horizontalSpacer_11 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        billedButton = new QPushButton(menuGroupBox);
        billedButton->setObjectName(QString::fromUtf8("billedButton"));
        billedButton->setEnabled(false);
        billedButton->setMinimumSize(QSize(30, 30));
        billedButton->setMaximumSize(QSize(30, 30));
        billedButton->setIcon(icon);

        horizontalLayout->addWidget(billedButton);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);


        formLayout->setWidget(0, QFormLayout::SpanningRole, menuGroupBox);

        QWidget::setTabOrder(findLineEdit, findButton);
        QWidget::setTabOrder(findButton, thrdDateTimeEdit);
        QWidget::setTabOrder(thrdDateTimeEdit, thrdPayValueSpinBox);
        QWidget::setTabOrder(thrdPayValueSpinBox, thrdTicketLineEdit);
        QWidget::setTabOrder(thrdTicketLineEdit, thrdObservLineEdit);
        QWidget::setTabOrder(thrdObservLineEdit, payThrdButton);
        QWidget::setTabOrder(payThrdButton, inspectorDateTimeEdit);
        QWidget::setTabOrder(inspectorDateTimeEdit, inspectorPayValueSpinBox);
        QWidget::setTabOrder(inspectorPayValueSpinBox, inspectorTicketLineEdit);
        QWidget::setTabOrder(inspectorTicketLineEdit, inspectorObservLineEdit);
        QWidget::setTabOrder(inspectorObservLineEdit, payInspectorButton);
        QWidget::setTabOrder(payInspectorButton, userDateTimeEdit);
        QWidget::setTabOrder(userDateTimeEdit, userPayValueSpinBox);
        QWidget::setTabOrder(userPayValueSpinBox, userTicketLineEdit);
        QWidget::setTabOrder(userTicketLineEdit, userObservLineEdit);
        QWidget::setTabOrder(userObservLineEdit, payUserButton);
        QWidget::setTabOrder(payUserButton, billedButton);
        QWidget::setTabOrder(billedButton, listButton);
        QWidget::setTabOrder(listButton, accountingListButton);
        QWidget::setTabOrder(accountingListButton, soOutWebView);
        QWidget::setTabOrder(soOutWebView, printSoButton);
        QWidget::setTabOrder(printSoButton, propValueTableView);
        QWidget::setTabOrder(propValueTableView, thrdBalanceSpinBox);
        QWidget::setTabOrder(thrdBalanceSpinBox, inspectorBalanceSpinBox);
        QWidget::setTabOrder(inspectorBalanceSpinBox, userBalanceSpinBox);

        retranslateUi(accountingForm);

        QMetaObject::connectSlotsByName(accountingForm);
    } // setupUi

    void retranslateUi(QWidget *accountingForm)
    {
        accountingForm->setWindowTitle(QApplication::translate("accountingForm", "Contabilidad", nullptr));
        printSoButton->setText(QApplication::translate("accountingForm", "Imprimir Orden de Servicio", nullptr));
        groupBox->setTitle(QString());
        label_11->setText(QApplication::translate("accountingForm", "<html><head/><body><p align=\"center\">Fecha de Pago</p></body></html>", nullptr));
        thrdDateTimeEdit->setDisplayFormat(QApplication::translate("accountingForm", "dd/MM/yyyy", nullptr));
        inspectorDateTimeEdit->setDisplayFormat(QApplication::translate("accountingForm", "dd/MM/yyyy", nullptr));
        userDateTimeEdit->setDisplayFormat(QApplication::translate("accountingForm", "dd/MM/yyyy", nullptr));
        label_10->setText(QApplication::translate("accountingForm", "<html><head/><body><p align=\"center\">Valor a pagar</p></body></html>", nullptr));
        thrdPayValueSpinBox->setPrefix(QApplication::translate("accountingForm", "$", nullptr));
        inspectorPayValueSpinBox->setPrefix(QApplication::translate("accountingForm", "$", nullptr));
        userPayValueSpinBox->setPrefix(QApplication::translate("accountingForm", "$", nullptr));
        label_12->setText(QApplication::translate("accountingForm", "<html><head/><body><p align=\"center\">Comprobante</p></body></html>", nullptr));
        label_20->setText(QApplication::translate("accountingForm", "<html><head/><body><p align=\"center\">Observaciones</p></body></html>", nullptr));
        payThrdButton->setText(QApplication::translate("accountingForm", "Pagar Factura", nullptr));
        payInspectorButton->setText(QApplication::translate("accountingForm", "Pagar Inspector", nullptr));
        payUserButton->setText(QApplication::translate("accountingForm", "Pagar Comercial", nullptr));
        label_41->setText(QApplication::translate("accountingForm", "M\303\251todo de Aprobaci\303\263n", nullptr));
        label_40->setText(QApplication::translate("accountingForm", "N\302\272 Factura", nullptr));
        label_36->setText(QApplication::translate("accountingForm", "Saldo Factura", nullptr));
        thrdBalanceSpinBox->setPrefix(QApplication::translate("accountingForm", "$", nullptr));
        label_37->setText(QApplication::translate("accountingForm", "Saldo Inspector", nullptr));
        inspectorBalanceSpinBox->setPrefix(QApplication::translate("accountingForm", "$", nullptr));
        label_39->setText(QApplication::translate("accountingForm", "Saldo Comercial", nullptr));
        userBalanceSpinBox->setPrefix(QApplication::translate("accountingForm", "$", nullptr));
        label_13->setText(QApplication::translate("accountingForm", "Valor de la Propuesta", nullptr));
        userValueSpinBox->setPrefix(QApplication::translate("accountingForm", "$", nullptr));
        soDateEdit->setDisplayFormat(QApplication::translate("accountingForm", "dd 'de' MMM 'de' yyyy", nullptr));
        label_8->setText(QApplication::translate("accountingForm", "Inspector", nullptr));
        label_9->setText(QApplication::translate("accountingForm", "Valor Inspector", nullptr));
        label_38->setText(QApplication::translate("accountingForm", "OS N\302\272", nullptr));
        label_33->setText(QApplication::translate("accountingForm", "Estado Contable", nullptr));
        label_4->setText(QApplication::translate("accountingForm", "Fecha", nullptr));
        inspectorValueSpinBox->setPrefix(QApplication::translate("accountingForm", "$", nullptr));
        label_5->setText(QApplication::translate("accountingForm", "Propuesta N\302\272", nullptr));
        label_35->setText(QApplication::translate("accountingForm", "Estado de Documentos", nullptr));
        label_6->setText(QApplication::translate("accountingForm", "Comercial", nullptr));
        label_7->setText(QApplication::translate("accountingForm", "Valor Comercial", nullptr));
        menuGroupBox->setTitle(QString());
        label_2->setText(QApplication::translate("accountingForm", "Localizar OS", nullptr));
#ifndef QT_NO_TOOLTIP
        findButton->setToolTip(QApplication::translate("accountingForm", "Ir", nullptr));
#endif // QT_NO_TOOLTIP
        findButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        listButton->setToolTip(QApplication::translate("accountingForm", "Listar todas", nullptr));
#endif // QT_NO_TOOLTIP
        listButton->setText(QString());
        accountingListButton->setText(QString());
        label->setText(QApplication::translate("accountingForm", "OS's Sin Procesar", nullptr));
#ifndef QT_NO_TOOLTIP
        billedButton->setToolTip(QApplication::translate("accountingForm", "Facturar", nullptr));
#endif // QT_NO_TOOLTIP
        billedButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class accountingForm: public Ui_accountingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTING_H
