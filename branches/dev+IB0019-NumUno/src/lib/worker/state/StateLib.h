/*! @file   StateLib.h   Eclipse StateLib declaration
 */
#ifndef StateLib_H
#define StateLib_H
#define MODULE_NAME "eirState"
#include "state_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class StateLib
 * @brief The StateLib is the base class in the eirState library.
 *
 * The StateLib is an State Eclipse library from which new
 * libraries can be based.
 *
 */
class STATESHARED_EXPORT StateLib : public ModuleInfo
{
public:
    StateLib(void);
    //virtual void executeUnitTest(void);
};

/*! @typedef State
 *
 * @brief Is the Singleton instance of StateLib
 */
typedef Singleton<StateLib> State;

#endif // StateLib_H
