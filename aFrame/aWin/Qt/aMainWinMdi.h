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
#include "aMainWinMdi_i.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aMainWinMdi
*******************************************************************************/
class aMainWinMdi : public aMainWinMdi_i
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMainWinMdi(SysWin *_pParent = nullptr);
        ~aMainWinMdi();


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
    protected:
        virtual bool        onSysCreateWin() override;

}; // class aMainWinMdi


} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_
