#ifndef FILTERQUOTATIONS_H
#define FILTERQUOTATIONS_H

#include "ui_filterquotations.h"
#include <QSortFilterProxyModel>

class FilterQuotationsForm : public QDialog, public Ui::filterQuotationsForm
{
    Q_OBJECT

public:
    FilterQuotationsForm(QDialog *parent = 0);

    QSortFilterProxyModel *proxyModel;
    QString thrd_nit;

private:
public slots:

    void setDateRegExp(QString RegExp);
    void setInstNameRegExp(QString RegExp);
    void setScopeRegExp(QString RegExp);
    void setNameRegExp(QString RegExp);
    void setNitRegExp(QString RegExp);
    void setCelRegExp(QString RegExp);
    void setPhoneRegExp(QString RegExp);
    void setStateRegExp(QString RegExp);
    void setCityRegExp(QString RegExp);
    void setInstTypeRegExp(QString RegExp);

    void sendAndClose(void);

};

#endif // FILTERQUOTATIONS_H
