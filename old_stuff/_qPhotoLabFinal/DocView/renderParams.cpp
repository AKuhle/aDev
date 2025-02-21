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
* RenderParams::GetLayerStack
*******************************************************************************/
shared_ptr<qLayerStack> RenderParams::GetLayerStack() const
{
    return m_pLayerStack;
} // RenderParams::GetLayerStack


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
* RenderParams::GetZoomFactor
*******************************************************************************/
dbl RenderParams::GetZoomFactor() const
{
    return m_dZoomFactor;
} // RenderParams::GetZoomFactor


/*******************************************************************************
* RenderParams::SetZoomFactor
*******************************************************************************/
void RenderParams::SetZoomFactor(dbl _dZoomFactor)
{
    if (!MU<dbl>::IsEqual(m_dZoomFactor, _dZoomFactor))
    {
        m_dZoomFactor = _dZoomFactor;
        m_bModified     = true;
    }
} // RenderParams::SetZoomFactor


/*******************************************************************************
* RenderParams::SetVp_client
*******************************************************************************/
void RenderParams::SetVp_client(const qRect2D<s32> &_r2dViewport_client)
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
void RenderParams::SetVp_client(s32   _x_client,
                                s32   _y_client,
                                s32   _w_client,
                                s32   _h_client)
{
    SetVp_client(qRect2D<s32> (_x_client, _y_client, _w_client, _h_client));
} // RenderParams::SetVp_client


/*******************************************************************************
* RenderParams::GetOrigin_zoom
*******************************************************************************/
const qVector2D<s32>& RenderParams::GetOrigin_zoom() const
{
    return m_v2dOrigin_zoom;
} // RenderParams::GetOrigin_zoom


/*******************************************************************************
* RenderParams::SetOrigin_zoom
*******************************************************************************/
void RenderParams::SetOrigin_zoom(const qVector2D<s32> &_v2dOrigin_zoom)
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
void RenderParams::SetOrigin_zoom(s32   _x_zoom,
                                  s32   _y_zoom)
{
    SetOrigin_zoom(qVector2D<s32>(_x_zoom, _y_zoom));
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
* RenderParams::GetZoomedDimension
*******************************************************************************/
qDimension2D<s32> RenderParams::GetZoomedDimension() const
{
    CHECK_PRE_CONDITION(m_pLayerStack != nullptr, qDimension2D<s32> (0, 0));

    return qDimension2D<s32>(m_dZoomFactor * m_pLayerStack->w(),
                             m_dZoomFactor * m_pLayerStack->h());
} // RenderParams::GetZoomedDimension


/*******************************************************************************
* RenderParams::GetZoomedW
*******************************************************************************/
s32 RenderParams::GetZoomedW() const
{
    CHECK_PRE_CONDITION(m_pLayerStack != nullptr, 0);

    return m_dZoomFactor * m_pLayerStack->w();
} // RenderParams::GetZoomedW


/*******************************************************************************
* RenderParams::GetZoomedH
*******************************************************************************/
s32 RenderParams::GetZoomedH() const
{
    CHECK_PRE_CONDITION(m_pLayerStack != nullptr, 0);
    return m_dZoomFactor * m_pLayerStack->h();
} // RenderParams::GetZoomedH


/*******************************************************************************
* RenderParams::GetVpRect_client
*******************************************************************************/
const qRect2D<s32>& RenderParams::GetVpRect_client() const
{
    return m_r2dVp_client;
} // RenderParams::GetVpRect_client


/*******************************************************************************
* RenderParams::GetVpRect_pic
*******************************************************************************/
qRect2D<s32> RenderParams::GetVpRect_pic() const
{
    qRect2D<s32> r(m_v2dOrigin_zoom.x / m_dZoomFactor,
                   m_v2dOrigin_zoom.y / m_dZoomFactor,
                   m_r2dVp_client.w / m_dZoomFactor,
                   m_r2dVp_client.h / m_dZoomFactor);

    return r;
} // RenderParams::GetVpRect_pic


/*******************************************************************************
* RenderParams::GetVpRect_zoom
*******************************************************************************/
qRect2D<s32> RenderParams::GetVpRect_zoom() const
{
    return qRect2D<s32> (m_v2dOrigin_zoom.x,
                        m_v2dOrigin_zoom.y,
                        GetZoomedW(),
                        GetZoomedH());
} // RenderParams::GetVpRect_zoom


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
                                 m_r2dVp_client.w, m_r2dVp_client.h,
                                 m_v2dOrigin_zoom, m_dZoomFactor, m_pImage);
        }

        m_bModified = false;
    } // if (m_bModified)

    return m_pImage;
} // RenderParams::CreateQImage
