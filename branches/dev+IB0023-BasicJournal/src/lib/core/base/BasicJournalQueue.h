#ifndef BASICJOURNALQUEUE_H
#define BASICJOURNALQUEUE_H

#include <QObject>

#include <QList.h>
#include <QQueue>
class QFile;
class QUrl;

#include "BasicJournal.h"
class BasicJournalWriter;

class BasicJournalQueue : public QObject // Singleton
{
    Q_OBJECT
public:
    explicit BasicJournalQueue(QObject * parent=0);
    BasicJournalQueue(const QUrl & url, QObject * parent=0);
    void startup(const QUrl & url);
    bool isStartup(void) const;
    QFile * startupFile(void) const;
    void endStartup(void);

    void enqueue(const BasicJournalEntry & entry);
    BasicJournalEntry dequeue(void);
    BasicJournalEntryList dequeue(const int count=0);
    BasicJournalEntryList dequeueAll(void);

signals:
    void enqueued(void);
    void enqueued(BasicJournalEntry);
    void queueSize(int);
    void empty(void);

public slots:

private slots:
    void cleanStartupDir(void) {}
    void removeStartupFile(void) {}

private:
    BasicJournalWriter * mpWriter = 0;
    QQueue<BasicJournalEntry> mEntryQueue;
    QStringList mOldFileNameList; // or Queue?
};

#endif // BASICJOURNALQUEUE_H
