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
* class aToolManager
*******************************************************************************/
class aToolManager
{
    private:
        aUniquePtrVec<aToolBase>    m_vTools;


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aToolManager();


    public:
        ~aToolManager();

        void            addTool(std::unique_ptr<aToolBase>  _pTool);


        // double click
        virtual bool    onToolManagerLDoubleClick(u16          _u16Modifier,
                                                  const aPoint &_pntLocal,
                                                  const aPoint &_pntGlobal);

        virtual bool    onToolManagerMDoubleClick(u16          _u16Modifier,
                                                  const aPoint &_pntLocal,
                                                  const aPoint &_pntGlobal);

        virtual bool    onToolManagerRDoubleClick(u16          _u16Modifier,
                                                  const aPoint &_pntLocal,
                                                  const aPoint &_pntGlobal);
}; // class aToolManager


} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_
