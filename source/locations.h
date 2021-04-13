#ifndef LOCATIONS_H
#define LOCATIONS_H

#include "location.h"

class Locations : public MSettingsGroup<Location>
{
  public:
    struct Property
    {
      static const QString Group;
    };

             Locations();
    virtual ~Locations() Q_DECL_OVERRIDE Q_DECL_EQ_DEFAULT;

    LocationSPtr get(const MUuidPtr &id) const;
};

#endif