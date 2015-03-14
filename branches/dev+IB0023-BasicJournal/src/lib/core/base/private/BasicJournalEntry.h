#ifndef BASICJOURNALENTRY_H
#define BASICJOURNALENTRY_H

#include <QList>
#include <QMap>
#include <QVariant.h>

#include "../BasicName.h"

class BasicJournalEntry : public QMap<BasicName, QVariant>
{
public:
    typedef QList<BasicJournalEntry> List;

public:
    BasicJournalEntry(void);
};

typedef QList<BasicJournalEntry> BasicJournalEntryList;

#endif // BASICJOURNALENTRY_H
