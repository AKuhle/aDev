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
#include "aFrame_def.h"
#include "aUtil_def.h"
#include "aMath_def.h"

#include "aUniquePtrList.h"

using namespace std;
using namespace aFrame::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


class aToolMgr
{
    private:
        aUniquePtrList<aToolBase>   m_lstTools;

    public:
        aToolMgr();
        virtual ~aToolMgr();

    public:
        void            cancelAllTools();
        void            setTool(unique_ptr<aToolBase>_pTool);
        void            addTool(unique_ptr<aToolBase>_pTool);

        aToolBase*      ActiveTool() const;

        bool            toolMgrOnWheel(u32                  _u32Modifiers,
                                       s32                  _s32Degree,
                                       const aPoint2D<s32> &_v2dLocal,
                                       const aPoint2D<s32> &_v2dGlobal);

    // handler
    protected:
        virtual void    onToolStarted(aToolBase *_pTool) = 0;
        virtual void    onToolSuccess(aToolBase *_pTool) = 0;
        virtual void    onToolCanceled(aToolBase *_pTool) = 0;
        virtual void    onToolFinished(u32 _u32ToolId) = 0;


    /*******************************************************************************
    * messages
    *******************************************************************************/
    protected:
        virtual void    onToolMsg(aToolBase *_pTool,
                                  u32       _u32Msg,
                                  s32       _s32Param,
                                  u32       _u32Param,
                                  s64       _s64Param,
                                  u64       _u64Param,
                                  flt       _fltParam,
                                  dbl       _dblParam) = 0;

        void            sendToolMsg(aToolBase   *_pTool,
                                    u32         _u32Msg);

        void            sendToolMsg(aToolBase   *_pTool,
                                    u32         _u32Msg,
                                    s32         _s32Param1);


    /*******************************************************************************
    * private stuff
    *******************************************************************************/
    private:
        bool            manageTool(aToolBase        *_pTool,
                                   enumToolResult   _eToolResult);
}; // class aToolMgr


} // namespace aUtil
} // namespace aFrame


// /*******************************************************************************
// * class aToolMgr
// *******************************************************************************/
// class aToolMgr
// {
//     private:
//         qUniquePtrList<aToolBase>   m_lstTools;

//     public:
//         bool            ToolMgrOnEnter(u32                   _u32Modifiers,
//                                        const aPoint2D<s32>  &_v2dLocal,
//                                        const aPoint2D<s32>  &_v2dGlobal);

//         bool            ToolMgrOnLeave(u32 _u32Modifiers);

//         bool            ToolMgrOnDoubleClick(u32                   _u32Modifiers,
//                                              u32                   _u32MouseButton,
//                                              const aPoint2D<s32>  &_v2dLocal,
//                                              const aPoint2D<s32>  &_v2dGlobal);

//         bool            ToolMgrOnMousePress(u32                   _u32Modifiers,
//                                             u32                   _u32MouseButton,
//                                             const aPoint2D<s32>  &_v2dLocal,
//                                             const aPoint2D<s32>  &_v2dGlobal);

//         bool            ToolMgrOnMouseMove(u32                   _u32Modifiers,
//                                            u32                   _u32MouseButton,
//                                            const aPoint2D<s32>  &_v2dLocal,
//                                            const aPoint2D<s32>  &_v2dGlobal);

//         bool            ToolMgrOnMouseRelease(u32                   _u32Modifiers,
//                                               u32                   _u32MouseButton,
//                                               const aPoint2D<s32>  &_v2dLocal,
//                                               const aPoint2D<s32>  &_v2dGlobal);

//         void            ToolMgrOnPaintToolMarker();


// }; // class aToolMgr
