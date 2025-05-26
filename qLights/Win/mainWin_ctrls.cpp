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
    registerCtrl(m_pUi->m_pActionSaveScene, ID_SAVE_SCENE);
    registerCtrl(m_pUi->m_pActionResetAll, ID_RESET_ALL);
} // MainWin::onRegisterCtrl


/*******************************************************************************
* MainWin::onUpdateCtrl
*******************************************************************************/
void MainWin::onUpdateCtrl(aCtrlI */*_pCtrl*/)
{
    // switch (_pCtrl->ctrlId())
    // {
    //     // always ebabled
    //     case ID_ADD_BANK:
    //         _pCtrl->setCtrlEnabled(m_pCtrlPanel->bankCount() < BANK_COUNT);
    //         break;

    //     case ID_ADD_FIXTURE:
    //         //_pCtrl->ID_ADD_FIXTURE(!b);
    //         break;
    // }
} // MainWin::onUpdateCtrl


/*******************************************************************************
* MainWin::onCtrlClicked
*******************************************************************************/
void MainWin::onCtrlClicked(aCtrlI *_pCtrl)
{
    switch (_pCtrl->ctrlId())
    {
        case ID_SAVE_SCENE:
            if (m_eWorkMode == enumWorkMode::Play)
                m_eWorkMode = enumWorkMode::SaveScene;
            else
                m_eWorkMode = enumWorkMode::Play;

            sendUpdateCmd(UPDATE_GUI);
            break;

        case ID_RESET_ALL:
            sendUpdateCmd(UPDATE_RESET_ALL);
            break;
    }
} // MainWin::onCtrlClicked
