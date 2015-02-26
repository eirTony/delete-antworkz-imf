#ifndef BASICJOURNALWRITER_H
#define BASICJOURNALWRITER_H

#include <QUrl>
#include <QUrlQuery>
class QFile;

#include "BasicJournal.h"
#include "BasicJournalQueue.h"

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

public:
    explicit BasicJournalWriter(const QUrl & url);
    bool isWritable(void) const;
    void write(const BasicJournalEntry & entry);
    QFile * file(void) const;

private:
    bool parseUrl(const QUrl & url);
    Format parseFormat(const BasicName s);
    BasicJournalQueue::Category parseMinSev(const BasicName s);
    bool openFile(void);

private:
    QUrl mUrl;
    QUrlQuery mQuery;
    QString mPath;
    Format mFormat;
    BasicJournalQueue::Category mMinSeverity;
    int mKeepFiles = 0;
    int mKeepDays = 0;
    QFile * mpFile = 0;
};

#endif // BASICJOURNALWRITER_H
