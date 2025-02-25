/*******************************************************************************
* \file aView.cpp
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
#include "aView.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aView::aView
*******************************************************************************/
aView::aView(aBaseWin *_pParent)
: aBaseWin(_pParent)
{
} // aView::aView


/*******************************************************************************
* aView::aView
*******************************************************************************/
aView::aView(aBaseWin                      *_pParent,
             const std::shared_ptr<aDoc>   &_pDoc)
: aBaseWin(_pParent),
  m_pDoc(_pDoc)
{
} // aView::aView


/*******************************************************************************
* aView::~aView
*******************************************************************************/
aView::~aView()
{
} // aView::~aView


/*******************************************************************************
* aView::doc
*******************************************************************************/
shared_ptr<aDoc> aView::doc() const
{
    return m_pDoc;
} // aView::doc


/*******************************************************************************
* aView::setDoc
*******************************************************************************/
void aView::setDoc(const std::shared_ptr<aDoc> &_pDoc)
{
    m_pDoc = _pDoc;
} // aView::setDoc


} // namespace aWin
} // namespace aLib
