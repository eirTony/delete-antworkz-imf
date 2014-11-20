/*! @file   BaseNameIdBehavior.h BaseNameIdBehavior class declaration
 */
#ifndef BASEIDBEHAVIOR_H
#define BASEIDBEHAVIOR_H

#include <QRegularExpression>
#include <QString>

class BaseNameIdBehavior
{
public:
    bool isId(void) const;
    QString separator(void) const;
    QRegularExpression allowRE(void) const;
    QRegularExpression firstRE(void) const;
    QString initializeName(const QString & name) const;
    QString initializeId(const QString & name) const;

private:
    BaseNameIdBehavior(void);
};

#endif // BASEIDBEHAVIOR_H
