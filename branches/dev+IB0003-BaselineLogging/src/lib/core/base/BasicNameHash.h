#ifndef BASICNAMEHASH_H
#define BASICNAMEHASH_H

#include <QHash>
#include "BasicName.h"

template <class T> class BasicNameHash : public QHash<BasicName, T>
{
public:
    typedef QHash<BasicName, T> Base;

public:
    BasicNameHash(void) {}
    void insert(const BasicName & name, const T & t)
    { Base::insert(name.sortable(), t); }
    bool contains(const BasicName & name) const
    { return Base::contains(name.sortable()); }
    void remove(const BasicName & name)
    { Base::remove(name.sortable()); }
    T value(const BasicName & name, const T defaultT=T())
    { return Base::value(name.sortable(), defaultT); }
};

#endif // BASICNAMEHASH_H
