/*******************************************************************************
* \file aScrollWin_sys.cpp
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
#include "aScrollWin_sys.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aScrollWin_sys::aScrollWin_sys
*******************************************************************************/
aScrollWin_sys::aScrollWin_sys(SysWinClass *_pParent)
: aBaseWin<QAbstractScrollArea>(_pParent)
{
} // aScrollWin_sys::aScrollWin_sys


/*******************************************************************************
* aScrollWin_sys::~aScrollWin_sys
*******************************************************************************/
aScrollWin_sys::~aScrollWin_sys()
{
} // aScrollWin_sys::~aScrollWin_sys


/*******************************************************************************
* aScrollWin_sys::setCentralWin
*******************************************************************************/
void aScrollWin_sys::setCentralWin(SysWinClass *_pWin)
{
    setViewport(_pWin);
} // aScrollWin_sys::setCentralWin


/*******************************************************************************
* aScrollWin_sys::centralWin
*******************************************************************************/
SysWinClass* aScrollWin_sys::centralWin()
{
    return viewport();
} // aScrollWin_sys::centralWin


/*******************************************************************************
* aScrollWin_sys::setHoriScrollBarPolicy
*******************************************************************************/
void aScrollWin_sys::setHoriScrollBarPolicy(ScrollBarPolicy _policy)
{
    switch (_policy)
    {
        case ScrollBarPolicy::ScrollBarAlwaysOn:
            setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
            break;

        case ScrollBarPolicy::ScrollBarAlwaysOff:
            setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
            break;

        case ScrollBarPolicy::ScrollBarAsNeeded:
            setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
            break;
    }
} // aScrollWin_sys::setHoriScrollBarPolicy


/*******************************************************************************
* aScrollWin_sys::setVertScrollBarPolicy
*******************************************************************************/
void aScrollWin_sys::setVertScrollBarPolicy(ScrollBarPolicy _policy)
{
    switch (_policy)
    {
        case ScrollBarPolicy::ScrollBarAlwaysOn:
            setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
            break;

        case ScrollBarPolicy::ScrollBarAlwaysOff:
            setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
            break;

        case ScrollBarPolicy::ScrollBarAsNeeded:
            setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
            break;
    }
} // aScrollWin_sys::setVertScrollBarPolicy


// /*******************************************************************************
// * aScrollWin_sys::onPaint
// *******************************************************************************/
// bool aScrollWin_sys::onPaint()
// {
//     // inform the viewport about the repaint
//     QWidget *pW = viewport();
//     if (pW != nullptr)
//     {
//         //pW->repaint();
//     }

//     return false;   /* nothing paint in this window */
// } // aScrollWin_sys::onPaint


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
