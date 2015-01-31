#include "SerialExecutable.h"

#include "BaseSerialStream.h"

SerialExecutable::SerialExecutable(BaseSerialStream * textStream)
    : ExecutableSupport(ExecutableSupport::Serial)
{
    setStream(textStream);
}

void SerialExecutable::setStream(BaseSerialStream *textStream)
{
    mpSerialStream = textStream;
}

BaseSerialStream *SerialExecutable::stream(void)
{
    return mpSerialStream;
}

QChar SerialExecutable::readChar(void)
{
    return mpSerialStream ? mpSerialStream->readChar() : QChar();
}

QString SerialExecutable::readLine(void)
{
    return mpSerialStream ? mpSerialStream->readLine() : QString();
}

bool SerialExecutable::writeLine(const QString & line)
{
    return mpSerialStream ? mpSerialStream->writeLine(line) : false;
}

bool SerialExecutable::writeError(const QString & error)
{
    return mpSerialStream ? mpSerialStream->writeError(error) : false;
}


void SerialExecutable::initialize(void)
{
    ExecutableSupport::initialize();
    // do stuff
}

void SerialExecutable::setup(void)
{
    ExecutableSupport::setup();
    // do stuff
}

void SerialExecutable::start(void)
{
    ExecutableSupport::start();
    // do stuff
}
