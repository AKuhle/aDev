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
#include "aHelper.h"
#include "aLayerStack.h"



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
* RenderParams::layerStack
*******************************************************************************/
shared_ptr<aLayerStack> RenderParams::layerStack() const
{
    return m_pLayerStack;
} // RenderParams::layerStack


/*******************************************************************************
* RenderParams::setLayerStack
*******************************************************************************/
void RenderParams::setLayerStack(shared_ptr<aLayerStack> _pLayerStack)
{
    if (m_pLayerStack != _pLayerStack)
    {
        m_pLayerStack   = _pLayerStack;
        m_bModified     = true;
    }
} // RenderParams::setLayerStack


/*******************************************************************************
* RenderParams::zoomFactor
*******************************************************************************/
dbl RenderParams::zoomFactor() const
{
    return m_dZoomFactor;
} // RenderParams::zoomFactor


/*******************************************************************************
* RenderParams::setZoomFactor
*******************************************************************************/
void RenderParams::setZoomFactor(dbl _dZoomFactor)
{
    if (!aUtil::isEqual<dbl>(m_dZoomFactor, _dZoomFactor))
    {
        m_dZoomFactor = _dZoomFactor;
        m_bModified     = true;
    }
} // RenderParams::setZoomFactor


/*******************************************************************************
* RenderParams::setVp_client
*******************************************************************************/
void RenderParams::setVp_client(const aRect2D<s32> &_r2dViewport_client)
{
    if (m_r2dVp_client != _r2dViewport_client)
    {
        m_r2dVp_client  = _r2dViewport_client;
        m_bModified     = true;
    }
} // RenderParams::setVp_client


/*******************************************************************************
* RenderParams::setVp_client
*******************************************************************************/
void RenderParams::setVp_client(s32   _x_client,
                                s32   _y_client,
                                s32   _w_client,
                                s32   _h_client)
{
    setVp_client(aRect2D<s32> (_x_client, _y_client, _w_client, _h_client));
} // RenderParams::setVp_client


/*******************************************************************************
* RenderParams::origin_zoom
*******************************************************************************/
const aVector2D<s32>& RenderParams::origin_zoom() const
{
    return m_v2dOrigin_zoom;
} // RenderParams::origin_zoom


/*******************************************************************************
* RenderParams::setOrigin_zoom
*******************************************************************************/
void RenderParams::setOrigin_zoom(const aVector2D<s32> &_v2dOrigin_zoom)
{
    if (m_v2dOrigin_zoom != _v2dOrigin_zoom)
    {
        m_v2dOrigin_zoom    = _v2dOrigin_zoom;
        m_bModified         = true;
    }
} // RenderParams::setOrigin_zoom


/*******************************************************************************
* RenderParams::setOrigin_zoom
*******************************************************************************/
void RenderParams::setOrigin_zoom(s32   _x_zoom,
                                  s32   _y_zoom)
{
    setOrigin_zoom(aVector2D<s32>(_x_zoom, _y_zoom));
} // RenderParams::setOrigin_zoom


/*******************************************************************************
* RenderParams::isValid
*******************************************************************************/
bool RenderParams::isValid() const
{
    return m_pLayerStack != nullptr && m_pLayerStack->isValid();
} // RenderParams::isValid


/*******************************************************************************
* RenderParams::zoomedDimension
*******************************************************************************/
aDimension2D<s32> RenderParams::zoomedDimension() const
{
    CHECK_PRE_CONDITION(m_pLayerStack != nullptr, aDimension2D<s32> (0, 0));

    return aDimension2D<s32>(m_dZoomFactor * m_pLayerStack->w(),
                             m_dZoomFactor * m_pLayerStack->h());
} // RenderParams::zoomedDimension


/*******************************************************************************
* RenderParams::zoomedW
*******************************************************************************/
s32 RenderParams::zoomedW() const
{
    CHECK_PRE_CONDITION(m_pLayerStack != nullptr, 0);

    return m_dZoomFactor * m_pLayerStack->w();
} // RenderParams::zoomedW


/*******************************************************************************
* RenderParams::zoomedH
*******************************************************************************/
s32 RenderParams::zoomedH() const
{
    CHECK_PRE_CONDITION(m_pLayerStack != nullptr, 0);
    return m_dZoomFactor * m_pLayerStack->h();
} // RenderParams::zoomedH


/*******************************************************************************
* RenderParams::viewPort_client
*******************************************************************************/
aRect2D<s32> RenderParams::viewPort_client() const
{
    return m_r2dVp_client;
} // RenderParams::viewPort_client


/*******************************************************************************
* RenderParams::viewPort_pic
*******************************************************************************/
aRect2D<s32> RenderParams::viewPort_pic() const
{
    aRect2D<s32> r(m_v2dOrigin_zoom.x() / m_dZoomFactor,
                   m_v2dOrigin_zoom.y() / m_dZoomFactor,
                   m_r2dVp_client.w() / m_dZoomFactor,
                   m_r2dVp_client.h() / m_dZoomFactor);

    return r;
} // RenderParams::viewPort_pic


/*******************************************************************************
* RenderParams::viewPort_zoom
*******************************************************************************/
aRect2D<s32> RenderParams::viewPort_zoom() const
{
    return aRect2D<s32> (m_v2dOrigin_zoom.x(),
                        m_v2dOrigin_zoom.y(),
                        zoomedW(),
                        zoomedH());
} // RenderParams::viewPort_zoom


/*******************************************************************************
* RenderParams::createQImage
*******************************************************************************/
#ifdef _USE_QT_
    QImage* RenderParams::createQImage()
    {
        if (m_bModified)
        {
            // parameter have changed => update the QImage
            DELETE0(m_pImage);

            // render either the layerstack or a single layer
            if (m_pLayerStack != nullptr && m_pLayerStack->isValid())
            {
                m_picBuffer.toQImage(m_pLayerStack,
                                     m_r2dVp_client.w(), m_r2dVp_client.h(),
                                     m_v2dOrigin_zoom, m_dZoomFactor, m_pImage);
            }

            m_bModified = false;
        } // if (m_bModified)

        return m_pImage;
    } // RenderParams::createQImage
#endif // _USE_QT_
