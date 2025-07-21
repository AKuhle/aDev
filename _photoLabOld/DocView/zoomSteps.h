/*******************************************************************************
* \file zoomSteps.h
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
#include "aLib_def.h"
#include "aVector.h"

using namespace aLib;
using namespace aLib::aUtil;



/*******************************************************************************
* class ZoomSteps
*******************************************************************************/
class ZoomSteps
{
    private:
        static aVector<dbl> m_v2dZoomSteps;     // same values for all instances
        dbl                 m_dZoomFactor       { 1. };

    public:
        ZoomSteps();
        virtual ~ZoomSteps();

        dbl                 zoomFactor() const;
        s32                 zoomFactor_pml() const;
        void                setZoomFactor(dbl _dZF);
        void                setZoomFactor_pml(s32 _s32ZF_pml);

        bool                increaseZoomFactor();   // true => zoom factor changed
        bool                decreaseZoomFactor();   // true => zoom factor changed

}; // class ZoomSteps
