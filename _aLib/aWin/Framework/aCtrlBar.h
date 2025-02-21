/*******************************************************************************
* \file aCtrlBar.h
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
#include "aLib_def.h"
#include "aWin/aWin_def.h"

#include "aWin/Framework/aBaseWin.h"
#include "aWin/Framework/aPosition_i.h"
#include "aWin/Ctrl/aCtrlMgr.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aCtrlBar
*******************************************************************************/
class aCtrlBar : public aBaseWin,
                 public aCtrlMgr,
                 public aPositionI
{
    public:
        aCtrlBar(aBaseWin       *_pParent   = nullptr);
        ~aCtrlBar();

    protected:
        aLayoutHoriVert*    layoutHoriVert() const;

    private:
        void                setStyle();


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        void                onPositionChanged(enumPosition _eNewPosition) override;


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        bool                onSysCreate() override;
};


} // namespace aWin
} // namespace aLib
