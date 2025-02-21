/*******************************************************************************
* \file aCentralWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/Framework/aCentralWin.h"

#include "aWin/Layout/aLayoutCentralWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aCentralWin::aCentralWin
*******************************************************************************/
aCentralWin::aCentralWin(aBaseWin  *_pParent  /* = nullptr */)
: aBaseWin(_pParent)
{
} // aCentralWin::aCentralWin


/*******************************************************************************
* aCentralWin::~aCentralWin
*******************************************************************************/
aCentralWin::~aCentralWin()
{
} // aCentralWin::aCentralWin


/*******************************************************************************
* aCentralWin::setCentralWin
*******************************************************************************/
void aCentralWin::setCentralWin(aBaseWin *_pCentralWin)
{
    aLayoutCentralWin *pLayout = dynamic_cast<aLayoutCentralWin *> (layout());

    if (pLayout != nullptr)
    {
        pLayout->setCentralWin(_pCentralWin);
        _pCentralWin->setParent(this);
        updateLayout();
    }
} // aCentralWin::setCentralWin


/*******************************************************************************
* aCentralWin::centralWin
*******************************************************************************/
aBaseWin* aCentralWin::centralWin() const
{
    aLayoutCentralWin *pLayout = dynamic_cast<aLayoutCentralWin *> (layout());

    if (pLayout != nullptr)
    {
        return pLayout->centralWin();
    }

    return nullptr;
} // aCentralWin::centralWin


/*******************************************************************************
* aCentralWin::onSysCreate
*******************************************************************************/
bool aCentralWin::onSysCreate()
{
    unique_ptr<aLayoutCentralWin> pLayout = make_unique<aLayoutCentralWin> ();

    // move the layout
    setLayout(std::move (pLayout));

    return true;
} // aCentralWin::onSysCreate



} // namespace aWin
} // namespace aLib
