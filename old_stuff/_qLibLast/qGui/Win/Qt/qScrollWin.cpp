/*******************************************************************************
* \file qScrollWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "qGuiDefs.h"
#include "qScrollWin.h"
#include "qDockWin.h"
#include "qString16.h"
#include "qScrollBar.h"
#include "qLog.h"


namespace qLib
{
    /*******************************************************************************
    * qScrollWin::qScrollWin
    *******************************************************************************/
    qScrollWin::qScrollWin(SysWin_t  *_pParent  /* = nullptr */)
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
        CHECK_PRE_CONDITION(qWin::OnSysCreate(), false);

        m_pHoriSb = new qScrollBar(enumOrientation::Horizontal, this);
        Register(m_pHoriSb, true, ID_HORI_SCROLLBAR);

        m_pVertSb = new qScrollBar(enumOrientation::Vertical, this);
        Register(m_pVertSb, true, ID_VERT_SCROLLBAR);

        return true;
    } // qScrollWin::OnSysCreate


    /*******************************************************************************
    * qScrollWin::SetCentralWin
    *******************************************************************************/
    void qScrollWin::SetCentralWin(SysWin_t *_pWin)
    {
        m_pCentralWin = _pWin;
        _pWin->setParent(this);
        _pWin->setVisible(true);

        ArrangeChilds();
    } // qScrollWin::SetCentralWin


    /*******************************************************************************
    * qScrollWin::CentralWin
    *******************************************************************************/
    SysWin_t* qScrollWin::CentralWin() const
    {
        return m_pCentralWin;
    } // qScrollWin::CentralWin


    /*******************************************************************************
    * qScrollWin::SetHoriSbRange
    *******************************************************************************/
    void qScrollWin::SetHoriSbRange(s32  _s32Min,
                                    s32  _s32Max)
    {
        m_pHoriSb->SetRange(_s32Min, _s32Max);
    } // qScrollWin::SetHoriSbRange


    /*******************************************************************************
    * qScrollWin::SetVertSbRange
    *******************************************************************************/
    void qScrollWin::SetVertSbRange(s32  _s32Min,
                                    s32  _s32Max)
    {
        m_pVertSb->SetRange(_s32Min, _s32Max);
    } // qScrollWin::SetVertSbRange


    /*******************************************************************************
    * qScrollWin::SetHoriSbPos
    *******************************************************************************/
    void qScrollWin::SetHoriSbPos(s32 _s32Pos)
    {
        m_pHoriSb->SetValue(_s32Pos);
    } // qScrollWin::SetHoriSbPos


    /*******************************************************************************
    * qScrollWin::SetVertSbPos
    *******************************************************************************/
    void qScrollWin::SetVertSbPos(s32 _s32Pos)
    {
        m_pVertSb->SetValue(_s32Pos);
    } // qScrollWin::SetVertSbPos


    /*******************************************************************************
    * qScrollWin::HoriSbPos
    *******************************************************************************/
    s32 qScrollWin::HoriSbPos() const
    {
        return m_pHoriSb->Value();
    } // qScrollWin::HoriSbPos


    /*******************************************************************************
    * qScrollWin::VertSbPos
    *******************************************************************************/
    s32 qScrollWin::VertSbPos() const
    {
        return m_pVertSb->Value();
    } // qScrollWin::VertSbPos


    /*******************************************************************************
    * qScrollWin::OnRegisterCtrl
    *******************************************************************************/
    void qScrollWin::OnRegisterCtrl()
    {
    } // qScrollWin::OnRegisterCtrl


    /*******************************************************************************
    * qScrollWin::OnUpdateCtrl
    *******************************************************************************/
    void qScrollWin::OnUpdateCtrl(qCtrlI */*_pCtrl*/)
    {
    } // qScrollWin::OnUpdateCtrl


    /*******************************************************************************
    * qScrollWin::OnCtrlMessage
    *******************************************************************************/
    void qScrollWin::OnCtrlMessage(qCtrlI    *_pCtrl,
                                   u32       _u32Mes,
                                   s64       /*_s64Value*/  /*= 0*/,
                                   void      */*_pVoid1*/   /*= nullptr*/,
                                   void      */*_pVoid2*/   /*= nullptr*/)
    {
        switch (_pCtrl->CtrlId())
        {
            case ID_HORI_SCROLLBAR:
                if (_u32Mes == MsgValueChanged)
                    OnHoriScroll(HoriSbPos());
                break;

            case ID_VERT_SCROLLBAR:
                if (_u32Mes == MsgValueChanged)
                    OnVertScroll(VertSbPos());
                break;
        } // switch (_u32Mes)
    } // qScrollWin::OnCtrlMessage


    /*******************************************************************************
    * qScrollWin::ArrangeChilds
    *******************************************************************************/
    void qScrollWin::ArrangeChilds()
    {
        qRect2D<s32>    r2dClient   = ClientRect();
        const s32       s32SbSize   = 12;
        bool            bHori       = m_pHoriSb->IsVisible();
        bool            bVert       = m_pVertSb->IsVisible();

        if (bHori)
        {
            m_pHoriSb->SetGeometry(r2dClient.l(),
                                   r2dClient.b1() - s32SbSize,
                                   r2dClient.w() - ((bVert)?   s32SbSize : 0),
                                   s32SbSize);
        }

        if (bVert)
        {
            m_pVertSb->SetGeometry(r2dClient.r() - s32SbSize,
                                   r2dClient.t(),
                                   s32SbSize,
                                   r2dClient.h() - ((bHori)?   s32SbSize : 0));
        }

        if (m_pCentralWin != nullptr)
        {
            m_pCentralWin->setGeometry(r2dClient.l(), r2dClient.t(),
                                       r2dClient.w() - ((bVert)?   s32SbSize : 0),
                                       r2dClient.h() - ((bHori)?   s32SbSize : 0));
        }
    } // qScrollWin::ArrangeChilds


    /*******************************************************************************
    * qScrollWin::OnSysResize
    *******************************************************************************/
    void qScrollWin::OnSysResize(const qDimension2D<s32>   &/*_d2dOld*/,
                                 const qDimension2D<s32>   &/*_d2dNew*/)
    {
        LogToDo("ToDo: Scrollbars are invisible after Maximize/Restore");

        //m_pHoriSb->SetParent(this);
        //m_pVertSb->SetParent(this);
        // m_pHoriSb->SetVisible(true);
        // m_pVertSb->SetVisible(true);

        ArrangeChilds();
    } // qScrollWin::OnSysResize
} // namespace qLib

#endif // _USE_QT_
