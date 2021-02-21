#include "pch.h"
#include "compactor.h"

#include "options.h"

void Compactor::start(const LocationSPtrList &locations) const\
{
  for (const auto &location : locations)
  {
    processLocation(location);
  }
}

void Compactor::processDir(const QDir &dir) const
{
  auto entries = dir.entryInfoList(QStringList{}, QDir::Files);
  for (const auto &entry : entries)
  {
    processFile(entry);
  }

  entries = dir.entryInfoList(QStringList{}, QDir::AllDirs | QDir::NoDotAndDotDot);
  for (const auto &entry : entries)
  {
    processDir(entry.filePath());
  }
}

void Compactor::processFile(const QFileInfo &file) const
{
  MCompact compact(file.filePath());
  if (compact.method() != gOptions->method())
  {
    compact.setMethod(gOptions->method());
  }
}

void Compactor::processLocation(const LocationSPtr &location) const
{
  processDir(location->options().path());
}