/*! @file   CfgLib.cpp EclipseIR CfgLib definitions
 */
#include "CfgLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

CfgLib * gpCfg = &(Cfg::instance());

/*! @fn CfgLib::CfgLib(void)
 *
 * @brief CfgLib::CfgLib initializes the CfgLib class.
 */
CfgLib::CfgLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

#if 0
/*! @fn void executeUnitTest(void)
 *
 * @brief The executeUnitTest() function is global to CfgLib
 *
 * This global extern "C" function can be resolved and executed
 * after being loaded via QLibrary.
 */
extern "C" CFGSHARED_EXPORT void executeUnitTest(void)
{
    Cfg::instance()->executeUnitTest();
}


/*! @fn void CfgLib::executeUnitTest(void)
 *
 * @internal
 */
void CfgLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    QUT_EXPECTEQ(VER_MAJOR, Cfg::instance()->version().getMajor());
    //QUT_INSTANCE(AnyOtherClasses);
}
#endif
