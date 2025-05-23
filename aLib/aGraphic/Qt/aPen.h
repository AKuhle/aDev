/*******************************************************************************
* \file aPen.h
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
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include <QPen>

#include "aWin_def.h"
#include "aPeni.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {


/*******************************************************************************
* class aPen
*******************************************************************************/
class aPen : private QPen,
             public aPenI
{
    public:
        aPen();
        virtual ~aPen();
}; // aPen


} // namespace aGraphic
} // namespace aLib

#endif // _USE_QT_
