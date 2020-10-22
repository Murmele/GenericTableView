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
    void destroyEditor(QWidget *editor, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;
};

#endif // GENERICTABLEDELEGATOR_H
