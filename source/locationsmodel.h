#ifndef LOCATIONSMODEL_H
#define LOCATIONSMODEL_H

#include "locations.h"

class LocationsModel : public QAbstractItemModel
{
  public:
    enum class Column
    {
      Path,
      Count
    };

             LocationsModel();
    virtual ~LocationsModel() Q_DECL_OVERRIDE Q_DECL_EQ_DEFAULT;

    void insert(const MUuidPtr &id);

  private:
    Locations _locations;

    virtual int         columnCount(const QModelIndex &parent = QModelIndex())                      const Q_DECL_OVERRIDE;
    virtual QVariant    data       (const QModelIndex &index, int role = Qt::DisplayRole)           const Q_DECL_OVERRIDE;
    virtual QModelIndex index      (int row, int column, const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual bool        insertRows (int row, int count, const QModelIndex &parent = QModelIndex())        Q_DECL_OVERRIDE;
    virtual QModelIndex parent     (const QModelIndex &child)                                       const Q_DECL_OVERRIDE;
    virtual int         rowCount   (const QModelIndex &parent = QModelIndex())                      const Q_DECL_OVERRIDE;
};

#endif