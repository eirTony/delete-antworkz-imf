/*! @file   BasicNameHash.h   BaseLib BasicNameHash class declaration
 */
#ifndef BASICNAMEHASH_H
#define BASICNAMEHASH_H

#include <QHash>
#include "BasicName.h"

template <class T> class BasicNameHash : public QHash<BasicName, T>
{
public:
    BasicNameHash(void) {}
};
/*! @class BasicNameHash BasicNameHash.h <base/BasicNameHash.h>
 * @brief The BasicNameHash class supports a hash of BasicName keys to T values.
 * @see BasicName
 * @ingroup BaseLib
 * @since BasicNameHash was started in v2.03
 */

#endif // BASICNAMEHASH_H
