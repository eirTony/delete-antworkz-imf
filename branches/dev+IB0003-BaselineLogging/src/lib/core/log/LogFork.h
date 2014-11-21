#ifndef LOGFORK_H
#define LOGFORK_H

#include <QUrl>
#include <QUrlQuery>

#include <base/BasicName.h>
#include <base/BasicNameHash.h>
#include <type/CharCode.h>

#include "Severity.h"

class ForkOutputBehavior;
class ItemFormatBehavior;
class LogItem;

class LogFork
{
public:
    LogFork(const BasicName & name,
            const QUrl & url);
    bool isWritable(void) const;
    bool start(void);
    bool isStarted(void) const;
    bool isError(void) const;
    QString errorString(void) const;
    void write(LogItem item);
    void close(void);

private:
    bool parseUrl(const QUrl & url);
    QVariant urlOption(const BasicName & name);
    QString parseLineend(const QString & option);

private:
    QString mErrorString;
    bool mIsStarted = false;
    bool mWritable = false;
    BasicName mForkName;

    // url
    EightCC mSchemeEcc;
    QUrl mUrl;
    QUrlQuery mQuery;
    BasicNameHash<QString> mUrlOptionMap;

    // query results
    BasicName mFormatName;
    Severity mMinSeverity = Severity("Info");
    Severity mMaxSeverity = Severity("Maximum");
    //LogSeverityFilter mSeverityFilter;
    bool mAutoFlush = false;
    bool mReportPass = false;
    QString mLineendString;

    // helpers
    ForkOutputBehavior * mpOutput = 0;
    ItemFormatBehavior * mpFormat = 0;
};
/*! @class LogFork "LogFork.h" <log/LogFork.h>
 * @todo LogSeverityFilter
 * @since Started in v2.03
 */

#endif // LOGFORK_H
