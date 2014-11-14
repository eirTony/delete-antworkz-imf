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
        Todo,
        Preamble,
        Info,
        Progress,
        NeedDo,
        Quit,
        MustDo,
        Pointer,
        OPointer,
        Exception,
        Alloc,
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
