#include "generictablemodel.h"

GenericTableModel::GenericTableModel(QObject *parent) : QAbstractTableModel(parent) {}

int GenericTableModel::rowCount(const QModelIndex &parent) const
{
    return m_properties.length();
}

int GenericTableModel::columnCount(const QModelIndex &parent) const
{
    return Columns::ColumnCount;
}

QModelIndex GenericTableModel::index(int row, int column, const QModelIndex &parent) const
{
    if (row < 0 || row > rowCount() - 1 || column < 0 || column > columnCount() - 1)
        return QModelIndex();

    return createIndex(row, column, m_properties[row]);
}

Qt::ItemFlags GenericTableModel::flags(const QModelIndex &index) const
{
    if (index.isValid())
        return Qt::ItemFlag::NoItemFlags;

    if (index.column() == Columns::Value) {
        return Qt::ItemFlag::ItemIsEditable;
    }

    return Qt::ItemFlags(Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable);
}

QVariant GenericTableModel::data(const QModelIndex &index, int role) const
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

bool GenericTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
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

bool GenericTableModel::appendProperty(const Property &property)
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

    QModelIndex idx = createIndex(first, Columns::Value, m_properties[m_properties.length() - 1]);
    setData(idx, property.value());

    return true;
}

bool GenericTableModel::removeProperty(const Property &property)
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

bool GenericTableModel::removeProperty(const QString &propertyname)
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

bool GenericTableModel::removeProperty(const int &index)
{
    if (index < 0)
        return false;

    if (index >= m_properties.length())
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

bool GenericTableModel::updateProperty(const Property property)
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
