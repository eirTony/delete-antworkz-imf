
QT       -= gui

TARGET = eirEmpty
TEMPLATE = lib

DEFINES += EMPTY_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirQuick
LIBS *= -leirBase

SOURCES += EmptyLib.cpp

HEADERS += EmptyLib.h \
    Version.h \
    ../../../CommonVersion.h \
    empty_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
