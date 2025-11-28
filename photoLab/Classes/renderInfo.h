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
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aLayerStack.h"

using namespace aFrame::aPic;



/*******************************************************************************
* class RenderInfo
*******************************************************************************/
class RenderInfo
{
    private:
        aLayerStack                 m_layerStack;
        bool                        m_bModified         { false };
        mutable shared_ptr<QImage>  m_pQImage;


    public:
        RenderInfo();
        ~RenderInfo();

        void                    setLayerStack(const aLayerStack &_layerStack);

        // finally get the QImage
        shared_ptr<QImage>      getQImage() const;


}; // class RenderInfo
