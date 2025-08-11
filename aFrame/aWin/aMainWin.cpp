/*******************************************************************************
* \file aMainWin.cpp
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
#include <QMainWindow>
//#include <QSettings>

#include "aMainWin.h"
#include "aLayoutMainWin.h"
#include "aTitleBar.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aMainWin::aMainWin
*******************************************************************************/
aMainWin::aMainWin(SysWin *_pParent)
: aBaseWin(_pParent)
{
} // aMainWin::_isVisible


/*******************************************************************************
* aMainWin::~aMainWin
*******************************************************************************/
aMainWin::~aMainWin()
{
} // aMainWin::~aMainWin


/*******************************************************************************
* aMainWin::onSysCreateWin
*******************************************************************************/
bool aMainWin::onSysCreateWin()
{
    #ifdef _USE_QT_
        // Titelleiste entfernen (for top level windows)
        asSysWin()->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    #endif // _USE_QT_

    // create the layout
    unique_ptr<aLayoutMainWin>  pLayout = make_unique<aLayoutMainWin> ();

    unique_ptr<aTitleBar> pTitleBar = make_unique<aTitleBar> (asSysWin());
    pTitleBar->createWin();

    // move the items
    pLayout->setTitleBar(std::move(pTitleBar));
    setLayout(std::move(pLayout));

    return true;
} // aMainWin::onSysCreateWin


} // namespace aWin
} // namespace aFrame

#endif //_USE_QT_
