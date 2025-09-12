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
#include "aToolCb.h"



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
    CHECK_PRE_CONDITION_VOID(_pTool);

    m_vTools.push_back(std::move(_pTool));
    m_vTools.back()->onActivate(true);

    if (m_vTools.back()->toolCb())
    {
        m_vTools.back()->toolCb()->onToolStart(m_vTools.back().get());
    }
} // aToolMgr::addTool


/*******************************************************************************
* aToolMgr::activeTool
*******************************************************************************/
const aToolBase* aToolMgr::activeTool() const
{
    // tool at the back is active
    return (!m_vTools.empty())?    m_vTools.back().get() : nullptr;
} // aToolMgr::activeTool


/*******************************************************************************
* aToolMgr::activeTool
*******************************************************************************/
aToolBase* aToolMgr::activeTool()
{
    // tool at the back is active
    return (!m_vTools.empty())?    m_vTools.back().get() : nullptr;
} // aToolMgr::activeTool


/*******************************************************************************
* aToolMgr::onToolMgrEnter
*******************************************************************************/
bool aToolMgr::onToolMgrEnter(u16             _u16Modifier,
                              const aPoint    &_pntLocal,
                              const aPoint    &_pntGlobal)
{
    enumToolResult  eResult = enumToolResult::UNHANDLED;

    if (m_vTools.back() != nullptr)
    {
        eResult = m_vTools.back()->onToolEnter(_u16Modifier, _pntLocal, _pntGlobal);

        manage(m_vTools.back(), eResult);
    }

    return eResult != enumToolResult::UNHANDLED;
} // aToolMgr::onToolMgrEnter


/*******************************************************************************
* aToolMgr::onToolMgrLeave
*******************************************************************************/
bool aToolMgr::onToolMgrLeave(u16             _u16Modifier)
{
    enumToolResult  eResult = enumToolResult::UNHANDLED;

    if (m_vTools.back() != nullptr)
    {
        eResult = m_vTools.back()->onToolLeave(_u16Modifier);

        manage(m_vTools.back(), eResult);
    }

    return eResult != enumToolResult::UNHANDLED;
} // aToolMgr::onToolMgrLeave


/*******************************************************************************
* aToolMgr::onToolMgrWheel
*******************************************************************************/
bool aToolMgr::onToolMgrWheel(u16             _u16Modifier,
                              s16             _s16Degree,
                              const aPoint    &_pntLocal,
                              const aPoint    &_pntGlobal)
{
    enumToolResult  eResult = enumToolResult::UNHANDLED;

    if (m_vTools.back() != nullptr)
    {
        eResult = m_vTools.back()->onToolWheel(_u16Modifier, _s16Degree, _pntLocal, _pntGlobal);

        manage(m_vTools.back(), eResult);
    }

    return eResult != enumToolResult::UNHANDLED;
} // aToolMgr::onToolMgrWheel


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

        manage(m_vTools.back(), eResult);
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

        manage(m_vTools.back(), eResult);
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

        manage(m_vTools.back(), eResult);
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
        manage(m_vTools.back(), eResult);
    }

    return eResult != enumToolResult::UNHANDLED;
} // aToolMgr::onToolMgrButtonRelease


/*******************************************************************************
* aToolMgr::manage
*******************************************************************************/
void aToolMgr::manage(std::unique_ptr<aToolBase>    &/*_pTool*/,
                      enumToolResult                _eResult)
{
    switch (_eResult)
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
