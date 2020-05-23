#ifndef ENGINEERING_H
#define ENGINEERING_H

#include "userlib/bcnamespace.h"
#include "ui_engineering.h"
#include <QtWidgets>

class EngineeringForm : public QDialog, public Ui::engineeringForm
{
    Q_OBJECT

public:
    EngineeringForm(QWidget *parent = nullptr);

    QList<QStringList> sosData;
    QList<QStringList> propsData;
    QList<QStringList> quotsData;
    QList<QStringList> processesData;
    QList<QStringList> usersData;
    QList<QStringList> inspectorsData;
    QList<QStringList> recordsData;
    QList<QStringList> statesData;
    QList<QStringList> citiesData;
    QList<QStringList> usesData;
    QList<QStringList> inspectionsData;
    QList<QStringList> dictumsData;
    QList<QStringList> extraData;
    QList<QStringList> subDictumsData;
    QList<QStringList> designersData;
    QList<QStringList> constructorsData;
    QList<QStringList> auditorsData;
    QStringList thrdData;
    QStringList procsIds;

    QString inspectionId;
    QString userName;

    QStandardItemModel *propValueModel;

    QAction *editDesignersAct;
    QAction *editConstructorsAct;
    QAction *editAuditorsAct;
    QAction *changeInspectionStateAct;

private:
    void clearControls();
    void fillData();
    void prepareEngControls();
    bool validateData();
    bool updateServiceOrder(QString state);
    bool updateQuotation();
    bool insertInspection();
    void styleWithData();
    void styleWithoutData();
    void voidStyle();
    bool updateInspection();

private slots:
    void findServiceOrder(void);
    void showCheckFolderForm(void);
    void checkEngState(void);
    void processInspection(void);
    void setInspectionCity(int);
    void newDictum(void);
    void goToDictum(void);
    void getDictums(void);
    void updateInspectionAction(void);
    void saveInspectionChanges(void);
    void listServiceOrders(void);
    void editDesigners(void);
    void editConstructors(void);
    void editAuditors(void);
    void endInspection(void);
    void changeInspectionState(void);
};

#endif // ENGINEERING_H
