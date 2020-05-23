#ifndef EDITPERSONS_H
#define EDITPERSONS_H

#include "ui_editpersons.h"
#include "userlib/bcnamespace.h"
#include <QDialog>


class EditPersonsForm : public QDialog, public Ui::editPersonsForm
{
    Q_OBJECT
    
public:
    explicit EditPersonsForm(int person_Type, QWidget *parent = 0);

    QList<QStringList> designersData;
    QList<QStringList> constructorsData;
    QList<QStringList> auditorsData;
    QList<QStringList> inspectorsData;
    QList<QStringList> usersData;
    QString userName;

    int personType;


    void styleWithThrds();
    void styleWithStaff();
    void setDialogType();
    void clearControls();
    bool validateData();
    void enableControls();
    void disableControls();

public slots:
    void fillDesignerData(int index);
    void fillConstructorData(int index);
    void fillAuditorData(int index);
    void fillInspectorData(int index);
    void fillUserData(int index);
    void updatePerson();
    void newPerson();
    void removePerson();
    void savePerson();

};

#endif // EDITPERSONS_H
