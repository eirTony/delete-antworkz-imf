/*! @file   QQChar.h   AntWorkz TypeLib QQChar declaration
 */
#ifndef QQCHAR_H
#define QQCHAR_H
#include "TypeLib.h"

#include <QChar>

/*! @class QQChar
 * @brief The QQChar class extends Qt's QChar class.
 *
 * @since TypeLib version 2.03
 */
class TYPESHARED_EXPORT QQChar : public QChar
{
public:
    QQChar(void);
    QQChar(const QChar other);
    QQChar(char c);
};

#endif // QQCHAR_H
