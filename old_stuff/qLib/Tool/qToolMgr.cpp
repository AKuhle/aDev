/*******************************************************************************
* \file qToolMgr.inl
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
#include "qToolMgr.h"
#include "qToolBase.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Tool {


/*******************************************************************************
* qToolMgr::qToolMgr
*******************************************************************************/
qToolMgr::qToolMgr()
{
} // qToolMgr::qToolMgr


/*******************************************************************************
* qToolMgr::~qToolMgr
*******************************************************************************/
qToolMgr::~qToolMgr()
{
} // qToolMgr::~qToolMgr


/*******************************************************************************
* qToolMgr::doEnter
*******************************************************************************/
bool qToolMgr::doEnter(u32                  _u32Modifiers,
                       const qVector2D<s32> &_v2dLocal,
                       const qVector2D<s32> &_v2dGlobal)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        qToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->doEnter(_u32Modifiers, _v2dLocal, _v2dGlobal));
    }

    return bHandled;
} // qToolMgr::doEnter


/*******************************************************************************
* qToolMgr::doLeave
*******************************************************************************/
bool qToolMgr::doLeave(u32                  _u32Modifiers)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        qToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->doLeave(_u32Modifiers));
    }

    return bHandled;
} // qToolMgr::doLeave


/*******************************************************************************
* qToolMgr::doWheel
*******************************************************************************/
bool qToolMgr::doWheel(u32                  _u32Modifiers,
                       s32                  _s32Degree,
                       const qVector2D<s32> &_v2dLocal,
                       const qVector2D<s32> &_v2dGlobal)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        qToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->doWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal));
    }

    return bHandled;
} // qToolMgr::doWheel


/*******************************************************************************
* qToolMgr::doDoubleClick
*******************************************************************************/
bool qToolMgr::doDoubleClick(u32                   _u32Modifiers,
                             u32                   _u32MouseButton,
                             const qVector2D<s32>  &_v2dLocal,
                             const qVector2D<s32>  &_v2dGlobal)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        qToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->doDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
    } // if...

    return bHandled;
} // qToolMgr::doDoubleClick


/*******************************************************************************
* qToolMgr::doMousePress
*******************************************************************************/
bool qToolMgr::doMousePress(u32                   _u32Modifiers,
                            u32                   _u32MouseButton,
                            const qVector2D<s32>  &_v2dLocal,
                            const qVector2D<s32>  &_v2dGlobal)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        qToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->doMousePress(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
    } // if...

    return bHandled;
} // qToolMgr::doMousePress


/*******************************************************************************
* qToolMgr::doMouseMove
*******************************************************************************/
bool qToolMgr::doMouseMove(u32                   _u32Modifiers,
                           u32                   _u32MouseButton,
                           const qVector2D<s32>  &_v2dLocal,
                           const qVector2D<s32>  &_v2dGlobal)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        qToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->doMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
    } // if...

    return bHandled;
} // qToolMgr::doMouseMove


/*******************************************************************************
* qToolMgr::doMouseRelease
*******************************************************************************/
bool qToolMgr::doMouseRelease(u32                   _u32Modifiers,
                              u32                   _u32MouseButton,
                              const qVector2D<s32>  &_v2dLocal,
                              const qVector2D<s32>  &_v2dGlobal)
{
    bool    bHandled = false;

    if (!m_lstTools.empty())
    {
        qToolBase   *pTool = m_lstTools.back().get();

        bHandled = manageTool(pTool, pTool->doMouseRelease(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
    } // if...

    return bHandled;
} // qToolMgr::doMouseRelease


/*******************************************************************************
* qToolMgr::paintToolMarker
*******************************************************************************/
void qToolMgr::paintToolMarker()
{
    for (unique_ptr<qToolBase> &pTool : m_lstTools)
    {
        pTool.get()->paintToolMarker();
    }
} // qToolMgr::paintToolMarker


/*******************************************************************************
* qToolMgr::sendToolMsg
*******************************************************************************/
void qToolMgr::sendToolMsg(qToolBase *_pTool,
                           u32       _u32Msg)
{
    onToolMsg(_pTool, _u32Msg, 0, 0, 0, 0, 0., 0.);
} // qToolMgr::sendToolMsg


/*******************************************************************************
* qToolMgr::sendToolMsg
*******************************************************************************/
void qToolMgr::sendToolMsg(qToolBase    *_pTool,
                           u32          _u32Msg,
                           s32          _s32Param1)
{
    onToolMsg(_pTool, _u32Msg, _s32Param1, 0, 0, 0, 0., 0.);
} // qToolMgr::sendToolMsg


/*******************************************************************************
* qToolMgr::cancelAllTools
*******************************************************************************/
void qToolMgr::cancelAllTools()
{
    while (!m_lstTools.empty())
    {
        manageTool(m_lstTools.front().get(), enumToolResult::Canceled);
    } // while
} // qToolMgr::cancelAllTools


/*******************************************************************************
* qToolMgr::setTool
*******************************************************************************/
void qToolMgr::setTool(unique_ptr<qToolBase>_pTool)
{
    cancelAllTools();

    m_lstTools.push_back(std::move(_pTool));

    m_lstTools.back()->onToolActivated(true);
    m_lstTools.back()->setCursor();

    onToolStarted(m_lstTools.back().get());
} // qToolMgr::setTool


/*******************************************************************************
* qToolMgr::addTool
*******************************************************************************/
void qToolMgr::addTool(unique_ptr<qToolBase>_pTool)
{
    m_lstTools.push_back(std::move(_pTool));

    m_lstTools.back()->onToolActivated(true);
    m_lstTools.back()->setCursor();

    onToolStarted(m_lstTools.back().get());
} // qToolMgr::addTool


/*******************************************************************************
* qToolMgr::activeTool
*******************************************************************************/
qToolBase* qToolMgr::activeTool() const
{
    if (!m_lstTools.empty())
    {
        return m_lstTools.back().get();
    }

    return nullptr;
} // qToolMgr::activeTool


/*******************************************************************************
* qToolMgr::onToolStarted
*******************************************************************************/
void qToolMgr::onToolStarted(qToolBase */*_pTool*/)
{
} // qToolMgr::onToolStarted


/*******************************************************************************
* qToolMgr::onToolSuccess
*******************************************************************************/
void qToolMgr::onToolSuccess(qToolBase */*_pTool*/)
{
} // qToolMgr::OnToolSuccess


/*******************************************************************************
* qToolMgr::onToolCanceled
*******************************************************************************/
void qToolMgr::onToolCanceled(qToolBase */*_pTool*/)
{
} // qToolMgr::onToolCanceled


/*******************************************************************************
* qToolMgr::onToolFinished
*******************************************************************************/
void qToolMgr::onToolFinished(u32 /*_u32ToolId*/)
{
} // qToolMgr::onToolFinished


/*******************************************************************************
* qToolMgr::onToolMsg
*******************************************************************************/
void qToolMgr::onToolMsg(qToolBase */*_pTool*/,
                         u32       /*_u32Msg*/,
                         s32       /*_s32Param*/,
                         u32       /*_u32Param*/,
                         s64       /*_s64Param*/,
                         u64       /*_u64Param*/,
                         flt       /*_fltParam*/,
                         dbl       /*_dblParam*/)
{
} // qToolMgr::onToolMsg


/*******************************************************************************
* qToolMgr::manageTool
*******************************************************************************/
bool qToolMgr::manageTool(qToolBase            *_pTool,
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
            unique_ptr<qToolBase>   pTool = m_lstTools.FindAndRemove(_pTool);

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
            unique_ptr<qToolBase>   pTool = m_lstTools.FindAndRemove(_pTool);

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

} // qToolMgr::manageTool


} // namespace Tool
} // namespace qLib
