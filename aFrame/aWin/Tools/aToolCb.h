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

using namespace std;
using namespace aFrame;
using namespace aFrame::aUtil;
using namespace aFrame::aWin;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aToolCb
*******************************************************************************/
class aToolCb
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aToolCb();

    public:
        ~aToolCb();

        virtual void        onToolStart(aToolBase   *_pTool);
        virtual void        onToolSuccess(aToolBase   *_pTool);
        virtual void        onToolCanceled(aToolBase   *_pTool);
        virtual void        onToolFinished(aToolBase   *_pTool);
}; // class aToolCb


} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_
