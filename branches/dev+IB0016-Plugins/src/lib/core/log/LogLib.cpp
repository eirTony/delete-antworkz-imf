/*! @file   LogLib.cpp EclipseIR LogLib definitions
 */
#include "LogLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

LogLib * gpLog = &(Log::instance());

/*! @fn LogLib::LogLib(void)
 *
 * @brief LogLib::LogLib initializes the LogLib class.
 */
LogLib::LogLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

#if 0
/*! @fn void executeUnitTest(void)
 *
 * @brief The executeUnitTest() function is global to LogLib
 *
 * This global extern "C" function can be resolved and executed
 * after being loaded via QLibrary.
 */
extern "C" LOGSHARED_EXPORT void executeUnitTest(void)
{
    Log::instance()->executeUnitTest();
}

/*! @fn void LogLib::executeUnitTest(void)
 *
 * @internal
 */
void LogLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    QUT_EXPECTEQ(VER_MAJOR, Log::instance()->version().getMajor());
    //QUT_INSTANCE(AnyOtherClasses);
}
#endif
