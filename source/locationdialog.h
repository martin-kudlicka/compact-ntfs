#ifndef LOCATIONDIALOG_H
#define LOCATIONDIALOG_H

#include "ui_locationdialog.h"
#include "locationoptions.h"

class LocationDialog : public QDialog
{
  Q_OBJECT

  public:
             LocationDialog(QWidget *parent);
             LocationDialog(const MUuidPtr &id, QWidget *parent);
    virtual ~LocationDialog() Q_DECL_OVERRIDE Q_DECL_EQ_DEFAULT;

    const LocationOptions &options() const;

  private:
    MWidgetSettings    _widgetSettings;
    Ui::LocationDialog _ui;
    LocationOptions    _options;

    void setupSettings();

    virtual void accept() Q_DECL_OVERRIDE;
};

#endif