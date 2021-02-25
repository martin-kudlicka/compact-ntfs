#include "pch.h"
#include "options.h"

const QString Options::Property::ExcludeCheck         = "excludeCheck";
const QString Options::Property::Excludes             = "excludes";
const QString Options::Property::LastWriteOffsetCheck = "lastWriteOffsetCheck";
const QString Options::Property::LastWriteOffsetDays  = "lastWriteOffsetDays";
const QString Options::Property::Method               = "method";

MLazySingleton<Options> gOptions;

Options::Options()
{
  beginGroup("options");
}

QString Options::excludes() const
{
  return value(Property::Excludes).toString();
}

bool Options::excludeCheck() const
{
  return value(Property::ExcludeCheck).toBool();
}

bool Options::lastWriteOffsetCheck() const
{
  return value(Property::LastWriteOffsetCheck).toBool();
}

quintptr Options::lastWriteOffsetDays() const
{
  return value(Property::LastWriteOffsetDays).toUInt();
}

MCompact::Method Options::method() const
{
  return gsl::narrow<MCompact::Method>(value(Property::Method).toUInt());
}