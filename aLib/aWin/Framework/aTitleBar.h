/*******************************************************************************
* \file aTitleBar.h
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
#include "aWin/Framework/aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aTitleBar
*******************************************************************************/
class aTitleBar : public aBaseWin
{
    public:
        aTitleBar(aBaseWin *_pParent = nullptr);
        ~aTitleBar();


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        virtual bool                onSysCreate();
};


} // namespace aWin
} // namespace aLib