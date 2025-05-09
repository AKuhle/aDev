/*******************************************************************************
* \file CtrlPanel.cpp
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
#include "ctrlPanel.h"


/*******************************************************************************
* CtrlPanel::CtrlPanel
*******************************************************************************/
CtrlPanel::CtrlPanel(SysWin *_pParent /*= nullptr*/)
: aPlainWin(_pParent)
{
    #ifdef _USE_QT_
        m_pUi = new Ui::FormCtrlPanel;
        m_pUi->setupUi(this);
    #endif
} // CtrlPanel::CtrlPanel


/*******************************************************************************
* CtrlPanel::~CtrlPanel
*******************************************************************************/
CtrlPanel::~CtrlPanel()
{
    #ifdef _USE_QT_
        delete m_pUi;
    #endif
} // ~CtrlPanel::CtrlPanel


/*******************************************************************************
* CtrlPanel::onCreateWin
*******************************************************************************/
bool CtrlPanel::onCreateWin()
{
    return true;
} // CtrlPanel::onCreateWin


/*******************************************************************************
* CtrlPanel::onRegisterCtrl
*******************************************************************************/
void CtrlPanel::onRegisterCtrl()
{
    // registerCtrl(m_pUi->m_pZoomFit, ID_ZOOM_FIT, true);
    // registerCtrl(m_pUi->m_pZoom100pcnt, ID_ZOOM_100_PCNT, true);
    // registerCtrl(m_pUi->m_pZoom200pcnt, ID_ZOOM_200_PCNT, true);
} // CtrlPanel::onRegisterCtrl


/*******************************************************************************
* CtrlPanel::onUpdateCtrl
*******************************************************************************/
void CtrlPanel::onUpdateCtrl(aCtrlI */*_pCtrl*/)
{
    // ViewBase    *pView  = getActiveView();
    // bool        bView   = (pView != nullptr);

    // switch (_pCtrl->ctrlId())
    // {
    //     case ID_ZOOM_FIT:
    //     case ID_ZOOM_100_PCNT:
    //     case ID_ZOOM_200_PCNT:
    //         _pCtrl->setCtrlEnabled(bView);
    //         break;
    // } // switch
} // CtrlPanel::onUpdateCtrl


/*******************************************************************************
* CtrlPanel::onCtrlClicked
*******************************************************************************/
void CtrlPanel::onCtrlClicked(aCtrlI */*_pCtrl*/)
{
    // //shared_ptr<Document>    pDoc    = getActiveDoc();

    // switch (_pCtrl->ctrlId())
    // {
    //     case ID_ZOOM_FIT:
    //         setZoomFactorFit();
    //         break;

    //     case ID_ZOOM_100_PCNT:
    //         setZoomFactor(1);
    //         break;

    //     case ID_ZOOM_200_PCNT:
    //         setZoomFactor(2);
    //         break;
    // } // switch
} // CtrlPanel::onCtrlClicked
