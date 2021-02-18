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
  auto location = _locations.get(index.internalId());

  struct DataGetter
  {
    Column                                            column;
    int                                               role;
    std::function<QVariant(const Location &location)> fnGetter;
  };
  static DataGetter getters[] =
  {
    { Column::Path, Qt::DisplayRole, [](const Location &location) { return location.options().path(); } }
  };

  for (const auto &getter : getters)
  {
    if (gsl::narrow<decltype(index.column())>(getter.column) == index.column() && getter.role == role)
    {
      return getter.fnGetter(location);
    }
  }

  return QVariant();
}

QModelIndex LocationsModel::index(int row, int column, const QModelIndex &parent /* QModelIndex() */) const
{
  Q_UNUSED(parent);

  if (_locations.isEmpty())
  {
    return createIndex(row, column);
  }

  return createIndex(row, column, _locations.id(row));
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
  if (parent.isValid())
  {
    return 0;
  }

  return _locations.count();
}