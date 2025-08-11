/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aUtil_def.h"
#include "aWin_def.h"

#include "aMargin.h"
#include "aColor.h"

#include "aStyleItem.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aStyleItemBorder
*******************************************************************************/
class aStyleItemBorder : public aStyleItem
{
    private:
        aMargin     m_margin;
        aColor      m_color;

    public:
        aStyleItemBorder(const aMargin  &_margin,
                         const aColor   &_col);
        virtual ~aStyleItemBorder();

        void            setMargin(const aMargin  &_margin)  { m_margin = _margin; }
        const aMargin&  margin() const                      { return m_margin; }

        void            setColor(const aColor   &_col)      { m_color = _col; }
        const aColor&   color() const                       { return m_color; }
}; // class aStyleItemBorder


} // namespace aWin
} // namespace aFrame
