#include "pch.h"
#include "optionsdialog.h"

#include "options.h"

OptionsDialog::OptionsDialog(QWidget *parent) : QDialog(parent), _widgetSettings(gOptions.data())
{
  _ui.setupUi(this);

  setupWidgets();
  setupSettings();

  _ui.lastWriteOffsetDays->setEnabled(_ui.lastWriteOffsetCheck->isChecked());
}

void OptionsDialog::setupSettings()
{
  _widgetSettings.setWidget(Options::Property::Method,               _ui.method);
  _widgetSettings.setWidget(Options::Property::LastWriteOffsetCheck, _ui.lastWriteOffsetCheck);
  _widgetSettings.setWidget(Options::Property::LastWriteOffsetDays,  _ui.lastWriteOffsetDays);

  _widgetSettings.load();
}

void OptionsDialog::setupWidgets()
{
  _ui.method->addItem("NTFS",      gsl::narrow<quintptr>(MCompact::Method::Ntfs));
  _ui.method->addItem("XPRESS4K",  gsl::narrow<quintptr>(MCompact::Method::Xpress4K));
  _ui.method->addItem("XPRESS8K",  gsl::narrow<quintptr>(MCompact::Method::Xpress8K));
  _ui.method->addItem("XPRESS16K", gsl::narrow<quintptr>(MCompact::Method::Xpress16K));
  _ui.method->addItem("LZX",       gsl::narrow<quintptr>(MCompact::Method::Lzx));
}

void OptionsDialog::accept()
{
  _widgetSettings.save();

  QDialog::accept();
}

void OptionsDialog::on_lastWriteOffsetCheck_stateChanged(int state) const
{
  _ui.lastWriteOffsetDays->setEnabled(state == Qt::Checked);
}