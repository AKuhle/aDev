/*******************************************************************************
* \file aToolButton.cpp
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
#include "aToolButton.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aToolButton::aToolButton
*******************************************************************************/
aToolButton::aToolButton(SysWin *_pParent)
: aButton<QToolButton>(_pParent)
{
    // connect the handlers
    connect(this, SIGNAL(clicked(bool)),
            this, SLOT(slotClicked(bool)));
} // aToolButton::_isVisible


/*******************************************************************************
* aToolButton::~aToolButton
*******************************************************************************/
aToolButton::~aToolButton()
{
} // aToolButton::~aToolButton


/*******************************************************************************
* aToolButton::slotClicked
*******************************************************************************/
void aToolButton::slotClicked(bool /*_bChecked*/)
{
    //Control2VarPool();

    if (ctrlMgr() != nullptr)
    {
        ctrlMgr()->sendCtrlMessage(this, MSG_CLICKED);
    }
} // aToolButton::slotClicked


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
