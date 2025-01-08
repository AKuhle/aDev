/*******************************************************************************
* \file qScrollWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qScrollWin.h"
#include "qLayoutScrollWin.h"
#include "qScrollBar.h"


namespace qLib
{
    /*******************************************************************************
    * qScrollWin::qScrollWin
    *******************************************************************************/
    qScrollWin::qScrollWin(qWin  *_pParent  /* = nullptr */)
    : qWin(_pParent)
    {
    } // qScrollWin::qScrollWin


    /*******************************************************************************
    * qScrollWin::~qScrollWin
    *******************************************************************************/
    qScrollWin::~qScrollWin()
    {
    } // qScrollWin::~qScrollWin


    /*******************************************************************************
    * qScrollWin::OnSysCreate
    *******************************************************************************/
    bool qScrollWin::OnSysCreate()
    {
        // create the layout
        unique_ptr<qLayoutScrollWin> pLayout = make_unique<qLayoutScrollWin> ();

        // add the vertical scrollbar
        m_pHori = new qScrollBar(this, ID_SCROLLBAR_HORI, enumOrientation::Hori);
        m_pHori->CreateWin();
        pLayout->SetHoriSb(m_pHori);
        Register(m_pHori);

        // add the vertical scrollbar
        m_pVert = new qScrollBar(this, ID_SCROLLBAR_VERT, enumOrientation::Vert);
        m_pVert->CreateWin();
        pLayout->SetVertSb(m_pVert);
        Register(m_pVert);

        SetLayout(std::move(pLayout));

        return true;
    } // qScrollWin::OnSysCreate


    /*******************************************************************************
    * qScrollWin::OnClose
    *******************************************************************************/
    bool qScrollWin::OnClose()
    {
        // todo: really close?

        m_pHori->CloseWin();
        m_pVert->CloseWin();

        return true;
    } // qScrollWin::OnClose


    /*******************************************************************************
    * qScrollWin::GetCenterWin
    *******************************************************************************/
    qWin* qScrollWin::GetCenterWin() const
    {
        qLayoutScrollWin  *pLayout = dynamic_cast<qLayoutScrollWin *> (GetLayout());
        CHECK_PRE_CONDITION(pLayout != nullptr, nullptr);

        return pLayout->GetCenterWin();
    } // qScrollWin::GetCenterWin


    /*******************************************************************************
    * qScrollWin::SetCenterWin
    *******************************************************************************/
    void qScrollWin::SetCenterWin(qWin *_pWin)
    {
        qLayoutScrollWin  *pLayout = dynamic_cast<qLayoutScrollWin *> (GetLayout());
        CHECK_PRE_CONDITION_VOID(pLayout != nullptr);

        _pWin->SetParent(this);

        pLayout->SetCenterWin(_pWin);
    } // qScrollWin::SetCenterWin


    /*******************************************************************************
    * qScrollWin::EnableTracking
    *******************************************************************************/
    void qScrollWin::EnableTracking(bool _bTracking)
    {
        m_pHori->SetTracking(_bTracking);
        m_pVert->SetTracking(_bTracking);
    } // qScrollWin::EnableTracking


    /*******************************************************************************
    * qScrollWin::SetHoriVisible
    *******************************************************************************/
    void qScrollWin::SetHoriVisible(bool _bVisible)
    {
        m_pHori->SetVisible(_bVisible);
    } // qScrollWin::SetHoriVisible


    /*******************************************************************************
    * qScrollWin::SetHoriRange
    *******************************************************************************/
    void qScrollWin::SetHoriRange(s32 _s32MinValue,
                                  s32 _s32MaxValue)
    {
        m_pHori->SetRange(_s32MinValue, _s32MaxValue);
    } // qScrollWin::SetHoriRange


    /*******************************************************************************
    * qScrollWin::SetHoriPageStep
    *******************************************************************************/
    void qScrollWin::SetHoriPageStep(s32 _s32Step)
    {
        m_pHori->SetPageStep(_s32Step);
    } // qScrollWin::SetHoriPageStep


    /*******************************************************************************
    * qScrollWin::SetHoriValue
    *******************************************************************************/
    void qScrollWin::SetHoriValue(s32 _s32Value)
    {
        m_pHori->SetValue(_s32Value);
    } // qScrollWin::SetHoriValue


    /*******************************************************************************
    * qScrollWin::GetHoriValue
    *******************************************************************************/
    s32 qScrollWin::GetHoriValue() const
    {
        return m_pHori->GetValue();
    } // qScrollWin::GetHoriValue


    /*******************************************************************************
    * qScrollWin::SetVertVisible
    *******************************************************************************/
    void qScrollWin::SetVertVisible(bool _bVisible)
    {
        m_pVert->SetVisible(_bVisible);
    } // qScrollWin::SetVertVisible


    /*******************************************************************************
    * qScrollWin::SetVertRange
    *******************************************************************************/
    void qScrollWin::SetVertRange(s32 _s32MinValue,
                                  s32 _s32MaxValue)
    {
        m_pVert->SetRange(_s32MinValue, _s32MaxValue);
    } // qScrollWin::SetVertRange


    /*******************************************************************************
    * qScrollWin::SetVertPageStep
    *******************************************************************************/
    void qScrollWin::SetVertPageStep(s32 _s32Step)
    {
        m_pVert->SetPageStep(_s32Step);
    } // qScrollWin::SetVertPageStep


    /*******************************************************************************
    * qScrollWin::SetVertValue
    *******************************************************************************/
    void qScrollWin::SetVertValue(s32 _s32Value)
    {
        m_pVert->SetValue(_s32Value);
    } // qScrollWin::SetVertValue


    /*******************************************************************************
    * qScrollWin::GetVertValue
    *******************************************************************************/
    s32 qScrollWin::GetVertValue() const
    {
        return m_pVert->GetValue();
    } // qScrollWin::GetVertValue


    /*******************************************************************************
    * qScrollWin::SetHoriVertVisible
    *******************************************************************************/
    void qScrollWin::SetHoriVertVisible(bool _bHoriVisible,
                                        bool _bVertVisible)
    {
        m_pHori->SetVisible(_bHoriVisible);
        m_pVert->SetVisible(_bVertVisible);
    } // qScrollWin::SetHoriVertVisible


    /*******************************************************************************
    * qScrollWin::OnHoriChanged
    *******************************************************************************/
    void qScrollWin::OnHoriChanged(s32 /*_s32Value*/)
    {
    } // qScrollWin::OnHoriChanged


    /*******************************************************************************
    * qScrollWin::OnVertChanged
    *******************************************************************************/
    void qScrollWin::OnVertChanged(s32 /*_s32Value*/)
    {
    } // qScrollWin::OnVertChanged


    /*******************************************************************************
    * qScrollWin::OnRegisterCtrl
    *******************************************************************************/
    void qScrollWin::OnRegisterCtrl()
    {
    } // qScrollWin::OnRegisterCtrl


    /*******************************************************************************
    * qScrollWin::OnUpdateCtrl
    *******************************************************************************/
    void qScrollWin::OnUpdateCtrl(qCtrlBase */*_pCtrl*/)
    {
    } // qScrollWin::OnUpdateCtrl


    /*******************************************************************************
    * qScrollWin::OnCtrlValueChanged
    *******************************************************************************/
    void qScrollWin::OnCtrlValueChanged(qCtrlBase    *_pCtrl)
    {
        switch (_pCtrl->GetCtrlId())
        {
            case ID_SCROLLBAR_HORI:
                OnHoriChanged((dynamic_cast<qScrollBar *> (_pCtrl))->GetValue());
                break;

            case ID_SCROLLBAR_VERT:
                OnVertChanged((dynamic_cast<qScrollBar *> (_pCtrl))->GetValue());
                break;
        }
    } // qScrollWin::OnCtrlValueChanged

} // namespace qLib
