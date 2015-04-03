#ifndef BASICJOURNALINTERNAL_H
#define BASICJOURNALINTERNAL_H

#include "private/BasicJournalEntry.h"
#include "private/BasicJournalItem.h"
#include "BasicName.h"
#include "BasicNameMap.h"

#define _BJOURNAL (BasicJournalQueue::instance())

#define _BJENTRY(mac, cat) BasicJournalEntry() \
            << BasicJournalItem("TimeStamp", QDateTime::currentDateTime()) \
            << BasicJournalItem("ModuleName", MODULE_NAME) \
            << BasicJournalItem("PrettyFunction", Q_FUNC_INFO) \
            << BasicJournalItem("SourceFileName", __FILE__) \
            << BasicJournalItem("SourceFileLine", __LINE__) \
            << BasicJournalItem("MacroName", mac) \
            << BasicJournalItem("Category", cat) \


#endif // BASICJOURNALINTERNAL_H
