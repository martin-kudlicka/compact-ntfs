#ifndef LOCATIONOPTIONS_H
#define LOCATIONOPTIONS_H

class LocationOptions : public MSettings
{
  public:
    struct Property
    {
      static const QString Path;
    };

             LocationOptions(const MUuidPtr& id);
    virtual ~LocationOptions() Q_DECL_OVERRIDE Q_DECL_EQ_DEFAULT;

    const MUuidPtr &id  () const;
          QString   path() const;

  private:
    MUuidPtr _id;
};

#endif