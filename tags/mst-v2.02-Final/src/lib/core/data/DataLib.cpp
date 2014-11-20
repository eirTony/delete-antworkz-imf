/*! @file   DataLib.cpp EclipseIR DataLib definitions
 */
#include "DataLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

DataLib * gpData = &(Data::instance());

/*! @fn DataLib::DataLib(void)
 *
 * @brief DataLib::DataLib initializes the DataLib class.
 */
DataLib::DataLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

#if 0
/*! @fn void executeUnitTest(void)
 *
 * @brief The executeUnitTest() function is global to DataLib
 *
 * This global extern "C" function can be resolved and executed
 * after being loaded via QLibrary.
 */
extern "C" DATASHARED_EXPORT void executeUnitTest(void)
{
    Data::instance()->executeUnitTest();
}

/*! @fn void DataLib::executeUnitTest(void)
 *
 * @internal
 */
void DataLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    QUT_EXPECTEQ(VER_MAJOR, Data::instance()->version().getMajor());
    //QUT_INSTANCE(AnyOtherClasses);
}
#endif
