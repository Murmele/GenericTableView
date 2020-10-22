#include "generictablemodel.h"

GenericTableModel::GenericTableModel(QObject *parent) : QAbstractTableModel(parent) {}

int GenericTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_properties.length();
}

int GenericTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return Columns::ColumnCount;
}

QVariant GenericTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (section < 0 || section >= m_header.length())
        return QVariant();

    if (orientation == Qt::Orientation::Horizontal && role == Qt::DisplayRole)
        return m_header[section];

    return QVariant();
}

QModelIndex GenericTableModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    if (row < 0 || row > rowCount() - 1 || column < 0 || column > columnCount() - 1)
        return QModelIndex();

    return createIndex(row, column, m_properties[row]);
}

Qt::ItemFlags GenericTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemFlag::NoItemFlags;

    if (index.column() == Columns::Value) {
        return Qt::ItemFlags(Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable
                             | Qt::ItemFlag::ItemIsEditable);
    }

    return Qt::ItemFlags(Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable);
}

bool GenericTableModel::setHeader(QStringList &header)
{
    if (header.length() != ColumnCount)
        return false;

    m_header = header;

    emit headerDataChanged(Qt::Orientation::Horizontal, 0, m_header.length() - 1);
    return true;
}

QVariant GenericTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

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

bool GenericTableModel::appendProperty(const Property &property, const QVariant initialValue)
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
    if (initialValue.isValid()) {
        // check if valid value
        if (property.widget->validValue(initialValue))
            setData(idx, initialValue);
        else // set default valid value
            setData(idx, property.widget->initialValue());
    } else
        setData(idx, property.widget->widgetValue());

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

    if (m_properties[index]->required)
        return false; // if the property is required, it is not possible to delete it

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
