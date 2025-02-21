/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/Framework/aPosition_i.h"
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
* aPositionI::aPositionI
*******************************************************************************/
aPositionI::aPositionI()
{
} // aPositionI::aPositionI


/*******************************************************************************
* aPositionI::~aPositionI
*******************************************************************************/
aPositionI::~aPositionI()
{
} // aPositionI::~aPositionI


/*******************************************************************************
* aPositionI::setPosition
*******************************************************************************/
void aPositionI::setPosition(enumPosition _ePosition)
{
    m_ePosition = _ePosition;

    onPositionChanged(_ePosition);
} // aPositionI::setPosition


/*******************************************************************************
* aPositionI::position
*******************************************************************************/
enumPosition aPositionI::position() const
{
    return m_ePosition;
} // aPositionI::position


/*******************************************************************************
* aPositionI::onPositionChanged
*******************************************************************************/
void aPositionI::onPositionChanged(enumPosition /*_eNewPosition*/)
{
} // aPositionI::layoutHoriVert


} // namespace aWin
} // namespace aLib
