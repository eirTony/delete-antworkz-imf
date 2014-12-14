#ifndef READABLELOGOUTPUT_H
#define READABLELOGOUTPUT_H

#include "LogOutputPlugin.h"

#include <type/QQDataStream.h>
#include <type/QQFile.h>

class ReadableLogOutput : public LogOutputPlugin
{
    Q_OBJECT

    // handles stdout, stderr, logfile

public:
    explicit ReadableLogOutput(LogFork * fork,
                               QObject * parent=0);

signals:

public slots:

private:
    QQDataStream * mpStream = 0;
    QQFile * mpFile = 0;

private: //static
    const static BasicName csmPluginName;
    const static EightCC csmStdoutEcc;
    const static EightCC csmStderrEcc;
    const static EightCC csmLogFileEcc;
    const static EightCCList csmSchemataList;
};

#endif // READABLELOGOUTPUT_H
