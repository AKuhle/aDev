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
#include "Math/qMathObj.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Math {


/*******************************************************************************
* \class qMathObj3D
* \brief baseclass for 3D math objects
*******************************************************************************/
class qMathObj3D : public qMathObj
{
    protected:
        qMathObj3D();

    public:
        virtual ~qMathObj3D();
}; // class qMathObj3D


} // namespace Math
} // namespace qLib
