#ifndef MSG_GLOBAL_H
#define MSG_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MSG_LIBRARY)
#  define MSGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MSGSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MSG_GLOBAL_H
