#include "pch.h"
#include "locations.h"

const QString Locations::Property::Group = "locations";

Locations::Locations()
{
  _settings.beginGroup(Property::Group);
}

quintptr Locations::index(const MUuidPtr &id) const
{
  quintptr indexVal = 0;

  for (const auto &id2 : _settings.childGroups())
  {
    if (id2 == id.toString())
    {
      return indexVal;
    }

    ++indexVal;
  }

  Q_UNREACHABLE();
  return std::numeric_limits<quintptr>::max();
}