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
  m_vChaseSteps(_vSteps)
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
//     auto it = std::find_if(m_vChaseSteps.begin(), m_vChaseSteps.end(),
//         [_sName](const stChaseStep &step) { return step.sSceneName == _sName; });

//     return it != m_vChaseSteps.end();
// } // Chase::isSceneInChase


/*******************************************************************************
* Chase::startChase
*******************************************************************************/
void Chase::startChase()
{
    CHECK_PRE_CONDITION_VOID(m_vRunSteps.size() > 0);

    const stRunStep   &runStep = m_vRunSteps.at(0);

    // mark the active chasebutton as activated
    MainWin::instance()->activateChaseButton(this, true);

    // starting a chase begins with setting the start scene
    // if the chase has black start, we need to wait
    // until the fixtures are beeing switched on
    m_s32RunStepIdx = 0;
    m_s32CurrentStep = 0;
    m_bChaseStopped = false;

    // decrease the nr of steps about 10% to compensate the time which
    // is neccessary for the calculation.
    // this matches the duration time for the chase better
    m_s32Steps = runStep.u32Duration_ms / CHASE_UPDATE_TIME_MS;    // m_u32StepTime_ms for each step
    m_s32Steps = max(1, static_cast<s32> (0.9 * m_s32Steps));

    // start the timer for the first step.
    // isBlackStart: the delay is BLACK_START_TIME_MS to ensure, that
    // the fixtures are switches on again
    if (isBlackStart())
    {
        m_bNeedToSwitchAllFixturesOn = true;
        runStep.pStartScene->switchAllFixturesOff();
        runStep.pStartScene->showScene(true);
        QTimer::singleShot(BLACK_START_TIME_MS, this, SLOT(onTimeout()));
    }
    else
    {
        m_bNeedToSwitchAllFixturesOn = false;
        runStep.pStartScene->showScene(true);
        QTimer::singleShot(CHASE_UPDATE_TIME_MS, this, SLOT(onTimeout()));
    }
} // Chase::startChase


/*******************************************************************************
* Chase::stopChase
*******************************************************************************/
void Chase::stopChase()
{
    m_bChaseStopped = true;
} // Chase::stopChase


/*******************************************************************************
* Chase::createRunSteps
*******************************************************************************/
void Chase::createRunSteps()
{
    MainWin                         *pMainWin   = MainWin::instance();

    int iChaseStepCount = m_vChaseSteps.size();
    CHECK_PRE_CONDITION_VOID(iChaseStepCount > 0);

    // delete previous stuff
    m_vRunSteps.clear();

    // iterate over all chase steps
    for (int iChaseStep = 0; iChaseStep < iChaseStepCount; iChaseStep++)
    {
        stRunStep runStep;

        // the start scene must exist and has a duration (maybe = 0)
        runStep.pStartScene     = pMainWin->findScene(m_vChaseSteps.at(iChaseStep).sSceneName);
        runStep.u32Duration_ms  = m_vChaseSteps.at(iChaseStep).u32Duration_ms;

        if (iChaseStep == iChaseStepCount - 1)
        {
            // last chase step (probably just one chase step)
            // => just set the start scene for the duration time
        }
        else
        {
            // not the last chase step => calculate the transition of the channels with different values

            // set the end scene
            runStep.pEndScene = pMainWin->findScene(m_vChaseSteps.at(iChaseStep + 1).sSceneName);

            // find all fixtures which are in both scenes
            const vector<shared_ptr<Fixture>>   &vStartFix = runStep.pStartScene->fixtures();
            for (shared_ptr<Fixture> pStartFix : vStartFix)
            {
                // check, if the end scene has the same fixture
                if (runStep.pEndScene->hasFixture(pStartFix))
                {
                    // iterate over all channels and find channels with different values
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
        } // else

        // add the run step to vector of steps
        m_vRunSteps.push_back(runStep);
    }
} // Chase::createRunSteps


/*******************************************************************************
* Chase::onTimeout
*******************************************************************************/
void Chase::onTimeout()
{
    const stRunStep &runStep = m_vRunSteps.at(m_s32RunStepIdx);

    // check, whether the fixtures must be switched on
    if (m_bNeedToSwitchAllFixturesOn)
    {
        runStep.pStartScene->switchAllFixturesOn();
        m_bNeedToSwitchAllFixturesOn = false;
    }

    // if the chase is stopped => simply break the processing
    if (m_bChaseStopped)
    {
        // no more steps => mark the active chasebutton as activated
        MainWin::instance()->activateChaseButton(this, false);
    }
    else
    {
        // increase the step counter
        m_s32CurrentStep++;

        // iterate over all channels with different start-/endvalue and set the
        // value for this step
        for (const stChannelStep &channelStep : runStep.vChannelStep)
        {
            float fDelta = channelStep.fEndValue - channelStep.fStartValue;

            float fNewValue = channelStep.fStartValue + ((float) m_s32CurrentStep) / m_s32Steps * fDelta;

            channelStep.pFixture->setChannelValue(channelStep.pChannel,
                                                  static_cast<u8> (fNewValue));
        }

        // start the next step
        if (m_s32CurrentStep < m_s32Steps)
        {
            QTimer::singleShot(CHASE_UPDATE_TIME_MS, this, SLOT(onTimeout()));
        }
        else
        {
            // if there is only one step
            // => switch all fixtures off
            if (runStep.pEndScene == nullptr)
            {
                // last step is reached
                if (isCycle())
                {
                    // => cycle mode: start from beginning
                }
                else
                {
                    // => no cycle: switch scene off
                    runStep.pStartScene->switchAllFixturesOff();

                    // no more steps => mark the active chasebutton as activated
                    MainWin::instance()->activateChaseButton(this, false);
                }
            }
            else
            {
                // last run step not reached => move to next run step
                m_s32RunStepIdx++;

                m_s32Steps = m_vRunSteps.at(m_s32RunStepIdx).u32Duration_ms / CHASE_UPDATE_TIME_MS;
                m_s32Steps = max(1, static_cast<s32> (0.9 * m_s32Steps));
                m_s32CurrentStep = 0;

                QTimer::singleShot(CHASE_UPDATE_TIME_MS, this, SLOT(onTimeout()));
            }
        }

        // update the faders, they maybe have changed
        MainWin::instance()->updateFaders();
    }

} // Chase::onTimeout
