#include "pch.h"

#include "mainwindow.h"

int main(int argc, char *argv[])
{
  MApplication application(argc, argv);

  mAnalytics->setId("24222e1209847239cefb8b2bbb9a27b64755bf73");

  MainWindow mainWindow;
  mainWindow.show();

  return application.exec();
}