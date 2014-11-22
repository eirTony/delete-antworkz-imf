#ifndef BUILTINOUTPUTBEHAVIOR_H
#define BUILTINOUTPUTBEHAVIOR_H
#include "LogLib.h"

#include "ForkOutputBehavior.h"

class LOGSHARED_EXPORT BuiltinOutputBehavior : public ForkOutputBehavior
{
public:
    BuiltinOutputBehavior(void);
    bool setUrl(const QUrl & url);

public: // virtual

public: // pure virtual implementations
    virtual bool open(void);
    virtual bool write(const Severity severity,
                       const QString & message);
    virtual bool flush(void);
    virtual void close(void);

public: // static
    const static BasicNameList mSchemeNames;
    const static EightCCList mRegisteredEccs;
    const static QByteArray csmMetaName;

};

#endif // BUILTINOUTPUTBEHAVIOR_H
