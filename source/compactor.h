#ifndef COMPACTOR_H
#define COMPACTOR_H

#include "location.h"

class Compactor
{
  public:
    void start(const LocationSPtrList &locations) const;

  private:
    void processDir     (const QDir &dir)              const;
    void processLocation(const LocationSPtr &location) const;
};

#endif