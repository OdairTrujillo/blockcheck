/********************************************************************************
** Form generated from reading UI file 'filteraccountinginfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERACCOUNTINGINFO_H
#define UI_FILTERACCOUNTINGINFO_H

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

class Ui_filterAccountingInfoForm
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *filterBySoIdLineEdit;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *filterByMovTypeLineEdit;
    QLineEdit *filterByMovDocummentLineEdit;
    QLineEdit *filterByMovDateLineEdit;
    QLineEdit *filterByMovNameLineEdit;
    QLineEdit *filterByMovNitLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *filterByMovObservationsLineEdit;
    QTableView *accountingInfoTableView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *goRecordButton;

    void setupUi(QDialog *filterAccountingInfoForm)
    {
        if (filterAccountingInfoForm->objectName().isEmpty())
            filterAccountingInfoForm->setObjectName(QString::fromUtf8("filterAccountingInfoForm"));
        filterAccountingInfoForm->setWindowModality(Qt::WindowModal);
        filterAccountingInfoForm->resize(1180, 502);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(filterAccountingInfoForm->sizePolicy().hasHeightForWidth());
        filterAccountingInfoForm->setSizePolicy(sizePolicy);
        filterAccountingInfoForm->setMinimumSize(QSize(0, 0));
        filterAccountingInfoForm->setMaximumSize(QSize(1180, 502));
        gridLayout = new QGridLayout(filterAccountingInfoForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        filterBySoIdLineEdit = new QLineEdit(filterAccountingInfoForm);
        filterBySoIdLineEdit->setObjectName(QString::fromUtf8("filterBySoIdLineEdit"));
        sizePolicy.setHeightForWidth(filterBySoIdLineEdit->sizePolicy().hasHeightForWidth());
        filterBySoIdLineEdit->setSizePolicy(sizePolicy);
        filterBySoIdLineEdit->setMinimumSize(QSize(100, 24));
        filterBySoIdLineEdit->setMaximumSize(QSize(100, 16777215));
        QFont font;
        font.setPointSize(10);
        filterBySoIdLineEdit->setFont(font);

        horizontalLayout->addWidget(filterBySoIdLineEdit);

        horizontalSpacer_3 = new QSpacerItem(105, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        filterByMovTypeLineEdit = new QLineEdit(filterAccountingInfoForm);
        filterByMovTypeLineEdit->setObjectName(QString::fromUtf8("filterByMovTypeLineEdit"));
        sizePolicy.setHeightForWidth(filterByMovTypeLineEdit->sizePolicy().hasHeightForWidth());
        filterByMovTypeLineEdit->setSizePolicy(sizePolicy);
        filterByMovTypeLineEdit->setMinimumSize(QSize(100, 24));
        filterByMovTypeLineEdit->setMaximumSize(QSize(118, 16777215));
        filterByMovTypeLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByMovTypeLineEdit);

        filterByMovDocummentLineEdit = new QLineEdit(filterAccountingInfoForm);
        filterByMovDocummentLineEdit->setObjectName(QString::fromUtf8("filterByMovDocummentLineEdit"));
        filterByMovDocummentLineEdit->setMinimumSize(QSize(95, 24));
        filterByMovDocummentLineEdit->setMaximumSize(QSize(95, 16777215));
        filterByMovDocummentLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByMovDocummentLineEdit);

        filterByMovDateLineEdit = new QLineEdit(filterAccountingInfoForm);
        filterByMovDateLineEdit->setObjectName(QString::fromUtf8("filterByMovDateLineEdit"));
        filterByMovDateLineEdit->setMinimumSize(QSize(75, 24));
        filterByMovDateLineEdit->setMaximumSize(QSize(85, 16777215));

        horizontalLayout->addWidget(filterByMovDateLineEdit);

        filterByMovNameLineEdit = new QLineEdit(filterAccountingInfoForm);
        filterByMovNameLineEdit->setObjectName(QString::fromUtf8("filterByMovNameLineEdit"));
        filterByMovNameLineEdit->setMinimumSize(QSize(175, 24));
        filterByMovNameLineEdit->setMaximumSize(QSize(175, 16777215));

        horizontalLayout->addWidget(filterByMovNameLineEdit);

        filterByMovNitLineEdit = new QLineEdit(filterAccountingInfoForm);
        filterByMovNitLineEdit->setObjectName(QString::fromUtf8("filterByMovNitLineEdit"));
        filterByMovNitLineEdit->setMinimumSize(QSize(90, 24));
        filterByMovNitLineEdit->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(filterByMovNitLineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        filterByMovObservationsLineEdit = new QLineEdit(filterAccountingInfoForm);
        filterByMovObservationsLineEdit->setObjectName(QString::fromUtf8("filterByMovObservationsLineEdit"));
        filterByMovObservationsLineEdit->setMinimumSize(QSize(250, 24));
        filterByMovObservationsLineEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(filterByMovObservationsLineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        accountingInfoTableView = new QTableView(filterAccountingInfoForm);
        accountingInfoTableView->setObjectName(QString::fromUtf8("accountingInfoTableView"));
        accountingInfoTableView->setFont(font);
        accountingInfoTableView->setAlternatingRowColors(true);
        accountingInfoTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        accountingInfoTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        accountingInfoTableView->setSortingEnabled(false);
        accountingInfoTableView->setWordWrap(true);
        accountingInfoTableView->horizontalHeader()->setDefaultSectionSize(100);
        accountingInfoTableView->horizontalHeader()->setMinimumSectionSize(40);
        accountingInfoTableView->horizontalHeader()->setStretchLastSection(false);
        accountingInfoTableView->verticalHeader()->setVisible(false);

        gridLayout->addWidget(accountingInfoTableView, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        goRecordButton = new QPushButton(filterAccountingInfoForm);
        goRecordButton->setObjectName(QString::fromUtf8("goRecordButton"));
        goRecordButton->setLayoutDirection(Qt::RightToLeft);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/go.png"), QSize(), QIcon::Normal, QIcon::Off);
        goRecordButton->setIcon(icon);

        horizontalLayout_2->addWidget(goRecordButton);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(filterAccountingInfoForm);

        QMetaObject::connectSlotsByName(filterAccountingInfoForm);
    } // setupUi

    void retranslateUi(QDialog *filterAccountingInfoForm)
    {
        filterAccountingInfoForm->setWindowTitle(QApplication::translate("filterAccountingInfoForm", "Filtro Contable", nullptr));
        goRecordButton->setText(QApplication::translate("filterAccountingInfoForm", "Ir a OS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class filterAccountingInfoForm: public Ui_filterAccountingInfoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERACCOUNTINGINFO_H
