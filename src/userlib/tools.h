#include <QString>
#include <QSqlQuery>

float money2float(QString money);
QString float2money(float number);

float money2float(QString money)
{
    QString temp;
    for (int i=0;i<money.size()-3;i++) {
        if (money.at(i).isNumber())
            temp.append(money.at(i));
    }
    return temp.toFloat();
}


QString float2money(float number)
{
    QString temp;
    // Esto se hace para dar formato de moneda usando las capacidades de postgresql
    QSqlQuery formatValue;
    formatValue.prepare("SELECT :number::money");
    formatValue.bindValue(":number", number);
    formatValue.exec();
    formatValue.first();
    temp=formatValue.value(0).toString();
    return temp;
}
