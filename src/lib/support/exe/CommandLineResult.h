/*! @file   CommandLineResult.h   AntWorkz ExeLib CommandLineOption definition
 */
#ifndef COMMANDLINERESULT_H
#define COMMANDLINERESULT_H

#include <type/QQStringList.h>

class CommandLineResult
{
public:
    CommandLineResult(void);

private:
    QQStringList mRawArgumentList;
};

#endif // COMMANDLINERESULT_H
