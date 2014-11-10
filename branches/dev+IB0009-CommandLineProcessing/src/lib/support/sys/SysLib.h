/*! @file   SysLib.h   Eclipse SysLib declaration
 */
#ifndef SysLib_H
#define SysLib_H
#define MODULE_NAME "eirSys"
#include "Sys_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class SysLib
 * @brief The SysLib is the base class in the eirSys library.
 *
 * The SysLib is an Sys Eclipse library from which new
 * libraries can be based.
 *
 */
class SYSSHARED_EXPORT SysLib : public ModuleInfo
{
public:
    SysLib(void);
    //virtual void executeUnitTest(void);
};

/*! @typedef Sys
 *
 * @brief Is the Singleton instance of SysLib
 */
typedef Singleton<SysLib> Sys;

#endif // SysLib_H
