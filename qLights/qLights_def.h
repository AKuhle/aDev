/*******************************************************************************
* \file Channel.h
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
#include "aFrame_def.h"

#include <QColor>
#include <QPixmap>

#include "aFrame_def.h"

using namespace std;
using namespace aFrame;

class Universe;
class DmxData;
class BankButton;
class SceneButton;
class ChaseButton;
class Fixture;
class Universe;
class Scene;
class Chase;


/*******************************************************************************
* alias
*******************************************************************************/
using mapChannelValue = std::map<int, u8>;


/*******************************************************************************
* gloabl constants
*******************************************************************************/
constexpr QColor            colDeviceImageBg(120, 120, 120);

constexpr aFrame::u32       UNIVERSE_UPDATE_TIME_MS     { 50 };
constexpr aFrame::u32       CHASE_UPDATE_TIME_MS        { 50 };
constexpr aFrame::u32       BLACK_START_TIME_MS         { 2000 };

constexpr aFrame::u32       DMX_DATA_SIZE               { 512 };

constexpr aFrame::s32       BANK_SET_COUNT              { 5 };
constexpr aFrame::s32       BANK_BTN_COUNT              { 20 };
constexpr aFrame::s32       BANK_1 { 0 };
constexpr aFrame::s32       BANK_2 { 1 };
constexpr aFrame::s32       BANK_3 { 2 };
constexpr aFrame::s32       BANK_4 { 3 };
constexpr aFrame::s32       BANK_5 { 4 };

constexpr aFrame::s32       SCENE_SET_COUNT { 5 };
constexpr aFrame::s32       SCENE_BTN_COUNT { 20 };
constexpr aFrame::s32       SCENE_1 { 0 };
constexpr aFrame::s32       SCENE_2 { 1 };
constexpr aFrame::s32       SCENE_3 { 2 };
constexpr aFrame::s32       SCENE_4 { 3 };
constexpr aFrame::s32       SCENE_5 { 4 };

constexpr aFrame::s32       CHASE_SET_COUNT { 5 };
constexpr aFrame::s32       CHASE_BTN_COUNT { 20 };
constexpr aFrame::s32       CHASE_1 { 0 };
constexpr aFrame::s32       CHASE_2 { 1 };
constexpr aFrame::s32       CHASE_3 { 2 };
constexpr aFrame::s32       CHASE_4 { 3 };
constexpr aFrame::s32       CHASE_5 { 4 };


/*******************************************************************************
* struct stBankBtn
*******************************************************************************/
struct stBankBtn
{
    BankButton              *pBtn;
    shared_ptr<Fixture>     pFixture;

}; // stBankBtn


/*******************************************************************************
* struct stSceneBtn
*******************************************************************************/
struct stSceneBtn
{
    SceneButton         *pBtn;
    shared_ptr<Scene>   pScene;

}; // stSceneBtn


/*******************************************************************************
* struct stChaseBtn
*******************************************************************************/
struct stChaseBtn
{
    ChaseButton         *pBtn;
    shared_ptr<Chase>   pChase;
}; // stChaseBtn


/*******************************************************************************
* struct stUniverseInfo
*******************************************************************************/
struct stUniverseInfo
{
    shared_ptr<Universe>    pUniverse;
    QByteArray              data;
}; // stUniverseInfo


/*******************************************************************************
* struct stChaseStep
*******************************************************************************/
struct stChaseStep
{
    QString     sSceneName;
    u32         u32Duration_ms;
}; // stChaseStep
