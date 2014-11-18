#ifndef BUILTINOUTPUTBEHAVIOR_H
#define BUILTINOUTPUTBEHAVIOR_H
#include "LogLib.h"

#include "ForkOutputBehavior.h"

class LOGSHARED_EXPORT BuiltinOutputBehavior : public ForkOutputBehavior
{
public:
    BuiltinOutputBehavior(const QUrl & url=QUrl());
    bool setUrl(const QUrl & url);

public: // virtual

public: // pure virtual implementations
    virtual bool open(const QUrl & url);
    virtual bool write(const Severity severity,
                       const QString & message);
    virtual bool flush(void);
    virtual void close(void);

};

#endif // BUILTINOUTPUTBEHAVIOR_H
