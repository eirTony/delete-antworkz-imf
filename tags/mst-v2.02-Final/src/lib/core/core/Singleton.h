#ifndef SINGLETON_H
#define SINGLETON_H

#include <QtDebug>

template <class T> class Singleton
{
public:
    static T & instance(void)
        { static T it; return it; }
    static T * p(void)
        { return &instance(); }
    T & operator() (void) const
        { return instance(); }

protected:
    Singleton(void) {}
    Singleton(const T & rhs);
};

#endif // SINGLETON_H
