/*******************************************************************************
* \file Document.h
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
#include "aLib_def.h"
#include "aLayerStack.h"
#include "aSynchronize.h"

using namespace aLib;
using namespace aLib::aPic;


/*******************************************************************************
* class LayerStack
*******************************************************************************/
class LayerStack : public aLayerStack
{
    public:
        LayerStack();
        virtual ~LayerStack();

        void                        createClone(const shared_ptr<LayerStack>    _pSrcLS,
                                                bool                            _bCopyImageData);

        void                        createClone(const shared_ptr<LayerStack>    _pSrcLS,
                                                s32                             _s32NewW,
                                                s32                             _s32NewH);

}; // class LayerStack

using SynchronizedLS    = aSynchronized<shared_ptr<LayerStack>>;
using ExclusiveLS       = aExclusiveAccessor<SynchronizedLS>;
using SharedLS          = aSharedAccessor<SynchronizedLS>;
