#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include "ui_accounting.h"
#include <QtWidgets>

class AccountingForm : public QDialog, public Ui::accountingForm
{
    Q_OBJECT

public:
    AccountingForm(QWidget *parent = 0);

    QList<QStringList> sosData;
    QList<QStringList> sosData2; // Para revisar estado de documentos
    QList<QStringList> propsData;
    QList<QStringList> quotsData;
    QList<QStringList> processesData;
    QList<QStringList> usersData;
    QList<QStringList> inspectorsData;
    QList<QStringList> recordsData;
    QStringList thrdPaysData;
    QStringList userPaysData;
    QStringList inspectorPaysData;
    QStringList thrdData;
    QStringList procsIds;
    QStandardItemModel *propValueModel;
    QStringList soValues;
    QString userName;

private:
    void fillSoData(void);
    void clearSoControls(void);
    void renderServiceOrder(void);
    void getUserPays(void);
    void getInspectorPays(void);
    bool validateThrdPayFields(void);
    bool validateInspectorPayFields(void);
    bool validateUserPayFields(void);
    
signals:
    
public slots:
    void findServiceOrder();
    void billedServiceOrder(void);
    void listServiceOrders(void);
    void listAccountingInfo(void);
    void checkAccountingState(void);
    void payThrd(void);
    void payUser(void);
    void payInspector(void);
    void printServiceOrder();
};

#endif // ACCOUNTING_H
