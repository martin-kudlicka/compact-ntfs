#ifndef COMPACTOR_H
#define COMPACTOR_H

#include "location.h"

class Compactor
{
  public:
    Compactor();

    void start(const LocationSPtrList &locations) const;

  private:
    QStringList _excludes;

    bool isExcluded     (const QString &filePath)      const;
    void processDir     (const QDir &dir)              const;
    void processFile    (const QFileInfo &file)        const;
    void processLocation(const LocationSPtr &location) const;
};

#endif