/*******************************************************************************
* \file aMathObj2D.h
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
#include "aMathObj.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aMath {


/*******************************************************************************
* \class aMathObj2D
* \brief baseclass for 2D math objects
*******************************************************************************/
class aMathObj2D : public aMathObj
{
    protected:
        aMathObj2D();

    public:
        virtual ~aMathObj2D();
}; // class aMathObj2D


} // namespace aMath
} // namespace aFrame
