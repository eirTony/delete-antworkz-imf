#include "CommandLineOptions.h"

CommandLineOptions::CommandLineOptions(void)
{
    mPositionalNameList << "{dummy0}";
}

bool CommandLineOptions::isEmpty(void) const
{
    return true;
}

bool CommandLineOptions::isValid(void) const
{
    return false;
}

void CommandLineOptions::clear(void)
{
    mOptionMap.clear();
    mPositionalNameList.clear();
}

bool CommandLineOptions::add(const CommandLineOption option)
{
    CommandLineOption newOption(option);

    if (option.getOptionName().isEmpty())
    {
        if (option.getNameList().isEmpty())
            return false;
        else
            newOption.setOptionName(option.getNameList().first());
    }
    if (mOptionMap.contains(newOption.getOptionName()))
        return false;

    if (option.getPosition())
    {
        newOption.setPosition(mPositionalNameList.size());
        mPositionalNameList.append(option.getOptionName());
    }

    return true;
}

bool CommandLineOptions::remove(const BasicName & name)
{
    return false;
}
