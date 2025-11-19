/*******************************************************************************
* \file aBaseWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aBaseWin.h"
#include "aCursor.h"
#include "aStyleItemBorder.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aBaseWin::aBaseWin
*******************************************************************************/
aBaseWin::aBaseWin(aBaseWin *_pParent)
: aBaseWin_sys(_pParent)
{
} // aBaseWin::aBaseWin


/*******************************************************************************
* aBaseWin::~aBaseWin
*******************************************************************************/
aBaseWin::~aBaseWin()
{
} // aBaseWin::~aBaseWin


/*******************************************************************************
* aBaseWin::createWin
*******************************************************************************/
bool aBaseWin::createWin()
{
    // first set the style, probably used in the creation methods
    setWinStyle();

    if (onSysCreateWin() && onCreateWin() && onCreateChilds())
    {
//         // aCtrlMgr initialization
//         aCtrlMgr *pCtrlMgr = dynamic_cast<aCtrlMgr *> (this);
//         if (pCtrlMgr != nullptr)
//         {
//             pCtrlMgr->onRegisterCtrl();
//         }

        return true;
    }

    return false;
} // aBaseWin::createWin


/*******************************************************************************
* aBaseWin::closeWin
*******************************************************************************/
bool aBaseWin::closeWin()
{
    if (onCloseWin())
    {
        aBaseWin_sys::closeWin();
        return true;
    }

    return false;
} // aBaseWin::closeWin


/*******************************************************************************
* aBaseWin::setMinDim
*******************************************************************************/
void aBaseWin::setMinDim(const aDimension &_minDim)
{
    setMinW(_minDim.w());
    setMinH(_minDim.h());
} // aBaseWin::setMinDim


/*******************************************************************************
* aBaseWin::setMinDim
*******************************************************************************/
void aBaseWin::setMinDim(s32 _s32MinW,
                         s32 _s32MinH)
{
    setMinW(_s32MinW);
    setMinH(_s32MinH);
} // aBaseWin::setMinDim


/*******************************************************************************
* aBaseWin::minW
*******************************************************************************/
s32 aBaseWin::minW() const
{
    aDimension  dim(aBaseWin_sys::minW(),
                    aBaseWin_sys::minH());

    if (m_pLayout)
    {
        dim = dim.max(m_pLayout->layoutMinDim());
    }

    return dim.w();
} // aBaseWin::minW


/*******************************************************************************
* aBaseWin::minH
*******************************************************************************/
s32 aBaseWin::minH() const
{
    aDimension  dim(aBaseWin_sys::minW(),
                    aBaseWin_sys::minH());

    if (m_pLayout)
    {
        dim = dim.max(m_pLayout->layoutMinDim());
    }

    return dim.h();
} // aBaseWin::minH


/*******************************************************************************
* aBaseWin::minDim
*******************************************************************************/
aDimension aBaseWin::minDim() const
{
    aDimension  dim(aBaseWin_sys::minW(),
                    aBaseWin_sys::minH());

    if (m_pLayout)
    {
        dim = dim.max(m_pLayout->layoutMinDim());
    }

    return dim;
} // aBaseWin::minDim


/*******************************************************************************
* aBaseWin::setMaxDim
*******************************************************************************/
void aBaseWin::setMaxDim(const aDimension &_maxDim)
{
    setMaxW(_maxDim.w());
    setMaxH(_maxDim.h());
} // aBaseWin::setMaxDim


/*******************************************************************************
* aBaseWin::setMaxDim
*******************************************************************************/
void aBaseWin::setMaxDim(s32 _s32MaxW,
                         s32 _s32MaxH)
{
    setMaxW(_s32MaxW);
    setMaxH(_s32MaxH);
} // aBaseWin::setMaxDim


/*******************************************************************************
* aBaseWin::setFixW
*******************************************************************************/
void aBaseWin::setFixW(s32 _s32FixW)
{
    setMinW(_s32FixW);
    setMaxW(_s32FixW);
} // aBaseWin::setFixW


/*******************************************************************************
* aBaseWin::setFixH
*******************************************************************************/
void aBaseWin::setFixH(s32 _s32FixW)
{
    setMinH(_s32FixW);
    setMaxH(_s32FixW);
} // aBaseWin::setFixH


/*******************************************************************************
* aBaseWin::setFixDim
*******************************************************************************/
void aBaseWin::setFixDim(const aDimension &_minDim)
{
    setFixW(_minDim.w());
    setFixH(_minDim.h());
} // aBaseWin::setFixDim


/*******************************************************************************
* aBaseWin::setFixDim
*******************************************************************************/
void aBaseWin::setFixDim(s32 _s32MinW,
                         s32 _s32MinH)
{
    setFixW(_s32MinW);
    setFixH(_s32MinH);
} // aBaseWin::setFixDim


/*******************************************************************************
* aBaseWin::isFixW
*******************************************************************************/
bool aBaseWin::isFixW() const
{
    return minW() == maxW();
} // aBaseWin::isFixW


/*******************************************************************************
* aBaseWin::isFixH
*******************************************************************************/
bool aBaseWin::isFixH() const
{
    return minH() == maxH();
} // aBaseWin::isFixH


/*******************************************************************************
* aBaseWin::marginRect
*******************************************************************************/
aRect aBaseWin::marginRect() const
{
    return aRect(0, 0, geometryW(), geometryH());
} // aBaseWin::marginRect


/*******************************************************************************
* aBaseWin::borderRect
*******************************************************************************/
aRect aBaseWin::borderRect() const
{
    aRect    r = marginRect();

    // full screen => no margin => border rect = margin rect
    if (!isFullScreen())
    {
        r -= marginMargin();
    }

    return r;
} // aBaseWin::borderRect


/*******************************************************************************
* aBaseWin::paddingRect
*******************************************************************************/
aRect aBaseWin::paddingRect() const
{
    aRect    r = borderRect();

    // full screen => no border => padding rect = border rect
    if (!isFullScreen())
    {
        // no border => padding rect == border rect
        if (borderStyle())
        {
            r -= borderStyle()->margin();
        }
    }

    return r;
} // aBaseWin::paddingRect


/*******************************************************************************
* aBaseWin::contentRect
*******************************************************************************/
aRect aBaseWin::contentRect() const
{
    return paddingRect() - paddingMargin();
} // aBaseWin::contentRect


/*******************************************************************************
* aBaseWin::setLayout
*******************************************************************************/
void aBaseWin::setLayout(unique_ptr<aLayout_i> _pLayout)
{
    m_pLayout = std::move(_pLayout);
} // aBaseWin::setLayout


/*******************************************************************************
* aBaseWin::layout
*******************************************************************************/
aLayout_i* aBaseWin::layout()
{
    return m_pLayout.get();
} // aBaseWin::layout


/*******************************************************************************
* aBaseWin::layout
*******************************************************************************/
const aLayout_i* aBaseWin::layout() const
{
    return m_pLayout.get();
} // aBaseWin::layout



} // namespace aWin
} // namespace aFrame



// /*******************************************************************************
// * aBaseWin::setWinTitle
// *******************************************************************************/
// template<class T>
// void aBaseWin::setWinTitle(const aString &_sTitle)
// {
//     T::setWindowTitle(_sTitle.toQString());
// } // aBaseWin::setWinTitle
