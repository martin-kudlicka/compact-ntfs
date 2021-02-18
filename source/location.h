#ifndef LOCATION_H
#define LOCATION_H

#include "locationoptions.h"

class Location
{
  public:
    Location(const MUuidPtr &id);

    const LocationOptions &options() const;

  private:
    LocationOptions _options;
};

#endif