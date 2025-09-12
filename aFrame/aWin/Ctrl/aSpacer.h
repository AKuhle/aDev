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
#include "aString.h"
#include "aCtrl.h"
#include "aToolMgr.h"
#include "aVector.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aSpacer
*******************************************************************************/
class aSpacer : public aCtrl
{
    public:
        aSpacer(aBaseWin        *_pParent);
        virtual ~aSpacer();


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    // protected:
    //     virtual bool        onSysCreateWin() override;

}; // class aSpacer


} // namespace aWin
} // namespace aFrame
