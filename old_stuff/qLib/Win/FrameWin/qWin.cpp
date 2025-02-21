/*******************************************************************************
* \file qWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "Math/qRect2D.h"

#include "Win/WinStyle/qWinStyleFactory.h"
#include "Win/FrameWin/qWin.h"

using namespace qLib::Graphic;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* statics
*******************************************************************************/
unique_ptr<qWinStyleFactory>    qWin::m_pWinStyleFactory;


/*******************************************************************************
* qWin::qWin
*******************************************************************************/
qWin::qWin(qWin  *_pParent  /* = nullptr */)
: qSysWin(_pParent)
{
} // qWin::qWin


/*******************************************************************************
* qWin::~qWin
*******************************************************************************/
qWin::~qWin()
{
} // qWin::~qWin


/*******************************************************************************
* qWin::createWin
*******************************************************************************/
bool qWin::createWin()
{
    bool    bSuccess = false;

    if (m_pWinStyleFactory != nullptr)
    {
        m_pWinStyleFactory->setWinStyle(*this);
    }

    bSuccess = onSysCreateWin() && onCreateWin();

    if (bSuccess)
    {
        show();
    }

    return bSuccess;
} // qWin::createWin


/*******************************************************************************
* qWin::setWinStyleFactory
*******************************************************************************/
void qWin::setWinStyleFactory(unique_ptr<qWinStyleFactory>_pWinStyleFactory)
{
    m_pWinStyleFactory = std::move(_pWinStyleFactory);
} // qWin::setWinStyleFactory


/*******************************************************************************
* qWin::setLayout
*******************************************************************************/
void qWin::setLayout(unique_ptr<qLayout>_pLayout)
{
    m_pLayout = std::move(_pLayout);
} // qWin::setLayout


/*******************************************************************************
* qWin::layout
*******************************************************************************/
qLayout* qWin::layout() const
{
    return m_pLayout.get();
} // qWin::layout


/*******************************************************************************
* qWin::updateLayout
*******************************************************************************/
void qWin::updateLayout()
{
    CHECK_PRE_CONDITION_VOID(m_pLayout != nullptr);

    m_pLayout->arrangeChilds(layoutRect());
} // qWin::updateLayout


/*******************************************************************************
* qWin::marginRect
*******************************************************************************/
qRect2D<s32> qWin::marginRect() const
{
    return qRect2D<s32> (0, 0, w(), h());
} // qWin::marginRect


/*******************************************************************************
* qWin::borderRect
*******************************************************************************/
qRect2D<s32> qWin::borderRect() const
{
    qRect2D<s32>    r = marginRect();

    // maximized wins don't have a margin
    // => border rect == margin rect
    if (!isMaximized())
    {
        qMargin         m = margin();

        r.set(r.x() + m.l(),
              r.y() + m.t(),
              r.w() - m.w(),
              r.h() - m.h());
    }

    return r;
} // qWin::borderRect


/*******************************************************************************
* qWin::paddingRect
*******************************************************************************/
qRect2D<s32> qWin::paddingRect() const
{
    qRect2D<s32>    r = borderRect();

    // maximized wins don't show a border
    // => padding  rect == border rect
    if (!isMaximized())
    {
        qMargin         m = border();

        r.set(r.x() + m.l(),
              r.y() + m.t(),
              r.w() - m.w(),
              r.h() - m.h());
    }

    return r;
} // qWin::paddingRect


/*******************************************************************************
* qWin::layoutRect
*******************************************************************************/
qRect2D<s32> qWin::layoutRect() const
{
    qRect2D<s32>    r = paddingRect();
    qMargin         m = padding();

    r.set(r.x() + m.l(),
          r.y() + m.t(),
          r.w() - m.w(),
          r.h() - m.h());

    return r;
} // qWin::layoutRect


/*******************************************************************************
* qWin::contentRect
*******************************************************************************/
qRect2D<s32> qWin::contentRect() const
{
    qRect2D<s32>    r = layoutRect();

    if (m_pLayout != nullptr)
    {
        m_pLayout->adjustContentRect(r);
    }

    return r;
} // qWin::contentRect


/*******************************************************************************
* qWin::toggleMaximized
*******************************************************************************/
void qWin::toggleMaximized()
{
    if (isMaximized())
    {
        showNormal();
    }
    else
    {
        showMaximized();
    }
} // qWin::toggleMaximized


} // namespace Win
} // namespace qLib
