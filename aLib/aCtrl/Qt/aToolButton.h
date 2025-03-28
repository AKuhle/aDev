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
#include <QToolButton>
#include "aCtrl.h"
#include "aToolButtonI.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aToolButton
*******************************************************************************/
class aToolButton : public aCtrl<QToolButton>,
                    public aToolButton_i
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aToolButton(SysWin *_pParent);

    public:
        virtual ~aToolButton();

}; // class aToolButton


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
