#include "LogOutputInterface.h"

#include "LogFork.h"
#include "LogOutputPlugin.h"

LogOutputInterface::LogOutputInterface(LogFork * fork,
                                       LogOutputPlugin * plugin,
                                       QObject *parent) :
    QObject(parent)
{
}
