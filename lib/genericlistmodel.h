#ifndef GENERICLISTMODEL_H
#define GENERICLISTMODEL_H

#include "../lib/property.h"
#include <QAbstractListModel>

class GenericListModel : public QAbstractListModel
{
public:
    GenericListModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool addProperty()
};

#endif // GENERICLISTMODEL_H
