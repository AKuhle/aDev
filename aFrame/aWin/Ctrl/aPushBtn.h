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
* class aPushBtn
*******************************************************************************/
class aPushBtn : public aBtn
{
    public:
        aPushBtn(aBaseWin        *_pParent,
                 const aString   &_sRsc,
                 const aString   &_sLabel);

        virtual ~aPushBtn();
}; // class aPushBtn


} // namespace aWin
} // namespace aFrame
