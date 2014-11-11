/*! @file   CommandLineOption.h   AntWorkz ExeLib CommandLineOption definition
 */
#ifndef COMMANDLINEOPTION_H
#define COMMANDLINEOPTION_H
#include "ExeLib.h"

#include <base/BasicName.h>
#include <type/DProperty.h>
#include <type/QQChar.h>
#include <type/QQString.h>
#include <type/QQVariant.h>

#define COMMANDLINEOPTION_DATAPROPS(TND) \
    TND(BasicName, OptionName, BasicName()) \
    TND(int, OptionType, 0) \
    TND(QQChar, SingleChar, QChar()) \
    TND(BasicNameList, NameList, BasicNameList()) \
    TND(QQString, Description, QQString()) \
    TND(QQVariant, DefaultValue, QQVariant()) \
    TND(int, DataType, 0) \
    TND(QQString, Syntax, QQString()) \
    TND(int, Position, -1) \
    TND(QQVariant, Value, QQVariant()) \

class CommandLineOptionData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(COMMANDLINEOPTION_DATAPROPS)
public:
    CommandLineOptionData(void)
    {
        DEFINE_DATAPROPS_CTORS(COMMANDLINEOPTION_DATAPROPS)
    }
};

/*! @class CommandLineOption
 * @breif The CommandLineOption class contains each for CommandLineProcessing
 *
 * Each item can represent one of:
 *  * Positional Argument
 *  * Named Argument
 *  * Command Line Option with optional single char or multiple name options
 *  * Special Option, like Help and TBD
 *
 * @since ExeLib version 2.03
 */
class EXESHARED_EXPORT CommandLineOption
{
    DECLARE_PARENT_DATAPROPS(COMMANDLINEOPTION_DATAPROPS)
    DECLARE_DATAPROPS(CommandLineOption, CommandLineOptionData)
};

#endif // COMMANDLINEOPTION_H
