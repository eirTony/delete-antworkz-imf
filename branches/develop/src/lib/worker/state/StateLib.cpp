/*! @file   StateLib.cpp EclipseIR StateLib definitions
 */
#include "StateLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

//#include <quick/QuickUnitTest.h>

//StateLib * gpState = State::instance();
/*! @fn void executeUnitTest(void)
 *
 * @brief The executeUnitTest() function is global to StateLib
 *
 * This global extern "C" function can be resolved and executed
 * after being loaded via QLibrary.
 */
/*
extern "C" StateSHARED_EXPORT void executeUnitTest(void)
{
    State::instance()->executeUnitTest();
}
*/

/*! @fn StateLib::StateLib(void)
 *
 * @brief StateLib::StateLib initializes the StateLib class.
 */
StateLib::StateLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

/*! @fn void StateLib::executeUnitTest(void)
 *
 * @internal
 */
/*
void StateLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    QUT_EXPECTEQ(VER_MAJOR, State::instance()->version().getMajor());
    //QUT_INSTANCE(AnyOtherClasses);
}
*/
