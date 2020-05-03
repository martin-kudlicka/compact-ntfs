#include "pch.h"
#include "locationoptions.h"

#include "locations.h"

const QString LocationOptions::Property::Path = "path";

LocationOptions::LocationOptions(const MUuidPtr &id)
{
  beginGroup(Locations::Property::Group);
  beginGroup(id.toString());
}

QString LocationOptions::path() const
{
  return value(Property::Path).toString();
}
