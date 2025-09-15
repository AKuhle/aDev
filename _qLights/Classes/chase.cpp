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
#include "aJsonFile.h"
#include "aJsonValue.h"

#include "mainWin.h"
#include "chase.h"
#include "ctrlPanel.h"


/*******************************************************************************
* Chase::Chase
*******************************************************************************/
Chase::Chase(const aString &_sName)
: m_sName(_sName)
{
    m_pTimer = new QTimer(this);
    //connect(m_pTimer, &QTimer::timeout, this, &Chase::onTimeout);
} // Chase::Chase


/*******************************************************************************
* Chase::~Chase
*******************************************************************************/
Chase::~Chase()
{
    delete m_pTimer;
} // Chase::~Chase


/*******************************************************************************
* Chase::addStep
*******************************************************************************/
void Chase::addStep(const aString   &_sScene,
                    s32             _s32Length_s)
{
    CtrlPanel                               &ctrlPanel  = getCtrlPanel();
    shared_ptr<Scene>                       pScene      = ctrlPanel.findScene(_sScene);
    aVector<shared_ptr<StepChannelTuple>>   vChannel;

    // no scene => no step
    CHECK_PRE_CONDITION_VOID(pScene != nullptr);

    // add the new step to the steps
    StepTuple step = make_tuple(pScene, nullptr, vChannel, _s32Length_s);
    m_vSteps.push_back(step);

    // if it is not the first step => add the changing of the
    // channels to the previous step
    if (m_vSteps.size() > 1)
    {
        // find the previous step
        StepTuple   &prevStep   = m_vSteps.at(m_vSteps.size() - 1);

        // set the sceneEnd of the previous step
        std::get<1> (prevStep) = pScene;

        // find channels which changes over the period of time and
        // add them to the list of channelValueTuples of the previous scene
        shared_ptr<Scene>                       pStartScene     = std::get<0> (prevStep);
        shared_ptr<Scene>                       pEndScene       = std::get<1> (prevStep);
        aVector<shared_ptr<StepChannelTuple>>   &vChannelTuple  = std::get<2> (prevStep);   // reference!
        const aVector<channelValueTuple>        &vStartChannels = pStartScene->channelValues();
        const channelValueTuple                 *pEndChannel    = nullptr;

        // iterate over all start scene channels and find the same endChannel
        for (const channelValueTuple &startChannel : vStartChannels)
        {
            pEndChannel = pEndScene->findCorrespondingChannelValueTuple(startChannel);

            // if we find a corresponding end channel
            if (pEndChannel != nullptr &&
                std::get<1> (startChannel) != std::get<1> (*pEndChannel))
            {
                shared_ptr<Channel> pChannel        = std::get<0> (startChannel);
                u8                  u8StartValue    = std::get<1> (startChannel);
                u8                  u8EndValue      = std::get<1> (*pEndChannel);

                shared_ptr<StepChannelTuple> pSCT   = make_shared<StepChannelTuple> (pChannel, u8StartValue, u8EndValue);

                vChannelTuple.push_back(pSCT);
            }
        }
    }
} // Chase::addStep


/*******************************************************************************
* Chase::playChase
*******************************************************************************/
void Chase::playChase()
{
    cout << __PRETTY_FUNCTION__ << endl;

    // cout << this << "<-this, playChase: " << m_vSteps.size() << " steps" << endl;

    // for (auto &st : m_vSteps)
    // {
        // shared_ptr<Scene>                           pStartScene = std::get<0> (st);
        // shared_ptr<Scene>                           pEndScene   = std::get<1> (st);
        // const aVector<shared_ptr<StepChannelTuple>> &vChannels  = std::get<2> (st);
        // s32                                         s32Length_s = std::get<3> (st);
    // }

    //m_timer.start(250);
} // Chase::playChase


/*******************************************************************************
* Chase::onTimeout
*******************************************************************************/
// void Chase::onTimeout()
// {
//     cout << "onTimeout" << endl;
// } // Chase::onTimeout

/*******************************************************************************
* Chase::add2Configuration
*******************************************************************************/
void Chase::add2Configuration(aJsonFile     &/*_jf*/,
                              s32           /*_idx*/) const
{
    // _jf.openLevel();
    //     // add Chase info
    //     _jf.add(aJsonValue("idx", (dbl) _idx));
    //     _jf.add(aJsonValue("ChaseName", m_sName));

    //     // add the channels
    //     for (const channelValueTuple &t : m_vValues)
    //     {
    //         shared_ptr<Channel> pChannel        = std::get<0> (t);
    //         u8                  u8Value         = std::get<1> (t);

    //         aString             sFixName        = pChannel->fixture()->name();
    //         s32                 s32ChannelNr    = pChannel->channelNr();

    //         _jf.openLevel();
    //             _jf.add(aJsonValue("ChaseName", m_sName));
    //             _jf.add(aJsonValue("fixtureName", sFixName));
    //             _jf.add(aJsonValue("channelNr", (dbl) s32ChannelNr));
    //             _jf.add(aJsonValue("value", (dbl) u8Value));
    //         _jf.closeLevel(aString("channel") + "-" + sFixName + "-" + aString::fromValue(s32ChannelNr));
    //     }
    // _jf.closeLevel(aString("Chase") + "-" + m_sName);
} // Chase::add2Configuration
