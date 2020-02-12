TEMPLATE = app
CONFIG += qt \
    warn_on \
    debug
QT += core \
    webenginewidgets \
    uitools \
    gui \
    network \
    sql \
    printsupport
DESTDIR += bin
FORMS += ui/sales.ui \
    ui/login.ui \
    ui/filterquotations.ui \
    ui/filterproposals.ui \
    ui/filterserviceorders.ui \
    ui/checkfolder.ui \
    ui/accounting.ui \
    ui/filteraccountinginfo.ui \
    ui/sotracking.ui \
    ui/engineering.ui \
    ui/dictum.ui \
    ui/subdictum.ui \
    ui/subdictumslist.ui \
    ui/editpersons.ui \
    ui/renderdictum.ui \
    ui/mainwindow.ui \
    ui/sostate.ui \
    ui/logview.ui \
    ui/bcconfs.ui \
    ui/filesomething.ui
HEADERS += src/core/dbhandler.h \
    src/core/salesutils.h \
    src/core/sales.h \
    src/core/login.h \
    src/userlib/filterquotations.h \
    src/userlib/filterserviceorders.h \
    src/userlib/filterproposals.h \
    src/userlib/tools.h \
    src/core/checkfolder.h \
    src/core/accounting.h \
    src/userlib/filteraccountinginfo.h \
    src/core/sotracking.h \
    src/core/engineering.h \
    src/core/engineeringutils.h \
    src/userlib/spinboxdelegate.h \
    src/core/dictum.h \
    src/core/subdictum.h \
    src/core/subdictumslist.h \
    src/core/editpersons.h \
    src/userlib/renderdictum.h \
    src/core/mainwindow.h \
    src/userlib/logger.h \
    src/core/logview.h \
    src/core/sostate.h \
    src/userlib/outsideactions.h \
    src/core/bcconfs.h \
    src/userlib/bcnamespace.h \
    src/userlib/filesomething.h

SOURCES += src/core/main.cpp \
    src/core/dbhandler.cpp \
    src/core/sales.cpp \
    src/core/login.cpp \
    src/userlib/filterquotations.cpp \
    src/userlib/filterproposals.cpp \
    src/userlib/filterserviceorders.cpp \
    src/core/checkfolder.cpp \
    src/core/accounting.cpp \
    src/userlib/filteraccointinginfo.cpp \
    src/core/sotracking.cpp \
    src/core/engineering.cpp \
    src/userlib/spinboxdelegate.cpp \
    src/core/dictum.cpp \
    src/core/subdictum.cpp \
    src/core/subdictumslist.cpp \
    src/core/editpersons.cpp \
    src/userlib/renderdictum.cpp \
    src/core/mainwindow.cpp \
    src/userlib/logger.cpp \
    src/core/logview.cpp \
    src/core/sostate.cpp \
    src/userlib/outsideactions.cpp \
    src/core/bcconfs.cpp \
    src/userlib/filesomething.cpp

RESOURCES += resources/resources.qrc
INCLUDEPATH += . \
    src
#Costumized Shadow Build
MOC_DIR += build/moc
RCC_DIR += build/rcc
UI_DIR += build/ui

macx {
    TARGET = blockcheck
    CONFIG-=app_bundle
    ICON +=  resources/icons/icon.icns
    OBJECTS_DIR += build/o/mac
}
unix { 
    TARGET = blockcheck
    OBJECTS_DIR += build/o/unix
}

win64 {
    TARGET = BlockCheck
    OBJECTS_DIR += build/o/win64
}
#Install
target.path = bin/
INSTALLS += target
