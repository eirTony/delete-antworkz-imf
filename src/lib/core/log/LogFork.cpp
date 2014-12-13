#include "LogFork.h"

#include "LogItem.h"
#include "ForkOutputBehavior.h"
#include "ItemFormatBehavior.h"

LogFork::LogFork(const BasicName &name,
                 const QUrl &url)
    : mForkName(name)
    , mSchemeEcc(url.scheme())
    , mUrl(url)
    , mQuery(url.query())
{
    parseUrl(mUrl);
    mpOutput = ForkOutputBehavior::forScheme(mSchemeEcc);
    if (mpOutput)
    {
        mpOutput->setFork(this);
        mpOutput->setScheme(mSchemeEcc);
        mpOutput->setUrl(mUrl);
    }
    else
    {
        setError("Unable to create output");
    }
}

bool LogFork::start(void)
{
    return setStarted(mpOutput->open());
}

bool LogFork::isStarted(void) const
{
    return mIsStarted;
}

bool LogFork::isError(void) const
{
    return ! mErrorString.isEmpty();
}

QString LogFork::errorString(void) const
{
    return mErrorString;
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

bool LogFork::setError(const QString & message)
{
    mErrorString = message;
    return mErrorString.isEmpty();
}

bool LogFork::isNotMinMax(const Severity severity)
{
    return severity > mMaxSeverity || severity < mMinSeverity;
}

bool LogFork::setStarted(const bool started)
{
    return mIsStarted = started;
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

    // Interpret Query Values
    QVariant varFormat = urlOption("Format");
    QVariant varMinSeverity = urlOption("MinSeverity");
    QVariant varMaxSeverity = urlOption("MinSeverity");
    //mSeverityFilter "Filter"
    QVariant varAutoFlush = urlOption("MaxSeverity");
    QVariant varReportPass = urlOption("ReportPass");
    if ( ! varFormat.isNull())
        mFormatName = varFormat.toString();
    if ( ! varMinSeverity.isNull())
        mMinSeverity = Severity(varMinSeverity.toString());
    if ( ! varMaxSeverity.isNull())
        mMaxSeverity = Severity(varMaxSeverity.toString());
    if ( ! varAutoFlush.isNull())
        mAutoFlush = varAutoFlush.toBool();
    if ( ! varReportPass.isNull())
        mReportPass = varReportPass.toBool();

    return true;
}

QVariant LogFork::urlOption(const BasicName & name)
{
    return QVariant();
}

QString LogFork::parseLineend(const QString & option)
{
    return QChar(QChar::CarriageReturn) + QChar(QChar::LineFeed);
}

QUrl LogFork::url(void) const
{
    return mUrl;
}
