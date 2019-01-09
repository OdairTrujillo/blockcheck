#ifndef BCCONFS_H
#define BCCONFS_H

#include <QDialog>
#include <QFile>

#include "ui_bcconfs.h"

namespace Ui {
class BcConfsForm;
}

class BcConfsForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit BcConfsForm(QWidget *parent = 0);
    ~BcConfsForm();

    QString userName;
    
private:
    Ui::BcConfsForm *ui;

private slots:
    void saveConfs(void);
};

#endif // BCCONFS_H
