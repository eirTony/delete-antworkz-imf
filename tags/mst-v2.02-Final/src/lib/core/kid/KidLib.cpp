/*! @file   KidLib.cpp EclipseIR KidLib definitions
 */
#include "KidLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

KidLib * gpKid = &(Kid::instance());

/*! @fn KidLib::KidLib(void)
 *
 * @brief KidLib::KidLib initializes the KidLib class.
 */
KidLib::KidLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

#if 0
/*! @fn void executeUnitTest(void)
 *
 * @brief The executeUnitTest() function is global to KidLib
 *
 * This global extern "C" function can be resolved and executed
 * after being loaded via QLibrary.
 */
extern "C" KIDSHARED_EXPORT void executeUnitTest(void)
{
    Kid::instance()->executeUnitTest();
}

/*! @fn void KidLib::executeUnitTest(void)
 *
 * @internal
 */
void KidLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    QUT_EXPECTEQ(VER_MAJOR, Kid::instance()->version().getMajor());
    //QUT_INSTANCE(AnyOtherClasses);
}
#endif
