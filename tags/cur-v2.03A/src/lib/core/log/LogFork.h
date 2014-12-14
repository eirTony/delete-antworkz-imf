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
    bool start(void);
    bool isStarted(void) const;
    bool isError(void) const;
    QString errorString(void) const;
    void write(LogItem item);
    void close(void);
    QVariant urlOption(const BasicName & name);
    QUrl url(void) const;

    bool setStarted(const bool yes=true);
    bool setError(const QString & message=QString());
    bool isNotMinMax(const Severity severity);

private:
    bool parseUrl(const QUrl & url);
    QString parseLineend(const QString & option);

private:
    QString mErrorString;
    bool mIsStarted = false;
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
    QString mLineendString = (QChar(QChar::CarriageReturn)
                              + QChar(QChar::LineFeed));

    // helpers
    ForkOutputBehavior * mpOutput = 0;
    ItemFormatBehavior * mpFormat = 0;
};
/*! @class LogFork "LogFork.h" <log/LogFork.h>
 * @todo LogSeverityFilter
 * @since Started in v2.03
 */

#endif // LOGFORK_H
