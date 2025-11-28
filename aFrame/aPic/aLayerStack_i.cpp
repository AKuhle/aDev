/*******************************************************************************
* \file aLayerStackI.h
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
#include "aLayerStack_i.h"
#include "aPath.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aPic {


/*******************************************************************************
* aLayerStackI::aLayerStackI
*******************************************************************************/
aLayerStackI::aLayerStackI()
{
} // aLayerStackI::aLayerStackI


/*******************************************************************************
* aLayerStackI::~aLayerStackI
*******************************************************************************/
aLayerStackI::~aLayerStackI()
{
} // aLayerStackI::~aLayerStackI


/*******************************************************************************
* aLayerStackI::isValid
*******************************************************************************/
bool aLayerStackI::isValid() const
{
    return m_vLayer.size() > 0;
} // aLayerStackI::isValid


/*******************************************************************************
* aLayerStackI::addLayer
*******************************************************************************/
void aLayerStackI::addLayer(shared_ptr<aLayerI> _pLayer)
{
    CHECK_PRE_CONDITION_VOID(_pLayer);

    m_vLayer.push_back(_pLayer);
} // aLayerStackI::addLayer


} // namespace aPic
} // namespace aFrame
