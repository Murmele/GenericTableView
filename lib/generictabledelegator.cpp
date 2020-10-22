#include "generictabledelegator.h"

#include "generictablemodel.h"
#include "property.h"

GenericTableDelegator::GenericTableDelegator(QObject *parent) : QStyledItemDelegate(parent) {}

QWidget *GenericTableDelegator::createEditor(QWidget *parent,
                                            const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const
{
    if (index.column() == GenericTableModel::Columns::Description)
        return nullptr;
    else if (index.column() == GenericTableModel::Columns::Value) {
        Property *p = static_cast<Property *>(index.internalPointer());
        return p->widget;
    }

    return nullptr;
}
