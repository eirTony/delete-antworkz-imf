#ifndef COMMANDLINEOPTIONS_H
#define COMMANDLINEOPTIONS_H

#include <base/BasicNameMap.h>
#include "CommandLineOption.h"

class CommandLineOptions : private BasicNameMap<CommandLineOption>
{
public:
    CommandLineOptions(void);
    bool isEmpty(void) const;
    bool isValid(void) const;
    void clear(void);
    void addPositionalArgument(const BasicName & argName,
                               const QQString description,
                               const QQString syntax=QQString());
    bool add(const BasicName & optName,
             const CommandLineOption option);
    bool remove(const BasicName & key);

private:
    BasicName::List mPositionalNameList;
};

#endif // COMMANDLINEOPTIONS_H
