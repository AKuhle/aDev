/*******************************************************************************
* \file aProgressBar.cpp
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
#include "aProgressBar.h"
#include "aString.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aProgressBar::aProgressBar
*******************************************************************************/
aProgressBar::aProgressBar(SysWin *_pParent)
: aCtrl<QProgressBar>(_pParent)
{
} // aProgressBar::_isVisible


/*******************************************************************************
* aProgressBar::~aProgressBar
*******************************************************************************/
aProgressBar::~aProgressBar()
{
} // aProgressBar::~aProgressBar


/*******************************************************************************
* aProgressBar::setInfo
*******************************************************************************/
void aProgressBar::setInfo(const aString &_sInfo)
{
    QProgressBar::setFormat(_sInfo.toQString() + ": %p%");
} // aProgressBar::setText


/*******************************************************************************
* aProgressBar::setRange
*******************************************************************************/
void aProgressBar::setRange(s32    _s32Min,
                      s32    _s32Max)
{
    QProgressBar::setRange(_s32Min, _s32Max);
} // aProgressBar::setRange


/*******************************************************************************
* aProgressBar::setValue
*******************************************************************************/
void aProgressBar::setValue(s32 s32Value)
{
    QProgressBar::setValue(s32Value);
} // aProgressBar::setValue


/*******************************************************************************
* aProgressBar::reset
*******************************************************************************/
void aProgressBar::reset()
{
    QProgressBar::reset();
} // aProgressBar::reset

} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
