#include "ForkOutputBehavior.h"

#include <QUrlQuery>

#include <type/CharCode.h>

ForkOutputBehavior::ForkOutputBehavior(const BasicNameList & schemeName,
                                       const BasicName metaName)
    : mWritable(false)
{
}

bool ForkOutputBehavior::setUrlVars(const QUrl & url)
{
    mUrl = url;
    mSchemeEcc = EightCC(url.scheme());
    //ASSERT(mRegisteredEccs.contains(mSchemeEcc));
    const QUrlQuery query(url);
    typedef QPair<QString, QString> QStringPair;
    const QList<QStringPair> items(query.queryItems());
    foreach (QStringPair item, items)
    {
        BasicName name(item.first);
        QString value(item.second);
        mUrlOptionMap.insert(name, value);
    }
}
