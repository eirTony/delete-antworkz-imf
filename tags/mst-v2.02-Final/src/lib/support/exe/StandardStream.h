#ifndef STANDARDSTREAM_H
#define STANDARDSTREAM_H

class QTextStream;

#include "BaseSerialStream.h"


class StandardStream : public BaseSerialStream
{
public:
    StandardStream(QObject * parent=0);
    virtual QString readLine(void);
    virtual bool writeLine(const QString & line);
    virtual bool writeError(const QString & error);

private:
    QTextStream * mpStdinStream  = 0;
    QTextStream * mpStdoutStream = 0;
    QTextStream * mpStderrStream = 0;
};

#endif // STANDARDSTREAM_H
