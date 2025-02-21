/*******************************************************************************
* \file qLayerStack.h
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
#include "qLayerStack.h"
#include "qLayer_i.h"


namespace qLib
{
    /*******************************************************************************
    * qLayerStack::qLayerStack
    *******************************************************************************/
    qLayerStack::qLayerStack()
    {
    } // qLayerStack::qLayerStack


    /*******************************************************************************
    * qLayerStack::qLayerStack
    *******************************************************************************/
//    qLayerStack::qLayerStack(const qLayerStack& _rhs)
//    {
//        // ???
//        *this = _rhs;

////        for (const shared_ptr<LayerI> &pLayer : _rhs)
////        {
////            push_back(pLayer);
////        }
//    } // qLayerStack::qLayerStack


    /*******************************************************************************
    * qLayerStack::~qLayerStack
    *******************************************************************************/
    qLayerStack::~qLayerStack()
    {
    } // qLayerStack::~qLayerStack


    /*******************************************************************************
    * qLayerStack::CreateClone
    *******************************************************************************/
    shared_ptr<qLayerStack> qLayerStack::CreateClone(bool   _bSameLayerID,
                                                     bool   _bCopyImageData) const
    {
        shared_ptr<qLayerStack> pNewLS = make_shared<qLayerStack> ();

        pNewLS->SetType(m_eType);
        pNewLS->SetDimension(m_d2dDimension);
        pNewLS->SetName(m_sName);

        for (const unique_ptr<qLayerI> &pLayer : *this)
        {
            pNewLS->AddLayer(pLayer->CreateClone(_bSameLayerID, _bCopyImageData));
        }

        return pNewLS;
    } // qLayerStack::CreateClone


    /*******************************************************************************
    * qLayerStack::CreateCloneSwapWH
    *******************************************************************************/
    shared_ptr<qLayerStack> qLayerStack::CreateCloneSwapWH(bool    _bSameLayerID) const
    {
        shared_ptr<qLayerStack> pNewLS = make_shared<qLayerStack> ();

        pNewLS->SetType(m_eType);
        pNewLS->SetDimension(h(), w());
        pNewLS->SetName(m_sName);

        for (const unique_ptr<qLayerI> &pLayer : *this)
        {
            pNewLS->AddLayer(pLayer->CreateCloneSwapWH(_bSameLayerID));
        }

        return pNewLS;
    } // qLayerStack::CreateCloneSwapWH


    /*******************************************************************************
    * qLayerStack::Type
    *******************************************************************************/
    enumLayerType qLayerStack::Type() const
    {

        return m_eType;
    } // qLayerStack::Type


    /*******************************************************************************
    * qLayerStack::SetType
    *******************************************************************************/
    void qLayerStack::SetType(enumLayerType  _eType)
    {
        m_eType = _eType;
    } // qLayerStack::SetType


    /*******************************************************************************
    * qLayerStack::Dimension
    *******************************************************************************/
    qDimension2D<s32> qLayerStack::Dimension() const
    {

        return m_d2dDimension;
    } // qLayerStack::Dimension


    /*******************************************************************************
    * qLayerStack::SetDimension
    *******************************************************************************/
    void qLayerStack::SetDimension(const qDimension2D<s32> &_d2dDim)
    {
        m_d2dDimension = _d2dDim;
    } // qLayerStack::SetDimension


    /*******************************************************************************
    * qLayerStack::SetDimension
    *******************************************************************************/
    void qLayerStack::SetDimension(s32        _s32W,
                                   s32        _s32H)
    {
        SetDimension(qDimension2D<s32>(_s32W, _s32H));
    } // qLayerStack::SetDimension


    /*******************************************************************************
    * qLayerStack::w
    *******************************************************************************/
    s32 qLayerStack::w() const
    {
        return m_d2dDimension.w();
    } // qLayerStack::w


    /*******************************************************************************
    * qLayerStack::h
    *******************************************************************************/
    s32 qLayerStack::h() const
    {
        return m_d2dDimension.h();
    } // qLayerStack::h


    /*******************************************************************************
    * qLayerStack::Name
    *******************************************************************************/
    qString16 qLayerStack::Name() const
    {

        return m_sName;
    } // qLayerStack::Name


    /*******************************************************************************
    * qLayerStack::SetName
    *******************************************************************************/
    void qLayerStack::SetName(const qString16& _sName)
    {
        m_sName = _sName;
    } // qLayerStack::SetName


    /*******************************************************************************
    * qLayerStack::IsValid
    *******************************************************************************/
    bool qLayerStack::IsValid() const
    {
        return size() > 0 && w() > 0 && h() > 0;
    } // qLayerStack::IsValid


    /*******************************************************************************
    * qLayerStack::RemoveAllLayers
    *******************************************************************************/
    void qLayerStack::RemoveAllLayers()
    {
        clear();
    } // qLayerStack::RemoveAllLayers


    /*******************************************************************************
    * qLayerStack::AddLayer
    *******************************************************************************/
    void qLayerStack::AddLayer(unique_ptr<qLayerI> _pLayer)
    {
        push_back(std::move(_pLayer));
    } // qLayerStack::AddLayer


    /*******************************************************************************
    * qLayerStack::FindLayer
    *******************************************************************************/
    qLayerI* qLayerStack::FindLayer(u32   _u32LayerID)
    {
        for (const unique_ptr<qLayerI> &pLayer : *this)
        {
            if (pLayer->Id() == _u32LayerID)
                return pLayer.get();
        }

        return nullptr;
    } // qLayerStack::FindLayer

} // namespace qLib
