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
             const vector<stChaseStep>  &_vSteps)
: m_sName(_sName),
  m_bBlackStart(_bBlackStart),
  m_vSteps(_vSteps)
{
    // create steps for activation
    createRunSteps();
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
bool Chase::isSceneInChase(const QString &_sName)
{
    auto it = std::find_if(m_vSteps.begin(), m_vSteps.end(),
        [_sName](const stChaseStep &step) { return step.sSceneName == _sName; });

    return it != m_vSteps.end();
} // Chase::isSceneInChase


/*******************************************************************************
* Chase::startChase
*******************************************************************************/
void Chase::startChase()
{
    cout << "chase >" << m_sName.toStdString() << "< running" << endl;

    CHECK_PRE_CONDITION_VOID(m_vRunSteps.size() > 0);

    m_s32RunStepIdx = 0;
    m_s32Steps = m_vRunSteps.at(0).u32Duration_ms / m_u32StepTime_ms;    // m_u32StepTime_ms for each step
    m_s32CurrentStep = 0;

    cout << m_s32Steps << endl;
} // Chase::startChase


/*******************************************************************************
* Chase::createRunSteps
*******************************************************************************/
void Chase::createRunSteps()
{
    MainWin                         *pMainWin   = MainWin::instance();
    const list<shared_ptr<Fixture>> &lstFix     = pMainWin->getAllFixtures();

    // delete previous stuff
    m_vRunSteps.clear();

    // iterate over all chase steps
    int iStepCount = m_vSteps.size();
    for (int iStep = 0; iStep < iStepCount-1; iStep++)
    {
        stRunStep runStep;
        runStep.pStartScene     = pMainWin->findScene(m_vSteps.at(iStep).sSceneName);
        runStep.pEndScene       = pMainWin->findScene(m_vSteps.at(iStep + 1).sSceneName);
        runStep.u32Duration_ms  = m_vSteps.at(iStep).u32Duration_ms;

        // iterate over all fixtures
        for (const shared_ptr<Fixture> &pFix : lstFix)
        {
            shared_ptr<Universe>    pU      = pFix->universe();
            s32                     adress  = pFix->adress();

            // iterate over all channels in the fixture
            const vector<shared_ptr<Channel>> &vChannel = pFix->device()->channel();
            for (shared_ptr<Channel> pChannel : vChannel)
            {
                s32 nr = pChannel->nr();

                float startValue   = static_cast<float> (runStep.pStartScene->channelValue(pU, adress, nr));
                float endValue     = static_cast<float> (runStep.pEndScene->channelValue(pU, adress, nr));

                if (startValue != endValue)
                {
                    stChannelStep channelStep { pU, adress, nr, startValue, endValue };

                    runStep.vChannelStep.push_back(channelStep);

                    cout << "channel " << nr << ": " << startValue << " -> " << endValue << endl;
                }
            }
        }

        m_vRunSteps.push_back(runStep);
    }

} // Chase::createRunSteps
