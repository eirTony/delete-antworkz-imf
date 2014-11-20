/*! @file   KidLib.h KidLib class declaration
 */
#ifndef KidLib_H
#define KidLib_H
#define MODULE_NAME "eirKid"
#include "Kid_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class KidLib
 * @brief The KidLib is the base class in the eirKid library.
 *
 * The KidLib is an Kid Eclipse library from which new
 * libraries can be based.
 *
 */
class KIDSHARED_EXPORT KidLib : public ModuleInfo
{
public:
    KidLib(void);
    //virtual void executeUnitTest(void);
};

/*! @typedef Kid
 *
 * @brief Is the Singleton instance of KidLib
 */
typedef Singleton<KidLib> Kid;

#endif // KidLib_H
