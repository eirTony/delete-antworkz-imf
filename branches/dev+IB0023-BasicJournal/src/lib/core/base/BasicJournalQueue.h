#ifndef BASICJOURNALQUEUE_H
#define BASICJOURNALQUEUE_H

#include <QObject>

#include <QList.h>
class QFile;
class QUrl;

#include "BasicName.h"
#include "BasicNameMap.h"
class BasicJournalWriter;

typedef BasicName::VariantPair BasicJournalItem;
typedef BasicName::VariantMap BasicJournalEntry;
typedef QList<BasicJournalEntry> BasicJournalEntryList;

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

    void append(const BasicJournalEntry & entry);
    BasicJournalEntry dequeue(void);
    BasicJournalEntryList dequeue(const int count=-1);
    BasicJournalEntryList dequeueAll(void);

signals:
    void enqueued(void);
    void enqueued(BasicJournalEntry);
    void queueSize(int);

public slots:

private slots:
    void cleanStartupDir(void) {}
    void removeStartupFile(void) {}

private:
    BasicJournalWriter * mpWriter = 0;

};

#endif // BASICJOURNALQUEUE_H
