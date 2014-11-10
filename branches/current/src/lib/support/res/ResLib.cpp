/*! @file   ResLib.cpp EclipseIR ResLib definitions
 */
#include "ResLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

ResLib * gpRes = &(Res::instance());

/*! @fn ResLib::ResLib(void)
 *
 * @brief ResLib::ResLib initializes the ResLib class.
 */
ResLib::ResLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

#if 0
/*! @fn void executeUnitTest(void)
 *
 * @brief The executeUnitTest() function is global to ResLib
 *
 * This global extern "C" function can be resolved and executed
 * after being loaded via QLibrary.
 */
extern "C" RESSHARED_EXPORT void executeUnitTest(void)
{
    Res::instance()->executeUnitTest();
}

/*! @fn void ResLib::executeUnitTest(void)
 *
 * @internal
 */
void ResLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    QUT_EXPECTEQ(VER_MAJOR, Res::instance()->version().getMajor());
    //QUT_INSTANCE(AnyOtherClasses);
}
#endif
