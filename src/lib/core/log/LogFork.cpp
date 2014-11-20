#include "LogFork.h"

#include "LogItem.h"
#include "ForkOutputBehavior.h"
#include "ItemFormatBehavior.h"

LogFork::LogFork(const BasicName &name,
                 const QUrl &url)
    : mForkName(name)
    , mUrl(url)
    , mSchemeEcc(url.scheme())
    , mQuery(url.query())
{
    parseUrl(mUrl);
}

bool LogFork::isError(void) const
{
    return ! mErrorString.isEmpty();
}

void LogFork::write(LogItem item)
{
    QString s = mpFormat->formatItem(mFormatName, item);
    mpOutput->write(item.getSeverity(), s);
}

void LogFork::close(void)
{
    mpOutput->close();
}

bool LogFork::parseUrl(const QUrl & url)
{
    if ( ! url.isValid()) return false;
    //ASSERT(mRegisteredEccs.contains(mSchemeEcc));
    typedef QPair<QString, QString> QStringPair;
    const QList<QStringPair> items(mQuery.queryItems());
    foreach (QStringPair item, items)
    {
        BasicName name(item.first);
        QString value(item.second);
        mUrlOptionMap.insert(name, value);
    }

    return true;
}
