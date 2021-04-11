#ifndef LOCATIONDIALOG_H
#define LOCATIONDIALOG_H

#include "ui_locationdialog.h"
#include "locationoptions.h"

class LocationDialog : public MOptionsDialog<Ui::LocationDialog, LocationOptions>
{
  Q_OBJECT

  public:
             LocationDialog(QWidget *parent);
             LocationDialog(const MUuidPtr &id, QWidget *parent);
    virtual ~LocationDialog() Q_DECL_OVERRIDE Q_DECL_EQ_DEFAULT;

  private:
    virtual void setupSettings();
};

#endif