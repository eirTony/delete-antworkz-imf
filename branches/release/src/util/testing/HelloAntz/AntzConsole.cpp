#include "AntzConsole.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QTimer>

AntzConsole::AntzConsole(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

void AntzConsole::doStart(void)
{
    SerialExecutable::writeLine("Hello Antz!");
    SerialExecutable::writeError("This may be an error?!");
    QTimer::singleShot(5000, this, SLOT(quit()));
}
