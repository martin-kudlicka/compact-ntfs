#ifndef LOCATIONS_H
#define LOCATIONS_H

#include "location.h"

class Locations
{
  public:
    struct Property
    {
      static const QString Group;
    };

    Locations();

    quintptr     count      ()                   const;
    LocationSPtr get        (const MUuidPtr &id) const;
    LocationSPtr get        (quintptr index)     const;
    MUuidPtr     id         (quintptr index)     const;
    quintptr     index      (const MUuidPtr &id) const;
    bool         isEmpty    ()                   const;
    void         removeIndex(quintptr index);

  private:
    QSettings _settings;
};

#endif