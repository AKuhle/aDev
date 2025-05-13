/*******************************************************************************
* \file aScrollBar.cpp
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
#include "aScrollBar.h"
#include "aString.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aScrollBar::aScrollBar
*******************************************************************************/
aScrollBar::aScrollBar(SysWin *_pParent /*=nullptr*/)
: aCtrl<QScrollBar>(_pParent)
{
    // connect the handlers
    connect(this, SIGNAL(valueChanged(int)),
            this, SLOT(slotValueChanged(int)));
} // aScrollBar::_isVisible


/*******************************************************************************
* aScrollBar::~aScrollBar
*******************************************************************************/
aScrollBar::~aScrollBar()
{
} // aScrollBar::~aScrollBar


/*******************************************************************************
* aScrollBar::setRange
*******************************************************************************/
void aScrollBar::setRange(s32    _s32Min,
                          s32    _s32Max)
{
    QScrollBar::setRange(_s32Min, _s32Max);
} // aScrollBar::setRange


/*******************************************************************************
* aScrollBar::setValue
*******************************************************************************/
void aScrollBar::setValue(s32 s32Value)
{
    QScrollBar::setValue(s32Value);
} // aScrollBar::setValue


/*******************************************************************************
* aScrollBar::slotValueChanged
*******************************************************************************/
void aScrollBar::slotValueChanged(int _iValue)
{
    //Control2VarPool();

    if (ctrlMgr() != nullptr)
    {
        ctrlMgr()->sendCtrlMessage(this, MSG_VALUE_CHANGED, _iValue);
    }
} // aScrollBar::slotValueChanged


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
