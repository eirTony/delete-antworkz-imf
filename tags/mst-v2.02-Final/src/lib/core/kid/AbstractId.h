/*! @file   AbstractId.h AbstractId class declaration
 */
#ifndef ABSTRACTID_H
#define ABSTRACTID_H

#include <QString>

class BaseNameIdBehavior;

class AbstractId : public QString
{
protected:
    AbstractId(BaseNameIdBehavior * behavior,
               const QString &name);

private:
    BaseNameIdBehavior * mpBehavior;
};

#endif // ABSTRACTID_H
