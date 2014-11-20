/*! @file   EmptyLib.h   Eclipse EmptyLib declaration
 */
#ifndef EmptyLib_H
#define EmptyLib_H
#define MODULE_NAME "eirEmpty"
#include "empty_global.h"

#include <base/ModuleInfo.h>
#include <type/Singleton.h>

/*! @class EmptyLib
 * @brief The EmptyLib is the base class in the eirEmpty library.
 *
 * The EmptyLib is an empty Eclipse library from which new
 * libraries can be based.
 *
 */
class EMPTYSHARED_EXPORT EmptyLib : public ModuleInfo
{
public:
    EmptyLib(void);
    virtual void executeUnitTest(void);
};

/*! @typedef Empty
 *
 * @brief Is the Singleton instance of EmptyLib
 */
typedef Singleton<EmptyLib> Empty;

#endif // EmptyLib_H
