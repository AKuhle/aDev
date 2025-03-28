/*******************************************************************************
* \file aScrollWin.cpp
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
#include "aScrollWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aScrollWin::aScrollWin
*******************************************************************************/
aScrollWin::aScrollWin(SysWin *_pParent)
: aBaseWin<QAbstractScrollArea>(_pParent)
{
} // aScrollWin::aScrollWin


/*******************************************************************************
* aScrollWin::~aScrollWin
*******************************************************************************/
aScrollWin::~aScrollWin()
{
} // aScrollWin::~aScrollWin


/*******************************************************************************
* aScrollWin::setCentralWin
*******************************************************************************/
void aScrollWin::setCentralWin(SysWin *_pWin)
{
    setViewport(_pWin);
} // aScrollWin::setCentralWin


/*******************************************************************************
* aScrollWin::centralWin
*******************************************************************************/
SysWin* aScrollWin::centralWin()
{
    return viewport();
} // aScrollWin::centralWin


/*******************************************************************************
* aScrollWin::setScrollBarPolicy
*******************************************************************************/
void aScrollWin::setScrollBarPolicy(ScrollBarPolicy _policy)
{
    setHoriScrollBarPolicy(_policy);
    setVertScrollBarPolicy(_policy);
} // aScrollWin::setScrollBarPolicy


/*******************************************************************************
* aScrollWin::setHoriScrollBarPolicy
*******************************************************************************/
void aScrollWin::setHoriScrollBarPolicy(ScrollBarPolicy _policy)
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
} // aScrollWin::setHoriScrollBarPolicy


/*******************************************************************************
* aScrollWin::setVertScrollBarPolicy
*******************************************************************************/
void aScrollWin::setVertScrollBarPolicy(ScrollBarPolicy _policy)
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
} // aScrollWin::setVertScrollBarPolicy


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
