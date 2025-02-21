/*******************************************************************************
* \file qLayoutObj.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLayoutObj.h"

using namespace std;


namespace qLib
{
    /*******************************************************************************
    * qLayoutObj::qLayoutObj
    *******************************************************************************/
    flt qLayoutObj::m_minScale  { 1.0 };


    /*******************************************************************************
    * qLayoutObj::qLayoutObj
    *******************************************************************************/
    qLayoutObj::qLayoutObj()
	{
    } // qLayoutObj::qLayoutObj


    /*******************************************************************************
    * qLayoutObj::~qLayoutObj
    *******************************************************************************/
    qLayoutObj::~qLayoutObj()
    {
    } // qLayoutObj::~qLayoutObj


    /*******************************************************************************
    * qLayoutObj::SetMinScale
    *******************************************************************************/
    void qLayoutObj::SetMinScale(flt _minScale)
    {
        m_minScale = _minScale;
    } // qLayoutObj::SetMinScale


    /*******************************************************************************
    * qLayoutObj::GetMinSize
    *******************************************************************************/
    qDimension2D<s32> qLayoutObj::GetMinSize() const
    {
        return m_d2dMinSize;
    } // qLayoutObj::GetMinSize


    /*******************************************************************************
    * qLayoutObj::SetMinSize
    *******************************************************************************/
    void qLayoutObj::SetMinSize(const qDimension2D<s32>  &_minSize)
    {
        SetMinSize(_minSize.w, _minSize.h);
    } // qLayoutObj::SetMinSize


    /*******************************************************************************
    * qLayoutObj::SetMinSize
    *******************************************************************************/
    void qLayoutObj::SetMinSize(s32 _minW,
                          s32 _minH)
    {
        m_d2dMinSize.Set(m_minScale * _minW,
                         m_minScale * _minH);
    } // qLayoutObj::SetMinSize


    /*******************************************************************************
    * qLayoutObj::SetMinW
    *******************************************************************************/
    void qLayoutObj::SetMinW(s32 _minW)
    {
        m_d2dMinSize.w = m_minScale * _minW;
    } // qLayoutObj::SetMinW


    /*******************************************************************************
    * qLayoutObj::SetMinH
    *******************************************************************************/
    void qLayoutObj::SetMinH(s32 _minH)
    {
        m_d2dMinSize.h = m_minScale * _minH;
    } // qLayoutObj::SetMinH


    /*******************************************************************************
    * qLayoutObj::ArangeChilds
    *******************************************************************************/
    void qLayoutObj::ArangeChilds(const qRect2D<s32> &/*_parentRect*/)
    {
    } // qLayoutObj::ArangeChilds

} // namespace qLib
