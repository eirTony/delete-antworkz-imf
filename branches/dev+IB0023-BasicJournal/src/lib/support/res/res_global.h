#ifndef RES_GLOBAL_H
#define RES_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RES_LIBRARY)
#  define RESSHARED_EXPORT Q_DECL_EXPORT
#else
#  define RESSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RES_GLOBAL_H
