/*! @file   CoreLib.h   Eclipse CoreLib declaration
 */
#ifndef CoreLib_H
#define CoreLib_H
#define MODULE_NAME "eirCore"
#include "Core_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class CoreLib
 * @brief The CoreLib is the base class in the eirCore library.
 *
 * The CoreLib is an Core Eclipse library from which new
 * libraries can be based.
 *
 */
class CORESHARED_EXPORT CoreLib : public ModuleInfo
{
public:
    CoreLib(void);
    //virtual void executeUnitTest(void);
};

/*! @typedef Core
 *
 * @brief Is the Singleton instance of CoreLib
 */
typedef Singleton<CoreLib> Core;

#endif // CoreLib_H
