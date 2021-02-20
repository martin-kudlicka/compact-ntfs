#include "pch.h"
#include "optionsdialog.h"

#include "options.h"

OptionsDialog::OptionsDialog(QWidget *parent) : QDialog(parent), _widgetSettings(gOptions.data())
{
  _ui.setupUi(this);

  setupWidgets();
  setupSettings();
}

void OptionsDialog::setupSettings()
{
  _widgetSettings.setWidget(Options::Property::Method, _ui.method);

  _widgetSettings.load();
}

void OptionsDialog::setupWidgets()
{
  _ui.method->addItem("NTFS",      "NTFS");
  _ui.method->addItem("XPRESS4K",  "XPRESS4K");
  _ui.method->addItem("XPRESS8K",  "XPRESS8K");
  _ui.method->addItem("XPRESS16K", "XPRESS16K");
  _ui.method->addItem("LZX",       "LZX");
}

void OptionsDialog::accept()
{
  _widgetSettings.save();

  QDialog::accept();
}