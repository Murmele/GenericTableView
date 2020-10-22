#include "genericlistdelegator.h"

#include "genericlistmodel.h"
#include "property.h"

GenericListDelegator::GenericListDelegator(QObject *parent) : QStyledItemDelegate(parent) {}

QWidget *GenericListDelegator::createEditor(QWidget *parent,
                                            const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const
{
    if (index.column() == GenericListModel::Columns::Description)
        return nullptr;
    else if (index.column() == GenericListModel::Columns::Value) {
        Property *p = static_cast<Property *>(index.internalPointer());
        return p->widget;
    }

    return nullptr;
}
