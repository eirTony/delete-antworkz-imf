/*! @file AbstractId.cpp AbstractId class definitions
 */

#include "AbstractId.h"

#include "BaseNameIdBehavior.h"

AbstractId::AbstractId(BaseNameIdBehavior * behavior,
                       const QString & name)
    : mpBehavior(behavior)
{
    mpBehavior->initializeId(name);
}
