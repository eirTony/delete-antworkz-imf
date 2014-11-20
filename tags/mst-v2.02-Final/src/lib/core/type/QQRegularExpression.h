#ifndef QQREGULAREXPRESSION_H
#define QQREGULAREXPRESSION_H

#include <QRegularExpression>

class QQRegularExpression : public QRegularExpression
{
public:
    QQRegularExpression(void);
    QQRegularExpression(const QString & string,
                        const PatternOptions options=NoPatternOption);

    static QQRegularExpression VariableName(void);
private:
    const static QQRegularExpression csVariableName_rx;
};

#endif // QQREGULAREXPRESSION_H
