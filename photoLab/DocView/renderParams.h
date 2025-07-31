/*******************************************************************************
* \file qRenderParams.h
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
#ifdef _USE_QT_
    #include <QImage>
#endif // _USE_QT_

#include "aLib_def.h"

#include "aDimension2D.h"
#include "aPoint2D.h"
#include "aRect2D.h"
#include "zoomSteps.h"
#include "layerStack.h"

#include "aPicBuffer.h"

using namespace std;
using namespace aLib;
using namespace aLib::aMath;
using namespace aLib::aPic;


/*******************************************************************************
* class RenderParams
*******************************************************************************/
class RenderParams
{
    /*******************************************************************************
    * 1.	setLayerStack
    * 2.	setZoomfactor
    * 3.	setVp_client
    * 4.	setRenderOrigin_zoom
    *
    * 5.	Last command is CreateQImage() which calculates the final QImage
    *******************************************************************************/

    private:
        ZoomSteps                   m_zoomSteps;

        // draw params set by the application
        shared_ptr<SynchronizedLS>  m_pLayerStack;
        aRect2D<s32>                m_r2dVp_client;                     // viewport to render into
        aPoint2D<s32>              m_v2dOrigin_zoom;                   // mapped to left/top of the viewport

        // calculated values
        bool                        m_bModified				{ true };

        // the final picture
        mutable aPicBuffer          m_picBuffer;
        mutable QImage*             m_pImage				{ nullptr };

    public:
        RenderParams();
        virtual ~RenderParams();


    /*******************************************************************************
    * values which are set in View::UpdateDrawParams
    *******************************************************************************/
    public:
        // 1. layer stack
        shared_ptr<SynchronizedLS>  layerStack() const;
        void						setLayerStack(shared_ptr<SynchronizedLS> _pLayerStack);

        // 2. zoomfactor
        dbl                         zoomFactor() const;
        void                        setZoomFactor(dbl _dZoomFactor);
        void                        increaseZoomFactor();
        void                        decreaseZoomFactor();

        // 3. SetVp_client
        void						setVp_client(const aRect2D<s32> &_r2dViewport_client);
        void						setVp_client(s32   _x_client,
                                                 s32   _y_client,
                                                 s32   _w_client,
                                                 s32   _h_client);

        // 4. m_v2dOrigin_zoom
        const aPoint2D<s32>&       origin_zoom( ) const;
        void						setOrigin_zoom(const aPoint2D<s32> &_v2dOrigin_zoom);
        void						setOrigin_zoom(s32    _x_zoom,
                                                   s32    _y_zoom);

    public:
        bool                        isValid() const;

        // calculated values

        // size of the zoomed layer stack (picture)
        aDimension2D<s32>           dimension_zoom() const;
        s32                         w_zoom() const;
        s32                         h_zoom() const;

        // the position and size of the viewport within the client
        aRect2D<s32>                viewPort_client() const;
        aRect2D<s32>                viewPort_pic() const;
        aRect2D<s32>                viewPort_zoom() const;


        /*******************************************************************************
        * GetQImage() is the final method which is called in the UpdateRenderParams()
        * method of the view.
        *  GetQImage() calculates the QImage depending on the values in the draw buffer
        *******************************************************************************/
        #ifdef _USE_QT_
            QImage*                 createQImage();
        #endif // _USE_QT_

}; // class RenderParams
