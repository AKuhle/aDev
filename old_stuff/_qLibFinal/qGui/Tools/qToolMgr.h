/*******************************************************************************
* \file qToolMgr.h
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
#include "qGuiDefs.h"
#include "qVector2D.h"
#include "qUniquePtrList.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qToolBase;


    /*******************************************************************************
    * class qToolMgr
    *******************************************************************************/
    class qToolMgr
    {
        private:
            qUniquePtrList<qToolBase>   m_lstTools;

        public:
            qToolMgr();
            virtual ~qToolMgr();

            bool            ToolMgrOnEnter(u32                   _u32Modifiers,
                                           const qVector2D<s32>  &_v2dLocal,
                                           const qVector2D<s32>  &_v2dGlobal);

            bool            ToolMgrOnLeave(u32 _u32Modifiers);

            bool            ToolMgrOnWheel(u32                  _u32Modifiers,
                                           s32                  _s32Degree,
                                           const qVector2D<s32> &_v2dLocal,
                                           const qVector2D<s32> &_v2dGlobal);

            bool            ToolMgrOnDoubleClick(u32                   _u32Modifiers,
                                                 u32                   _u32MouseButton,
                                                 const qVector2D<s32>  &_v2dLocal,
                                                 const qVector2D<s32>  &_v2dGlobal);

            bool            ToolMgrOnMousePress(u32                   _u32Modifiers,
                                                u32                   _u32MouseButton,
                                                const qVector2D<s32>  &_v2dLocal,
                                                const qVector2D<s32>  &_v2dGlobal);

            bool            ToolMgrOnMouseMove(u32                   _u32Modifiers,
                                               u32                   _u32MouseButton,
                                               const qVector2D<s32>  &_v2dLocal,
                                               const qVector2D<s32>  &_v2dGlobal);

            bool            ToolMgrOnMouseRelease(u32                   _u32Modifiers,
                                                  u32                   _u32MouseButton,
                                                  const qVector2D<s32>  &_v2dLocal,
                                                  const qVector2D<s32>  &_v2dGlobal);

            void            ToolMgrOnPaintToolMarker();

            virtual void    SendToolMsg(qToolBase   *_pTool,
                                        u32         _u32Msg);

            virtual void    SendToolMsg(qToolBase   *_pTool,
                                        u32         _u32Msg,
                                        s32         _s32Param1);

        public:
            void            CancelAllTools();
            void            SetTool(unique_ptr<qToolBase>_pTool);
            void            AddTool(unique_ptr<qToolBase>_pTool);

            qToolBase*      ActiveTool() const;

        // handler
        protected:
            virtual void    OnToolStarted(qToolBase *_pTool);
            virtual void    OnToolSuccess(qToolBase *_pTool);
            virtual void    OnToolCanceled(qToolBase *_pTool);
            virtual void    OnToolFinished(u32 _u32ToolId);

            virtual void    OnToolMsg(qToolBase *_pTool,
                                      u32       _u32Msg,
                                      s32       _s32Param,
                                      u32       _u32Param,
                                      s64       _s64Param,
                                      u64       _u64Param,
                                      flt       _fltParam,
                                      dbl       _dblParam);


        private:
            bool            ManageTool(qToolBase            *_pTool,
                                       enumToolResult   _eToolResult);
    }; // class qToolMgr

} // namespace qLib
