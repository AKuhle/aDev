/*******************************************************************************
* \file aLayerStack.h
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
#include "aLayerStack.h"
#include "aLayer_i.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aPic {


/*******************************************************************************
* aLayerStack::aLayerStack
*******************************************************************************/
aLayerStack::aLayerStack()
{
} // aLayerStack::aLayerStack


/*******************************************************************************
* aLayerStack::aLayerStack
*******************************************************************************/
//    aLayerStack::aLayerStack(const aLayerStack& _rhs)
//    {
//        // ???
//        *this = _rhs;

////        for (const shared_ptr<LayerI> &pLayer : _rhs)
////        {
////            push_back(pLayer);
////        }
//    } // aLayerStack::aLayerStack


/*******************************************************************************
* aLayerStack::~aLayerStack
*******************************************************************************/
aLayerStack::~aLayerStack()
{
} // aLayerStack::~aLayerStack


/*******************************************************************************
* aLayerStack::createClone
*******************************************************************************/
void aLayerStack::createClone(const shared_ptr<aLayerStack> _pSrcLS,
                              bool                          _bCopyImageData)
{
    setType(_pSrcLS->m_eType);
    setDimension(_pSrcLS->m_d2dDimension);
    setName(_pSrcLS->m_sName);

    for (const unique_ptr<aLayerI> &pLayer : *_pSrcLS)
    {
        addLayer(pLayer->createClone(_bCopyImageData));
    }
} // aLayerStack::createClone


/*******************************************************************************
* aLayerStack::createClone
*******************************************************************************/
void aLayerStack::createClone(const shared_ptr<aLayerStack> _pSrcLS,
                              s32                           _s32NewW,
                              s32                           _s32NewH)
{
    setType(_pSrcLS->m_eType);
    setDimension(_s32NewW, _s32NewH);
    setName(_pSrcLS->m_sName);

    for (const unique_ptr<aLayerI> &pLayer : *_pSrcLS)
    {
        addLayer(pLayer->createClone(_s32NewW, _s32NewH));
    }
} // aLayerStack::createClone


/*******************************************************************************
* aLayerStack::type
*******************************************************************************/
enumLayerType aLayerStack::type() const
{
    return m_eType;
} // aLayerStack::type


/*******************************************************************************
* aLayerStack::setType
*******************************************************************************/
void aLayerStack::setType(enumLayerType  _eType)
{
    m_eType = _eType;
} // aLayerStack::setType


/*******************************************************************************
* aLayerStack::dimension
*******************************************************************************/
aDimension2D<s32> aLayerStack::dimension() const
{

    return m_d2dDimension;
} // aLayerStack::dimension


/*******************************************************************************
* aLayerStack::setDimension
*******************************************************************************/
void aLayerStack::setDimension(const aDimension2D<s32> &_d2dDim)
{
    m_d2dDimension = _d2dDim;
} // aLayerStack::setDimension


/*******************************************************************************
* aLayerStack::setDimension
*******************************************************************************/
void aLayerStack::setDimension(s32        _s32W,
                               s32        _s32H)
{
    m_d2dDimension.set(_s32W, _s32H);
} // aLayerStack::setDimension


/*******************************************************************************
* aLayerStack::w
*******************************************************************************/
s32 aLayerStack::w() const
{
    return m_d2dDimension.w();
} // aLayerStack::w


/*******************************************************************************
* aLayerStack::h
*******************************************************************************/
s32 aLayerStack::h() const
{
    return m_d2dDimension.h();
} // aLayerStack::h


/*******************************************************************************
* aLayerStack::name
*******************************************************************************/
aString aLayerStack::name() const
{

    return m_sName;
} // aLayerStack::name


/*******************************************************************************
* aLayerStack::setName
*******************************************************************************/
void aLayerStack::setName(const aString& _sName)
{
    m_sName = _sName;
} // aLayerStack::setName


/*******************************************************************************
* aLayerStack::isValid
*******************************************************************************/
bool aLayerStack::isValid() const
{
    return !empty() && w() > 0 && h() > 0;
} // aLayerStack::isValid


/*******************************************************************************
* aLayerStack::removeAllLayers
*******************************************************************************/
void aLayerStack::removeAllLayers()
{
    clear();
} // aLayerStack::removeAllLayers


/*******************************************************************************
* aLayerStack::addLayer
*******************************************************************************/
void aLayerStack::addLayer(unique_ptr<aLayerI> _pLayer)
{
    push_back(std::move(_pLayer));
} // aLayerStack::addLayer


/*******************************************************************************
* aLayerStack::FindLayer
*******************************************************************************/
// aLayerI* aLayerStack::FindLayer(u32   _u32LayerID)
// {
//     for (const unique_ptr<aLayerI> &pLayer : *this)
//     {
//         if (pLayer->Id() == _u32LayerID)
//             return pLayer.get();
//     }

//     return nullptr;
// } // aLayerStack::FindLayer


} // namespace aPic
} // namespace aLib
