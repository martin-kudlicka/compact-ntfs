#include "pch.h"
#include "mainwindow.h"

#include "locationdialog.h"

MainWindow::MainWindow()
{
  _ui.setupUi(this);

  setupWidgets();
}

void MainWindow::setupWidgets()
{
  _ui.locations->setModel(&_locationsModel);

  connect(_ui.locations->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainWindow::on_locations_selectionChanged);
}

void MainWindow::on_locationAdd_clicked(bool checked /* false */)
{
  Q_UNUSED(checked);

  LocationDialog locationDialog(this);
  if (locationDialog.exec() == QDialog::Rejected)
  {
    return;
  }

  _locationsModel.insert(locationDialog.options().id());

  // TODO
}

void MainWindow::on_locationEdit_clicked(bool checked /* false */)
{
  Q_UNUSED(checked);

  auto index = _ui.locations->currentIndex();
  auto id    = _locationsModel.id(index);

  LocationDialog locationDialog(id, this);
  locationDialog.exec();
}

void MainWindow::on_locations_selectionChanged(const QItemSelection &selected, const QItemSelection &deselected) const
{
  Q_UNUSED(selected);
  Q_UNUSED(deselected);

  auto isSelected = !_ui.locations->selectionModel()->selectedRows().isEmpty();

  _ui.locationEdit->setEnabled(isSelected);
}