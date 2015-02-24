
QT       -= gui

TARGET = eirState
TEMPLATE = lib

DEFINES += STATE_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

#LIBS *= -leirQuick
LIBS *= -leirBase
LIBS *= -leirVar
LIBS *= -leirCfg

SOURCES += StateLib.cpp \
    EclipseStateMachine.cpp \
    StateMachineConfiguration.cpp

HEADERS += StateLib.h \
    Version.h \
    ../../../CommonVersion.h \
    state_global.h \
    EclipseStateMachine.h \
    StateMachineConfiguration.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
