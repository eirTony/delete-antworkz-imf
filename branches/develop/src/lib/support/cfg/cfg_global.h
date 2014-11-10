#ifndef CFG_GLOBAL_H
#define CFG_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CFG_LIBRARY)
#  define CFGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CFGSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CFG_GLOBAL_H
