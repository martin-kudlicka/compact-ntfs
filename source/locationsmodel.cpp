#include "pch.h"
#include "locationsmodel.h"

LocationsModel::LocationsModel()
{
}

MUuidPtr LocationsModel::id(const QModelIndex &index) const
{
  return index.internalId();
}

void LocationsModel::insert(const MUuidPtr &id)
{
  auto row = _locations.index(id);

  insertRow(row);
}

const Locations &LocationsModel::locations() const
{
  return _locations;
}

void LocationsModel::remove(const QModelIndex &index)
{
  removeRow(index.row());
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
    std::function<QVariant(const LocationSPtr &location)> fnGetter;
  };
  static DataGetter getters[] =
  {
    { Column::Path, Qt::DisplayRole, [](const LocationSPtr &location) { return location->options().path(); } }
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

QVariant LocationsModel::headerData(int section, Qt::Orientation orientation, int role /* Qt::DisplayRole */) const
{
  if (orientation == Qt::Orientation::Vertical || role != Qt::DisplayRole)
  {
    return QVariant();
  }

  switch (section)
  {
    case Column::Path:
      return tr("Path");
    default:
      Q_UNREACHABLE();
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

bool LocationsModel::removeRows(int row, int count, const QModelIndex &parent /* QModelIndex() */)
{
  beginRemoveRows(parent, row, row + count - 1);

  _locations.removeIndex(row);

  endRemoveRows();

  return true;
}

int LocationsModel::rowCount(const QModelIndex &parent /* QModelIndex() */) const
{
  if (parent.isValid())
  {
    return 0;
  }

  return _locations.count();
}