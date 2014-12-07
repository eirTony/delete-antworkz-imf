#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <base/AbstractPlugin.h>
#include <base/BasicId.h>
#include <base/BasicName.h>
#include <type/CharCode.h>
#include <type/QQDir.h>

class LogOutputPlugin;

class PluginManager
{
public:
    PluginManager(void);
    BasicId::List classList(void) const;
    EightCCList classSchemata(void) const;
    bool Enumerate(const QQDir::List & additionalPaths=QQDir::List());
    AbstractPlugin * classPlugin(const BasicId & pluginClass);
    LogOutputPlugin * logoutputPlugin(const EightCC schema,
          const BasicName::VariantMap & init=BasicName::VariantMap(),
          const BasicName::VariantMap & config=BasicName::VariantMap());
    LogOutputPlugin * logoutputPlugin(const EightCC schema,
                                      const QUrl & url);
    // can we template<LogOutputPlugin *> ?

private:
    bool mAutoEnumerate = false;
};

#endif // PLUGINMANAGER_H
