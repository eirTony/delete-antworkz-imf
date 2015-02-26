#ifndef PARSEDENTRY_H
#define PARSEDENTRY_H

#include "../BasicJournal.h"
#include "../BasicJournalQueue.h"
#include "../BasicJournalWriter.h"

class ParsedEntry
{
public:
    explicit ParsedEntry(const BasicJournalEntry & entry);
    QString formatted(void) const;

public: // access
    const QDateTime timeStamp;
    const BasicJournalQueue::MacroName macroName;
    const BasicJournalQueue::Category category;
    const QString message;
    const QString expression;
    const QString objectName;
    const QVariant var1;
    const QVariant var2;
    const QVariant var3;
    const QVariant var4;
};

#endif // PARSEDENTRY_H
