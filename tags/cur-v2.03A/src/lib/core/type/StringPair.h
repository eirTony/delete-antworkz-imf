#ifndef STRINGPAIR_H
#define STRINGPAIR_H
#include "TypeLib.h"

#include "QQPair.h"
#include "QQString.h"

class TYPESHARED_EXPORT StringPair : public QQPair<QQString, QQString>
{
public:
    typedef QQPair<QQString, QQString> Base;

public:
    StringPair(void);
    StringPair(const QQString & first,
               const QQString & second);
    QQString first(void)  const;
    QQString second(void) const;
};

#endif // STRINGPAIR_H
