#include "ArgumentSourcePair.h"

ArgumentSourcePair::ArgumentSourcePair(void) {}

ArgumentSourcePair::ArgumentSourcePair(const QQString & argument,
                                       const QQString & source)
    : StringPair(argument, source) {}

QQString ArgumentSourcePair::argument(void) const
{
    return StringPair::first();
}

QQString ArgumentSourcePair::source(void) const
{
    return StringPair::second();
}


