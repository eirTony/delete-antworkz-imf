
QT       -= gui

TARGET = eirWork
TEMPLATE = lib

DEFINES += WORK_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirQuick
LIBS *= -leirBase

SOURCES += WorkLib.cpp

HEADERS += WorkLib.h \
    Version.h \
    ../../../CommonVersion.h \
    work_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
