/*******************************************************************************
* \file Chase.cpp
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


/*******************************************************************************
* includes
*******************************************************************************/
#include "mainWin.h"
#include "fixture.h"
#include "scene.h"
#include "chase.h"



/*******************************************************************************
* Chase::Chase
*******************************************************************************/
Chase::Chase(const QString              &_sName,
             bool                       _bBlackStart,
             bool                       _bCycle,
             const vector<stChaseStep>  &_vSteps)
: m_sName(_sName),
  m_bBlackStart(_bBlackStart),
  m_bCycle(_bCycle),
  m_vSteps(_vSteps)
{
    // create steps for activation
    createRunSteps();

    // // connect the timer
    // connect(&m_timer, &QTimer::timeout, this, &Chase::onTimeout);
    // m_timer.setSingleShot(true);
} // Chase::Chase


/*******************************************************************************
* Chase::~Chase
*******************************************************************************/
Chase::~Chase()
{
} // Chase::~Chase


/*******************************************************************************
* Chase::isSceneInChase
*******************************************************************************/
// bool Chase::isSceneInChase(const QString &_sName)
// {
//     auto it = std::find_if(m_vSteps.begin(), m_vSteps.end(),
//         [_sName](const stChaseStep &step) { return step.sSceneName == _sName; });

//     return it != m_vSteps.end();
// } // Chase::isSceneInChase


/*******************************************************************************
* Chase::startChase
*******************************************************************************/
// void Chase::startChase()
// {
//     CHECK_PRE_CONDITION_VOID(m_vRunSteps.size() > 0);

//     // initialize the fixtures with the start scene
//     for (shared_ptr<Fixture> &pFix : m_vAffectedFixtures)
//     {
//         m_vRunSteps.at(0).pStartScene->applySceneData2Fixture(pFix);
//     }

//     // prepare the timer
//     m_s32RunStepIdx = 0;

//     // mark the active chasebutton as activated
//     MainWin::instance()->activateChaseButton(this, true);

//     // execute the first step
//     executeRunStep(m_vRunSteps.at(0));
// } // Chase::startChase


/*******************************************************************************
* Chase::executeRunStep
*******************************************************************************/
// void Chase::executeRunStep(const stRunStep &_stRunStep)
// {
//     // prepare the timer
//     m_s32CurrentStep = 0;

//     // decrease the nr of steps about 10% to compensate the time
//     // which is neccessary for the calculation.
//     // this matches the duration time for the chase better
//     m_s32Steps = _stRunStep.u32Duration_ms / m_u32StepTime_ms;    // m_u32StepTime_ms for each step
//     m_s32Steps = static_cast<s32> (0.9 * m_s32Steps);

//     m_timer.start(m_u32StepTime_ms);
// } // Chase::executeRunStep


/*******************************************************************************
* Chase::createRunSteps
*******************************************************************************/
void Chase::createRunSteps()
{
    MainWin                         *pMainWin   = MainWin::instance();

    // delete previous stuff
    m_vRunSteps.clear();

    // iterate over all chase steps
    int iStepCount = m_vSteps.size();
    for (int iStep = 0; iStep < iStepCount-1; iStep++)
    {
        stRunStep runStep;
        runStep.pStartScene     = pMainWin->findScene(m_vSteps.at(iStep).sSceneName);
        runStep.pEndScene       = pMainWin->findScene(m_vSteps.at(iStep + 1).sSceneName);
        // the scenes must exist
        CHECK_PRE_CONDITION_VOID(runStep.pStartScene);
        CHECK_PRE_CONDITION_VOID(runStep.pEndScene);

        runStep.u32Duration_ms  = m_vSteps.at(iStep).u32Duration_ms;

        // find all fixtures which are in both scenes
        const vector<shared_ptr<Fixture>>   &vStartFix = runStep.pStartScene->fixtures();
        for (shared_ptr<Fixture> pStartFix : vStartFix)
        {
            if (runStep.pEndScene->hasFixture(pStartFix))
            {
                // get the cahnnel values of the start channel
                const mapChannelValue *pStartValues = runStep.pStartScene->findChannelValues(pStartFix);

                for (const auto &me : *pStartValues)
                {
                    int iChannelNr = me.first;
                    int iStartValue = me.second;
                    int iEndValue = runStep.pEndScene->channelValue(pStartFix, iChannelNr);

                    // start value of this fixture and channel != endvalue => add as a channel step
                    if (iStartValue != iEndValue)
                    {
                        stChannelStep cs;
                        cs.pFixture = pStartFix;
                        cs.pChannel = pStartFix->findChannel(iChannelNr);
                        cs.fStartValue = iStartValue;
                        cs.fEndValue = iEndValue;

                        runStep.vChannelStep.push_back(cs);
                    }

                }
            }
        }

        m_vRunSteps.push_back(runStep);
    }
} // Chase::createRunSteps


/*******************************************************************************
* Chase::onTimeout
*******************************************************************************/
// void Chase::onTimeout()
// {
//     const stRunStep &runStep = m_vRunSteps.at(m_s32RunStepIdx);

//     for (const stChannelStep &channelStep : runStep.vChannelStep)
//     {
//         float fDelta = channelStep.fEndValue - channelStep.fStartValue;

//         float fNewValue = channelStep.fStartValue + ((float) m_s32CurrentStep) / m_s32Steps * fDelta;

//         channelStep.pUniverse->setChannelValue(channelStep.s32FixtureAdress,
//                                                channelStep.pChannel,
//                                                static_cast<u8> (fNewValue));
//     }

//     // update the faders
//     MainWin::instance()->updateFaders();

//     // start the next step
//     if (m_s32CurrentStep < m_s32Steps)
//     {
//         m_s32CurrentStep++;

//         m_timer.start(m_u32StepTime_ms);
//     }
//     else
//     {
//         // scene end reached => move to next run step
//         if (m_s32RunStepIdx < ((s32) m_vRunSteps.size()) - 1)
//         {
//             m_s32RunStepIdx++;

//             executeRunStep(m_vRunSteps.at(m_s32RunStepIdx));
//         }
//         else
//         {
//             // no more steps => mark the active chasebutton as activated
//             MainWin::instance()->activateChaseButton(this, false);
//         }
//     }

// } // Chase::onTimeout
