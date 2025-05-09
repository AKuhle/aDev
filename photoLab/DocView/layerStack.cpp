/*******************************************************************************
* \file LayerStack.cpp
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
#include "layerStack.h"


/*******************************************************************************
* LayerStack::LayerStack
*******************************************************************************/
LayerStack::LayerStack()
{
} // LayerStack::LayerStacks


/*******************************************************************************
* LayerStack::~LayerStack
*******************************************************************************/
LayerStack::~LayerStack()
{
} // LayerStack::~LayerStack


/*******************************************************************************
* LayerStack::createClone
*******************************************************************************/
void LayerStack::createClone(const shared_ptr<LayerStack>   _pSrcLS,
                             bool                           _bCopyImageData)
{
    aLayerStack::createClone(_pSrcLS, _bCopyImageData);
} // LayerStack::createClone


/*******************************************************************************
* LayerStack::createClone
*******************************************************************************/
void  LayerStack::createClone(const shared_ptr<LayerStack>  _pSrcLS,
                              s32                           _s32NewW,
                              s32                           _s32NewH)
{
    aLayerStack::createClone(_pSrcLS, _s32NewW, _s32NewH);
} // LayerStack::createClone
