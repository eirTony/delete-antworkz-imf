/*! @file   ExeLib.h   Eclipse ExeLib declaration
 */
#ifndef ExeLib_H
#define ExeLib_H
#define MODULE_NAME "eirExe"
#include "Exe_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class ExeLib
 * @brief The ExeLib is the base class in the eirExe library.
 *
 * The ExeLib is an Exe Eclipse library from which new
 * libraries can be based.
 *
 */
class EXESHARED_EXPORT ExeLib : public ModuleInfo
{
public:
    ExeLib(void);
    //virtual void executeUnitTest(void);
};

/*! @typedef Exe
 *
 * @brief Is the StaticSingleton instance of ExeLib
 */
typedef StaticSingleton<ExeLib> Exe;

#endif // ExeLib_H
