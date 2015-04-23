/*! @file   BaseBasicJournalEntry.cpp   Eclipse BasicJournalEntry definition
 */
#include "BasicJournalEntry.h"

#include "BasicJournalItem.h"

BasicJournalEntry::BasicJournalEntry(void)
{
}

void BasicJournalEntry::append(const BasicJournalItem & item)
{
    insert(item.first, item.second);
}
