#include "genericlistmodel.h"

GenericListModel::GenericListModel(QObject *parent) : QAbstractListModel(parent) {}

int GenericListModel::rowCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant GenericListModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}
