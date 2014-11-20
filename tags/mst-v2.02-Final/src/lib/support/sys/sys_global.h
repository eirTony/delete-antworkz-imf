#ifndef SYS_GLOBAL_H
#define SYS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SYS_LIBRARY)
#  define SYSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SYSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SYS_GLOBAL_H
