/********************************************************************************
** Form generated from reading UI file 'filterserviceorders.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERSERVICEORDERS_H
#define UI_FILTERSERVICEORDERS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_filterServiceOrdersForm
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *filterBySoIdLineEdit;
    QLineEdit *filterByDateLineEdit;
    QLineEdit *filterByInstNameLineEdit;
    QLineEdit *filterByScopeLineEdit;
    QLineEdit *filterByNameLineEdit;
    QLineEdit *filterByValueLineEdit;
    QLineEdit *filterByAssignDateLineEdit;
    QLineEdit *filterByProcessedLineEdit;
    QLineEdit *filterByDocProcessedLineEdit;
    QLineEdit *filterByEngProcessedLineEdit;
    QTableView *serviceOrdersTableView;
    QSpacerItem *horizontalSpacer;
    QPushButton *goRecordButton;

    void setupUi(QDialog *filterServiceOrdersForm)
    {
        if (filterServiceOrdersForm->objectName().isEmpty())
            filterServiceOrdersForm->setObjectName(QString::fromUtf8("filterServiceOrdersForm"));
        filterServiceOrdersForm->setWindowModality(Qt::WindowModal);
        filterServiceOrdersForm->resize(1250, 502);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(filterServiceOrdersForm->sizePolicy().hasHeightForWidth());
        filterServiceOrdersForm->setSizePolicy(sizePolicy);
        filterServiceOrdersForm->setMinimumSize(QSize(1250, 502));
        filterServiceOrdersForm->setMaximumSize(QSize(1206, 502));
        gridLayout = new QGridLayout(filterServiceOrdersForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        filterBySoIdLineEdit = new QLineEdit(filterServiceOrdersForm);
        filterBySoIdLineEdit->setObjectName(QString::fromUtf8("filterBySoIdLineEdit"));
        sizePolicy.setHeightForWidth(filterBySoIdLineEdit->sizePolicy().hasHeightForWidth());
        filterBySoIdLineEdit->setSizePolicy(sizePolicy);
        filterBySoIdLineEdit->setMinimumSize(QSize(70, 24));
        filterBySoIdLineEdit->setMaximumSize(QSize(0, 16777215));
        QFont font;
        font.setPointSize(10);
        filterBySoIdLineEdit->setFont(font);

        horizontalLayout->addWidget(filterBySoIdLineEdit);

        filterByDateLineEdit = new QLineEdit(filterServiceOrdersForm);
        filterByDateLineEdit->setObjectName(QString::fromUtf8("filterByDateLineEdit"));
        sizePolicy.setHeightForWidth(filterByDateLineEdit->sizePolicy().hasHeightForWidth());
        filterByDateLineEdit->setSizePolicy(sizePolicy);
        filterByDateLineEdit->setMinimumSize(QSize(70, 24));
        filterByDateLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByDateLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByDateLineEdit);

        filterByInstNameLineEdit = new QLineEdit(filterServiceOrdersForm);
        filterByInstNameLineEdit->setObjectName(QString::fromUtf8("filterByInstNameLineEdit"));
        filterByInstNameLineEdit->setMinimumSize(QSize(180, 24));
        filterByInstNameLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByInstNameLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByInstNameLineEdit);

        filterByScopeLineEdit = new QLineEdit(filterServiceOrdersForm);
        filterByScopeLineEdit->setObjectName(QString::fromUtf8("filterByScopeLineEdit"));
        filterByScopeLineEdit->setMinimumSize(QSize(215, 24));
        filterByScopeLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByScopeLineEdit);

        filterByNameLineEdit = new QLineEdit(filterServiceOrdersForm);
        filterByNameLineEdit->setObjectName(QString::fromUtf8("filterByNameLineEdit"));
        filterByNameLineEdit->setMinimumSize(QSize(165, 24));
        filterByNameLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByNameLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByNameLineEdit);

        filterByValueLineEdit = new QLineEdit(filterServiceOrdersForm);
        filterByValueLineEdit->setObjectName(QString::fromUtf8("filterByValueLineEdit"));
        filterByValueLineEdit->setMinimumSize(QSize(110, 24));
        filterByValueLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByValueLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByValueLineEdit);

        filterByAssignDateLineEdit = new QLineEdit(filterServiceOrdersForm);
        filterByAssignDateLineEdit->setObjectName(QString::fromUtf8("filterByAssignDateLineEdit"));
        filterByAssignDateLineEdit->setMinimumSize(QSize(100, 24));
        filterByAssignDateLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByAssignDateLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByAssignDateLineEdit);

        filterByProcessedLineEdit = new QLineEdit(filterServiceOrdersForm);
        filterByProcessedLineEdit->setObjectName(QString::fromUtf8("filterByProcessedLineEdit"));
        filterByProcessedLineEdit->setMinimumSize(QSize(100, 24));
        filterByProcessedLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByProcessedLineEdit);

        filterByDocProcessedLineEdit = new QLineEdit(filterServiceOrdersForm);
        filterByDocProcessedLineEdit->setObjectName(QString::fromUtf8("filterByDocProcessedLineEdit"));
        filterByDocProcessedLineEdit->setMinimumSize(QSize(100, 24));
        filterByDocProcessedLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByDocProcessedLineEdit);

        filterByEngProcessedLineEdit = new QLineEdit(filterServiceOrdersForm);
        filterByEngProcessedLineEdit->setObjectName(QString::fromUtf8("filterByEngProcessedLineEdit"));
        filterByEngProcessedLineEdit->setMinimumSize(QSize(100, 24));
        filterByEngProcessedLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByEngProcessedLineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        serviceOrdersTableView = new QTableView(filterServiceOrdersForm);
        serviceOrdersTableView->setObjectName(QString::fromUtf8("serviceOrdersTableView"));
        serviceOrdersTableView->setFont(font);
        serviceOrdersTableView->setAlternatingRowColors(true);
        serviceOrdersTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        serviceOrdersTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        serviceOrdersTableView->setSortingEnabled(false);
        serviceOrdersTableView->setWordWrap(true);
        serviceOrdersTableView->horizontalHeader()->setDefaultSectionSize(100);
        serviceOrdersTableView->horizontalHeader()->setMinimumSectionSize(40);
        serviceOrdersTableView->horizontalHeader()->setStretchLastSection(false);
        serviceOrdersTableView->verticalHeader()->setVisible(false);

        gridLayout->addWidget(serviceOrdersTableView, 1, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(1065, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        goRecordButton = new QPushButton(filterServiceOrdersForm);
        goRecordButton->setObjectName(QString::fromUtf8("goRecordButton"));
        goRecordButton->setLayoutDirection(Qt::RightToLeft);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/go.png"), QSize(), QIcon::Normal, QIcon::Off);
        goRecordButton->setIcon(icon);

        gridLayout->addWidget(goRecordButton, 2, 1, 1, 1);


        retranslateUi(filterServiceOrdersForm);

        QMetaObject::connectSlotsByName(filterServiceOrdersForm);
    } // setupUi

    void retranslateUi(QDialog *filterServiceOrdersForm)
    {
        filterServiceOrdersForm->setWindowTitle(QApplication::translate("filterServiceOrdersForm", "Filtrar Orden de Servicio", nullptr));
        goRecordButton->setText(QApplication::translate("filterServiceOrdersForm", "Ir a OS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class filterServiceOrdersForm: public Ui_filterServiceOrdersForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERSERVICEORDERS_H
