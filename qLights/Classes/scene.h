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
        QString                     m_sName;
        bool                        m_bBlackStart           { false };
        vector<shared_ptr<Fixture>> m_vAffectedFixtures;

    public:
        Scene(const QString &_sName,
              bool          _bBlackStart);

        ~Scene();

        QString                             name() const                        { return m_sName; }

        bool                                isBlackStart() const                { return m_bBlackStart; }
        void                                setBlackStart(bool _bBlackStart)    { m_bBlackStart = _bBlackStart; }

        void                                addFixture(shared_ptr<Fixture>);
        const vector<shared_ptr<Fixture>>&  fixtures() const                    { return m_vAffectedFixtures; }

        //const list<stUniverseInfo>& universes() const                   { return m_lstUniverse; }

        //void                        addUniverses(const list<shared_ptr<Universe>>  &_lstUniverse);

        //u8                          channelValue(const shared_ptr<Universe> _pUniverse,
        //                                         s32                        _s32FixtureAdress,
        //                                         s32                        _s32ChannelNr) const;

        //void                        applySceneData2Fixture(shared_ptr<Fixture>  _pFix) const;
}; // class Scene
