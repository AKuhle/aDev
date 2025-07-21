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
#include "aMainWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aMainWinMdi_i
*******************************************************************************/
class aMainWinMdi_i : public aMainWin
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMainWinMdi_i(SysWin *_pParent = nullptr);
        ~aMainWinMdi_i();


    /*******************************************************************************
    * aMainWinI interface
    *******************************************************************************/
    // protected:
    //     aMdiArea*           mdiArea() override;
    //     aMdiArea*           mdiArea() const override;

    // public:
    //     void                addMdiChild(aMdiChild *_pMdiChild) override;

    //     void                mdiChildList(aPtrList<aMdiChild> &_lstMdiChild) const override;
    //     aMdiChild*          activeMdiChild() const override;
    //     aMdiChild*          topmostMdiChild() const override;


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    // protected:
    //     virtual bool        onSysCreateWin() override;

}; // class aMainWinMdi_i


} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_
