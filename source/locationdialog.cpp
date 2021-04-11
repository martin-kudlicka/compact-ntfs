#include "pch.h"
#include "locationdialog.h"

LocationDialog::LocationDialog(QWidget* parent) : MOptionsDialog(parent)
{
}

LocationDialog::LocationDialog(const MUuidPtr& id, QWidget* parent) : MOptionsDialog(id, parent)
{
}

void LocationDialog::setupSettings()
{
  _widgetSettings.setWidget(LocationOptions::Property::Path, _ui.path);

  MOptionsDialog::setupSettings();
}