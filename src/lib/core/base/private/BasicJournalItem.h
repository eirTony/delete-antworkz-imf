#ifndef BASICJOURNALITEM_H
#define BASICJOURNALITEM_H

#include <QPair>
#include <QVariant>

#include "../BasicName.h"

class BasicJournalItem : public QPair<BasicName, QVariant>
{
public:
    BasicJournalItem(const BasicName & name,
                     const QVariant & var);
};

#endif // BASICJOURNALITEM_H
