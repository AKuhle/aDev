/*******************************************************************************
* \file aLabel.inl
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
#include "aLabel.h"
#include "aGraphic/aPainter.h"

using namespace aLib::aGraphic;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aLabel::aLabel
*******************************************************************************/
aLabel::aLabel(aBaseWin   *_pParent,
                             u32        _u32Id /*= CTRL_ID_PROGRESS_CTRL*/)
: aCtrl(_pParent, _u32Id)
{
    setMinDim(0, 0);
    setMaxDim(S32_MAX, 0);
} // aLabel::aLabel


/*******************************************************************************
* aLabel::~aLabel
*******************************************************************************/
aLabel::~aLabel()
{
} // aLabel::~aLabel


/*******************************************************************************
* aLabel::setText
*******************************************************************************/
void aLabel::setText(const aString &_sText)
{
    m_sText = _sText;
    update();
} // aLabel::~setText


/*******************************************************************************
* aLabel::text
*******************************************************************************/
aString aLabel::text() const
{
    return m_sText;
} // aLabel::~text


/*******************************************************************************
* aLabel::setHoriAlignment
*******************************************************************************/
void aLabel::setHoriAlignment(enumAlignmentHori _eHori)
{
    m_eAlignmentHori = _eHori;
} // aLabel::~setHoriAlignment


/*******************************************************************************
* aLabel::setVertAlignment
*******************************************************************************/
void aLabel::setVertAlignment(enumAlignmentVert _eVert)
{
    m_eAlignmentVert = _eVert;
} // aLabel::~setVertAlignment


/*******************************************************************************
* aLabel::setAlignment
*******************************************************************************/
void aLabel::setAlignment(enumAlignmentHori _eHori,
                          enumAlignmentVert _eVert)
{
    m_eAlignmentHori = _eHori;
    m_eAlignmentVert = _eVert;
} // aLabel::~setAlignment


/*******************************************************************************
* aLabel::onPaintContent
*******************************************************************************/
void aLabel::onPaintContent()
{
    aPainter    p(this);
    aFont       f = font();

    p.drawText(m_sText, contentRect(), m_eAlignmentHori, m_eAlignmentVert, &f, &textColor());
} // aLabel::onPaintContent


} // namespace aWin
} // namespace aLib
