/*******************************************************************************
* \file aUrl_sysi.h
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
#include "aUtil_def.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aUrl_sysi
*******************************************************************************/
class aUrl_sysi
{
    protected:
        virtual bool        _isLocalFile() const = 0;
        virtual aString     _toLocalFile() const = 0;

}; // class aUrl_sysi


} // namespace aUtil
} // namespace aFrame
