/*******************************************************************************
* \file aBtn.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aBtn.h"
#include "aPixmap.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aBtn::aBtn
*******************************************************************************/
aBtn::aBtn(aBaseWin        *_pParent,
           const aString   &_sRsc,
           const aString   &_sInfoText)
: aCtrl(_pParent),
  m_sRsc(_sRsc),
  m_sInfoText(_sInfoText)
{
} // aBtn::_isVisible


/*******************************************************************************
* aBtn::~aBtn
*******************************************************************************/
aBtn::~aBtn()
{
} // aBtn::~aBtn


/*******************************************************************************
* aBtn::createPixmap
*******************************************************************************/
void aBtn::createPixmap()
{
    // create the pixmap
    if (m_sRsc != "")
    {
        m_pPixmap = make_shared<aPixmap> (m_sRsc);

        if (!m_pPixmap->isValid())
        {
            m_pPixmap = nullptr;
        }
        else
        {
            aDimension dim = sysMetrics();

            m_pPixmap->scale((dim.w() == 0)?   24 : dim.w(),
                             (dim.h() == 0)?   24 : dim.h());
        }
    }
} // aBtn::_isVisible


/*******************************************************************************
* aBtn::onSysCreateWin
*******************************************************************************/
bool aBtn::onSysCreateWin()
{
    createPixmap();

    return true;
} // aBtn::onSysCreateWin


} // namespace aWin
} // namespace aFrame
