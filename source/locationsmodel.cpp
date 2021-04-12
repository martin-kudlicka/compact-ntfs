#include "pch.h"
#include "locationsmodel.h"

const Locations &LocationsModel::locations() const
{
  return _data;
}

int LocationsModel::columnCount(const QModelIndex &parent /* QModelIndex() */) const
{
  Q_UNUSED(parent);

  return gsl::narrow<int>(Column::Count);
}

QVariant LocationsModel::data(const QModelIndex &index, int role /* Qt::DisplayRole */) const
{
  auto location = _data.get(MUuidPtr(index.internalId()));

  struct DataGetter
  {
    Column                                                column;
    int                                                   role;
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