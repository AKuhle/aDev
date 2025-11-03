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
using namespace aFrame;

class Universe;



/*******************************************************************************
* class Scene
*******************************************************************************/
class Scene
{
    private:
        QString                 m_sName;
        list<stUniverseInfo>    m_lstUniverse;
        u8                      m_u8MasterBrighness     { 0 };

    public:
        Scene(const QString   &_sName,
              u8              _u8MasterBrighness);

        ~Scene();

        QString                     name() const                    { return m_sName; }

        void                        setMasterBrighness(u8 _bright)  {  m_u8MasterBrighness = _bright; }
        u8                          masterBrighness() const         { return m_u8MasterBrighness; }

        const list<stUniverseInfo>& universes() const               { return m_lstUniverse; }

        void                        addUniverses(const list<shared_ptr<Universe>>  &_lstUniverse);

        u8                          channelValue(const shared_ptr<Universe> _pUniverse,
                                                 s32                        _s32FixtureAdress,
                                                 s32                        _s32ChannelNr) const;

}; // class Scene
