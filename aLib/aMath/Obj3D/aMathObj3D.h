/*******************************************************************************
* \file qMathObjBase3D.h
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
namespace aLib {
namespace aMath {


/*******************************************************************************
* \class aMathObj3D
* \brief baseclass for 3D math objects
*******************************************************************************/
class aMathObj3D : public aMathObj
{
    protected:
        aMathObj3D();

    public:
        virtual ~aMathObj3D();
}; // class aMathObj3D


} // namespace aMath
} // namespace aLib
