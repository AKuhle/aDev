/*******************************************************************************
* \file qLayoutMainWin.h
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
#include "Win/winDefs.h"
#include "Win/Layout/qLayout.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* class qLayoutMainWin
*******************************************************************************/
class qLayoutMainWin : public qLayout
{
    private:
        qWin        *m_pTitleBar    { nullptr };

    public:
        qLayoutMainWin();
        ~qLayoutMainWin();

        void                    setTitleBar(qWin *_pBar);
        qWin*                   titleBar() const;


    /*******************************************************************************
    * qLayout interfasce
    *******************************************************************************/
    public:
        virtual void            adjustContentRect(qRect2D<s32> &_r2d) override;
        virtual void            arrangeChilds(qRect2D<s32>  _r2d) override;
}; // class qLayoutMainWin


} // namespace Win
} // namespace qLib
