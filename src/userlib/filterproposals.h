#ifndef FILTERPROPOSALS_H
#define FILTERPROPOSALS_H

#include "ui_filterproposals.h"
#include <QSortFilterProxyModel>

class FilterProposalsForm : public QDialog, public Ui::filterProposalsForm
{
    Q_OBJECT

public:
    FilterProposalsForm(QDialog *parent = 0);

    QSortFilterProxyModel *proxyModel;
    QString prop_id;

private:
public slots:

    void setPropIdRegExp(QString RegExp);
    void setDateRegExp(QString RegExp);
    void setInstNameRegExp(QString RegExp);
    void setScopeRegExp(QString RegExp);
    void setNameRegExp(QString RegExp);
    void setValueRegExp(QString RegExp);
    void setStateRegExp(QString RegExp);
    void setUserRegExp(QString RegExp);

    void sendAndClose(void);

};

#endif // FILTERPROPOSALS_H
