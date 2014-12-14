#include "DatastreamLogOutput.h"

const BasicName DatastreamLogOutput::csmPluginName("Datastream");
const EightCC DatastreamLogOutput::csmDatastrmEcc("datastrm");
const EightCCList DatastreamLogOutput::csmSchemataList(EightCCList()
                                                       << csmDatastrmEcc);

DatastreamLogOutput::DatastreamLogOutput(LogFork * fork,
                                         QObject * parent)
    : LogOutputPlugin(csmPluginName,
                      EightCCList() << csmDatastrmEcc,
                      fork,
                      parent)
{
}
