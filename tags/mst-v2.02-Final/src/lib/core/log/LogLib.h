/*! @file   LogLib.h   Eclipse LogLib declaration
 */
#ifndef LogLib_H
#define LogLib_H
#include "log_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class LogLib
 * @brief The LogLib is the base class in the eirLog library.
 *
 * The LogLib is an Log Eclipse library from which new
 * libraries can be based.
 *
 */
class LOGSHARED_EXPORT LogLib : public ModuleInfo
{
public:
    LogLib(void);
    //virtual void executeUnitTest(void);
};

/*! @typedef Log
 *
 * @brief Is the Singleton instance of LogLib
 */
typedef Singleton<LogLib> Log;

#endif // LogLib_H
