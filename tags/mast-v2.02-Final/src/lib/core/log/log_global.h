#ifndef EMPTY_GLOBAL_H
#define EMPTY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LOG_LIBRARY)
#  define LOGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LOGSHARED_EXPORT Q_DECL_IMPORT
#endif
#define MODULE_NAME "eirLog"

#endif // EMPTY_GLOBAL_H
