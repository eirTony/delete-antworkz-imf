#ifndef COMMANDLINEOPTIONS_H
#define COMMANDLINEOPTIONS_H

#include <base/BasicNameMap.h>
#include "CommandLineOptions.h"

class CommandLineOptions : private BasicNameMap<CommandLineOption>
{
public:
    CommandLineOptions(void);
};

#endif // COMMANDLINEOPTIONS_H
