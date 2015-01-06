/*! @file   WorkLib.cpp EclipseIR WorkLib definitions
 */
#include "WorkLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

//WorkLib * gpWork = Work::instance();

/*! @fn WorkLib::WorkLib(void)
 *
 * @brief WorkLib::WorkLib initializes the WorkLib class.
 */
WorkLib::WorkLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}
