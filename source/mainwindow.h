#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "locationsmodel.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
             MainWindow();
    virtual ~MainWindow() Q_DECL_OVERRIDE Q_DECL_EQ_DEFAULT;

  private:
    LocationsModel _locationsModel;
    Ui::MainWindow _ui;

    void setupWidgets();

  private Q_SLOTS:
    void on_actionOptions_triggered     (bool checked = false);
    void on_actionStartCompact_triggered(bool checked = false);
    void on_locationAdd_clicked         (bool checked = false);
    void on_locationEdit_clicked        (bool checked = false);
    void on_locationRemove_clicked      (bool checked = false);
    void on_locations_selectionChanged  (const QItemSelection &selected, const QItemSelection &deselected) const;
};

#endif