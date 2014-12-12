#include "LogOutputPlugin.h"

#include <base/BasicName.h>
#include <base/BasicId.h>

#include "LogFork.h"

LogOutputPlugin::LogOutputPlugin(const BasicName & name,
                                 LogFork * fork,
                                 QObject * parent)
    : LogOutputInterface(fork,
                         this,
                         parent)
    , AbstractPlugin("LogOutput",
                     name,
                     EightCCList()
                        << EightCC(QString(name).toLocal8Bit().constData()),
                     "LogOutputPlugin") {}

LogOutputPlugin::LogOutputPlugin(const BasicName & name,
                                 const EightCCList & schemata,
                                 LogFork * fork,
                                 QObject * parent)
    : LogOutputInterface(fork,
                         this,
                         parent)
    , AbstractPlugin("LogOutput",
                     name,
                     schemata,
                     "LogOutputPlugin") {}
