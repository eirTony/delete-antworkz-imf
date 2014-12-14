/*! @file   BasicNameHash.h   BaseLib BasicNameHash class declaration
 */
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
/*! @class BasicNameHash BasicNameHash.h <base/BasicNameHash.h>
 * @brief The BasicNameHash class supports a hash of BasicName keys to T values.
 * @see BasicName
 * @ingroup BaseLib
 * @since BasicNameHash was started in v2.03
 */

#endif // BASICNAMEHASH_H
