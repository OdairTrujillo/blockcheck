#ifndef FILESOMETHING_H
#define FILESOMETHING_H

#include <QDialog>
#include "ui_filesomething.h"


class FileSomething : public QDialog
{
    Q_OBJECT

public:
    explicit FileSomething(QWidget *parent = 0);
    ~FileSomething();

    QList<QStringList> sosData;
    QList<QStringList> recordsData;



private:
    Ui::fileSomethingDialog *ui;
};

#endif // FILESOMETHING_H
