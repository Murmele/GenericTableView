#ifndef WRAPPERMANAGER_H
#define WRAPPERMANAGER_H

#include "property.h"

class WrapperManager
{
public:
    static WrapperManager* instance ()
    {
       static CGuard g;   // Speicherbereinigung
       if (!_instance)
          _instance = new WrapperManager ();
       return _instance;
    }

    void addWrapperWidget(const QString& wrappername, QSharedPointer<PropertySelectionWrapper> wrapper)
    {
        mWrappers[wrappername] = wrapper;
    }

    QSharedPointer<PropertySelectionWrapper> wrapperWidget(const QString& wrappername)
    {
        if (!mWrappers.contains(wrappername))
            return nullptr;

        return mWrappers[wrappername];
    }

    void removeWrapperWidget(const QString& wrappername)
    {
        if (!mWrappers.contains(wrappername))
            return;

        mWrappers.take(wrappername); // remove pointer from hash
    }

 private:
    static WrapperManager* _instance;
    WrapperManager () { } /* verhindert, dass ein Objekt von außerhalb von N erzeugt wird. */
              // protected, wenn man von der Klasse noch erben möchte
    WrapperManager ( const WrapperManager& ); /* verhindert, dass eine weitere Instanz via
 Kopie-Konstruktor erstellt werden kann */
    ~WrapperManager () { }
    class CGuard
    {
    public:
       ~CGuard()
       {
          if( nullptr != WrapperManager::_instance )
          {
             delete WrapperManager::_instance;
             WrapperManager::_instance = nullptr;
          }
       }
    };

private:
    QHash<QString, QSharedPointer<PropertySelectionWrapper>> mWrappers;
 };

#endif // WRAPPERMANAGER_H
