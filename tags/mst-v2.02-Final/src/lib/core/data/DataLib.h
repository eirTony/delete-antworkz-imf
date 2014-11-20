/*! @file   DataLib.h   Eclipse DataLib declaration
 */
#ifndef DataLib_H
#define DataLib_H
#define MODULE_NAME "eirData"
#include "data_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class DataLib
 * @brief The DataLib is the base class in the eirData library.
 *
 * The DataLib is an Data Eclipse library from which new
 * libraries can be based.
 *
 */
class DATASHARED_EXPORT DataLib : public ModuleInfo
{
public:
    DataLib(void);
    //virtual void executeUnitTest(void);
};

/*! @typedef Data
 *
 * @brief Is the Singleton instance of DataLib
 */
typedef Singleton<DataLib> Data;

#endif // DataLib_H
