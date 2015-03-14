/*! @file   MsgLib.h   Eclipse MsgLib declaration
 */
#ifndef MsgLib_H
#define MsgLib_H
#define MODULE_NAME "eirMsg"
#include "Msg_global.h"

#include <QVariantMap>

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class MsgLib
 * @brief The MsgLib is the base class in the eirMsg library.
 *
 * The MsgLib is an Msg Eclipse library from which new
 * libraries can be based.
 *
 */
class MSGSHARED_EXPORT MsgLib : public ModuleInfo
{
public:
    MsgLib(void);
//    virtual void executeUnitTest(void);
};

/*! @typedef Msg
 *
 * @brief Is the StaticSingleton instance of MsgLib
 */
typedef StaticSingleton<MsgLib> Msg;

#endif // MsgLib_H
