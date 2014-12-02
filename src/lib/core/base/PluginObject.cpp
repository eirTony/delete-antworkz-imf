/*! @file PluginObject.h    BaseLib PluginObject class definition */
#include "PluginObject.h"

PluginObject::PluginObject(const QString & name,
                           const QString & type,
                           QObject * fallback)
    : QPluginLoader(name, this)
    , ModuleInfo(type+name)
    , mPluginType(type)
    , mPluginName(name)
{
    setVersion(); // for ModuleInfo

    if (fallback)
    {
        QObject * parent = fallback->parent();
        mpFallback = fallback;
        setParent(parent);
        mpFallback->setParent(this);
    }
    else
    {
        setError("No fallback");
    }


    mpInstance = QPluginLoader::instance();
    if ( ! mpInstance) mpInstance = mpFallback;
    if ( ! mpInstance)
        setError("Unable to load "+type+name+" and no fallback");
}

QObject * PluginObject::instance(void) const
{
    return mpInstance;
}

bool PluginObject::isError(void) const
{
    return ! mError.isEmpty();
}

QString PluginObject::errorString(void) const
{
    return mError;
}

void PluginObject::setError(const QString & message)
{
    mError = message;
    emit error(message);
}
