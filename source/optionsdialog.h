#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include "ui_optionsdialog.h"

class OptionsDialog : public QDialog
{
  Q_OBJECT

  public:
             OptionsDialog(QWidget *parent);
    virtual ~OptionsDialog() Q_DECL_OVERRIDE Q_DECL_EQ_DEFAULT;

  private:
    Ui::OptionsDialog _ui;
    MWidgetSettings   _widgetSettings;

    void setupSettings();
    void setupWidgets();

    virtual void accept() Q_DECL_OVERRIDE;

  private Q_SLOTS:
    void on_lastWriteOffsetCheck_stateChanged(int state) const;
};

#endif