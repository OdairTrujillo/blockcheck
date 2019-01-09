#include "logger.h"
#include "../core/dbhandler.h"

void Logger::login(QString name, QString lname)
{
    QStringList logData;

    logData.append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    logData.append(name);
    logData.append(trUtf8("Inicio de sesión del usuario: ") + lname);
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("16");

    if (!DbHandler::insertLogReg(logData))
        qDebug() << trUtf8("DbHandler::insertLogReg devolvió false al tratar de insertar registro de inicio de sesión");
}

void Logger::logout(QString name, QString lname)
{
    QStringList logData;

    logData.append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    logData.append(name);
    logData.append(trUtf8("Cierre de sesión del usuario: ") + lname);
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("17");

    if (!DbHandler::insertLogReg(logData))
        qDebug() << trUtf8("DbHandler::insertLogReg devolvió false al tratar de insertar registro de cierre de sesión");
}

void Logger::insertQuotation(QString name, QString thrdNit, QString quotId)
{
    QStringList logData;

    logData.append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    logData.append(name);
    logData.append(trUtf8("Nueva cotización para el NIT: ") + thrdNit);
    logData.append(quotId);
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("19");

    if (!DbHandler::insertLogReg(logData))
        qDebug() << trUtf8("DbHandler::insertLogReg devolvió false al tratar de insertar registro de nueva cotización");
}

void Logger::insertProposal(QString name, QString thrdNit, QString quotId, QString propId)
{
    QStringList logData;

    logData.append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    logData.append(name);
    logData.append(trUtf8("Nueva propuesta para el NIT: ") + thrdNit);
    logData.append(quotId);
    logData.append(propId);
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("23");

    if (!DbHandler::insertLogReg(logData))
        qDebug() << trUtf8("DbHandler::insertLogReg devolvió false al tratar de insertar registro de nueva propuesta");
}

void Logger::insertServiceOrder(QString name, QString thrdNit, QString quotId, QString propId, QString soId)
{
    QStringList logData;

    logData.append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    logData.append(name);
    logData.append(trUtf8("Nueva orden de servicio para el NIT: ") + thrdNit);
    logData.append(quotId);
    logData.append(propId);
    logData.append(soId);
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("26");

    if (!DbHandler::insertLogReg(logData))
        qDebug() << trUtf8("DbHandler::insertLogReg devolvió false al tratar de insertar registro de nueva OS");
}

//queryInsertLogReg.bindValue(":log_date_time", logData.at(0));
//queryInsertLogReg.bindValue(":log_user_name", logData.at(1));
//queryInsertLogReg.bindValue(":log_detail", logData.at(2));
//queryInsertLogReg.bindValue(":quot_id", logData.at(3).toInt());
//queryInsertLogReg.bindValue(":prop_id", logData.at(4).toInt());
//queryInsertLogReg.bindValue(":so_id", logData.at(5).toInt());
//queryInsertLogReg.bindValue(":inspection_id", logData.at(6).toInt());
//queryInsertLogReg.bindValue(":dictum_id", logData.at(7).toInt());
//queryInsertLogReg.bindValue(":subdictum_id", logData.at(8).toInt());
//queryInsertLogReg.bindValue(":event_type_id", logData.at(9).toInt());

void Logger::updateUser(QString name, QString userLName)
{
    QStringList logData;

    logData.append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    logData.append(name);
    logData.append(trUtf8("Se editó el usuario: ") + userLName);
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("2"); //Tipo de evento

    if (!DbHandler::insertLogReg(logData))
        qDebug() << trUtf8("DbHandler::insertLogReg devolvió false al tratar de insertar registro de nueva OS");
}

void Logger::updateInspector(QString name, QString inspectorName)
{
    QStringList logData;

    logData.append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    logData.append(name);
    logData.append(trUtf8("Se editó el inspector: ") + inspectorName);
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("0");
    logData.append("5"); //Tipo de evento

    if (!DbHandler::insertLogReg(logData))
        qDebug() << trUtf8("DbHandler::insertLogReg devolvió false al tratar de insertar registro de nueva OS");
}
