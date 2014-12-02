/*! @file   BasicName.h   BaseLib BasicName class declaration
 */
#ifndef BASICNAME_H
#define BASICNAME_H
#include "BaseLib.h"

#include <QList>
#include <QMap>
#include <QString>


class BASESHARED_EXPORT BasicName
{
public:
    typedef QList<BasicName> List;

public:
    BasicName(const QString & name=QString());
    bool isNull(void) const;
    void clear(void);
    void set(const QString & name);
    QString sortable(void) const;

private:
    QString mName;
};
/*! @class BasicName BasicName.h <base/BasicName.h>
 * @brief The BasicName class supports names that mirror programming variable names
 * @ingroup BaseLib
 * @since BasicName was started in v2.03
 * @todo { Investigate whether a variable name consisting of an initial underscore
 * and only numbers following should be valid. }
 *
 * The BasicName class provides strings that their syntax is restricted to
 * those characters allowed in typical programming language variable names.
 * Names must start with an upper or lower case alphabetic character
 * or an underscore character.
 * Subsequent characters may also include numeric characters.
 */

typedef BasicName::List BasicNameList;

#endif // BASICNAME_H
