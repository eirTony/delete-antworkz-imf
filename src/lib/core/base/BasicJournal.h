#ifndef BASICJOURNAL_H
#define BASICJOURNAL_H
#include "BasicJournalInternal.h"

#define BTRACE(msg) \
            _BJENTRY("BTRACE", "Debug") \
            << BasicJournalItem("Message", msg) \

#define BTRACE1(msg, var1) \
            _BJENTRY("BTRACE", "Debug") \
            << BasicJournalItem("Message", msg) \
            << BasicJournalItem("Var1", var1) \

#define BTRACE2(msg, var1, var2) \
            _BJENTRY("BTRACE", "Debug") \
            << BasicJournalItem("Message", msg) \
            << BasicJournalItem("Var1", var1) \
            << BasicJournalItem("Var2", var2) \

#define BTRACE3(msg, var1, var2, var3) \
            _BJENTRY("BTRACE", "Debug") \
            << BasicJournalItem("Message", msg) \
            << BasicJournalItem("Var1", var1) \
            << BasicJournalItem("Var2", var2) \
            << BasicJournalItem("Var3", var3) \

#define BTRACE4(msg, var1, var2, var3, var4) \
            _BJENTRY("BTRACE", "Debug") \
            << BasicJournalItem("Message", msg) \
            << BasicJournalItem("Var1", var1) \
            << BasicJournalItem("Var2", var2) \
            << BasicJournalItem("Var3", var3) \
            << BasicJournalItem("Var4", var4) \

#define BDUMP(expr) _BJENTRY("BDUMP", "Debug") \
            << BasicJournalItem("Expression", #expr) \
            << BasicJournalItem("Value", expr) \

#define BWARNIF(expr, msg)  {if(!!expr) _BJOURNAL_BOOL(expr, msg, "BWARNIF", "Warning");}
#define BERRORIF(expr, msg) {if(!!expr) _BJOURNAL_BOOL(expr, msg, "BERRORIF", "Error");}
#define BFATALIF(expr, msg) {if(!!expr) _BJOURNAL_BOOL(expr, msg, "BFATALIF", "Fatal");}

#endif // BASICJOURNAL_H
