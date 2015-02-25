#ifndef BASICJOURNALWRITER_H
#define BASICJOURNALWRITER_H

#include <QUrl>
#include <QUrlQuery>
class QFile;

#include "BasicJournal.h"

class BasicJournalWriter
{
private:
    enum Format
    {
        nullFormat = 0,
        Trace,
        User,
        Csv,
        Tsv,
        sizeFormat
    };
    enum Category // for now until Qt5.4 QMessageLogger understood
    {
        nullCategory = 0,
        Debug,
        Warning,
        Critical,
        Fatal,
        sizeCategory
    };

public:
    explicit BasicJournalWriter(const QUrl & url);
    bool isWritable(void) const;
    void write(const BasicJournalEntry & entry);
    QFile * file(void) const;

private:
    bool parseUrl(const QUrl & url);

private:
    QUrl mUrl;
    QUrlQuery mQuery;
    Format mFormat;
    Category mMinSeverity;
    QFile * mpFile = 0;
};

#endif // BASICJOURNALWRITER_H
