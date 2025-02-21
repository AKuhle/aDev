/*******************************************************************************
* \file StatusBar.cpp
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

#include "statusBar.h"
#include "aLayoutHoriVert.h"


/*******************************************************************************
* StatusBar::StatusBar
*******************************************************************************/
StatusBar::StatusBar(aBaseWin     *_pParent   /*= nullptr*/)
: aStatusBar(_pParent)
{
} // StatusBar::StatusBar


/*******************************************************************************
* StatusBar::~StatusBar
*******************************************************************************/
StatusBar::~StatusBar()
{
} // StatusBar::~StatusBar


/*******************************************************************************
* StatusBar::clearCoordinates
*******************************************************************************/
void StatusBar::clearCoordinates() const
{
    CHECK_PRE_CONDITION_VOID(m_pCoordinatesLabel != nullptr);

    m_pCoordinatesLabel->setText("");
} // StatusBar::clearCoordinates


/*******************************************************************************
* StatusBar::updateCoordinates
*******************************************************************************/
void StatusBar::updateCoordinates(s32   _x,
                                  s32   _y) const
{
    CHECK_PRE_CONDITION_VOID(m_pCoordinatesLabel != nullptr);

    aString s = aString("x:") + aString::fromValue(_x) + ", y:" + aString::fromValue(_y);
    m_pCoordinatesLabel->setText(s);
} // StatusBar::updateCoordinates


/*******************************************************************************
* StatusBar::onRegisterCtrl
*******************************************************************************/
void StatusBar::onRegisterCtrl()
{
    // get the layout
    aLayoutHoriVert *pLayout    = layoutHoriVert();
    CHECK_PRE_CONDITION_VOID(pLayout != nullptr);

    // create the coordinate label
    m_pCoordinatesLabel = new aLabel(this);
    m_pCoordinatesLabel->create();
    m_pCoordinatesLabel->distance().set(1, 1, 2, 2);
    m_pCoordinatesLabel->setFixedDim(100, 22);
    m_pCoordinatesLabel->setAlignment(enumAlignmentHori::AlignLeft, enumAlignmentVert::AlignVCenter);
    pLayout->addChild(m_pCoordinatesLabel);

    // create the progress bar
    m_pProgressCtrl = new aProgressCtrl(this);
    m_pProgressCtrl->create();
    m_pProgressCtrl->distance().set(1, 1, 2, 2);
    m_pProgressCtrl->setMinDim(100, 22);
    m_pProgressCtrl->setMaxDim(200, 22);
    pLayout->addChild(m_pProgressCtrl);
} // StatusBar::onRegisterCtrl


/*******************************************************************************
* StatusBar::onUpdateCtrl
*******************************************************************************/
void StatusBar::onUpdateCtrl(aCtrl */*_pCtrl*/)
{

} // StatusBar::onUpdateCtrl


/*******************************************************************************
* StatusBar::onCtrlClicked
*******************************************************************************/
void StatusBar::onCtrlClicked(aCtrl */*_pCtrl*/)
{
} // StatusBar::onCtrlClicked


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
    m_pProgressCtrl->setProgress(0);
} // StatusBar::onCloseProgressDisplay


/*******************************************************************************
* StatusBar::onUpdateProgressDisplay
*******************************************************************************/
void StatusBar::onUpdateProgressDisplay(const aString &/*_sInfoText*/)
{
} // StatusBar::onUpdateProgressDisplay


/*******************************************************************************
* StatusBar::onUpdateProgressDisplay
*******************************************************************************/
void StatusBar::onUpdateProgressDisplay(u16 _u16Progress_pml)
{
    CHECK_PRE_CONDITION_VOID(m_pProgressCtrl != nullptr);

    m_pProgressCtrl->setProgress(_u16Progress_pml);
} // StatusBar::onUpdateProgressDisplay
