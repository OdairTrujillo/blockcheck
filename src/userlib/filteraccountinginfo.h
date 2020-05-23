#ifndef FILTERACCOUNTINGINFO_H
#define FILTERACCOUNTINGINFO_H

#include "ui_filteraccountinginfo.h"
#include <QSortFilterProxyModel>

class FilterAccountingInfoForm : public QDialog, public Ui::filterAccountingInfoForm
{
    Q_OBJECT

public:
    FilterAccountingInfoForm(QDialog *parent = 0);

    QSortFilterProxyModel *proxyModel;
    QString so_id;

private:
public slots:

    void setSoIdRegExp(QString RegExp);
    void setMovTypeRegExp(QString RegExp);
    void setMovDocummentRegExp(QString RegExp);
    void setMovDateRegExp(QString RegExp);
    void setMovNameRegExp(QString RegExp);
    void setMovNitRegExp(QString RegExp);
    void setMovObservationsRegExp(QString RegExp);

    void sendAndClose(void);

};


#endif // FILTERACCOUNTINGINFO_H
