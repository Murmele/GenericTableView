#ifndef GENERICTABLEMODEL_H
#define GENERICTABLEMODEL_H

#include "../lib/property.h"
#include <QAbstractTableModel>

class GenericTableModel : public QAbstractTableModel
{
public:
    GenericTableModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    /*!
     * \brief data
     * Get data of a property from the model
     * \param index
     * \param role
     * \return 
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setHeader(QStringList &header);
    QStringList header() { return m_header; }
    QVector<Property *> properties() { return m_properties; }

    enum UserRoles {
        Widget = Qt::UserRole + 1,
    };

    /*!
     * \brief addProperty
     * Add a new property. If a property with the same name already exists, the
     * property will not be added and false is returned
     * \param property
     * \return true if the property was added successfully, else false
     */
    bool appendProperty(const Property &property, const QVariant initialValue = QVariant());

    bool removeProperty(const Property &property);
    bool removeProperty(const QString &propertyname);
    bool removeProperty(const int &index);
    /*!
     * \brief removeProperties
     * Remove multiple properties at the same time. \p endIndex is the last index which will be removed
     * \param startIndex
     * \param endIndex
     * \return
     */
    bool removeProperties(const int startIndex, const int endIndex);
    /*!
     * \brief clear
     * Remove all properties
     */
    void clear();
    /*!
     * \brief updateProperty
     * Replace the property in m_properties by property if the name matches
     * \param propertyname
     * \param value
     * \return true if the property was updated, false if the property was not found
     */
    bool updateProperty(const Property property);

    enum Columns {
        Description = 0,
        Value = 1,  // Values are stored in the second column
        ColumnCount // counts the columns
    };

private:
    QVector<Property *> m_properties; // contains all properties in the model
    QStringList m_header;
};

#endif // GENERICTABLEMODEL_H
