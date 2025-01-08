/*******************************************************************************
* \file qScrollBar.inl
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
#include "qScrollBar.h"
#include "qLayoutHoriVert.h"
#include "qToolButton.h"
#include "qStyleBorderSolid.h"
#include "qSpacer.h"
#include "qScrollBarTool.h"
#include "qPainter.h"
#include "qPen.h"
#include "qBrush.h"

namespace qLib
{
    /*******************************************************************************
    * qScrollBar::qScrollBar
    *******************************************************************************/
    qScrollBar::qScrollBar(qWin             *_pParent,
                           u32              _u32Id,
                           enumOrientation  _eOrientation)
    : qCtrlBase(_pParent, _u32Id),
      m_eOrientation(_eOrientation)
	{
    } // qScrollBar::qScrollBar


    /*******************************************************************************
    * qScrollBar::~qScrollBar
    *******************************************************************************/
    qScrollBar::~qScrollBar()
	{
    } // qScrollBar::~qScrollBar


    /*******************************************************************************
    * qScrollBar::OnSysCreate
    *******************************************************************************/
    bool qScrollBar::OnSysCreate()
    {
        // enable mouse tracking for border resize
        SetMouseTracking(true);

        // start the scrollbar tool
        unique_ptr<qScrollBarTool> pTool = make_unique<qScrollBarTool> (this);
        SetTool(std::move(pTool));

        return true;
    } // qScrollBar::OnSysCreate


    /*******************************************************************************
    * qScrollBar::OnRegisterCtrl
    *******************************************************************************/
    void qScrollBar::OnRegisterCtrl()
    {
        qSpacer     *pSpacer;

        // the buttons must fit within the scrollbar
        qDimension2D<s32>     dimBtn = GetMinSize();
        dimBtn.w -= GetBorderEdges().w();
        dimBtn.h -= GetBorderEdges().h();

        // create the layout
        unique_ptr<qLayoutHoriVert> pLayout = make_unique<qLayoutHoriVert> ();
        pLayout->SetOrientation(m_eOrientation);

        // add the line decrement button
        m_pBtnDec = new qToolButton(this, ID_SCROLLBAR_LINE_DEC);
        m_pBtnDec->CreateWin();
        m_pBtnDec->SetFixedSize(dimBtn);
        m_pBtnDec->SetPixmap((m_eOrientation == enumOrientation::Hori)?   "Masked/scrollBarLeft.png" : "Masked/scrollBarUp.png");
        m_pBtnDec->SetBorderEdges(1);
        m_pBtnDec->SetBorderStyle(make_unique<qStyleBorderSolid> (GetFrameDark2Color()));
        m_pBtnDec->SetButtonStyle(enumButtonStyle::MASKED_MODE);
        pLayout->AddChild(m_pBtnDec);
        Register(m_pBtnDec);

        // add the qSpacer
        pSpacer = new qSpacer(this);
        pSpacer->CreateWin();
        pSpacer->SetOrientation(m_eOrientation);
        pLayout->AddChild(pSpacer);

        // add the line increment button
        m_pBtnInc = new qToolButton(this, ID_SCROLLBAR_LINE_INC);
        m_pBtnInc->CreateWin();
        m_pBtnInc->SetFixedSize(dimBtn);
        m_pBtnInc->SetPixmap((m_eOrientation == enumOrientation::Hori)?   "Masked/scrollBarRight.png" : "Masked/scrollBarDown.png");
        m_pBtnInc->SetBorderEdges(1);
        m_pBtnInc->SetBorderStyle(make_unique<qStyleBorderSolid> (GetFrameDark2Color()));
        m_pBtnInc->SetButtonStyle(enumButtonStyle::MASKED_MODE);
        pLayout->AddChild(m_pBtnInc);
        Register(m_pBtnInc);

        // move the layout to the base class
        SetLayout(std::move(pLayout));
    } // qScrollBar::OnRegisterCtrl


    /*******************************************************************************
    * qScrollBar::OnUpdateCtrl
    *******************************************************************************/
    void qScrollBar::OnUpdateCtrl(qCtrlBase */*_pCtrl*/)
    {
    } // qScrollBar::OnUpdateCtrl


    /*******************************************************************************
    * qScrollBar::OnCtrlClicked
    *******************************************************************************/
    void qScrollBar::OnCtrlClicked(qCtrlBase *_pCtrl)
    {
        switch (_pCtrl->GetCtrlId())
        {
            case ID_SCROLLBAR_LINE_DEC:
                if (SetValue(m_s32Value - m_s32LineStep) && GetCtrlMgr() != nullptr)
                {
                    GetCtrlMgr()->SendCtrlMessage(this, MSG_VALUE_CHANGED);
                }
                break;

            case ID_SCROLLBAR_LINE_INC:
                if (SetValue(m_s32Value + m_s32LineStep) && GetCtrlMgr() != nullptr)
                {
                    GetCtrlMgr()->SendCtrlMessage(this, MSG_VALUE_CHANGED);
                }
                break;
        }
    } // qScrollBar::OnCtrlClicked


    /*******************************************************************************
    * qScrollBar::OnToolMsg
    *******************************************************************************/
    void qScrollBar::OnToolMsg(qToolBase */*_pTool*/,
                               u32       _u32Msg,
                               s32       _s32Param,
                               u32       /*_u32Param*/,
                               s64       /*_s64Param*/,
                               u64       /*_u64Param*/,
                               flt       /*_fltParam*/,
                               dbl       /*_dblParam*/)
    {
        switch (_u32Msg)
        {
            case MSG_PAGE_DEC:
                if (SetValue(m_s32Value - GetPageStep()) && GetCtrlMgr() != nullptr)
                {
                    GetCtrlMgr()->SendCtrlMessage(this, MSG_VALUE_CHANGED);
                }
                break;

            case MSG_PAGE_INC:
                if (SetValue(m_s32Value + GetPageStep()) && GetCtrlMgr() != nullptr)
                {
                    GetCtrlMgr()->SendCtrlMessage(this, MSG_VALUE_CHANGED);
                }
                break;

            case MSG_SLIDER_POS_MOVED:
                // no trackiong => only slider update, no message send to CtrlMgr
                // trackiong => only slider update and message send to CtrlMgr
                if (SetValue(Pos2Value(_s32Param)) && IsTracking() && GetCtrlMgr() != nullptr)
                {
                    GetCtrlMgr()->SendCtrlMessage(this, MSG_VALUE_CHANGED);
                }
                break;

            case MSG_SLIDER_POS_SET:
                SetValue(Pos2Value(_s32Param));
                if (GetCtrlMgr() != nullptr)
                {
                    GetCtrlMgr()->SendCtrlMessage(this, MSG_VALUE_CHANGED);
                }
                break;
        }
    } // qScrollBar::OnToolMsg


    /*******************************************************************************
    * qScrollBar::SetRange
    *******************************************************************************/
    void qScrollBar::SetRange(s32 _s32MinValue,
                              s32 _s32MaxValue)
    {
        if (_s32MinValue != m_s32MinValue ||
            _s32MaxValue != m_s32MaxValue)
        {
            m_s32MinValue = _s32MinValue;
            m_s32MaxValue = _s32MaxValue;

            // check, whether the current value is within the new range
            m_s32Value = MU<s32>::Clamp(m_s32Value, m_s32MinValue, m_s32MaxValue);
            UpdateSlider();
        }
    } // qScrollBar::SetRange


    /*******************************************************************************
    * qScrollBar::SetRange
    *******************************************************************************/
    void qScrollBar::SetRange(const qInterval2D<s32> &_rhs)
    {
        if (_rhs.min != m_s32MinValue ||
            _rhs.max != m_s32MaxValue)
        {
            m_s32MinValue = _rhs.min;
            m_s32MaxValue = _rhs.max;

            // check, whether the current value is within the new range
            m_s32Value = MU<s32>::Clamp(m_s32Value, m_s32MinValue, m_s32MaxValue);
            UpdateSlider();
        }
    } // qScrollBar::SetRange


    /*******************************************************************************
    * qScrollBar::GetRange
    *******************************************************************************/
    qInterval2D<s32> qScrollBar::GetRange() const
    {
        return qInterval2D<s32> (m_s32MinValue, m_s32MaxValue);
    } // qScrollBar::GetRange


    /*******************************************************************************
    * qScrollBar::GetMinValue
    *******************************************************************************/
    s32 qScrollBar::GetMinValue() const
    {
        return m_s32MinValue;
    } // qScrollBar::GetMinValue


    /*******************************************************************************
    * qScrollBar::GetMaxValue
    *******************************************************************************/
    s32 qScrollBar::GetMaxValue() const
    {
        return m_s32MaxValue;
    } // qScrollBar::GetMaxValue


    /*******************************************************************************
    * qScrollBar::SetValue
    *******************************************************************************/
    bool qScrollBar::SetValue(s32 _s32Value)
    {
        s32 s32NewValue = MU<s32>::Clamp(_s32Value, m_s32MinValue, m_s32MaxValue);

        if (m_s32Value != s32NewValue)
        {
            m_s32Value = s32NewValue;
            UpdateSlider();

            return true;
        }

        return false;
    } // qScrollBar::SetValue


    /*******************************************************************************
    * qScrollBar::GetValue
    *******************************************************************************/
    s32 qScrollBar::GetValue() const
    {
        return m_s32Value;
    } // qScrollBar::GetValue


    /*******************************************************************************
    * qScrollBar::GetOrientation
    *******************************************************************************/
    enumOrientation qScrollBar::GetOrientation() const
    {
        return m_eOrientation;
    } // qScrollBar::GetOrientation


    /*******************************************************************************
    * qScrollBar::GetSlideArea
    *******************************************************************************/
    qRect2D<s32> qScrollBar::GetSlideArea() const
    {
        qRect2D<s32>    r2dContent  = GetContentRect();
        bool            bH          = (m_eOrientation == enumOrientation::Hori);

        return qRect2D<s32>((bH)?   r2dContent.x + m_pBtnDec->w() + 1 : r2dContent.x,
                            (bH)?   r2dContent.y : r2dContent.y + m_pBtnDec->h() + 1,
                            (bH)?   r2dContent.w - m_pBtnDec->w() - m_pBtnInc->w() - 2 : r2dContent.w,
                            (bH)?   r2dContent.h : r2dContent.h - m_pBtnDec->h() - m_pBtnInc->h() - 2);
    } // qScrollBar::GetSlideArea


    /*******************************************************************************
    * qScrollBar::GetSliderRect
    *******************************************************************************/
    qRect2D<s32> qScrollBar::GetSliderRect() const
    {
        qRect2D<s32>    r2dContent  = GetContentRect();
        qRect2D<s32>    r2dSlider;

        if (m_eOrientation == enumOrientation::Hori)
        {
            r2dSlider.Set(m_s32Pos, r2dContent.y, m_s32SliderSize, r2dContent.h);
        }
        else
        {
            r2dSlider.Set(r2dContent.x, m_s32Pos, r2dContent.w, m_s32SliderSize);
        }

        return r2dSlider;

    } // qScrollBar::GetSliderRect


    /*******************************************************************************
    * qScrollBar::GetPos
    *******************************************************************************/
    s32 qScrollBar::GetPos() const
    {
        return m_s32Pos;
    } // qScrollBar::GetPos


    /*******************************************************************************
    * qScrollBar::Pos2Value
    *******************************************************************************/
    s32 qScrollBar::Pos2Value(s32 _s32Pos) const
    {
        qRect2D<s32>    a   = GetSlideArea();
        bool            bHori   = (m_eOrientation == enumOrientation::Hori);

        qTransform<s32, s32>    t((bHori)?   a.l() : a.t(),
                                  (bHori)?   a.r() - m_s32SliderSize : a.b() - m_s32SliderSize,
                                  m_s32MinValue,
                                  m_s32MaxValue);

        return t.Src2Dst(_s32Pos, true);
    } // qScrollBar::Pos2Value


    /*******************************************************************************
    * qScrollBar::Value2Pos
    *******************************************************************************/
    s32 qScrollBar::Value2Pos(s32 _s32Value) const
    {
        qRect2D<s32>    a   = GetSlideArea();
        bool            bHori   = (m_eOrientation == enumOrientation::Hori);

        qTransform<s32, s32>    t(m_s32MinValue,
                                  m_s32MaxValue,
                                  (bHori)?   a.l() : a.t(),
                                  (bHori)?   a.r() - m_s32SliderSize : a.b() - m_s32SliderSize);

        return t.Src2Dst(_s32Value, true);
    } // qScrollBar::Value2Pos


    /*******************************************************************************
    * qScrollBar::UpdateSlider
    *******************************************************************************/
    void qScrollBar::UpdateSlider()
    {
        m_s32Pos = Value2Pos(m_s32Value);

        Repaint();
    } // qScrollBar::UpdateSlider


    /*******************************************************************************
    * qScrollBar::OnSysResize
    *******************************************************************************/
    void qScrollBar::OnSysResize(const qDimension2D<s32>    &_oldSize,
                                 const qDimension2D<s32>    &_newSize)
    {
        qCtrlBase::OnSysResize(_oldSize, _newSize);

        UpdateSlider();
    } // qScrollBar::OnSysResize


    /*******************************************************************************
    * qScrollBar::OnPaintContent
    *******************************************************************************/
    void qScrollBar::OnPaintContent()
    {
        CHECK_PRE_CONDITION_VOID(m_pBtnDec != nullptr);
        CHECK_PRE_CONDITION_VOID(m_pBtnInc != nullptr);

        qRect2D<s32>    r2dContent  = GetContentRect();
        qPainter        p(this);
        qPen            penBorder(GetFrameDark2Color());
        qBrush          brushSlider(GetWinColor());

        if (m_eOrientation == enumOrientation::Hori)
        {
            p.DrawRect(m_s32Pos, r2dContent.y, m_s32SliderSize, r2dContent.h, &penBorder);
            p.DrawFilledRect(m_s32Pos+1, r2dContent.y+1, m_s32SliderSize-2, r2dContent.h-2, &brushSlider);
        }
        else
        {
            p.DrawRect(r2dContent.x, m_s32Pos, r2dContent.w, m_s32SliderSize, &penBorder);
            p.DrawFilledRect(r2dContent.x+1, m_s32Pos+1, r2dContent.w-2, m_s32SliderSize-2, &brushSlider);
        }
    } // qScrollBar::OnPaintContent

} // namespace qLib
