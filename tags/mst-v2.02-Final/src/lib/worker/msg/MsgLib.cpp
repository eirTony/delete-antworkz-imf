/*! @file   MsgLib.cpp EclipseIR MsgLib definitions
 */
#include "MsgLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

#include <quick/QuickUnitTest.h>

MsgLib * gpMsg = Msg::instance();
/*! @fn void executeUnitTest(void)
 *
 * @brief The executeUnitTest() function is global to MsgLib
 *
 * This global extern "C" function can be resolved and executed
 * after being loaded via QLibrary.
 */
extern "C" MSGSHARED_EXPORT void executeUnitTest(void)
{
    Msg::instance()->executeUnitTest();
}


/*! @fn MsgLib::MsgLib(void)
 *
 * @brief MsgLib::MsgLib initializes the MsgLib class.
 */
MsgLib::MsgLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

/*! @fn void MsgLib::executeUnitTest(void)
 *
 * @internal
 */
void MsgLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    QUT_EXPECTEQ(VER_MAJOR, Msg::instance()->version().getMajor());
    //QUT_INSTANCE(AnyOtherClasses);
}
