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
#include <QMdiArea>

#include "aWin_def.h"
#include "aMdiAreaI.h"
#include "aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aMdiArea
*******************************************************************************/
class aMdiArea : public aBaseWin<QMdiArea>,
                 public aMdiAreaI
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aMdiArea(SysWin *_pParent = nullptr);
        ~aMdiArea();


    /*******************************************************************************
    * aMdiAreai interface
    *******************************************************************************/
    public:
        void            addMdiChild(aMdiChild *_pMdiChild) override;

        void            mdiChildList(aPtrList<aMdiChild> &_lstMdiChild) const override;
        aMdiChild*      activeMdiChild() const override;
        aMdiChild*      topmostMdiChild() const override;

}; // class aMdiArea


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
