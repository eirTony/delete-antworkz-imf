#include "ForkOutputBehavior.h"

#include <QUrlQuery>

#include <type/CharCode.h>

#include "LogFork.h"

QHash<EightCC, QByteArray> ForkOutputBehavior::smEccMetaHash;

ForkOutputBehavior::ForkOutputBehavior(void)
{
}

void ForkOutputBehavior::setFork(LogFork * const fork)
{
    mpFork = fork;
}

void ForkOutputBehavior::setUrl(const QUrl & url)
{
    mUrl = url;
}

void ForkOutputBehavior::setScheme(const EightCC scheme)
{
    mSchemeEcc = scheme;
}

void ForkOutputBehavior::registerSchemes(const EightCCList & schemeEccs,
                                         const QByteArray & metaName) // [static]
{
    foreach (EightCC ecc, schemeEccs)
        smEccMetaHash.insert(ecc, metaName);
}


ForkOutputBehavior *
    ForkOutputBehavior::forScheme(const EightCC schemeEcc) // [static]
{
    QByteArray metaName = smEccMetaHash.value(schemeEcc);
    if (metaName.isEmpty()) return 0;
    int metaType = QMetaType::type(metaName);
    if ( ! metaType) return 0;
    ForkOutputBehavior * rtn
            = (ForkOutputBehavior *)QMetaType::create(metaType);
    // more TBD?
    return rtn;
}
