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
#include "qLib.h"

using namespace qLib;



/*******************************************************************************
* class ZoomSteps
*******************************************************************************/
class ZoomSteps
{
    private:
        static qVec<dbl>    m_v2dZoomSteps;     // same values for all instances
        dbl                 m_dZoomFactor       { 1. };

    public:
        ZoomSteps();
        virtual ~ZoomSteps();

        dbl                 ZoomFactor() const;
        s32                 ZoomFactor_pml() const;
        void                SetZoomFactor(dbl _dZF);
        void                SetZoomFactor_pml(s32 _s32ZF_pml);

        void                IncreaseZoomFactor();
        void                DecreaseZoomFactor();

}; // class ZoomSteps
