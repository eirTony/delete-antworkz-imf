#ifndef WORK_GLOBAL_H
#define WORK_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(WORK_LIBRARY)
#  define WORKSHARED_EXPORT Q_DECL_EXPORT
#else
#  define WORKSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // WORK_GLOBAL_H
