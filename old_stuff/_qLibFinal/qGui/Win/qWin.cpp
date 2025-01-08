/*******************************************************************************
* \file qWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qWin.h"
#include "qPainter.h"
#include "qWinStyleFactory_dark.h"
#include "qLayoutObj.h"
#include "qCursor.h"
#include "qStyleFillBase.h"
#include "qStyleBorderBase.h"
#include "qMainWin.h"
#include "qCtrlMgr.h"


namespace qLib
{
    /*******************************************************************************
    * statics
    *******************************************************************************/
    unique_ptr<qWinStyleFactoryBase>    qWin::m_pWinStyleFactory(new qWinStyleFactoryDark);


    /*******************************************************************************
    * qWin::qWin
    *******************************************************************************/
    qWin::qWin(SysWin_t  *_pParent  /* = nullptr */)
    : qSysWin(_pParent)
    {
    } // qWin::qWin


    /*******************************************************************************
    * qWin::~qWin
    *******************************************************************************/
    qWin::~qWin()
    {
    } // qWin::~qWin


    /*******************************************************************************
    * qWin::CreateWin
    *******************************************************************************/
    bool qWin::CreateWin()
    {
        qCtrlMgr *pCtrlMgr = dynamic_cast<qCtrlMgr *> (this);

        // 1. set the win style
        m_pWinStyleFactory->SetWinStyle(*this);

        // 2. create the win
        bool bCreated = OnSysCreate() && OnCreate();

        if (bCreated)
        {
            if (pCtrlMgr != nullptr)
            {
                pCtrlMgr->OnRegisterCtrl();
                pCtrlMgr->UpdateAllCtrls();
            }

            SetVisible(true);
        }
        else
        {
            CloseWin();
        }

        return bCreated;
    } // qWin::CreateWin


    /*******************************************************************************
    * qWin::CloseWin
    *******************************************************************************/
    bool qWin::CloseWin()
    {
        if (OnClose())
        {
            _CloseWin();
            return true;
        }

        return false;
    } // qWin::CloseWin


    /*******************************************************************************
    * qWin::GetParent
    *******************************************************************************/
    qWin* qWin::GetParent() const
    {
        return static_cast<qWin *> (_Parent());
    } // qWin::GetParent


    /*******************************************************************************
    * qWin::SetParent
    *******************************************************************************/
    void qWin::SetParent(qWin *_pParent)
    {
        _SetParent(_pParent);
    } // qWin::SetParent


    /*******************************************************************************
    * qWin::GetLayout
    *******************************************************************************/
    qLayoutObj* qWin::GetLayout() const
    {
        return m_pLayout.get();
    } // qWin::GetLayout


    /*******************************************************************************
    * qWin::SetLayout
    *******************************************************************************/
    void qWin::SetLayout(unique_ptr<qLayoutObj> _pLayout)
    {
        m_pLayout = std::move(_pLayout);
    } // qWin::SetLayout


    /*******************************************************************************
    * qWin::IsVisible
    *******************************************************************************/
    bool qWin::IsVisible() const
    {
        return _IsVisible();
    } // qWin::IsVisible


    /*******************************************************************************
    * qWin::SetVisible
    *******************************************************************************/
    void qWin::SetVisible(bool _bVisible)
    {
        _SetVisible(_bVisible);
    } // qWin::SetVisible


    /*******************************************************************************
    * qWin::IsDisabled
    *******************************************************************************/
    bool qWin::IsDisabled() const
    {
        return _IsDisabled();
    } // qWin::IsDisabled


    /*******************************************************************************
    * qWin::SetDisabled
    *******************************************************************************/
    void qWin::SetDisabled(bool _bDisabled)
    {
        _SetDisabled(_bDisabled);
    } // qWin::SetDisabled


    /*******************************************************************************
    * qWin::GeometryRect
    *******************************************************************************/
    qRect2D<s32> qWin::GeometryRect() const
    {
        return _Geometry();
    } // qWin::GeometryRect


    /*******************************************************************************
    * qWin::w
    *******************************************************************************/
    s32 qWin::w() const
    {
        return _w();
    } // qWin::w


    /*******************************************************************************
    * qWin::h
    *******************************************************************************/
    s32 qWin::h() const
    {
        return _h();
    } // qWin::h


    /*******************************************************************************
    * qWin::SetGeometry
    *******************************************************************************/
    void qWin::SetGeometry(const qRect2D<s32> &geo)
    {
        SetGeometry(geo.x, geo.y, geo.w, geo.h);
    } // qWin::SetGeometry


    /*******************************************************************************
    * qWin::SetGeometry
    *******************************************************************************/
    void qWin::SetGeometry(s32 _x,
                           s32 _y,
                           s32 _w,
                           s32 _h)
    {
        qDimension2D<s32> minDim = GetMinSize();

        _SetGeometry(_x, _y,
                     MU<s32>::Clamp(_w, minDim.w, GetMaxSize().w),
                     MU<s32>::Clamp(_h, minDim.h, GetMaxSize().h));

    } // qWin::SetGeometry


    /*******************************************************************************
    * qWin::SetPosition
    *******************************************************************************/
    void qWin::SetPosition(s32 _x,
                           s32 _y)
    {
        _SetPosition(_x, _y);
    } // qWin::SetPosition


    /*******************************************************************************
    * qWin::GetMinSize
    *******************************************************************************/
    qDimension2D<s32> qWin::GetMinSize() const
    {
        if (m_pLayout != nullptr)
        {
            qDimension2D<s32> minDim = m_pLayout->GetMinSize();

            minDim.w += GetPaddingEdges().w() + GetBorderEdges().w() + GetMarginEdges().w();
            minDim.h += GetPaddingEdges().h() + GetBorderEdges().h() + GetMarginEdges().h();

            return qDimension2D<s32> (MU<s32>::Max(m_d2dMinSize.w, minDim.w),
                                      MU<s32>::Max(m_d2dMinSize.h, minDim.h));
        }
        else
        {
            return qLayoutObj::GetMinSize();
        }
    } // qWin::GetMinSize


    /*******************************************************************************
    * qWin::GetMaxSize
    *******************************************************************************/
    qDimension2D<s32> qWin::GetMaxSize() const
    {
        return m_d2dMaxSize;
    } // qWin::GetMaxSize


    /*******************************************************************************
    * qWin::SetMaxSize
    *******************************************************************************/
    void qWin::SetMaxSize(const qDimension2D<s32>  &_maxSize)
    {
        SetMaxSize(_maxSize.w, _maxSize.h);
    } // qWin::SetMaxSize


    /*******************************************************************************
    * qWin::SetMaxSize
    *******************************************************************************/
    void qWin::SetMaxSize(s32 _maxW,
                          s32 _maxH)
    {
        m_d2dMaxSize.Set(_maxW, _maxH);
    } // qWin::SetMaxSize


    /*******************************************************************************
    * qWin::SetMaxW
    *******************************************************************************/
    void qWin::SetMaxW(s32 _maxW)
    {
        m_d2dMaxSize.w = m_minScale * _maxW;
    } // qWin::SetMaxW


    /*******************************************************************************
    * qWin::SetMaxH
    *******************************************************************************/
    void qWin::SetMaxH(s32 _maxH)
    {
        m_d2dMaxSize.h = m_minScale * _maxH;
    } // qWin::SetMaxH


    /*******************************************************************************
    * qWin::SetFixedSize
    *******************************************************************************/
    void qWin::SetFixedSize(const qDimension2D<s32>  &_fixSize)
    {
        m_d2dMinSize.Set(_fixSize.w, _fixSize.h);
        m_d2dMaxSize.Set(_fixSize.w, _fixSize.h);
    } // qWin::SetFixedSize


    /*******************************************************************************
    * qWin::SetFixedSize
    *******************************************************************************/
    void qWin::SetFixedSize(s32 _fixW,
                            s32 _fixH)
    {
        m_d2dMinSize.Set(m_minScale * _fixW, m_minScale * _fixH);
        m_d2dMaxSize.Set(m_minScale * _fixW, m_minScale * _fixH);
    } // qWin::SetFixedSize


    /*******************************************************************************
    * qWin::SetFixedW
    *******************************************************************************/
    void qWin::SetFixedW(s32 _minW)
    {
        m_d2dMinSize.w = m_minScale * _minW;
        m_d2dMaxSize.w = m_minScale * _minW;
    } // qWin::SetFixedW


    /*******************************************************************************
    * qWin::SetFixedH
    *******************************************************************************/
    void qWin::SetFixedH(s32 _minH)
    {
        m_d2dMinSize.h = m_minScale * _minH;
        m_d2dMaxSize.h = m_minScale * _minH;
    } // qWin::SetFixedH


    /*******************************************************************************
    * qWin::IsHoriExpandable
    *******************************************************************************/
    bool qWin::IsHoriExpandable() const
    {
        return GetMaxSize().w > GetMinSize().w;
    } // qWin::IsHoriExpandable


    /*******************************************************************************
    * qWin::IsVertExpandable
    *******************************************************************************/
    bool qWin::IsVertExpandable() const
    {
        return GetMaxSize().h > GetMinSize().h;
    } // qWin::IsVertExpandable


    /*******************************************************************************
    * qWin::ShowMaximized
    *******************************************************************************/
    void qWin::ShowMaximized()
    {
        _ShowMaximized();
    } // qWin::ShowMaximized


    /*******************************************************************************
    * qWin::ShowMinimized
    *******************************************************************************/
    void qWin::ShowMinimized()
    {
        _ShowMinimized();
    } // qWin::ShowMinimized


    /*******************************************************************************
    * qWin::ShowNormal
    *******************************************************************************/
    void qWin::ShowNormal()
    {
        _ShowNormal();
    } // qWin::ShowNormal


    /*******************************************************************************
    * qWin::ToggleMaximized
    *******************************************************************************/
    void qWin::ToggleMaximized()
    {
        if (_IsMaximized())
        {
            _ShowNormal();
        }
        else
        {
            _ShowMaximized();
        }
    } // qWin::ToggleMaximized


    /*******************************************************************************
    * qWin::IsMaximized
    *******************************************************************************/
    bool qWin::IsMaximized() const
    {
        return _IsMaximized();
    } // qWin::IsMaximized


    /*******************************************************************************
    * qWin::IsMinimized
    *******************************************************************************/
    bool qWin::IsMinimized() const
    {
        return _IsMinimized();
    } // qWin::IsMinimized


    /*******************************************************************************
    * qWin::LocalCursorPos
    *******************************************************************************/
    qVector2D<s32> qWin::LocalCursorPos() const
    {
        return _LocalCursorPos();
    } // qWin::LocalCursorPos


    /*******************************************************************************
    * qWin::SetMouseTracking
    *******************************************************************************/
    void qWin::SetMouseTracking(bool _bEnable)
    {
        return _SetMouseTracking(_bEnable);
    } // qWin::SetMouseTracking


    /*******************************************************************************
    * qWin::EnableDrop
    *******************************************************************************/
    void qWin::EnableDrop(bool _bAccept)
    {
        return _EnableDrop(_bAccept);
    } // qWin::EnableDrop


    /*******************************************************************************
    * qWin::SetCursor
    *******************************************************************************/
    void qWin::SetCursor(const qCursor &_cursor)
    {
        return _SetCursor(_cursor);
    } // qWin::SetCursor


    /*******************************************************************************
    * qWin::Update
    *******************************************************************************/
    void qWin::Update()
    {
        _Update();
    } // qWin::Update


    /*******************************************************************************
    * qWin::Repaint
    *******************************************************************************/
    void qWin::Repaint()
    {
        _Repaint();
    } // qWin::Repaint::


    /*******************************************************************************
    * qWin::GetMarginRect
    *******************************************************************************/
    qRect2D<s32> qWin::GetMarginRect() const
    {
        return qRect2D<s32> (0, 0, _w(), _h());
    } // qWin::GetMarginRect


    /*******************************************************************************
    * qWin::GetBorderRect
    *******************************************************************************/
    qRect2D<s32> qWin::GetBorderRect() const
    {
        qRect2D<s32>    r   = GetMarginRect();

        // maximized wins don't have a margin
        if (!IsMaximized())
        {
            const qEdges    &m  = GetMarginEdges();

            r.x += m.l;
            r.y += m.t;
            r.w -= m.w();
            r.h -= m.h();
        }

        return r;
    } // qWin::GetBorderRect


    /*******************************************************************************
    * qWin::GetPaddingRect
    *******************************************************************************/
    qRect2D<s32> qWin::GetPaddingRect() const
    {
        qRect2D<s32>    r   = GetBorderRect();

        // maximized wins don't show a border
        if (!IsMaximized())
        {
            const qEdges    &b  = GetBorderEdges();

            r.x += b.l;
            r.y += b.t;
            r.w -= b.w();
            r.h -= b.h();
        }

        return r;
    } // qWin::GetPaddingRect


    /*******************************************************************************
    * qWin::GetContentRect
    *******************************************************************************/
    qRect2D<s32> qWin::GetContentRect() const
    {
        qRect2D<s32>    r   = GetPaddingRect();
        const qEdges    &p  = GetPaddingEdges();

        r.x += p.l;
        r.y += p.t;
        r.w -= p.w();
        r.h -= p.h();

        return r;
    } // qWin::GetContentRect


    /*******************************************************************************
    * qWin::OnSysCreate
    *******************************************************************************/
    bool qWin::OnSysCreate()
    {
        return true;
    } // qWin::OnSysCreate


    /*******************************************************************************
    * qWin::OnCreate
    *******************************************************************************/
    bool qWin::OnCreate()
    {
        return true;
    } // qWin::OnCreate


    /*******************************************************************************
    * qWin::OnClose
    *******************************************************************************/
    bool qWin::OnClose()
    {
        return true;
    } // qWin::OnClose


    /*******************************************************************************
    * qWin::OnSysResize
    *******************************************************************************/
    void qWin::OnSysResize(const qDimension2D<s32>    &/*_oldSize*/,
                           const qDimension2D<s32>    &/*_newSize*/)
    {
        // update the layout
        if (m_pLayout != nullptr)
        {
            m_pLayout->ArangeChilds(GetContentRect());
        }
    } // qWin::OnSysResize


    /*******************************************************************************
    * qWin::OnResize
    *******************************************************************************/
    void qWin::OnResize(const qDimension2D<s32>    &/*_oldSize*/,
                        const qDimension2D<s32>    &/*_newSize*/)
    {
    } // qWin::OnResize


    /*******************************************************************************
    * qWin::OnEnter
    *******************************************************************************/
    bool qWin::OnEnter(u32                     /*_u32Modifiers*/,
                       const qVector2D<s32>    &/*_v2dLocal*/,
                       const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        return false;
    } // qWin::OnEnter


    /*******************************************************************************
    * qWin::OnLeave
    *******************************************************************************/
    bool qWin::OnLeave(u32 /*_u32Modifiers*/)
    {
        return false;
    } // qWin::OnLeave


    /*******************************************************************************
    * qWin::OnSetCursor
    *******************************************************************************/
    void qWin::OnSetCursor()
    {
        SetCursor(m_cursor);
    } // qWin::OnSetCursor


    /*******************************************************************************
    * qWin::OnWheel
    *******************************************************************************/
    bool qWin::OnWheel(u32                     /*_u32Modifiers*/,
                       s32                     /*_s32Degree*/,
                       const qVector2D<s32>    &/*_v2dLocal*/,
                       const qVector2D<s32>    &/*_v2dGlobal*/)
    {
        return false;
    } // qWin::OnWheel


    /*******************************************************************************
    * qWin::OnDoubleClick
    *******************************************************************************/
    bool qWin::OnDoubleClick(u32                    /*_u32Modifiers*/,
                             u32                    /*_u32MouseButton*/,
                             const qVector2D<s32>   &/*_v2dLocal*/,
                             const qVector2D<s32>   &/*_v2dGlobal*/)
    {
        return false;
    } // qWin::OnDoubleClick


    /*******************************************************************************
    * qWin::OnMousePress
    *******************************************************************************/
    bool qWin::OnMousePress(u32                    /*_u32Modifiers*/,
                            u32                    /*_u32MouseButton*/,
                            const qVector2D<s32>   &/*_v2dLocal*/,
                            const qVector2D<s32>   &/*_v2dGlobal*/)
    {
        return false;
    } // qWin::OnMousePress


    /*******************************************************************************
    * qWin::OnMouseMove
    *******************************************************************************/
    bool qWin::OnMouseMove(u32                    /*_u32Modifiers*/,
                           u32                    /*_u32MouseButton*/,
                           const qVector2D<s32>   &/*_v2dLocal*/,
                           const qVector2D<s32>   &/*_v2dGlobal*/)
    {
        return false;
    } // qWin::OnMouseMove


    /*******************************************************************************
    * qWin::OnMouseRelease
    *******************************************************************************/
    bool qWin::OnMouseRelease(u32                    /*_u32Modifiers*/,
                              u32                    /*_u32MouseButton*/,
                              const qVector2D<s32>   &/*_v2dLocal*/,
                              const qVector2D<s32>   &/*_v2dGlobal*/)
    {
        return false;
    } // qWin::OnMouseRelease


    /*******************************************************************************
    * qWin::OnDropUrl
    *******************************************************************************/
    void qWin::OnDropUrl(const qUrl  &/*_url*/)
    {
    } // qWin::OnDropUrl


    /*******************************************************************************
    * qWin::OnPaintMarginBg
    *******************************************************************************/
    void qWin::OnPaintMarginBg()
    {
        // maximized wins don't have a margin
        if (!IsMaximized())
        {
            qStyleFillBase   *pStyle = GetMarginFillStyle();

            if (pStyle != nullptr)
            {
                qRect2D<s32>    r = GetMarginRect();
                qPainter        p(this);

                pStyle->Draw(p, r);
            }
        }
    } // qWin::OnPaintMarginBg


    /*******************************************************************************
    * qWin::OnPaintBorder
    *******************************************************************************/
    void qWin::OnPaintBorder()
    {
        // maximized wins don't show a border
        if (!IsMaximized())
        {
            qStyleBorderBase   *pStyle = GetBorderStyle();

            if (pStyle != nullptr)
            {
                qRect2D<s32>    r = GetBorderRect();
                qPainter        p(this);

                pStyle->Draw(p, r, GetBorderEdges());
            }
        }
    } // qWin::OnPaintBorder


    /*******************************************************************************
    * qWin::OnPaintPaddingBg
    *******************************************************************************/
    void qWin::OnPaintPaddingBg()
    {
        qStyleFillBase   *pStyle = GetPaddingFillStyle();

        if (pStyle != nullptr)
        {
            qRect2D<s32>    r = GetPaddingRect();
            qPainter        p(this);

            pStyle->Draw(p, r);
        }
    } // qWin::OnPaintPaddingBg


    /*******************************************************************************
    * qWin::OnPaintContentBg
    *******************************************************************************/
    void qWin::OnPaintContentBg()
    {
        qStyleFillBase   *pStyle = GetContentFillStyle();

        if (pStyle != nullptr)
        {
            qRect2D<s32>    r = GetContentRect();
            qPainter        p(this);

            pStyle->Draw(p, r);
        }
    } // qWin::OnPaintContentBg


    /*******************************************************************************
    * qWin::OnPaintContent
    *******************************************************************************/
    void qWin::OnPaintContent()
    {
    } // qWin::OnPaintContent


    /*******************************************************************************
    * qWin::OnOsResize
    *******************************************************************************/
    void qWin::OnOsResize(const qDimension2D<s32>    &_oldSize,
                          const qDimension2D<s32>    &_newSize)
    {
        OnSysResize(_oldSize, _newSize);
        OnResize(_oldSize, _newSize);
    } // qWin::OnOsResize


    /*******************************************************************************
    * qWin::OnOsPaint
    *******************************************************************************/
    void qWin::OnOsPaint()
    {
        OnPaintMarginBg();
        OnPaintBorder();
        OnPaintPaddingBg();
        OnPaintContentBg();
        OnPaintContent();
    } // qWin::OnOsPaint


    /*******************************************************************************
    * qWin::OnOsEnter
    *******************************************************************************/
    bool qWin::OnOsEnter(u32                    _u32Modifiers,
                         const qVector2D<s32>   &_v2dLocal,
                         const qVector2D<s32>   &_v2dGlobal)
    {
        m_bHover = true;

        // set the cursor
        OnSetCursor();

        return ToolMgrOnEnter(_u32Modifiers, _v2dLocal, _v2dGlobal) ||
               OnEnter(_u32Modifiers, _v2dLocal, _v2dGlobal);
    } // qWin::OnOsEnter


    /*******************************************************************************
    * qWin::OnOsLeave
    *******************************************************************************/
    bool qWin::OnOsLeave(u32 _u32Modifiers)
    {
        m_bHover = false;

        return ToolMgrOnLeave(_u32Modifiers) ||
               OnLeave(_u32Modifiers);
    } // qWin::OnOsLeave


    /*******************************************************************************
    * qWin::OnOsWheel
    *******************************************************************************/
    bool qWin::OnOsWheel(u32                     _u32Modifiers,
                         s32                     _s32Degree,
                         const qVector2D<s32>    &_v2dLocal,
                         const qVector2D<s32>    &_v2dGlobal)
    {
        return ToolMgrOnWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal) ||
               OnWheel(_u32Modifiers, _s32Degree, _v2dLocal, _v2dGlobal);
    } // qWin::OnOsWheel


    /*******************************************************************************
    * qWin::OnOsDoubleClick
    *******************************************************************************/
    bool qWin::OnOsDoubleClick(u32                   _u32Modifiers,
                               u32                   _u32MouseButton,
                               const qVector2D<s32>  &_v2dLocal,
                               const qVector2D<s32>  &_v2dGlobal)
    {
        return ToolMgrOnDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal) ||
               OnDoubleClick(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
    } // qWin::OnOsDoubleClick


    /*******************************************************************************
    * qWin::OnOsMousePress
    *******************************************************************************/
    bool qWin::OnOsMousePress(u32                   _u32Modifiers,
                              u32                   _u32MouseButton,
                              const qVector2D<s32>  &_v2dLocal,
                              const qVector2D<s32>  &_v2dGlobal)
    {
        return ToolMgrOnMousePress(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal) ||
               OnMousePress(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
    } // qWin::OnOsMousePress


    /*******************************************************************************
    * qWin::OnOsMouseMove
    *******************************************************************************/
    bool qWin::OnOsMouseMove(u32                   _u32Modifiers,
                             u32                   _u32MouseButton,
                             const qVector2D<s32>  &_v2dLocal,
                             const qVector2D<s32>  &_v2dGlobal)
    {
        return ToolMgrOnMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal) ||
               OnMouseMove(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
    } // qWin::OnOsMouseMove


    /*******************************************************************************
    * qWin::OnOsMouseRelease
    *******************************************************************************/
    bool qWin::OnOsMouseRelease(u32                   _u32Modifiers,
                                u32                   _u32MouseButton,
                                const qVector2D<s32>  &_v2dLocal,
                                const qVector2D<s32>  &_v2dGlobal)
    {
        return ToolMgrOnMouseRelease(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal) ||
               OnMouseRelease(_u32Modifiers, _u32MouseButton, _v2dLocal, _v2dGlobal);
    } // qWin::OnOsMouseRelease


    /*******************************************************************************
    * qWin::OnOsDropUrl
    *******************************************************************************/
    void qWin::OnOsDropUrl(const qUrl  &_url)
    {
        OnDropUrl(_url);
    } // qWin::OnOsDropUrl

} // namespace qLib
