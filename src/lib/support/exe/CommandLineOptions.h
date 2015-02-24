#ifndef COMMANDLINEOPTIONS_H
#define COMMANDLINEOPTIONS_H
#include "ExeLib.h"

#include <base/BasicNameMap.h>
#include "CommandLineOption.h"

class EXESHARED_EXPORT CommandLineOptions
{
public:
    CommandLineOptions(void);
    bool isEmpty(void) const;
    bool isValid(void) const;
    void clear(void);
    bool add(const CommandLineOption option);
    bool remove(const BasicName & name);

private:
    BasicName::List mPositionalNameList;
    BasicNameMap<CommandLineOption> mOptionMap;
};

#endif // COMMANDLINEOPTIONS_H
