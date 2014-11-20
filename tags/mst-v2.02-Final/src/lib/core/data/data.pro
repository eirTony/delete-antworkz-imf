
QT       -= gui

TARGET = eirData
TEMPLATE = lib

DEFINES += DATA_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase

SOURCES += DataLib.cpp

HEADERS += DataLib.h \
    Version.h \
    ../../../CommonVersion.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
