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
#include "aWin_def.h"
#include "aUtil/aUrl.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aScrollWinI
*******************************************************************************/
class aScrollWinI
{
    public:
        virtual ~aScrollWinI() = default;

    protected:
        virtual void            setCentralWin(SysWin *_pWin) = 0;
        virtual SysWin*         centralWin() = 0;

        // policy
        virtual void            setScrollBarPolicy(ScrollBarPolicy _Ppolicy) = 0;   // for both scrollbars
        virtual void            setHoriScrollBarPolicy(ScrollBarPolicy _policy) = 0;
        virtual void            setVertScrollBarPolicy(ScrollBarPolicy _policy) = 0;

}; // class aScrollWinI


} // namespace aWin
} // namespace aLib
