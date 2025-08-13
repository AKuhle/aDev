/*******************************************************************************
* \file aToolMgr.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aToolMgr.h"
#include "aToolBase.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aToolMgr::aToolMgr
*******************************************************************************/
aToolMgr::aToolMgr()
{
} // aToolMgr::aToolMgr


/*******************************************************************************
* aToolMgr::~aToolMgr
*******************************************************************************/
aToolMgr::~aToolMgr()
{
} // aToolMgr::~aToolMgr


/*******************************************************************************
* aToolMgr::addTool
*******************************************************************************/
void aToolMgr::addTool(std::unique_ptr<aToolBase>  _pTool)
{
    m_vTools.push_back(std::move(_pTool));
} // aToolMgr::addTool


/*******************************************************************************
* aToolMgr::onToolMgrDoubleClick
*******************************************************************************/
bool aToolMgr::onToolMgrDoubleClick(u16             _u16Modifier,
                                    u16             _u16Btn,
                                    const aPoint    &_pntLocal,
                                    const aPoint    &_pntGlobal)
{
    enumToolResult  eResult = enumToolResult::UNHANDLED;

    if (m_vTools.back() != nullptr)
    {
        eResult = m_vTools.back()->onToolDoubleClick(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);

        manage(m_vTools.back().get(), eResult);
    }

    return eResult != enumToolResult::UNHANDLED;
} // aToolMgr::onToolMgrDoubleClick


/*******************************************************************************
* aToolMgr::onToolMgrButtonPress
*******************************************************************************/
bool aToolMgr::onToolMgrButtonPress(u16             _u16Modifier,
                                    u16             _u16Btn,
                                    const aPoint    &_pntLocal,
                                    const aPoint    &_pntGlobal)
{
    enumToolResult  eResult = enumToolResult::UNHANDLED;

    if (m_vTools.back() != nullptr)
    {
        eResult = m_vTools.back()->onToolButtonPress(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);

        manage(m_vTools.back().get(), eResult);
    }

    return eResult != enumToolResult::UNHANDLED;
} // aToolMgr::onToolMgrButtonPress


/*******************************************************************************
* aToolMgr::onToolMgrMouseMove
*******************************************************************************/
bool aToolMgr::onToolMgrMouseMove(u16           _u16Modifier,
                                  u16           _u16Btn,
                                  const aPoint  &_pntLocal,
                                  const aPoint  &_pntGlobal)
{
    enumToolResult  eResult = enumToolResult::UNHANDLED;

    if (m_vTools.back() != nullptr)
    {
        eResult = m_vTools.back()->onToolMouseMove(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);

        manage(m_vTools.back().get(), eResult);
    }

    return eResult != enumToolResult::UNHANDLED;
} // aToolMgr::onToolMgrMouseMove


/*******************************************************************************
* aToolMgr::onToolMgrButtonRelease
*******************************************************************************/
bool aToolMgr::onToolMgrButtonRelease(u16           _u16Modifier,
                                      u16           _u16Btn,
                                      const aPoint  &_pntLocal,
                                      const aPoint  &_pntGlobal)
{
    enumToolResult  eResult = enumToolResult::UNHANDLED;

    if (m_vTools.back() != nullptr)
    {
        eResult = m_vTools.back()->onToolButtonRelease(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);
        manage(m_vTools.back().get(), eResult);
    }

    return eResult != enumToolResult::UNHANDLED;
} // aToolMgr::onToolMgrButtonRelease


/*******************************************************************************
* aToolMgr::manage
*******************************************************************************/
void aToolMgr::manage(aToolBase        */*_pTool*/,
                      enumToolResult   _eRresult)
{
    switch (_eRresult)
    {
        case enumToolResult::UNHANDLED:
        {
        }

        case enumToolResult::HANDLED:
        {
        }

        case enumToolResult::SUCCESS:
        {
        }

        case enumToolResult::CANCELED:
        {
        }
    } // switch (_eRresult)
} // aToolMgr::manage



} // namespace aWin
} // namespace aFrame
