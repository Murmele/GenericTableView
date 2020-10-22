#ifndef GENERICTABLEDELEGATOR_H
#define GENERICTABLEDELEGATOR_H

#include <QStyledItemDelegate>

class GenericTableDelegator : public QStyledItemDelegate
{
public:
    GenericTableDelegator(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
};

#endif // GENERICTABLEDELEGATOR_H
