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
#include "aWin/Framework/aMainWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMdiMainWin
*******************************************************************************/
class aMdiMainWin : public aMainWin
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aMdiMainWin(aMdiMainWin *_pParent = nullptr);
        ~aMdiMainWin();

        aMdiArea*                   mdiArea() const;

        void                        addMdiWin(aMdiWin *_pMdiWin);

    public:
        aMdiWin*                    activeMdiWin() const;

        const aPtrList<aMdiWin>*    mdiWinList() const;

    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        virtual bool                onSysCreate();

}; // class aMdiMainWin


} // namespace aWin
} // namespace aLib
