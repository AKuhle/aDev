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
* class aMdiWin
*******************************************************************************/
class aMdiWin : public aCentralWin
{
    private:
        aTitleBar   *m_pTitleBar    { nullptr };

    public:
        aMdiWin(aBaseWin *_pParent = nullptr);
        ~aMdiWin();

        aMdiArea*                   mdiArea();

    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        virtual bool                onSysCreate();

        virtual void                onFocusIn(enumFocusReason  _eReason);
        virtual void                onFocusOut(enumFocusReason  _eReason);

}; // class aMdiWin


} // namespace aWin
} // namespace aLib
