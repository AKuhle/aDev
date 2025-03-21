/*******************************************************************************
* \file qSpacer.inl
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
#include "qSpacer.h"


namespace qLib
{
    /*******************************************************************************
    * qSpacer::qSpacer
    *******************************************************************************/
    qSpacer::qSpacer(qWin  *_pParent,
                     u32    _u32Id /*= SYS_ID_SPACER*/)
    : qCtrlBase(_pParent, _u32Id)
	{
    } // qSpacer::qSpacer


    /*******************************************************************************
B    * qSpacer::~qSpacer
    *******************************************************************************/
    qSpacer::~qSpacer()
	{
    } // qSpacer::~qSpacer

} // namespace qLib
