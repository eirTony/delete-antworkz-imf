#ifndef PARSEDENTRY_H
#define PARSEDENTRY_H

#include "../BasicJournal.h"
#include "../BasicJournalQueue.h"
#include "../BasicJournalWriter.h"

class ParsedEntry
{
public:
    explicit ParsedEntry(const BasicJournalEntry & entry
                                    =BasicJournalEntry());
    void set(const BasicJournalEntry & entry);
    int variantSize(void) const;
    QVariant variant(const int x) const;

public: // access
    QDateTime timeStamp;
    BasicJournalQueue::MacroName macro;
    BasicJournalQueue::Category category;
    QString message;
    QString formatted;
    QString expression;
    QString objectName;

private:
    QVariantList mVariantList;
};

#endif // PARSEDENTRY_H
