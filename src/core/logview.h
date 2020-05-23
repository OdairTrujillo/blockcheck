#ifndef LOGVIEWFORM_H
#define LOGVIEWFORM_H

#include <QDialog>
#include <QSortFilterProxyModel>

namespace Ui {
class LogViewForm;
}

class LogViewForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit LogViewForm(QWidget *parent = 0);
    ~LogViewForm();

    QSortFilterProxyModel *proxyModel;
    QList<QStringList> eventTypeData;
    QList<QStringList> usersData;

    QStringList idType;
    QStringList idTypeName;
    QStringList userId;
    QStringList userName;
    QStringList eventId;
    QStringList eventName;
    
private:
    Ui::LogViewForm *ui;

private slots:
    void filterData(void);
};

#endif // LOGVIEWFORM_H
