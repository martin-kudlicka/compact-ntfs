#ifndef OPTIONS_H
#define OPTIONS_H

class Options : public MSettings
{
  public:
    struct Property
    {
      static const QString ExcludeCheck;
      static const QString Excludes;
      static const QString LastWriteOffsetCheck;
      static const QString LastWriteOffsetDays;
      static const QString Method;
    };

             Options();
    virtual ~Options() Q_DECL_OVERRIDE Q_DECL_EQ_DEFAULT;

    QString          excludes            () const;
    bool             excludeCheck        () const;
    bool             lastWriteOffsetCheck() const;
    quintptr         lastWriteOffsetDays () const;
    MCompact::Method method              () const;
};

extern MLazySingleton<Options> gOptions;

#endif