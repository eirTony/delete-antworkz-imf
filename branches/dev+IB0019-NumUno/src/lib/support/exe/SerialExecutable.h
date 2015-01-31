#ifndef SERIALEXECUTABLE_H
#define SERIALEXECUTABLE_H
#include "ExeLib.h"

#include "ExecutableSupport.h"

class BaseSerialStream;

class EXESHARED_EXPORT SerialExecutable : public ExecutableSupport
{
    Q_OBJECT
public:
    void setStream(BaseSerialStream * textStream);
    BaseSerialStream * stream(void);
    QChar readChar(void);
    QString readLine(void);
    bool writeLine(const QString & line);
    bool writeError(const QString & error);
signals:

public slots:
    void initialize(void);
    void setup(void);
    void start(void);

protected:
    SerialExecutable(BaseSerialStream * textStream=0);

private:
    BaseSerialStream * mpSerialStream = 0;
};

#endif // SERIALEXECUTABLE_H
