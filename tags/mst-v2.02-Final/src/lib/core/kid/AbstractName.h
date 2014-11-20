/*! @file   AbstractName.h AbstractName class declaration
 */
#ifndef ABSTRACTNAME_H
#define ABSTRACTNAME_H

#include <QString>

class BaseNameIdBehavior;

class AbstractName : public QString
{
protected:
    AbstractName(BaseNameIdBehavior * behavior,
                 const QString & name);
private:
    BaseNameIdBehavior * mpBehavior;
};

#endif // ABSTRACTNAME_H
