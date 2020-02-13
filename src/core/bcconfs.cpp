#include "bcconfs.h"

#include <QtCore>
#include <QtWidgets>

BcConfsForm::BcConfsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BcConfsForm)
{
    ui->setupUi(this);

    connect(ui->saveConfsButton, SIGNAL(clicked()),
            this, SLOT(saveConfs(void)));

    QString sqlServerIP, databaseName, webServer, updateTime;
    QString fileName(QDir::currentPath() + "/blockcheck.conf");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(0, ("Error Abriendo Configuración"),
                             ("No se puedo abrir '%1'").arg(fileName));

    } else {
        QTextStream readStream(&file);

        readStream.seek(0);
        sqlServerIP = readStream.readLine(75);
        databaseName=readStream.readLine(75);
        webServer=readStream.readLine(75);
        updateTime=readStream.readLine(75);
    }

    ui->sqlServerIpLineEdit->setText(sqlServerIP);
    ui->dbNameLineEdit->setText(databaseName);
    ui->webServerLineEdit->setText(webServer);
    ui->updateTimeSpinBox->setValue(updateTime.toInt());

}

void BcConfsForm::saveConfs(void)
{

    QString fileName(QDir::currentPath() + "/blockcheck.conf");
    QFile file(fileName);
    file.remove();
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream writeStream(&file);
    writeStream << ui->sqlServerIpLineEdit->text() << endl;
    writeStream << ui->dbNameLineEdit->text() << endl;
    writeStream << ui->webServerLineEdit->text() << endl;
    writeStream << QString::number(ui->updateTimeSpinBox->value());

    if (writeStream.status()==QTextStream::Ok) {
        QMessageBox::information(this, ("Guardando"), ("Configuraciones guardadas con éxito"),
                                                               QMessageBox::Ok);
    close();
    }
    else
        QMessageBox::warning(this, ("Guardando"), ("Hubo un error guardando el archivo"),
                                                           QMessageBox::Cancel);

}

BcConfsForm::~BcConfsForm()
{
    delete ui;
}
