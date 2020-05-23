/********************************************************************************
** Form generated from reading UI file 'checkfolder.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKFOLDER_H
#define UI_CHECKFOLDER_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_checkFolderForm
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QDateEdit *soDateEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *saveEngObservsButton;
    QLabel *label_8;
    QTextEdit *admObservsTextEdit;
    QTextEdit *engObservsTextEdit;
    QTextEdit *soScopeTextEdit;
    QLabel *label_6;
    QVBoxLayout *verticalLayout;
    QLabel *label_38;
    QLineEdit *soIdLineEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_35;
    QListWidget *recordFoilListWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_33;
    QLineEdit *soStateLineEdit;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLineEdit *folderStateLineEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_9;
    QDateEdit *soAssignDateEdit;
    QLabel *label_2;
    QGroupBox *menuGroupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_45;
    QLineEdit *findLineEdit;
    QPushButton *findButton;
    QPushButton *listButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLCDNumber *noCheckedLcdNumber;
    QLabel *label_5;
    QLCDNumber *incompleteLcdNumber;
    QLabel *label_7;
    QLCDNumber *observedLcdNumber;
    QPushButton *saveButton;
    QPushButton *storeButton;
    QPushButton *soTrackingButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *createFoilButton;

    void setupUi(QDialog *checkFolderForm)
    {
        if (checkFolderForm->objectName().isEmpty())
            checkFolderForm->setObjectName(QString::fromUtf8("checkFolderForm"));
        checkFolderForm->resize(849, 637);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/store.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkFolderForm->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(checkFolderForm);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(checkFolderForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(10);
        label_3->setFont(font);
        label_3->setIndent(4);

        verticalLayout_5->addWidget(label_3);

        soDateEdit = new QDateEdit(checkFolderForm);
        soDateEdit->setObjectName(QString::fromUtf8("soDateEdit"));
        soDateEdit->setMinimumSize(QSize(0, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(9);
        soDateEdit->setFont(font1);
        soDateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        soDateEdit->setWrapping(false);
        soDateEdit->setReadOnly(true);
        soDateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        soDateEdit->setAccelerated(false);
        soDateEdit->setCurrentSection(QDateTimeEdit::DaySection);
        soDateEdit->setDate(QDate(2000, 1, 2));

        verticalLayout_5->addWidget(soDateEdit);


        gridLayout_2->addLayout(verticalLayout_5, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 2, 1);

        saveEngObservsButton = new QPushButton(checkFolderForm);
        saveEngObservsButton->setObjectName(QString::fromUtf8("saveEngObservsButton"));
        saveEngObservsButton->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveEngObservsButton->setIcon(icon1);

        gridLayout_2->addWidget(saveEngObservsButton, 11, 0, 1, 2);

        label_8 = new QLabel(checkFolderForm);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font2;
        font2.setPointSize(9);
        label_8->setFont(font2);
        label_8->setMargin(0);
        label_8->setIndent(4);

        gridLayout_2->addWidget(label_8, 9, 0, 1, 1);

        admObservsTextEdit = new QTextEdit(checkFolderForm);
        admObservsTextEdit->setObjectName(QString::fromUtf8("admObservsTextEdit"));
        admObservsTextEdit->setMaximumSize(QSize(16777215, 50));
        QFont font3;
        font3.setPointSize(12);
        admObservsTextEdit->setFont(font3);
        admObservsTextEdit->setTabChangesFocus(true);
        admObservsTextEdit->setReadOnly(true);
        admObservsTextEdit->setAcceptRichText(false);

        gridLayout_2->addWidget(admObservsTextEdit, 10, 0, 1, 6);

        engObservsTextEdit = new QTextEdit(checkFolderForm);
        engObservsTextEdit->setObjectName(QString::fromUtf8("engObservsTextEdit"));
        engObservsTextEdit->setMaximumSize(QSize(16777215, 50));
        engObservsTextEdit->setFont(font3);
        engObservsTextEdit->setTabChangesFocus(true);
        engObservsTextEdit->setReadOnly(true);
        engObservsTextEdit->setAcceptRichText(false);

        gridLayout_2->addWidget(engObservsTextEdit, 8, 0, 1, 6);

        soScopeTextEdit = new QTextEdit(checkFolderForm);
        soScopeTextEdit->setObjectName(QString::fromUtf8("soScopeTextEdit"));
        soScopeTextEdit->setMaximumSize(QSize(16777215, 60));
        soScopeTextEdit->setFont(font3);
        soScopeTextEdit->setTabChangesFocus(true);
        soScopeTextEdit->setAcceptRichText(false);

        gridLayout_2->addWidget(soScopeTextEdit, 5, 0, 1, 6);

        label_6 = new QLabel(checkFolderForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);
        label_6->setMargin(0);
        label_6->setIndent(4);

        gridLayout_2->addWidget(label_6, 7, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_38 = new QLabel(checkFolderForm);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setMaximumSize(QSize(16777215, 16777215));
        label_38->setFont(font);
        label_38->setIndent(4);

        verticalLayout->addWidget(label_38);

        soIdLineEdit = new QLineEdit(checkFolderForm);
        soIdLineEdit->setObjectName(QString::fromUtf8("soIdLineEdit"));
        soIdLineEdit->setMinimumSize(QSize(0, 24));
        soIdLineEdit->setMaximumSize(QSize(16777215, 16777215));
        soIdLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        soIdLineEdit->setReadOnly(true);

        verticalLayout->addWidget(soIdLineEdit);


        gridLayout_2->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_35 = new QLabel(checkFolderForm);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setMaximumSize(QSize(16777215, 16777215));
        label_35->setFont(font);
        label_35->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_35->setMargin(0);
        label_35->setIndent(4);

        verticalLayout_2->addWidget(label_35);

        recordFoilListWidget = new QListWidget(checkFolderForm);
        recordFoilListWidget->setObjectName(QString::fromUtf8("recordFoilListWidget"));
        recordFoilListWidget->setMinimumSize(QSize(0, 0));
        recordFoilListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        recordFoilListWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        verticalLayout_2->addWidget(recordFoilListWidget);


        gridLayout_2->addLayout(verticalLayout_2, 1, 5, 4, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_33 = new QLabel(checkFolderForm);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font);
        label_33->setIndent(4);

        verticalLayout_3->addWidget(label_33);

        soStateLineEdit = new QLineEdit(checkFolderForm);
        soStateLineEdit->setObjectName(QString::fromUtf8("soStateLineEdit"));
        soStateLineEdit->setMinimumSize(QSize(0, 24));
        soStateLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        soStateLineEdit->setReadOnly(true);

        verticalLayout_3->addWidget(soStateLineEdit);


        gridLayout_2->addLayout(verticalLayout_3, 1, 2, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(checkFolderForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setIndent(4);

        verticalLayout_4->addWidget(label);

        folderStateLineEdit = new QLineEdit(checkFolderForm);
        folderStateLineEdit->setObjectName(QString::fromUtf8("folderStateLineEdit"));
        folderStateLineEdit->setMinimumSize(QSize(0, 24));
        folderStateLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));

        verticalLayout_4->addWidget(folderStateLineEdit);


        gridLayout_2->addLayout(verticalLayout_4, 1, 1, 1, 1);

        scrollArea = new QScrollArea(checkFolderForm);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 823, 154));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 6, 0, 1, 6);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_9 = new QLabel(checkFolderForm);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setIndent(4);

        verticalLayout_6->addWidget(label_9);

        soAssignDateEdit = new QDateEdit(checkFolderForm);
        soAssignDateEdit->setObjectName(QString::fromUtf8("soAssignDateEdit"));
        soAssignDateEdit->setMinimumSize(QSize(0, 24));
        soAssignDateEdit->setFont(font1);
        soAssignDateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        soAssignDateEdit->setWrapping(false);
        soAssignDateEdit->setReadOnly(true);
        soAssignDateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        soAssignDateEdit->setAccelerated(false);
        soAssignDateEdit->setCurrentSection(QDateTimeEdit::DaySection);
        soAssignDateEdit->setDate(QDate(2000, 1, 2));

        verticalLayout_6->addWidget(soAssignDateEdit);


        gridLayout_2->addLayout(verticalLayout_6, 1, 4, 1, 1);

        label_2 = new QLabel(checkFolderForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 4, 0, 1, 1);

        menuGroupBox = new QGroupBox(checkFolderForm);
        menuGroupBox->setObjectName(QString::fromUtf8("menuGroupBox"));
        menuGroupBox->setMinimumSize(QSize(0, 45));
        menuGroupBox->setMaximumSize(QSize(16777215, 50));
        menuGroupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        menuGroupBox->setFlat(false);
        menuGroupBox->setCheckable(false);
        gridLayout = new QGridLayout(menuGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_45 = new QLabel(menuGroupBox);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setFont(font);
        label_45->setMargin(3);
        label_45->setIndent(0);

        horizontalLayout->addWidget(label_45);

        findLineEdit = new QLineEdit(menuGroupBox);
        findLineEdit->setObjectName(QString::fromUtf8("findLineEdit"));
        findLineEdit->setMinimumSize(QSize(0, 24));
        findLineEdit->setMaximumSize(QSize(200, 16777215));
        QFont font4;
        font4.setPointSize(11);
        findLineEdit->setFont(font4);

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

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_4 = new QLabel(menuGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout->addWidget(label_4);

        noCheckedLcdNumber = new QLCDNumber(menuGroupBox);
        noCheckedLcdNumber->setObjectName(QString::fromUtf8("noCheckedLcdNumber"));
        noCheckedLcdNumber->setMinimumSize(QSize(40, 25));
        noCheckedLcdNumber->setDigitCount(2);

        horizontalLayout->addWidget(noCheckedLcdNumber);

        label_5 = new QLabel(menuGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setIndent(4);

        horizontalLayout->addWidget(label_5);

        incompleteLcdNumber = new QLCDNumber(menuGroupBox);
        incompleteLcdNumber->setObjectName(QString::fromUtf8("incompleteLcdNumber"));
        incompleteLcdNumber->setMinimumSize(QSize(40, 25));
        incompleteLcdNumber->setDigitCount(2);

        horizontalLayout->addWidget(incompleteLcdNumber);

        label_7 = new QLabel(menuGroupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setIndent(4);

        horizontalLayout->addWidget(label_7);

        observedLcdNumber = new QLCDNumber(menuGroupBox);
        observedLcdNumber->setObjectName(QString::fromUtf8("observedLcdNumber"));
        observedLcdNumber->setMinimumSize(QSize(40, 25));
        observedLcdNumber->setDigitCount(2);

        horizontalLayout->addWidget(observedLcdNumber);

        saveButton = new QPushButton(menuGroupBox);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setEnabled(false);
        saveButton->setMinimumSize(QSize(30, 30));
        saveButton->setMaximumSize(QSize(30, 30));
        saveButton->setIcon(icon1);

        horizontalLayout->addWidget(saveButton);

        storeButton = new QPushButton(menuGroupBox);
        storeButton->setObjectName(QString::fromUtf8("storeButton"));
        storeButton->setEnabled(false);
        storeButton->setMinimumSize(QSize(30, 30));
        storeButton->setMaximumSize(QSize(30, 30));
        storeButton->setIcon(icon);

        horizontalLayout->addWidget(storeButton);

        soTrackingButton = new QPushButton(menuGroupBox);
        soTrackingButton->setObjectName(QString::fromUtf8("soTrackingButton"));
        soTrackingButton->setEnabled(false);
        soTrackingButton->setMinimumSize(QSize(30, 30));
        soTrackingButton->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        soTrackingButton->setIcon(icon4);

        horizontalLayout->addWidget(soTrackingButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        createFoilButton = new QPushButton(menuGroupBox);
        createFoilButton->setObjectName(QString::fromUtf8("createFoilButton"));
        createFoilButton->setMinimumSize(QSize(30, 30));
        createFoilButton->setMaximumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        createFoilButton->setIcon(icon5);

        horizontalLayout->addWidget(createFoilButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(menuGroupBox, 0, 0, 1, 6);

        QWidget::setTabOrder(findLineEdit, findButton);
        QWidget::setTabOrder(findButton, soTrackingButton);
        QWidget::setTabOrder(soTrackingButton, soScopeTextEdit);
        QWidget::setTabOrder(soScopeTextEdit, saveButton);
        QWidget::setTabOrder(saveButton, storeButton);
        QWidget::setTabOrder(storeButton, createFoilButton);
        QWidget::setTabOrder(createFoilButton, soIdLineEdit);
        QWidget::setTabOrder(soIdLineEdit, folderStateLineEdit);
        QWidget::setTabOrder(folderStateLineEdit, soStateLineEdit);
        QWidget::setTabOrder(soStateLineEdit, soDateEdit);
        QWidget::setTabOrder(soDateEdit, listButton);
        QWidget::setTabOrder(listButton, scrollArea);

        retranslateUi(checkFolderForm);

        QMetaObject::connectSlotsByName(checkFolderForm);
    } // setupUi

    void retranslateUi(QDialog *checkFolderForm)
    {
        checkFolderForm->setWindowTitle(QApplication::translate("checkFolderForm", "Revisi\303\263n de Carpeta", nullptr));
        label_3->setText(QApplication::translate("checkFolderForm", "Fecha", nullptr));
        soDateEdit->setDisplayFormat(QApplication::translate("checkFolderForm", "dd 'de' MMM 'de' yyyy", nullptr));
#ifndef QT_NO_TOOLTIP
        saveEngObservsButton->setToolTip(QApplication::translate("checkFolderForm", "Guardar", nullptr));
#endif // QT_NO_TOOLTIP
        saveEngObservsButton->setText(QApplication::translate("checkFolderForm", "Guardar Observaci\303\263n", nullptr));
        label_8->setText(QApplication::translate("checkFolderForm", "Observaciones de Gerencia", nullptr));
        label_6->setText(QApplication::translate("checkFolderForm", "Observaciones de Ingenier\303\255a", nullptr));
        label_38->setText(QApplication::translate("checkFolderForm", "Orden de Servicio", nullptr));
        label_35->setText(QApplication::translate("checkFolderForm", "Archivo N\302\272", nullptr));
        label_33->setText(QApplication::translate("checkFolderForm", "Estado Contable", nullptr));
        label->setText(QApplication::translate("checkFolderForm", "Estado Expediente", nullptr));
        label_9->setText(QApplication::translate("checkFolderForm", "Fecha Inspecci\303\263n", nullptr));
        soAssignDateEdit->setDisplayFormat(QApplication::translate("checkFolderForm", "dd 'de' MMM 'de' yyyy", nullptr));
        label_2->setText(QApplication::translate("checkFolderForm", "Alcance", nullptr));
        menuGroupBox->setTitle(QString());
        label_45->setText(QApplication::translate("checkFolderForm", "Localizar OS", nullptr));
#ifndef QT_NO_TOOLTIP
        findLineEdit->setToolTip(QApplication::translate("checkFolderForm", "Introduzca Dato a Localizar", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        findButton->setToolTip(QApplication::translate("checkFolderForm", "Ir", nullptr));
#endif // QT_NO_TOOLTIP
        findButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        listButton->setToolTip(QApplication::translate("checkFolderForm", "Listar todas", nullptr));
#endif // QT_NO_TOOLTIP
        listButton->setText(QString());
        label_4->setText(QApplication::translate("checkFolderForm", "Sin Procesar", nullptr));
        label_5->setText(QApplication::translate("checkFolderForm", "Incompletas", nullptr));
        label_7->setText(QApplication::translate("checkFolderForm", "Observadas", nullptr));
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("checkFolderForm", "Guardar", nullptr));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        storeButton->setToolTip(QApplication::translate("checkFolderForm", "Archivar", nullptr));
#endif // QT_NO_TOOLTIP
        storeButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        soTrackingButton->setToolTip(QApplication::translate("checkFolderForm", "Recepci\303\263n y Env\303\255o", nullptr));
#endif // QT_NO_TOOLTIP
        soTrackingButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        createFoilButton->setToolTip(QApplication::translate("checkFolderForm", "Crear AZ", nullptr));
#endif // QT_NO_TOOLTIP
        createFoilButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class checkFolderForm: public Ui_checkFolderForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKFOLDER_H
