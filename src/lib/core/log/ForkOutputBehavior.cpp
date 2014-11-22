#include "ForkOutputBehavior.h"

#include <QUrlQuery>

#include <type/CharCode.h>

#include "LogFork.h"

QHash<EightCC, QByteArray> ForkOutputBehavior::smEccMetaHash;

ForkOutputBehavior::ForkOutputBehavior(void)
{
}

void ForkOutputBehavior::setFork(const LogFork * const fork)
{

}

void ForkOutputBehavior::setUrl(const QUrl & url)
{

}

void ForkOutputBehavior::setScheme(const EightCC scheme)
{

}

ForkOutputBehavior *
    ForkOutputBehavior::forScheme(const EightCC schemeEcc,
                                  const LogFork * const fork) // [static]
{
    QByteArray metaName = smEccMetaHash.value(schemeEcc);
    if (metaName.isEmpty()) return 0;
    int metaType = QMetaType::type(metaName);
    if ( ! metaType) return 0;
    ForkOutputBehavior * rtn
            = (ForkOutputBehavior *)QMetaType::create(metaType);
    if ( ! rtn) return 0;


    // more TBD?
    return rtn;
}
