/********************************************************************************
** Form generated from reading UI file 'renderdictum.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDERDICTUM_H
#define UI_RENDERDICTUM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <qwebengineview.h>

QT_BEGIN_NAMESPACE

class Ui_renderDictumForm
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *printDictumButton;
    QWebEngineView *webView;

    void setupUi(QDialog *renderDictumForm)
    {
        if (renderDictumForm->objectName().isEmpty())
            renderDictumForm->setObjectName(QString::fromUtf8("renderDictumForm"));
        renderDictumForm->resize(793, 601);
        gridLayout = new QGridLayout(renderDictumForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(renderDictumForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_9);

        printDictumButton = new QPushButton(frame);
        printDictumButton->setObjectName(QString::fromUtf8("printDictumButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        printDictumButton->setIcon(icon);

        horizontalLayout_17->addWidget(printDictumButton);


        gridLayout_2->addLayout(horizontalLayout_17, 1, 0, 1, 1);

        webView = new QWebEngineView(frame);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_2->addWidget(webView, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(renderDictumForm);

        QMetaObject::connectSlotsByName(renderDictumForm);
    } // setupUi

    void retranslateUi(QDialog *renderDictumForm)
    {
        renderDictumForm->setWindowTitle(QApplication::translate("renderDictumForm", "Dialog", nullptr));
        printDictumButton->setText(QApplication::translate("renderDictumForm", "Imprimir Dictamen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class renderDictumForm: public Ui_renderDictumForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERDICTUM_H
