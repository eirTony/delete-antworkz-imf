/*! @file   BasicName.cpp BaseLib BasicName class definitions
 */

#include "BasicName.h"

#include <QtDebug>

BasicName::BasicName(void) {}

BasicName::BasicName(const QString & name)
{
    set(name);
}

BasicName::BasicName(const char * const name)
{
    set(QString::fromLocal8Bit(name));
}

bool BasicName::isNull(void) const
{
    return mName.isNull();
}

bool BasicName::isEmpty(void) const
{
    return mName.isEmpty();
}

void BasicName::clear(void)
{
    mName.clear();
}

void BasicName::set(const QString & name)
{
    mName.clear();
    qWarning("TODO: void BasicName::set(const QString & name)");
    mName.append(name);
}

QString BasicName::sortable(void) const
{
    // Future:  refactor op== op< with CaseInsensitive .compare()
    //          and/or class InsensitiveString
    return mName.toLower();
}

bool BasicName::operator == (const BasicName & other) const
{
    return sortable() == other.sortable();
}

bool BasicName::operator <  (const BasicName & other) const
{
    return sortable() <  other.sortable();
}

QString BasicName::operator () (void) const
{
    return mName;
}

BasicName::operator QString (void) const
{
    return mName;
}
