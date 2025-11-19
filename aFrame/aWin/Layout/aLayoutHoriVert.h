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
#include "aWin_def.h"
#include "aLayout_i.h"

using namespace std;
using namespace aFrame::aWin;
using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aLayoutHoriVert
*******************************************************************************/
class aLayoutHoriVert : public aLayout_i
{
    private:
        enumOrientation     m_eOrientation      { enumOrientation::Hori };
        list<aBaseWin *>    m_lstChilds;


    public:
        aLayoutHoriVert();
        virtual ~aLayoutHoriVert();

        void                addChild(aBaseWin *_pWin);

        void                arrange(const aRect &_r) override;


    protected:
        aDimension          layoutMinDim() const override;


    private:
        aDimension          layoutMinDimHori() const;
        aDimension          layoutMinDimVert() const;

        void                arrangeHori(const aRect &_r);
        void                arrangeVert(const aRect &_r);
}; // class aLayoutHoriVert


} // namespace aWin
} // namespace aFrame
