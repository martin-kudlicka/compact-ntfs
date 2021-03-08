#ifndef COMPACTOR_H
#define COMPACTOR_H

#include "location.h"

class Compactor : public QObject
{
  Q_OBJECT

  public:
    Compactor();

    void start(const LocationSPtrList &locations);
    void stop();

  private:
    bool                 _canceled;
    QFuture<void>        _worker;
    QFutureWatcher<void> _workerWatcher;
    QStringList          _excludes;

    bool isExcluded     (const QString &filePath)      const;
    void processDir     (const QDir &dir)              const;
    void processFile    (const QFileInfo &file)        const;
    void processLocation(const LocationSPtr &location) const;

  Q_SIGNALS:
    void finished();
};

#endif