#include "pch.h"
#include "locationdialog.h"

LocationDialog::LocationDialog(QWidget* parent) : LocationDialog(MUuidPtr::createUuid(), parent)
{
}

LocationDialog::LocationDialog(const MUuidPtr& id, QWidget* parent) : QDialog(parent), _options(id), _widgetSettings(&_options)
{
  _ui.setupUi(this);

  setupSettings();
}

const LocationOptions &LocationDialog::options() const
{
  return _options;
}

void LocationDialog::setupSettings()
{
  _widgetSettings.setWidget(LocationOptions::Property::Path, _ui.path);
}

void LocationDialog::accept()
{
  _widgetSettings.save();

  QDialog::accept();
}