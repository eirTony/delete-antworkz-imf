#include "QQRegularExpression.h"

const QQRegularExpression
    QQRegularExpression::csVariableName_rx("^[A~Z_a~z][A~Z_a~z0~9]*$");

QQRegularExpression::QQRegularExpression(void)
{
}

QQRegularExpression::QQRegularExpression(const QString & string,
                                         const PatternOptions options)
    : QRegularExpression(string, options) {}

QQRegularExpression QQRegularExpression::VariableName(void)
{
    return csVariableName_rx;
}
