#ifndef LOCATIONSMODEL_H
#define LOCATIONSMODEL_H

#include "locations.h"

class LocationsModel : public MSettingsGroupModel<Locations>
{
  public:
    enum class Column
    {
      Path,
      Count
    };

    virtual ~LocationsModel() Q_DECL_OVERRIDE Q_DECL_EQ_DEFAULT;

    const Locations &locations() const;

  protected:
    virtual int      columnCount(const QModelIndex &parent = QModelIndex())                            const Q_DECL_OVERRIDE;
    virtual QVariant data       (const QModelIndex &index, int role = Qt::DisplayRole)                 const Q_DECL_OVERRIDE;
    virtual QVariant headerData (int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
};

#endif