#ifndef OPTIONS_H
#define OPTIONS_H

class Options : public MSettings
{
  public:
    struct Property
    {
      static const QString LastWriteOffsetCheck;
      static const QString LastWriteOffsetDays;
      static const QString Method;
    };

             Options();
    virtual ~Options() Q_DECL_OVERRIDE Q_DECL_EQ_DEFAULT;

    MCompact::Method method() const;
};

extern MLazySingleton<Options> gOptions;

#endif