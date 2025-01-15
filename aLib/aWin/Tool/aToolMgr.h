/*******************************************************************************
* \file aToolMgr.h
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
#include "aLib_def.h"
#include "aMath/aMath_def.h"
#include "aWin/aWin_def.h"

#include "aUtil/Collection/aUniquePtrList.h"

#include "aWin/Tool/aToolBase.h"

using namespace std;
using namespace aLib::aMath;
using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aToolMgr
*******************************************************************************/
class aToolMgr
{
    private:
        aUniquePtrList<aToolBase>   m_lstTools;

    public:
        aToolMgr();
        virtual ~aToolMgr();

        bool            doToolMgrEnter(u32                   _u32Modifiers,
                                       const aVector2D<s32>  &_v2dLocal,
                                       const aVector2D<s32>  &_v2dGlobal);

        bool            doToolMgrLeave(u32 _u32Modifiers);

        bool            doToolMgrWheel(u32                  _u32Modifiers,
                                       s32                  _s32Degree,
                                       const aVector2D<s32> &_v2dLocal,
                                       const aVector2D<s32> &_v2dGlobal);

        bool            doToolMgrDoubleClick(u32                   _u32Modifiers,
                                             u32                   _u32MouseButton,
                                             const aVector2D<s32>  &_v2dLocal,
                                             const aVector2D<s32>  &_v2dGlobal);

        bool            doToolMgrMousePress(u32                   _u32Modifiers,
                                            u32                   _u32MouseButton,
                                            const aVector2D<s32>  &_v2dLocal,
                                            const aVector2D<s32>  &_v2dGlobal);

        bool            doToolMgrMouseMove(u32                   _u32Modifiers,
                                           u32                   _u32MouseButton,
                                           const aVector2D<s32>  &_v2dLocal,
                                           const aVector2D<s32>  &_v2dGlobal);

        bool            doToolMgrMouseRelease(u32                   _u32Modifiers,
                                              u32                   _u32MouseButton,
                                              const aVector2D<s32>  &_v2dLocal,
                                              const aVector2D<s32>  &_v2dGlobal);

        // void            paintToolMarker();

        // virtual void    sendToolMsg(aToolBase   *_pTool,
        //                             u32         _u32Msg);

        // virtual void    sendToolMsg(aToolBase   *_pTool,
        //                             u32         _u32Msg,
        //                             s32         _s32Param1);

    public:
        void            cancelAllTools();
        void            setTool(unique_ptr<aToolBase>_pTool);
        void            addTool(unique_ptr<aToolBase>_pTool);

        // aToolBase*      activeTool() const;

    // handler
    protected:
        virtual void    onToolStarted(aToolBase *_pTool);
        virtual void    onToolSuccess(aToolBase *_pTool);
        virtual void    onToolCanceled(aToolBase *_pTool);
        virtual void    onToolFinished(u32 _u32ToolId);

    //     virtual void    onToolMsg(aToolBase *_pTool,
    //                               u32       _u32Msg,
    //                               s32       _s32Param,
    //                               u32       _u32Param,
    //                               s64       _s64Param,
    //                               u64       _u64Param,
    //                               flt       _fltParam,
    //                               dbl       _dblParam);


    private:
        bool            manageTool(aToolBase            *_pTool,
                                   enumToolResult   _eToolResult);
}; // class aToolMgr


} // namespace aWin
} // namespace aLib
