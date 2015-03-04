#ifndef BASICJOURNALINTERNAL_H
#define BASICJOURNALINTERNAL_H

#include "BasicName.h"
#include "BasicNameMap.h"

typedef BasicName::VariantPair BasicJournalItem;
typedef BasicName::VariantMap BasicJournalEntry;
typedef QList<BasicJournalEntry> BasicJournalEntryList;

#define _BJENTRY(mac, cat) BasicJournalEntry() \
            << BasicJournalItem("TimeStamp", QDateTime::currentDateTime()) \
            << BasicJournalItem("ModuleName", _MODULE_) \
            << BasicJournalItem("PrettyFunction", Q_FUNC_INFO) \
            << BasicJournalItem("SourceFileName", __FILE__) \
            << BasicJournalItem("SourceFileLine", __LINE__) \
            << BasicJournalItem("MacroName", mac) \
            << BasicJournalItem("Category", cat) \


#endif // BASICJOURNALINTERNAL_H
