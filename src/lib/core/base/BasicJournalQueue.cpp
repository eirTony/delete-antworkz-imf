#include "BasicJournalQueue.h"

#include <QTimer>

#include "BasicJournalWriter.h"

BasicJournalQueue::BasicJournalQueue(QObject * parent)
    : QObject(parent)
{
}

BasicJournalQueue::BasicJournalQueue(const QUrl & url,
                                     QObject * parent)
    : QObject(parent)
{
    startup(url);
}

void BasicJournalQueue::startup(const QUrl & url)
{
    if (isStartup())    endStartup();
    mpWriter = new BasicJournalWriter(url);
    QTimer::singleShot(60000, this, SLOT(cleanStartupDir()));
}

bool BasicJournalQueue::isStartup(void) const
{
    return !! mpWriter && mpWriter->isWritable();
}

QFile * BasicJournalQueue::startupFile(void) const
{
    return isStartup() ? mpWriter->file() : 0;
}

void BasicJournalQueue::endStartup(void)
{
   if (mpWriter)
   {
       delete mpWriter;
       mpWriter = 0;
   }
}

void BasicJournalQueue::enqueue(const BasicJournalEntry & entry)
{
    mEntryQueue.enqueue(entry);
    emit enqueued();
    emit enqueued(entry);
    emit queueSize(mEntryQueue.size());
}

BasicJournalEntry BasicJournalQueue::dequeue(void)
{
    BasicJournalEntry entry;
    if ( ! mEntryQueue.isEmpty())
        entry = mEntryQueue.dequeue();
    emit queueSize(mEntryQueue.size());
    if (mEntryQueue.isEmpty())
        emit empty();
    return entry;
}

BasicJournalEntryList BasicJournalQueue::dequeue(const int count)
{
    BasicJournalEntryList list;
    if ( !! count)
    {
        list = mEntryQueue;
    }
    else
    {
        int k = 0;
        while (count && ++k < count && ! mEntryQueue.isEmpty())
            list.append(mEntryQueue.dequeue());
    }
    emit queueSize(mEntryQueue.size());
    if (mEntryQueue.isEmpty())
        emit empty();
    return list;
}

BasicJournalEntryList BasicJournalQueue::dequeueAll(void)
{
    return dequeue(0);
}

BasicJournalQueue::Category
        BasicJournalQueue::parseCategory(const BasicName & s) // static
{
    Category rtn = nullCategory;
    if (false)
        ;
    else if (BasicName("Debug") == s)
        rtn = Debug;
    else if (BasicName("Warning") == s)
        rtn = Warning;
    else if (BasicName("Critical") == s)
        rtn = Critical;
    else if (BasicName("Fatal") == s)
        rtn = Fatal;
    return rtn;
}

BasicJournalQueue::MacroName
        BasicJournalQueue::parseMacroName(const BasicName & s) // static
{
    MacroName rtn = nullMacroName;
    if (false)
        ;
    else if (BasicName("BTrace") == s)
        rtn = BTrace;
    else if (BasicName("BDump") == s)
        rtn = BDump;
    else if (BasicName("BTodo") == s)
        rtn = BTodo;
    else if (BasicName("BWarnIf") == s)
        rtn = BWarnIf;
    return rtn;
}
