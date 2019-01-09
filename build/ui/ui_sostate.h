/********************************************************************************
** Form generated from reading UI file 'sostate.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOSTATE_H
#define UI_SOSTATE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SoStateForm
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QTextEdit *scopeTextEdit;
    QLabel *label_4;
    QGridLayout *gridLayout;
    QCheckBox *propCheckBox;
    QDateEdit *receivedDateEdit;
    QCheckBox *docProccCheckBox;
    QLineEdit *docProccLineEdit;
    QDateEdit *propDateEdit;
    QCheckBox *soCheckBox;
    QLineEdit *soLineEdit;
    QLineEdit *propLineEdit;
    QLabel *label_5;
    QCheckBox *accProccCheckBox;
    QLineEdit *accProccLineEdit;
    QCheckBox *engProccCheckBox;
    QLineEdit *engProccLineEdit;
    QCheckBox *dictumsCheckBox;
    QCheckBox *inspectorCheckBox;
    QLineEdit *inspectorLineEdit;
    QLabel *label_7;
    QCheckBox *receivedCheckBox;
    QLabel *label_6;
    QDateEdit *soDateEdit;
    QDateEdit *assignDateEdit;
    QComboBox *dictumsComboBox;
    QCheckBox *shippedCheckBox;
    QDateEdit *shippedDateEdit;
    QCheckBox *engObservCheckBox;
    QLabel *label_8;
    QLineEdit *propTotValueLineEdit;
    QSpacerItem *horizontalSpacer;
    QTextEdit *admObservTextEdit;
    QPushButton *saveObservsButton;
    QPushButton *findButton;
    QLabel *label_2;
    QLineEdit *findLineEdit;
    QTextEdit *engObservTextEdit;
    QComboBox *findByComboBox;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *SoStateForm)
    {
        if (SoStateForm->objectName().isEmpty())
            SoStateForm->setObjectName(QString::fromUtf8("SoStateForm"));
        SoStateForm->resize(710, 548);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        SoStateForm->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(SoStateForm);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(SoStateForm);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);

        gridLayout_2->addWidget(label, 5, 0, 1, 1);

        scopeTextEdit = new QTextEdit(SoStateForm);
        scopeTextEdit->setObjectName(QString::fromUtf8("scopeTextEdit"));
        scopeTextEdit->setFont(font);
        scopeTextEdit->setTabChangesFocus(true);
        scopeTextEdit->setReadOnly(true);
        scopeTextEdit->setAcceptRichText(false);

        gridLayout_2->addWidget(scopeTextEdit, 2, 0, 1, 7);

        label_4 = new QLabel(SoStateForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setIndent(4);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        propCheckBox = new QCheckBox(SoStateForm);
        propCheckBox->setObjectName(QString::fromUtf8("propCheckBox"));
        propCheckBox->setFont(font);

        gridLayout->addWidget(propCheckBox, 0, 0, 1, 1);

        receivedDateEdit = new QDateEdit(SoStateForm);
        receivedDateEdit->setObjectName(QString::fromUtf8("receivedDateEdit"));
        receivedDateEdit->setMinimumSize(QSize(0, 24));
        QFont font1;
        font1.setPointSize(10);
        receivedDateEdit->setFont(font1);
        receivedDateEdit->setReadOnly(true);
        receivedDateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(receivedDateEdit, 3, 1, 1, 1);

        docProccCheckBox = new QCheckBox(SoStateForm);
        docProccCheckBox->setObjectName(QString::fromUtf8("docProccCheckBox"));
        docProccCheckBox->setFont(font);

        gridLayout->addWidget(docProccCheckBox, 3, 2, 1, 1);

        docProccLineEdit = new QLineEdit(SoStateForm);
        docProccLineEdit->setObjectName(QString::fromUtf8("docProccLineEdit"));
        docProccLineEdit->setMinimumSize(QSize(0, 25));
        docProccLineEdit->setFont(font1);
        docProccLineEdit->setReadOnly(true);

        gridLayout->addWidget(docProccLineEdit, 3, 3, 1, 1);

        propDateEdit = new QDateEdit(SoStateForm);
        propDateEdit->setObjectName(QString::fromUtf8("propDateEdit"));
        propDateEdit->setMinimumSize(QSize(0, 24));
        propDateEdit->setFont(font1);
        propDateEdit->setReadOnly(true);
        propDateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(propDateEdit, 0, 3, 1, 1);

        soCheckBox = new QCheckBox(SoStateForm);
        soCheckBox->setObjectName(QString::fromUtf8("soCheckBox"));
        soCheckBox->setFont(font);

        gridLayout->addWidget(soCheckBox, 1, 0, 1, 1);

        soLineEdit = new QLineEdit(SoStateForm);
        soLineEdit->setObjectName(QString::fromUtf8("soLineEdit"));
        soLineEdit->setMinimumSize(QSize(0, 25));
        soLineEdit->setFont(font1);
        soLineEdit->setReadOnly(true);

        gridLayout->addWidget(soLineEdit, 1, 1, 1, 1);

        propLineEdit = new QLineEdit(SoStateForm);
        propLineEdit->setObjectName(QString::fromUtf8("propLineEdit"));
        propLineEdit->setMinimumSize(QSize(0, 25));
        propLineEdit->setFont(font1);
        propLineEdit->setReadOnly(true);

        gridLayout->addWidget(propLineEdit, 0, 1, 1, 1);

        label_5 = new QLabel(SoStateForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setIndent(4);

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        accProccCheckBox = new QCheckBox(SoStateForm);
        accProccCheckBox->setObjectName(QString::fromUtf8("accProccCheckBox"));
        accProccCheckBox->setFont(font);

        gridLayout->addWidget(accProccCheckBox, 4, 0, 1, 1);

        accProccLineEdit = new QLineEdit(SoStateForm);
        accProccLineEdit->setObjectName(QString::fromUtf8("accProccLineEdit"));
        accProccLineEdit->setMinimumSize(QSize(0, 25));
        accProccLineEdit->setFont(font1);
        accProccLineEdit->setReadOnly(true);

        gridLayout->addWidget(accProccLineEdit, 4, 1, 1, 1);

        engProccCheckBox = new QCheckBox(SoStateForm);
        engProccCheckBox->setObjectName(QString::fromUtf8("engProccCheckBox"));
        engProccCheckBox->setFont(font);

        gridLayout->addWidget(engProccCheckBox, 4, 2, 1, 1);

        engProccLineEdit = new QLineEdit(SoStateForm);
        engProccLineEdit->setObjectName(QString::fromUtf8("engProccLineEdit"));
        engProccLineEdit->setMinimumSize(QSize(0, 25));
        engProccLineEdit->setFont(font1);
        engProccLineEdit->setReadOnly(true);

        gridLayout->addWidget(engProccLineEdit, 4, 3, 1, 1);

        dictumsCheckBox = new QCheckBox(SoStateForm);
        dictumsCheckBox->setObjectName(QString::fromUtf8("dictumsCheckBox"));
        dictumsCheckBox->setFont(font);

        gridLayout->addWidget(dictumsCheckBox, 5, 0, 1, 1);

        inspectorCheckBox = new QCheckBox(SoStateForm);
        inspectorCheckBox->setObjectName(QString::fromUtf8("inspectorCheckBox"));
        inspectorCheckBox->setFont(font);

        gridLayout->addWidget(inspectorCheckBox, 2, 0, 1, 1);

        inspectorLineEdit = new QLineEdit(SoStateForm);
        inspectorLineEdit->setObjectName(QString::fromUtf8("inspectorLineEdit"));
        inspectorLineEdit->setMinimumSize(QSize(0, 25));
        inspectorLineEdit->setFont(font1);
        inspectorLineEdit->setReadOnly(true);

        gridLayout->addWidget(inspectorLineEdit, 2, 1, 1, 1);

        label_7 = new QLabel(SoStateForm);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setIndent(4);

        gridLayout->addWidget(label_7, 2, 2, 1, 1);

        receivedCheckBox = new QCheckBox(SoStateForm);
        receivedCheckBox->setObjectName(QString::fromUtf8("receivedCheckBox"));
        receivedCheckBox->setFont(font);

        gridLayout->addWidget(receivedCheckBox, 3, 0, 1, 1);

        label_6 = new QLabel(SoStateForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setIndent(4);

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        soDateEdit = new QDateEdit(SoStateForm);
        soDateEdit->setObjectName(QString::fromUtf8("soDateEdit"));
        soDateEdit->setMinimumSize(QSize(0, 24));
        soDateEdit->setFont(font1);
        soDateEdit->setReadOnly(true);
        soDateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(soDateEdit, 1, 3, 1, 1);

        assignDateEdit = new QDateEdit(SoStateForm);
        assignDateEdit->setObjectName(QString::fromUtf8("assignDateEdit"));
        assignDateEdit->setMinimumSize(QSize(0, 24));
        assignDateEdit->setFont(font1);
        assignDateEdit->setReadOnly(true);
        assignDateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(assignDateEdit, 2, 3, 1, 1);

        dictumsComboBox = new QComboBox(SoStateForm);
        dictumsComboBox->setObjectName(QString::fromUtf8("dictumsComboBox"));
        dictumsComboBox->setMinimumSize(QSize(0, 24));
        dictumsComboBox->setFont(font1);

        gridLayout->addWidget(dictumsComboBox, 5, 1, 1, 1);

        shippedCheckBox = new QCheckBox(SoStateForm);
        shippedCheckBox->setObjectName(QString::fromUtf8("shippedCheckBox"));
        shippedCheckBox->setFont(font);

        gridLayout->addWidget(shippedCheckBox, 5, 2, 1, 1);

        shippedDateEdit = new QDateEdit(SoStateForm);
        shippedDateEdit->setObjectName(QString::fromUtf8("shippedDateEdit"));
        shippedDateEdit->setMinimumSize(QSize(0, 24));
        shippedDateEdit->setFont(font1);
        shippedDateEdit->setReadOnly(true);
        shippedDateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(shippedDateEdit, 5, 3, 1, 1);

        engObservCheckBox = new QCheckBox(SoStateForm);
        engObservCheckBox->setObjectName(QString::fromUtf8("engObservCheckBox"));
        engObservCheckBox->setFont(font);

        gridLayout->addWidget(engObservCheckBox, 6, 0, 1, 2);

        label_8 = new QLabel(SoStateForm);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setIndent(4);

        gridLayout->addWidget(label_8, 6, 2, 1, 1);

        propTotValueLineEdit = new QLineEdit(SoStateForm);
        propTotValueLineEdit->setObjectName(QString::fromUtf8("propTotValueLineEdit"));
        propTotValueLineEdit->setMinimumSize(QSize(0, 25));
        propTotValueLineEdit->setFont(font1);
        propTotValueLineEdit->setReadOnly(true);

        gridLayout->addWidget(propTotValueLineEdit, 6, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 3, 0, 1, 7);

        horizontalSpacer = new QSpacerItem(376, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 7, 0, 1, 3);

        admObservTextEdit = new QTextEdit(SoStateForm);
        admObservTextEdit->setObjectName(QString::fromUtf8("admObservTextEdit"));
        admObservTextEdit->setFont(font);
        admObservTextEdit->setTabChangesFocus(true);
        admObservTextEdit->setAcceptRichText(false);

        gridLayout_2->addWidget(admObservTextEdit, 6, 0, 1, 7);

        saveObservsButton = new QPushButton(SoStateForm);
        saveObservsButton->setObjectName(QString::fromUtf8("saveObservsButton"));
        saveObservsButton->setEnabled(true);
        saveObservsButton->setMinimumSize(QSize(0, 26));
        saveObservsButton->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveObservsButton->setIcon(icon1);

        gridLayout_2->addWidget(saveObservsButton, 7, 3, 1, 4);

        findButton = new QPushButton(SoStateForm);
        findButton->setObjectName(QString::fromUtf8("findButton"));
        findButton->setMinimumSize(QSize(30, 30));
        findButton->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/go.png"), QSize(), QIcon::Normal, QIcon::Off);
        findButton->setIcon(icon2);

        gridLayout_2->addWidget(findButton, 0, 4, 1, 1);

        label_2 = new QLabel(SoStateForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        findLineEdit = new QLineEdit(SoStateForm);
        findLineEdit->setObjectName(QString::fromUtf8("findLineEdit"));
        findLineEdit->setMinimumSize(QSize(130, 25));
        findLineEdit->setMaximumSize(QSize(100, 16777215));
        findLineEdit->setFont(font1);

        gridLayout_2->addWidget(findLineEdit, 0, 2, 1, 2);

        engObservTextEdit = new QTextEdit(SoStateForm);
        engObservTextEdit->setObjectName(QString::fromUtf8("engObservTextEdit"));
        engObservTextEdit->setFont(font);
        engObservTextEdit->setTabChangesFocus(true);
        engObservTextEdit->setReadOnly(true);
        engObservTextEdit->setAcceptRichText(false);

        gridLayout_2->addWidget(engObservTextEdit, 4, 0, 1, 7);

        findByComboBox = new QComboBox(SoStateForm);
        findByComboBox->addItem(QString());
        findByComboBox->addItem(QString());
        findByComboBox->setObjectName(QString::fromUtf8("findByComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(findByComboBox->sizePolicy().hasHeightForWidth());
        findByComboBox->setSizePolicy(sizePolicy);
        findByComboBox->setMinimumSize(QSize(0, 24));
        findByComboBox->setFont(font);

        gridLayout_2->addWidget(findByComboBox, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        QWidget::setTabOrder(findByComboBox, findLineEdit);
        QWidget::setTabOrder(findLineEdit, findButton);
        QWidget::setTabOrder(findButton, scopeTextEdit);
        QWidget::setTabOrder(scopeTextEdit, propCheckBox);
        QWidget::setTabOrder(propCheckBox, propLineEdit);
        QWidget::setTabOrder(propLineEdit, propDateEdit);
        QWidget::setTabOrder(propDateEdit, soCheckBox);
        QWidget::setTabOrder(soCheckBox, soLineEdit);
        QWidget::setTabOrder(soLineEdit, soDateEdit);
        QWidget::setTabOrder(soDateEdit, inspectorCheckBox);
        QWidget::setTabOrder(inspectorCheckBox, inspectorLineEdit);
        QWidget::setTabOrder(inspectorLineEdit, assignDateEdit);
        QWidget::setTabOrder(assignDateEdit, receivedCheckBox);
        QWidget::setTabOrder(receivedCheckBox, receivedDateEdit);
        QWidget::setTabOrder(receivedDateEdit, docProccCheckBox);
        QWidget::setTabOrder(docProccCheckBox, docProccLineEdit);
        QWidget::setTabOrder(docProccLineEdit, accProccCheckBox);
        QWidget::setTabOrder(accProccCheckBox, accProccLineEdit);
        QWidget::setTabOrder(accProccLineEdit, engProccCheckBox);
        QWidget::setTabOrder(engProccCheckBox, engProccLineEdit);
        QWidget::setTabOrder(engProccLineEdit, dictumsCheckBox);
        QWidget::setTabOrder(dictumsCheckBox, dictumsComboBox);
        QWidget::setTabOrder(dictumsComboBox, shippedCheckBox);
        QWidget::setTabOrder(shippedCheckBox, shippedDateEdit);
        QWidget::setTabOrder(shippedDateEdit, engObservCheckBox);
        QWidget::setTabOrder(engObservCheckBox, propTotValueLineEdit);
        QWidget::setTabOrder(propTotValueLineEdit, engObservTextEdit);
        QWidget::setTabOrder(engObservTextEdit, admObservTextEdit);
        QWidget::setTabOrder(admObservTextEdit, saveObservsButton);

        retranslateUi(SoStateForm);

        QMetaObject::connectSlotsByName(SoStateForm);
    } // setupUi

    void retranslateUi(QDialog *SoStateForm)
    {
        SoStateForm->setWindowTitle(QApplication::translate("SoStateForm", "Estado de Expediente", nullptr));
        label->setText(QApplication::translate("SoStateForm", "Observaciones", nullptr));
        label_4->setText(QApplication::translate("SoStateForm", "Alcances", nullptr));
        propCheckBox->setText(QApplication::translate("SoStateForm", "Propuesta N\302\272:", nullptr));
        receivedDateEdit->setDisplayFormat(QApplication::translate("SoStateForm", "d 'de' MMM 'de' yyyy", nullptr));
        docProccCheckBox->setText(QApplication::translate("SoStateForm", "Revisado:", nullptr));
        propDateEdit->setDisplayFormat(QApplication::translate("SoStateForm", "d 'de' MMM 'de' yyyy", nullptr));
        soCheckBox->setText(QApplication::translate("SoStateForm", "OS N\302\272:", nullptr));
        label_5->setText(QApplication::translate("SoStateForm", "Fecha de Propuesta:", nullptr));
        accProccCheckBox->setText(QApplication::translate("SoStateForm", "Facturado:", nullptr));
        engProccCheckBox->setText(QApplication::translate("SoStateForm", "Inspeccionado:", nullptr));
        dictumsCheckBox->setText(QApplication::translate("SoStateForm", "Con Dictamen", nullptr));
        inspectorCheckBox->setText(QApplication::translate("SoStateForm", "Asignado a:", nullptr));
        label_7->setText(QApplication::translate("SoStateForm", "Fecha de Asignaci\303\263n:", nullptr));
        receivedCheckBox->setText(QApplication::translate("SoStateForm", "Radicado el:", nullptr));
        label_6->setText(QApplication::translate("SoStateForm", "Fecha de OS:", nullptr));
        soDateEdit->setDisplayFormat(QApplication::translate("SoStateForm", "d 'de' MMM 'de' yyyy", nullptr));
        assignDateEdit->setDisplayFormat(QApplication::translate("SoStateForm", "d 'de' MMM 'de' yyyy", nullptr));
        shippedCheckBox->setText(QApplication::translate("SoStateForm", "Entregada:", nullptr));
        shippedDateEdit->setDisplayFormat(QApplication::translate("SoStateForm", "d 'de' MMM 'de' yyyy", nullptr));
        engObservCheckBox->setText(QApplication::translate("SoStateForm", "Observaciones de Ingenier\303\255a", nullptr));
        label_8->setText(QApplication::translate("SoStateForm", "Valor Total de la OS:", nullptr));
        saveObservsButton->setText(QApplication::translate("SoStateForm", "Guardar Observaciones", nullptr));
#ifndef QT_NO_TOOLTIP
        findButton->setToolTip(QApplication::translate("SoStateForm", "Ir", nullptr));
#endif // QT_NO_TOOLTIP
        findButton->setText(QString());
        label_2->setText(QApplication::translate("SoStateForm", "Localizar Expediente por: ", nullptr));
        findByComboBox->setItemText(0, QApplication::translate("SoStateForm", "Nit o C\303\251dula", nullptr));
        findByComboBox->setItemText(1, QApplication::translate("SoStateForm", "Orden de Servicio", nullptr));

    } // retranslateUi

};

namespace Ui {
    class SoStateForm: public Ui_SoStateForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOSTATE_H
