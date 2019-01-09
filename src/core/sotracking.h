#ifndef SOTRACKING_H
#define SOTRACKING_H

#include "ui_sotracking.h"
#include <QtWidgets>
#include <QtCore>

class SoTrackingForm : public QDialog, public Ui::soTrackingForm
{
    Q_OBJECT

public:
    SoTrackingForm(QDialog *parent = 0, QString soId="");
//    ~SoTrackingForm();

    QList<QStringList> statesData;
    QList<QStringList> citiesData;
    QList<QStringList> usersData;
    QStringList soTrackingData;
    QString userName;

    bool recordExist; // Sirve para definir si se encontró el registro o no.

private:


signals:

public slots:
    void setShippingCity(int);
    void insertOrUpdateShipping(void);

};

#endif // SOTRACKING_H
