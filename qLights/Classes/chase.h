/*******************************************************************************
* \file Chase.h
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
#include <QString>
#include <QTimer>

#include "qLights_def.h"


class Channel;
class Fixture;


/*******************************************************************************
* class Chase
*******************************************************************************/
class Chase : public QObject
{
    Q_OBJECT

    private:
        struct stChannelStep
        {
            shared_ptr<Fixture>     pFixture;
            shared_ptr<Channel>     pChannel;
            float                   fStartValue;
            float                   fEndValue;
        }; // stChannelStep

        struct stRunStep
        {
            shared_ptr<Scene>           pStartScene;
            shared_ptr<Scene>           pEndScene;
            u32                         u32Duration_ms;
            vector<stChannelStep>       vChannelStep;
        }; // stRunStep

        QString                     m_sName;
        bool                        m_bBlackStart       { false };
        bool                        m_bCycle            { false };
        vector<stChaseStep>         m_vSteps;
        vector<stRunStep>           m_vRunSteps;

        // member for running the chase
        // QTimer                      m_timer;
        // s32                         m_s32RunStepIdx;
        // s32                         m_s32Steps;
        // s32                         m_s32CurrentStep;
        // const u32                   m_u32StepTime_ms    { UNIVERSE_UPDATE_TIME_MS };

    public:
        Chase(const QString             &_sName,
              bool                      _bBlackStart,
              bool                      _bCycle,
              const vector<stChaseStep> &_vSteps);

        ~Chase();

        QString                             name() const                        { return m_sName; }

        //const vector<shared_ptr<Fixture>>&  fixtures() const                    { return m_vAffectedFixtures; }

        const vector<stChaseStep>&          chaseSteps() const                  { return m_vSteps; }

        bool                                isBlackStart() const                { return m_bBlackStart; }
        void                                setBlackStart(bool _bBlackStart)    { m_bBlackStart = _bBlackStart; }

        bool                                isCycle() const                     { return m_bCycle; }
        void                                setCycle(bool _bCycle)              { m_bCycle = _bCycle; }

        // bool                                isSceneInChase(const QString &_sName);

        // void                                startChase();


    private:
        void                                createRunSteps();
        // void                                executeRunStep(const stRunStep &_stRunStep);

    private slots:
        // void                                onTimeout();
}; // class Chase
