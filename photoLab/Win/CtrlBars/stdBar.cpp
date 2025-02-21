/*******************************************************************************
* \file StdBar.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "photoLab_defs.h"

#include "mainWin.h"
#include "stdBar.h"
#include "aToolButton.h"
#include "aLayoutHoriVert.h"


/*******************************************************************************
* StdBar::StdBar
*******************************************************************************/
StdBar::StdBar(aBaseWin     *_pParent   /*= nullptr*/)
: aCtrlBar(_pParent)
{
} // StdBar::StdBar


/*******************************************************************************
* StdBar::~StdBar
*******************************************************************************/
StdBar::~StdBar()
{
} // StdBar::~StdBar


/*******************************************************************************
* StdBar::onRegisterCtrl
*******************************************************************************/
void StdBar::onRegisterCtrl()
{
    // get the layout
    aLayoutHoriVert *pLayout    = layoutHoriVert();
    CHECK_PRE_CONDITION_VOID(pLayout != nullptr);

    MainWin         &mw         = getMainWin();
    aToolButton     *pBtn;

    pBtn = new aToolButton(this, ID_FILE_OPEN);
    pBtn->create();
    pBtn->setPixmap("Masked/file_open.png");
    pBtn->setFixedDim(22, 22);
    pLayout->addChild(pBtn);
    mw.registerCtrl(pBtn);

} // StdBar::onRegisterCtrl


/*******************************************************************************
* StdBar::onUpdateCtrl
*******************************************************************************/
void StdBar::onUpdateCtrl(aCtrl */*_pCtrl*/)
{

} // StdBar::onUpdateCtrl


/*******************************************************************************
* StdBar::onCtrlClicked
*******************************************************************************/
void StdBar::onCtrlClicked(aCtrl */*_pCtrl*/)
{
} // StdBar::onCtrlClicked
