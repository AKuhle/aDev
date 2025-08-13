/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"
#include "aUtil_def.h"
#include "aWin_def.h"

#include "aUniquePtrVec.h"

using namespace aFrame;
using namespace aFrame::aUtil;
using namespace aFrame::aWin;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aToolMgr
*******************************************************************************/
class aToolMgr
{
    private:
        aUniquePtrVec<aToolBase>    m_vTools;


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aToolMgr();


    public:
        ~aToolMgr();

        void                addTool(std::unique_ptr<aToolBase>  _pTool);


        // double click
        bool                onToolMgrDoubleClick(u16            _u16Modifier,
                                                 u16            _u16Btn,
                                                 const aPoint   &_pntLocal,
                                                 const aPoint   &_pntGlobal);

        // mouse pressed events, true => event handled
        virtual bool        onToolMgrButtonPress(u16            _u16Modifier,
                                                 u16            _u16Btn,
                                                 const aPoint   &_pntLocal,
                                                 const aPoint   &_pntGlobal);

        // mouse move events, true => event handled
        // separate handler for moves without/multiple buttons
        virtual bool        onToolMgrMouseMove(u16          _u16Modifier,
                                               u16          _u16Btn,
                                               const aPoint &_pntLocal,
                                               const aPoint &_pntGlobal);

        // mouse release events, true => event handled
        virtual bool        onToolMgrButtonRelease(u16          _u16Modifier,
                                                   u16          _u16Btn,
                                                   const aPoint &_pntLocal,
                                                   const aPoint &_pntGlobal);


    private:
        void                manage(std::unique_ptr<aToolBase>   &_pTool,
                                   enumToolResult               _eResult);
}; // class aToolMgr


} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_
