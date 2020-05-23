#ifndef SALES_H
#define SALES_H

#include "ui_sales.h"
#include <QStandardItemModel>
#include <QTableView>
#include "userlib/spinboxdelegate.h"
#include "userlib/filterquotations.h"

class SalesForm : public QDialog, public Ui::salesForm
{
    Q_OBJECT

public:
    SalesForm(QWidget *parent = 0);

    QList<QStringList> quotCitiesData;
    QList<QStringList> thrdCitiesData;
    QList<QStringList> statesData;
    QList<QStringList> usesData;
    QList<QStringList> processesData;
    QList<QStringList> inspectorsData;
    QList<QStringList> usersData;
    QList<QStringList> recordsData;
    QStringList thrdData;
    QList<QStringList> quotsData;
    QStringList propsThrdData;
    QList<QStringList> propsData;
    QList<QStringList> documentsData;
    QStringList sosThrdData;
    QList<QStringList> sosData;
    QStandardItemModel *propValueModel;
    SpinBoxDelegate *spinBoxDelegate;
    QString userName;
    int quot_position;
    int prop_position;
    int so_position;
    int newQuot;
    int newProp;
    int newSo;
    int oldTabIndex;
    int found;
    //bool eventFilter(QObject* object, QEvent* event);
    //FilterQuotationsForm filterForm;

private:
    void fillQuotControls(void);
    void fillPropControls(void);
    void fillSoControls(void);
    void setValidators(void);


    int findByNit(QString thrdNit);
    int findByThrdId(QString thrdId);
    int findByInstName(QString instName);
    int findByScope(QString scope);
    int findByPropId(QString propId);
    int findBySoId(QString soId);
    int findByRecordFoil(QString recordFoil);

    int insertQuotation(int opt);
    int insertProposal();
    int insertServiceOrder();

    bool updateQuotation();
    bool updateProposal();
    bool updateServiceOrder();

    int deleteQuotation();
    int deleteProposal();
    int deleteServiceOrder();


    //Estas funciones no reciben datos porque operan sobre
    //variables miembro
    void fillQuotData();
    void fillPropData();
    void fillSoData();


    //void fillSoData(void);
    void clearQuotControls();
    void clearThrdQuotControls();
    void clearPropControls();
    void clearSoControls();

    void preparePropControls();
    void prepareSoControls();

    bool validateQuotData();
    bool validatePropData();
    bool validateSoData();

    void listQuotations();
    void listProposals();
    void listServiceOrders();


private slots:
    void findSomething(void); // something porque no se sabe si es cotizacion, propuesta u os.
    void newSomething(void);
    void updateSomething(void);
    void deleteSomething();
    void findNext(void);
    void findPrevious(void);

    void setQuotCity(int);
    void setThrdCity(int);

    void genQuotation(void);
    void genProposal(void);
    void genServiceOrder(void);

    void renderProposal(void);
    void renderServiceOrder(void);
    void printProposal(void);
    void printServiceOrder(void);
    void listSomething();
    void propTotalSum(void);

    void testQuotation();
    void testProposal();

    void approvProposal();
    void rejectProposal();

};

#endif // SALES_H

