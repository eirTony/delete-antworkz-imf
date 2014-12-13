/*! @file   CommandLineProcessing.cpp   AntWorkz TypeLib CommandLineOption definition
 */
#include "CommandLineProcessing.h"

CommandLineProcessing::CommandLineProcessing(QObject * parent)
    : QObject(parent)
{
}

#if 0
CommandLineProcessing::CommandLineProcessing(const ExecutableSupport * exe)
    : QObject(exe)
    , mpExecutableSupport(exe)
{
}
#endif
