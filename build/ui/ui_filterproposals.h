/********************************************************************************
** Form generated from reading UI file 'filterproposals.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERPROPOSALS_H
#define UI_FILTERPROPOSALS_H

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

class Ui_filterProposalsForm
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *filterByPropIdLineEdit;
    QLineEdit *filterByDateLineEdit;
    QLineEdit *filterByInstNameLineEdit;
    QLineEdit *filterByScopeLineEdit;
    QLineEdit *filterByNameLineEdit;
    QLineEdit *filterByValueLineEdit;
    QLineEdit *filterByStateLineEdit;
    QLineEdit *filterByUserLineEdit;
    QTableView *proposalsTableView;
    QSpacerItem *horizontalSpacer;
    QPushButton *goRecordButton;

    void setupUi(QDialog *filterProposalsForm)
    {
        if (filterProposalsForm->objectName().isEmpty())
            filterProposalsForm->setObjectName(QString::fromUtf8("filterProposalsForm"));
        filterProposalsForm->setWindowModality(Qt::WindowModal);
        filterProposalsForm->resize(1206, 502);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(filterProposalsForm->sizePolicy().hasHeightForWidth());
        filterProposalsForm->setSizePolicy(sizePolicy);
        filterProposalsForm->setMinimumSize(QSize(1206, 502));
        filterProposalsForm->setMaximumSize(QSize(1206, 502));
        gridLayout = new QGridLayout(filterProposalsForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        filterByPropIdLineEdit = new QLineEdit(filterProposalsForm);
        filterByPropIdLineEdit->setObjectName(QString::fromUtf8("filterByPropIdLineEdit"));
        sizePolicy.setHeightForWidth(filterByPropIdLineEdit->sizePolicy().hasHeightForWidth());
        filterByPropIdLineEdit->setSizePolicy(sizePolicy);
        filterByPropIdLineEdit->setMinimumSize(QSize(100, 24));
        filterByPropIdLineEdit->setMaximumSize(QSize(0, 16777215));
        QFont font;
        font.setPointSize(10);
        filterByPropIdLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByPropIdLineEdit);

        filterByDateLineEdit = new QLineEdit(filterProposalsForm);
        filterByDateLineEdit->setObjectName(QString::fromUtf8("filterByDateLineEdit"));
        sizePolicy.setHeightForWidth(filterByDateLineEdit->sizePolicy().hasHeightForWidth());
        filterByDateLineEdit->setSizePolicy(sizePolicy);
        filterByDateLineEdit->setMinimumSize(QSize(90, 24));
        filterByDateLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByDateLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByDateLineEdit);

        filterByInstNameLineEdit = new QLineEdit(filterProposalsForm);
        filterByInstNameLineEdit->setObjectName(QString::fromUtf8("filterByInstNameLineEdit"));
        filterByInstNameLineEdit->setMinimumSize(QSize(220, 24));
        filterByInstNameLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByInstNameLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByInstNameLineEdit);

        filterByScopeLineEdit = new QLineEdit(filterProposalsForm);
        filterByScopeLineEdit->setObjectName(QString::fromUtf8("filterByScopeLineEdit"));
        sizePolicy.setHeightForWidth(filterByScopeLineEdit->sizePolicy().hasHeightForWidth());
        filterByScopeLineEdit->setSizePolicy(sizePolicy);
        filterByScopeLineEdit->setMinimumSize(QSize(215, 24));
        filterByScopeLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByScopeLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByScopeLineEdit);

        filterByNameLineEdit = new QLineEdit(filterProposalsForm);
        filterByNameLineEdit->setObjectName(QString::fromUtf8("filterByNameLineEdit"));
        sizePolicy.setHeightForWidth(filterByNameLineEdit->sizePolicy().hasHeightForWidth());
        filterByNameLineEdit->setSizePolicy(sizePolicy);
        filterByNameLineEdit->setMinimumSize(QSize(150, 24));
        filterByNameLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByNameLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByNameLineEdit);

        filterByValueLineEdit = new QLineEdit(filterProposalsForm);
        filterByValueLineEdit->setObjectName(QString::fromUtf8("filterByValueLineEdit"));
        filterByValueLineEdit->setMinimumSize(QSize(110, 24));
        filterByValueLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByValueLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByValueLineEdit);

        filterByStateLineEdit = new QLineEdit(filterProposalsForm);
        filterByStateLineEdit->setObjectName(QString::fromUtf8("filterByStateLineEdit"));
        filterByStateLineEdit->setMinimumSize(QSize(100, 24));
        filterByStateLineEdit->setMaximumSize(QSize(0, 16777215));
        filterByStateLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByStateLineEdit);

        filterByUserLineEdit = new QLineEdit(filterProposalsForm);
        filterByUserLineEdit->setObjectName(QString::fromUtf8("filterByUserLineEdit"));
        filterByUserLineEdit->setMinimumSize(QSize(150, 24));
        filterByUserLineEdit->setFont(font);

        horizontalLayout->addWidget(filterByUserLineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        proposalsTableView = new QTableView(filterProposalsForm);
        proposalsTableView->setObjectName(QString::fromUtf8("proposalsTableView"));
        proposalsTableView->setFont(font);
        proposalsTableView->setAlternatingRowColors(true);
        proposalsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        proposalsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        proposalsTableView->setSortingEnabled(false);
        proposalsTableView->setWordWrap(true);
        proposalsTableView->horizontalHeader()->setDefaultSectionSize(100);
        proposalsTableView->horizontalHeader()->setMinimumSectionSize(40);
        proposalsTableView->horizontalHeader()->setStretchLastSection(false);
        proposalsTableView->verticalHeader()->setVisible(false);

        gridLayout->addWidget(proposalsTableView, 1, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(1065, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        goRecordButton = new QPushButton(filterProposalsForm);
        goRecordButton->setObjectName(QString::fromUtf8("goRecordButton"));
        goRecordButton->setLayoutDirection(Qt::RightToLeft);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/go.png"), QSize(), QIcon::Normal, QIcon::Off);
        goRecordButton->setIcon(icon);

        gridLayout->addWidget(goRecordButton, 2, 1, 1, 1);


        retranslateUi(filterProposalsForm);

        QMetaObject::connectSlotsByName(filterProposalsForm);
    } // setupUi

    void retranslateUi(QDialog *filterProposalsForm)
    {
        filterProposalsForm->setWindowTitle(QApplication::translate("filterProposalsForm", "Filtrar Propuesta", nullptr));
        goRecordButton->setText(QApplication::translate("filterProposalsForm", "Ir a Propuesta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class filterProposalsForm: public Ui_filterProposalsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERPROPOSALS_H
