#include "pch.h"
#include "locations.h"

const QString Locations::Property::Group = "locations";

Locations::Locations()
{
  _settings.beginGroup(Property::Group);
}