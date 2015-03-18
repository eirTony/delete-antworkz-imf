#ifndef BASICJOURNALITEM_H
#define BASICJOURNALITEM_H
#include "../BaseLib.h"

#include <QPair>
#include <QVariant>

#include "../BasicName.h"

class BASESHARED_EXPORT BasicJournalItem : public QPair<BasicName, QVariant>
{
public:
    BasicJournalItem(const BasicName & name,
                     const QVariant & var);
};

#endif // BASICJOURNALITEM_H
