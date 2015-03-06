#ifndef BASICJOURNALWRITER_H
#define BASICJOURNALWRITER_H

#include <QUrl>
#include <QUrlQuery>
class QFile;
class QTextStream;

#include "BasicJournalInternal.h"
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
    bool setFile(const QString path);
    bool openFile(void);
    bool startFile(void);
    void writeTextFile(const BasicJournalEntry & entry);
    void writeDelimited(const BasicJournalEntry & entry);

private:
    QUrl mUrl;
    QUrlQuery mQuery;
    Format mFormat;
    QString mFilePath;
    BasicJournalQueue::Category mMinSeverity;
    int mKeepFiles = 0;
    int mKeepDays = 0;
    QFile * mpFile = 0;
    QTextStream * mpStream = 0;
    bool mStarted = false;
};

#endif // BASICJOURNALWRITER_H
