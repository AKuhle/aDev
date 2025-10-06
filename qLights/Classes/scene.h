/*******************************************************************************
* \file Scene.h
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLights_def.h"

#include <QByteArray>
#include <QString>

using namespace std;

class Universe;



/*******************************************************************************
* class Scene
*******************************************************************************/
class Scene
{
    private:
        QString                 m_sName;
        list<UniverseTuple>     m_lstUniverse;


    public:
        Scene(const QString   &_sName);

        ~Scene();

        QString                     name() const        { return m_sName; }

        const list<UniverseTuple>&  universes() const    { return m_lstUniverse; }

        void                        addUniverses(const list<shared_ptr<Universe>>  &_lstUniverse);
}; // class Scene
