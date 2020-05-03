#include "pch.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
  _ui.setupUi(this);

  setupWidgets();
}

void MainWindow::setupWidgets()
{
  _ui.locations->setModel(&_locationsModel);
}
