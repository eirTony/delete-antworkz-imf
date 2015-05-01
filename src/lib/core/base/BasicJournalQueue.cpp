#include "BasicJournalQueue.h"

#include <QTimer>

#include "private/BasicJournalEntry.h"
#include "private/BasicJournalWriter.h"

BasicJournalQueue * BasicJournalQueue::smpInstance = 0;

BasicJournalQueue::BasicJournalQueue(void)
{
}

#if 0
BasicJournalQueue::~BasicJournalQueue()
{
    if (mpWriter)   delete mpWriter;
}
#endif

BasicJournalQueue & BasicJournalQueue::instance(void) // static
{
    if ( ! smpInstance)
        smpInstance = new BasicJournalQueue;
    return *smpInstance;
}

void BasicJournalQueue::startup(const QUrl & url)
{
    if (isStartup())    endStartup();
    BasicJournalWriter * writer = new BasicJournalWriter(url);
    if ( ! writer->isWritable()) return;

    // success
    mpWriter = writer;
    connect(this, SIGNAL(enqueued(BasicJournalEntry)),
            mpWriter, SLOT(write(BasicJournalEntry)));
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

BasicJournalEntry::List BasicJournalQueue::dequeue(const int count)
{
    BasicJournalEntry::List list;
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

BasicJournalEntry::List BasicJournalQueue::dequeueAll(void)
{
    return dequeue(0);
}

BasicJournalQueue::Category
        BasicJournalQueue::parseCategory(const BasicName & s) // static
{
    Category rtn = nullCategory;
    if (false)  {;}
    else if (BasicName("Debug") == s)           rtn = Debug;
    else if (BasicName("Warning") == s)         rtn = Warning;
    else if (BasicName("Critical") == s)        rtn = Critical;
    else if (BasicName("Fatal") == s)           rtn = Fatal;
    else {;}
    return rtn;
}

BasicJournalQueue::MacroName
        BasicJournalQueue::parseMacroName(const BasicName & s) // static
{
    MacroName rtn = nullMacroName;
    if (false)  {;}
    else if (BasicName("BTrace") == s)          rtn = BTrace;
    else if (BasicName("BDump") == s)           rtn = BDump;
    else if (BasicName("BToDo") == s)           rtn = BToDo;
    else if (BasicName("BWarnIf") == s)         rtn = BWarnIf;
    else if (BasicName("BWarnNot") == s)        rtn = BWarnNot;
    else if (BasicName("BWarn") == s)           rtn = BWarn;
    else if (BasicName("BErrorIf") == s)        rtn = BErrorIf;
    else if (BasicName("BErrorNot") == s)       rtn = BErrorNot;
    else if (BasicName("BError") == s)          rtn = BError;
    else if (BasicName("BMustDo") == s)         rtn = BMustDo;
    else if (BasicName("BFatalIf") == s)        rtn = BFatalIf;
    else if (BasicName("BFatalNot") == s)       rtn = BFatalNot;
    else if (BasicName("BObjPtr") == s)         rtn = BObjPtr;
    else if (BasicName("BNulPtr") == s)         rtn = BNulPtr;
    else if (BasicName("BFatal") == s)          rtn = BFatal;
    else   {;}
    return rtn;
}
