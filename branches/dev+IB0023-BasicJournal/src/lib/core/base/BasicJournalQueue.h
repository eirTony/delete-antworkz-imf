#ifndef BASICJOURNALQUEUE_H
#define BASICJOURNALQUEUE_H
#include "BaseLib.h"

#include <QObject>

#include <QList.h>
#include <QQueue>
class QFile;
class QUrl;

#include <core/Singleton.h>

#include "BasicJournalInternal.h"
class BasicJournalWriter;

class BASESHARED_EXPORT BasicJournalQueue : public QObject // StaticSingleton
{
    Q_OBJECT
public:
    enum Category // for now until Qt5.4 QMessageLogger understood
    {
        nullCategory = 0,
        Debug,
        Warning,
        Critical,
        Fatal,
        sizeCategory
    };
    enum MacroName
    {
        nullMacroName = 0,
        BTrace,
        BDump,
        BToDo,
        BWarnIf,
        BWarnNot,
        BWarn,
        BErrorIf,
        BErrorNot,
        BError,
        BMustDo,
        BFatalIf,
        BFatalNot,
        BObjPtr,
        BNulPtr,
        BFatal,
        sizeMacroName
    };

public: // static
    static BasicJournalQueue &instance(void);

public:
    void startup(const QUrl & url);
    bool isStartup(void) const;
    QFile * startupFile(void) const;
    void endStartup(void);

    void enqueue(const BasicJournalEntry & entry);
    BasicJournalEntry dequeue(void);
    BasicJournalEntryList dequeue(const int count=0);
    BasicJournalEntryList dequeueAll(void);

public: // static
    static Category parseCategory(const BasicName & s);
    static MacroName parseMacroName(const BasicName & s);

signals:
    void enqueued(void);
    void enqueued(BasicJournalEntry);
    void queueSize(int);
    void empty(void);

public slots:

private:
    BasicJournalQueue(void);
    ~BasicJournalQueue() {}

private slots:
    void cleanStartupDir(void) {}
    void removeStartupFile(void) {}

private:
    BasicJournalWriter * mpWriter = 0;
    QQueue<BasicJournalEntry> mEntryQueue;
    QStringList mOldFileNameList; // or Queue?

private: // static
    static BasicJournalQueue * smpInstance;
};

//typedef PointerSingleton<BasicJournalQueue> BasicJournalInstance;

#endif // BASICJOURNALQUEUE_H
