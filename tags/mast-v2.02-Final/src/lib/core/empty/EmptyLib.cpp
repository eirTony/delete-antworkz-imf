/*! @file   EmptyLib.cpp EclipseIR EmptyLib definitions
 */
#include "EmptyLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

#include <quick/QuickUnitTest.h>

EmptyLib * gpEmpty = Empty::instance();
/*! @fn void executeUnitTest(void)
 *
 * @brief The executeUnitTest() function is global to EmptyLib
 *
 * This global extern "C" function can be resolved and executed
 * after being loaded via QLibrary.
 */
extern "C" EMPTYSHARED_EXPORT void executeUnitTest(void)
{
    Empty::instance()->executeUnitTest();
}


/*! @fn EmptyLib::EmptyLib(void)
 *
 * @brief EmptyLib::EmptyLib initializes the EmptyLib class.
 */
EmptyLib::EmptyLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

/*! @fn void EmptyLib::executeUnitTest(void)
 *
 * @internal
 */
void EmptyLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    QUT_EXPECTEQ(VER_MAJOR, Empty::instance()->version().getMajor());
    //QUT_INSTANCE(AnyOtherClasses);
}
