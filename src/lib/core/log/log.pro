
QT       -= gui

TARGET = eirLog
TEMPLATE = lib

DEFINES += LOG_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase

SOURCES += LogLib.cpp \
    LogItem.cpp \
    LogFork.cpp \
    Logger.cpp \
    LogLevel.cpp \
    ForkOutputBehavior.cpp \
    ItemFormatBehavior.cpp \
    TodoItem.cpp \
    LogOutputPlugin.cpp \
    LogOutputInterface.cpp \
    DatastreamLogOutput.cpp \
    ReadableLogOutput.cpp \
    Severity.cpp

HEADERS += LogLib.h \
    Version.h \
    ../../../CommonVersion.h \
    LogItem.h \
    LogFork.h \
    Logger.h \
    LogLevel.h \
    Log.h \
    ForkOutputBehavior.h \
    ItemFormatBehavior.h \
    TodoItem.h \
    LogOutputPlugin.h \
    LogOutputInterface.h \
    DatastreamLogOutput.h \
    ReadableLogOutput.h \
    Severity.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
