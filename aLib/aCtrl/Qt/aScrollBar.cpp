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
    if (m_bInverse)
    {
        QScrollBar::setValue(QScrollBar::maximum() - s32Value + QScrollBar::minimum());
    }
    else
    {
        QScrollBar::setValue(s32Value);
    }
} // aScrollBar::setValue


/*******************************************************************************
* aScrollBar::setInverse
*******************************************************************************/
void aScrollBar::setInverse(bool _bInverse)
{
    m_bInverse = _bInverse;
} // aScrollBar::setInverse


/*******************************************************************************
* aScrollBar::slotValueChanged
*******************************************************************************/
void aScrollBar::slotValueChanged(int _iValue)
{
    if (m_bInverse)
    {
        _iValue = QScrollBar::maximum() - _iValue + QScrollBar::minimum();
    }

    //Control2VarPool();

    if (ctrlMgr() != nullptr)
    {
        ctrlMgr()->sendCtrlMessage(this, MSG_VALUE_CHANGED, _iValue);
    }
} // aScrollBar::slotValueChanged


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
