
QT       -= gui

TARGET = eirKid
TEMPLATE = lib

DEFINES += KID_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase

SOURCES += KidLib.cpp \
    AbstractId.cpp \
    AbstractName.cpp \
    BaseNameIdBehavior.cpp

HEADERS += KidLib.h \
    Version.h \
    ../../../CommonVersion.h \
    AbstractId.h \
    AbstractName.h \
    BaseNameIdBehavior.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
