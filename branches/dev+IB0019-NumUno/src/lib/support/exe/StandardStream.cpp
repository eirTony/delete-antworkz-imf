#include "StandardStream.h"

#include <QTextStream>

StandardStream::StandardStream(QObject * parent)
    : BaseSerialStream(parent)
{
    mpStdinStream  = new QTextStream(stdin,  QIODevice::ReadOnly);
    mpStdoutStream = new QTextStream(stdout, QIODevice::WriteOnly);
    mpStderrStream = new QTextStream(stderr, QIODevice::WriteOnly);

    connect(mpStdinStream->device(), SIGNAL(readyRead()),
            this, SLOT(streamReadyRead()));
}

QChar StandardStream::readChar(void)
{
    if ( ! mpStdinStream)   return QChar();
    QString s = mpStdinStream->read(1);
    return s.isEmpty() ? QChar() : s[0];
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
    emit readyRead();
}
