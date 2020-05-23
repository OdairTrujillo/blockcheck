#ifndef LOGGER_H
#define LOGGER_H

#include <QtWidgets>

class Logger : public QObject
{
    Q_OBJECT

public:
    Logger(void);

    static void login(QString name, QString lname);
    static void logout(QString name, QString lname);
    static void insertQuotation(QString name, QString thrdNit, QString quotId);
    static void insertProposal(QString name, QString thrdNit, QString quotId, QString propId);
    static void insertServiceOrder(QString name, QString thrdNit, QString quotId, QString propId, QString soId);
    static void updateUser(QString name, QString userLName);
    static void updateInspector(QString name, QString inspectorName);


private:
};

#endif // LOGGER_H
