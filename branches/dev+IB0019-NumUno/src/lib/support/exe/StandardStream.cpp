#include "StandardStream.h"

#include <QTextStream>

StandardStream::StandardStream(QObject * parent)
    : BaseSerialStream(parent)
{
    mpStdinStream  = new QTextStream(stdin);
    mpStdoutStream = new QTextStream(stdout);
    mpStderrStream = new QTextStream(stderr);

    Q_ASSERT(QTextStream::Ok == mpStdinStream->status());

    Q_ASSERT(connect(mpStdinStream->device(), SIGNAL(readyRead()),
                     this, SLOT(streamReadyRead())));
}

QChar StandardStream::readChar(void)
{
    return mReadQueue.isEmpty() ? QChar() : mReadQueue.dequeue();
}

QString StandardStream::readLine(void)
{
    return mpStdinStream ? mpStdinStream->readLine() : QString();
}

bool StandardStream::writeLine(const QString & line)
{
    if ( ! mpStdoutStream) return false;
    *mpStdoutStream << line << endl;
    return true;
}

bool StandardStream::writeError(const QString & error)
{
    if ( ! mpStderrStream) return false;
    *mpStderrStream << error << endl;
    return true;
}

void StandardStream::streamReadyRead(void)
{
    Q_ASSERT(mpStdinStream);
    QChar c;
    while ( ! mpStdinStream->atEnd())
    {
        *mpStdinStream >> c;
        mReadQueue.enqueue(c);
    }
    emit readyRead();
}
