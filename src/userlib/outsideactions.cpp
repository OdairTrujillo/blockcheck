#include "outsideactions.h"
#include "userlib/bcnamespace.h"

#include <QMessageBox>

OutsideActions::OutsideActions()
{    
}

bool OutsideActions::readSqlServerConf()
{
    QString fileName = QDir::currentPath() + "/blockcheck.conf";
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "No se tuvo acceso a " + fileName.toUtf8();
        return false;
    } else {
        QTextStream readStream(&file);

        readStream.seek(0);
        sqlServerIP = readStream.readLine(75); // Lee la primera línea
        sqlServerPort = readStream.readLine(75).toInt(); // lee la segunda línea
        databaseName=readStream.readLine(75); // Lee la tercera línea
        return true;
    }
    return false;
}

QString OutsideActions::readWebServerConf()
{
    QString fileName = QDir::currentPath() + "/blockcheck.conf";
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "No se tuvo acceso a " + fileName.toUtf8();
        return "Error";
    } else {
        QTextStream readStream(&file);
        QString webServer;
        readStream.seek(0);
        readStream.readLine(0); // Salta la primer línea al tener tamaño 0
        readStream.readLine(0); // Salta la segunda línea
        webServer=readStream.readLine(75); // Lee la tercer línea
        return webServer;
    }

    return "Error";
}

int OutsideActions::readUpdateTimeConf()
{
    QString fileName = QDir::currentPath() + "/blockcheck.conf";
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "No se tuvo acceso a " + fileName.toUtf8();
        return 0;
    } else {
        QTextStream readStream(&file);
        QString updateTime;
        readStream.seek(0);
        readStream.readLine(0); // Salta la primer línea al tener tamaño 0
        readStream.readLine(0); // Salta la segunda línea
        readStream.readLine(0); // Salta la tercer línea
        updateTime=readStream.readLine(75); // Lee la cuarta línea

        return updateTime.toInt()*60*1000;
    }
    return 0;
}
