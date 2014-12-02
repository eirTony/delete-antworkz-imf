/*! @file   BasicNameMap.h   BaseLib BasicNameMap class declaration
 */
#ifndef BASICNAMEMAP_H
#define BASICNAMEMAP_H

#include <QMap>
#include "BasicName.h"

template <class T> class BasicNameMap : public QMap<BasicName, T>
{
public:
    BasicNameMap(void) {}
};
/*! @class BasicNameMap BasicNameMap.h <base/BasicNameMap.h>
 * @brief The BasicNameHash class supports a sorted map of BasicName keys to T values.
 * @see BasicName
 * @ingroup BaseLib
 * @since BasicNameMap was started in v2.03
 */

#endif // BASICNAMEMAP_H
