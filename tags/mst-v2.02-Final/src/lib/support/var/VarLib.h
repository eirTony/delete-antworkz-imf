/*! @file   VarLib.h   Eclipse VarLib declaration
 */
#ifndef VarLib_H
#define VarLib_H
#define MODULE_NAME "eirVar"
#include "var_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class VarLib
 * @brief The VarLib is the base class in the eirVar library.
 *
 * The VarLib is an Var Eclipse library from which new
 * libraries can be based.
 *
 */
class VARSHARED_EXPORT VarLib : public ModuleInfo
{
public:
    VarLib(void);
    //virtual void executeUnitTest(void);
};

/*! @typedef Var
 *
 * @brief Is the Singleton instance of VarLib
 */
typedef Singleton<VarLib> Var;

#endif // VarLib_H
