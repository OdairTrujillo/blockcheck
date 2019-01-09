#ifndef DICTUMFORM_H
#define DICTUMFORM_H

#include "ui_dictum.h"

#include <QtWidgets>

class DictumForm : public QDialog, public Ui::dictumForm
{
    Q_OBJECT

public:
    explicit DictumForm(QString dictumOption, QStringList dictum_Data, QStringList inspection_Data, QDialog *parent = nullptr);
    
    QDialog *filterUsesDialog;
    QStandardItemModel *filterUsesModel;
    QListView *filterListView;
    QSortFilterProxyModel *proxyModel;

    QList<QStringList> requirementsData;

    QList<QCheckBox*> applyCheckBoxes;
    QList<QCheckBox*> meetsCheckBoxes;
    QList<QCheckBox*> noMeetsCheckBoxes;

    QList<QStringList> processesData;
    QList<QStringList> usesData;
    QList<QStringList> subDictumsData;
    QList<QStringList> dictumReqsData;

    QStringList inspectionData;
    QStringList dictumData;
    QStringList extraData;

    QString freshDictumId;
    QString userName;
    int meetsClicks;
    int noMeetsClicks;
    int dictumIndex;

private:
    void newDictum(QString processName);
    void fillDictumData();
    void insertDictum(QString techState, QStringList reqIds, QStringList reqMeets, QStringList reqNoMeets);
    bool validateData(void);
    void styleWithData();
    void styleWithoutData();
    void updateDictum(QString techState, QStringList reqIds, QStringList reqMeets, QStringList reqNoMeets);

signals:

public slots:
    void processDictum();
    void setAllMeetsCheckboxes(int i);
    void setNoMeetsCheckboxes(int i);
    void setMeetsCheckboxes(int i);
    void getSubDictums();
    void updateDictumAction();
    void saveDictum();
    void newSubDictum();
    void goSubDictum();
    void previewDictum();
    void launchUsesFilter(QString);
    void changeFilterRegExp(QString);
    
};

#endif // DICTUMFORM_H
