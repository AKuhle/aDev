/*******************************************************************************
* \file layer_I.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLayerBase.h"


namespace qLib
{
    /*******************************************************************************
    * statics
    *******************************************************************************/
    u32		qLayerBase::m_u32NextId  { 0 };


    /*******************************************************************************
    * qLayerBase::qLayerBase
    *******************************************************************************/
    qLayerBase::qLayerBase(enumLayerType        _eType,
                           const qRect2D<s32>	&_rct)
    : m_u32Id(++m_u32NextId),
        m_eType(_eType),
      m_rctGeometry(_rct)
    {
    } // qLayerBase::qLayerBase


    /*******************************************************************************
    * qLayerBase::~qLayerBase
    *******************************************************************************/
    qLayerBase::~qLayerBase()
	{
    } // qLayerBase::~qLayerBase


    /*******************************************************************************
    * qLayerBase::GetId
    *******************************************************************************/
    u32 qLayerBase::GetId() const
    {
        return m_u32Id;
    } // qLayerBase::GetId


    /*******************************************************************************
    * qLayerBase::GetGeometry
    *******************************************************************************/
    const qRect2D<s32>& qLayerBase::GetGeometry() const
    {
        return m_rctGeometry;
    } // qLayerBase::GetGeometry


    /*******************************************************************************
    * qLayerBase::GetDimension
    *******************************************************************************/
    qDimension2D<s32> qLayerBase::GetDimension() const
    {
        return m_rctGeometry.Dimension();
    } // qLayerBase::GetDimension


    /*******************************************************************************
    * qLayerBase::w
    *******************************************************************************/
    s32 qLayerBase::w() const
    {
        return m_rctGeometry.w;
    } // qLayerBase::w


    /*******************************************************************************
    * qLayerBase::h
    *******************************************************************************/
    s32 qLayerBase::h() const
    {
        return m_rctGeometry.h;
    } // qLayerBase::h


    /*******************************************************************************
    * qLayerBase::Name
    *******************************************************************************/
    qString16 qLayerBase::Name() const
    {
        return m_sName;
    } // qLayerBase::Name


    /*******************************************************************************
    * qLayerBase::SetName
    *******************************************************************************/
    void qLayerBase::SetName(qString16 _sName)
    {
        m_sName = _sName;
    } // qLayerBase::SetName


    /*******************************************************************************
    * qLayerBase::CloneBaseData
    *******************************************************************************/
   void qLayerBase::CloneBaseData(const qLayerBase    &_pRhs,
                               bool             _bSameID)
   {
       m_bVisible   = _pRhs.m_bVisible;
       m_dOpacity   = _pRhs.m_dOpacity;
       m_sName      = _pRhs.m_sName;

       if (_bSameID)
       {
           m_u32Id = _pRhs.m_u32Id;
       }

   } // qLayerBase::CloneBaseData


    /*******************************************************************************
    * qLayerBase::Visible
    *******************************************************************************/
    bool qLayerBase::Visible() const
    {
        return m_bVisible;
    } // qLayerBase::Visible


    /*******************************************************************************
    * qLayerBase::SetVisible
    *******************************************************************************/
    void qLayerBase::SetVisible(bool _bVisible)
    {
        m_bVisible = _bVisible;
    } // qLayerBase::SetVisible


    /*******************************************************************************
    * qLayerBase::GetOpacity
    *******************************************************************************/
    dbl qLayerBase::GetOpacity() const
    {
        return m_dOpacity;
    } // qLayerBase::GetOpacity


    /*******************************************************************************
    * qLayerBase::SetOpacity
    *******************************************************************************/
    void qLayerBase::SetOpacity(dbl  _dOpacity)
    {
        m_dOpacity = _dOpacity;
    } // qLayerBase::SetOpacity

} // namespace qLib
