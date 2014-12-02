#-------------------------------------------------
#
# Project created by QtCreator 2014-10-01T21:29:12
#
#-------------------------------------------------

QT       -= gui

TARGET = eirBase
TEMPLATE = lib

DEFINES += BASE_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *=

SOURCES += BaseLib.cpp \
    ModuleInfo.cpp \
    VersionInfo.cpp \
    BaseLog.cpp \
    BasicName.cpp \
    FunctionInfo.cpp \
    FunctionMap.cpp \
    FileLinePair.cpp \
    PluginObject.cpp \
    AbstractPlugin.cpp \
    BasicId.cpp \
    MetaName.cpp

HEADERS += BaseLib.h\
        base_global.h \
    ModuleInfo.h \
    VersionInfo.h \
    Version.h \
    ../../../CommonVersion.h \
    ../type/CProperty.h \
    ../type/Singleton.h \
    BaseLog.h \
    BasicName.h \
    FunctionInfo.h \
    FunctionMap.h \
    FileLinePair.h \
    BasicNameMap.h \
    BasicNameHash.h \
    PluginObject.h \
    AbstractPlugin.h \
    BasicId.h \
    MetaName.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
