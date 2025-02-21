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
#include "aWin/aWin_def.h"
#include "aWin/Framework/aBaseWin.h"
#include "aWin/Framework/aPosition_i.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aDockArea
*******************************************************************************/
class aDockArea : public aBaseWin,
                  public aPositionI
{
    private:

    public:
        aDockArea(aBaseWin *_pParent = nullptr);
        ~aDockArea();
}; // class aDockArea


} // namespace aWin
} // namespace aLib
