#include "AntzConsole.h"
#ifdef MODULE_NAME
# undef MODULE_NAME
#endif
#define MODULE_NAME "AntzConsole"
#include "Version.h"
#include <CommonVersion.h>

#include <QTimer>

AntzConsole::AntzConsole(void)
{
    ModuleInfo::setVersion();
    QObject::setObjectName("AntzConsole");
}

void AntzConsole::doStart(void)
{
    SerialExecutable::writeLine("Hello Antz!");
    SerialExecutable::writeError("This may be an error?!");
    QTimer::singleShot(5000, this, SLOT(quit()));
}
