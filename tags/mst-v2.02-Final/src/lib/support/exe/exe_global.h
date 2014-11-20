#ifndef EXE_GLOBAL_H
#define EXE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(EXE_LIBRARY)
#  define EXESHARED_EXPORT Q_DECL_EXPORT
#else
#  define EXESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // EXE_GLOBAL_H
