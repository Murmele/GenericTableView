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
        //Only possible when widget gets not destroyed in destroy Editor
        QWidget *w = p->widget->widget();
        w->setParent(parent);
        return w;
    }

    return nullptr;
}

void GenericTableDelegator::destroyEditor(QWidget *editor, const QModelIndex &index) const
{
    // Do not destory the editor, because it is stored in the Property.
    // By default createEditor() returns a new object and GenericTableDelegator takes over and
    // at the end of editing, the editor gets deleted. We wanna reuse the editor and therefore
    // it should not be deleted.
}
