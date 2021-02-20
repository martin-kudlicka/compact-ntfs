#include "pch.h"
#include "locations.h"

const QString Locations::Property::Group = "locations";

Locations::Locations()
{
  _settings.beginGroup(Property::Group);
}

quintptr Locations::count() const
{
  return _settings.childGroups().count();
}

Location Locations::get(const MUuidPtr &id) const
{
  return Location(id);
}

MUuidPtr Locations::id(quintptr index) const
{
  return _settings.childGroups().at(index);
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

bool Locations::isEmpty() const
{
  return count() == 0;
}

void Locations::removeIndex(quintptr index)
{
  auto id2 = id(index);

  _settings.remove(id2.toString());
}