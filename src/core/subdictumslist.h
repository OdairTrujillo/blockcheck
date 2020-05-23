#ifndef SUBDICTUMSLIST_H
#define SUBDICTUMSLIST_H

#include <QtWidgets>

#include "ui_subdictumslist.h"
#include "userlib/spinboxdelegate.h"

class SubDictumsListForm : public QDialog, public Ui::subDictumsListForm
{
    Q_OBJECT

public:
    explicit SubDictumsListForm(QStringList subDictum_Data, QList<QStringList> req_Results, int start, int end, QDialog *parent = 0);

    SpinBoxDelegate *spinBoxKVA;
    SpinBoxDelegate *spinBoxOhms;

    QStringList subDictumData;
    QList<QStringList> reqResults;
    QString subDictumId;
    QString userName;
    bool success;
    int subDictumsEnd, subDictumIndex;

signals:
    
public slots:
    void processDictums();
    
};

#endif // SUBDICTUMSLIST_H
