/*! @file   CoreLib.cpp EclipseIR CoreLib definitions
 */
#include "CoreLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>


/*! @fn CoreLib::CoreLib(void)
 *
 * @brief CoreLib::CoreLib initializes the CoreLib class.
 */
CoreLib::CoreLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

#if 0
CoreLib * gpCore = Core::instance();
/*! @fn void executeUnitTest(void)
 *
 * @brief The executeUnitTest() function is global to CoreLib
 *
 * This global extern "C" function can be resolved and executed
 * after being loaded via QLibrary.
 */
extern "C" CORESHARED_EXPORT void executeUnitTest(void)
{
    Core::instance()->executeUnitTest();
}

/*! @fn void CoreLib::executeUnitTest(void)
 *
 * @internal
 */
void CoreLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    QUT_EXPECTEQ(VER_MAJOR, Core::instance()->version().getMajor());
    //QUT_INSTANCE(AnyOtherClasses);
}
#endif
