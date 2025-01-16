/*******************************************************************************
* \file aButton.inl
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/Ctrl/aButton.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aButton::aButton
*******************************************************************************/
aButton::aButton(aBaseWin    *_pParent,
                 u32         _u32Id)
: aCtrl(_pParent, _u32Id)
{
} // aButton::aButton


/*******************************************************************************
* aButton::~aButton
*******************************************************************************/
aButton::~aButton()
{
} // aButton::~aButton


/*******************************************************************************
* aButton::onSysCreate
*******************************************************************************/
bool aButton::onSysCreate()
{
    // // enable mouse tracking for border resize
    // SetMouseTracking(true);

    // // start the border resize tool
    // unique_ptr<qButtonTool> pTool = make_unique<qButtonTool> (this);
    // SetTool(std::move(pTool));

    return true;
} // aButton::onSysCreate


/*******************************************************************************
* aButton::GetPixmap
*******************************************************************************/
// qPixmap* aButton::GetPixmap() const
// {
//     return m_pPixmap.get();
// } // aButton::GetPixmap


/*******************************************************************************
* aButton::SetPixmap
*******************************************************************************/
// void aButton::SetPixmap(const char    *_pRscName)
// {
//     m_pPixmap = make_unique<qPixmap> (_pRscName);
// } // aButton::SetPixmap


} // namespace aWin
} // namespace aLib
