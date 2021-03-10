#include "pch.h"
#include "mainwindow.h"

#include "locationdialog.h"
#include "optionsdialog.h"
#include "compactor.h"

MainWindow::MainWindow()
{
  _ui.setupUi(this);

  setupWidgets();
}

void MainWindow::setupWidgets()
{
  _ui.locations->setModel(&_locationsModel);
  _ui.logMessages->setModel(&_messageLogModel);

  _ui.logMessages->header()->setSectionResizeMode(gsl::narrow<int>(MMessageLogModel::Column::Timestamp), QHeaderView::ResizeToContents);
  _ui.logMessages->header()->setSectionResizeMode(gsl::narrow<int>(MMessageLogModel::Column::Category),  QHeaderView::ResizeToContents);
  _ui.logMessages->header()->setSectionResizeMode(gsl::narrow<int>(MMessageLogModel::Column::Type),      QHeaderView::ResizeToContents);
  _ui.logMessages->header()->setSectionResizeMode(gsl::narrow<int>(MMessageLogModel::Column::Error),     QHeaderView::ResizeToContents);
  _ui.logMessages->header()->setSectionResizeMode(gsl::narrow<int>(MMessageLogModel::Column::Message),   QHeaderView::Stretch);

  connect(&_locationsModel,                &LocationsModel::rowsInserted,          this, &MainWindow::on_locations_rowsInserted);
  connect(&_locationsModel,                &LocationsModel::rowsRemoved,           this, &MainWindow::on_locations_rowsRemoved);
  connect(_ui.locations->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MainWindow::on_locations_selectionChanged);

  _ui.start->setEnabled(!_locationsModel.isEmpty());
}

void MainWindow::on_actionAbout_triggered(bool checked /* false */)
{
  Q_UNUSED(checked);

  MAboutBox(this).exec();
}

void MainWindow::on_actionOptions_triggered(bool checked /* false */)
{
  Q_UNUSED(checked);

  OptionsDialog optionsDialog(this);
  optionsDialog.exec();
}

void MainWindow::on_actionSendFeedback_triggered(bool checked /* false */) const
{
  Q_UNUSED(checked);

  MFeedback::createEmailForm();
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
}

void MainWindow::on_locationEdit_clicked(bool checked /* false */)
{
  Q_UNUSED(checked);

  auto index = _ui.locations->currentIndex();
  auto id    = _locationsModel.id(index);

  LocationDialog locationDialog(id, this);
  locationDialog.exec();
}

void MainWindow::on_locationRemove_clicked(bool checked /* false */)
{
  Q_UNUSED(checked);

  auto index = _ui.locations->currentIndex();

  _locationsModel.remove(index);
}

void MainWindow::on_locations_rowsInserted(const QModelIndex &parent, int first, int last) const
{
  Q_UNUSED(parent);
  Q_UNUSED(first);
  Q_UNUSED(last);

  _ui.start->setEnabled(true);
}

void MainWindow::on_locations_rowsRemoved(const QModelIndex &parent, int first, int last) const
{
  Q_UNUSED(parent);
  Q_UNUSED(first);
  Q_UNUSED(last);

  _ui.start->setEnabled(!_locationsModel.isEmpty());
}

void MainWindow::on_locations_selectionChanged(const QItemSelection &selected, const QItemSelection &deselected) const
{
  Q_UNUSED(selected);
  Q_UNUSED(deselected);

  auto isSelected = !_ui.locations->selectionModel()->selectedRows().isEmpty();

  _ui.locationEdit->setEnabled(isSelected);
  _ui.locationRemove->setEnabled(isSelected);
}

void MainWindow::on_start_clicked(bool checked /* false */)
{
  Q_UNUSED(checked);

  LocationSPtrList locations;
  for (decltype(_locationsModel.locations().count()) index = 0; index < _locationsModel.locations().count(); ++index)
  {
    locations.append(_locationsModel.locations().get(index));
  }

  Compactor(this).exec(locations);
}