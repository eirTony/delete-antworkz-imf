
QT       -= gui

TARGET = eirCore
TEMPLATE = lib

DEFINES += CORE_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase

SOURCES += CoreLib.cpp

HEADERS += CoreLib.h \
    Version.h \
    ../../../CommonVersion.h \
    Singleton.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
