/*! @file   CommandLineProcessing.h   AntWorkz ExeLib CommandLineOption definition
 */
#ifndef COMMANDLINEPROCESSING_H
#define COMMANDLINEPROCESSING_H
#include "ExeLib.h"

#include <QObject>

#include "CommandLineResult.h"
class CommandLineOptions;
class ExecutableSupport;

class EXESHARED_EXPORT CommandLineProcessing : public QObject
{
    Q_OBJECT

public:
    CommandLineProcessing(QObject * parent=0);
//  CommandLineProcessing(const ExecutableSupport * exe);
    void setExecutableSupport(const ExecutableSupport * exe);
    void setCommandLineOptions(const CommandLineOptions & options);
    CommandLineResult result(void) const;

signals:
    void processed(void);
    void processed(CommandLineResult result);

public slots:
    void process(void) {}
    void process(const CommandLineOptions & options) {}

private:
    ExecutableSupport * mpExecutableSupport = 0;
    CommandLineResult mCommandLineResult;
};

#endif // COMMANDLINEPROCESSING_H
