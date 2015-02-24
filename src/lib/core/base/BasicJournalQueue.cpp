#include "BasicJournalQueue.h"

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
    (void)url;
}
