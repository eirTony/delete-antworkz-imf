#ifndef STATE_GLOBAL_H
#define STATE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(STATE_LIBRARY)
#  define STATESHARED_EXPORT Q_DECL_EXPORT
#else
#  define STATESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // STATE_GLOBAL_H
