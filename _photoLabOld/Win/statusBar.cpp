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
#include "statusBar.h"
#include "aProgressBar.h"
#include "aString.h"


/*******************************************************************************
* StatusBar::StatusBar
*******************************************************************************/
StatusBar::StatusBar(SysWin *pParent /*= nullptr*/)
: aStatusBar(pParent)
{
} // StatusBar::StatusBar


/*******************************************************************************
* StatusBar::~StatusBar
*******************************************************************************/
StatusBar::~StatusBar()
{
} // StatusBar::~StatusBar


/*******************************************************************************
* StatusBar::onCreateWin
*******************************************************************************/
bool StatusBar::onCreateWin()
{
    m_pProgressBar = new aProgressBar(this);
    m_pProgressBar->createWin();
    m_pProgressBar->setFixedWidth(200);
    m_pProgressBar->setRange(0, 1000);
    addChild(m_pProgressBar);

    return true;
} // StatusBar::onCreateWin


/*******************************************************************************
* StatusBar::onOpenProgressDisplay
*******************************************************************************/
void StatusBar::onOpenProgressDisplay()
{
} // StatusBar::onOpenProgressDisplay


/*******************************************************************************
* StatusBar::onCloseProgressDisplay
*******************************************************************************/
void StatusBar::onCloseProgressDisplay()
{
    m_pProgressBar->reset();
} // StatusBar::onCloseProgressDisplay


/*******************************************************************************
* StatusBar::onUpdateProgressDisplay
*******************************************************************************/
void StatusBar::onUpdateProgressDisplay(const aString &_sInfoText)
{
    m_pProgressBar->setInfo(_sInfoText);
} // StatusBar::onUpdateProgressDisplay


/*******************************************************************************
* StatusBar::onUpdateProgressDisplay
*******************************************************************************/
void StatusBar::onUpdateProgressDisplay(u16 _u16Progress_pml)
{
    m_pProgressBar->setValue(_u16Progress_pml);
} // StatusBar::onUpdateProgressDisplay
