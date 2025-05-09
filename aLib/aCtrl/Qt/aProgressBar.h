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
#include <QProgressBar>
#include "aCtrl.h"
#include "aProgressBarI.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aProgressBar
*******************************************************************************/
class aProgressBar : public aCtrl<QProgressBar>,
                     public aProgressBarI
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aProgressBar(SysWin *_pParent);
        virtual ~aProgressBar();


    /*******************************************************************************
    * aProgressBar interface
    *******************************************************************************/
    public:
        void            setInfo(const aString &_sInfo) override;

        void            setRange(s32    _s32Min,
                                 s32    _s32Max) override;

        void            setValue(s32 s32Value) override;

        void            reset() override;

}; // class aProgressBar


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
