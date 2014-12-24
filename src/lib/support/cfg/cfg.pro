
QT       -= gui

TARGET = eirCfg
TEMPLATE = lib

DEFINES += CFG_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase
LIBS *= -leirVar

SOURCES += CfgLib.cpp \
    Configuration.cpp

HEADERS += CfgLib.h \
    cfg_global.h \
    Version.h \
    ../../../CommonVersion.h \
    Configuration.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
