#ifndef QQPAIR_H
#define QQPAIR_H

#include <QPair>

template <class FIRST, class SECOND>
    class QQPair : public QPair<FIRST, SECOND>
{
public:
    QQPair(void) {}
    QQPair(const FIRST & first, const SECOND & second)
        : QPair<FIRST, SECOND>(first, second) {}
    FIRST  first(void)  const { return first; }
    SECOND second(void) const { return second; }
};

#endif // QQPAIR_H
