/*******************************************************************************
* \file aHoriSpacer.inl
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
#include "aHoriSpacer.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aHoriSpacer::aHoriSpacer
*******************************************************************************/
aHoriSpacer::aHoriSpacer(aBaseWin  *_pParent,
                         u32    _u32Id /*= CTRL_ID_HORI_SPACER*/)
: aCtrl(_pParent, _u32Id)
{
    setMinDim(0, 0);
    setMaxDim(S32_MAX, 0);
} // aHoriSpacer::aHoriSpacer


/*******************************************************************************
* aHoriSpacer::~aHoriSpacer
*******************************************************************************/
aHoriSpacer::~aHoriSpacer()
{
} // aHoriSpacer::~aHoriSpacer


} // namespace aWin
} // namespace aLib
