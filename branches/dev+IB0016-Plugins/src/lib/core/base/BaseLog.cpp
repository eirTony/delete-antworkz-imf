/*! @file   BaseLog.cpp BaseLib BaseLog class definitions
 */

#include "BaseLog.h"
#include <QSharedData>

#include <QtDebug>
#include <QCoreApplication>
#include <QDateTime>
#include <QFile>
#include <QTemporaryFile>
#include <QUrl>
#include <QUrlQuery>

BaseLog::Severity BaseLog::min_sev = Trace;
BaseLog::Severity BaseLog::fatal_sev = Pointer;
QFile * BaseLog::blog_file = 0;

BaseLog::BaseLog(const BaseLog::Severity severity,
                 const QString & format,
                 const QVariant & value1,
                 const QVariant & value2,
                 const QVariant & value3,
                 const QVariant & value4)
{
    QString s = fillString(format, value1, value2, value3, value4);
    QString msg = QString("%1%2 " + s)
            .arg(severityChar(severity))
            .arg(QDateTime::currentDateTime().toString("hh:mm:ss.zzz"));
    write(severity, msg);
}

QString BaseLog::fillString(const QString & format,
                            const QVariant & value1,
                            const QVariant & value2,
                            const QVariant & value3,
                            const QVariant & value4)
{
    QString result(format);
    result.replace("%1", value1.toString());
    result.replace("%2", value2.toString());
    result.replace("%3", value3.toString());
    result.replace("%4", value4.toString());
    return result;
}

void BaseLog::write(const Severity severity,
                    const QString & message)
{
    if (BaseLog::isFatal(severity))
    {
        qCritical(qPrintable(message + " *** FATAL ***"));
        BaseLog::flush();
        qFatal(qPrintable(message + " *** FATAL ***"));
    }
    else if (isError(severity))
        qCritical(qPrintable(message));
    else if (isWarning(severity))
        qWarning(qPrintable(message));
    else if (isMinimum(severity))
        qDebug(qPrintable(message));
}
void BaseLog::flush(void)
{
    if (blog_file)
        blog_file->flush();
}

void BaseLog::setMinimum(const Severity severity)
{
    min_sev = severity;
}

void BaseLog::setFatal(const Severity severity)
{
    fatal_sev = severity;
}

BaseLog::Severity BaseLog::minimumSeverity(void)
{
    return Severity(min_sev);
}

BaseLog::Severity BaseLog::fatalSeverity(void)
{
    return Severity(fatal_sev);
}

bool BaseLog::isMinimum(const Severity severity)
{
    return severity >= min_sev;
}

bool BaseLog::isWarning(const Severity severity)
{
    return severity >= Warning;
}

bool BaseLog::isError(const Severity severity)
{
    return severity >= Error;
}

bool BaseLog::isFatal(const Severity severity)
{
    return severity >= fatal_sev;
}

QFile * BaseLog::blogFile(void)
{
    return blog_file;
}

QString BaseLog::blogFileName(void)
{
    return blog_file ? blog_file->fileName() : QString();
}

void BaseLog::setFile(const QString & fileName)
{
    resetFile();

    if (fileName.trimmed().isEmpty())
    {
        QString templateName("EclipseBlog.tmp");
        if (qApp && ! qApp->applicationName().isEmpty())
            templateName = qApp->applicationName() + "-Blog.tmp";
        blog_file = new QTemporaryFile(templateName);
    }
    else
    {
        blog_file = new QFile(fileName);
    }

    if (blog_file)
    {
        blog_file->open(QIODevice::WriteOnly | QIODevice::Text);
        if (blog_file->isWritable())
            qInstallMessageHandler(&myMsgHandler);
        else
            resetFile();
    }
}

void BaseLog::resetFile(void)
{
    if (blog_file)
    {
        blog_file->flush();
        blog_file->close();
        delete blog_file;
        blog_file = 0;
    }
    qInstallMessageHandler(0);
}

void BASESHARED_EXPORT myMsgHandler(QtMsgType t,
                                    const QMessageLogContext & context,
                                    const QString & msg)
{
    (void)context;
    if (BaseLog::blogFile())
    {
        BaseLog::blogFile()->write(qPrintable(msg));
        BaseLog::blogFile()->write("\n");
        BaseLog::blogFile()->flush();
    }
    if (QtFatalMsg == t)
        abort();
}
/*
QUrl BaseLog::url(void)
{
    QUrl result;
    QUrlQuery query;
    query.addQueryItem("fatal", BaseLog::fatalSeverity().name());
    query.addQueryItem("options", "UserOpts");
    query.addQueryItem("global", "~"+BaseLog::minimumSeverity().name());
    result.setScheme("troll");
    if (blogFile()) result.setPath(blogFileName());
    result.setQuery(query);
    return result;
}
*/
QChar BaseLog::severityChar(const Severity sev)
{
    static const QString chars("})|([~+.XXX <>-=!*?$&$$##%%@@@@{");
    return (sev >= 0 && sev < chars.size()) ? chars.at(sev) : QChar('?');
}
