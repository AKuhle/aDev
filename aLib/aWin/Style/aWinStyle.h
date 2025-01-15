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
#include "aGraphic/GraphicObj/aBorderObj.h"
#include "aGraphic/GraphicObj/aFillObj.h"

#include "aUtil/aMargin.h"

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
        aMargin    m_margin;
        aMargin    m_border;
        aMargin    m_padding;

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

        void                setBorderObj(unique_ptr<aBorderObj> _pObj);
        aBorderObj*         borderObj() const;

        void                setContentObj(unique_ptr<aFillObj> _pObj);
        aFillObj*           contentObj() const;
}; // class aWinStyle


} // namespace aWin
} // namespace aLib
