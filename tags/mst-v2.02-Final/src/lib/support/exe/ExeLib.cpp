/*! @file   ExeLib.cpp EclipseIR ExeLib definitions
 */
#include "ExeLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

ExeLib * gpExe = &(Exe::instance());

/*! @fn ExeLib::ExeLib(void)
 *
 * @brief ExeLib::ExeLib initializes the ExeLib class.
 */
ExeLib::ExeLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

#if 0
/*! @fn void executeUnitTest(void)
 *
 * @brief The executeUnitTest() function is global to ExeLib
 *
 * This global extern "C" function can be Exeolved and executed
 * after being loaded via QLibrary.
 */
extern "C" EXESHARED_EXPORT void executeUnitTest(void)
{
    Exe::instance()->executeUnitTest();
}

/*! @fn void ExeLib::executeUnitTest(void)
 *
 * @internal
 */
void ExeLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    QUT_EXPECTEQ(VER_MAJOR, Exe::instance()->version().getMajor());
    //QUT_INSTANCE(AnyOtherClasses);
}
#endif
