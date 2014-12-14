#include "ReadableLogOutput.h"

const BasicName ReadableLogOutput::csmPluginName("Readable");
const EightCC ReadableLogOutput::csmStdoutEcc("stdout");
const EightCC ReadableLogOutput::csmStderrEcc("stderr");
const EightCC ReadableLogOutput::csmLogFileEcc("logfile");
const EightCCList ReadableLogOutput::csmSchemataList(EightCCList()
                                                     << csmStdoutEcc
                                                     << csmStderrEcc
                                                     << csmLogFileEcc);

ReadableLogOutput::ReadableLogOutput(LogFork * fork, QObject *parent)
    : LogOutputPlugin(csmPluginName,
                      csmSchemataList,
                      fork,
                      parent)

{
}
