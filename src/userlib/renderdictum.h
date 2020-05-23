#ifndef RENDERDICTUM_H
#define RENDERDICTUM_H

#include "ui_renderdictum.h"

class RenderDictumForm : public QDialog, public Ui::renderDictumForm
{
    Q_OBJECT
    
public:
    RenderDictumForm(QStringList inspectionData, QStringList dictumData, QList<QStringList> dictumReqsData, QDialog *parent = 0);
    QString dictumNumber;

private:

public slots:
    void printDictum();

};

#endif // RENDERDICTUM_H
