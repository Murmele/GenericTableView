#include "genericlistmodel.h"

GenericListModel::GenericListModel(QObject *parent) : QAbstractListModel(parent) {}

int GenericListModel::rowCount(const QModelIndex &parent) const
{
    return m_properties.length();
}

int GenericListModel::columnCount(const QModelIndex &parent) const
{
    int count = Columns::ColumnCount;
    return Columns::ColumnCount;
}

QModelIndex GenericListModel::index(int row, int column, const QModelIndex &parent) const
{
    if (row < 0 || row > rowCount() - 1 || column < 0 || column > columnCount() - 1)
        return QModelIndex();

    return createIndex(row, column, m_properties[row]);
}

QVariant GenericListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int column = index.column();
    if (column != 0)
        int stop = 1;

    Property *p = static_cast<Property *>(index.internalPointer());

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        if (index.column() == Columns::Description)
            return p->name;
        else if (index.column() == Columns::Value)
            return p->value();
    }
    return QVariant();
}

bool GenericListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;

    Property *p = static_cast<Property *>(index.internalPointer());
    if (p) {
        bool success = p->setValue(value);
        if (success) {
            emit dataChanged(index, index, {role});
            return true;
        }
    }

    return false;
}

bool GenericListModel::appendProperty(const Property &property)
{
    for (Property *p : m_properties) {
        if (p->name == property.name) {
            return false;
        }
    }

    int first = m_properties.length();
    int last = m_properties.length();
    beginInsertRows(QModelIndex(), first, last);
    // TODO: check if the parameters are applied
    m_properties.append(new Property(property));
    endInsertRows();

    QModelIndex idx = createIndex(first, 2, m_properties[m_properties.length() - 1]);
    setData(idx, property.value());

    return true;
}

bool GenericListModel::removeProperty(const Property &property)
{
    int index = -1;
    for (int i = 0; i < m_properties.length(); i++) {
        if (m_properties[i]->name == property.name) {
            index = i;
            break;
        }
    }

    return removeProperty(index);
}

bool GenericListModel::removeProperty(const QString &propertyname)
{
    int index = -1;
    for (int i = 0; i < m_properties.length(); i++) {
        if (m_properties[i]->name == propertyname) {
            index = i;
            break;
        }
    }

    return removeProperty(index);
}

bool GenericListModel::removeProperty(const int &index)
{
    if (index < 0)
        return false;

    int first = index;
    int last = index;
    beginRemoveRows(QModelIndex(), first, last);
    // TODO: check if the parameters are removed correctly
    delete m_properties[index];
    m_properties.remove(index);
    endRemoveRows();

    return true;
}

bool GenericListModel::updateProperty(const Property property)
{
    for (int i = 0; i < m_properties.length(); i++) {
        if (m_properties[i]->name == property.name) {
            *m_properties[i] = property;
            QModelIndex index = createIndex(i, Columns::Value, m_properties[i]);
            emit dataChanged(index, index, {Qt::DisplayRole});
            return true;
        }
    }

    return false;
}
