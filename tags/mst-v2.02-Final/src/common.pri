# file: ./src/common.pri
message("In ./src/common.pri")

#SRCDIR = $$(PWD)
#BASEDIR = $$dirname($$SRCDIR)
#EXEDIR = $$BASEDIR/exe
SRCDIR = ../../..
BASEDIR = ../../../..
EXEDIR = ../../../../exe

CONFIG += debug_and_release
CONFIG(debug, debug|release) {
        QMAKE_CXXFLAGS_DEBUG *= -Og
        DESTDIR = $$EXEDIR/dbg32W
        LIBS += -L$$EXEDIR/dbg32W
}
else {
        DESTDIR = $$EXEDIR/bin32W
        LIBS += -L$$EXEDIR/bin32W
}
INCLUDEPATH *= ../../../lib/core
INCLUDEPATH *= ../../../lib/support
INCLUDEPATH *= ../../..
DEFINES *= QT_USE_QSTRINGBUILDER
QMAKE_CXXFLAGS *= -std=c++11

