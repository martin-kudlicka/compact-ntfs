#include "pch.h"
#include "locationsmodel.h"

LocationsModel::LocationsModel()
{
}

void LocationsModel::insert(const MUuidPtr &id)
{
  auto row = _locations.index(id);

  insertRow(row);
}

int LocationsModel::columnCount(const QModelIndex &parent /* QModelIndex() */) const
{
  Q_UNUSED(parent);

  return gsl::narrow<int>(Column::Count);
}

QVariant LocationsModel::data(const QModelIndex &index, int role /* Qt::DisplayRole */) const
{
  Q_UNUSED(index);
  Q_UNUSED(role);

  // TODO

  return QVariant();
}

QModelIndex LocationsModel::index(int row, int column, const QModelIndex &parent /* QModelIndex() */) const
{
  Q_UNUSED(parent);

  return createIndex(row, column);
}

bool LocationsModel::insertRows(int row, int count, const QModelIndex &parent /* QModelIndex() */)
{
  beginInsertRows(parent, row, row + count - 1);
  // already added
  endInsertRows();

  return true;
}

QModelIndex LocationsModel::parent(const QModelIndex &child) const
{
  Q_UNUSED(child);

  return QModelIndex();
}

int LocationsModel::rowCount(const QModelIndex &parent /* QModelIndex() */) const
{
  Q_UNUSED(parent);

  // TODO

  return 0;
}