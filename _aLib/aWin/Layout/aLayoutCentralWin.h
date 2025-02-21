/*******************************************************************************
* \file aLayoutCentralWin.h
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
#include "aUtil/Collection/aPtrList.h"

#include "aWin/aWin_def.h"

#include "aWin/Layout/aLayout.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aLayoutCentralWin
*******************************************************************************/
class aLayoutCentralWin : public aLayout
{
    private:
        aPtrList<aBaseWin>      m_lstTop;
        aPtrList<aBaseWin>      m_lstBottom;
        aPtrList<aBaseWin>      m_lstLeft;
        aPtrList<aBaseWin>      m_lstRight;

        aBaseWin                *m_pCentralWin    { nullptr };

    public:
        aLayoutCentralWin();
        ~aLayoutCentralWin();

        void                        addTopWin(aBaseWin *_pWin);
        void                        addBottomWin(aBaseWin *_pWin);
        void                        addLeftWin(aBaseWin *_pWin);
        void                        addRightWin(aBaseWin *_pWin);

        void                        setCentralWin(aBaseWin *_pCentralWin);
        aBaseWin*                   centralWin() const;


    /*******************************************************************************
    * aLayout interfasce
    *******************************************************************************/
    public:
        virtual void                shrinkContentSize(aRect2D<s32>  &_r2dContent) const override;
        virtual void                arrangeChilds(aRect2D<s32>  _r2dLayout) override;
        virtual aDimension2D<s32>   calculateMinDim() const override;
}; // class aLayoutCentralWin


} // namespace aWin
} // namespace aLib
