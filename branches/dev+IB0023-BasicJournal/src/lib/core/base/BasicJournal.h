#ifndef BASICJOURNAL_H
#define BASICJOURNAL_H
#include "BasicJournalInternal.h"

#define BTRACE(msg, var1=QVariant(), var2=QVariant() \
                    var3=QVariant(), var4=QVariant()) \
            _BJENTRY("BTRACE", "Debug") \
            << BasicJournalItem("Message", msg) \
            << BasicJournalItem("Var1", var1) \
            << BasicJournalItem("Var2", var2) \
            << BasicJournalItem("Var3", var3) \
            << BasicJournalItem("Var4", var4) \

#define BDUMP(expr) _BJENTRY("BDUMP", "Debug") \
            << BasicJournalItem("Expression", #expr) \
            << BasicJournalItem("Value", expr) \

#endif // BASICJOURNAL_H
