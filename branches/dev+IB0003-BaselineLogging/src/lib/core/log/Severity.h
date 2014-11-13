#ifndef SEVERITY_H
#define SEVERITY_H

class Severity
{
public:
    enum Level
    {
        nullLevel = 0,
        DumpVar,
        DumpHex,
        Preamble,
        Info,
        Progress,
        Quit,
        Exception,
        Signal,
        sizeLevel
    };

public:
    Severity(const int iLevel=0);
    operator bool (void) const;
    operator int  (void) const;
    bool operator == (const Severity other) const;
    bool operator >  (const Severity other) const;

private:
    int mLevelInt;
};

#endif // SEVERITY_H
