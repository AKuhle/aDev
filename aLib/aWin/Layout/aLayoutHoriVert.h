/*******************************************************************************
* \file aLayoutHoriVert.h
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aUtil/Collection/aPtrList.h"

#include "aWin/Layout/aLayout.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* forward
*******************************************************************************/
class qTitleBar;
class qStatusBar;


/*******************************************************************************
* \class aLayoutHoriVert
*******************************************************************************/
class aLayoutHoriVert : public aLayout
{
    private:
        enumOrientation         m_eOrientation      { enumOrientation::Hori };
        aPtrList<aLayoutObj>    m_lstChilds;

        struct structDim
        {
            aLayoutObj          *pLO;
            aDimension2D<s32>   minDim;     // multiple use => calculate just one time
            s32                 s32Size;

            structDim(aLayoutObj        *_pLO,
                      aDimension2D<s32> _minDim)
            {
                pLO     = _pLO;
                minDim  = _minDim;
                s32Size = 0;
            }
        }; // structDim


    public:
        aLayoutHoriVert();
        virtual ~aLayoutHoriVert();

        void                        addChild(aLayoutObj *_pChild);

        void                        setOrientation(enumOrientation  _eOrientation);
        enumOrientation             orientation() const;

    private:
        aDimension2D<s32>           minSizeHori() const;
        aDimension2D<s32>           minSizeVert() const;

        void                        arangeChildsHori(aRect2D<s32> _r2dLayout);
        void                        arangeChildsVert(aRect2D<s32> _r2dLayout);


    /*******************************************************************************
    * qLayout interfasce
    *******************************************************************************/
    public:
        virtual aDimension2D<s32>   calculateMinSize() const override;
        virtual void                arrangeChilds(aRect2D<s32> _r2dLayout) override;
}; // class aLayoutHoriVert


} // namespace aWin
} // namespace aLib
