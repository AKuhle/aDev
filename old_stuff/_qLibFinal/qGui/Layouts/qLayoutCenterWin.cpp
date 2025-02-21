/*******************************************************************************
* \file qLayoutCenterWin.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLayoutCenterWin.h"
#include "qWin.h"

using namespace std;


namespace qLib
{
    /*******************************************************************************
    * qLayoutCenterWin::qLayoutCenterWin
    *******************************************************************************/
    qLayoutCenterWin::qLayoutCenterWin()
	{
    } // qLayoutCenterWin::qLayoutCenterWin


    /*******************************************************************************
    * qLayoutCenterWin::~qLayoutCenterWin
    *******************************************************************************/
    qLayoutCenterWin::~qLayoutCenterWin()
    {
    } // qLayoutCenterWin::~qLayoutCenterWin


    /*******************************************************************************
    * qLayoutCenterWin::GetMinSize
    *******************************************************************************/
    qDimension2D<s32> qLayoutCenterWin::GetMinSize() const
    {
        qDimension2D<s32>   minDim;

        // set the size of the central win
        if (GetCenterWin() != nullptr)
        {
            minDim.w += MU<s32>::Max(minDim.w, GetCenterWin()->GetMinSize().w);
            minDim.h += GetCenterWin()->GetMinSize().h;
        }

        return minDim;
    } // qLayoutCenterWin::GetMinSize


    /*******************************************************************************
    * qLayoutCenterWin::ArangeChilds
    *******************************************************************************/
    void qLayoutCenterWin::ArangeChilds(const qRect2D<s32> &_parentRect)
    {
        // set the size of the central win
        if (GetCenterWin() != nullptr)
        {
            GetCenterWin()->SetGeometry(_parentRect);
        }
    } // qLayoutCenterWin::ArangeChilds

} // namespace qLib
