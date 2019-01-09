#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

class QAction;
class QMenu;
class QPlainTextEdit;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString userName;
    QString userLName;
    QLabel *statusLabel;

protected:
    void closeEvent(QCloseEvent *event);

private slots:

    void about();
    void login();
    void logout();
    void showSalesForm();
    void showCheckFolderForm();
    void showAccountingForm();
    void showEngineeringForm();
    void showEditDesignersForm();
    void showEditConstructorsForm();
    void showEditAuditorsForm();
    void showEditInspectorsForm();
    void showEditUsersForm();
    void showEventsForm();
    void showSoStateForm();
    void showBcConfsForm();

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void hideItems();

    QMenu *sessionMenu;
    QMenu *salesMenu;
    QMenu *checkFolderMenu;
    QMenu *accountingMenu;
    QMenu *engineeringMenu;
    QMenu *adminMenu;
    QMenu *personsMenu;
    QMenu *bcConfsMenu;
    QMenu *helpMenu;

    QToolBar *adminToolBar;

    QAction *loginAct;
    QAction *logoutAct;
    QAction *showSalesAct;
    QAction *showCheckFolderAct;
    QAction *showAccountingAct;
    QAction *showEngineeringAct;
    QAction *showEventsAct;
    QAction *showEditDesignersAct;
    QAction *showEditConstructorsAct;
    QAction *showEditAuditorsAct;
    QAction *showEditInspectorsAct;
    QAction *showEditUsersAct;
    QAction *showSoStateAct;
    QAction *showBcConfsAct;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
