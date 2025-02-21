/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/aWin_def.h"

#include "aWin/Framework/aCentralWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aScrollWin
*******************************************************************************/
class aScrollWin : public aCentralWin
{
    private:
        aScrollBar  *m_pHoriSb      { nullptr };
        aScrollBar  *m_pVertSb      { nullptr };


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aScrollWin(aBaseWin *_pParent = nullptr);
        ~aScrollWin();


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        virtual bool                onSysCreate();
        //virtual aRect2D<s32>        contentRect() const;    // take dockareas into account

}; // class aScrollWin


} // namespace aWin
} // namespace aLib
