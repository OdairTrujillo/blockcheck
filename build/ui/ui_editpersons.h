/********************************************************************************
** Form generated from reading UI file 'editpersons.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPERSONS_H
#define UI_EDITPERSONS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_editPersonsForm
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *personsComboBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *updateButton;
    QPushButton *newButton;
    QPushButton *saveButton;
    QPushButton *removeButton;
    QLabel *label;
    QLabel *percentageLabel;
    QLineEdit *nitLineEdit;
    QDoubleSpinBox *percentageSpinBox;
    QLabel *label_4;
    QLabel *availibleLabel;
    QLineEdit *mailLineEdit;
    QComboBox *availibleComboBox;
    QLabel *label_5;
    QLabel *longNameLabel;
    QLineEdit *celLineEdit;
    QLineEdit *longNameLineEdit;
    QLabel *mpLabel;
    QLabel *passwordLabel;
    QLineEdit *mpLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *addressLabel;
    QLabel *chargeLabel;
    QLineEdit *addressLineEdit;
    QComboBox *chargeComboBox;
    QLabel *phoneLabel;
    QLabel *levelLabel;
    QLineEdit *phoneLineEdit;
    QSpinBox *levelSpinBox;

    void setupUi(QDialog *editPersonsForm)
    {
        if (editPersonsForm->objectName().isEmpty())
            editPersonsForm->setObjectName(QString::fromUtf8("editPersonsForm"));
        editPersonsForm->resize(464, 350);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(editPersonsForm->sizePolicy().hasHeightForWidth());
        editPersonsForm->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/users.png"), QSize(), QIcon::Normal, QIcon::Off);
        editPersonsForm->setWindowIcon(icon);
        gridLayout = new QGridLayout(editPersonsForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        personsComboBox = new QComboBox(editPersonsForm);
        personsComboBox->setObjectName(QString::fromUtf8("personsComboBox"));
        personsComboBox->setMinimumSize(QSize(150, 24));
        QFont font;
        font.setPointSize(9);
        personsComboBox->setFont(font);
        personsComboBox->setEditable(true);
        personsComboBox->setModelColumn(0);

        horizontalLayout->addWidget(personsComboBox);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        updateButton = new QPushButton(editPersonsForm);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setEnabled(true);
        updateButton->setMinimumSize(QSize(30, 30));
        updateButton->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        updateButton->setIcon(icon1);

        horizontalLayout->addWidget(updateButton);

        newButton = new QPushButton(editPersonsForm);
        newButton->setObjectName(QString::fromUtf8("newButton"));
        newButton->setEnabled(true);
        newButton->setMinimumSize(QSize(30, 30));
        newButton->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/add-user.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton->setIcon(icon2);

        horizontalLayout->addWidget(newButton);

        saveButton = new QPushButton(editPersonsForm);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setEnabled(true);
        saveButton->setMinimumSize(QSize(30, 30));
        saveButton->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/save-user.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon3);

        horizontalLayout->addWidget(saveButton);

        removeButton = new QPushButton(editPersonsForm);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setEnabled(true);
        removeButton->setMinimumSize(QSize(30, 30));
        removeButton->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/remove-user.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeButton->setIcon(icon4);

        horizontalLayout->addWidget(removeButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        label = new QLabel(editPersonsForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setIndent(4);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        percentageLabel = new QLabel(editPersonsForm);
        percentageLabel->setObjectName(QString::fromUtf8("percentageLabel"));
        percentageLabel->setFont(font);
        percentageLabel->setIndent(4);

        gridLayout->addWidget(percentageLabel, 1, 1, 1, 1);

        nitLineEdit = new QLineEdit(editPersonsForm);
        nitLineEdit->setObjectName(QString::fromUtf8("nitLineEdit"));
        nitLineEdit->setMinimumSize(QSize(220, 24));
        nitLineEdit->setFont(font);

        gridLayout->addWidget(nitLineEdit, 2, 0, 1, 1);

        percentageSpinBox = new QDoubleSpinBox(editPersonsForm);
        percentageSpinBox->setObjectName(QString::fromUtf8("percentageSpinBox"));
        percentageSpinBox->setMinimumSize(QSize(220, 24));
        percentageSpinBox->setFont(font);
        percentageSpinBox->setDecimals(1);
        percentageSpinBox->setValue(20.000000000000000);

        gridLayout->addWidget(percentageSpinBox, 2, 1, 1, 1);

        label_4 = new QLabel(editPersonsForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setIndent(4);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        availibleLabel = new QLabel(editPersonsForm);
        availibleLabel->setObjectName(QString::fromUtf8("availibleLabel"));
        availibleLabel->setFont(font);
        availibleLabel->setIndent(4);

        gridLayout->addWidget(availibleLabel, 3, 1, 1, 1);

        mailLineEdit = new QLineEdit(editPersonsForm);
        mailLineEdit->setObjectName(QString::fromUtf8("mailLineEdit"));
        mailLineEdit->setMinimumSize(QSize(0, 24));
        mailLineEdit->setFont(font);

        gridLayout->addWidget(mailLineEdit, 4, 0, 1, 1);

        availibleComboBox = new QComboBox(editPersonsForm);
        availibleComboBox->addItem(QString());
        availibleComboBox->addItem(QString());
        availibleComboBox->addItem(QString());
        availibleComboBox->addItem(QString());
        availibleComboBox->setObjectName(QString::fromUtf8("availibleComboBox"));
        availibleComboBox->setMinimumSize(QSize(0, 24));
        availibleComboBox->setFont(font);

        gridLayout->addWidget(availibleComboBox, 4, 1, 1, 1);

        label_5 = new QLabel(editPersonsForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setIndent(4);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        longNameLabel = new QLabel(editPersonsForm);
        longNameLabel->setObjectName(QString::fromUtf8("longNameLabel"));
        longNameLabel->setFont(font);
        longNameLabel->setIndent(4);

        gridLayout->addWidget(longNameLabel, 5, 1, 1, 1);

        celLineEdit = new QLineEdit(editPersonsForm);
        celLineEdit->setObjectName(QString::fromUtf8("celLineEdit"));
        celLineEdit->setMinimumSize(QSize(0, 24));
        celLineEdit->setFont(font);

        gridLayout->addWidget(celLineEdit, 6, 0, 1, 1);

        longNameLineEdit = new QLineEdit(editPersonsForm);
        longNameLineEdit->setObjectName(QString::fromUtf8("longNameLineEdit"));
        longNameLineEdit->setMinimumSize(QSize(0, 24));
        longNameLineEdit->setFont(font);

        gridLayout->addWidget(longNameLineEdit, 6, 1, 1, 1);

        mpLabel = new QLabel(editPersonsForm);
        mpLabel->setObjectName(QString::fromUtf8("mpLabel"));
        mpLabel->setFont(font);
        mpLabel->setIndent(4);

        gridLayout->addWidget(mpLabel, 7, 0, 1, 1);

        passwordLabel = new QLabel(editPersonsForm);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setFont(font);
        passwordLabel->setIndent(4);

        gridLayout->addWidget(passwordLabel, 7, 1, 1, 1);

        mpLineEdit = new QLineEdit(editPersonsForm);
        mpLineEdit->setObjectName(QString::fromUtf8("mpLineEdit"));
        mpLineEdit->setMinimumSize(QSize(0, 24));
        mpLineEdit->setFont(font);

        gridLayout->addWidget(mpLineEdit, 8, 0, 1, 1);

        passwordLineEdit = new QLineEdit(editPersonsForm);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setMinimumSize(QSize(0, 24));
        passwordLineEdit->setFont(font);

        gridLayout->addWidget(passwordLineEdit, 8, 1, 1, 1);

        addressLabel = new QLabel(editPersonsForm);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));
        addressLabel->setFont(font);
        addressLabel->setIndent(4);

        gridLayout->addWidget(addressLabel, 9, 0, 1, 1);

        chargeLabel = new QLabel(editPersonsForm);
        chargeLabel->setObjectName(QString::fromUtf8("chargeLabel"));
        chargeLabel->setFont(font);
        chargeLabel->setIndent(4);

        gridLayout->addWidget(chargeLabel, 9, 1, 1, 1);

        addressLineEdit = new QLineEdit(editPersonsForm);
        addressLineEdit->setObjectName(QString::fromUtf8("addressLineEdit"));
        addressLineEdit->setMinimumSize(QSize(0, 24));
        addressLineEdit->setFont(font);

        gridLayout->addWidget(addressLineEdit, 10, 0, 1, 1);

        chargeComboBox = new QComboBox(editPersonsForm);
        chargeComboBox->addItem(QString());
        chargeComboBox->addItem(QString());
        chargeComboBox->addItem(QString());
        chargeComboBox->addItem(QString());
        chargeComboBox->addItem(QString());
        chargeComboBox->setObjectName(QString::fromUtf8("chargeComboBox"));
        chargeComboBox->setMinimumSize(QSize(0, 24));
        chargeComboBox->setFont(font);

        gridLayout->addWidget(chargeComboBox, 10, 1, 1, 1);

        phoneLabel = new QLabel(editPersonsForm);
        phoneLabel->setObjectName(QString::fromUtf8("phoneLabel"));
        phoneLabel->setFont(font);
        phoneLabel->setIndent(4);

        gridLayout->addWidget(phoneLabel, 11, 0, 1, 1);

        levelLabel = new QLabel(editPersonsForm);
        levelLabel->setObjectName(QString::fromUtf8("levelLabel"));
        levelLabel->setFont(font);
        levelLabel->setIndent(4);

        gridLayout->addWidget(levelLabel, 11, 1, 1, 1);

        phoneLineEdit = new QLineEdit(editPersonsForm);
        phoneLineEdit->setObjectName(QString::fromUtf8("phoneLineEdit"));
        phoneLineEdit->setMinimumSize(QSize(0, 24));
        phoneLineEdit->setFont(font);

        gridLayout->addWidget(phoneLineEdit, 12, 0, 1, 1);

        levelSpinBox = new QSpinBox(editPersonsForm);
        levelSpinBox->setObjectName(QString::fromUtf8("levelSpinBox"));
        levelSpinBox->setMinimumSize(QSize(0, 24));
        QFont font1;
        font1.setPointSize(9);
        font1.setItalic(false);
        levelSpinBox->setFont(font1);

        gridLayout->addWidget(levelSpinBox, 12, 1, 1, 1);

        QWidget::setTabOrder(personsComboBox, nitLineEdit);
        QWidget::setTabOrder(nitLineEdit, mailLineEdit);
        QWidget::setTabOrder(mailLineEdit, celLineEdit);
        QWidget::setTabOrder(celLineEdit, mpLineEdit);
        QWidget::setTabOrder(mpLineEdit, addressLineEdit);
        QWidget::setTabOrder(addressLineEdit, phoneLineEdit);
        QWidget::setTabOrder(phoneLineEdit, percentageSpinBox);
        QWidget::setTabOrder(percentageSpinBox, availibleComboBox);
        QWidget::setTabOrder(availibleComboBox, longNameLineEdit);
        QWidget::setTabOrder(longNameLineEdit, passwordLineEdit);
        QWidget::setTabOrder(passwordLineEdit, chargeComboBox);
        QWidget::setTabOrder(chargeComboBox, levelSpinBox);
        QWidget::setTabOrder(levelSpinBox, updateButton);
        QWidget::setTabOrder(updateButton, newButton);
        QWidget::setTabOrder(newButton, saveButton);
        QWidget::setTabOrder(saveButton, removeButton);

        retranslateUi(editPersonsForm);

        QMetaObject::connectSlotsByName(editPersonsForm);
    } // setupUi

    void retranslateUi(QDialog *editPersonsForm)
    {
        editPersonsForm->setWindowTitle(QApplication::translate("editPersonsForm", "Edici\303\263n de Datos Personales", nullptr));
#ifndef QT_NO_TOOLTIP
        updateButton->setToolTip(QApplication::translate("editPersonsForm", "Guardar", nullptr));
#endif // QT_NO_TOOLTIP
        updateButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QApplication::translate("editPersonsForm", "Nuevo", nullptr));
#endif // QT_NO_TOOLTIP
        newButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("editPersonsForm", "Nuevo", nullptr));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        removeButton->setToolTip(QApplication::translate("editPersonsForm", "Eliminar", nullptr));
#endif // QT_NO_TOOLTIP
        removeButton->setText(QString());
        label->setText(QApplication::translate("editPersonsForm", "NIT", nullptr));
        percentageLabel->setText(QApplication::translate("editPersonsForm", "Porcentaje", nullptr));
        percentageSpinBox->setSuffix(QApplication::translate("editPersonsForm", "%", nullptr));
        label_4->setText(QApplication::translate("editPersonsForm", "e-mail", nullptr));
        availibleLabel->setText(QApplication::translate("editPersonsForm", "Disponibilidad", nullptr));
        availibleComboBox->setItemText(0, QApplication::translate("editPersonsForm", "Disponible", nullptr));
        availibleComboBox->setItemText(1, QApplication::translate("editPersonsForm", "En Comisi\303\263n", nullptr));
        availibleComboBox->setItemText(2, QApplication::translate("editPersonsForm", "En Entrenamiento", nullptr));
        availibleComboBox->setItemText(3, QApplication::translate("editPersonsForm", "Inactivo", nullptr));

        label_5->setText(QApplication::translate("editPersonsForm", "Celular", nullptr));
        longNameLabel->setText(QApplication::translate("editPersonsForm", "Nombre Completo", nullptr));
        mpLabel->setText(QApplication::translate("editPersonsForm", "Matr\303\255cula Profesional", nullptr));
        passwordLabel->setText(QApplication::translate("editPersonsForm", "Contrase\303\261a", nullptr));
        addressLabel->setText(QApplication::translate("editPersonsForm", "Direcci\303\263n", nullptr));
        chargeLabel->setText(QApplication::translate("editPersonsForm", "Cargo", nullptr));
        chargeComboBox->setItemText(0, QApplication::translate("editPersonsForm", "Comercial", nullptr));
        chargeComboBox->setItemText(1, QApplication::translate("editPersonsForm", "Contabilidad", nullptr));
        chargeComboBox->setItemText(2, QApplication::translate("editPersonsForm", "Documentos", nullptr));
        chargeComboBox->setItemText(3, QApplication::translate("editPersonsForm", "Ingenier\303\255a", nullptr));
        chargeComboBox->setItemText(4, QApplication::translate("editPersonsForm", "Gerencia", nullptr));

        phoneLabel->setText(QApplication::translate("editPersonsForm", "Tel\303\251fono", nullptr));
        levelLabel->setText(QApplication::translate("editPersonsForm", "Nivel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editPersonsForm: public Ui_editPersonsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPERSONS_H
