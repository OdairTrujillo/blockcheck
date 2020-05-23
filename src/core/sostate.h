#ifndef SOSTATEFORM_H
#define SOSTATEFORM_H

#include <QDialog>

namespace Ui {
class SoStateForm;
}

class SoStateForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit SoStateForm(QWidget *parent = 0);
    ~SoStateForm();

    void fillData();
    void clearControls();
    void enableControls();

    QString searchString;
    
private slots:
    void findServiceOrder(void);
    void saveObservartions(void);

private:
    Ui::SoStateForm *ui;
};

#endif // SOSTATEFORM_H
