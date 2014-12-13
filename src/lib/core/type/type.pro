#-------------------------------------------------
#
# Project created by QtCreator 2014-10-01T21:39:05
#
#-------------------------------------------------

QT       -= gui

TARGET = eirType
TEMPLATE = lib

DEFINES += TYPE_LIBRARY

include (../common.pri)

LIBS *= -leirBase

SOURCES += TypeLib.cpp \
    MillisecondTime.cpp \
    QQString.cpp \
    QQRegularExpression.cpp \
    QQChar.cpp \
    QQVariant.cpp \
    QQStringList.cpp \
    StringPair.cpp \
    QQList.cpp \
    QQUrl.cpp \
    QQDir.cpp \
    QQFile.cpp \
    QQDataStream.cpp \
    QQTextStream.cpp \
    QQFileInfo.cpp

HEADERS += TypeLib.h\
    type_global.h \
    MillisecondTime.h \
    CProperty.h \
    DProperty.h \
    QQString.h \
    QQRegularExpression.h \
    CharCode.h \
    QQChar.h \
    QQVariant.h \
    QQStringList.h \
    StringPair.h \
    QQPair.h \
    QQList.h \
    CharCode.h \
    Unsigned.h \
    QQUrl.h \
    QQDir.h \
    QQFile.h \
    QQDataStream.h \
    QQTextStream.h \
    QQFileInfo.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
