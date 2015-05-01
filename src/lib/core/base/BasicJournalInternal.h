#ifndef BASICJOURNALINTERNAL_H
#define BASICJOURNALINTERNAL_H

#include "BasicJournalQueue.h"
#include "private/BasicJournalEntry.h"
#include "private/BasicJournalItem.h"
#include "BasicName.h"
#include "BasicNameMap.h"

#define _BJOURNAL (BasicJournalQueue::instance())
#define _BJOURNAL_EXPR(expr) _BJOURNAL.expr

#define _BJOURNAL_ENQ(entry) _BJOURNAL_EXPR(enqueue(entry))

#define _BJENTRY(mac, cat) BasicJournalEntry() \
            << BasicJournalItem("TimeStamp", QDateTime::currentDateTime()) \
            << BasicJournalItem("ModuleName", MODULE_NAME) \
            << BasicJournalItem("PrettyFunction", Q_FUNC_INFO) \
            << BasicJournalItem("SourceFileName", __FILE__) \
            << BasicJournalItem("SourceFileLine", __LINE__) \
            << BasicJournalItem("MacroName", mac) \
            << BasicJournalItem("Category", cat) \

#define _BJOURNAL_BOOL(mac, cat, expr, msg) \
            _BJOURNAL_ENQ(_BJENTRY(mac, cat) \
                << BasicJournalItem("Expression", expr) \
                << BasicJournalItem("ExprName", #expr) \
                << BasicJournalItem("Message", msg) \
                )

#define _BJOURNAL_MSG(mac, cat, msg) \
            _BJOURNAL_ENQ(_BJENTRY(mac, cat) \
                << BasicJournalItem("Message", msg) \
                )


#endif // BASICJOURNALINTERNAL_H
