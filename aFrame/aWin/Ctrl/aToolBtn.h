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
#include "aBtn.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aToolBtn
*******************************************************************************/
class aToolBtn : public aBtn
{
    public:
        aToolBtn(aBaseWin        *_pParent,
                 const aString   &_sRsc,
                 const aString   &_sLabel);

        virtual ~aToolBtn();


    /*******************************************************************************
    * aBaseWin implementation
    *******************************************************************************/
    protected:
        bool                onSysCreateWin() override;

        void                onPaintContentBg() override;
        void                onPaintContent() override;

}; // class aToolBtn


} // namespace aWin
} // namespace aFrame
