/*! @file   QQVariant.h   AntWorkz TypeLib QQVariant declaration
 */
#ifndef QQVARIANT_H
#define QQVARIANT_H
#include "TypeLib.h"

#include <QVariant>

/*! @class QQVariant
 * @brief The QQVariant class extends Qt's QVariant class.
 *
 * @since TypeLib version 2.03
 */
class TYPESHARED_EXPORT QQVariant : public QVariant
{
public:
    QQVariant(void);
    QQVariant(const QVariant & other);
};

#endif // QQVARIANT_H
