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
#include "aToolMgr.h"
#include "aToolBase.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


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
* aToolMgr::cancelAllTools
*******************************************************************************/
void aToolMgr::cancelAllTools()
{
    while (!m_lstTools.empty())
    {
        manageTool(m_lstTools.front().get(), enumToolResult::Canceled);
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
    //m_lstTools.back()->onSetCursor();

    onToolStarted(m_lstTools.back().get());
} // aToolMgr::setTool


/*******************************************************************************
* aToolMgr::addTool
*******************************************************************************/
void aToolMgr::addTool(unique_ptr<aToolBase>_pTool)
{
    m_lstTools.push_back(std::move(_pTool));

    m_lstTools.back()->onToolActivated(true);
    //m_lstTools.back()->OnSetCursor();

    onToolStarted(m_lstTools.back().get());
} // aToolMgr::addTool


/*******************************************************************************
* aToolMgr::ActiveTool
*******************************************************************************/
aToolBase* aToolMgr::ActiveTool() const
{
    if (!m_lstTools.empty())
    {
        return m_lstTools.back().get();
    }

    return nullptr;
} // aToolMgr::ActiveTool


/*******************************************************************************
* aToolMgr::toolMgrOnWheel
*******************************************************************************/
bool aToolMgr::toolMgrOnWheel(u32                  _u32Modifiers,
                              s32                  _s32Degree,
                              const aVector2D<s32> &_v2dLocal,
                              const aVector2D<s32> &_v2dGlobal)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        aToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->toolOnWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal));
    }

    return bHandled;
} // aToolMgr::toolMgrOnWheel


/*******************************************************************************
* aToolMgr::sendToolMsg
*******************************************************************************/
void aToolMgr::sendToolMsg(aToolBase    *_pTool,
                           u32          _u32Msg)
{
    onToolMsg(_pTool, _u32Msg, 0, 0, 0, 0, 0., 0.);
} // aToolMgr::sendToolMsg


/*******************************************************************************
* aToolMgr::sendToolMsg
*******************************************************************************/
void aToolMgr::sendToolMsg(aToolBase    *_pTool,
                           u32          _u32Msg,
                           s32          _s32Param1)
{
    onToolMsg(_pTool, _u32Msg, _s32Param1, 0, 0, 0, 0., 0.);
} // aToolMgr::sendToolMsg


/*******************************************************************************
* aToolMgr::manageTool
*******************************************************************************/
bool aToolMgr::manageTool(aToolBase         *_pTool,
                          enumToolResult    _eToolResult)
{
    bool bHandled = false;

    switch (_eToolResult)
    {
        case enumToolResult::Unhandled:
            bHandled = false;
            break;

        case enumToolResult::Handled:
            return true;

        case enumToolResult::Success:
        {
            unique_ptr<aToolBase>   pTool = m_lstTools.findAndSteal(_pTool);

            if (pTool != nullptr)
            {
                pTool->onToolActivated(false);

                onToolSuccess(pTool.get());
                onToolFinished(pTool->toolId());
                bHandled = true;
            }

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
                bHandled = true;
            }

            break;
        } // case enumToolResult::Canceled:

    } // switch (_eToolResult)

    return bHandled;
} // aToolMgr::manageTool


} // namespace aUtil
} // namespace aFrame


// namespace qLib
// {
//     /*******************************************************************************
//     * aToolMgr::ToolMgrOnEnter
//     *******************************************************************************/
//     bool aToolMgr::ToolMgrOnEnter(u32                  _u32Modifiers,
//                                   const aVector2D<s32> &_v2dLocal,
//                                   const aVector2D<s32> &_v2dGlobal)
//     {
//         bool    bHandled = false;

//         if (!m_lstTools.empty())
//         {
//             aToolBase   *pTool = m_lstTools.back().get();

//             bHandled = ManageTool(pTool, pTool->ToolOnEnter(_u32Modifiers, _v2dLocal, _v2dGlobal));
//         }

//         return bHandled;
//     } // aToolMgr::ToolMgrOnEnter


//     /*******************************************************************************
//     * aToolMgr::ToolMgrOnLeave
//     *******************************************************************************/
//     bool aToolMgr::ToolMgrOnLeave(u32                  _u32Modifiers)
//     {
//         bool    bHandled = false;

//         if (!m_lstTools.empty())
//         {
//             aToolBase   *pTool = m_lstTools.back().get();

//             bHandled = ManageTool(pTool, pTool->ToolOnLeave(_u32Modifiers));
//         }

//         return bHandled;
//     } // aToolMgr::ToolMgrOnLeave


//     /*******************************************************************************
//     * aToolMgr::ToolMgrOnDoubleClick
//     *******************************************************************************/
//     bool aToolMgr::ToolMgrOnDoubleClick(u32                   _u32Modifiers,
//                                         u32                   _u32MouseButton,
//                                         const aVector2D<s32>  &_v2dLocal,
//                                         const aVector2D<s32>  &_v2dGlobal)
//     {
//         bool    bHandled = false;

//         if (!m_lstTools.empty())
//         {
//             aToolBase   *pTool = m_lstTools.back().get();

//             bHandled = ManageTool(pTool, pTool->ToolOnDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
//         } // if...

//         return bHandled;
//     } // aToolMgr::ToolMgrOnDoubleClick


//     /*******************************************************************************
//     * aToolMgr::ToolMgrOnMousePress
//     *******************************************************************************/
//     bool aToolMgr::ToolMgrOnMousePress(u32                   _u32Modifiers,
//                                        u32                   _u32MouseButton,
//                                        const aVector2D<s32>  &_v2dLocal,
//                                        const aVector2D<s32>  &_v2dGlobal)
//     {
//         bool    bHandled = false;

//         if (!m_lstTools.empty())
//         {
//             aToolBase   *pTool = m_lstTools.back().get();

//             bHandled = ManageTool(pTool, pTool->ToolOnMousePress(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
//         } // if...

//         return bHandled;
//     } // aToolMgr::ToolMgrOnMousePress


//     /*******************************************************************************
//     * aToolMgr::ToolMgrOnMouseMove
//     *******************************************************************************/
//     bool aToolMgr::ToolMgrOnMouseMove(u32                   _u32Modifiers,
//                                       u32                   _u32MouseButton,
//                                       const aVector2D<s32>  &_v2dLocal,
//                                       const aVector2D<s32>  &_v2dGlobal)
//     {
//         bool    bHandled = false;

//         if (!m_lstTools.empty())
//         {
//             aToolBase   *pTool = m_lstTools.back().get();

//             bHandled = ManageTool(pTool, pTool->ToolOnMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
//         } // if...

//         return bHandled;
//     } // aToolMgr::ToolMgrOnMouseMove


//     /*******************************************************************************
//     * aToolMgr::ToolMgrOnMouseRelease
//     *******************************************************************************/
//     bool aToolMgr::ToolMgrOnMouseRelease(u32                   _u32Modifiers,
//                                          u32                   _u32MouseButton,
//                                          const aVector2D<s32>  &_v2dLocal,
//                                          const aVector2D<s32>  &_v2dGlobal)
//     {
//         bool    bHandled = false;

//         if (!m_lstTools.empty())
//         {
//             aToolBase   *pTool = m_lstTools.back().get();

//             bHandled = ManageTool(pTool, pTool->ToolOnMouseRelease(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
//         } // if...

//         return bHandled;
//     } // aToolMgr::ToolMgrOnMouseRelease


//     /*******************************************************************************
//     * aToolMgr::ToolMgrOnPaintToolMarker
//     *******************************************************************************/
//     void aToolMgr::ToolMgrOnPaintToolMarker()
//     {
//         for (unique_ptr<aToolBase> &pTool : m_lstTools)
//         {
//             pTool.get()->OnPaintToolMarker();
//         }
//     } // aToolMgr::ToolMgrOnPaintToolMarker


//     /*******************************************************************************
//     * aToolMgr::OnToolStarted
//     *******************************************************************************/
//     void aToolMgr::OnToolStarted(aToolBase */*_pTool*/)
//     {
//     } // aToolMgr::OnToolStarted


//     /*******************************************************************************
//     * aToolMgr::OnToolSuccess
//     *******************************************************************************/
//     void aToolMgr::OnToolSuccess(aToolBase */*_pTool*/)
//     {
//     } // aToolMgr::OnToolSuccess


//     /*******************************************************************************
//     * aToolMgr::OnToolCanceled
//     *******************************************************************************/
//     void aToolMgr::OnToolCanceled(aToolBase */*_pTool*/)
//     {
//     } // aToolMgr::OnToolCanceled


//     /*******************************************************************************
//     * aToolMgr::OnToolFinished
//     *******************************************************************************/
//     void aToolMgr::OnToolFinished(u32 /*_u32ToolId*/)
//     {
//     } // aToolMgr::OnToolFinished


//     /*******************************************************************************
//     * aToolMgr::OnToolMsg
//     *******************************************************************************/
//     void aToolMgr::OnToolMsg(aToolBase */*_pTool*/,
//                              u32       /*_u32Msg*/,
//                              s32       /*_s32Param*/,
//                              u32       /*_u32Param*/,
//                              s64       /*_s64Param*/,
//                              u64       /*_u64Param*/,
//                              flt       /*_fltParam*/,
//                              dbl       /*_dblParam*/)
//     {
//     } // aToolMgr::OnToolMsg

// } // namespace qLib
