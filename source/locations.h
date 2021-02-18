#ifndef LOCATIONS_H
#define LOCATIONS_H

class Locations
{
  public:
    struct Property
    {
      static const QString Group;
    };

    Locations();

    quintptr count  ()                   const;
    MUuidPtr id     (quintptr index)     const;
    quintptr index  (const MUuidPtr &id) const;
    bool     isEmpty()                   const;

  private:
    QSettings _settings;
};

#endif