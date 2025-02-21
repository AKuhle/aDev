/*******************************************************************************
* \file aWinStyle.h
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
#include "aGraphic/aGraphic_def.h"
#include "aGraphic/GraphicObj/aBorderObj.h"
#include "aGraphic/GraphicObj/aFillObj.h"
#include "aGraphic/aFont.h"

#include "aUtil/aMargin.h"
#include "aUtil/aColor.h"


using namespace std;
using namespace aLib::aGraphic;
using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aWinStyle
*******************************************************************************/


/*******************************************************************************
* class aWinStyle
*******************************************************************************/
class aWinStyle
{
    private:
        aMargin     m_margin;
        aMargin     m_border;
        aMargin     m_padding;

        aColor      m_colBg;
        aColor      m_colActive;
        aColor      m_colText;

        unique_ptr<aBorderObj>  m_pBorderObj;
        unique_ptr<aFillObj>    m_pContentObj;

    public:
        aWinStyle();
        ~aWinStyle();

        const aMargin       &margin() const;
        aMargin             &margin();

        const aMargin       &border() const;
        aMargin             &border();

        const aMargin       &padding() const;
        aMargin             &padding();

        void                setBgColor(const aColor  &_color);
        const aColor&       bgColor() const;

        void                setActiveColor(const aColor  &_color);
        const aColor&       activeColor() const;

        void                setTextColor(const aColor  &_color);
        const aColor&       textColor() const;

        void                setBorderObj(unique_ptr<aBorderObj> _pObj);
        aBorderObj*         borderObj() const;

        void                setContentObj(unique_ptr<aFillObj> _pObj);
        aFillObj*           contentObj() const;
}; // class aWinStyle


} // namespace aWin
} // namespace aLib
