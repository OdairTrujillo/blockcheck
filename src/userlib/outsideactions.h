#ifndef OUTSIDEACTIONS_H
#define OUTSIDEACTIONS_H

#include <QtCore>

class OutsideActions : public QObject
{
    Q_OBJECT
public:
    OutsideActions();

    bool readSqlServerConf();
    QString readWebServerConf();
    static int readUpdateTimeConf();

    QString sqlServerIP, databaseName;
    int sqlServerPort;
};

#endif // OUTSIDEACTIONS_H
