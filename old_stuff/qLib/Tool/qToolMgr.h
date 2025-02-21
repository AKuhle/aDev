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
#include "qLibDefs.h"
#include "Tool/toolDefs.h"
#include "Collection/qUniquePtrList.h"
#include "Math/qVector2D.h"

using namespace qLib::Math;
using namespace qLib::Collection;
using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Tool {


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

        bool            doEnter(u32                   _u32Modifiers,
                                const qVector2D<s32>  &_v2dLocal,
                                const qVector2D<s32>  &_v2dGlobal);

        bool            doLeave(u32 _u32Modifiers);

        bool            doWheel(u32                  _u32Modifiers,
                                s32                  _s32Degree,
                                const qVector2D<s32> &_v2dLocal,
                                const qVector2D<s32> &_v2dGlobal);

        bool            doDoubleClick(u32                   _u32Modifiers,
                                      u32                   _u32MouseButton,
                                      const qVector2D<s32>  &_v2dLocal,
                                      const qVector2D<s32>  &_v2dGlobal);

        bool            doMousePress(u32                   _u32Modifiers,
                                     u32                   _u32MouseButton,
                                     const qVector2D<s32>  &_v2dLocal,
                                     const qVector2D<s32>  &_v2dGlobal);

        bool            doMouseMove(u32                   _u32Modifiers,
                                    u32                   _u32MouseButton,
                                    const qVector2D<s32>  &_v2dLocal,
                                    const qVector2D<s32>  &_v2dGlobal);

        bool            doMouseRelease(u32                   _u32Modifiers,
                                       u32                   _u32MouseButton,
                                       const qVector2D<s32>  &_v2dLocal,
                                       const qVector2D<s32>  &_v2dGlobal);

        void            paintToolMarker();

        virtual void    sendToolMsg(qToolBase   *_pTool,
                                    u32         _u32Msg);

        virtual void    sendToolMsg(qToolBase   *_pTool,
                                    u32         _u32Msg,
                                    s32         _s32Param1);

    public:
        void            cancelAllTools();
        void            setTool(unique_ptr<qToolBase>_pTool);
        void            addTool(unique_ptr<qToolBase>_pTool);

        qToolBase*      activeTool() const;

    // handler
    protected:
        virtual void    onToolStarted(qToolBase *_pTool);
        virtual void    onToolSuccess(qToolBase *_pTool);
        virtual void    onToolCanceled(qToolBase *_pTool);
        virtual void    onToolFinished(u32 _u32ToolId);

        virtual void    onToolMsg(qToolBase *_pTool,
                                  u32       _u32Msg,
                                  s32       _s32Param,
                                  u32       _u32Param,
                                  s64       _s64Param,
                                  u64       _u64Param,
                                  flt       _fltParam,
                                  dbl       _dblParam);


    private:
        bool            manageTool(qToolBase            *_pTool,
                                   enumToolResult   _eToolResult);
}; // class qToolMgr


} // namespace Tool
} // namespace qLib
