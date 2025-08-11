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

#include "aColor.h"
#include "aStyleItemFill.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aStyleItemFillSolid
*******************************************************************************/
class aStyleItemFillSolid : public aStyleItemFill
{
    private:
        aColor      m_color;

    public:
        aStyleItemFillSolid(const aColor   &_col);
        virtual ~aStyleItemFillSolid();

        void            setColor(const aColor   &_col);
        const aColor&   color() const;

        void            draw(aPainter       &_p,
                             const aRect    &_r) override;

}; // class aStyleItemFillSolid


} // namespace aWin
} // namespace aFrame
