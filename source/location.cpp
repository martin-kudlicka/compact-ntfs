#include "pch.h"
#include "location.h"

Location::Location(const MUuidPtr &id) : _options(id)
{
}

const LocationOptions &Location::options() const
{
  return _options;
}