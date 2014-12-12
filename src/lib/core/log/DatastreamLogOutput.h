#ifndef DATASTREAMLOGOUTPUT_H
#define DATASTREAMLOGOUTPUT_H

#include "LogOutputPlugin.h"

class DatastreamLogOutput : public LogOutputPlugin
{
    Q_OBJECT

    // handles datastrm, but not textstrm

public:
    explicit DatastreamLogOutput(LogFork * fork,
                                 QObject * parent=0);

signals:

public slots:

private: //static
    const static BasicName csmPluginName;
    const static EightCC csmDatastrmEcc;
    const static EightCCList csmSchemataList;
};

#endif // DATASTREAMLOGOUTPUT_H
