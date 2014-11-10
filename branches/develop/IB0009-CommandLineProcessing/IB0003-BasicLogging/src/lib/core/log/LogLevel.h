#ifndef LOGLEVEL_H
#define LOGLEVEL_H

class LogLevel
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
    LogLevel(const int iLevel=0);
    operator bool (void) const;
    operator int  (void) const;
    bool operator == (const LogLevel other) const;
    bool operator >  (const LogLevel other) const;

private:
    int mLevelInt;
};

#endif // LOGLEVEL_H
