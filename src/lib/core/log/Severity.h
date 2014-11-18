#ifndef SEVERITY_H
#define SEVERITY_H

#include <base/BasicName.h>
#include <base/BasicNameMap.h>

class Severity
{
public:

public:
    Severity(const int iLevel=0);
    Severity(const QString & name);
    BasicName name(void) const;
//    operator bool (void) const;
    operator int  (void) const;
    bool operator == (const Severity other) const;
    bool operator >  (const Severity other) const;

public: // static functions
    static void staticCtor(void);

private:
    int mLevelInt;

private: // static members
    static const int csmInitialValue;
    static const int csmMaximumValue;
    static const BasicName::List csmNameList;
    static BasicNameMap<int> smNameValueMap;
    static QMap<int, BasicName> smValueNameMap;
};

#endif // SEVERITY_H
