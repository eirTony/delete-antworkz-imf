#ifndef EMPTY_GLOBAL_H
#define EMPTY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(EMPTY_LIBRARY)
#  define EMPTYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define EMPTYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // EMPTY_GLOBAL_H
