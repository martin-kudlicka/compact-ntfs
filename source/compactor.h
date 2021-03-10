#ifndef COMPACTOR_H
#define COMPACTOR_H

#include "location.h"

class Compactor : public QProgressDialog
{
  Q_OBJECT

  public:
    Compactor(QWidget *parent);

    void exec(const LocationSPtrList &locations);

  private:
    QFuture<void>        _worker;
    QFutureWatcher<void> _workerWatcher;
    QStringList          _excludes;

    bool isExcluded     (const QString &filePath)      const;
    void processDir     (const QDir &dir)              const;
    void processFile    (const QFileInfo &file)        const;
    void processLocation(const LocationSPtr &location) const;

  Q_SIGNALS:
    void compactingFile(const QString &filePath) const;

  private Q_SLOTS:
    void on_compactingFile(const QString &filePath);

};

#endif