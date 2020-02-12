
#include <QtWidgets>
#include <QWebEngineView>
#include <QUrl>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

#include "sales.h"
#include "salesutils.h"
#include "dbhandler.h"
#include "userlib/logger.h"


SalesForm::SalesForm(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    // Centrar el widget en la mitad del escritorio
    //move(QApplication::desktop()->screen()->rect().center() - rect().center());

    // Preparar controles
    fillQuotControls();
    fillPropControls();
    fillSoControls();
    setValidators();

    // Crear señales y slots
    connect(findButton, SIGNAL(clicked()),
            this, SLOT(findSomething()));

    connect(nextButton, SIGNAL(clicked()),
            this, SLOT(findNext()));

    connect(prevButton, SIGNAL(clicked()),
            this, SLOT(findPrevious()));

    connect(quotStateComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(setQuotCity(int)));

    connect(thrdStateComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(setThrdCity(int)));

    connect(newButton, SIGNAL(clicked()),
            this, SLOT(newSomething()));

    connect(quotGenButton, SIGNAL(clicked()),
            this, SLOT(genQuotation()));

    connect(propGenButton, SIGNAL(clicked()),
            this, SLOT(genProposal()));

    connect(soGenButton, SIGNAL(clicked()),
            this, SLOT(genServiceOrder()));

    connect(updateButton, SIGNAL(clicked()),
            this, SLOT(updateSomething()));

    connect(deleteButton, SIGNAL(clicked()),
            this, SLOT(deleteSomething()));

   // connect(propPreviewButton, SIGNAL(clicked()),
           // this, SLOT(renderProposal()));

    //connect(soPreviewButton, SIGNAL(clicked()),
           // this, SLOT(renderServiceOrder()));

    connect(propPrintButton, SIGNAL(clicked()),
            this, SLOT(printProposal()));

    connect(soPrintButton, SIGNAL(clicked()),
            this, SLOT(printServiceOrder()));

    connect(listButton, SIGNAL(clicked()),
            this, SLOT(listSomething()));

    connect(propApprovButton, SIGNAL(clicked()),
            this, SLOT(approvProposal()));

    connect(spinBoxDelegate, SIGNAL(commitData(QWidget*)),
            this, SLOT(propTotalSum(void)));


    QShortcut *ShortcutQuotation = new QShortcut(QKeySequence(tr("Ctrl+Q+T")), this);
    QShortcut *ShortcutProposal = new QShortcut(QKeySequence(tr("Ctrl+P+R")), this);

    connect(ShortcutQuotation,SIGNAL(activated()),
            this, SLOT(testQuotation()));

    connect(ShortcutProposal,SIGNAL(activated()),
            this, SLOT(testProposal()));

    //    QTabBar *tabBar = salesTabWidget->findChild<QTabBar *>(QLatin1String("qt_tabwidget_tabbar"));
    //    tabBar->installEventFilter(this);

}


//bool SalesForm::eventFilter(QObject *object, QEvent *event)
//{

//    if (object == salesTabWidget->findChild<QTabBar *>(QLatin1String("qt_tabwidget_tabbar")) && event->type() == QEvent::MouseButtonPress) {
//        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
//        if (mouseEvent->button() == Qt::LeftButton) {
//            qDebug() << "Se disparo el evento";
//            return true;
//        } else
//            return false;
//    }
//    return false;
//}


// NOTE: Encuentra algo
void SalesForm::findSomething(void)
{
    if (findLineEdit->text() != "") {
        quot_position=0; //Cada busqueda inicia en la posicion 0
        prop_position=0;
        so_position=0;
        switch (findComboBox->currentIndex()) {
        case 0:
            // Nit o CC
            switch (findByNit(findLineEdit->text())) {
            case 0: // No encontro datos o ocurrio un error
                QMessageBox::critical(this, trUtf8("Sin Datos"),
                                      trUtf8("No se encontraron cotizaciones con: \n" +
                                      findLineEdit->text().toUtf8()),
                                      QMessageBox::Cancel);
                quotsData.append(QStringList(""));
                break;

            case 1: // Solo encontro cotizacion
                fillQuotData();
                clearPropControls();
                clearSoControls();
                quotGenButton->setEnabled(false);
                updateButton->setEnabled(true);
                deleteButton->setEnabled(true);
                salesTabWidget->setCurrentIndex(0);
                break;

            case 2: // Se econtró cotización y propuesta
                fillQuotData();
                fillPropData();
                clearSoControls();
                quotGenButton->setEnabled(false);
                propGenButton->setEnabled(false);
                updateButton->setEnabled(true);
                deleteButton->setEnabled(true);
                propApprovButton->setEnabled(true);
                salesTabWidget->setCurrentIndex(0);
                break;

            case 3: // Se econtró cotización, propuesta y orden de servicio
                fillQuotData();
                fillPropData();
                fillSoData();
                quotGenButton->setEnabled(false);
                propGenButton->setEnabled(false);
                soGenButton->setEnabled(false);
                updateButton->setEnabled(true);
                deleteButton->setEnabled(true);
                propApprovButton->setEnabled(false);
                salesTabWidget->setCurrentIndex(0);
                break;

            }

            foundLCD->display(quotsData.at(0).size());
            prevButton->setEnabled(false);

            if (quotsData.at(0).size()==1)
                nextButton->setEnabled(false);
            else
                nextButton->setEnabled(true);
            quotLCD->display(quot_position+1);
            break;

        case 1:
            // Id Propuesta
            switch (findByPropId(findLineEdit->text())) {
            case 0:
                QMessageBox::critical(this, trUtf8("Sin Datos"),
                                      trUtf8("No se encontró propuesta con: \n" +
                                      findLineEdit->text().toUtf8()),
                                      QMessageBox::Cancel);
                break;
                // No tiene case 1 porque nunca devuelve 1
            case 2: // Se encontró cotización y propueta
                fillQuotData();
                fillPropData();
                clearSoControls();
                quotGenButton->setEnabled(false);
                propGenButton->setEnabled(false);
                updateButton->setEnabled(true);
                deleteButton->setEnabled(true);
                propApprovButton->setEnabled(true);
                salesTabWidget->setCurrentIndex(1);
                quotLCD->display(1);
                break;

            case 3: // Se encontró cotización, propuesta y orden de servicio.
                fillQuotData();
                fillPropData();
                fillSoData();
                quotGenButton->setEnabled(false);
                propGenButton->setEnabled(false);
                soGenButton->setEnabled(false);
                updateButton->setEnabled(true);
                deleteButton->setEnabled(true);
                propApprovButton->setEnabled(false);
                salesTabWidget->setCurrentIndex(1);
                quotLCD->display(1);
                break;

            }
            prevButton->setEnabled(false);
            nextButton->setEnabled(false);
            break;
        case 2:
            // Id Orden de servicio
            switch (findBySoId(findLineEdit->text())) {
            case 0:
                QMessageBox::critical(this, trUtf8("Sin Datos"),
                                      trUtf8("No se encontró Orden de Servicio con: \n" +
                                      findLineEdit->text().toUtf8()),
                                      QMessageBox::Cancel);
                break;
                // No tiene case 1 y 2 porque nunca devuelve esos valores
            case 3: // Se encontró cotización, propuesta y orden de servicio.
                fillQuotData();
                fillPropData();
                fillSoData();
                quotGenButton->setEnabled(false);
                propGenButton->setEnabled(false);
                soGenButton->setEnabled(false);
                updateButton->setEnabled(true);
                deleteButton->setEnabled(true);
                propApprovButton->setEnabled(false);
                salesTabWidget->setCurrentIndex(2);
                quotLCD->display(1);
                break;
            }
            prevButton->setEnabled(false);
            nextButton->setEnabled(false);
            break;

        }


    } else {
        QMessageBox::warning(this, trUtf8("Faltan Datos"),
                             trUtf8("Debe introducir texto de búsqueda"),
                             QMessageBox::Cancel);
        findLineEdit->setFocus();
    }

}


// NOTA: Nuevo algo
void SalesForm::newSomething()
{
    switch (salesTabWidget->currentIndex()) {
    case 0: // Nueva cotización
        newQuot=QMessageBox::question(this, trUtf8("Nueva Cotización"),
                                      trUtf8("Presione \"Si\" para crear un nuevo\n"
                                             "cliente y cotización,  \"No\" para\n"
                                             "crear  una cotización  en cliente  actual"),
                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        switch (newQuot) {
        case QMessageBox::Yes:
            updateButton->setEnabled(false);
            deleteButton->setEnabled(false);
            clearThrdQuotControls();
            clearPropControls();
            clearSoControls();
            quotGenButton->setEnabled(true);
            break;
        case QMessageBox::No:

            // Se hace por si el usuario selecciono crear cotizacion y los datos del cliente estan vacios
            if (thrdNitLineEdit->text()=="") {
                QMessageBox::information(this, trUtf8("Faltan Datos"),
                                         trUtf8("No hay datos del cliente. Se procederá \n"
                                                "a crear cotización con cliente."),
                                         QMessageBox::Ok);
                newQuot=QMessageBox::Yes;
                clearThrdQuotControls();
                clearPropControls();
                clearSoControls();
            } else {
                clearQuotControls();
                clearPropControls();
                clearSoControls();
            }
            updateButton->setEnabled(false);
            deleteButton->setEnabled(false);
            quotGenButton->setEnabled(true);
            break;
        case QMessageBox::Cancel:
            break;
        }
        break;

    case 1: // Nueva Propuesta Comercial
        if (found == 1) { // si se entontró cotización se puede continuar
            newProp=QMessageBox::question(this, trUtf8("Nueva Propuesta"),
                                          trUtf8("Presione \"Si\" para crear una propuesta\n"
                                                 "para " + thrdRepLineEdit->text().toUtf8() + "\n"
                                                 "en la cotización: " + QString::number(quotLCD->value()).toUtf8()),
                                          QMessageBox::Yes | QMessageBox::Cancel);
            switch (newProp) {
            case QMessageBox::Yes:
                updateButton->setEnabled(false);
                deleteButton->setEnabled(false);
                preparePropControls();
                propGenButton->setEnabled(true);
                break;
            case QMessageBox::Cancel:
                break;
            }
        } else {

            QMessageBox::critical(this, trUtf8("Faltan Datos"),
                                  trUtf8("Una propuesta se crea sobre una cotización,\n"
                                         "encuentre la cotización o cree una nueva\n"
                                         "para continuar."),
                                  QMessageBox::Cancel);


        }
        break;
    case 2: // Nueva Orden de Servicio
        if (found == 2) { // se econtró propuesta, se puede continuar.
            // Se consulta si la propuesta está aprobada para continuar.
            if (propStateLineEdit->text() == "Aprobada") {
                newSo=QMessageBox::question(this, trUtf8("Nueva Orden de Servicio"),
                                            trUtf8("Presione \"Si\" para crear una Orden de\n"
                                                   "Servicio para " +propThrdNameLineEdit->text().toUtf8() + "\n"
                                                   "en la propuesta de la cotización: " + QString::number(quotLCD->value()).toUtf8()),
                                            QMessageBox::Yes | QMessageBox::Cancel);
                switch (newSo) {
                case QMessageBox::Yes:
                    updateButton->setEnabled(false);
                    deleteButton->setEnabled(false);
                    prepareSoControls();
                    soGenButton->setEnabled(true);
                    break;
                case QMessageBox::Cancel:
                    break;
                }
            } else {
                QMessageBox::critical(this, trUtf8("Propuesta sin Aprobar"),
                                      trUtf8("La propuesta comercial no está aprobada. \n"
                                             "Cambie a la pestaña de propuesta y apruébela\n"
                                             "para poder continuar."),
                                      QMessageBox::Ok);
            }
        } else {
            QMessageBox::critical(this, trUtf8("Faltan Datos"),
                                  trUtf8("Un Orden de Servicio se crea sobre una \n"
                                         "propuesta, encuentre la prupuesta o cree\n"
                                         "una nueva para continuar."),
                                  QMessageBox::Cancel);

        }
        break;
    }
}

// NOTE: Actualizar algo
void SalesForm::updateSomething()
{

    switch (salesTabWidget->currentIndex()) {
    case 0: // actualizar cotización
        if (found >= 1) { // >1 se encontró cotización, se puede seguir
            if (QMessageBox::information(this, trUtf8("Actualizar Cotización"),
                                         trUtf8("¿Desea Actualizar esta Cotización?"),
                                         QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
                if (validateQuotData() && found >=1) { // >=1 significa que está en una cotización válida
                    if (!updateQuotation())
                        QMessageBox::critical(this, trUtf8("Error Actualizando Cotización"),
                                              trUtf8("No se pudieron actualizar los datos \n"
                                                     "Ejecute  el programa bajo consola y \n"
                                                     "revise   los  mensajes   de   error"),
                                              QMessageBox::Cancel);
                    else
                        QMessageBox::information(this, trUtf8("Actualizando Cotización"),
                                                 trUtf8("Cotización actualizada con éxito"),
                                                 QMessageBox::Ok);
                }
            }
        } else
            QMessageBox::information(this, trUtf8("Error al Actualizar"),
                                     trUtf8("No hay una cotización que actualizar"),
                                     QMessageBox::Cancel);

        break;
    case 1: // actualizar propuesta
        if (found >= 2) { // se encontró propuesta, se puede seguir
            if (QMessageBox::information(this, trUtf8("Actualizar Propuesta"),
                                         trUtf8("¿Desea Actualizar esta Propuesta?"),
                                         QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
                if (validatePropData() && found >=2) {
                    if (!updateProposal())
                        QMessageBox::critical(this, trUtf8("Error Actualizando Propuesta"),
                                              trUtf8("No se pudieron actualizar los datos \n"
                                                     "Ejecute  el programa bajo consola y \n"
                                                     "revise   los  mensajes   de   error"),
                                              QMessageBox::Cancel);
                    else
                        QMessageBox::information(this, trUtf8("Actualizando Propuesta"),
                                                 trUtf8("Propuesta actualizada con éxito"),
                                                 QMessageBox::Ok);
                }

            }
        } else
            QMessageBox::information(this, trUtf8("Error al Actualizar"),
                                     trUtf8("No hay una propuesta que actualizar"),
                                     QMessageBox::Cancel);
        break;
    case 2: // actualizar orden de servicio
        if (found >= 3) { // se encontró órden de servicio, se puede continuar.
            if (QMessageBox::information(this, trUtf8("Actualizar Orden de Servicio"),
                                         trUtf8("¿Desea Actualizar esta Orden de Servicio?"),
                                         QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
                if (validateSoData()) {
                    if (!updateServiceOrder())
                        QMessageBox::critical(this, trUtf8("Error Actualizando OS"),
                                              trUtf8("No se pudieron actualizar los datos \n"
                                                     "Ejecute  el programa bajo consola y \n"
                                                     "revise   los  mensajes   de   error"),
                                              QMessageBox::Cancel);
                    else
                        QMessageBox::information(this, trUtf8("Actualizando OS"),
                                                 trUtf8("Orden de Servicio actualizada con éxito"),
                                                 QMessageBox::Ok);
                }
            }
        } else
            QMessageBox::information(this, trUtf8("Error al Actualizar"),
                                     trUtf8("No hay una orden de servicio que actualizar"),
                                     QMessageBox::Cancel);
        break;
    }

}

// NOTE: Borrar algo
void SalesForm::deleteSomething()
{
    switch (salesTabWidget->currentIndex()) {
    case 0:
        if (found >= 1) {
            if (QMessageBox::warning(this, trUtf8("Eliminar Cotización"),
                                     trUtf8("¿Desea Eliminar esta Cotización?"),
                                     QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
                switch (deleteQuotation()) {
                case 0:
                    QMessageBox::information(this, trUtf8("Eliminando Cotización"),
                                             trUtf8("Cotización Eliminada con éxito"),
                                             QMessageBox::Ok);
                    findByNit(thrdData.at(1));
                    break;
                case 1:
                    QMessageBox::critical(this, trUtf8("Error Eliminando Cotización"),
                                          trUtf8("No se pudo elminar la cotización, hace\n"
                                                 "parte de una propuesta comercial, debe\n"
                                                 "eliminar la propuesta relacionada"),
                                          QMessageBox::Cancel);
                    break;
                case 2:
                    QMessageBox::critical(this, trUtf8("Error Eliminando Cotización"),
                                          trUtf8("No se pudo  elminar  la  cotización \n"
                                                 "Ejecute  el programa bajo consola y \n"
                                                 "revise   los  mensajes   de   error"),
                                          QMessageBox::Cancel);
                    break;
                }

            }
        } else
            QMessageBox::information(this, trUtf8("Error al Borar"),
                                     trUtf8("No hay una cotización que borrar"),
                                     QMessageBox::Cancel);

        break;
    case 1:
        if (found >= 2) {
            if (QMessageBox::warning(this, trUtf8("Eliminar Propuesta"),
                                     trUtf8("¿Desea Eliminar esta Propuesta?"),
                                     QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
                switch (deleteProposal()) {
                case 0:
                    QMessageBox::information(this, trUtf8("Eliminando Propuesta"),
                                             trUtf8("Propuesta Eliminada con éxito"),
                                             QMessageBox::Ok);
                    found = 1; // al eliminar propuesta es seguro que hay cotización
                    break;
                case 1:
                    QMessageBox::critical(this, trUtf8("Error Eliminando Propuesta"),
                                          trUtf8("No se pudo elminar la propuesta, hace\n"
                                                 "parte de una orden de servicio, debe\n"
                                                 "eliminar la orden de servicio relacionada"),
                                          QMessageBox::Cancel);
                    break;
                case 2:
                    QMessageBox::critical(this, trUtf8("Error Eliminando Propuesta"),
                                          trUtf8("No se pudo  elminar  la  propuesta \n"
                                                 "Ejecute  el programa bajo consola y \n"
                                                 "revise   los  mensajes   de   error"),
                                          QMessageBox::Cancel);
                    break;
                }

            }
        } else
            QMessageBox::information(this, trUtf8("Error al Borar"),
                                     trUtf8("No hay una propuesta que borrar"),
                                     QMessageBox::Cancel);
        break;
    case 2:
        if (found >= 3) {
            if (QMessageBox::warning(this, trUtf8("Eliminar Orden de Servicio"),
                                     trUtf8("¿Desea Eliminar esta Orden de Servicio?"),
                                     QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
                switch (deleteServiceOrder()) {
                case 0:
                    QMessageBox::information(this, trUtf8("Eliminando OS"),
                                             trUtf8("Orden de Servicio Eliminada con éxito"),
                                             QMessageBox::Ok);
                    found = 2; // al eliminar la orden de serivcio es seguro que la propuesta existe.
                    break;
                case 1:
                    QMessageBox::critical(this, trUtf8("Error Eliminando OS"),
                                          trUtf8("No se pudo elminar la orden de servicio\n"
                                                 "hace parte de una inspección, debe\n"
                                                 "eliminar la inspección relacionada"),
                                          QMessageBox::Cancel);
                    break;
                case 2:
                    QMessageBox::critical(this, trUtf8("Error Eliminando OS"),
                                          trUtf8("No se pudo  elminar  la  Orden de Servicio \n"
                                                 "Ejecute  el programa bajo consola y \n"
                                                 "revise   los  mensajes   de   error"),
                                          QMessageBox::Cancel);
                    break;
                }
            }
        } else
            QMessageBox::information(this, trUtf8("Error al Borar"),
                                     trUtf8("No hay una orden de servicio que borrar"),
                                     QMessageBox::Cancel);
        break;
    }
}
// NOTE: Generar una nueva cotizacion
void SalesForm::genQuotation()
{
    if (validateQuotData()) {
        switch (insertQuotation(newQuot)) {

        case 2:
            QMessageBox::critical(this, trUtf8("Error Insertando"),
                                  trUtf8("No se  pudo generar la  cotización \n"
                                         "Ejecute el programa bajo consola y \n"
                                         " revise  los  mensajes  de  error"),
                                  QMessageBox::Cancel);
            quotGenButton->setEnabled(false);
            break;
        case 0: // exitoso
            findByNit(thrdData.at(1));

            prevButton->setEnabled(false);
            if (quotsData.at(0).size()==1)
                nextButton->setEnabled(false);
            else
                nextButton->setEnabled(true);
            quotLCD->display(quot_position+1);
            foundLCD->display(quotsData[0].size());

            if (newQuot==QMessageBox::No) // Se hace porque al crear cliente no existe una siguiente cotizacion
                findNext();

            QMessageBox::information(this, trUtf8("Insersión Exitosa"),
                                     trUtf8("Se ha generado corectamente la cotización"),
                                     QMessageBox::Accepted);

            quotGenButton->setEnabled(false);
            updateButton->setEnabled(true);
            deleteButton->setEnabled(true);
            break;
        case 1:
            thrdNitLineEdit->setFocus();
            break;
        case 3:
            QMessageBox::critical(this, trUtf8("Error insertando cotización"),
                                     trUtf8("Ejecute el programa bajo consola \n "
                                            "y anote el error"),
                                     QMessageBox::Ok);
            break;
        }

    }
}

// NOTE: Generar propuesta comercial
void SalesForm::genProposal()
{
    if (validatePropData()) {
        switch (insertProposal()) {
        case 0:
            QMessageBox::information(this, trUtf8("Insersión Exitosa"),
                                     trUtf8("Se ha generado corectamente la Propuesta"),
                                     QMessageBox::Accepted);
            propGenButton->setEnabled(false);
            updateButton->setEnabled(true);
            deleteButton->setEnabled(true);
            propApprovButton->setEnabled(true);

            break;
        case 1:
            QMessageBox::critical(this, trUtf8("Error Insertando"),
                                  trUtf8("Ya existe una propuesta para esta cotización  \n"
                                         "seleccione  una  cotización  sin  propuesta \n"
                                         "o cree una nueva"),
                                  QMessageBox::Cancel);
            propGenButton->setEnabled(false);
            break;
        case 2:
            QMessageBox::critical(this, trUtf8("Error Insertando"),
                                  trUtf8("No se pudo generar la Propuesta. Ejecute  \n"
                                         "el programa  bajo  consola y revise  los \n"
                                         "mensajes  de  error"),
                                  QMessageBox::Cancel);
            propGenButton->setEnabled(false);
            break;

        }
    }
}

// NOTE: Generar orden de servicio
void SalesForm::genServiceOrder()
{
    if (validateSoData()) {
        switch (insertServiceOrder()) {
        case 0:
            QMessageBox::information(this, trUtf8("Insersión Exitosa"),
                                     trUtf8("Se ha generado corectamente la Orden de Servicio"),
                                     QMessageBox::Accepted);
            soGenButton->setEnabled(false);
            updateButton->setEnabled(true);
            deleteButton->setEnabled(true);
            break;
        case 1:
            QMessageBox::critical(this, trUtf8("Error Insertando"),
                                  trUtf8("Ya existe una orden de servicio para esta  \n"
                                         "propuesta, seleccione  una  propuesta sin \n"
                                         "orden de servicio o cree una nueva"),
                                  QMessageBox::Cancel);
            soGenButton->setEnabled(false);
            break;
        case 2:
            QMessageBox::critical(this, trUtf8("Error Insertando"),
                                  trUtf8("No se pudo generar la Órden de Servicio  \n"
                                         "Ejecute el programa bajo consola y revise\n"
                                         "los  mensajes  de  error"),
                                  QMessageBox::Cancel);
            soGenButton->setEnabled(false);
            break;

        }
    }

}

// Llenado de datos segun foundLCD
void SalesForm::findNext()
{
        quot_position+=1;
        fillQuotData();
        if (DbHandler::getProposals(quotsData.at(0).at(quot_position), propsData, "quot_id")) {
            found=2;
            fillPropData();
            if (DbHandler::getServiceOrders(propsData.at(0).at(prop_position), sosData, "prop_id")) {
                found=3;
                fillSoData();
            } else
                clearSoControls();
        } else {
            found=1;
            clearPropControls();
            clearSoControls();
        }
        prevButton->setEnabled(true);
        if (quot_position >= quotsData.at(0).size()-1)
            nextButton->setEnabled(false);
        quotLCD->display(quot_position+1);

}
//
void SalesForm::findPrevious()
{
        quot_position-=1;
        fillQuotData();
        if (DbHandler::getProposals(quotsData.at(0).at(quot_position), propsData, "quot_id")) {
            found=2; // 2 significa que se ha encontrado contizacion + propuesta
            fillPropData();
            if (DbHandler::getServiceOrders(propsData.at(0).at(prop_position), sosData, "prop_id")) {
                found=3; // significa que se ha encontrado cotizacion + propuesta + os
                fillSoData();
            } else
                clearSoControls();
        } else {
            found=1; // 1 significa que solo se ha encontrado cotizacion
            clearPropControls();
            clearSoControls();
        }
        nextButton->setEnabled(true);
        if (quot_position <= 0)
            prevButton->setEnabled(false);
        quotLCD->display(quot_position+1);
}

// NOTE: Slots para cambiar las ciudades de acuerdo al departamento
void SalesForm::setQuotCity(int index)
{
    quotCityComboBox->clear();
    if (DbHandler::getCities(statesData.at(0).at(index), quotCitiesData))
        quotCityComboBox->addItems(quotCitiesData.at(2));
    else
        quotCityComboBox->addItem("Sin Datos");

}

void SalesForm::setThrdCity(int index)
{
    thrdCityComboBox->clear();
    if (DbHandler::getCities(statesData.at(0).at(index), thrdCitiesData))
        thrdCityComboBox->addItems(thrdCitiesData.at(2));
    else
        thrdCityComboBox->addItem("Sin Datos");

}

// NOTE: Renderizar la propuesta en el QWebView
void SalesForm::renderProposal()
{
    // Se obtiene la ruta actual de trabajo
    QString currDir;
    currDir=QDir::currentPath();
    // Si es en linux debe agregarse file://
    #ifdef Q_OS_LINUX
        currDir="file://" + QDir::currentPath();
    #endif

    if (found >=2) {
        QString fileName = QDir::currentPath() + "/templates/proposal_template.html";
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, trUtf8("Error Abriendo Plantilla"),
                                 trUtf8("No se puedo abrir '%1'").arg(fileName));
        } else {
            QStringList selectedDocs(documentsData.at(1)); // La creo así para que tenga el mismo tamaño
            // Obtengo los documentos de la propuesta para ser marcados en la lista
            // que se obtuvo al preparar los controles de propuesta
            QStringList propDocsIds;
            DbHandler::getPropDocuments(propsData.at(Props::Id).at(0), propDocsIds);

            for (int i=0;i<selectedDocs.size();i++)
                selectedDocs.replace(i, QString("&nbsp;")); // Primero los borro todos

            int index;
            for (int i=0; i<propDocsIds.size();i++) {
                // indexOf me entrega la posición en la que está el id del documento, con esa posición
                // reemplazo el string vacío por el nombre del documento
                index=documentsData.at(0).indexOf(propDocsIds.at(i));
                selectedDocs.replace(index, documentsData.at(1).at(index)); // Agrego los seleccionados en la posición correcta
            }

            QStringList selectedProcs(processesData.at(1)); // Creo una copia de los nombre de procesos
            for (int i=0;i<selectedProcs.size();i++)
                selectedProcs.replace(i, QString("")); // Primero los borro todos

            QModelIndexList processesIndexes = quotProcessesListWidget->selectionModel()->selectedIndexes();
            for (int i=0; i< processesIndexes.size(); i++)
                // ProcessesData es un Qlist<QStringList>, 0 es la primera lista, osea la de Ids
                // processesIndexes.at(i).row() indican el registro en cuestion, así coincide
                // lo seleccionado en el listWidget con lo guardado en el QList.
                selectedProcs.replace(processesIndexes.at(i).row(), processesData.at(1).at(processesIndexes.at(i).row()));
                // Con esto quedan los ids de los procesos seleccionados y guardados.

            QTextStream stream(&file);
            QString htmlString;
            htmlString = stream.readAll();

            htmlString.replace("_logo", currDir + "/templates/logorig.png");
            htmlString.replace("_nombreUsuario", propsData.at(Props::UserLName).at(0));
            htmlString.replace("_ciudad", propsData.at(Props::City).at(0));
            htmlString.replace("_fecha", QDate::fromString(propsData.at(Props::Date).at(0), "yyyy-MM-dd").toString("dd 'de' MMMM 'de' yyyy"));
            htmlString.replace("_telefonoUsuario", propsData.at(Props::userCel).at(0));
            htmlString.replace("_emailUsuario", propsData.at(Props::userMail).at(0));
            htmlString.replace("_nombreTercero", propsData.at(Props::thrdName).at(0));
            htmlString.replace("_nombreContacto", quotsData.at(4).at(quot_position));
            htmlString.replace("_telefonoContacto", quotsData.at(7).at(quot_position));
            htmlString.replace("_emailContacto", quotsData.at(6).at(quot_position));
            htmlString.replace("_inspecTipo", quotsData.at(12).at(quot_position));
            htmlString.replace("_propNumero", propsData.at(Props::Id).at(0));
            htmlString.replace("_instalNombre", propsData.at(Props::InstName).at(0));
            htmlString.replace("_tiposProceso", selectedProcs.at(0)+" "+selectedProcs.at(1)
                               +" "+selectedProcs.at(2)+" "+selectedProcs.at(3)+" "+selectedProcs.at(4)
                               +" "+selectedProcs.at(5));
            htmlString.replace("_alcance", propsData.at(Props::Scope).at(0));

            htmlString.replace("_a", selectedDocs.at(0));
            htmlString.replace("_b", selectedDocs.at(1));
            htmlString.replace("_c", selectedDocs.at(2));
            htmlString.replace("_d", selectedDocs.at(3));
            htmlString.replace("_e", selectedDocs.at(4));
            htmlString.replace("_f", selectedDocs.at(5));
            htmlString.replace("_g", selectedDocs.at(6));
            htmlString.replace("_h", selectedDocs.at(7));
            htmlString.replace("_i", selectedDocs.at(8));
            htmlString.replace("_j", selectedDocs.at(9));
            htmlString.replace("_k", selectedDocs.at(10));
            htmlString.replace("_l", selectedDocs.at(11));
            htmlString.replace("_m", selectedDocs.at(12));
            htmlString.replace("_n", selectedDocs.at(13));
            htmlString.replace("_o", selectedDocs.at(14));
            htmlString.replace("_p", selectedDocs.at(15));
            htmlString.replace("_q", selectedDocs.at(16));
            htmlString.replace("_r", selectedDocs.at(17));
            htmlString.replace("_s", selectedDocs.at(18));
            htmlString.replace("_t", selectedDocs.at(19));
            htmlString.replace("_u", selectedDocs.at(20));
            htmlString.replace("_v", selectedDocs.at(21));

            htmlString.replace("-inspecValor", propsData.at(Props::ValueMoney).at(0));
            htmlString.replace("-inspecIVA", propsData.at(Props::Iva).at(0));
            htmlString.replace("-inspecViaticos", propsData.at(Props::Viatic).at(0));
            htmlString.replace("-inspecTotal", propsData.at(Props::TotVal).at(0));
            htmlString.replace("-formaPago", propsData.at(Props::PayWay).at(0));

            //propOutWebView->setHtml(htmlString);
            //propOutWebView->setZoomFactor(0.72);

        }
    }else
        QMessageBox::warning(this, trUtf8("Vista Previa"),
                             trUtf8("No hay Propuesta para previsualizar"));

//    propsData.append(propsIds); // 0
//    propsData.append(quotsIds); // 1
//    propsData.append(propsScopes); // 2
//    propsData.append(propsDates); // 3
//    propsData.append(propsValues); // 4
//    propsData.append(propsPayWay); // 5
//    propsData.append(propsUsersPerc); // 6
//    propsData.append(propsStates); // 7
//    propsData.append(quotsCityNames); // 8
//    propsData.append(quotsAddress); // 9
//    propsData.append(quotsNames); // 10
//    propsData.append(inspectorsNames); // 11
//    propsData.append(usersNames); // 12
//    propsData.append(thrdNit); // 13
//    propsData.append(thrdName); // 14
//    propsData.append(propsObserv); // 15
//    propsData.append(propsIvas); // 16
//    propsData.append(propsViaticals); // 17
//    propsData.append(propsTotalValues); // 18
//    propsData.append(usersCels); // 19
//    propsData.append(usersMails); // 20
}

// NOTE: Renderizar la orden de servicio en el QWebView
void SalesForm::renderServiceOrder()
{
    QString currDir;
    currDir=QDir::currentPath();
    #ifdef Q_OS_LINUX
        currDir="file://" + QDir::currentPath();
    #endif
    if (found >=3) {
        QString fileName = QDir::currentPath() + "/templates/so_template.html";
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, trUtf8("Error Abriendo Plantilla"),
                                 trUtf8("No se puedo abrir '%1'").arg(fileName));
        } else {
            QStringList selectedProcs(processesData.at(1)); // Creo una copia de los nombre de procesos
            for (int i=0;i<selectedProcs.size();i++)
                selectedProcs.replace(i, QString("")); // Primero los borro todos

            QModelIndexList processesIndexes = quotProcessesListWidget->selectionModel()->selectedIndexes();
            for (int i=0; i< processesIndexes.size(); i++)
                // ProcessesData es un Qlist<QStringList>, 0 es la primera lista, osea la de Ids
                // processesIndexes.at(i).row() indican el registro en cuestion, así coincide
                // lo seleccionado en el listWidget con lo guardado en el QList.
                selectedProcs.replace(processesIndexes.at(i).row(), processesData.at(1).at(processesIndexes.at(i).row()));
                // Con esto quedan los ids de los procesos seleccionados y guardados.

            // Primero se carga el archivo a un stream de texto
            QTextStream stream(&file);
            QString htmlString;
            htmlString = stream.readAll();

            htmlString.replace("_logo", currDir + "/templates/logorig.png");
            htmlString.replace("_fecha", QDate::fromString(sosData.at(1).at(0), "yyyy-MM-dd").toString("dd 'de' MMMM 'de' yyyy"));
            htmlString.replace("_osNumero", sosData.at(0).at(0));
            htmlString.replace("_propNumero", propsData.at(0).at(0));
            htmlString.replace("_nombreTercero", thrdData.at(2));
            htmlString.replace("_nit", thrdData.at(1));
            htmlString.replace("_direccion", thrdData.at(5));
            htmlString.replace("_celular", thrdData.at(7));
            htmlString.replace("_ciudadTercero", thrdData.at(10));
            htmlString.replace("_departTercero", thrdData.at(9));
            htmlString.replace("_nombreContacto", quotsData.at(4).at(quot_position));
            htmlString.replace("_telefonoContacto", quotsData.at(8).at(quot_position));
            htmlString.replace("_nombreInstal", quotsData.at(2).at(quot_position));
            htmlString.replace("_ciudadInstal", quotsData.at(10).at(quot_position));
            htmlString.replace("_departInstal", quotsData.at(9).at(quot_position));
            htmlString.replace("_ubicacionInst", quotsData.at(5).at(quot_position));
            htmlString.replace("_alcance", sosData.at(2).at(0));
            htmlString.replace("_tiposProceso", selectedProcs.at(0)+" "+selectedProcs.at(1)
                               +" "+selectedProcs.at(2)+" "+selectedProcs.at(3)+" "+selectedProcs.at(4)
                               +" "+selectedProcs.at(5));
            htmlString.replace("_tipoUso", quotsData.at(11).at(quot_position));
            htmlString.replace("_observ", sosData.at(3).at(0));
            htmlString.replace("_nombreInspect", sosData.at(Sos::InspName).at(0));
            htmlString.replace("_fInsp", QDate::fromString(sosData.at(Sos::AssignD).at(0), "yyyy-MM-dd").toString("dd 'de' MMMM 'de' yyyy"));

            //soOutWebView->setHtml(htmlString);
            //soOutWebView->setZoomFactor(0.73);
        }
    }else
        QMessageBox::warning(this, trUtf8("Vista Previa"),
                             trUtf8("No hay Orden de Servicio para previsualizar"));

//    thrdData.append(queryGetThirdPartie.value(0).toString()); //id
//    thrdData.append(queryGetThirdPartie.value(1).toString()); //nit
//    thrdData.append(queryGetThirdPartie.value(2).toString()); //razon zocial
//    thrdData.append(queryGetThirdPartie.value(3).toString()); //representante legal
//    thrdData.append(queryGetThirdPartie.value(4).toString()); //cedula
//    thrdData.append(queryGetThirdPartie.value(5).toString()); //direccion
//    thrdData.append(queryGetThirdPartie.value(6).toString()); //mail
//    thrdData.append(queryGetThirdPartie.value(7).toString()); //celular
//    thrdData.append(queryGetThirdPartie.value(8).toString()); //telefono
//    thrdData.append(queryGetThirdPartie.value(9).toString()); //deprtamento
//    thrdData.append(queryGetThirdPartie.value(10).toString()); //ciudad

//    quotsData.append(quotIds); 0
//    quotsData.append(quotDates); 1
//    quotsData.append(quotNames); 2
//    quotsData.append(quotScopes); 3
//    quotsData.append(quotContacts); 4
//    quotsData.append(quotAddresses); 5
//    quotsData.append(quotMails); 6
//    quotsData.append(quotCels); 7
//    quotsData.append(quotTels); 8
//    quotsData.append(quotStates); 9
//    quotsData.append(quotCities); 10
//    quotsData.append(quotUses); 11
//    quotsData.append(quotInspecType); 12

//    sosData.append(sosIds);  0
//    sosData.append(sosDates); 1
//    sosData.append(sosScopes); 2
//    sosData.append(sosObservations); 3
//    sosData.append(sosProcessed); 4
//    sosData.append(propsIds); 5
//    sosData.append(recordsFoils); 6

}

// NOTE: Imprimir propuesta comercial
void SalesForm::printProposal()
{
    if (found >=2) {

        QPrinter printer(QPrinter::HighResolution);
        printer.setDocName(trUtf8("PC - %1 - %2").arg(propsData.at(0).at(0)).arg(propsData.at(14).at(0)));
        printer.setPaperSize(QPrinter::A4);
        printer.setPageMargins(10,10,10,10,QPrinter::Millimeter);

#ifdef Q_OS_LINUX
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(QDir::homePath() +"/"+ printer.docName() + ".pdf");
#endif
        QPrintDialog *dialog = new QPrintDialog(&printer, this);
        dialog->setWindowTitle(trUtf8("Imprimir Propuesta"));
        if ( dialog->exec() == QDialog::Accepted) {
            //propOutWebView->setZoomFactor(1);
            //propOutWebView->page()->print(&printer, true);
            //propOutWebView->setZoomFactor(0.73);
        }
    } else
        QMessageBox::warning(this, trUtf8("Imprimir Propuesta"),
                             trUtf8("No hay Propuesta para imprimir"));

}

// NOTE: Imprimir orden de servicio
void SalesForm::printServiceOrder()
{
    if (found >=3) {
        QPrinter printer;
        printer.setDocName(trUtf8("OS - %1 - %2").arg(sosData.at(0).at(0)).arg(propsData.at(14).at(0)));
        printer.setPaperSize(QPrinter::A4);
        printer.setPageMargins(10,10,10,10,QPrinter::Millimeter);

#ifdef Q_OS_LINUX
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(QDir::homePath() +"/"+ printer.docName() + ".pdf");
#endif

        QPrintDialog *dialog = new QPrintDialog(&printer, this);
        dialog->setWindowTitle(trUtf8("Imprimir Orden de Servicio"));
        if ( dialog->exec() == QDialog::Accepted) {
            //soOutWebView->setZoomFactor(1);
            //soOutWebView->page()->print(&printer, true);
            //soOutWebView->setZoomFactor(0.73);
        }
    } else
        QMessageBox::warning(this, trUtf8("Imprimir Orden de Servicio"),
                             trUtf8("No hay Orden de Servicio para imprimir"));
}


// NOTE: Listar todas las cotizaciones, propuestas, ordenes de servicio
void SalesForm::listSomething()
{
    switch (salesTabWidget->currentIndex()) {
    case 0:
        // Listar cotizaciones
        listQuotations();
        break;
    case 1:
        // Listar Propuestas comerciales
        listProposals();
        break;
    case 2:
        // Listar Ordenes de servicio
        listServiceOrders();
        break;
    }
}

// NOTE: Aprobar propuesta comercial
void SalesForm::approvProposal()
{
    bool ok;
    QStringList approvalList;
    approvalList.append(trUtf8("Consignación"));
    approvalList.append(trUtf8("Transferencia bancaria"));
    approvalList.append(trUtf8("Orden de compra"));
    approvalList.append(trUtf8("Pago en efectivo"));
    approvalList.append(trUtf8("Cheque"));

    QString approvalDetail = QInputDialog::getItem(this, trUtf8("Método de Aprobación"),
                                         trUtf8("Seleccione el método de aprobación usado, o presione cancelar para no aprobar:"),
                                         approvalList, 0, false, &ok);
    if (ok) {
        if (DbHandler::updatePropApproval(propsData.at(Props::Id).at(0), "Aprobada", approvalDetail)) {
            propStateLineEdit->setText("Aprobada");
            propStateDetailLineEdit->setText(approvalDetail);
            QMessageBox::information(this, trUtf8("Propuesta Aprobada"),
                                 trUtf8("Se ha aprobado la propuesta comercial, \n "
                                        "ahora puede crear la Orden de Servicio"),
                                 QMessageBox::Ok);
        } else
            qDebug() << "Error, DbHandler::updatePropApprobal devolvió false al tratar de aprobar la propuesta";
    }
}

// NOTE: Aprobar propuesta comercial
void SalesForm::rejectProposal()
{
    bool ok;
    QStringList rejectList;
    rejectList.append(trUtf8("Cliente no responde"));
    rejectList.append(trUtf8("Precio mínimo rechazado"));
    rejectList.append(trUtf8("No se puede cubrir el alcance"));

    QString rejectDetail = QInputDialog::getItem(this, trUtf8("Razón de Rechazo"),
                                         trUtf8("Seleccione la razón por la que se rechazó la propuesta, o presione cancelar para no rechazar:"),
                                         rejectList, 0, false, &ok);
    if (ok) {
        if (DbHandler::updatePropApproval(propsData.at(Props::Id).at(0), "Rechazada", rejectDetail)) {
            propStateLineEdit->setText("Rechazada");
            propStateDetailLineEdit->setText(rejectDetail);
            QMessageBox::information(this, trUtf8("Propuesta Rechazada"),
                                 trUtf8("Se ha rechazado la propuesta comercial, \n"
                                        "no podrá crear la Orden de Servicio"),
                                 QMessageBox::Ok);
       } else
            qDebug() << "Error, DbHandler::updatePropApprobal devolvió false al tratar de rechazar la propuesta";
    }
}


// TODO: Falla de actualización activa botón de nuevo
// TODO: Revisar asignar fecha actual a asignación de inspección cuando se crea la nueva os..
// TODO: Revisar los mensajes de error en windows cuando se rendea una propuesta, file://






