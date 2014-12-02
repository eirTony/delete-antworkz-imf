#include "LogOutputPlugin.h"

#include <base/BasicName.h>

#include "LogFork.h"

LogOutputPlugin::LogOutputPlugin(const BasicName & name,
                                 const BasicName::List & aliases,
                                 LogFork * fork,
                                 QObject * parent)
    : LogOutputInterface(fork, this, parent)
{
}
