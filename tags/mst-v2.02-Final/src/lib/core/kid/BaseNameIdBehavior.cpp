/*! @file BaseNameIdBehavior.cpp BaseNameIdBehavior class definitions
 */

#include <base/BaseLog.h>

#include "BaseNameIdBehavior.h"

BaseNameIdBehavior::BaseNameIdBehavior(void)
{
}

QString BaseNameIdBehavior::initializeName(const QString & name) const
{
    BNEEDDO(name);
    return name;
}

QString BaseNameIdBehavior::initializeId(const QString & name) const
{
    BNEEDDO(name);
    return name;
}
