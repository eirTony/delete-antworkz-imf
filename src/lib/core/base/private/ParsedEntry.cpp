#include "ParsedEntry.h"

ParsedEntry::ParsedEntry(const BasicJournalEntry & entry)
{
    set(entry);
}

void ParsedEntry::set(const BasicJournalEntry & entry)
{
    timeStamp = entry.value("TimeStamp").toDateTime();
}

int ParsedEntry::variantSize(void) const
{

}

QVariant ParsedEntry::variant(const int x) const
{

}
