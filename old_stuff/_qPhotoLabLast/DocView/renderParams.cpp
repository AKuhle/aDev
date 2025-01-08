/*******************************************************************************
* \file qRenderParams.cpp
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
#include "renderParams.h"



/*******************************************************************************
* RenderParams::RenderParams
*******************************************************************************/
RenderParams::RenderParams()
{
} // RenderParams::RenderParams


/*******************************************************************************
* RenderParams::~RenderParams
*******************************************************************************/
RenderParams::~RenderParams()
{
    DELETE0(m_pImage);
} // RenderParams::~RenderParams


/*******************************************************************************
* RenderParams::SetLayerStack
*******************************************************************************/
void RenderParams::SetLayerStack(shared_ptr<qLayerStack> _pLayerStack)
{
    if (m_pLayerStack != _pLayerStack)
    {
        m_pLayerStack   = _pLayerStack;
        //m_pLayer        = nullptr;
        m_bModified     = true;
    }
} // RenderParams::SetLayerStack


/*******************************************************************************
* RenderParams::LayerStack
*******************************************************************************/
shared_ptr<qLayerStack> RenderParams::LayerStack() const
{
    return m_pLayerStack;
} // RenderParams::LayerStack


/*******************************************************************************
* RenderParams::ZoomFactor
*******************************************************************************/
dbl RenderParams::ZoomFactor() const
{
    return m_dblZoomFactor;
} // RenderParams::ZoomFactor


/*******************************************************************************
* RenderParams::SetZoomFactor
*******************************************************************************/
void RenderParams::SetZoomFactor(dbl _dblZoomFactor)
{
    if (!IsEqual(m_dblZoomFactor, _dblZoomFactor))
    {
        m_dblZoomFactor = _dblZoomFactor;
        m_bModified     = true;
    }
} // RenderParams::SetZoomFactor


/*******************************************************************************
* RenderParams::SetVp_client
*******************************************************************************/
void RenderParams::SetVp_client(const qRect2D<s32>& _r2dViewport_client)
{
    if (m_r2dVp_client != _r2dViewport_client)
    {
        m_r2dVp_client  = _r2dViewport_client;
        m_bModified     = true;
    }
} // RenderParams::SetVp_client


/*******************************************************************************
* RenderParams::SetVp_client
*******************************************************************************/
void RenderParams::SetVp_client(s32   _s32X_client,
                                s32   _s32Y_client,
                                s32   _s32W_client,
                                s32   _s32H_client)
{
    SetVp_client(qRect2D<s32> (_s32X_client, _s32Y_client, _s32W_client, _s32H_client));
} // RenderParams::SetVp_client


/*******************************************************************************
* RenderParams::Origin_zoom
*******************************************************************************/
const qVector2D<s32>& RenderParams::Origin_zoom() const
{
    return m_v2dOrigin_zoom;
} // RenderParams::Origin_zoom


/*******************************************************************************
* RenderParams::SetOrigin_zoom
*******************************************************************************/
void RenderParams::SetOrigin_zoom(const qVector2D<s32>    &_v2dOrigin_zoom)
{
    if (m_v2dOrigin_zoom != _v2dOrigin_zoom)
    {
        m_v2dOrigin_zoom    = _v2dOrigin_zoom;
        m_bModified         = true;
    }
} // RenderParams::SetOrigin_zoom


/*******************************************************************************
* RenderParams::SetOrigin_zoom
*******************************************************************************/
void RenderParams::SetOrigin_zoom(s32   _v2dOriginX_zoom,
                                  s32   _v2dOriginY_zoom)
{
    SetOrigin_zoom(qVector2D<s32>(_v2dOriginX_zoom, _v2dOriginY_zoom));
} // RenderParams::SetOrigin_zoom


/*******************************************************************************
* RenderParams::IsValid
*******************************************************************************/
bool RenderParams::IsValid() const
{
    return (m_pLayerStack != nullptr) &&
           (m_pLayerStack->w() > 0 ) &&
           (m_pLayerStack->h() > 0 );
} // RenderParams::IsValid


/*******************************************************************************
* RenderParams::ZoomedDimension
*******************************************************************************/
qDimension2D<s32> RenderParams::ZoomedDimension() const
{
    CHECK_PRE_CONDITION(m_pLayerStack != nullptr, qDimension2D<s32> (0, 0));

    return qDimension2D<s32>(m_dblZoomFactor * m_pLayerStack->w(),
                             m_dblZoomFactor * m_pLayerStack->h());
} // RenderParams::ZoomedDimension


/*******************************************************************************
* RenderParams::ZoomedW
*******************************************************************************/
s32 RenderParams::ZoomedW() const
{
    CHECK_PRE_CONDITION(m_pLayerStack != nullptr, 0);

    return m_dblZoomFactor * m_pLayerStack->w();
} // RenderParams::ZoomedW


/*******************************************************************************
* RenderParams::ZoomedH
*******************************************************************************/
s32 RenderParams::ZoomedH() const
{
    CHECK_PRE_CONDITION(m_pLayerStack != nullptr, 0);
    return m_dblZoomFactor * m_pLayerStack->h();
} // RenderParams::ZoomedH


/*******************************************************************************
* RenderParams::VpRect_client
*******************************************************************************/
const qRect2D<s32>& RenderParams::VpRect_client() const
{
    return m_r2dVp_client;
} // RenderParams::VpRect_client


/*******************************************************************************
* RenderParams::VpRect_pic
*******************************************************************************/
qRect2D<s32> RenderParams::VpRect_pic() const
{
    qRect2D<s32> r(m_v2dOrigin_zoom.x() / m_dblZoomFactor,
                   m_v2dOrigin_zoom.y() / m_dblZoomFactor,
                   m_r2dVp_client.w() / m_dblZoomFactor,
                   m_r2dVp_client.h() / m_dblZoomFactor);

    return r;
} // RenderParams::VpRect_pic


/*******************************************************************************
* RenderParams::VpRect_zoom
*******************************************************************************/
qRect2D<s32> RenderParams::VpRect_zoom() const
{
    return qRect2D<s32> (m_v2dOrigin_zoom.x(),
                        m_v2dOrigin_zoom.y(),
                        ZoomedW(),
                        ZoomedH());
} // RenderParams::VpRect_zoom


/*******************************************************************************
* RenderParams::CreateQImage
*******************************************************************************/
QImage* RenderParams::CreateQImage()
{
    if (m_bModified)
    {
        // parameter have changed => update the QImage
        DELETE0(m_pImage);

        // render either the layerstack or a single layer
        if (m_pLayerStack != nullptr && m_pLayerStack->IsValid())
        {
            m_picBuffer.ToQImage(m_pLayerStack,
                                 m_r2dVp_client.w(), m_r2dVp_client.h(),
                                 m_v2dOrigin_zoom, m_dblZoomFactor, m_pImage);
        }

        m_bModified = false;
    } // if (m_bModified)

    return m_pImage;
} // RenderParams::CreateQImage
