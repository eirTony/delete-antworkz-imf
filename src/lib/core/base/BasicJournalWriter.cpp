#include "BasicJournalWriter.h"

#include <QUrl>

BasicJournalWriter::BasicJournalWriter(const QUrl & url)
{
    parseUrl(url);
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
    if ("txtfile" != mUrl.scheme())         return false;

    QString sFormat    = mQuery.queryItemValue("Format");
    QString sMinSev    = mQuery.queryItemValue("MinSev");
    QString sKeepFiles = mQuery.queryItemValue("sKeepFiles");
    QString sKeepDays  = mQuery.queryItemValue("sKeepDays");

    return false;
}
