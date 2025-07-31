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
        aColor      m_fillColor;

    public:
        aStyleItemFillSolid(const aColor   &_col);
        virtual ~aStyleItemFillSolid();

        void            setFillColor(const aColor   &_col);
        aColor          fillColor() const;
}; // class aStyleItemFillSolid


} // namespace aWin
} // namespace aFrame
