#ifndef LOGFORK_H
#define LOGFORK_H

#include <QUrl>
#include <QUrlQuery>

#include <base/BasicName.h>
#include <base/BasicNameHash.h>

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

private:
    BasicName mName;
    QUrl mUrl;
    QUrlQuery mQuery;
    QString mErrorString;
    BasicName mFormatName;
    bool mIsStarted = false;
    QString mLineEndString = (QChar(QChar::CarriageReturn)
                              + QChar(QChar::LineFeed));
    bool mAutoFlush = false;
    bool mReportPass = false;
    ForkOutputBehavior * mpOutput = 0;
    ItemFormatBehavior * mpFormat = 0;
    //LogSeverityFilter mSeverityFilter;
};

#endif // LOGFORK_H
