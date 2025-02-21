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


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMainWin_sysi
*******************************************************************************/
class aMainWin_sysi
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMainWin_sysi()             = default;

    public:
        virtual ~aMainWin_sysi()   = default;

    protected:
        virtual void        _setCentralWin(SysWinClass *_pWin) = 0;

}; // class aMainWin_sysi


} // namespace aWin
} // namespace aLib
