/*******************************************************************************
* \file qBaseDefs.h
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
#include "aProgressCb.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aProgressCb::slotOpenProgressDisplay
*******************************************************************************/
void aProgressCb::slotOpenProgressDisplay()
{
    onOpenProgressDisplay();
} // aProgressCb::slotOpenProgressDisplay


/*******************************************************************************
* aProgressCb::slotCloseProgressDisplay
*******************************************************************************/
void aProgressCb::slotCloseProgressDisplay()
{
    onCloseProgressDisplay();
} // aProgressCb::slotCloseProgressDisplay


/*******************************************************************************
* aProgressCb::slotUpdateProgressDisplay
*******************************************************************************/
void aProgressCb::slotUpdateProgressDisplay(const QString &_sInfoText)
{
    onUpdateProgressDisplay(aString::fromQString(_sInfoText));
} // aProgressCb::slotUpdateProgressDisplay


/*******************************************************************************
* aProgressCb::slotUpdateProgressDisplay
*******************************************************************************/
void aProgressCb::slotUpdateProgressDisplay(u16 _u16Progress_pml)
{
    onUpdateProgressDisplay(_u16Progress_pml);
} // aProgressCb::slotUpdateProgressDisplay



} // namespace aUtil
} // namespace aLib

