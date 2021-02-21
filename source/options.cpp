#include "pch.h"
#include "options.h"

const QString Options::Property::LastWriteOffsetCheck = "lastWriteOffsetCheck";
const QString Options::Property::LastWriteOffsetDays  = "lastWriteOffsetDays";
const QString Options::Property::Method               = "method";

MLazySingleton<Options> gOptions;

Options::Options()
{
  beginGroup("options");
}

MCompact::Method Options::method() const
{
  return gsl::narrow<MCompact::Method>(value(Property::Method).toUInt());
}