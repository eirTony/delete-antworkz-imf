
QT       -= gui

TARGET = eirWork
TEMPLATE = lib

DEFINES += WORK_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase
LIBS *= -leirState
LIBS *= -leirMsg

SOURCES += WorkLib.cpp \
    EclipseWorkSupervisor.cpp \
    EclipseWorkMessageMachine.cpp

HEADERS += WorkLib.h \
    Version.h \
    ../../../CommonVersion.h \
    work_global.h \
    EclipseWorkSupervisor.h \
    EclipseWorkMessageMachine.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
