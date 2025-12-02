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
#include <QObject>

#include "qLights_def.h"

#include <QByteArray>
#include <QString>

using namespace std;
using namespace aFrame;

class Universe;



/*******************************************************************************
* class Scene
*******************************************************************************/
class Scene : public QObject
{
    Q_OBJECT

    private:
        QString                                         m_sName;
        bool                                            m_bBlackStart           { false };
        vector<shared_ptr<Fixture>>                     m_vAffectedFixtures;
        std::map<shared_ptr<Fixture>, mapChannelValue>  m_mapFixtureValues;


    public:
        Scene(const QString &_sName,
              bool          _bBlackStart);

        ~Scene();

        QString                             name() const                        { return m_sName; }

        bool                                isBlackStart() const                { return m_bBlackStart; }
        void                                setBlackStart(bool _bBlackStart)    { m_bBlackStart = _bBlackStart; }

        void                                addFixture(shared_ptr<Fixture>      _pFixture,
                                                       const mapChannelValue    &_channelValue);
        const vector<shared_ptr<Fixture>>&  fixtures() const                    { return m_vAffectedFixtures; }
        bool                                hasFixture(shared_ptr<Fixture> _pFixture) const;

        void                                showScene(bool _bIgnoreBlackStart) const;
        void                                switchAllFixturesOff() const;
        void                                switchAllFixturesOn() const;
        void                                resetAllFixtures() const;
        void                                setAllFixtureBrightness0() const;

        u8                                  channelValue(shared_ptr<Fixture>    _pFixture,
                                                         s32                    _s32ChannelNr) const;

        const mapChannelValue*              findChannelValues(const shared_ptr<Fixture> &_pFixture) const;


    private slots:
        void                                switchFixturesOn() const;

}; // class Scene
