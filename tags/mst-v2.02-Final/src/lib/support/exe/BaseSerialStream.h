#ifndef BASESERIALSTREAM_H
#define BASESERIALSTREAM_H

#include <QObject>

#include <QIODevice>

class BaseSerialStream : public QObject
{
    Q_OBJECT
public:
    explicit BaseSerialStream(QObject * parent=0);
    virtual bool open(const QIODevice::OpenMode mode=QIODevice::ReadWrite
                                                   | QIODevice::Text) {}
    virtual QString readLine(void) { return QString(); }
    virtual bool writeLine(const QString & line) { return false; }
    virtual bool writeError(const QString & error) { return false;}
    virtual bool flush(void) { return false; }
    virtual void close(void) {}

signals:

public slots:

};

#endif // BASESERIALSTREAM_H
