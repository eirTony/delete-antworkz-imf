#ifndef LOGFORK_H
#define LOGFORK_H

#include <QUrl>
#include <QUrlQuery>

#include <base/BasicName.h>
#include <base/BasicNameHash.h>
#include <type/CharCode.h>

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

private:
    bool mIsStarted = false;
    QString mErrorString;
    bool mWritable = false;

    BasicName mName;
    EightCC mSchemeEcc;
    QUrl mUrl;
    QUrlQuery mQuery;
    BasicNameHash<QString> mUrlOptionMap;

    BasicName mFormatName;
    bool mAutoFlush = false;
    bool mReportPass = false;
    ForkOutputBehavior * mpOutput = 0;
    ItemFormatBehavior * mpFormat = 0;
    //LogSeverityFilter mSeverityFilter;


};

#endif // LOGFORK_H
