/*******************************************************************************
* includes
*******************************************************************************/
#include "Win/FrameWin/qMainWin.h"
#include "Win/FrameWin/qTitleBar.h"
#include "Win/Layout/qLayoutMainWin.h"
#include "Tool/qBorderResizeTool.h"

/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* qMainWin::qMainWin
*******************************************************************************/
qMainWin::qMainWin(qWin *_pParent /*= nullptr*/)
: qWin(_pParent)
{
} // qMainWin::qMainWin


/*******************************************************************************
* qMainWin::~qMainWin
*******************************************************************************/
qMainWin::~qMainWin()
{
} // qMainWin::~qMainWin


/*******************************************************************************
* qMainWin::onSysCreateWin
*******************************************************************************/
bool qMainWin::onSysCreateWin()
{
    // create the layout
    unique_ptr<qLayoutMainWin>  pLayout = make_unique<qLayoutMainWin> ();

    // titlebar
    qTitleBar   *pTitleBar = new qTitleBar(this);
    pTitleBar->createWin();
    pLayout->setTitleBar(pTitleBar);

    // the the layout
    setLayout(std::move(pLayout));
    updateLayout();

    // start th eparent ctrl tool
    unique_ptr<qBorderResizeTool> pTool = make_unique<qBorderResizeTool> (this);
    setTool(std::move(pTool));

    return true;
} // qMainWin::onSysCreateWin


} // namespace Win
} // namespace qLib
