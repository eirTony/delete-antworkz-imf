#ifndef ABSTRACTPLUGIN_H
#define ABSTRACTPLUGIN_H
#include "BaseLib.h"

#include "ModuleInfo.h"

#include <QFileInfo>
#include <QList>
#include <QMap>
#include <QString>

#include "BasicName.h"
#include "BasicId.h"
#include "MetaName.h"

class QPluginLoader;

class BASESHARED_EXPORT AbstractPlugin : public ModuleInfo
{
public:
    bool load(const BasicId id);
    bool create(const MetaName & meta);
    bool isError(void) const;
    QString errorString(void) const;
    bool isLoaded(void) const;

protected:
    AbstractPlugin(const BasicId & prefix,
                   const BasicName & name,
                   const BasicNameList & aliases);
    QObject * instance(void) const;

private:
    QString mErrorString;
    QObject * mpInstance = 0;
    QPluginLoader * mpLoader = 0;
    BasicId mId;
    MetaName mMetaName;

private: // static
    friend class PluginManager;
    static QMap<BasicId, BasicId> smAliasesPluginIdMap;
    static QMap<BasicId, QFileInfo> smPluginIdFileInfoMap;
    static QList<BasicId> smPrefixList;
};

#endif // ABSTRACTPLUGIN_H
