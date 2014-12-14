/*! @file   CommandLineResult.h   AntWorkz ExeLib CommandLineOption definition
 */
#ifndef COMMANDLINERESULT_H
#define COMMANDLINERESULT_H
#include "ExeLib.h"

#include <base/BasicNameMap.h>
#include <type/QQStringList.h>

#include "ArgumentSourcePair.h"
#include "CommandLineOption.h"

class EXESHARED_EXPORT CommandLineResult
{
public:
    CommandLineResult(void);
    bool ingestOption(const CommandLineOption & option);

private:
    QQStringList mRawArgumentList;
    ArgumentSourcePair::List mExpandedArgumentSourceList;
    BasicNameMap<int> mPositionalNameIndexMap;
    QQStringList mPositionalArgumentList;
    QQStringList mOtherArgumentList;
    BasicNameMap<int> mOptionNameIndexMap;
    QQStringList mSpecifiedOptionMap;
    QQStringList mDefaultOptionMap;
};

#endif // COMMANDLINERESULT_H
