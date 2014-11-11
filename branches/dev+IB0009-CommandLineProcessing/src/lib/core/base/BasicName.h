#ifndef BASICNAME_H
#define BASICNAME_H
#include "BaseLib.h"

#include <QList>
#include <QMap>
#include <QString>


class BASESHARED_EXPORT BasicName
{
public:
    typedef QList<BasicName> List;

public:
    BasicName(const QString & name=QString());
    BasicName(const char * psz);
    bool isNull(void) const;
    void clear(void);
    void set(const QString & name);
    QString sortable(void) const;

private:
    QString mName;
};

typedef BasicName::List BasicNameList;

#endif // BASICNAME_H
