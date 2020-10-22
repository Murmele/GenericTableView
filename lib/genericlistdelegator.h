#ifndef GENERICLISTDELEGATOR_H
#define GENERICLISTDELEGATOR_H

#include <QStyledItemDelegate>

class GenericListDelegator : public QStyledItemDelegate
{
public:
    GenericListDelegator(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
};

#endif // GENERICLISTDELEGATOR_H
