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
    Q_UNUSED(editor)
    Q_UNUSED(index)
    // Do not destory the editor, because it is stored in the Property.
    // By default createEditor() returns a new object and GenericTableDelegator takes over and
    // at the end of editing, the editor gets deleted. We wanna reuse the editor and therefore
    // it should not be deleted.
}

void GenericTableDelegator::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    // Works, but not needed, because the data of the editor is the same as the data for the model
    //    if (!index.isValid())
    //        return;

    //    QVariant val = index.model()->data(index, Qt::EditRole);

    //    Property *p = static_cast<Property *>(index.internalPointer());
    //    p->setValue(val);
}

void GenericTableDelegator::setModelData(QWidget *editor,
                                         QAbstractItemModel *model,
                                         const QModelIndex &index) const
{
    if (!index.isValid())
        return;

    Property *p = static_cast<Property *>(index.internalPointer());
    QVariant value = p->value();
    model->setData(index, value, Qt::EditRole);
}

void GenericTableDelegator::updateEditorGeometry(QWidget *editor,
                                                 const QStyleOptionViewItem &option,
                                                 const QModelIndex &index) const
{
    if (!index.isValid())
        return;

    editor->setGeometry(option.rect);
}
