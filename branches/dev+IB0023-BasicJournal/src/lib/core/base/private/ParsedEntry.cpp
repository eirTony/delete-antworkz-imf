#include "ParsedEntry.h"

ParsedEntry::ParsedEntry(const BasicJournalEntry & entry)
    : timeStamp(entry.value("TimeStamp").toDateTime())
    , macroName(BasicJournalQueue::parseMacroName
                        (entry.value("MacroName").toString()))
    , category(BasicJournalQueue::parseCategory
                        (entry.value("Category").toString()))
    , message(entry.value("Message").toString())
    , expression(entry.value("Expression").toString())
    , objectName(entry.value("ObjectName").toString())
    , var1(entry.value("Var1"))
    , var2(entry.value("Var2"))
    , var3(entry.value("Var3"))
    , var4(entry.value("Var4"))
{
}

QString ParsedEntry::formatted(void) const
{
    QString rtn(message);
    rtn.replace("%1", var1.toString());
    rtn.replace("%2", var2.toString());
    rtn.replace("%3", var3.toString());
    rtn.replace("%4", var4.toString());
    return rtn;
}
