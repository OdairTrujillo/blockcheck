#include <QtWidgets>

#include "dbhandler.h"
#include "mainwindow.h"



int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QTranslator translator;
    translator.load("qt_es", app.applicationDirPath());
    app.installTranslator(&translator);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
