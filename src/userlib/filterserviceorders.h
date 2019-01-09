#ifndef FILTERSERVICEORDERS_H
#define FILTERSERVICEORDERS_H

#include "ui_filterserviceorders.h"
#include <QSortFilterProxyModel>

class FilterServiceOrdersForm : public QDialog, public Ui::filterServiceOrdersForm
{
    Q_OBJECT

public:
    FilterServiceOrdersForm(QDialog *parent = 0);

    QSortFilterProxyModel *proxyModel;
    QString so_id;

private:
public slots:

    void setSoIdRegExp(QString RegExp);
    void setDateRegExp(QString RegExp);
    void setInstNameRegExp(QString RegExp);
    void setScopeRegExp(QString RegExp);
    void setNameRegExp(QString RegExp);
    void setValueRegExp(QString RegExp);
    void setAssignDateRegExp(QString RegExp);
    void setProcessedRegExp(QString RegExp);
    void setDocProcessedRegExp(QString RegExp);
    void setEngProcessedRegExp(QString RegExp);

    void sendAndClose(void);

};

#endif // FILTERSERVICEORDERS_H
