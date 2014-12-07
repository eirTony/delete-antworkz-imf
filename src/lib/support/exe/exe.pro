
QT       -= gui

TARGET = eirExe
TEMPLATE = lib

DEFINES += EXE_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase
LIBS *= -leirType

SOURCES += ExeLib.cpp \
    ConsoleApplication.cpp \
    ExecutableSupport.cpp \
    SerialExecutable.cpp \
    StandardIO.cpp \
    StandardStream.cpp \
    BaseSerialStream.cpp \
    CommandLineOption.cpp \
    CommandLineProcessing.cpp \
    CommandLineResult.cpp \
    CommandLineOptions.cpp \
    ArgumentSourcePair.cpp \
    BaseSerialStream.cpp \
    PluginManager.cpp \
    ArgumentElement.cpp

HEADERS += ExeLib.h \
    Exe_global.h \
    Version.h \
    ../../../CommonVersion.h \
    ConsoleApplication.h \
    ExecutableSupport.h \
    SerialExecutable.h \
    StandardIO.h \
    StandardStream.h \
    BaseSerialStream.h \
    CommandLineOption.h \
    CommandLineProcessing.h \
    CommandLineResult.h \
    CommandLineOptions.h \
    ArgumentSourcePair.h \
    BaseSerialStream.h \
    PluginManager.h \
    ArgumentElement.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc
