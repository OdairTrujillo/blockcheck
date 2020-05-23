/********************************************************************************
** Form generated from reading UI file 'logview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGVIEW_H
#define UI_LOGVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_LogViewForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDateTimeEdit *startDateTimeEdit;
    QDateTimeEdit *endDateTimeEdit;
    QComboBox *eventTypeComboBox;
    QComboBox *userComboBox;
    QComboBox *byIdComboBox;
    QLineEdit *idLineEdit;
    QTableView *logTableView;
    QSpacerItem *horizontalSpacer;
    QPushButton *filterButton;

    void setupUi(QDialog *LogViewForm)
    {
        if (LogViewForm->objectName().isEmpty())
            LogViewForm->setObjectName(QString::fromUtf8("LogViewForm"));
        LogViewForm->resize(1128, 545);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        LogViewForm->setWindowIcon(icon);
        gridLayout = new QGridLayout(LogViewForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(LogViewForm);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        label->setIndent(4);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(LogViewForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setIndent(4);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(LogViewForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setIndent(4);

        gridLayout->addWidget(label_3, 0, 2, 2, 1);

        label_4 = new QLabel(LogViewForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setIndent(4);

        gridLayout->addWidget(label_4, 0, 3, 2, 1);

        label_5 = new QLabel(LogViewForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setIndent(4);

        gridLayout->addWidget(label_5, 0, 4, 2, 2);

        label_6 = new QLabel(LogViewForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setIndent(4);
        label_6->setOpenExternalLinks(false);

        gridLayout->addWidget(label_6, 0, 6, 2, 1);

        startDateTimeEdit = new QDateTimeEdit(LogViewForm);
        startDateTimeEdit->setObjectName(QString::fromUtf8("startDateTimeEdit"));
        startDateTimeEdit->setMinimumSize(QSize(210, 24));
        startDateTimeEdit->setFont(font);
        startDateTimeEdit->setCalendarPopup(true);

        gridLayout->addWidget(startDateTimeEdit, 1, 0, 2, 1);

        endDateTimeEdit = new QDateTimeEdit(LogViewForm);
        endDateTimeEdit->setObjectName(QString::fromUtf8("endDateTimeEdit"));
        endDateTimeEdit->setMinimumSize(QSize(210, 24));
        endDateTimeEdit->setFont(font);
        endDateTimeEdit->setCalendarPopup(true);

        gridLayout->addWidget(endDateTimeEdit, 1, 1, 2, 1);

        eventTypeComboBox = new QComboBox(LogViewForm);
        eventTypeComboBox->setObjectName(QString::fromUtf8("eventTypeComboBox"));
        eventTypeComboBox->setMinimumSize(QSize(230, 24));
        eventTypeComboBox->setFont(font);
        eventTypeComboBox->setEditable(true);

        gridLayout->addWidget(eventTypeComboBox, 2, 2, 1, 1);

        userComboBox = new QComboBox(LogViewForm);
        userComboBox->setObjectName(QString::fromUtf8("userComboBox"));
        userComboBox->setMinimumSize(QSize(200, 24));
        userComboBox->setFont(font);
        userComboBox->setEditable(false);

        gridLayout->addWidget(userComboBox, 2, 3, 1, 1);

        byIdComboBox = new QComboBox(LogViewForm);
        byIdComboBox->setObjectName(QString::fromUtf8("byIdComboBox"));
        byIdComboBox->setMinimumSize(QSize(150, 24));
        byIdComboBox->setFont(font);

        gridLayout->addWidget(byIdComboBox, 2, 4, 1, 2);

        idLineEdit = new QLineEdit(LogViewForm);
        idLineEdit->setObjectName(QString::fromUtf8("idLineEdit"));
        idLineEdit->setMinimumSize(QSize(100, 24));
        idLineEdit->setFont(font);

        gridLayout->addWidget(idLineEdit, 2, 6, 1, 1);

        logTableView = new QTableView(LogViewForm);
        logTableView->setObjectName(QString::fromUtf8("logTableView"));

        gridLayout->addWidget(logTableView, 3, 0, 1, 7);

        horizontalSpacer = new QSpacerItem(864, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 5);

        filterButton = new QPushButton(LogViewForm);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        filterButton->setMinimumSize(QSize(0, 24));
        filterButton->setFont(font);
        filterButton->setLayoutDirection(Qt::RightToLeft);
        filterButton->setIcon(icon);

        gridLayout->addWidget(filterButton, 4, 5, 1, 2);


        retranslateUi(LogViewForm);

        QMetaObject::connectSlotsByName(LogViewForm);
    } // setupUi

    void retranslateUi(QDialog *LogViewForm)
    {
        LogViewForm->setWindowTitle(QApplication::translate("LogViewForm", "Registro de Eventos", nullptr));
        label->setText(QApplication::translate("LogViewForm", "Desde", nullptr));
        label_2->setText(QApplication::translate("LogViewForm", "Hasta", nullptr));
        label_3->setText(QApplication::translate("LogViewForm", "Tipo de Evento", nullptr));
        label_4->setText(QApplication::translate("LogViewForm", "Usuario", nullptr));
        label_5->setText(QApplication::translate("LogViewForm", "Por ID", nullptr));
        label_6->setText(QApplication::translate("LogViewForm", "ID", nullptr));
        startDateTimeEdit->setDisplayFormat(QApplication::translate("LogViewForm", "d 'de' MMM 'de' yyyy h:mm AP", nullptr));
        endDateTimeEdit->setDisplayFormat(QApplication::translate("LogViewForm", "d 'de' MMM 'de' yyyy h:mm AP", nullptr));
        filterButton->setText(QApplication::translate("LogViewForm", "Filtrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogViewForm: public Ui_LogViewForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGVIEW_H
