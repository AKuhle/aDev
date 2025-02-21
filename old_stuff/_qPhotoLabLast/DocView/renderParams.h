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
#include "qLib.h"

using namespace qLib;


/*******************************************************************************
* class RenderParams
*******************************************************************************/
class RenderParams
{
    /*******************************************************************************
    * 1.	SetLayerStack
    * 2.	SetZoomfactor
    * 3.	SetVp_client
    * 4.	SetRenderOrigin_zoom
    *
    * 5.	Last command in CreateQImage() which calculates the final QImage
    *******************************************************************************/

    private:
        // draw params set by the application
        shared_ptr<qLayerStack> m_pLayerStack;

        dbl                     m_dblZoomFactor			{ 1. };		// the current zoomfactor
        qRect2D<s32>            m_r2dVp_client;                     // viewport to render into
        qVector2D<s32>          m_v2dOrigin_zoom;                   // mapped to left/top of the viewport

        // calculated values
        bool                    m_bModified				{ true };

        // the final picture
        mutable qPicBuffer      m_picBuffer;
        mutable QImage*         m_pImage				{ nullptr };

    public:
        RenderParams();
        virtual ~RenderParams();


    /*******************************************************************************
    * values which are set in View::UpdateDrawParams
    *******************************************************************************/
    public:
        // 1. layer stack
        void						SetLayerStack(shared_ptr<qLayerStack> _pLayerStack);
        shared_ptr<qLayerStack>     LayerStack() const;

        // 2. zoomfactor
        dbl                         ZoomFactor() const;
        void                        SetZoomFactor(dbl _dblZoomFactor);

        // 3. SetVp_client
        void						SetVp_client(const qRect2D<s32>& _r2dViewport_client);
        void						SetVp_client(s32   _s32X_client,
                                                 s32   _s32Y_client,
                                                 s32   _s32W_client,
                                                 s32   _s32H_client);

        // 4. m_v2dOrigin_zoom
        const qVector2D<s32>&       Origin_zoom( ) const;
        void						SetOrigin_zoom(const qVector2D<s32>& _v2dOrigin_zoom);
        void						SetOrigin_zoom(s32    _v2dOriginX_zoom,
                                                   s32    _v2dOriginY_zoom);

    public:
        bool                        IsValid() const;

        // calculated values

        // size of the zoomed layer stack (picture)
        qDimension2D<s32>           ZoomedDimension() const;
        s32                         ZoomedW() const;
        s32                         ZoomedH() const;

        // the position and size of the viewport within the client
        const qRect2D<s32>&         VpRect_client() const;
        qRect2D<s32>                VpRect_pic() const;
        qRect2D<s32>                VpRect_zoom() const;


        /*******************************************************************************
        * GetQImage() is the final method which is called in the UpdateRenderParams()
        * method of the view.
        *  GetQImage() calculates the QImage depending on the values in the draw buffer
        *******************************************************************************/
        QImage*						CreateQImage();

}; // class RenderParams
