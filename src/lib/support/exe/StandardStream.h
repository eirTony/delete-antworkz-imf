#ifndef STANDARDSTREAM_H
#define STANDARDSTREAM_H

#include <QChar>
#include <QQueue>
class QTextStream;


#include "BaseSerialStream.h"


class StandardStream : public BaseSerialStream
{
    Q_OBJECT

public:
    StandardStream(QObject * parent=0);
    virtual QChar readChar(void);
    virtual QString readLine(void);
    virtual bool writeLine(const QString & line);
    virtual bool writeError(const QString & error);

signals:
    void readyRead(void);

public slots:
    void streamReadyRead(void);

private:
    QTextStream * mpStdinStream  = 0;
    QTextStream * mpStdoutStream = 0;
    QTextStream * mpStderrStream = 0;
    QQueue<QChar> mReadQueue;
};

#endif // STANDARDSTREAM_H
