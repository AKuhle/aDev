/*******************************************************************************
* \file layer_Rgb8.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qlayer_rgb8.h"
#include "qRgba.h"



namespace qLib
{
    /*******************************************************************************
    * qLayerRgb8::qLayerRgb8
    *******************************************************************************/
    qLayerRgb8::qLayerRgb8(const qRect2D<s32>	&_rctLayer)
    : qLayerI(_rctLayer),
      m_pR(new qChannel<u8> (_rctLayer.Dimension())),
      m_pG(new qChannel<u8> (_rctLayer.Dimension())),
      m_pB(new qChannel<u8> (_rctLayer.Dimension())),
      m_pA(new qChannel<u8> (_rctLayer.Dimension()))
    {
    } // qLayerRgb8::qLayerRgb8


    /*******************************************************************************
    * qLayerRgb8::qLayerRgb8
    *******************************************************************************/
    qLayerRgb8::qLayerRgb8(s32  _s32X,
                           s32	_s32Y,
                           s32	_s32W,
                           s32  _s32H)
    : qLayerI(qRect2D<s32> (_s32X, _s32Y, _s32W, _s32H)),
      m_pR(new qChannel<u8> (_s32W, _s32H)),
      m_pG(new qChannel<u8> (_s32W, _s32H)),
      m_pB(new qChannel<u8> (_s32W, _s32H)),
      m_pA(new qChannel<u8> (_s32W, _s32H))
    {
    } // qLayerRgb8::qLayerRgb8


    /*******************************************************************************
    * qLayerRgb8::qLayerRgb8
    *******************************************************************************/
    qLayerRgb8::qLayerRgb8(s32  _s32W,
                           s32	_s32H)
    : qLayerI(qRect2D<s32> (0, 0, _s32W, _s32H)),
      m_pR(new qChannel<u8> (_s32W, _s32H)),
      m_pG(new qChannel<u8> (_s32W, _s32H)),
      m_pB(new qChannel<u8> (_s32W, _s32H)),
      m_pA(new qChannel<u8> (_s32W, _s32H))
    {
    } // qLayerRgb8::LayerRgb8


    /*******************************************************************************
    * qLayerRgb8::~qLayerRgb8
    *******************************************************************************/
    qLayerRgb8::~qLayerRgb8()
	{
    } // qLayerRgb8::~qLayerRgb8


    /*******************************************************************************
    * qLayerRgb8::Type
    *******************************************************************************/
    enumLayerType qLayerRgb8::Type() const
    {
        return enumLayerType::Rgb_8;
    } // qLayerRgb8::Type


    /*******************************************************************************
    * qLayerRgb8::CreateClone
    * clone: same LayerID's, Layers copies also the image data on demand
    *******************************************************************************/
    unique_ptr<qLayerI> qLayerRgb8::CreateClone(bool    _bSameLayerID,
                                                bool    _bCopyData) const
    {
        unique_ptr<qLayerRgb8>	pNew = make_unique<qLayerRgb8> (Geometry());

        // clone the base data
        pNew->CloneBaseData(*this, _bSameLayerID);

        if (_bCopyData)
        {
            pNew->m_pR->CopyFromChannel(m_pR);
            pNew->m_pG->CopyFromChannel(m_pG);
            pNew->m_pB->CopyFromChannel(m_pB);
            pNew->m_pA->CopyFromChannel(m_pA);
        }

        return pNew;
    } // qLayerRgb8::CreateClone


    /*******************************************************************************
    * qLayerRgb8::CreateClone
    * clone: same LayerID's, empty Layers because of different size
    *******************************************************************************/
    unique_ptr<qLayerI> qLayerRgb8::CreateCloneSwapWH(bool    _bSameLayerID) const
    {
        unique_ptr<qLayerRgb8>	pNew(new qLayerRgb8(h(), w()));

        // clone the base data
        pNew->CloneBaseData(*this, _bSameLayerID);

        return pNew;
    } // qLayerRgb8::CreateClone


    /*******************************************************************************
    * qLayerRgb8::Clear
    *******************************************************************************/
    void qLayerRgb8::Clear()
    {
        m_pR->ClearChannel();
        m_pG->ClearChannel();
        m_pB->ClearChannel();
        m_pA->ClearChannel();
    } // qLayerRgb8::Clear


    /*******************************************************************************
    * qLayerRgb8::Pixel
    *******************************************************************************/
    void qLayerRgb8::Pixel(s32      _s32X,
                           s32      _s32Y,
                           qRgba    &_rgb) const
    {
        s32		s32OS = _s32Y * Geometry().w() + _s32X;

        _rgb.SetRgba(static_cast<Rgba_t> (m_pR->m_pData[s32OS]) / 0xff,
                     static_cast<Rgba_t> (m_pG->m_pData[s32OS]) / 0xff,
                     static_cast<Rgba_t> (m_pB->m_pData[s32OS]) / 0xff,
                     static_cast<Rgba_t> (m_pA->m_pData[s32OS]) / 0xff);
    } // qLayerRgb8::Pixel


    /*******************************************************************************
    * qLayerRgb8::SetPixel
    *******************************************************************************/
    void qLayerRgb8::SetPixel(s32           _s32X,
                              s32           _s32Y,
                              const qRgba   &_rgba)
    {
        s32		s32OS = _s32Y * Geometry().w() + _s32X;

        m_pR->m_pData[s32OS] = static_cast<u8> (_rgba.r * 0xff);
        m_pG->m_pData[s32OS] = static_cast<u8> (_rgba.g * 0xff);
        m_pB->m_pData[s32OS] = static_cast<u8> (_rgba.b * 0xff);
        m_pA->m_pData[s32OS] = static_cast<u8> (_rgba.a * 0xff);
    } // qLayerRgb8::SetPixel


    /*******************************************************************************
    * qLayerRgb8::SetPixel
    *******************************************************************************/
    void qLayerRgb8::SetPixel(s32       _s32X,
                              s32       _s32Y,
                              Rgba_t    _r,
                              Rgba_t    _g,
                              Rgba_t    _b,
                              Rgba_t    _a)
    {
        s32		s32OS = _s32Y * Geometry().w() + _s32X;

        m_pR->m_pData[s32OS] = static_cast<u8> (_r * 0xff);
        m_pG->m_pData[s32OS] = static_cast<u8> (_g * 0xff);
        m_pB->m_pData[s32OS] = static_cast<u8> (_b * 0xff);
        m_pA->m_pData[s32OS] = static_cast<u8> (_a * 0xff);
    } // qLayerRgb8::SetPixel

} // namespace qLib
