#ifndef ARGUMENTSOURCEPAIR_H
#define ARGUMENTSOURCEPAIR_H

#include <type/StringPair.h>

#include <QList>

class ArgumentSourcePair : public StringPair
{
public:
    typedef QList<StringPair> List;

public:
    ArgumentSourcePair(void);
    ArgumentSourcePair(const QQString & argument,
                       const QQString & source);
    QQString argument(void) const;
    QQString source(void) const;
};

#endif // ARGUMENTSOURCEPAIR_H
