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
#include "aMainWinMdiI.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMainWinMdi
*******************************************************************************/
class aMainWinMdi : public aMainWin,
                    public aMainWinMdiI
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
    protected:
        aMdiArea*           mdiArea() override;
        aMdiArea*           mdiArea() const override;

    public:
        void                addMdiChild(aMdiChild *_pMdiChild) override;

        void                mdiChildList(aPtrList<aMdiChild> &_lstMdiChild) const override;
        aMdiChild*          activeMdiChild() const override;
        aMdiChild*          topmostMdiChild() const override;


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        virtual bool        onSysCreateWin() override;

}; // class aMainWinMdi


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
