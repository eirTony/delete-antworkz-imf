#ifndef SINGLETON_H
#define SINGLETON_H

#include <QtDebug>

#if 0
template <class T> class PointerSingleton
{
public:
    static T * instance(void)
        { if (mpT) return mpT; return mpT = new T(); }

protected:
    PointerSingleton(void) {}
    PointerSingleton(const T & rhs);

private:
    static T * mpT = 0;
};
#endif

template <class T> class StaticSingleton
{
public:
    static T & instance(void)
        { static T it; return it; }
    static T * p(void)
        { return &instance(); }
    T & operator() (void) const
        { return instance(); }

protected:
    StaticSingleton(void) {}
    StaticSingleton(const T & rhs);
};

#endif // SINGLETON_H
