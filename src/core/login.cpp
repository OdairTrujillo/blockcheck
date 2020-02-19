#include <QtWidgets>

#include "login.h"
#include "dbhandler.h"
#include "userlib/logger.h"

LoginDialog::LoginDialog(QDialog *parent)
    : QDialog(parent)
{
    setupUi(this);

//    if (!DbHandler::createConnection()) {
//        qDebug() << "No se obtuvo acceso a la DB ";
//    }

    passwdLineEdit->setEchoMode(QLineEdit::Password);

    connect(loginButton, SIGNAL(clicked()),
            this, SLOT(userLogin(void)));
    connect(closeButton, SIGNAL(clicked()),
            this, SLOT(close()));
}

void LoginDialog::userLogin(void)
{
    if (DbHandler::getLogin(userNameLineEdit->text(), passwdLineEdit->text(), userData)) {
        Logger::login(userData.at(0), userData.at(2));
        this->accept();
    }
    else
        QMessageBox::information(this, trUtf8("Error"),
                                 trUtf8("Nombre de Usuario o Contraseña incorrecto"),
                                 QMessageBox::Cancel);
}
