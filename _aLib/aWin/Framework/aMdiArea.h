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

#include "aUtil/Collection/aPtrList.h"

#include "aWin/Framework/aBaseWin.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMdiArea
*******************************************************************************/
class aMdiArea : public aBaseWin
{
    friend class aMdiWin;

    private:
        aPtrList<aMdiWin>       m_lstMdiWin;

    public:
        aMdiArea(aBaseWin *_pParent = nullptr);
        ~aMdiArea();

        void                        addMdChild(aMdiWin *_pMdiWin);

        aMdiWin*                    activeMdiWin() const;

        const aPtrList<aMdiWin>&    mdiWinList() const;


    /*******************************************************************************
    * private methods for aMdiWin
    *******************************************************************************/
    private:
        void                        mdiChildRaised(aMdiWin *_pMdiWin);
}; // class aMdiArea


} // namespace aWin
} // namespace aLib
