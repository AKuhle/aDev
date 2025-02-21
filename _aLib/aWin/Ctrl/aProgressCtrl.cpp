/*******************************************************************************
* \file aProgressCtrl.inl
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


/*******************************************************************************
* includes
*******************************************************************************/
#include "aProgressCtrl.h"
#include "aGraphic/aPainter.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aProgressCtrl::aProgressCtrl
*******************************************************************************/
aProgressCtrl::aProgressCtrl(aBaseWin   *_pParent,
                             u32        _u32Id /*= CTRL_ID_PROGRESS_CTRL*/)
: aCtrl(_pParent, _u32Id)
{
    setMinDim(0, 0);
    setMaxDim(S32_MAX, 0);
} // aProgressCtrl::aProgressCtrl


/*******************************************************************************
* aProgressCtrl::~aProgressCtrl
*******************************************************************************/
aProgressCtrl::~aProgressCtrl()
{
} // aProgressCtrl::~aProgressCtrl


/*******************************************************************************
* aProgressCtrl::setProgress
*******************************************************************************/
void aProgressCtrl::setProgress(s32     _s32Progress_pml)
{
    m_s32Progress_pml = _s32Progress_pml;

    cout << _s32Progress_pml << endl;

    // repaint
    update();
} // aProgressCtrl::~setProgress


/*******************************************************************************
* aProgressCtrl::onSysCreate
*******************************************************************************/
bool aProgressCtrl::onSysCreate()
{
    return true;
} // aProgressCtrl::~onSysCreate


/*******************************************************************************
* aProgressCtrl::onPaintContent
*******************************************************************************/
void aProgressCtrl::onPaintContent()
{
    aRect2D<s32>    r = contentRect();
    aPainter        p(this);

    r.w() = ((dbl) m_s32Progress_pml) / 1000. * r.w();

    p.drawFilledRect(r, &activeColor());
} // aProgressCtrl::~onPaintContent


} // namespace aWin
} // namespace aLib
