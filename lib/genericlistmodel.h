#ifndef GENERICLISTMODEL_H
#define GENERICLISTMODEL_H

#include "../lib/property.h"
#include <QAbstractListModel>

class GenericListModel : public QAbstractListModel
{
public:
    GenericListModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    /*!
     * \brief data
     * Get data of a property from the model
     * \param index
     * \param role
     * \return 
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

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
    bool appendProperty(const Property &property);

    bool removeProperty(const Property &property);
    bool removeProperty(const QString &propertyname);
    bool removeProperty(const int &index);
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
};

#endif // GENERICLISTMODEL_H
