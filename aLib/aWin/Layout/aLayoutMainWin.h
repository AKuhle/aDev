/*******************************************************************************
* \file aLayoutMainWin.h
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

#include "aWin/Layout/aLayout.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aLayoutMainWin
*******************************************************************************/
class aLayoutMainWin : public aLayout
{
    private:
        aTitleBar   *m_pTitleBar    { nullptr };

    public:
        aLayoutMainWin();
        ~aLayoutMainWin();

        void                        setTitleBar(aTitleBar *_pBar);
        aTitleBar*                  titleBar() const;

        void                        shrinkContentSize(aRect2D<s32>  &_r2dContent) const;


    /*******************************************************************************
    * qLayout interfasce
    *******************************************************************************/
    public:
        virtual aDimension2D<s32>   calculateMinDim() const override;
        virtual void                arrangeChilds(aRect2D<s32>  _r2dLayout) override;
}; // class aLayoutMainWin


} // namespace aWin
} // namespace aLib
