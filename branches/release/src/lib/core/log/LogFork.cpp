#include "LogFork.h"

#include "LogItem.h"

LogFork::LogFork(const BasicName &name,
                 const QUrl &url)
    : mName(name)
    , mUrl(url)
{
}

void LogFork::write(LogItem item)
{

}
