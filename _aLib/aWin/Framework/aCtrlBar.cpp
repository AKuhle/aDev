/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/Framework/aCtrlBar.h"
#include "aWin/Tool/aParentControlTool.h"

#include "aWin/Layout/aLayoutHoriVert.h"

#include "aWin/Ctrl/aToolButton.h"
#include "aWin/Ctrl/aHoriSpacer.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aCtrlBar::aCtrlBar
*******************************************************************************/
aCtrlBar::aCtrlBar(aBaseWin *_pParent   /*= nullptr*/)
: aBaseWin(_pParent)
{
} // aCtrlBar::aCtrlBar


/*******************************************************************************
* aCtrlBar::~aCtrlBar
*******************************************************************************/
aCtrlBar::~aCtrlBar()
{
} // aCtrlBar::~aCtrlBar


/*******************************************************************************
* aCtrlBar::layoutHoriVert
*******************************************************************************/
aLayoutHoriVert* aCtrlBar::layoutHoriVert() const
{
    return dynamic_cast<aLayoutHoriVert *> (layout());
} // aCtrlBar::layoutHoriVert


/*******************************************************************************
* aCtrlBar::setStyle
*******************************************************************************/
void aCtrlBar::setStyle()
{
    // set the bordersize dependend on the position
    // if a border exist
    if (borderObj() != nullptr)
    {
        switch (position())
        {
            default:
                break;

            case enumPosition::North:
                // the ctrlBar has a top border
                border().set(0, 0, 1, 0);
                break;

            case enumPosition::East:
                // the ctrlBar has a right border
                border().set(0, 1, 0, 0);
                break;

            case enumPosition::South:
                // the ctrlBar has a bottom border
                border().set(0, 0, 0, 1);
                break;

            case enumPosition::West:
                // the ctrlBar has a left border
                border().set(1, 0, 0, 0);
                break;
        } // switch
    } // if...
} // aCtrlBar::setStyle


/*******************************************************************************
* aCtrlBar::onPositionChanged
*******************************************************************************/
void aCtrlBar::onPositionChanged(enumPosition _eNewPosition)
{
    aLayoutHoriVert *pLayout = aCtrlBar::layoutHoriVert();
    CHECK_PRE_CONDITION_VOID(pLayout != nullptr);

    switch (_eNewPosition)
    {
        default:
            break;

        case enumPosition::North:
        case enumPosition::South:
            pLayout->setOrientation(enumOrientation::Hori);
            break;

        case enumPosition::East:
        case enumPosition::West:
            pLayout->setOrientation(enumOrientation::Vert);
            break;
    }

    setStyle();
} // aCtrlBar::onPositionChanged


/*******************************************************************************
* aCtrlBar::onSysCreate
*******************************************************************************/
bool aCtrlBar::onSysCreate()
{
    // create the layout
    unique_ptr<aLayoutHoriVert> pLayout = make_unique<aLayoutHoriVert> ();

    // set the layout
    setLayout(std::move (pLayout));

    return true;
} // aCtrlBar::onSysCreate


} // namespace aWin
} // namespace aLib
