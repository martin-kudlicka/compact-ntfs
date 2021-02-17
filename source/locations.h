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

    quintptr index(const MUuidPtr &id) const;

  private:
    QSettings _settings;
};

#endif