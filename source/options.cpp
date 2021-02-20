#include "pch.h"
#include "options.h"

const QString Options::Property::Method = "method";

MLazySingleton<Options> gOptions;

Options::Options()
{
  beginGroup("options");
}