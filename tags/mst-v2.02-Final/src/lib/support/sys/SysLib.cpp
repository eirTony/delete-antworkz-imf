/*! @file   SysLib.cpp EclipseIR SysLib definitions
 */
#include "SysLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

SysLib * gpSys = &(Sys::instance());

/*! @fn SysLib::SysLib(void)
 *
 * @brief SysLib::SysLib initializes the SysLib class.
 */
SysLib::SysLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

#if 0
/*! @fn void executeUnitTest(void)
 *
 * @brief The executeUnitTest() function is global to SysLib
 *
 * This global extern "C" function can be Sysolved and executed
 * after being loaded via QLibrary.
 */
extern "C" SYSSHARED_EXPORT void executeUnitTest(void)
{
    Sys::instance()->executeUnitTest();
}

/*! @fn void SysLib::executeUnitTest(void)
 *
 * @internal
 */
void SysLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    QUT_EXPECTEQ(VER_MAJOR, Sys::instance()->version().getMajor());
    //QUT_INSTANCE(AnyOtherClasses);
}
#endif
