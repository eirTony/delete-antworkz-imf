/*! @file AbstractName.cpp AbstractName class definitions
 */

#include "AbstractName.h"

#include "BaseNameIdBehavior.h"

AbstractName::AbstractName(BaseNameIdBehavior * behavior,
                           const QString & name)
    : mpBehavior(behavior)
{
    mpBehavior->initializeName(name);
}
