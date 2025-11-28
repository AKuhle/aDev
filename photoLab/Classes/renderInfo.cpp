/*******************************************************************************
* \file BaseApp.h
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
#include "renderInfo.h"



/*******************************************************************************
* RenderInfo::RenderInfo
*******************************************************************************/
RenderInfo::RenderInfo()
{
} // RenderInfo::RenderInfo


/*******************************************************************************
* RenderInfo::~RenderInfo
*******************************************************************************/
RenderInfo::~RenderInfo()
{
} // RenderInfo::~RenderInfo


/*******************************************************************************
* RenderInfo::setLayerStack
*******************************************************************************/
void RenderInfo::setLayerStack(const aLayerStack &_layerStack)
{
    m_layerStack = _layerStack;

    m_bModified = true;
} // RenderInfo::setLayerStack


/*******************************************************************************
* RenderInfo::getQImage
*******************************************************************************/
shared_ptr<QImage> RenderInfo::getQImage() const
{
    if (m_bModified)
    {
        m_pQImage = m_layerStack.getQImage();
    }

    return m_pQImage;
} // RenderInfo::getQImage
