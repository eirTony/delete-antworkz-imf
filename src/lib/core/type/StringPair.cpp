#include "StringPair.h"

StringPair::StringPair(void) {}

StringPair::StringPair(const QQString & first,
                       const QQString & second)
    : Base(first, second) {}

QQString StringPair::first(void)  const
{
    return first();
}

QQString StringPair::second(void) const
{
    return second();
}


