/********************************************************************************
** Form generated from reading UI file 'engineering.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENGINEERING_H
#define UI_ENGINEERING_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
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
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_engineeringForm
{
public:
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_21;
    QDateEdit *inspectionDateEdit;
    QLabel *label_40;
    QLineEdit *inspectionStateLineEdit;
    QSpacerItem *horizontalSpacer_12;
    QGroupBox *menuGroupBox;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *findLineEdit;
    QPushButton *findButton;
    QPushButton *listButton;
    QPushButton *checkFolderButton;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label;
    QLCDNumber *noProcessedLcdNumber;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *inspectionUpdateButton;
    QPushButton *inspectionSaveButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_2;
    QLabel *label_10;
    QLabel *label_13;
    QListWidget *processesListWidget;
    QPushButton *processInspectionButton;
    QTableView *propValueTableView;
    QLabel *label_29;
    QTextEdit *inspectionObservTextEdit;
    QLabel *label_41;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *newDictumButton;
    QPushButton *inspectionEndButton;
    QLabel *label_7;
    QPushButton *goDictumButton;
    QComboBox *processesComboBox;
    QLabel *label_20;
    QComboBox *dictumsComboBox;
    QTextEdit *inspectionScopeTextEdit;
    QGroupBox *inspectionGroupBox;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QDateEdit *soDateEdit;
    QLabel *label_22;
    QDateEdit *soAssignDateEdit;
    QLabel *label_39;
    QLineEdit *soAccStateLineEdit;
    QLabel *label_38;
    QLineEdit *soDocStateLineEdit;
    QLabel *label_6;
    QLineEdit *userNameLineEdit;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QLineEdit *inspectorNameLineEdit;
    QLabel *label_15;
    QLineEdit *propietaryNameLineEdit;
    QLabel *label_11;
    QLineEdit *inspectionAddressLineEdit;
    QLabel *label_12;
    QComboBox *inspectionStateComboBox;
    QLabel *label_19;
    QComboBox *inspectionCityComboBox;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_17;
    QListWidget *designersListWidget;
    QLabel *label_18;
    QComboBox *constructorNameComboBox;
    QLabel *label_16;
    QComboBox *auditorNameComboBox;

    void setupUi(QDialog *engineeringForm)
    {
        if (engineeringForm->objectName().isEmpty())
            engineeringForm->setObjectName(QString::fromUtf8("engineeringForm"));
        engineeringForm->resize(858, 874);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/engineering.png"), QSize(), QIcon::Normal, QIcon::Off);
        engineeringForm->setWindowIcon(icon);
        gridLayout_4 = new QGridLayout(engineeringForm);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_21 = new QLabel(engineeringForm);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        QFont font;
        font.setPointSize(10);
        label_21->setFont(font);
        label_21->setMargin(0);
        label_21->setIndent(4);

        horizontalLayout_2->addWidget(label_21);

        inspectionDateEdit = new QDateEdit(engineeringForm);
        inspectionDateEdit->setObjectName(QString::fromUtf8("inspectionDateEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inspectionDateEdit->sizePolicy().hasHeightForWidth());
        inspectionDateEdit->setSizePolicy(sizePolicy);
        inspectionDateEdit->setMinimumSize(QSize(200, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        inspectionDateEdit->setFont(font1);
        inspectionDateEdit->setAutoFillBackground(true);
        inspectionDateEdit->setCalendarPopup(true);

        horizontalLayout_2->addWidget(inspectionDateEdit);

        label_40 = new QLabel(engineeringForm);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setMaximumSize(QSize(16777215, 16777215));
        label_40->setFont(font);
        label_40->setIndent(4);

        horizontalLayout_2->addWidget(label_40);

        inspectionStateLineEdit = new QLineEdit(engineeringForm);
        inspectionStateLineEdit->setObjectName(QString::fromUtf8("inspectionStateLineEdit"));
        inspectionStateLineEdit->setMinimumSize(QSize(150, 24));
        inspectionStateLineEdit->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(11);
        font2.setItalic(false);
        inspectionStateLineEdit->setFont(font2);
        inspectionStateLineEdit->setContextMenuPolicy(Qt::ActionsContextMenu);
        inspectionStateLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(inspectionStateLineEdit);

        horizontalSpacer_12 = new QSpacerItem(267, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        menuGroupBox = new QGroupBox(engineeringForm);
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/go.png"), QSize(), QIcon::Normal, QIcon::Off);
        findButton->setIcon(icon1);

        horizontalLayout->addWidget(findButton);

        listButton = new QPushButton(menuGroupBox);
        listButton->setObjectName(QString::fromUtf8("listButton"));
        listButton->setMinimumSize(QSize(30, 30));
        listButton->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/list.png"), QSize(), QIcon::Normal, QIcon::Off);
        listButton->setIcon(icon2);

        horizontalLayout->addWidget(listButton);

        checkFolderButton = new QPushButton(menuGroupBox);
        checkFolderButton->setObjectName(QString::fromUtf8("checkFolderButton"));
        checkFolderButton->setEnabled(true);
        checkFolderButton->setMinimumSize(QSize(30, 30));
        checkFolderButton->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/store.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkFolderButton->setIcon(icon3);

        horizontalLayout->addWidget(checkFolderButton);

        horizontalSpacer_10 = new QSpacerItem(180, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        label = new QLabel(menuGroupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        noProcessedLcdNumber = new QLCDNumber(menuGroupBox);
        noProcessedLcdNumber->setObjectName(QString::fromUtf8("noProcessedLcdNumber"));
        noProcessedLcdNumber->setMinimumSize(QSize(40, 0));
        QFont font3;
        font3.setPointSize(9);
        noProcessedLcdNumber->setFont(font3);
        noProcessedLcdNumber->setDigitCount(2);

        horizontalLayout->addWidget(noProcessedLcdNumber);

        horizontalSpacer_11 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        inspectionUpdateButton = new QPushButton(menuGroupBox);
        inspectionUpdateButton->setObjectName(QString::fromUtf8("inspectionUpdateButton"));
        inspectionUpdateButton->setEnabled(true);
        inspectionUpdateButton->setMinimumSize(QSize(30, 30));
        inspectionUpdateButton->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        inspectionUpdateButton->setIcon(icon4);

        horizontalLayout->addWidget(inspectionUpdateButton);

        inspectionSaveButton = new QPushButton(menuGroupBox);
        inspectionSaveButton->setObjectName(QString::fromUtf8("inspectionSaveButton"));
        inspectionSaveButton->setEnabled(true);
        inspectionSaveButton->setMinimumSize(QSize(30, 30));
        inspectionSaveButton->setMaximumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        inspectionSaveButton->setIcon(icon5);

        horizontalLayout->addWidget(inspectionSaveButton);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(menuGroupBox, 0, 0, 1, 2);

        groupBox = new QGroupBox(engineeringForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
        label_10->setMargin(2);

        gridLayout_2->addWidget(label_10, 0, 1, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);
        label_13->setFrameShape(QFrame::NoFrame);
        label_13->setFrameShadow(QFrame::Plain);
        label_13->setMargin(2);

        gridLayout_2->addWidget(label_13, 0, 0, 1, 1);

        processesListWidget = new QListWidget(groupBox);
        processesListWidget->setObjectName(QString::fromUtf8("processesListWidget"));
        processesListWidget->setEnabled(false);
        processesListWidget->setMinimumSize(QSize(0, 125));
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
        QFont font4;
        font4.setPointSize(12);
        processesListWidget->setFont(font4);
        processesListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        processesListWidget->setAlternatingRowColors(false);
        processesListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

        gridLayout_2->addWidget(processesListWidget, 1, 1, 3, 1);

        processInspectionButton = new QPushButton(groupBox);
        processInspectionButton->setObjectName(QString::fromUtf8("processInspectionButton"));
        processInspectionButton->setEnabled(false);
        processInspectionButton->setMinimumSize(QSize(0, 26));
        processInspectionButton->setFont(font);
        processInspectionButton->setIcon(icon5);

        gridLayout_2->addWidget(processInspectionButton, 4, 1, 2, 1);

        propValueTableView = new QTableView(groupBox);
        propValueTableView->setObjectName(QString::fromUtf8("propValueTableView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(propValueTableView->sizePolicy().hasHeightForWidth());
        propValueTableView->setSizePolicy(sizePolicy1);
        propValueTableView->setMinimumSize(QSize(340, 150));
        propValueTableView->setMaximumSize(QSize(340, 16777215));
        propValueTableView->setFont(font4);
        propValueTableView->setAlternatingRowColors(true);

        gridLayout_2->addWidget(propValueTableView, 1, 0, 5, 1);


        gridLayout_5->addLayout(gridLayout_2, 4, 0, 2, 1);

        label_29 = new QLabel(groupBox);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font);
        label_29->setMargin(2);

        gridLayout_5->addWidget(label_29, 0, 0, 1, 1);

        inspectionObservTextEdit = new QTextEdit(groupBox);
        inspectionObservTextEdit->setObjectName(QString::fromUtf8("inspectionObservTextEdit"));
        inspectionObservTextEdit->setMinimumSize(QSize(0, 80));
        inspectionObservTextEdit->setMaximumSize(QSize(16777215, 150));
        inspectionObservTextEdit->setFont(font4);
        inspectionObservTextEdit->setTabChangesFocus(true);
        inspectionObservTextEdit->setAcceptRichText(false);

        gridLayout_5->addWidget(inspectionObservTextEdit, 3, 0, 1, 2);

        label_41 = new QLabel(groupBox);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setFont(font);

        gridLayout_5->addWidget(label_41, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(2);
        gridLayout->setContentsMargins(-1, 2, -1, -1);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 0, 1, 3);

        newDictumButton = new QPushButton(groupBox);
        newDictumButton->setObjectName(QString::fromUtf8("newDictumButton"));
        newDictumButton->setEnabled(true);
        newDictumButton->setMinimumSize(QSize(0, 26));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/icons/new_dict.png"), QSize(), QIcon::Normal, QIcon::Off);
        newDictumButton->setIcon(icon6);

        gridLayout->addWidget(newDictumButton, 6, 1, 2, 2);

        inspectionEndButton = new QPushButton(groupBox);
        inspectionEndButton->setObjectName(QString::fromUtf8("inspectionEndButton"));
        inspectionEndButton->setEnabled(false);
        inspectionEndButton->setMinimumSize(QSize(0, 26));
        inspectionEndButton->setFont(font);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/icons/approb.png"), QSize(), QIcon::Normal, QIcon::Off);
        inspectionEndButton->setIcon(icon7);

        gridLayout->addWidget(inspectionEndButton, 9, 0, 1, 3);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 18));
        label_7->setFont(font);
        label_7->setIndent(4);

        gridLayout->addWidget(label_7, 3, 0, 2, 3);

        goDictumButton = new QPushButton(groupBox);
        goDictumButton->setObjectName(QString::fromUtf8("goDictumButton"));
        goDictumButton->setEnabled(true);
        goDictumButton->setMinimumSize(QSize(0, 26));
        goDictumButton->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/icons/go-next.png"), QSize(), QIcon::Normal, QIcon::Off);
        goDictumButton->setIcon(icon8);

        gridLayout->addWidget(goDictumButton, 6, 0, 2, 1);

        processesComboBox = new QComboBox(groupBox);
        processesComboBox->setObjectName(QString::fromUtf8("processesComboBox"));
        processesComboBox->setEnabled(true);
        processesComboBox->setMinimumSize(QSize(170, 24));
        processesComboBox->setFont(font);

        gridLayout->addWidget(processesComboBox, 2, 0, 1, 3);

        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(0, 18));
        label_20->setFont(font);
        label_20->setIndent(4);

        gridLayout->addWidget(label_20, 0, 0, 2, 3);

        dictumsComboBox = new QComboBox(groupBox);
        dictumsComboBox->setObjectName(QString::fromUtf8("dictumsComboBox"));
        dictumsComboBox->setEnabled(true);
        dictumsComboBox->setMinimumSize(QSize(170, 24));
        dictumsComboBox->setFont(font);

        gridLayout->addWidget(dictumsComboBox, 5, 0, 1, 3);


        gridLayout_5->addLayout(gridLayout, 4, 1, 2, 1);

        inspectionScopeTextEdit = new QTextEdit(groupBox);
        inspectionScopeTextEdit->setObjectName(QString::fromUtf8("inspectionScopeTextEdit"));
        inspectionScopeTextEdit->setMinimumSize(QSize(0, 0));
        inspectionScopeTextEdit->setMaximumSize(QSize(16777215, 150));
        inspectionScopeTextEdit->setFont(font4);
        inspectionScopeTextEdit->setFrameShape(QFrame::StyledPanel);
        inspectionScopeTextEdit->setFrameShadow(QFrame::Sunken);
        inspectionScopeTextEdit->setLineWidth(1);
        inspectionScopeTextEdit->setMidLineWidth(0);
        inspectionScopeTextEdit->setTabChangesFocus(true);
        inspectionScopeTextEdit->setHtml(QString::fromUtf8("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'DejaVu Sans';\"><br /></span></p></body></html>"));
        inspectionScopeTextEdit->setAcceptRichText(false);

        gridLayout_5->addWidget(inspectionScopeTextEdit, 1, 0, 1, 2);


        gridLayout_4->addWidget(groupBox, 3, 0, 1, 2);

        inspectionGroupBox = new QGroupBox(engineeringForm);
        inspectionGroupBox->setObjectName(QString::fromUtf8("inspectionGroupBox"));
        inspectionGroupBox->setMinimumSize(QSize(0, 0));
        horizontalLayout_3 = new QHBoxLayout(inspectionGroupBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(4, -1, -1, -1);
        label_4 = new QLabel(inspectionGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setIndent(4);

        verticalLayout->addWidget(label_4);

        soDateEdit = new QDateEdit(inspectionGroupBox);
        soDateEdit->setObjectName(QString::fromUtf8("soDateEdit"));
        soDateEdit->setMinimumSize(QSize(0, 24));
        soDateEdit->setFont(font1);
        soDateEdit->setAutoFillBackground(true);
        soDateEdit->setWrapping(false);
        soDateEdit->setReadOnly(true);
        soDateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        soDateEdit->setAccelerated(false);
        soDateEdit->setCurrentSection(QDateTimeEdit::DaySection);
        soDateEdit->setDate(QDate(2000, 1, 2));

        verticalLayout->addWidget(soDateEdit);

        label_22 = new QLabel(inspectionGroupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font);
        label_22->setMargin(0);
        label_22->setIndent(4);

        verticalLayout->addWidget(label_22);

        soAssignDateEdit = new QDateEdit(inspectionGroupBox);
        soAssignDateEdit->setObjectName(QString::fromUtf8("soAssignDateEdit"));
        soAssignDateEdit->setMinimumSize(QSize(0, 24));
        soAssignDateEdit->setFont(font1);
        soAssignDateEdit->setAutoFillBackground(true);
        soAssignDateEdit->setCalendarPopup(true);

        verticalLayout->addWidget(soAssignDateEdit);

        label_39 = new QLabel(inspectionGroupBox);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setMaximumSize(QSize(16777215, 16777215));
        label_39->setFont(font);
        label_39->setIndent(4);

        verticalLayout->addWidget(label_39);

        soAccStateLineEdit = new QLineEdit(inspectionGroupBox);
        soAccStateLineEdit->setObjectName(QString::fromUtf8("soAccStateLineEdit"));
        soAccStateLineEdit->setMinimumSize(QSize(0, 24));
        soAccStateLineEdit->setMaximumSize(QSize(16777215, 16777215));
        soAccStateLineEdit->setFont(font2);
        soAccStateLineEdit->setReadOnly(true);

        verticalLayout->addWidget(soAccStateLineEdit);

        label_38 = new QLabel(inspectionGroupBox);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setMaximumSize(QSize(16777215, 16777215));
        label_38->setFont(font);
        label_38->setIndent(4);

        verticalLayout->addWidget(label_38);

        soDocStateLineEdit = new QLineEdit(inspectionGroupBox);
        soDocStateLineEdit->setObjectName(QString::fromUtf8("soDocStateLineEdit"));
        soDocStateLineEdit->setMinimumSize(QSize(0, 24));
        soDocStateLineEdit->setMaximumSize(QSize(16777215, 16777215));
        soDocStateLineEdit->setFont(font2);
        soDocStateLineEdit->setReadOnly(true);

        verticalLayout->addWidget(soDocStateLineEdit);

        label_6 = new QLabel(inspectionGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setIndent(4);

        verticalLayout->addWidget(label_6);

        userNameLineEdit = new QLineEdit(inspectionGroupBox);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));
        userNameLineEdit->setMinimumSize(QSize(0, 24));
        userNameLineEdit->setFont(font2);

        verticalLayout->addWidget(userNameLineEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_8 = new QLabel(inspectionGroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setIndent(4);

        verticalLayout_3->addWidget(label_8);

        inspectorNameLineEdit = new QLineEdit(inspectionGroupBox);
        inspectorNameLineEdit->setObjectName(QString::fromUtf8("inspectorNameLineEdit"));
        inspectorNameLineEdit->setMinimumSize(QSize(0, 24));
        inspectorNameLineEdit->setFont(font2);

        verticalLayout_3->addWidget(inspectorNameLineEdit);

        label_15 = new QLabel(inspectionGroupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);
        label_15->setMargin(0);
        label_15->setIndent(4);

        verticalLayout_3->addWidget(label_15);

        propietaryNameLineEdit = new QLineEdit(inspectionGroupBox);
        propietaryNameLineEdit->setObjectName(QString::fromUtf8("propietaryNameLineEdit"));
        propietaryNameLineEdit->setMinimumSize(QSize(0, 24));
        propietaryNameLineEdit->setFont(font1);
        propietaryNameLineEdit->setReadOnly(false);

        verticalLayout_3->addWidget(propietaryNameLineEdit);

        label_11 = new QLabel(inspectionGroupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);
        label_11->setMargin(0);
        label_11->setIndent(4);

        verticalLayout_3->addWidget(label_11);

        inspectionAddressLineEdit = new QLineEdit(inspectionGroupBox);
        inspectionAddressLineEdit->setObjectName(QString::fromUtf8("inspectionAddressLineEdit"));
        inspectionAddressLineEdit->setMinimumSize(QSize(0, 24));
        inspectionAddressLineEdit->setFont(font1);
        inspectionAddressLineEdit->setReadOnly(false);

        verticalLayout_3->addWidget(inspectionAddressLineEdit);

        label_12 = new QLabel(inspectionGroupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);
        label_12->setMargin(0);
        label_12->setIndent(4);

        verticalLayout_3->addWidget(label_12);

        inspectionStateComboBox = new QComboBox(inspectionGroupBox);
        inspectionStateComboBox->setObjectName(QString::fromUtf8("inspectionStateComboBox"));
        inspectionStateComboBox->setEnabled(true);
        inspectionStateComboBox->setMinimumSize(QSize(0, 24));
        inspectionStateComboBox->setFont(font);
        inspectionStateComboBox->setAutoFillBackground(true);

        verticalLayout_3->addWidget(inspectionStateComboBox);

        label_19 = new QLabel(inspectionGroupBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font);
        label_19->setMargin(0);
        label_19->setIndent(4);

        verticalLayout_3->addWidget(label_19);

        inspectionCityComboBox = new QComboBox(inspectionGroupBox);
        inspectionCityComboBox->setObjectName(QString::fromUtf8("inspectionCityComboBox"));
        inspectionCityComboBox->setMinimumSize(QSize(0, 24));
        inspectionCityComboBox->setFont(font);
        inspectionCityComboBox->setAutoFillBackground(true);

        verticalLayout_3->addWidget(inspectionCityComboBox);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 4, -1);
        label_17 = new QLabel(inspectionGroupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font);
        label_17->setMargin(0);
        label_17->setIndent(4);

        verticalLayout_2->addWidget(label_17);

        designersListWidget = new QListWidget(inspectionGroupBox);
        designersListWidget->setObjectName(QString::fromUtf8("designersListWidget"));
        designersListWidget->setEnabled(true);
        QFont font5;
        font5.setPointSize(11);
        designersListWidget->setFont(font5);
        designersListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout_2->addWidget(designersListWidget);

        label_18 = new QLabel(inspectionGroupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font);
        label_18->setMargin(0);
        label_18->setIndent(4);

        verticalLayout_2->addWidget(label_18);

        constructorNameComboBox = new QComboBox(inspectionGroupBox);
        constructorNameComboBox->setObjectName(QString::fromUtf8("constructorNameComboBox"));
        constructorNameComboBox->setMinimumSize(QSize(0, 24));
        constructorNameComboBox->setFont(font);
        constructorNameComboBox->setContextMenuPolicy(Qt::ActionsContextMenu);
        constructorNameComboBox->setAutoFillBackground(true);
        constructorNameComboBox->setEditable(true);

        verticalLayout_2->addWidget(constructorNameComboBox);

        label_16 = new QLabel(inspectionGroupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);
        label_16->setMargin(0);
        label_16->setIndent(4);

        verticalLayout_2->addWidget(label_16);

        auditorNameComboBox = new QComboBox(inspectionGroupBox);
        auditorNameComboBox->setObjectName(QString::fromUtf8("auditorNameComboBox"));
        auditorNameComboBox->setEnabled(true);
        auditorNameComboBox->setMinimumSize(QSize(0, 24));
        auditorNameComboBox->setFont(font);
        auditorNameComboBox->setContextMenuPolicy(Qt::ActionsContextMenu);
        auditorNameComboBox->setAutoFillBackground(true);
        auditorNameComboBox->setEditable(true);

        verticalLayout_2->addWidget(auditorNameComboBox);


        horizontalLayout_3->addLayout(verticalLayout_2);


        gridLayout_4->addWidget(inspectionGroupBox, 2, 0, 1, 2);

        QWidget::setTabOrder(findLineEdit, findButton);
        QWidget::setTabOrder(findButton, constructorNameComboBox);
        QWidget::setTabOrder(constructorNameComboBox, auditorNameComboBox);
        QWidget::setTabOrder(auditorNameComboBox, inspectionScopeTextEdit);
        QWidget::setTabOrder(inspectionScopeTextEdit, inspectionObservTextEdit);
        QWidget::setTabOrder(inspectionObservTextEdit, propValueTableView);
        QWidget::setTabOrder(propValueTableView, processesListWidget);
        QWidget::setTabOrder(processesListWidget, processesComboBox);
        QWidget::setTabOrder(processesComboBox, goDictumButton);
        QWidget::setTabOrder(goDictumButton, newDictumButton);
        QWidget::setTabOrder(newDictumButton, listButton);
        QWidget::setTabOrder(listButton, soDateEdit);

        retranslateUi(engineeringForm);

        QMetaObject::connectSlotsByName(engineeringForm);
    } // setupUi

    void retranslateUi(QDialog *engineeringForm)
    {
        engineeringForm->setWindowTitle(QApplication::translate("engineeringForm", "Ingenier\303\255a", nullptr));
        label_21->setText(QApplication::translate("engineeringForm", "Fecha de revisi\303\263n y procesamiento", nullptr));
        inspectionDateEdit->setDisplayFormat(QApplication::translate("engineeringForm", "dd 'de' MMM 'de' yyyy", nullptr));
        label_40->setText(QApplication::translate("engineeringForm", "Estado de Inspecci\303\263n", nullptr));
#ifndef QT_NO_TOOLTIP
        inspectionStateLineEdit->setToolTip(QApplication::translate("engineeringForm", "Clic derecho para cambiar estado", nullptr));
#endif // QT_NO_TOOLTIP
        inspectionStateLineEdit->setText(QString());
        menuGroupBox->setTitle(QString());
        label_2->setText(QApplication::translate("engineeringForm", "Localizar OS", nullptr));
#ifndef QT_NO_TOOLTIP
        findButton->setToolTip(QApplication::translate("engineeringForm", "Ir", nullptr));
#endif // QT_NO_TOOLTIP
        findButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        listButton->setToolTip(QApplication::translate("engineeringForm", "Listar todas", nullptr));
#endif // QT_NO_TOOLTIP
        listButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        checkFolderButton->setToolTip(QApplication::translate("engineeringForm", "Documentos", nullptr));
#endif // QT_NO_TOOLTIP
        checkFolderButton->setText(QString());
        label->setText(QApplication::translate("engineeringForm", "Expedientes por procesar", nullptr));
#ifndef QT_NO_TOOLTIP
        inspectionUpdateButton->setToolTip(QApplication::translate("engineeringForm", "Actualizar", nullptr));
#endif // QT_NO_TOOLTIP
        inspectionUpdateButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        inspectionSaveButton->setToolTip(QApplication::translate("engineeringForm", "Guardar", nullptr));
#endif // QT_NO_TOOLTIP
        inspectionSaveButton->setText(QString());
        groupBox->setTitle(QString());
        label_10->setText(QApplication::translate("engineeringForm", "Procesos", nullptr));
        label_13->setText(QApplication::translate("engineeringForm", "Valor de la Propuesta", nullptr));
        processInspectionButton->setText(QApplication::translate("engineeringForm", "Procesar Inspecci\303\263n", nullptr));
        label_29->setText(QApplication::translate("engineeringForm", "Alcance", nullptr));
        label_41->setText(QApplication::translate("engineeringForm", "Observaciones", nullptr));
        newDictumButton->setText(QApplication::translate("engineeringForm", "A\303\261adir", nullptr));
        inspectionEndButton->setText(QApplication::translate("engineeringForm", "Finalizar Inspecci\303\263n", nullptr));
        label_7->setText(QApplication::translate("engineeringForm", "Dictamen", nullptr));
        goDictumButton->setText(QApplication::translate("engineeringForm", "Ir", nullptr));
        label_20->setText(QApplication::translate("engineeringForm", "Seleccione el Proceso", nullptr));
        inspectionGroupBox->setTitle(QString());
        label_4->setText(QApplication::translate("engineeringForm", "Fecha de la OS", nullptr));
        soDateEdit->setDisplayFormat(QApplication::translate("engineeringForm", "dd 'de' MMM 'de' yyyy", nullptr));
        label_22->setText(QApplication::translate("engineeringForm", "Fecha Asignada de Inspecci\303\263n", nullptr));
        soAssignDateEdit->setDisplayFormat(QApplication::translate("engineeringForm", "dd 'de' MMM 'de' yyyy", nullptr));
        label_39->setText(QApplication::translate("engineeringForm", "Estado Contable", nullptr));
        soAccStateLineEdit->setText(QString());
        label_38->setText(QApplication::translate("engineeringForm", "Estado de Documentos", nullptr));
        soDocStateLineEdit->setText(QString());
        label_6->setText(QApplication::translate("engineeringForm", "Comercial", nullptr));
        label_8->setText(QApplication::translate("engineeringForm", "Inspector", nullptr));
        label_15->setText(QApplication::translate("engineeringForm", "Nombre del Propietario", nullptr));
        label_11->setText(QApplication::translate("engineeringForm", "Direcci\303\263n", nullptr));
        label_12->setText(QApplication::translate("engineeringForm", "Departamento", nullptr));
        label_19->setText(QApplication::translate("engineeringForm", "Ciudad", nullptr));
        label_17->setText(QApplication::translate("engineeringForm", "Dise\303\261ador", nullptr));
        label_18->setText(QApplication::translate("engineeringForm", "Constructor", nullptr));
        label_16->setText(QApplication::translate("engineeringForm", "Interventor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class engineeringForm: public Ui_engineeringForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINEERING_H
