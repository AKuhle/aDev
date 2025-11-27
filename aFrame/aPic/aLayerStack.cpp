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
#include "aPath.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aPic {


/*******************************************************************************
* aLayerStack::aLayerStack
*******************************************************************************/
aLayerStack::aLayerStack()
{
} // aLayerStack::aLayerStack


/*******************************************************************************
* aLayerStack::~aLayerStack
*******************************************************************************/
aLayerStack::~aLayerStack()
{
} // aLayerStack::~aLayerStack


/*******************************************************************************
* aLayerStack::isValid
*******************************************************************************/
bool aLayerStack::isValid() const
{
    return (m_pImage != nullptr) &&
            !m_pImage->isNull();
} // aLayerStack::isValid


/*******************************************************************************
* aLayerStack::load
*******************************************************************************/
bool aLayerStack::load(const aPath  &_sFileName)
{
    m_pImage = make_shared<QImage> ();

    if (!m_pImage->load(_sFileName.canonicalPath().toQString()))
    {
        m_pImage = nullptr;
    }

    return m_pImage != nullptr;
} // aLayerStack::load


/*******************************************************************************
* aLayerStack::getQImage
*******************************************************************************/
shared_ptr<QImage> aLayerStack::getQImage() const
{
    return m_pImage;
} // aLayerStack::getQImage


} // namespace aPic
} // namespace aFrame
