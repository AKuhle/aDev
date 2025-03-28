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
#include "aScrollWin_sys.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aScrollWin
*******************************************************************************/
class aScrollWin : public aScrollWin_sys
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aScrollWin(SysWinClass *_pParent = nullptr);
        ~aScrollWin();

        // central win
        void                setCentralWin(SysWinClass *_pWin);
        SysWinClass*        centralWin();

        // policy
        void                setScrollBarPolicy(ScrollBarPolicy _Ppolicy);       // for both scrollbars
        void                setHoriScrollBarPolicy(ScrollBarPolicy _policy);
        void                setVertScrollBarPolicy(ScrollBarPolicy _policy);

}; // class aScrollWin


} // namespace aWin
} // namespace aLib
