#include "BasicJournalWriter.h"

#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QTemporaryDir>
#include <QTextStream>
#include <QUrl>

#include "ParsedEntry.h"

BasicJournalWriter::BasicJournalWriter(const QUrl & url)
{
    if ( ! parseUrl(url))                   return;
    if ( ! setFile(mUrl.path()))            return;
    if ( ! openFile())                      return;
    if ( ! startFile())                     return;
    mStarted = true;
}

bool BasicJournalWriter::isWritable(void) const
{
    return false;
}

void BasicJournalWriter::write(BasicJournalEntry entry)
{
    switch (mFormat)
    {
    case User:
    case Trace:     writeTextFile(entry);   break;

    case Csv:
    case Tsv:       writeDelimited(entry);  break;

    case nullFormat: // reserved format values
    case sizeFormat: ;
    }
}

QFile * BasicJournalWriter::file(void) const
{
    return mpFile;
}

bool BasicJournalWriter::parseUrl(const QUrl & url)
{
    if ( ! url.isValid())                   return false;
    mUrl = url;
    mQuery = QUrlQuery(mUrl);
    mScheme = mUrl.scheme().isEmpty() ? "txtfile" : mUrl.scheme();
    if ("txtfile" != mScheme)               return false;

    mFormat         = parseFormat(mQuery.queryItemValue("Format"));
    mMinSeverity    = parseMinSev(mQuery.queryItemValue("MinSev"));
    mKeepFiles      = mQuery.queryItemValue("sKeepFiles").toInt();
    mKeepDays       = mQuery.queryItemValue("sKeepDays").toInt();
    return true;
}

BasicJournalWriter::Format BasicJournalWriter::parseFormat(const BasicName s)
{
    Format rtn = nullFormat;
    if (false)
        ;
    else if (BasicName("Trace") == s)
        rtn = Trace;
    else if (BasicName("User") == s)
        rtn = User;
    else if (BasicName("Csv") == s)
        rtn = Csv;
    else if (BasicName("Tsv") == s)
        rtn = Tsv;
    else
        rtn = Tsv;
    return rtn;
}

BasicJournalQueue::Category BasicJournalWriter::parseMinSev(const BasicName s)
{
    BasicJournalQueue::Category rtn = BasicJournalQueue::nullCategory;
    if (BasicName("All") == s)
        rtn = BasicJournalQueue::Debug;
    else
        rtn = BasicJournalQueue::parseCategory(s);
    if (BasicJournalQueue::nullCategory == rtn)
        rtn = BasicJournalQueue::Debug;
    return rtn;
}

bool BasicJournalWriter::setFile(const QString path)
{
    // collect information
    QDir dir(QTemporaryDir().path());
    QString org = qApp->organizationName();
    QString app = qApp->applicationName();
    QFileInfo pathFI(path);
    QFileInfo outFI;
    QString sfx;
    switch (mFormat)
    {
    case User:      sfx = ".log";       break;
    case Trace:     sfx = ".trc";       break;
    case Csv:       sfx = ".csv";       break;
    case Tsv:       sfx = ".tsv";       break;
    case nullFormat:    case sizeFormat: ; // invalid values
    }

    if (path.isEmpty())
    {
        dir.mkpath("Antz/StartLog");    dir.cd("Antz/StartLog");
        dir.mkpath(org);                dir.cd(org);
        dir.mkpath(app);                dir.cd(app);
        outFI.setFile(dir.path() + "/"
                      + QDateTime::currentDateTime()
                        .toString("DyyyyMMddThhmmss")+sfx);

    }
    else if (pathFI.exists())
    {
        outFI = pathFI;
    }
    else if (pathFI.isDir())
    {
        outFI = QFileInfo(path + "/"
                          + QDateTime::currentDateTime()
                            .toString("DyyyyMMddThhmmss")+sfx);
    }
    else
    {
        return false;
    }

    mFilePath = outFI.absoluteFilePath();
    return true;
}

bool BasicJournalWriter::openFile(void)
{

    return false;
}

bool BasicJournalWriter::startFile(void)
{

    return false;
}

void BasicJournalWriter::writeTextFile(const BasicJournalEntry & entry)
{
    Q_ASSERT(mpStream);
    ParsedEntry pe(entry);
    QString trace;
    QString user(QString("%1 %2")
                .arg(pe.timeStamp.toString("hh:mm:ss.zz"))
                .arg(pe.formatted()));
    if (Trace == mFormat)
        trace = QString(" [%1, %2] %3")
                .arg(pe.sourceFileName)
                .arg(pe.sourceFileLine)
                .arg(pe.prettyFunction);
    *mpStream << user << trace << endl;
}

void BasicJournalWriter::writeDelimited(const BasicJournalEntry & entry)
{
    Q_ASSERT(mpStream);
    static QString  left(Tsv ? ""   : "\"");
    static QString right(Tsv ? ""   : "\"");
    static QString delim(Tsv ? "\t" : ",");
    ParsedEntry pe(entry);

    *mpStream << left << pe.timeStamp.toString() << right << delim
              << left << pe.formatted()          << right << delim
              << left << pe.prettyFunction       << right << delim
              << left << pe.sourceFileName       << right << delim
              << left << pe.sourceFileLine       << right << delim
              << endl;
}
