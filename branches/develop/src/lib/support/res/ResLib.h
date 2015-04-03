/*! @file   ResLib.h   Eclipse ResLib declaration
 */
#ifndef ResLib_H
#define ResLib_H
#define MODULE_NAME "eirRes"
#include "Res_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class ResLib
 * @brief The ResLib is the base class in the eirRes library.
 *
 * The ResLib is an Res Eclipse library from which new
 * libraries can be based.
 *
 */
class RESSHARED_EXPORT ResLib : public ModuleInfo
{
public:
    ResLib(void);
    //virtual void executeUnitTest(void);
};

/*! @typedef Res
 *
 * @brief Is the StaticSingleton instance of ResLib
 */
typedef StaticSingleton<ResLib> Res;

#endif // ResLib_H
