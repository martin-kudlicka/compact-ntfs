#include "pch.h"
#include "locationoptions.h"

#include "locations.h"

const QString LocationOptions::Property::Path = "path";

LocationOptions::LocationOptions(const MUuidPtr &id) : _id(id)
{
  beginGroup(Locations::Property::Group);
  beginGroup(id.toString());
}

const MUuidPtr &LocationOptions::id() const
{
  return _id;
}

QString LocationOptions::path() const
{
  return value(Property::Path).toString();
}