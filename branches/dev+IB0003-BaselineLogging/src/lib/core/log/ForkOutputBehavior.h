#ifndef FORKOUTPUTBEHAVIOR_H
#define FORKOUTPUTBEHAVIOR_H
#include "LogLib.h"

#include <QString>
#include <QUrl>

#include <base/BasicName.h>
#include <type/CharCode.h>

#include "Severity.h"
class LogFork;

class ForkOutputBehavior
{
public:
    void setFork(LogFork * const fork);
    void setUrl(const QUrl & url);
    void setScheme(const EightCC scheme);

public: // virtual
    virtual ~ForkOutputBehavior() {}

public: // pure virtual
    virtual bool open(void) = 0;
    virtual bool write(const Severity severity,
                       const QString & message) = 0;
    virtual bool flush(void) = 0;
    virtual void close(void) = 0;

public: // static
    static void registerSchemes(const EightCCList & schemeEccs,
                                const QByteArray & metaName);
    static ForkOutputBehavior * forScheme(const EightCC schemeEcc);

protected:
    ForkOutputBehavior(void);

private:
    LogFork * mpFork;
    EightCC mSchemeEcc;
    QUrl mUrl;

private: // static
    static QHash<EightCC, QByteArray> smEccMetaHash;
};
#endif // FORKOUTPUTBEHAVIOR_H
