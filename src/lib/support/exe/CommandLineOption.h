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
#include <data/DataType.h>

#define COMMANDLINEOPTION_DATAPROPS(TND) \
    TND(BasicName,      OptionName,     BasicName()) \
    TND(QQChar,         SingleChar,     QQChar()) \
    TND(BasicNameList,  NameList,       BasicNameList()) \
    TND(QQString,       Description,    QQString()) \
    TND(QQVariant,      DefaultValue,   QQVariant()) \
    TND(int,            DataType,       0) \
    TND(QQString,       Syntax,         QQString()) \
    TND(int,            Position,       0) \
    TND(QQVariant,      Value,          QQVariant()) \

class CommandLineOptionData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(COMMANDLINEOPTION_DATAPROPS)
public:
    CommandLineOptionData(void)
    {
        DEFINE_DATAPROPS_CTORS(COMMANDLINEOPTION_DATAPROPS)
    }
};
/*! @class CommandLineOptionData CommandLineOption.h "exe/CommandLineOption.h"
 * @internal
 */

class EXESHARED_EXPORT CommandLineOption
{
public:
    DECLARE_PARENT_DATAPROPS(COMMANDLINEOPTION_DATAPROPS)
    DECLARE_DATAPROPS(CommandLineOption, CommandLineOptionData)

public:
    void Positional(const DataType dt,
                    const BasicName & argName,
                    const QQString & syntax,
                    const QQString & description=QQString());
    void Option(const DataType dt,
                const QQChar singleChar,
                const BasicNameList &optNames,
                const QQString & description=QQString(),
                const BasicName & valueName=BasicName(),
                const QQVariant & defaultValue=QQVariant());
    void Option(const DataType dt,
                const BasicName & optName,
                const QQString & description=QQString(),
                const BasicName & valueName=BasicName(),
                const QQVariant & defaultValue=QQVariant());
    bool isValid(void) const;
};
/*! @class CommandLineOption CommandLineOption.h "exe/CommandLineOption.h"
 * @breif The CommandLineOption class contains each for CommandLineProcessing
 * @todo Change DataType from int to DataLib:DataType when it matures.
 * @since ExeLib version 2.03
 *
 * Each item can represent one of:
 *  * Positional Argument
 *  * Named Argument
 *  * Command Line Option with optional single char or multiple name options
 *  * Special Option, like Help and Version
 *
 *
 */

#endif // COMMANDLINEOPTION_H
