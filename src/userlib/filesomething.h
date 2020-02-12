#ifndef FILESOMETHINGFORM_H
#define FILESOMETHINGFORM_H

#include <QDialog>

namespace Ui {
class fileSomethingForm;
}

class FileSomethingForm : public QDialog
{
    Q_OBJECT

public:
    explicit FileSomethingForm(QWidget *parent = 0);
    ~FileSomethingForm();

    QList<QStringList> sosData;
    QList<QStringList> recordsData;



private:
    Ui::fileSomethingForm *ui;
};

#endif // FILESOMETHINGFORM_H
