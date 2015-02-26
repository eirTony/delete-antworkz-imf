#include "BasicJournalWriter.h"

#include <QUrl>

BasicJournalWriter::BasicJournalWriter(const QUrl & url)
{
    if ( ! parseUrl(url))                   return;
    if ( ! openFile())                      return;

}

bool BasicJournalWriter::isWritable(void) const
{
    return false;
}

void BasicJournalWriter::write(const BasicJournalEntry & entry)
{

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
    mPath = mUrl.path();
    if ("txtfile" != mUrl.scheme())         return false;

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

bool BasicJournalWriter::openFile(void)
{
    return false;
}
