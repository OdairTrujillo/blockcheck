/********************************************************************************
** Form generated from reading UI file 'bcconfs.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCCONFS_H
#define UI_BCCONFS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BcConfsForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *dbNameLineEdit;
    QLabel *label_3;
    QLineEdit *webServerLineEdit;
    QLabel *label_2;
    QLineEdit *sqlServerIpLineEdit;
    QSpinBox *updateTimeSpinBox;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QPushButton *saveConfsButton;

    void setupUi(QDialog *BcConfsForm)
    {
        if (BcConfsForm->objectName().isEmpty())
            BcConfsForm->setObjectName(QString::fromUtf8("BcConfsForm"));
        BcConfsForm->resize(395, 170);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        BcConfsForm->setWindowIcon(icon);
        gridLayout = new QGridLayout(BcConfsForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(BcConfsForm);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        dbNameLineEdit = new QLineEdit(BcConfsForm);
        dbNameLineEdit->setObjectName(QString::fromUtf8("dbNameLineEdit"));
        dbNameLineEdit->setMinimumSize(QSize(0, 24));
        dbNameLineEdit->setFont(font);

        gridLayout->addWidget(dbNameLineEdit, 2, 1, 1, 1);

        label_3 = new QLabel(BcConfsForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        webServerLineEdit = new QLineEdit(BcConfsForm);
        webServerLineEdit->setObjectName(QString::fromUtf8("webServerLineEdit"));
        webServerLineEdit->setMinimumSize(QSize(0, 24));
        webServerLineEdit->setFont(font);

        gridLayout->addWidget(webServerLineEdit, 3, 1, 1, 1);

        label_2 = new QLabel(BcConfsForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        sqlServerIpLineEdit = new QLineEdit(BcConfsForm);
        sqlServerIpLineEdit->setObjectName(QString::fromUtf8("sqlServerIpLineEdit"));
        sqlServerIpLineEdit->setMinimumSize(QSize(0, 24));
        sqlServerIpLineEdit->setFont(font);

        gridLayout->addWidget(sqlServerIpLineEdit, 0, 1, 1, 1);

        updateTimeSpinBox = new QSpinBox(BcConfsForm);
        updateTimeSpinBox->setObjectName(QString::fromUtf8("updateTimeSpinBox"));
        updateTimeSpinBox->setMinimumSize(QSize(0, 24));
        updateTimeSpinBox->setFont(font);
        updateTimeSpinBox->setMaximum(120);
        updateTimeSpinBox->setSingleStep(10);

        gridLayout->addWidget(updateTimeSpinBox, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        label_4 = new QLabel(BcConfsForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        saveConfsButton = new QPushButton(BcConfsForm);
        saveConfsButton->setObjectName(QString::fromUtf8("saveConfsButton"));
        saveConfsButton->setEnabled(true);
        saveConfsButton->setMinimumSize(QSize(0, 26));
        QFont font1;
        font1.setPointSize(10);
        saveConfsButton->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveConfsButton->setIcon(icon1);

        gridLayout->addWidget(saveConfsButton, 6, 0, 1, 2);

        QWidget::setTabOrder(sqlServerIpLineEdit, dbNameLineEdit);
        QWidget::setTabOrder(dbNameLineEdit, webServerLineEdit);
        QWidget::setTabOrder(webServerLineEdit, updateTimeSpinBox);
        QWidget::setTabOrder(updateTimeSpinBox, saveConfsButton);

        retranslateUi(BcConfsForm);

        QMetaObject::connectSlotsByName(BcConfsForm);
    } // setupUi

    void retranslateUi(QDialog *BcConfsForm)
    {
        BcConfsForm->setWindowTitle(QApplication::translate("BcConfsForm", "Configuraciones BlockCheck", nullptr));
        label->setText(QApplication::translate("BcConfsForm", "Direcci\303\263n IP del servidor Postgres:", nullptr));
        dbNameLineEdit->setInputMask(QString());
        dbNameLineEdit->setText(QString());
        label_3->setText(QApplication::translate("BcConfsForm", "Tiempo para actualizar estados:", nullptr));
        webServerLineEdit->setInputMask(QString());
        webServerLineEdit->setText(QString());
        label_2->setText(QApplication::translate("BcConfsForm", "Direcci\303\263n URL del servidor Web:", nullptr));
#ifndef QT_NO_TOOLTIP
        sqlServerIpLineEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        sqlServerIpLineEdit->setInputMask(QApplication::translate("BcConfsForm", "000.000.000.000;_", nullptr));
        updateTimeSpinBox->setSuffix(QApplication::translate("BcConfsForm", " minutos", nullptr));
        label_4->setText(QApplication::translate("BcConfsForm", "Nombre de la base de datos:", nullptr));
        saveConfsButton->setText(QApplication::translate("BcConfsForm", "Guardar Configuraciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BcConfsForm: public Ui_BcConfsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCCONFS_H
