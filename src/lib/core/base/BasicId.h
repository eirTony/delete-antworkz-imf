#ifndef BASICID_H
#define BASICID_H
#include "BaseLib.h"

#include <QList>
#include <QMap>
#include <QString>
#include <QVariant>

class BASESHARED_EXPORT BasicId : public QString
{
public:
    typedef QList<BasicId> List;
    typedef QMap<BasicId, QVariant> VariantMap;

public:
    BasicId(const QString & string=QString());
    BasicId(const char * const chars);
};
/*! @class BasicId <core/BasicId.h.
 * @brief BasicId class provides a multipart identification string
 * @since BasicId was strted in v2.02
 * @ingroup BaseLib
 * @sa BasicName
 * @sa BasicKey
 *
 * BasicId instances are a sequence of BasicName instances separated
 * by a '/' segment delimtor.
 */

#endif // BASICID_H
