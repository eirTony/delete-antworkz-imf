#ifndef BASICID_H
#define BASICID_H
#include "BaseLib.h"

#include <QList>
#include <QMap>
#include <QString>
#include <QVariant>

class BASESHARED_EXPORT BasicId : public QString
{
public:
    typedef QList<BasicId> List;
    typedef QMap<BasicId, QVariant> VariantMap;

public:
    BasicId(const QString & string=QString());
    BasicId(const char * const chars);
};

#endif // BASICID_H
