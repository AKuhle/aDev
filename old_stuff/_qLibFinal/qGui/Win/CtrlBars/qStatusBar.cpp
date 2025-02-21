/*******************************************************************************
* \file qStatusBar.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qStatusBar.h"


namespace qLib
{
    /*******************************************************************************
    * qStatusBar::qStatusBar
    *******************************************************************************/
    qStatusBar::qStatusBar(qWin  *_pParent  /* = nullptr */)
    : qCtrlBar(_pParent)
    {
    } // qStatusBar::qStatusBar


    /*******************************************************************************
    * qStatusBar::~qStatusBar
    *******************************************************************************/
    qStatusBar::~qStatusBar()
    {
    } // qStatusBar::~qStatusBar


    /*******************************************************************************
    * qStatusBar::OnRegisterCtrl
    *******************************************************************************/
    void qStatusBar::OnRegisterCtrl()
    {
    } // qStatusBar::OnRegisterCtrl


    /*******************************************************************************
    * qStatusBar::OnUpdateCtrl
    *******************************************************************************/
    void qStatusBar::OnUpdateCtrl(qCtrlBase */*_pCtrl*/)
    {

    } // qStatusBar::OnUpdateCtrl

} // namespace qLib
