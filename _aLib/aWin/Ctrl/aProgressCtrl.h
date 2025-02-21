/*******************************************************************************
* \file aProgressCtrl.h
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once



/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/aWin_def.h"
#include "aWin/Ctrl/aCtrl.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aProgressCtrl
*******************************************************************************/
class aProgressCtrl : public aCtrl
{
    private:
        s32         m_s32Progress_pml       { 0 };

    public:
        aProgressCtrl(aBaseWin    *_pParent,
                      u32         _u32Id = CTRL_ID_PROGRESS_CTRL);

        virtual ~aProgressCtrl();

        void        setProgress(s32     _s32Progress_pml);


    /*******************************************************************************
    * qWin interface
    *******************************************************************************/
    public:
        bool        onSysCreate() override;
        void        onPaintContent() override;

}; // class aProgressCtrl


} // namespace aWin
} // namespace aLib
