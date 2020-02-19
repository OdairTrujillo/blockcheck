#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sales.h"
#include "login.h"
#include "checkfolder.h"
#include "accounting.h"
#include "engineering.h"
#include "logview.h"
#include "editpersons.h"
#include "dbhandler.h"
#include "sostate.h"
#include "bcconfs.h"
#include "userlib/logger.h"
#include "userlib/bcnamespace.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (!DbHandler::createConnection()) {
        qDebug() << "No se obtuvo acceso a la DB, revise que el servidor esté corriendo y aceptando conexiones.";
        exit(1); // Si no se obtiene acceso a la DB, el programa finaliza.
    } else {
    showMaximized();
    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
    hideItems();
    }
}

void MainWindow::login()
{
    LoginDialog loginDialog;

    // Pregunto si retorna aceptado para poder mostrar formulario de ventas
    // aceptado significa que existe el nombre de usuario y contrasena-
    if (loginDialog.exec()==QDialog::Accepted) {

        if (loginDialog.userData.at(3) == "Comercial") {
            salesMenu->menuAction()->setVisible(true);
        }
        if (loginDialog.userData.at(3) == "Documentos") {
            checkFolderMenu->menuAction()->setVisible(true);
        }

        if (loginDialog.userData.at(3) == "Contabilidad") {
            accountingMenu->menuAction()->setVisible(true);
        }

        if (loginDialog.userData.at(3) == "Ingeniería") {
            engineeringMenu->menuAction()->setVisible(true);
        }

        if (loginDialog.userData.at(3) == "Gerencia") {
            adminMenu->menuAction()->setVisible(true); // Muestra todo el menú
            adminToolBar->show();
        }

        userName = loginDialog.userData.at(0);
        userLName = loginDialog.userData.at(2);
        loginAct->setVisible(false); // Oculta solo la opción de login
        logoutAct->setVisible(true);

        statusLabel = new QLabel("Usuario Activo: " + userLName.toUtf8());
        statusBar()->addWidget(statusLabel);
    }
}

void MainWindow::logout()
{
    if (QMessageBox::question(this, "Cerrar sesión", "¿Desea cerrar sesión?",
                              QMessageBox::Yes | QMessageBox::Cancel)==QMessageBox::Yes) {
        hideItems();
        Logger::logout(userName, userLName);
        DbHandler::closeConnection();
    }

}

void MainWindow::showSalesForm()
{
    SalesForm salesForm;
    salesForm.userName=userName;
    salesForm.exec();
}

void MainWindow::showCheckFolderForm()
{
    CheckFolderForm checkFolderForm;
    checkFolderForm.userName=userName;
    checkFolderForm.exec();
}

void MainWindow::showAccountingForm()
{
    AccountingForm accountingForm;
    accountingForm.userName=userName;
    accountingForm.exec();
}

void MainWindow::showEngineeringForm()
{
    EngineeringForm engineeringForm;
    engineeringForm.userName=userName;
    engineeringForm.exec();
}

void MainWindow::showEventsForm()
{
    LogViewForm logViewForm(this);
    logViewForm.exec();
}

void MainWindow::showEditUsersForm()
{
    EditPersonsForm editPersonsForm(BcNames::EditUsers, this);
    editPersonsForm.userName=userName;
    editPersonsForm.exec();
}

void MainWindow::showEditInspectorsForm()
{
    EditPersonsForm editPersonsForm(BcNames::EditInspectors, this);
    editPersonsForm.userName=userName;
    editPersonsForm.exec();
}

void MainWindow::showEditDesignersForm()
{
    EditPersonsForm editPersonsForm(BcNames::EditDesigners, this);
    editPersonsForm.userName=userName;
    editPersonsForm.exec();
}

void MainWindow::showEditConstructorsForm()
{
    EditPersonsForm editPersonsForm(BcNames::EditConstructors, this);
    editPersonsForm.userName=userName;
    editPersonsForm.exec();
}


void MainWindow::showEditAuditorsForm()
{
    EditPersonsForm editPersonsForm(BcNames::EditAuditors, this);
    editPersonsForm.userName=userName;
    editPersonsForm.exec();
}

void MainWindow::showSoStateForm()
{
    SoStateForm soStateForm;
    soStateForm.exec();
}

void MainWindow::showBcConfsForm()
{
    BcConfsForm BcConfsForm(this);
    BcConfsForm.userName=userName;
    BcConfsForm.exec();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (QMessageBox::question(this, "Cerrar el programa", "¿Desea cerrar BlockCheck?",
                              QMessageBox::Yes | QMessageBox::Cancel)==QMessageBox::Yes) {

        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("Acerca de BlockCheck"),
                       "<b>BlockCheck</b> administración y gestión de "
                          "organismos de inspección RETIE - En desarrollo ");
}


void MainWindow::createActions()
{
    loginAct = new QAction(QIcon(":/icons/icons/login.png"), "&Iniciar Sesión", this);
    loginAct->setStatusTip("Iniciar Sesión");
    connect(loginAct, SIGNAL(triggered()), this, SLOT(login()));

    logoutAct = new QAction(QIcon(":/icons/icons/logout.png"), "&Cerrar Sesión", this);
    logoutAct->setStatusTip("Cerrar Sesión");
    connect(logoutAct, SIGNAL(triggered()), this, SLOT(logout()));

    showSalesAct = new QAction(QIcon(":/icons/icons/sales.png"), "&Ventas", this);
    showSalesAct->setStatusTip("Muestra el módulo de ventas");
    connect(showSalesAct, SIGNAL(triggered()), this, SLOT(showSalesForm()));

    showCheckFolderAct = new QAction(QIcon(":/icons/icons/store.png"), "&Documentos", this);
    showCheckFolderAct->setStatusTip("Muestra el módulo de documentos");
    connect(showCheckFolderAct, SIGNAL(triggered()), this, SLOT(showCheckFolderForm()));

    showAccountingAct = new QAction(QIcon(":/icons/icons/billed.png"), "&Contabilidad", this);
    showAccountingAct->setStatusTip("Muestra el módulo de Contabilidad");
    connect(showAccountingAct, SIGNAL(triggered()), this, SLOT(showAccountingForm()));

    showEngineeringAct = new QAction(QIcon(":/icons/icons/engineering.png"), "&Ingeniería", this);
    showEngineeringAct->setStatusTip("Muestra el módulo de Ingeniería");
    connect(showEngineeringAct, SIGNAL(triggered()), this, SLOT(showEngineeringForm()));

    showEventsAct = new QAction(QIcon(":/icons/icons/filter.png"), "&Eventos", this);
    showEventsAct->setStatusTip("Registro de Eventos");
    connect(showEventsAct, SIGNAL(triggered()), this, SLOT(showEventsForm()));

    showEditDesignersAct = new QAction("&Editar Diseñadores", this);
    showEditDesignersAct->setStatusTip("Edición de Diseñadores");
    connect(showEditDesignersAct, SIGNAL(triggered()), this, SLOT(showEditDesignersForm()));

    showEditConstructorsAct = new QAction("&Editar Constructores", this);
    showEditConstructorsAct->setStatusTip("Edición de Constructores");
    connect(showEditConstructorsAct, SIGNAL(triggered()), this, SLOT(showEditConstructorsForm()));

    showEditAuditorsAct = new QAction("&Editar Interventores", this);
    showEditAuditorsAct->setStatusTip("Edición de Interventores");
    connect(showEditAuditorsAct, SIGNAL(triggered()), this, SLOT(showEditAuditorsForm()));

    showEditInspectorsAct = new QAction("&Editar Inspectores", this);
    showEditInspectorsAct->setStatusTip("Edición de Inspectores");
    connect(showEditInspectorsAct, SIGNAL(triggered()), this, SLOT(showEditInspectorsForm()));

    showEditUsersAct = new QAction("&Editar Usuarios", this);
    showEditUsersAct->setStatusTip("Edición de Usuarios");
    connect(showEditUsersAct, SIGNAL(triggered()), this, SLOT(showEditUsersForm()));

    showSoStateAct = new QAction(QIcon(":/icons/icons/find.png"), "&Estado de Expediente", this);
    showSoStateAct->setStatusTip("Estado de Expediente");
    connect(showSoStateAct, SIGNAL(triggered()), this, SLOT(showSoStateForm()));

    exitAct = new QAction("&Salir", this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip("Salir de BlockCheck");
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    showBcConfsAct = new QAction(QIcon(":/icons/icons/configure.png"), "&Configurar BlockCheck", this);
    showBcConfsAct->setStatusTip("Accede las configuraciones del programa");
    connect(showBcConfsAct, SIGNAL(triggered()), this, SLOT(showBcConfsForm()));

    aboutAct = new QAction("&Acerca de ...", this);
    aboutAct->setStatusTip("Muestra el Acerca de BlockCheck");
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction("Acerca de &Qt", this);
    aboutQtAct->setStatusTip("Muestra el Acerca de Qt");
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

}

void MainWindow::createMenus()
{
    // Tanto las opciones de menú como las acciones de estas, son miembros de la clase
    // Aquí se agregan a la barra de menú que por defecto es parte del QMainWindow
    sessionMenu = menuBar()->addMenu("Sesión");
    sessionMenu->addAction(loginAct);
    sessionMenu->addAction(logoutAct);
    sessionMenu->addSeparator();
    sessionMenu->addAction(exitAct);

    salesMenu = menuBar()->addMenu("&Ventas");
    salesMenu->addAction(showSalesAct);

    checkFolderMenu = menuBar()->addMenu("&Documentos");
    checkFolderMenu->addAction(showCheckFolderAct);

    accountingMenu = menuBar()->addMenu("&Contabilidad");
    accountingMenu->addAction(showAccountingAct);

    engineeringMenu = menuBar()->addMenu("&Ingeniería");
    engineeringMenu->addAction(showEngineeringAct);

    // La función menuBar() evita tener que hacer adminMenu=new QMenu(menubar), ya que usa la barra de menú implícita
    adminMenu = menuBar()->addMenu("&Gerencia y Monitoreo");
    adminMenu->addAction(showEventsAct);
    // Para agregar el submenú, este debe ser hijo del menú y el padre debe agregar la acción del hijo con menuAction
    personsMenu = new QMenu("Editar &Personas", adminMenu);
    personsMenu->setIcon(QIcon(":/icons/icons/users.png"));
    // Aquí se agrega el menuAction del hijo al padre para que pueda ejecutarse como submenú dentro del menú.
    adminMenu->addAction(personsMenu->menuAction());
    // Finalmente se agregan las acciones del submenú.
    personsMenu->addAction(showEditUsersAct);
    personsMenu->addAction(showEditInspectorsAct);
    personsMenu->addAction(showEditDesignersAct);
    personsMenu->addAction(showEditConstructorsAct);
    personsMenu->addAction(showEditAuditorsAct);

    adminMenu->addAction(showSoStateAct);

    menuBar()->addSeparator();

    bcConfsMenu = menuBar()->addMenu("Configuración");
    bcConfsMenu->addAction(showBcConfsAct);

    helpMenu = menuBar()->addMenu(tr("&Ayuda"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void MainWindow::createToolBars()
{
    adminToolBar = addToolBar("Gerencia y Monitoreo");
    adminToolBar->addAction(showEventsAct);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage("Listo");
}

void MainWindow::hideItems()
{
    salesMenu->menuAction()->setVisible(false);
    checkFolderMenu->menuAction()->setVisible(false);
    accountingMenu->menuAction()->setVisible(false);
    engineeringMenu->menuAction()->setVisible(false);
    adminMenu->menuAction()->setVisible(false);
    adminToolBar->hide();
    logoutAct->setVisible(false);
    loginAct->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
