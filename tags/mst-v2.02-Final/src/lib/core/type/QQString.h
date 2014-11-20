#ifndef QQSTRING_H
#define QQSTRING_H

#include <QString>

class QQString : public QString
{
public:
    enum Squeeze
    {
        SqueezeNull = 0,
        SqueezeAll,
        //...
        SqueezeSize
    };

public:
    QQString(void);
    QQString(const QString & other);
    QQString(const QString & other,
             const QRegularExpression & allowRx);
    static QString allowed(const QQString &other,
                           const QRegularExpression & re);
    QString allowed(const QRegularExpression & re) const;
    QString allowed(const QRegularExpression & re,
                    const QString & replace) const;
    QString sortable(void) const;
    QString squeezed(const Squeeze Action) const;
    void squeeze(const Squeeze action);
    static bool isValid(const QQString &other,
                        const QRegularExpression &re);
    bool isValid(const QRegularExpression & re) const;
    QString validated(const QRegularExpression & re) const;
    void validate(const QRegularExpression & re);
};

#endif // QQSTRING_H
