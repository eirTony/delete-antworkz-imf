/*! @file   WorkLib.h   Eclipse WorkLib declaration
 */
#ifndef WORKLIB_H
#define WORKLIB_H
#define MODULE_NAME "eirWork"
#include "Work_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class WorkLib
 * @brief The WorkLib is the base class in the eirWork library.
 *
 * The WorkLib is an Work Eclipse library from which new
 * libraries can be based.
 *
 */
class WORKSHARED_EXPORT WorkLib : public ModuleInfo
{
public:
    WorkLib(void);
};

/*! @typedef Work
 *
 * @brief Is the StaticSingleton instance of WorkLib
 */
typedef StaticSingleton<WorkLib> Work;

#endif // WORKLIB_H
