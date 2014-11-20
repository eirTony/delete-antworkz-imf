/*! @file   VarLib.cpp EclipseIR VarLib definitions
 */
#include "VarLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

VarLib * gpVar = &(Var::instance());

/*! @fn VarLib::VarLib(void)
 *
 * @brief VarLib::VarLib initializes the VarLib class.
 */
VarLib::VarLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

#if 0
/*! @fn void executeUnitTest(void)
 *
 * @brief The executeUnitTest() function is global to VarLib
 *
 * This global extern "C" function can be resolved and executed
 * after being loaded via QLibrary.
 */
extern "C" VARSHARED_EXPORT void executeUnitTest(void)
{
    Var::instance()->executeUnitTest();
}

/*! @fn void VarLib::executeUnitTest(void)
 *
 * @internal
 */
void VarLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    QUT_EXPECTEQ(VER_MAJOR, Var::instance()->version().getMajor());
    //QUT_INSTANCE(AnyOtherClasses);
}
#endif
