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

class Universe;


/*******************************************************************************
* gloabl constants
*******************************************************************************/
constexpr QColor    colDeviceImageBg(120, 120, 120);

constexpr aFrame::s32       BANK_SET_COUNT { 5 };
constexpr aFrame::s32       BANK_BTN_COUNT { 20 };
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


using UniverseTuple = std::tuple<std::shared_ptr<Universe>, std::vector<aFrame::u8>>;


/*******************************************************************************
* structs
*******************************************************************************/
// struct structChannelIcn
// {
//     QString     rscName;
//     QPixmap     pixmap;
// };
