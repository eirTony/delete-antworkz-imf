#include "Severity.h"

const int Severity::csmInitialValue = 0;

const BasicName::List Severity::csmNameList = BasicName::List()
            << BasicName("Null")
            << BasicName("Alloc")
            << BasicName("Leave")
            << BasicName("EnterArg")
            << BasicName("Enter")
            << BasicName("Signal")
            << BasicName("Thread")
            << BasicName("Data")
            << BasicName("DumpHex")
            << BasicName("DumpVal")
            << BasicName("Dump")
            << BasicName("ToDo")
            << BasicName("Detail")
            << BasicName("Trace")
            << BasicName("Expect")
            << BasicName("State")
            << BasicName("Preamble")
            << BasicName("Info")
            << BasicName("LogMsg")
            << BasicName("Progress")
            << BasicName("NeedDo")
            << BasicName("Notice")
            << BasicName("Watch")
            << BasicName("Warning")
            << BasicName("MustDo")
            << BasicName("Stern")
            << BasicName("Error")
            << BasicName("Pointer")
            << BasicName("QPointer")
            << BasicName("Alloc")
            << BasicName("Assert")
            << BasicName("Quit")
            << BasicName("Exception")
            << BasicName("Signal")
            << BasicName("Shutdown")
            << BasicName("x")
            << BasicName("a")
            << BasicName("b")
            << BasicName("c")
            << BasicName("d")
            << BasicName("e")
            << BasicName("Maximum");

const int Severity::csmMaximumValue = csmInitialValue + csmNameList.size();

BasicNameMap<int> Severity::smNameValueMap;

QMap<int, BasicName> Severity::smValueNameMap;

void Severity::staticCtor(void)
{
    int value = csmInitialValue;
    foreach (BasicName name, csmNameList)
    {
        smNameValueMap.insert(name, value);
        smValueNameMap.insert(value, name);
        ++value;
    }
}

Severity::Severity(const int iLevel)
    : mLevelInt((mLevelInt < csmInitialValue
                 || mLevelInt > csmMaximumValue)
                ? iLevel
                : csmInitialValue) {}

Severity::Severity(const QString & name)
    : mLevelInt(smNameValueMap.contains(name)
                    ? smNameValueMap.value(name)
                    : csmInitialValue) {}

BasicName Severity::name(void) const
{
    return smValueNameMap.contains(mLevelInt)
            ? smValueNameMap.value(mLevelInt)
            : BasicName();
}

#if 0
Severity::operator bool (void) const
{
    return nullLevel != mLevelInt;
}
#endif
Severity::operator int (void) const
{
    return mLevelInt;
}

bool Severity::operator == (const Severity other) const
{
    return mLevelInt == other.mLevelInt;
}

bool Severity::operator >  (const Severity other) const
{
    return mLevelInt > other.mLevelInt;
}
