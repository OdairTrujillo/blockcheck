/********************************************************************************
** Form generated from reading UI file 'filterquotations.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERQUOTATIONS_H
#define UI_FILTERQUOTATIONS_H

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

class Ui_filterQuotationsForm
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *filterByDateLineEdit;
    QLineEdit *filterByInstNameLineEdit;
    QLineEdit *filterByScopeLineEdit;
    QLineEdit *filterByNameLineEdit;
    QLineEdit *filterByNitLineEdit;
    QLineEdit *filterByCelLineEdit;
    QLineEdit *filterByPhoneLineEdit;
    QLineEdit *filterByStateLineEdit;
    QLineEdit *filterByCityLineEdit;
    QLineEdit *filterByInstTypeLineEdit;
    QTableView *quotationsTableView;
    QSpacerItem *horizontalSpacer;
    QPushButton *goRecordButton;

    void setupUi(QDialog *filterQuotationsForm)
    {
        if (filterQuotationsForm->objectName().isEmpty())
            filterQuotationsForm->setObjectName(QString::fromUtf8("filterQuotationsForm"));
        filterQuotationsForm->setWindowModality(Qt::WindowModal);
        filterQuotationsForm->resize(1230, 502);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(filterQuotationsForm->sizePolicy().hasHeightForWidth());
        filterQuotationsForm->setSizePolicy(sizePolicy);
        filterQuotationsForm->setMinimumSize(QSize(1230, 502));
        filterQuotationsForm->setMaximumSize(QSize(1206, 502));
        gridLayout = new QGridLayout(filterQuotationsForm);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        filterByDateLineEdit = new QLineEdit(filterQuotationsForm);
        filterByDateLineEdit->setObjectName(QString::fromUtf8("filterByDateLineEdit"));
        sizePolicy.setHeightForWidth(filterByDateLineEdit->sizePolicy().hasHeightForWidth());
        filterByDateLineEdit->setSizePolicy(sizePolicy);
        filterByDateLineEdit->setMinimumSize(QSize(90, 24));
        filterByDateLineEdit->setMaximumSize(QSize(0, 16777215));
        QFont font;
        font.setPointSize(10);
        filterByDateLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByDateLineEdit);

        filterByInstNameLineEdit = new QLineEdit(filterQuotationsForm);
        filterByInstNameLineEdit->setObjectName(QString::fromUtf8("filterByInstNameLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(filterByInstNameLineEdit->sizePolicy().hasHeightForWidth());
        filterByInstNameLineEdit->setSizePolicy(sizePolicy1);
        filterByInstNameLineEdit->setMinimumSize(QSize(160, 24));
        filterByInstNameLineEdit->setMaximumSize(QSize(16777215, 16777215));
        filterByInstNameLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByInstNameLineEdit);

        filterByScopeLineEdit = new QLineEdit(filterQuotationsForm);
        filterByScopeLineEdit->setObjectName(QString::fromUtf8("filterByScopeLineEdit"));
        sizePolicy.setHeightForWidth(filterByScopeLineEdit->sizePolicy().hasHeightForWidth());
        filterByScopeLineEdit->setSizePolicy(sizePolicy);
        filterByScopeLineEdit->setMinimumSize(QSize(200, 24));
        filterByScopeLineEdit->setMaximumSize(QSize(16777215, 16777215));
        filterByScopeLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByScopeLineEdit);

        filterByNameLineEdit = new QLineEdit(filterQuotationsForm);
        filterByNameLineEdit->setObjectName(QString::fromUtf8("filterByNameLineEdit"));
        sizePolicy.setHeightForWidth(filterByNameLineEdit->sizePolicy().hasHeightForWidth());
        filterByNameLineEdit->setSizePolicy(sizePolicy);
        filterByNameLineEdit->setMinimumSize(QSize(150, 24));
        filterByNameLineEdit->setMaximumSize(QSize(16777215, 16777215));
        filterByNameLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByNameLineEdit);

        filterByNitLineEdit = new QLineEdit(filterQuotationsForm);
        filterByNitLineEdit->setObjectName(QString::fromUtf8("filterByNitLineEdit"));
        sizePolicy.setHeightForWidth(filterByNitLineEdit->sizePolicy().hasHeightForWidth());
        filterByNitLineEdit->setSizePolicy(sizePolicy);
        filterByNitLineEdit->setMinimumSize(QSize(100, 24));
        filterByNitLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByNitLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByNitLineEdit);

        filterByCelLineEdit = new QLineEdit(filterQuotationsForm);
        filterByCelLineEdit->setObjectName(QString::fromUtf8("filterByCelLineEdit"));
        sizePolicy.setHeightForWidth(filterByCelLineEdit->sizePolicy().hasHeightForWidth());
        filterByCelLineEdit->setSizePolicy(sizePolicy);
        filterByCelLineEdit->setMinimumSize(QSize(100, 24));
        filterByCelLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByCelLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByCelLineEdit);

        filterByPhoneLineEdit = new QLineEdit(filterQuotationsForm);
        filterByPhoneLineEdit->setObjectName(QString::fromUtf8("filterByPhoneLineEdit"));
        sizePolicy.setHeightForWidth(filterByPhoneLineEdit->sizePolicy().hasHeightForWidth());
        filterByPhoneLineEdit->setSizePolicy(sizePolicy);
        filterByPhoneLineEdit->setMinimumSize(QSize(100, 24));
        filterByPhoneLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByPhoneLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByPhoneLineEdit);

        filterByStateLineEdit = new QLineEdit(filterQuotationsForm);
        filterByStateLineEdit->setObjectName(QString::fromUtf8("filterByStateLineEdit"));
        sizePolicy.setHeightForWidth(filterByStateLineEdit->sizePolicy().hasHeightForWidth());
        filterByStateLineEdit->setSizePolicy(sizePolicy);
        filterByStateLineEdit->setMinimumSize(QSize(100, 24));
        filterByStateLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByStateLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByStateLineEdit);

        filterByCityLineEdit = new QLineEdit(filterQuotationsForm);
        filterByCityLineEdit->setObjectName(QString::fromUtf8("filterByCityLineEdit"));
        filterByCityLineEdit->setMinimumSize(QSize(100, 24));
        filterByCityLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByCityLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByCityLineEdit);

        filterByInstTypeLineEdit = new QLineEdit(filterQuotationsForm);
        filterByInstTypeLineEdit->setObjectName(QString::fromUtf8("filterByInstTypeLineEdit"));
        filterByInstTypeLineEdit->setMinimumSize(QSize(90, 24));
        filterByInstTypeLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByInstTypeLineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        quotationsTableView = new QTableView(filterQuotationsForm);
        quotationsTableView->setObjectName(QString::fromUtf8("quotationsTableView"));
        quotationsTableView->setFont(font);
        quotationsTableView->setAlternatingRowColors(true);
        quotationsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        quotationsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        quotationsTableView->setSortingEnabled(false);
        quotationsTableView->setWordWrap(true);
        quotationsTableView->horizontalHeader()->setDefaultSectionSize(100);
        quotationsTableView->horizontalHeader()->setMinimumSectionSize(40);
        quotationsTableView->horizontalHeader()->setStretchLastSection(false);
        quotationsTableView->verticalHeader()->setVisible(false);

        gridLayout->addWidget(quotationsTableView, 1, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(1065, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        goRecordButton = new QPushButton(filterQuotationsForm);
        goRecordButton->setObjectName(QString::fromUtf8("goRecordButton"));
        goRecordButton->setLayoutDirection(Qt::RightToLeft);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/go.png"), QSize(), QIcon::Normal, QIcon::Off);
        goRecordButton->setIcon(icon);

        gridLayout->addWidget(goRecordButton, 2, 1, 1, 1);


        retranslateUi(filterQuotationsForm);

        QMetaObject::connectSlotsByName(filterQuotationsForm);
    } // setupUi

    void retranslateUi(QDialog *filterQuotationsForm)
    {
        filterQuotationsForm->setWindowTitle(QApplication::translate("filterQuotationsForm", "Filtrar Cotizaci\303\263n", nullptr));
        filterByInstNameLineEdit->setInputMask(QString());
        goRecordButton->setText(QApplication::translate("filterQuotationsForm", "Ir a Cotizaci\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class filterQuotationsForm: public Ui_filterQuotationsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERQUOTATIONS_H
