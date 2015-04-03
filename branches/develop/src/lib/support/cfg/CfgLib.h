/*! @file   CfgLib.h   Eclipse CfgLib declaration
 */
#ifndef CfgLib_H
#define CfgLib_H
#define MODULE_NAME "eirCfg"
#include "Cfg_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class CfgLib
 * @brief The CfgLib is the base class in the eirCfg library.
 *
 * The CfgLib is an Cfg Eclipse library from which new
 * libraries can be based.
 *
 */
class CFGSHARED_EXPORT CfgLib : public ModuleInfo
{
public:
    CfgLib(void);
    //virtual void executeUnitTest(void);
};

/*! @typedef Cfg
 *
 * @brief Is the StaticSingleton instance of CfgLib
 */
typedef StaticSingleton<CfgLib> Cfg;

#endif // CfgLib_H
