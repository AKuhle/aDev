/*******************************************************************************
* \file aToolMgr.inl
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
#include "aWin/Tool/aToolMgr.h"

using namespace std;
using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
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
* aToolMgr::doToolMgrEnter
*******************************************************************************/
bool aToolMgr::doToolMgrEnter(u32                  _u32Modifiers,
                              const aVector2D<s32> &_v2dLocal,
                              const aVector2D<s32> &_v2dGlobal)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        aToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->doToolEnter(_u32Modifiers, _v2dLocal, _v2dGlobal));
    }

    return bHandled;
} // aToolMgr::doToolMgrEnter


/*******************************************************************************
* aToolMgr::doToolMgrLeave
*******************************************************************************/
bool aToolMgr::doToolMgrLeave(u32 _u32Modifiers)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        aToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->doToolLeave(_u32Modifiers));
    }

    return bHandled;
} // aToolMgr::doToolMgrLeave


/*******************************************************************************
* aToolMgr::doToolMgrWheel
*******************************************************************************/
bool aToolMgr::doToolMgrWheel(u32                  _u32Modifiers,
                              s32                  _s32Degree,
                              const aVector2D<s32> &_v2dLocal,
                              const aVector2D<s32> &_v2dGlobal)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        aToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->doToolWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal));
    }

    return bHandled;
} // aToolMgr::doToolMgrWheel


/*******************************************************************************
* aToolMgr::doToolMgrDoubleClick
*******************************************************************************/
bool aToolMgr::doToolMgrDoubleClick(u32                   _u32Modifiers,
                                    u32                   _u32MouseButton,
                                    const aVector2D<s32>  &_v2dLocal,
                                    const aVector2D<s32>  &_v2dGlobal)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        aToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->doToolDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
    } // if...

    return bHandled;
} // aToolMgr::doToolMgrDoubleClick


/*******************************************************************************
* aToolMgr::doToolMgrMousePress
*******************************************************************************/
bool aToolMgr::doToolMgrMousePress(u32                   _u32Modifiers,
                                   u32                   _u32MouseButton,
                                   const aVector2D<s32>  &_v2dLocal,
                                   const aVector2D<s32>  &_v2dGlobal)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        aToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->doToolMousePress(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
    } // if...

    return bHandled;
} // aToolMgr::doToolMgrMousePress


/*******************************************************************************
* aToolMgr::doToolMgrMouseMove
*******************************************************************************/
bool aToolMgr::doToolMgrMouseMove(u32                   _u32Modifiers,
                                  u32                   _u32MouseButton,
                                  const aVector2D<s32>  &_v2dLocal,
                                  const aVector2D<s32>  &_v2dGlobal)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        aToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->doToolMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
    } // if...

    return bHandled;
} // aToolMgr::doToolMgrMouseMove


/*******************************************************************************
* aToolMgr::doToolMgrMouseRelease
*******************************************************************************/
bool aToolMgr::doToolMgrMouseRelease(u32                   _u32Modifiers,
                                     u32                   _u32MouseButton,
                                     const aVector2D<s32>  &_v2dLocal,
                                     const aVector2D<s32>  &_v2dGlobal)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        aToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->doToolMouseRelease(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
    } // if...

    return bHandled;
} // aToolMgr::doToolMgrMouseRelease


// /*******************************************************************************
// * aToolMgr::paintToolMarker
// *******************************************************************************/
// void aToolMgr::paintToolMarker()
// {
//     for (unique_ptr<aToolBase> &pTool : m_lstTools)
//     {
//         pTool.get()->paintToolMarker();
//     }
// } // aToolMgr::paintToolMarker


// /*******************************************************************************
// * aToolMgr::sendToolMsg
// *******************************************************************************/
// void aToolMgr::sendToolMsg(aToolBase *_pTool,
//                            u32       _u32Msg)
// {
//     onToolMsg(_pTool, _u32Msg, 0, 0, 0, 0, 0., 0.);
// } // aToolMgr::sendToolMsg


// /*******************************************************************************
// * aToolMgr::sendToolMsg
// *******************************************************************************/
// void aToolMgr::sendToolMsg(aToolBase    *_pTool,
//                            u32          _u32Msg,
//                            s32          _s32Param1)
// {
//     onToolMsg(_pTool, _u32Msg, _s32Param1, 0, 0, 0, 0., 0.);
// } // aToolMgr::sendToolMsg


/*******************************************************************************
* aToolMgr::cancelAllTools
*******************************************************************************/
void aToolMgr::cancelAllTools()
{
    while (!m_lstTools.empty())
    {
        manageTool(m_lstTools.back().get(), enumToolResult::Canceled);
    } // while
} // aToolMgr::cancelAllTools


/*******************************************************************************
* aToolMgr::setTool
*******************************************************************************/
void aToolMgr::setTool(unique_ptr<aToolBase>_pTool)
{
    cancelAllTools();

    m_lstTools.push_back(std::move(_pTool));

    m_lstTools.back()->onToolActivated(true);
    m_lstTools.back()->setCursor();

    onToolStarted(m_lstTools.back().get());
} // aToolMgr::setTool


/*******************************************************************************
* aToolMgr::addTool
*******************************************************************************/
void aToolMgr::addTool(unique_ptr<aToolBase>_pTool)
{
    m_lstTools.push_back(std::move(_pTool));

    m_lstTools.back()->onToolActivated(true);
    m_lstTools.back()->setCursor();

    onToolStarted(m_lstTools.back().get());
} // aToolMgr::addTool


// /*******************************************************************************
// * aToolMgr::activeTool
// *******************************************************************************/
// aToolBase* aToolMgr::activeTool() const
// {
//     if (!m_lstTools.empty())
//     {
//         return m_lstTools.back().get();
//     }

//     return nullptr;
// } // aToolMgr::activeTool


/*******************************************************************************
* aToolMgr::onToolStarted
*******************************************************************************/
void aToolMgr::onToolStarted(aToolBase */*_pTool*/)
{
} // aToolMgr::onToolStarted


/*******************************************************************************
* aToolMgr::onToolSuccess
*******************************************************************************/
void aToolMgr::onToolSuccess(aToolBase */*_pTool*/)
{
} // aToolMgr::OnToolSuccess


/*******************************************************************************
* aToolMgr::onToolCanceled
*******************************************************************************/
void aToolMgr::onToolCanceled(aToolBase */*_pTool*/)
{
} // aToolMgr::onToolCanceled


/*******************************************************************************
* aToolMgr::onToolFinished
*******************************************************************************/
void aToolMgr::onToolFinished(u32 /*_u32ToolId*/)
{
} // aToolMgr::onToolFinished


// /*******************************************************************************
// * aToolMgr::onToolMsg
// *******************************************************************************/
// void aToolMgr::onToolMsg(aToolBase */*_pTool*/,
//                          u32       /*_u32Msg*/,
//                          s32       /*_s32Param*/,
//                          u32       /*_u32Param*/,
//                          s64       /*_s64Param*/,
//                          u64       /*_u64Param*/,
//                          flt       /*_fltParam*/,
//                          dbl       /*_dblParam*/)
// {
// } // aToolMgr::onToolMsg


/*******************************************************************************
* aToolMgr::manageTool
*******************************************************************************/
bool aToolMgr::manageTool(aToolBase         *_pTool,
                           enumToolResult   _eToolResult)
{
    bool    bHandled = false;

    switch (_eToolResult)
    {
        case enumToolResult::Unhandled:
            break;

        case enumToolResult::Handled:
            bHandled = true;
            break;

        case enumToolResult::Success:
        {
            unique_ptr<aToolBase>   pTool = m_lstTools.findAndSteal(_pTool);

            if (pTool != nullptr)
            {
                pTool->onToolActivated(false);

                onToolSuccess(pTool.get());
                onToolFinished(pTool->toolId());
            }

            bHandled = true;
            break;
        } // case enumToolResult::Done:

        case enumToolResult::Canceled:
        {
            unique_ptr<aToolBase>   pTool = m_lstTools.findAndSteal(_pTool);

            if (pTool != nullptr)
            {
                pTool->onToolActivated(false);

                onToolCanceled(pTool.get());
                onToolFinished(pTool->toolId());
            }

            bHandled = true;
            break;
        } // case enumToolResult::Canceled:

    } // switch (_eToolResult)

    return bHandled;

} // aToolMgr::manageTool


} // namespace aWin
} // namespace aLib
