
QT       -= gui

TARGET = eirState
TEMPLATE = lib

DEFINES += STATE_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

#LIBS *= -leirQuick
LIBS *= -leirBase

SOURCES += StateLib.cpp

HEADERS += StateLib.h \
    Version.h \
    ../../../CommonVersion.h \
    state_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
