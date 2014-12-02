#ifndef EMPTY_GLOBAL_H
#define EMPTY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(KID_LIBRARY)
#  define KIDSHARED_EXPORT Q_DECL_EXPORT
#else
#  define KIDSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // EMPTY_GLOBAL_H
