/*******************************************************************************
* \file aAction.inl
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
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include <QPalette>

#include "aAction.h"
#include "aCtrlMgr.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aAction::aAction
*******************************************************************************/
aAction::aAction(QAction *_pAction)
: m_pAction(_pAction)
{
    // connect the handlers
    connect(m_pAction, SIGNAL(triggered(bool)),
            this, SLOT(slotTriggered(bool)));
} // aAction::aAction


/*******************************************************************************
* aAction::~aActionW
*******************************************************************************/
aAction::~aAction()
{
} // aAction::~aAction


/*******************************************************************************
* aAction::setCtrlId
*******************************************************************************/
void aAction::setCtrlId(s32 _s32CtrlID)
{
    m_s32CtrlID = _s32CtrlID;
} // aAction::setCtrlId


/*******************************************************************************
* aAction::ctrlId
*******************************************************************************/
s32 aAction::ctrlId() const
{
    return m_s32CtrlID;
} // aAction::ctrlId


/*******************************************************************************
* aAction::setCtrlMgr
*******************************************************************************/
void aAction::setCtrlMgr(aCtrlMgr *_pCtrlMgr)
{
    m_pCtrlMgr = _pCtrlMgr;
} // aAction::setCtrlMgr


/*******************************************************************************
* aAction::ctrlMgr
*******************************************************************************/
aCtrlMgr* aAction::ctrlMgr() const
{
    return m_pCtrlMgr;
} // aAction::ctrlMgr


/*******************************************************************************
* aAction::setCtrlEnabled
*******************************************************************************/
void aAction::setCtrlEnabled(bool _bEnabled)
{
    m_pAction->setEnabled(_bEnabled);
} // aAction::setCtrlEnabled


/*******************************************************************************
* aAction::ctrlEnabled
*******************************************************************************/
bool aAction::ctrlEnabled() const
{
    return m_pAction->isEnabled();
} // qlaAction::ctrlEnabled


/*******************************************************************************
* aAction::setCtrlChecked
*******************************************************************************/
void aAction::setCtrlChecked(bool _bChecked)
{
    m_pAction->setChecked(_bChecked);
} // aAction::setCtrlChecked


/*******************************************************************************
* aAction::setCtrlEnabledChecked
*******************************************************************************/
void aAction::setCtrlEnabledChecked(bool _bEnabled,
                                       bool _bChecked)
{
    m_pAction->setEnabled(_bEnabled);
    m_pAction->setChecked(_bChecked);
} // aAction::setCtrlEnabledChecked


/*******************************************************************************
* aAction::ctrlChecked
*******************************************************************************/
bool aAction::ctrlChecked() const
{
    return m_pAction->isChecked();
} // aAction::ctrlChecked


/*******************************************************************************
* aAction::ctrlEnabled
*******************************************************************************/
void aAction::setBackgroundColor(const aColor &/*_color*/)
{
} // aAction::setBackgroundColor


/*******************************************************************************
* aAction::ctrlEnabled
*******************************************************************************/
aColor aAction::backgroundColor() const
{
    return colBlack;
} // aAction::backgroundColor


/*******************************************************************************
* aAction::slotTriggered
*******************************************************************************/
void aAction::slotTriggered(bool /*_bChecked*/)
{
    //Control2VarPool();

    if (m_pCtrlMgr != nullptr)
    {
        m_pCtrlMgr->sendCtrlMessage(this, MSG_CLICKED);
    }
} // aAction::slotTriggered


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
