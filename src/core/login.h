#ifndef LOGIN_H
#define LOGIN_H

#include "ui_login.h"


class LoginDialog : public QDialog, public Ui::loginDialog
{
    Q_OBJECT

    public:
    LoginDialog(QDialog *parent = 0);
    QStringList userData;

    private:

    private slots:
    void userLogin(void);
};
#endif // LOGIN_H
