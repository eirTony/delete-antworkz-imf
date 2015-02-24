
QT       -= gui

TARGET = eirMsg
TEMPLATE = lib

DEFINES += MSG_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

#LIBS *= -leirQuick
LIBS *= -leirBase
LIBS *= -leirVar

SOURCES += MsgLib.cpp \
    EclipseMessageQueue.cpp \
    EclipseMessage.cpp

HEADERS += MsgLib.h \
    Version.h \
    ../../../CommonVersion.h \
    Msg_global.h \
    EclipseMessageQueue.h \
    EclipseMessage.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
