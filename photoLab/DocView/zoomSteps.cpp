/*******************************************************************************
* \file zoomSteps.cpp
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
#include "photoLab_defs.h"
#include "zoomSteps.h"
#include "aTransform2D.h"

using namespace aLib::aMath;


/*******************************************************************************
* statics
*******************************************************************************/
aVector<dbl> ZoomSteps::m_v2dZoomSteps;     // same values for all instances


/*******************************************************************************
* ZoomSteps::ZoomSteps
*******************************************************************************/
ZoomSteps::ZoomSteps()
{
    // first call => vector is still empty
    if (m_v2dZoomSteps.empty())
    {
        // initialize the zoom steps, if not already done
        // push the values 1/PL_ZOOM_MIN ... 1/2
        for (s32 i = PL_ZOOM_MIN; i>=2; i--)
        {
            m_v2dZoomSteps.push_back(1./i);
        }

        // some factors near 1
        m_v2dZoomSteps.push_back(0.75);
        m_v2dZoomSteps.push_back(1.);
        m_v2dZoomSteps.push_back(1.5);

        // push back 2 ... PL_ZOOM_MAX
        for (s32 i = 2; i<=PL_ZOOM_MAX; i++)
        {
            m_v2dZoomSteps.push_back(i);
        }
    }
} // ZoomSteps::ZoomSteps


/*******************************************************************************
* ZoomSteps::~ZoomSteps
*******************************************************************************/
ZoomSteps::~ZoomSteps()
{
}; // ZoomSteps::~ZoomSteps


/*******************************************************************************
* ZoomSteps::zoomFactor
*******************************************************************************/
dbl ZoomSteps::zoomFactor() const
{
    return m_dZoomFactor;
} // ZoomSteps::zoomFactor


/*******************************************************************************
* ZoomSteps::zoomFactor_pml
*******************************************************************************/
s32 ZoomSteps::zoomFactor_pml() const
{
    if (m_dZoomFactor < 1)
    {
        aTransform2D<dbl, s32> t(1./PL_ZOOM_MIN, 1, 0, 500);
        return t.src2Dst(m_dZoomFactor, true);
    }
    else
    {
        aTransform2D<dbl, s32> t(1, PL_ZOOM_MAX, 500, 1000);
        return t.src2Dst(m_dZoomFactor, true);
    }
} // ZoomSteps::zoomFactor_pml


/*******************************************************************************
* ZoomSteps::setZoomFactor
*******************************************************************************/
void ZoomSteps::setZoomFactor(dbl _dZF)
{
    m_dZoomFactor = _dZF;
} // ZoomSteps::setZoomFactor


/*******************************************************************************
* ZoomSteps::setZoomFactor_pml
*******************************************************************************/
void ZoomSteps::setZoomFactor_pml(s32 _s32ZoomFactor_pml)
{
    if (_s32ZoomFactor_pml < 500)
    {
        aTransform2D<s32, dbl> t(0, 500, 1./PL_ZOOM_MIN, 1);
        setZoomFactor(t.src2Dst(_s32ZoomFactor_pml, true));
    }
    else
    {
        aTransform2D<s32, dbl> t(500, 1000, 1, PL_ZOOM_MAX);
        setZoomFactor(t.src2Dst(_s32ZoomFactor_pml, true));
    }
} // ZoomSteps::setZoomFactor_pml


/*******************************************************************************
* ZoomSteps::increaseZoomFactor
*******************************************************************************/
bool ZoomSteps::increaseZoomFactor()
{
    // search the next bigger zoomstep
    for (s32 i = 0; i < m_v2dZoomSteps.size(); i++)
    {
        if (m_v2dZoomSteps.at(i) > m_dZoomFactor)
        {
            // we found the next step
            m_dZoomFactor = m_v2dZoomSteps.at(i);
            return true;
        }
    }

    return false;
} // ZoomSteps::increaseZoomFactor


/*******************************************************************************
* ViewBase::decreaseZoomFactor
*******************************************************************************/
bool ZoomSteps::decreaseZoomFactor()
{
    //shared_ptr<qFsDoc>  pDoc	= GetFsActiveDoc();
    //CHECK_PRE_CONDITION_VOID(pDoc != nullptr);

    // iterate from 1/32 .. 32 and select the next higher zoomstep
    for (s32 i = m_v2dZoomSteps.size()-1; i >= 0; i--)
    {
        if (m_v2dZoomSteps.at(i) < m_dZoomFactor)
        {
            dbl				dblNewZF		= m_v2dZoomSteps.at(i);

            // if zoomfactor < 1 and the resulting image w/h < 10 pixel
            // => don't zoom, no pictures < 10 pixel if zoomed out
//            if (dblNewZF >= 1 || (pDoc->GetW()*dblNewZF >= MIN_ZOOM_OUT_PIXEL &&
//                                  pDoc->GetH()*dblNewZF >= MIN_ZOOM_OUT_PIXEL))
//            {
                // we found the next step which results in an image
                // with w and h > MIN_ZOOM_OUT_PIXEL if zoomed out
                m_dZoomFactor = dblNewZF;
                return true;
//            }
        }
    }

    return false;
} // ZoomSteps::decreaseZoomFactor
