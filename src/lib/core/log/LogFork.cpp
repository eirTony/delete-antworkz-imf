#include "LogFork.h"

#include "LogItem.h"
#include "ForkOutputBehavior.h"
#include "ItemFormatBehavior.h"

LogFork::LogFork(const BasicName &name,
                 const QUrl &url)
    : mName(name)
    , mUrl(url)
{
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
