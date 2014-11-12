#ifndef QQSTRINGLIST_H
#define QQSTRINGLIST_H
#include "TypeLib.h"

#include <QStringList>
#include "QQList.h"

class TYPESHARED_EXPORT QQStringList : public QStringList
{
public:
    QQStringList(void);
    QQStringList(const QStringList & other);
};

#endif // QQSTRINGLIST_H
