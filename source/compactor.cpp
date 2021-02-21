#include "pch.h"
#include "compactor.h"

void Compactor::start(const LocationSPtrList &locations) const\
{
  for (const auto &location : locations)
  {
    processLocation(location);
  }
}

void Compactor::processDir(const QDir &dir) const
{
  // TODO

  auto entries = dir.entryInfoList(QStringList{}, QDir::AllDirs | QDir::NoDotAndDotDot);
  for (const auto &entry : entries)
  {
    processDir(entry.filePath());
  }
}

void Compactor::processLocation(const LocationSPtr &location) const
{
  processDir(location->options().path());
}