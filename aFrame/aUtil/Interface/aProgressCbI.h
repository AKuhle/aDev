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
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include <QObject>

#include "aFrame_def.h"

#include "aString.h"

using namespace aFrame;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aProgressCbI
*******************************************************************************/
class aProgressCbI
{
    public:
        // interface for derived classes
        virtual void		onOpenProgressDisplay() = 0;
        virtual void		onCloseProgressDisplay() = 0;
        virtual void		onUpdateProgressDisplay(const aString &_sInfoText) = 0;
        virtual void		onUpdateProgressDisplay(u16 _u16Progress_pml) = 0;

}; // class aProgressCbI


} // namespace aUtil
} // namespace aFrame
