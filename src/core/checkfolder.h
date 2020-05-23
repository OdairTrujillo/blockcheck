#ifndef CHECKFOLDER_H
#define CHECKFOLDER_H

#include "ui_checkfolder.h"
#include <QtWidgets>

class CheckFolderForm : public QDialog, public Ui::checkFolderForm
{
    Q_OBJECT

public:
    CheckFolderForm(QWidget *parent = 0);

    QList<QStringList> sosData;
    QList<QStringList> sosData2; // Para revisar estado de documentos
    QList<QStringList> recordsData;
    QList<QCheckBox*> docsCheckBoxes;
    QList<QStringList> documentsData;
    QString userName;

private:
    void fillSoData(void);
    void clearSoControls(void);


private slots:
    void findServiceOrder(void);
    void updateServiceOrder(void);
    void listServiceOrders(void);
    void storeServiceOrder(void);
    void createFoil();
    void showSoTracking();
    void saveEngObservs();
    void checkDocsState(void);
};

#endif // CHECKFOLDER_H
