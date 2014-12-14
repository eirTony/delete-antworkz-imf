/*! @file   FunctionInfo.cpp BaseLib FunctionInfo class definitions
 */

#include "FunctionInfo.h"

#include <QtDebug>

DEFINE_DATAPROPS(FunctionInfo, FunctionInfoData)

void FunctionInfo::ctor(void) {}
void FunctionInfo::dtor(void) {}

FunctionInfo::FunctionInfo(const int fileLine,
                           const QString & fileName,
                           const QString & prettyFunction)
{
    ctor();
    set(prettyFunction, fileName, 0, fileLine);
}

FunctionInfo::FunctionInfo(const QString & prettyFunction,
                           const QString & fileName,
                           const int functionLine)
{
    ctor();
    set(prettyFunction, fileName, functionLine, functionLine);
}

void FunctionInfo::set(const QString & prettyFunction,
                       const QString & fileName,
                       const int functionLine,
                       const int fileLine)
{
    (void)prettyFunction; (void)fileName;
    (void)functionLine; (void)fileLine;
    qWarning("TODO: FunctionInfo::set()");
}
