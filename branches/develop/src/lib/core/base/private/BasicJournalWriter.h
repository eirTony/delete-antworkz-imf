#ifndef BASICJOURNALWRITER_H
#define BASICJOURNALWRITER_H

#include <QObject>

#include <QUrl>
#include <QUrlQuery>
class QDir;
class QFile;
class QTextStream;

#include "BasicJournalInternal.h"
#include "BasicJournalQueue.h"

class BasicJournalWriter : public QObject
{
    Q_OBJECT
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
    QFile * file(void) const;

public slots:
    void write(BasicJournalEntry entry);

private:
    bool parseUrl(const QUrl & url);
    Format parseFormat(const BasicName s);
    BasicJournalQueue::Category parseMinSev(const BasicName s);
    bool setFile(const QString path);
    QString fileSuffix(void) const;
    void setFileName(const QDir & dir,
                     const QString & org,
                     const QString & app,
                     const QString & base,
                     const QString & suffix);
    void setFileName(const QDir & dir,
                     const QString & base,
                     const QString & suffix);
    bool openFile(void);
    bool startFile(void);
    void writeTextFile(const BasicJournalEntry & entry);
    void writeDelimited(const BasicJournalEntry & entry);

private:
    QUrl mUrl;
    QUrlQuery mQuery;
    QString mScheme;
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
