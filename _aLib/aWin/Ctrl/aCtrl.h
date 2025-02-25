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
#include "aUtil/aColor.h"

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
        u32         m_u32Id     { 0 };
        aCtrlMgr    *m_pCtrlMgr     { nullptr };

        aColor      m_colHover;
        aColor      m_colDisabled;
        aColor      m_colNormal;


    public:
        aCtrl(aBaseWin  *_pParent,
              u32       _u32Id);
        virtual ~aCtrl();

        void                setCtrlMgr(aCtrlMgr *_pCtrlMgr);
        aCtrlMgr*           ctrlMgr() const;

        void                setId(u32 _u32Id);
        u32                 id() const;

        void                setHoverColor(const aColor  &_color);
        const aColor&       hoverColor() const;

        void                setDisabledColor(const aColor  &_color);
        const aColor&       disabledColor() const;

        void                setNormalColor(const aColor  &_color);
        const aColor&       normalColor() const;


    protected:
        virtual aColor      stateColor() const;

}; // class aCtrl


} // namespace aWin
} // namespace aLib
