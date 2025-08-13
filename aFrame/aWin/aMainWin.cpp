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
#include "aBorderResizeTool.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aMainWin::aMainWin
*******************************************************************************/
aMainWin::aMainWin(aBaseWin *_pParent)
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
    CHECK_PRE_CONDITION(aBaseWin::onSysCreateWin(), false);

    #ifdef _USE_QT_
        // Titelleiste entfernen (for top level windows)
        asSysWin()->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    #endif // _USE_QT_

    // create the layout
    unique_ptr<aLayoutMainWin>  pLayout = make_unique<aLayoutMainWin> ();

    unique_ptr<aTitleBar> pTitleBar = make_unique<aTitleBar> (this);
    pTitleBar->createWin();

    // move the items
    pLayout->setTitleBar(std::move(pTitleBar));
    setLayout(std::move(pLayout));

    // add the aBorderResizeTool
    addTool(make_unique<aBorderResizeTool> (this));

    return true;
} // aMainWin::onSysCreateWin


 /*******************************************************************************
 * aMainWin::onButtonPress
 *******************************************************************************/
 bool aMainWin::onButtonPress(u16          _u16Modifier,
                              u16          _u16Btn,
                              const aPoint &_pntLocal,
                              const aPoint &_pntGlobal)
{
    return onToolMgrButtonPress(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);
} // aMainWin::onButtonPress


/*******************************************************************************
* aMainWin::onMouseMove
*******************************************************************************/
bool aMainWin::onMouseMove(u16             _u16Modifier,
                           u16             _u16Btn,
                           const aPoint    &_pntLocal,
                           const aPoint    &_pntGlobal)
{
    return onToolMgrMouseMove(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);
} // aMainWin::onMouseMove


/*******************************************************************************
* aMainWin::onButtonRelease
*******************************************************************************/
bool aMainWin::onButtonRelease(u16             _u16Modifier,
                               u16             _u16Btn,
                               const aPoint    &_pntLocal,
                               const aPoint    &_pntGlobal)
{
    return onToolMgrButtonRelease(_u16Modifier, _u16Btn, _pntLocal, _pntGlobal);
} // aMainWin::onLDoubleClick


} // namespace aWin
} // namespace aFrame

#endif //_USE_QT_
