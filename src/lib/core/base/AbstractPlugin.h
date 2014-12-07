#ifndef ABSTRACTPLUGIN_H
#define ABSTRACTPLUGIN_H
#include "BaseLib.h"

#include "ModuleInfo.h"

#include <QFileInfo>
#include <QList>
#include <QMap>
#include <QUrl>
#include <QUrlQuery>
#include <QString>

#include <type/CharCode.h>

#include "BasicName.h"
#include "BasicId.h"
#include "MetaName.h"

class QPluginLoader;

class BASESHARED_EXPORT AbstractPlugin : public ModuleInfo
{
public:
    bool load(const BasicId & id,
              const QUrl & url);
    bool load(const BasicId & id,
              const BasicName::VariantMap init=BasicName::VariantMap(),
              const BasicName::VariantMap config=BasicName::VariantMap());
    bool create(const MetaName & meta,
                const QUrl & url);
    bool create(const MetaName & meta,
                const BasicName::VariantMap init=BasicName::VariantMap(),
                const BasicName::VariantMap config=BasicName::VariantMap());
    bool isError(void) const;
    QString errorString(void) const;
    bool isLoaded(void) const;
    bool setUrl(const QUrl & url);
    bool initialize(const BasicName::VariantMap init);
    bool configure(const BasicName::VariantMap config);


protected:
    AbstractPlugin(const BasicId & prefix,
                   const BasicName & name,
                   const EightCCList & schemata,
                   const MetaName & meta=MetaName());
    QObject * instance(void) const;

private:
    QString mErrorString;
    QObject * mpInstance = 0;
    QPluginLoader * mpLoader = 0;
    BasicId mId;
    MetaName mMetaName;
    QUrl mUrl;
    QUrlQuery mQuery;
    BasicName::VariantMap mInit;
    BasicName::VariantMap mConfig;

private: // static
    friend class PluginManager;
    static QList<BasicId> smPrefixIdList;
    static QMap<EightCCList, BasicId> smSchemaPluginIdMap;
    static QMap<BasicId, QFileInfo> smPluginIdFileInfoMap;
    static QMap<BasicId, MetaName> smPluginIdMetaNameMap;
};

#endif // ABSTRACTPLUGIN_H
