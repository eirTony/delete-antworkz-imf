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
            << BasicName("UsualPass")
            << BasicName("CheckPass")
            << BasicName("ExpectPass")
            << BasicName("RequirePass")
            << BasicName("AssertPass")
            << BasicName("Data")
            << BasicName("DumpHex")
            << BasicName("DumpVal")
            << BasicName("Dump")
            << BasicName("Usual")
            << BasicName("ToDo")
            << BasicName("Detail")
            << BasicName("Trace")
            << BasicName("State")
            << BasicName("Preamble")
            << BasicName("Check")
            << BasicName("Info")
            << BasicName("LogMsg")
            << BasicName("Progress")
            << BasicName("NeedDo")
            << BasicName("Notice")
            << BasicName("Watch")
            << BasicName("Warning")         // typical Debug|Test level
            << BasicName("Expect")
            << BasicName("MustDo")
            << BasicName("Stern")
            << BasicName("Error")
            << BasicName("Require")
            << BasicName("Pointer")         // typical Release level
            << BasicName("QPointer")
            << BasicName("Alloc")
            << BasicName("Assert")
            << BasicName("Quit")
            << BasicName("Exception")
            << BasicName("Signal")
            << BasicName("Shutdown")
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

Severity::Severity(const BasicName &name)
    : mLevelInt(smNameValueMap.contains(name)
                    ? smNameValueMap.value(name)
                    : csmInitialValue) {}

BasicName Severity::name(void) const
{
    return smValueNameMap.contains(mLevelInt)
            ? smValueNameMap.value(mLevelInt)
            : BasicName();
}

bool Severity::is(const BasicName & name) const
{
    return smNameValueMap.value(name) == mLevelInt;
}

Severity Severity::pass(void) const
{
    return pass(*this);
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

Severity Severity::pass(const Severity fail)
{
    Severity rtn = fail;
    if (false) ;
    else if (fail.is("Assert"))     rtn = Severity("AssertPass");
    else if (fail.is("Require"))     rtn = Severity("RequirePass");
    else if (fail.is("Watch"))     rtn = Severity("WatchPass");
    else if (fail.is("Expect"))     rtn = Severity("ExpectPass");
    else if (fail.is("Check"))     rtn = Severity("CheckPass");
    else if (fail.is("Usual"))     rtn = Severity("UsualPass");
    return rtn;
}
