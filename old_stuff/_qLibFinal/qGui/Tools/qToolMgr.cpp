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


namespace qLib
{
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
    * qToolMgr::ToolMgrOnEnter
    *******************************************************************************/
    bool qToolMgr::ToolMgrOnEnter(u32                  _u32Modifiers,
                                  const qVector2D<s32> &_v2dLocal,
                                  const qVector2D<s32> &_v2dGlobal)
    {
        bool    bHandled = false;

        if (!m_lstTools.empty())
        {
            qToolBase   *pTool = m_lstTools.back().get();

            bHandled = ManageTool(pTool, pTool->ToolOnEnter(_u32Modifiers, _v2dLocal, _v2dGlobal));
        }

        return bHandled;
    } // qToolMgr::ToolMgrOnEnter


    /*******************************************************************************
    * qToolMgr::ToolMgrOnLeave
    *******************************************************************************/
    bool qToolMgr::ToolMgrOnLeave(u32                  _u32Modifiers)
    {
        bool    bHandled = false;

        if (!m_lstTools.empty())
        {
            qToolBase   *pTool = m_lstTools.back().get();

            bHandled = ManageTool(pTool, pTool->ToolOnLeave(_u32Modifiers));
        }

        return bHandled;
    } // qToolMgr::ToolMgrOnLeave


    /*******************************************************************************
    * qToolMgr::ToolMgrOnWheel
    *******************************************************************************/
    bool qToolMgr::ToolMgrOnWheel(u32                  _u32Modifiers,
                                  s32                  _s32Degree,
                                  const qVector2D<s32> &_v2dLocal,
                                  const qVector2D<s32> &_v2dGlobal)
    {
        bool    bHandled = false;

        if (!m_lstTools.empty())
        {
            qToolBase   *pTool = m_lstTools.back().get();

            bHandled = ManageTool(pTool, pTool->ToolOnWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal));
        }

        return bHandled;
    } // qToolMgr::ToolMgrOnWheel


    /*******************************************************************************
    * qToolMgr::ToolMgrOnDoubleClick
    *******************************************************************************/
    bool qToolMgr::ToolMgrOnDoubleClick(u32                   _u32Modifiers,
                                        u32                   _u32MouseButton,
                                        const qVector2D<s32>  &_v2dLocal,
                                        const qVector2D<s32>  &_v2dGlobal)
    {
        bool    bHandled = false;

        if (!m_lstTools.empty())
        {
            qToolBase   *pTool = m_lstTools.back().get();

            bHandled = ManageTool(pTool, pTool->ToolOnDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
        } // if...

        return bHandled;
    } // qToolMgr::ToolMgrOnDoubleClick


    /*******************************************************************************
    * qToolMgr::ToolMgrOnMousePress
    *******************************************************************************/
    bool qToolMgr::ToolMgrOnMousePress(u32                   _u32Modifiers,
                                       u32                   _u32MouseButton,
                                       const qVector2D<s32>  &_v2dLocal,
                                       const qVector2D<s32>  &_v2dGlobal)
    {
        bool    bHandled = false;

        if (!m_lstTools.empty())
        {
            qToolBase   *pTool = m_lstTools.back().get();

            bHandled = ManageTool(pTool, pTool->ToolOnMousePress(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
        } // if...

        return bHandled;
    } // qToolMgr::ToolMgrOnMousePress


    /*******************************************************************************
    * qToolMgr::ToolMgrOnMouseMove
    *******************************************************************************/
    bool qToolMgr::ToolMgrOnMouseMove(u32                   _u32Modifiers,
                                      u32                   _u32MouseButton,
                                      const qVector2D<s32>  &_v2dLocal,
                                      const qVector2D<s32>  &_v2dGlobal)
    {
        bool    bHandled = false;

        if (!m_lstTools.empty())
        {
            qToolBase   *pTool = m_lstTools.back().get();

            bHandled = ManageTool(pTool, pTool->ToolOnMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
        } // if...

        return bHandled;
    } // qToolMgr::ToolMgrOnMouseMove


    /*******************************************************************************
    * qToolMgr::ToolMgrOnMouseRelease
    *******************************************************************************/
    bool qToolMgr::ToolMgrOnMouseRelease(u32                   _u32Modifiers,
                                         u32                   _u32MouseButton,
                                         const qVector2D<s32>  &_v2dLocal,
                                         const qVector2D<s32>  &_v2dGlobal)
    {
        bool    bHandled = false;

        if (!m_lstTools.empty())
        {
            qToolBase   *pTool = m_lstTools.back().get();

            bHandled = ManageTool(pTool, pTool->ToolOnMouseRelease(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal));
        } // if...

        return bHandled;
    } // qToolMgr::ToolMgrOnMouseRelease


    /*******************************************************************************
    * qToolMgr::ToolMgrOnPaintToolMarker
    *******************************************************************************/
    void qToolMgr::ToolMgrOnPaintToolMarker()
    {
        for (unique_ptr<qToolBase> &pTool : m_lstTools)
        {
            pTool.get()->OnPaintToolMarker();
        }
    } // qToolMgr::ToolMgrOnPaintToolMarker


    /*******************************************************************************
    * qToolMgr::SendToolMsg
    *******************************************************************************/
    void qToolMgr::SendToolMsg(qToolBase *_pTool,
                               u32       _u32Msg)
    {
        OnToolMsg(_pTool, _u32Msg, 0, 0, 0, 0, 0., 0.);
    } // qToolMgr::SendToolMsg


    /*******************************************************************************
    * qToolMgr::SendToolMsg
    *******************************************************************************/
    void qToolMgr::SendToolMsg(qToolBase    *_pTool,
                               u32          _u32Msg,
                               s32          _s32Param1)
    {
        OnToolMsg(_pTool, _u32Msg, _s32Param1, 0, 0, 0, 0., 0.);
    } // qToolMgr::SendToolMsg


    /*******************************************************************************
    * qToolMgr::CancelAllTools
    *******************************************************************************/
    void qToolMgr::CancelAllTools()
    {
        while (!m_lstTools.empty())
        {
            ManageTool(m_lstTools.front().get(), enumToolResult::Canceled);
        } // while
    } // qToolMgr::AddTool


    /*******************************************************************************
    * qToolMgr::SetTool
    *******************************************************************************/
    void qToolMgr::SetTool(unique_ptr<qToolBase>_pTool)
    {
        CancelAllTools();

        m_lstTools.push_back(std::move(_pTool));

        m_lstTools.back()->OnToolActivated(true);
        m_lstTools.back()->OnSetCursor();

        OnToolStarted(m_lstTools.back().get());
    } // qToolMgr::SetTool


    /*******************************************************************************
    * qToolMgr::AddTool
    *******************************************************************************/
    void qToolMgr::AddTool(unique_ptr<qToolBase>_pTool)
    {
        m_lstTools.push_back(std::move(_pTool));

        m_lstTools.back()->OnToolActivated(true);
        m_lstTools.back()->OnSetCursor();

        OnToolStarted(m_lstTools.back().get());
    } // qToolMgr::AddTool


    /*******************************************************************************
    * qToolMgr::ActiveTool
    *******************************************************************************/
    qToolBase* qToolMgr::ActiveTool() const
    {
        if (!m_lstTools.empty())
        {
            return m_lstTools.back().get();
        }

        return nullptr;
    } // qToolMgr::ActiveTool


    /*******************************************************************************
    * qToolMgr::OnToolStarted
    *******************************************************************************/
    void qToolMgr::OnToolStarted(qToolBase */*_pTool*/)
    {
    } // qToolMgr::OnToolStarted


    /*******************************************************************************
    * qToolMgr::OnToolSuccess
    *******************************************************************************/
    void qToolMgr::OnToolSuccess(qToolBase */*_pTool*/)
    {
    } // qToolMgr::OnToolSuccess


    /*******************************************************************************
    * qToolMgr::OnToolCanceled
    *******************************************************************************/
    void qToolMgr::OnToolCanceled(qToolBase */*_pTool*/)
    {
    } // qToolMgr::OnToolCanceled


    /*******************************************************************************
    * qToolMgr::OnToolFinished
    *******************************************************************************/
    void qToolMgr::OnToolFinished(u32 /*_u32ToolId*/)
    {
    } // qToolMgr::OnToolFinished


    /*******************************************************************************
    * qToolMgr::OnToolMsg
    *******************************************************************************/
    void qToolMgr::OnToolMsg(qToolBase */*_pTool*/,
                             u32       /*_u32Msg*/,
                             s32       /*_s32Param*/,
                             u32       /*_u32Param*/,
                             s64       /*_s64Param*/,
                             u64       /*_u64Param*/,
                             flt       /*_fltParam*/,
                             dbl       /*_dblParam*/)
    {
    } // qToolMgr::OnToolMsg


    /*******************************************************************************
    * qToolMgr::ManageTool
    *******************************************************************************/
    bool qToolMgr::ManageTool(qToolBase            *_pTool,
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
                    pTool->OnToolActivated(false);

                    OnToolSuccess(pTool.get());
                    OnToolFinished(pTool->GetToolId());
                }

                bHandled = true;
                break;
            } // case enumToolResult::Done:

            case enumToolResult::Canceled:
            {
                unique_ptr<qToolBase>   pTool = m_lstTools.FindAndRemove(_pTool);

                if (pTool != nullptr)
                {
                    pTool->OnToolActivated(false);

                    OnToolCanceled(pTool.get());
                    OnToolFinished(pTool->GetToolId());
                }

                bHandled = true;
                break;
            } // case enumToolResult::Canceled:

        } // switch (_eToolResult)

        return bHandled;

    } // qToolMgr::ManageTool

} // namespace qLib
