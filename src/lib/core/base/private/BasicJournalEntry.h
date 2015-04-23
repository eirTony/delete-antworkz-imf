/*! @file   BaseBasicJournalEntry.h   Eclipse BasicJournalEntry declaration
 */
#ifndef BASICJOURNALENTRY_H
#define BASICJOURNALENTRY_H
#include "../BaseLib.h"

#include <QList>
#include <QMap>
#include <QVariant.h>

#include "../BasicName.h"
class BasicJournalItem;

class BASESHARED_EXPORT BasicJournalEntry : public QMap<BasicName, QVariant>
{
public:
    typedef QList<BasicJournalEntry> List;

public:
    BasicJournalEntry(void);
    void append(const BasicJournalItem & item);

    inline BasicJournalEntry & operator<< (const BasicJournalItem & item)
    { append(item); return *this; }

};

typedef QList<BasicJournalEntry> BasicJournalEntryList;

#endif // BASICJOURNALENTRY_H
