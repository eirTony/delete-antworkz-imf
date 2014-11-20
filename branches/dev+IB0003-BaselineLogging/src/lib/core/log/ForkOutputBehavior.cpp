#include "ForkOutputBehavior.h"

#include <QUrlQuery>

#include <type/CharCode.h>

QHash<EightCC, BasicName> ForkOutputBehavior::smEccMetaHash;

ForkOutputBehavior::ForkOutputBehavior(void)
{
}

ForkOutputBehavior * ForkOutputBehavior::forScheme(
                                const EightCC schemeEcc,
                                const LogFork * const fork) // [static]
{
    const char * metaName = qPrintable(smEccMetaHash.value(schemeEcc));
    if ( ! metaName) return 0;
    int metaType = QMetaType::type(metaName);
    if ( ! metaType) return 0;
    ForkOutputBehavior * rtn = (ForkOutputBehavior *)QMetaType::create(metaType);
    if ( ! rtn) return 0;

    rtn->setup(fork, schemeEcc);
    // more TBD
    return rtn;
}

void ForkOutputBehavior::setup(const LogFork * const fork,
                               const EightCC schemeEcc)
{
    // todo
}
