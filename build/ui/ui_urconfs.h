/********************************************************************************
** Form generated from reading UI file 'urconfs.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_URCONFS_H
#define UI_URCONFS_H

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

class Ui_UrConfsForm
{
public:
    QGridLayout *gridLayout;
    QLineEdit *dbNameLineEdit;
    QLabel *label_3;
    QLabel *label;
    QSpinBox *updateTimeSpinBox;
    QLabel *label_2;
    QLineEdit *sqlServerIpLineEdit;
    QLineEdit *webServerLineEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *saveConfsButton;
    QLabel *label_4;

    void setupUi(QDialog *UrConfsForm)
    {
        if (UrConfsForm->objectName().isEmpty())
            UrConfsForm->setObjectName(QStringLiteral("UrConfsForm"));
        UrConfsForm->resize(395, 163);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        UrConfsForm->setWindowIcon(icon);
        gridLayout = new QGridLayout(UrConfsForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        dbNameLineEdit = new QLineEdit(UrConfsForm);
        dbNameLineEdit->setObjectName(QStringLiteral("dbNameLineEdit"));
        dbNameLineEdit->setMinimumSize(QSize(0, 24));
        QFont font;
        font.setPointSize(9);
        dbNameLineEdit->setFont(font);

        gridLayout->addWidget(dbNameLineEdit, 2, 1, 1, 1);

        label_3 = new QLabel(UrConfsForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label = new QLabel(UrConfsForm);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        updateTimeSpinBox = new QSpinBox(UrConfsForm);
        updateTimeSpinBox->setObjectName(QStringLiteral("updateTimeSpinBox"));
        updateTimeSpinBox->setMinimumSize(QSize(0, 24));
        updateTimeSpinBox->setFont(font);
        updateTimeSpinBox->setMaximum(120);
        updateTimeSpinBox->setSingleStep(10);

        gridLayout->addWidget(updateTimeSpinBox, 4, 1, 1, 1);

        label_2 = new QLabel(UrConfsForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        sqlServerIpLineEdit = new QLineEdit(UrConfsForm);
        sqlServerIpLineEdit->setObjectName(QStringLiteral("sqlServerIpLineEdit"));
        sqlServerIpLineEdit->setMinimumSize(QSize(0, 24));
        sqlServerIpLineEdit->setFont(font);

        gridLayout->addWidget(sqlServerIpLineEdit, 0, 1, 1, 1);

        webServerLineEdit = new QLineEdit(UrConfsForm);
        webServerLineEdit->setObjectName(QStringLiteral("webServerLineEdit"));
        webServerLineEdit->setMinimumSize(QSize(0, 24));
        webServerLineEdit->setFont(font);

        gridLayout->addWidget(webServerLineEdit, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        saveConfsButton = new QPushButton(UrConfsForm);
        saveConfsButton->setObjectName(QStringLiteral("saveConfsButton"));
        saveConfsButton->setEnabled(true);
        saveConfsButton->setMinimumSize(QSize(0, 26));
        QFont font1;
        font1.setPointSize(10);
        saveConfsButton->setFont(font1);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveConfsButton->setIcon(icon1);

        gridLayout->addWidget(saveConfsButton, 6, 0, 1, 2);

        label_4 = new QLabel(UrConfsForm);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        QWidget::setTabOrder(sqlServerIpLineEdit, dbNameLineEdit);
        QWidget::setTabOrder(dbNameLineEdit, webServerLineEdit);
        QWidget::setTabOrder(webServerLineEdit, updateTimeSpinBox);
        QWidget::setTabOrder(updateTimeSpinBox, saveConfsButton);

        retranslateUi(UrConfsForm);

        QMetaObject::connectSlotsByName(UrConfsForm);
    } // setupUi

    void retranslateUi(QDialog *UrConfsForm)
    {
        UrConfsForm->setWindowTitle(QApplication::translate("UrConfsForm", "Configuraciones UltraRetie", nullptr));
        dbNameLineEdit->setInputMask(QString());
        dbNameLineEdit->setText(QString());
        label_3->setText(QApplication::translate("UrConfsForm", "Tiempo para actualizar estados:", nullptr));
        label->setText(QApplication::translate("UrConfsForm", "Direcci\303\263n IP del servidor Postgres:", nullptr));
        updateTimeSpinBox->setSuffix(QApplication::translate("UrConfsForm", " minutos", nullptr));
        label_2->setText(QApplication::translate("UrConfsForm", "Direcci\303\263n URL del servidor Web:", nullptr));
#ifndef QT_NO_TOOLTIP
        sqlServerIpLineEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        sqlServerIpLineEdit->setInputMask(QApplication::translate("UrConfsForm", "000.000.000.000;_", nullptr));
        webServerLineEdit->setInputMask(QString());
        webServerLineEdit->setText(QString());
        saveConfsButton->setText(QApplication::translate("UrConfsForm", "Guardar Configuraciones", nullptr));
        label_4->setText(QApplication::translate("UrConfsForm", "Nombre de la base de datos:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UrConfsForm: public Ui_UrConfsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URCONFS_H
