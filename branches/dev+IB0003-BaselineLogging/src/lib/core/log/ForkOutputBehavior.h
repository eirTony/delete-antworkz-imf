#ifndef FORKOUTPUTBEHAVIOR_H
#define FORKOUTPUTBEHAVIOR_H
#include "LogLib.h"

#include <QString>
#include <QUrl>

#include <base/BasicName.h>
#include <type/CharCode.h>

#include "Severity.h"

class ForkOutputBehavior
{
public:
    bool setUrlVars(const QUrl & url);
    bool isWritable(void) const;
    bool isError(void) const;
    QString errorString(void) const;

public: // virtual
    virtual ~ForkOutputBehavior() {}

public: // pure virtual
    virtual bool open(const QUrl & url) = 0;
    virtual bool write(const Severity severity,
                       const QString & message) = 0;
    virtual bool flush(void) = 0;
    virtual void close(void) = 0;

private: // static
    static ForkOutputBehavior * forScheme(const BasicName scheme);

protected:
    ForkOutputBehavior(const BasicNameList & schemeNames,
                       const BasicName metaName);
    bool setWritable(const bool writable=true);
    bool setError(const QString & error);

protected: // static
    static void registerSchemes(const EightCCList & schemeEccs,
                                const BasicName & metaName);


private:
    BasicNameList mSchemeNames;
    EightCCList mRegisteredEccs;
    QUrl mUrl;
    EightCC mSchemeEcc;
    BasicNameMap<QString> mUrlOptionMap;
    bool mWritable;
    QString mErrorString;

private: // static
    static QHash<EightCC, BasicName> smEccMetaHash;
};
#endif // FORKOUTPUTBEHAVIOR_H
