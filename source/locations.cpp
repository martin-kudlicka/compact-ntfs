#include "pch.h"
#include "locations.h"

const QString Locations::Property::Group = "locations";

Locations::Locations()
{
  _settings.beginGroup(Property::Group);
}

LocationSPtr Locations::get(const MUuidPtr &id) const
{
  return QSharedPointer<Location>::create(id);
}