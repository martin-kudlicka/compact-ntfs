#include "pch.h"
#include "compactor.h"

#include "options.h"

Compactor::Compactor()
{
  connect(&_workerWatcher, &QFutureWatcher<void>::finished, this, &Compactor::finished);
}

void Compactor::start(const LocationSPtrList &locations)
{
  _worker = QtConcurrent::run([this, locations]
  {
    if (gOptions->excludeCheck())
    {
      _excludes = gOptions->excludes().split(';');
    }
    else
    {
      _excludes.clear();
    }

    for (const auto &location : locations)
    {
      processLocation(location);
    }
  });
  _workerWatcher.setFuture(_worker);
}

void Compactor::stop()
{
  _worker.cancel();
}

bool Compactor::isExcluded(const QString &filePath) const
{
  if (!_excludes.empty())
  {
    for (const auto &exclude : _excludes)
    {
      QRegExp regExp(exclude, Qt::CaseInsensitive, QRegExp::Wildcard);
      if (regExp.exactMatch(filePath))
      {
        return true;
      }
    }
  }

  return false;
}

void Compactor::processDir(const QDir &dir) const
{
  if (_worker.isCanceled() || isExcluded(dir.path()))
  {
    return;
  }

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
  if (_worker.isCanceled() || isExcluded(file.filePath()))
  {
    return;
  }

  if (gOptions->lastWriteOffsetCheck())
  {
    auto maxLastWriteTime = QDateTime::currentDateTimeUtc().addDays(- gsl::narrow<qint64>(gOptions->lastWriteOffsetDays()));
    if (file.lastModified() > maxLastWriteTime)
    {
      return;
    }
  }

  try
  {
    MCompact compact(file.filePath());
    if (compact.method() != gOptions->method())
    {
      compact.setMethod(gOptions->method());

      mInfo() << "compacted " << file.filePath();
    }
  }
  catch (const MException::MCritical &exception)
  {
    if (exception.error() != ERROR_COMPRESSION_NOT_BENEFICIAL)
    {
      mCriticalEx(exception);
    }
  }
}

void Compactor::processLocation(const LocationSPtr &location) const
{
  processDir(location->options().path());
}