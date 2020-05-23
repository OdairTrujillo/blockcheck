/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *userNameLineEdit;
    QLabel *label_2;
    QLineEdit *passwdLineEdit;
    QPushButton *loginButton;
    QPushButton *closeButton;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QString::fromUtf8("loginDialog"));
        loginDialog->setWindowModality(Qt::ApplicationModal);
        loginDialog->resize(210, 235);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        loginDialog->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(loginDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(loginDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(loginDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        userNameLineEdit = new QLineEdit(loginDialog);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));
        userNameLineEdit->setMinimumSize(QSize(0, 24));
        QFont font1;
        font1.setPointSize(10);
        userNameLineEdit->setFont(font1);

        gridLayout->addWidget(userNameLineEdit, 2, 0, 1, 1);

        label_2 = new QLabel(loginDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        passwdLineEdit = new QLineEdit(loginDialog);
        passwdLineEdit->setObjectName(QString::fromUtf8("passwdLineEdit"));
        passwdLineEdit->setMinimumSize(QSize(0, 24));

        gridLayout->addWidget(passwdLineEdit, 4, 0, 1, 1);

        loginButton = new QPushButton(loginDialog);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setMinimumSize(QSize(0, 24));

        gridLayout->addWidget(loginButton, 5, 0, 1, 1);

        closeButton = new QPushButton(loginDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMinimumSize(QSize(0, 24));

        gridLayout->addWidget(closeButton, 6, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(loginDialog);

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QApplication::translate("loginDialog", "Inicio Sesi\303\263n", nullptr));
        label->setText(QApplication::translate("loginDialog", "<html><head/><body><div align=\"center\">Ingrese su Nombre de<br>\n"
"Usuario y Contrase\303\261a<br>\n"
"</div></body></html>", nullptr));
        label_3->setText(QApplication::translate("loginDialog", "Nombre de Usuario", nullptr));
        userNameLineEdit->setText(QString());
        label_2->setText(QApplication::translate("loginDialog", "Contrase\303\261a", nullptr));
        passwdLineEdit->setInputMask(QString());
        passwdLineEdit->setText(QString());
        loginButton->setText(QApplication::translate("loginDialog", "Iniciar Sesi\303\263n", nullptr));
        closeButton->setText(QApplication::translate("loginDialog", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
