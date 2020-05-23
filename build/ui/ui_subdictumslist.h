/********************************************************************************
** Form generated from reading UI file 'subdictumslist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBDICTUMSLIST_H
#define UI_SUBDICTUMSLIST_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_subDictumsListForm
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QPushButton *processSubDictumsButton;

    void setupUi(QDialog *subDictumsListForm)
    {
        if (subDictumsListForm->objectName().isEmpty())
            subDictumsListForm->setObjectName(QString::fromUtf8("subDictumsListForm"));
        subDictumsListForm->resize(686, 424);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/engineering.png"), QSize(), QIcon::Normal, QIcon::Off);
        subDictumsListForm->setWindowIcon(icon);
        gridLayout = new QGridLayout(subDictumsListForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(subDictumsListForm);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);

        processSubDictumsButton = new QPushButton(subDictumsListForm);
        processSubDictumsButton->setObjectName(QString::fromUtf8("processSubDictumsButton"));
        processSubDictumsButton->setMinimumSize(QSize(0, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/process.png"), QSize(), QIcon::Normal, QIcon::Off);
        processSubDictumsButton->setIcon(icon1);

        gridLayout->addWidget(processSubDictumsButton, 1, 0, 1, 1);


        retranslateUi(subDictumsListForm);

        QMetaObject::connectSlotsByName(subDictumsListForm);
    } // setupUi

    void retranslateUi(QDialog *subDictumsListForm)
    {
        subDictumsListForm->setWindowTitle(QApplication::translate("subDictumsListForm", "Listado de Consecutivos", nullptr));
        processSubDictumsButton->setText(QApplication::translate("subDictumsListForm", "Procesar Consecutivos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class subDictumsListForm: public Ui_subDictumsListForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBDICTUMSLIST_H
