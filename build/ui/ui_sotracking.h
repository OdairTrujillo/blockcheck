/********************************************************************************
** Form generated from reading UI file 'sotracking.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOTRACKING_H
#define UI_SOTRACKING_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_soTrackingForm
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *menuGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_10;
    QLineEdit *soNumberLineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_3;
    QDateEdit *receiptDateEdit;
    QComboBox *receiverNameComboBox;
    QDateEdit *shippingDateEdit;
    QComboBox *shipperNameComboBox;
    QLabel *label_9;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *observationsTextEdit;
    QComboBox *shippingStateComboBox;
    QComboBox *shippingCityComboBox;
    QLabel *label_11;
    QLabel *label_8;
    QLineEdit *shippingCompany;
    QLineEdit *guideNumberLineEdit;
    QLineEdit *shippingNameLineEdit;
    QLabel *label_7;

    void setupUi(QDialog *soTrackingForm)
    {
        if (soTrackingForm->objectName().isEmpty())
            soTrackingForm->setObjectName(QString::fromUtf8("soTrackingForm"));
        soTrackingForm->setWindowModality(Qt::WindowModal);
        soTrackingForm->resize(623, 314);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(soTrackingForm->sizePolicy().hasHeightForWidth());
        soTrackingForm->setSizePolicy(sizePolicy);
        soTrackingForm->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        soTrackingForm->setWindowIcon(icon);
        gridLayout_4 = new QGridLayout(soTrackingForm);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(2, 2, 2, 2);
        menuGroupBox = new QGroupBox(soTrackingForm);
        menuGroupBox->setObjectName(QString::fromUtf8("menuGroupBox"));
        menuGroupBox->setMinimumSize(QSize(0, 45));
        menuGroupBox->setMaximumSize(QSize(16777215, 50));
        menuGroupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        menuGroupBox->setFlat(false);
        menuGroupBox->setCheckable(false);
        gridLayout_2 = new QGridLayout(menuGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        label_10 = new QLabel(menuGroupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font;
        font.setPointSize(10);
        label_10->setFont(font);
        label_10->setIndent(1);

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        soNumberLineEdit = new QLineEdit(menuGroupBox);
        soNumberLineEdit->setObjectName(QString::fromUtf8("soNumberLineEdit"));
        soNumberLineEdit->setMinimumSize(QSize(0, 24));
        soNumberLineEdit->setMaximumSize(QSize(150, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(9);
        soNumberLineEdit->setFont(font1);
        soNumberLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);\n"
"font: 75 oblique 10pt \"DejaVu Sans\";"));
        soNumberLineEdit->setReadOnly(true);

        gridLayout_2->addWidget(soNumberLineEdit, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        saveButton = new QPushButton(menuGroupBox);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setEnabled(true);
        saveButton->setMinimumSize(QSize(30, 30));
        saveButton->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon1);

        gridLayout_2->addWidget(saveButton, 0, 3, 1, 1);


        gridLayout_4->addWidget(menuGroupBox, 0, 0, 1, 1);

        groupBox = new QGroupBox(soTrackingForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setMargin(2);
        label->setIndent(1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setMargin(2);
        label_2->setIndent(1);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setMargin(2);
        label_6->setIndent(1);

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setMargin(2);
        label_3->setIndent(1);

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        receiptDateEdit = new QDateEdit(groupBox);
        receiptDateEdit->setObjectName(QString::fromUtf8("receiptDateEdit"));
        receiptDateEdit->setMinimumSize(QSize(0, 24));
        receiptDateEdit->setFont(font);
        receiptDateEdit->setCalendarPopup(true);

        gridLayout->addWidget(receiptDateEdit, 1, 0, 1, 1);

        receiverNameComboBox = new QComboBox(groupBox);
        receiverNameComboBox->setObjectName(QString::fromUtf8("receiverNameComboBox"));
        receiverNameComboBox->setMinimumSize(QSize(160, 24));
        receiverNameComboBox->setFont(font);

        gridLayout->addWidget(receiverNameComboBox, 1, 1, 1, 1);

        shippingDateEdit = new QDateEdit(groupBox);
        shippingDateEdit->setObjectName(QString::fromUtf8("shippingDateEdit"));
        shippingDateEdit->setMinimumSize(QSize(0, 24));
        shippingDateEdit->setFont(font);
        shippingDateEdit->setCalendarPopup(true);

        gridLayout->addWidget(shippingDateEdit, 1, 2, 1, 1);

        shipperNameComboBox = new QComboBox(groupBox);
        shipperNameComboBox->setObjectName(QString::fromUtf8("shipperNameComboBox"));
        shipperNameComboBox->setMinimumSize(QSize(160, 24));
        shipperNameComboBox->setFont(font);

        gridLayout->addWidget(shipperNameComboBox, 1, 3, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setMargin(2);
        label_9->setIndent(1);

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setMargin(2);
        label_4->setIndent(1);

        gridLayout->addWidget(label_4, 2, 2, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setMargin(2);
        label_5->setIndent(1);

        gridLayout->addWidget(label_5, 2, 3, 1, 1);

        observationsTextEdit = new QTextEdit(groupBox);
        observationsTextEdit->setObjectName(QString::fromUtf8("observationsTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(observationsTextEdit->sizePolicy().hasHeightForWidth());
        observationsTextEdit->setSizePolicy(sizePolicy1);
        observationsTextEdit->setFont(font);
        observationsTextEdit->setTabChangesFocus(true);
        observationsTextEdit->setAcceptRichText(false);

        gridLayout->addWidget(observationsTextEdit, 3, 0, 5, 2);

        shippingStateComboBox = new QComboBox(groupBox);
        shippingStateComboBox->setObjectName(QString::fromUtf8("shippingStateComboBox"));
        shippingStateComboBox->setMinimumSize(QSize(0, 24));

        gridLayout->addWidget(shippingStateComboBox, 3, 2, 1, 1);

        shippingCityComboBox = new QComboBox(groupBox);
        shippingCityComboBox->setObjectName(QString::fromUtf8("shippingCityComboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(shippingCityComboBox->sizePolicy().hasHeightForWidth());
        shippingCityComboBox->setSizePolicy(sizePolicy2);
        shippingCityComboBox->setMinimumSize(QSize(0, 24));

        gridLayout->addWidget(shippingCityComboBox, 3, 3, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);
        label_11->setMargin(2);
        label_11->setIndent(1);

        gridLayout->addWidget(label_11, 6, 2, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setMargin(2);
        label_8->setIndent(1);

        gridLayout->addWidget(label_8, 6, 3, 1, 1);

        shippingCompany = new QLineEdit(groupBox);
        shippingCompany->setObjectName(QString::fromUtf8("shippingCompany"));
        sizePolicy2.setHeightForWidth(shippingCompany->sizePolicy().hasHeightForWidth());
        shippingCompany->setSizePolicy(sizePolicy2);
        shippingCompany->setMinimumSize(QSize(0, 24));
        shippingCompany->setFont(font);

        gridLayout->addWidget(shippingCompany, 7, 2, 1, 1);

        guideNumberLineEdit = new QLineEdit(groupBox);
        guideNumberLineEdit->setObjectName(QString::fromUtf8("guideNumberLineEdit"));
        sizePolicy2.setHeightForWidth(guideNumberLineEdit->sizePolicy().hasHeightForWidth());
        guideNumberLineEdit->setSizePolicy(sizePolicy2);
        guideNumberLineEdit->setMinimumSize(QSize(0, 24));
        guideNumberLineEdit->setFont(font);

        gridLayout->addWidget(guideNumberLineEdit, 7, 3, 1, 1);

        shippingNameLineEdit = new QLineEdit(groupBox);
        shippingNameLineEdit->setObjectName(QString::fromUtf8("shippingNameLineEdit"));
        sizePolicy2.setHeightForWidth(shippingNameLineEdit->sizePolicy().hasHeightForWidth());
        shippingNameLineEdit->setSizePolicy(sizePolicy2);
        shippingNameLineEdit->setMinimumSize(QSize(0, 24));
        shippingNameLineEdit->setFont(font);

        gridLayout->addWidget(shippingNameLineEdit, 5, 2, 1, 2);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setMargin(2);

        gridLayout->addWidget(label_7, 4, 2, 1, 2);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 1, 0, 1, 1);

        QWidget::setTabOrder(soNumberLineEdit, receiptDateEdit);
        QWidget::setTabOrder(receiptDateEdit, receiverNameComboBox);
        QWidget::setTabOrder(receiverNameComboBox, shippingDateEdit);
        QWidget::setTabOrder(shippingDateEdit, shipperNameComboBox);
        QWidget::setTabOrder(shipperNameComboBox, shippingStateComboBox);
        QWidget::setTabOrder(shippingStateComboBox, shippingCityComboBox);
        QWidget::setTabOrder(shippingCityComboBox, shippingNameLineEdit);
        QWidget::setTabOrder(shippingNameLineEdit, shippingCompany);
        QWidget::setTabOrder(shippingCompany, guideNumberLineEdit);
        QWidget::setTabOrder(guideNumberLineEdit, observationsTextEdit);
        QWidget::setTabOrder(observationsTextEdit, saveButton);

        retranslateUi(soTrackingForm);

        receiverNameComboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(soTrackingForm);
    } // setupUi

    void retranslateUi(QDialog *soTrackingForm)
    {
        soTrackingForm->setWindowTitle(QApplication::translate("soTrackingForm", "Recepci\303\263n y Env\303\255o", nullptr));
        menuGroupBox->setTitle(QString());
        label_10->setText(QApplication::translate("soTrackingForm", "OS N\303\272mero", nullptr));
#ifndef QT_NO_TOOLTIP
        soNumberLineEdit->setToolTip(QApplication::translate("soTrackingForm", "Introduzca Dato a Localizar", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("soTrackingForm", "Guardar", nullptr));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QString());
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("soTrackingForm", "Fecha de Recepci\303\263n", nullptr));
        label_2->setText(QApplication::translate("soTrackingForm", "Qui\303\251n Recibe", nullptr));
        label_6->setText(QApplication::translate("soTrackingForm", "Fecha de Env\303\255o", nullptr));
        label_3->setText(QApplication::translate("soTrackingForm", "Qui\303\251n Env\303\255a", nullptr));
        receiptDateEdit->setDisplayFormat(QApplication::translate("soTrackingForm", "dd/MM/yyyy", nullptr));
        shippingDateEdit->setDisplayFormat(QApplication::translate("soTrackingForm", "dd/MM/yyyy", nullptr));
        label_9->setText(QApplication::translate("soTrackingForm", "Observaciones", nullptr));
        label_4->setText(QApplication::translate("soTrackingForm", "Departamento", nullptr));
        label_5->setText(QApplication::translate("soTrackingForm", "Ciudad", nullptr));
        label_11->setText(QApplication::translate("soTrackingForm", "Empresa de Env\303\255os", nullptr));
        label_8->setText(QApplication::translate("soTrackingForm", "N\302\272 de Guia", nullptr));
        label_7->setText(QApplication::translate("soTrackingForm", "Entregado A:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class soTrackingForm: public Ui_soTrackingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOTRACKING_H
