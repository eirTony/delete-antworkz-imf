#ifndef METANAME_H
#define METANAME_H
#include "BaseLib.h"

#include <QByteArray>
#include <QString.h>

class BASESHARED_EXPORT MetaName : public QByteArray
{
public:
    MetaName(const QByteArray & name=QByteArray());
    MetaName(const QString & string);
    MetaName(const char * chars);
};

#endif // METANAME_H
