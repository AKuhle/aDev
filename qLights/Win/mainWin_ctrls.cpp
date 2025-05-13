/*******************************************************************************
* \file BaseApp.h
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
#include "qLights_defs.h"

#include "aCtrl.h"

#include "mainWin.h"
#include "ctrlPanel.h"


using namespace aLib::aWin;
using namespace std;


/*******************************************************************************
* MainWin::onRegisterCtrl
*******************************************************************************/
void MainWin::onRegisterCtrl()
{
    registerCtrl(m_pUi->m_pActionAddBank, ID_ADD_BANK);
    registerCtrl(m_pUi->m_pActionAddFixture, ID_ADD_FIXTURE);
} // MainWin::onRegisterCtrl


/*******************************************************************************
* MainWin::onUpdateCtrl
*******************************************************************************/
void MainWin::onUpdateCtrl(aCtrlI *_pCtrl)
{
    switch (_pCtrl->ctrlId())
    {
        // always ebabled
        case ID_ADD_BANK:
            _pCtrl->setCtrlEnabled(m_pCtrlPanel->bankCount() < BANK_COUNT);
            break;

        case ID_ADD_FIXTURE:
            //_pCtrl->ID_ADD_FIXTURE(!b);
            break;
    }
} // MainWin::onUpdateCtrl


/*******************************************************************************
* MainWin::onCtrlClicked
*******************************************************************************/
void MainWin::onCtrlClicked(aCtrlI *_pCtrl)
{
    switch (_pCtrl->ctrlId())
    {
        case ID_ADD_BANK:
        m_pCtrlPanel->addBank();;
            break;

        case ID_ADD_FIXTURE:
            m_pCtrlPanel->addFixture();
            break;
    }
} // MainWin::onCtrlClicked
