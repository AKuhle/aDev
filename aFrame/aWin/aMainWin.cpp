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
#include "aLayoutHoriVert.h"
#include "aTitleBar.h"
#include "aBorderResizeTool.h"
#include "aToolBtn.h"


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
* aMainWin::onMinimize
*******************************************************************************/
void aMainWin::onMinimize(aBtn */*_pBtn*/)
{
    cout << __FUNCTION__ << endl;
} // aMainWin::onMinimize


/*******************************************************************************
* aMainWin::onMaximize
*******************************************************************************/
void aMainWin::onMaximize(aBtn */*_pBtn*/)
{
    cout << __FUNCTION__ << endl;
} // aMainWin::onMaximize


/*******************************************************************************
* aMainWin::onClose
*******************************************************************************/
void aMainWin::onClose(aBtn */*_pBtn*/)
{
    closeWin();
} // aMainWin::onClose


/*******************************************************************************
* aMainWin::onSysCreateWin
*******************************************************************************/
bool aMainWin::onSysCreateWin()
{
    aToolBtn *pBtn;

    CHECK_PRE_CONDITION(aBaseWin::onSysCreateWin(), false);

    #ifdef _USE_QT_
        // Titelleiste entfernen (for top level windows)
        asSysWin()->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    #endif // _USE_QT_

    // create the layout
    unique_ptr<aLayoutMainWin>  pLayout = make_unique<aLayoutMainWin> ();

    unique_ptr<aTitleBar> pTitleBar = make_unique<aTitleBar> (this);
    pTitleBar->createWin();
    aLayoutHoriVert *pTitleBarLayout = dynamic_cast<aLayoutHoriVert *> (pTitleBar->layout());

    // minimize button
    pBtn = new aToolBtn(pTitleBar.get(), ":/Standard/Masked/32/minimize.png", "");
    pBtn->createWin();
    pBtn->setFixDim(pBtn->sysMetrics());
    pBtn->addClickHandler([this](aBtn* btn) { onMinimize(btn); });
    pTitleBarLayout->addChild(pBtn);

    // maximize button
    pBtn = new aToolBtn(pTitleBar.get(), ":/Standard/Masked/32/maximize.png", "");
    pBtn->createWin();
    pBtn->setCheckable(true);
    pBtn->setFixDim(pBtn->sysMetrics());
    pBtn->addClickHandler([this](aBtn* btn) { onMaximize(btn); });
    pTitleBarLayout->addChild(pBtn);

    // close button - disabled
    pBtn = new aToolBtn(pTitleBar.get(), ":/Standard/Masked/32/close.png", "");
    pBtn->createWin();
    pBtn->setFixDim(pBtn->sysMetrics());
    pBtn->setHoverColor(colRed);
    pBtn->setEnabled(false);
    pTitleBarLayout->addChild(pBtn);

    // close button
    pBtn = new aToolBtn(pTitleBar.get(), ":/Standard/Masked/32/close.png", "");
    pBtn->createWin();
    pBtn->setFixDim(pBtn->sysMetrics());
    pBtn->setHoverColor(colRed);
    pBtn->addClickHandler([this](aBtn* btn) { onClose(btn); });
    pTitleBarLayout->addChild(pBtn);

    // move the items
    pLayout->setTitleBar(std::move(pTitleBar));
    setLayout(std::move(pLayout));

    // add the aBorderResizeTool
    addTool(make_unique<aBorderResizeTool> (this));

    return true;
} // aMainWin::onSysCreateWin


} // namespace aWin
} // namespace aFrame

#endif //_USE_QT_
