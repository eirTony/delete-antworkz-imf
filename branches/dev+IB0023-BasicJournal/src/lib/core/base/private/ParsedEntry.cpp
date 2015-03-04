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
    , prettyFunction(entry.value("PrettyFunction").toString())
    , sourceFileName(entry.value("SourceFileName").toString())
    , sourceFileLine(entry.value("SourceFileLine").toInt())
{
}

QString ParsedEntry::formatted(void) const
{
    QString rtn(message);

    switch (macroName)
    {
    case BasicJournalQueue::BTrace:
        rtn.replace("%1", var1.toString());
        rtn.replace("%2", var2.toString());
        rtn.replace("%3", var3.toString());
        rtn.replace("%4", var4.toString());
        break;

    case BasicJournalQueue::BToDo:
    case BasicJournalQueue::BMustDo:
        if (rtn.isEmpty())
            rtn = QString("%1 [%2, %3]").arg(prettyFunction)
                    .arg(sourceFileName).arg(sourceFileLine);
        break;

    case BasicJournalQueue::BWarn:
    case BasicJournalQueue::BError:
    case BasicJournalQueue::BFatal:
        // no processing needed
        break;

    case BasicJournalQueue::BWarnIf:
    case BasicJournalQueue::BErrorIf:
    case BasicJournalQueue::BFatalIf:
        rtn = QString("Failed: %1 (%2)")
                .arg(expression).arg(value.toString());
        break;

    case BasicJournalQueue::BWarnNot:
    case BasicJournalQueue::BErrorNot:
    case BasicJournalQueue::BFatalNot:
        rtn = QString("Failed NOT: %1 (%2)")
                .arg(expression).arg(value.toString());
        break;

    case BasicJournalQueue::BDump:
        rtn = QString("%1 = (%2)")
                .arg(expression).arg(value.toString());
        break;

    case BasicJournalQueue::BObjPtr:
    case BasicJournalQueue::BNulPtr:
        // TBD
        break;

    case BasicJournalQueue::nullMacroName: // reserved values
    case BasicJournalQueue::sizeMacroName: ;
    }

    return rtn;
} // formatted()
