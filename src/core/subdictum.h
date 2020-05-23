#ifndef SUBDICTUMFORM_H
#define SUBDICTUMFORM_H

#include "ui_subdictum.h"

#include <QtWidgets>

class SubDictumForm : public QDialog, public Ui::subDictumForm
{
    Q_OBJECT

public:
    explicit SubDictumForm(QString subDictumOption, int index, QList<QStringList> subDictums_Data,
                           QStringList dictumData, QList<QStringList> dictumReqsData, QDialog *parent = 0);

    QList<QStringList> requirementsData;

    QList<QCheckBox*> applyCheckBoxes;
    QList<QCheckBox*> meetsCheckBoxes;
    QList<QCheckBox*> noMeetsCheckBoxes;

    QList<QStringList> processesData;
    QList<QStringList> dictumsData;
    QList<QStringList> subDictumsData;
    QString dictumId, dictumNumber, processId, scope, observations, inspectionState;
    QString userName;
    int meetsClicks;
    int noMeetsClicks;
    int subDictumIndex;

private:
    void newSubDictum();
    void fillSubDictumData();
    void prepareSubDictumList(QString techState, QStringList reqIds, QStringList reqMeets, QStringList reqNoMeets);
    bool validateData(void);
    void styleWithData();
    void styleWithoutData();
    void updateSubDictum(QString techState, QStringList reqIds, QStringList reqMeets, QStringList reqNoMeets);

signals:

public slots:
    void processSubDictum();
    void setAllMeetsCheckboxes(int i);
    void setNoMeetsCheckboxes(int i);
    void setMeetsCheckboxes(int i);
    void updateSubDictumAction();
    void saveSubDictum();
};

#endif // SUBDICTUMFORM_H
