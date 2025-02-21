/*******************************************************************************
* \file aLayoutCentralWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/Layout/aLayoutCentralWin.h"
#include "aWin/Framework/aBaseWin.h"
#include "aWin/Framework/aPosition_i.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aLayoutCentralWin::aLayoutCentralWin
*******************************************************************************/
aLayoutCentralWin::aLayoutCentralWin()
{
} // aLayoutCentralWin::aLayoutCentralWin


/*******************************************************************************
* aLayoutCentralWin::~aLayoutCentralWin
*******************************************************************************/
aLayoutCentralWin::~aLayoutCentralWin()
{
} // aLayoutCentralWin::~aLayoutCentralWin


/*******************************************************************************
* aLayoutCentralWin::addTopWin
*******************************************************************************/
void aLayoutCentralWin::addTopWin(aBaseWin *_pWin)
{
    aPositionI *pPos = dynamic_cast<aPositionI *> (_pWin);
    CHECK_PRE_CONDITION_VOID(pPos != nullptr);

    m_lstTop.push_back(_pWin);
    pPos->setPosition(enumPosition::North);
} // aLayoutCentralWin::addTopWin


/*******************************************************************************
* aLayoutCentralWin::addBottomWin
*******************************************************************************/
void aLayoutCentralWin::addBottomWin(aBaseWin *_pWin)
{
    aPositionI *pPos = dynamic_cast<aPositionI *> (_pWin);
    CHECK_PRE_CONDITION_VOID(pPos != nullptr);

    m_lstBottom.push_back(_pWin);
    pPos->setPosition(enumPosition::South);
} // aLayoutCentralWin::addBottomWin


/*******************************************************************************
* aLayoutCentralWin::addLeftWin
*******************************************************************************/
void aLayoutCentralWin::addLeftWin(aBaseWin *_pWin)
{
    aPositionI *pPos = dynamic_cast<aPositionI *> (_pWin);
    CHECK_PRE_CONDITION_VOID(pPos != nullptr);

    m_lstLeft.push_back(_pWin);
    pPos->setPosition(enumPosition::West);
} // aLayoutCentralWin::addLeftWin


/*******************************************************************************
* aLayoutCentralWin::addRightWin
*******************************************************************************/
void aLayoutCentralWin::addRightWin(aBaseWin *_pWin)
{
    aPositionI *pPos = dynamic_cast<aPositionI *> (_pWin);
    CHECK_PRE_CONDITION_VOID(pPos != nullptr);

    m_lstRight.push_back(_pWin);
    pPos->setPosition(enumPosition::East);
} // aLayoutCentralWin::addRightWin


/*******************************************************************************
* aLayoutCentralWin::setCentralWin
*******************************************************************************/
void aLayoutCentralWin::setCentralWin(aBaseWin *_pCenterWin)
{
    m_pCentralWin = _pCenterWin;
} // aLayoutCentralWin::setCentralWin


/*******************************************************************************
* aLayoutCentralWin::centralWin
*******************************************************************************/
aBaseWin* aLayoutCentralWin::centralWin() const
{
    return m_pCentralWin;;
} // aLayoutCentralWin::centralWin


/*******************************************************************************
* aLayoutCentralWin::calculateMinDim
*******************************************************************************/
aDimension2D<s32> aLayoutCentralWin::calculateMinDim() const
{
    aDimension2D<s32>   d;

    // add top wins
    for (aBaseWin *pWin : m_lstTop)
    {
        if (pWin->isVisible())
        {
            d.h() += pWin->minDim().h();
        }
    }

    // add bottom wins
    for (aBaseWin *pWin : m_lstBottom)
    {
        if (pWin->isVisible())
        {
            d.h() += pWin->minDim().h();

        }
    }

    // add left wins
    for (aBaseWin *pWin : m_lstLeft)
    {
        if (pWin->isVisible())
        {
            d.w() += pWin->minDim().w();
        }
    }

    // add right wins
    for (aBaseWin *pWin : m_lstRight)
    {
        if (pWin->isVisible())
        {
            d.w() += pWin->minDim().w();
        }
    }

    // minDim of the centerWin
    if (m_pCentralWin != nullptr && m_pCentralWin->isVisible())
    {
        d += m_pCentralWin->minDim();
    }

    return d;
} // aLayoutCentralWin::calculateMinDim


/*******************************************************************************
* aLayoutCentralWin::shrinkContentSize
*******************************************************************************/
void aLayoutCentralWin::shrinkContentSize(aRect2D<s32>  &_r2dContent) const
{
    // substract top wins
    for (aBaseWin *pWin : m_lstTop)
    {
        if (pWin->isVisible())
        {
            _r2dContent.y() += pWin->h();
            _r2dContent.h() -= pWin->h();
        }
    }

    // substract bottom wins
    for (aBaseWin *pWin : m_lstBottom)
    {
        if (pWin->isVisible())
        {
            _r2dContent.h() -= pWin->minDim().h();
        }
    }

    // substract left wins
    for (aBaseWin *pWin : m_lstLeft)
    {
        if (pWin->isVisible())
        {
            _r2dContent.x() += pWin->minDim().w();
            _r2dContent.w() -= pWin->minDim().w();
        }
    }

    // substract right wins
    for (aBaseWin *pWin : m_lstRight)
    {
        if (pWin->isVisible())
        {
            _r2dContent.w() -= pWin->minDim().w();
        }
    }

} // aLayoutCentralWin::shrinkContentSize


/*******************************************************************************
* aLayoutCentralWin::arrangeChilds
*******************************************************************************/
void aLayoutCentralWin::arrangeChilds(aRect2D<s32>  _r2dLayout)
{
    // arrange top wins
    for (aBaseWin *pWin : m_lstTop)
    {
        if (pWin->isVisible())
        {
            pWin->setGeometry(_r2dLayout.x(),
                              _r2dLayout.y(),
                              _r2dLayout.w(),
                              pWin->minDim().h());

            _r2dLayout.y() += pWin->minDim().h();
            _r2dLayout.h() -= pWin->minDim().h();
        }
    }

    // arrange bottom wins
    for (aBaseWin *pWin : m_lstBottom)
    {
        if (pWin->isVisible())
        {
            aRect2D<s32> r(_r2dLayout.x(),
                         _r2dLayout.b() - pWin->minDim().h(),
                         _r2dLayout.w(),
                         pWin->minDim().h());
            cout << r << endl;

            pWin->setGeometry(_r2dLayout.x(),
                              _r2dLayout.b() - pWin->minDim().h(),
                              _r2dLayout.w(),
                              pWin->minDim().h());

            _r2dLayout.h() -= pWin->minDim().h();
        }
    }

    // arrange left wins
    for (aBaseWin *pWin : m_lstLeft)
    {
        if (pWin->isVisible())
        {
            pWin->setGeometry(_r2dLayout.x(),
                              _r2dLayout.y(),
                              pWin->minDim().w(),
                              _r2dLayout.h());

            _r2dLayout.x() += pWin->minDim().w();
            _r2dLayout.w() -= pWin->minDim().w();
        }
    }

    // arrange right wins
    for (aBaseWin *pWin : m_lstRight)
    {
        if (pWin->isVisible())
        {
            pWin->setGeometry(_r2dLayout.r() - pWin->minDim().w(),
                              _r2dLayout.y(),
                              pWin->minDim().w(),
                              _r2dLayout.h());

            _r2dLayout.w() -= pWin->minDim().w();
        }
    }

    // arrange central win
    if (m_pCentralWin != nullptr && m_pCentralWin->isVisible())
    {
        m_pCentralWin->setGeometry(_r2dLayout.x(),
                                   _r2dLayout.y(),
                                   _r2dLayout.w(),
                                   _r2dLayout.h());
    }
} // aLayoutCentralWin::arrangeChilds


} // namespace aWin
} // namespace aLib
