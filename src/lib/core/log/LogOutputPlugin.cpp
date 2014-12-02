#include "LogOutputPlugin.h"

#include <base/BasicName.h>
#include <base/BasicId.h>

#include "LogFork.h"

LogOutputPlugin::LogOutputPlugin(const BasicName & name,
                                 const BasicNameList & aliases,
                                 LogFork * fork,
                                 QObject * parent)
    : LogOutputInterface(fork, this, parent)
    , AbstractPlugin("LogOutput", name, aliases)
{
}
