/*******************************************************************************
* \file aCtrl.h
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

#include "aWin/Framework/aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aCtrl
*******************************************************************************/
class aCtrl : public aBaseWin
{
    private:
        u32         m_u32CtrlId     { 0 };
        aCtrlMgr    *m_pCtrlMgr     { nullptr };


    public:
        aCtrl(aBaseWin  *_pParent,
                  u32       _u32Id);
        virtual ~aCtrl();

        void                setCtrlMgr(aCtrlMgr *_pCtrlMgr);
        aCtrlMgr*           ctrlMgr() const;

        void                setCtrlMgr(u32 *_u32CtrlId);
        u32*                ctrlId() const;
}; // class aCtrl


} // namespace aWin
} // namespace aLib
