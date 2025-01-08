/*******************************************************************************
* \file qLayoutMainWin.h
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
#include "qRect2D.h"
#include "qLayoutCenterWin.h"
#include "qPtrList.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qTitleBar;
    class qStatusBar;


    /*******************************************************************************
    * \class qLayoutMainWin
    *******************************************************************************/
    class qLayoutMainWin : public qLayoutCenterWin
	{
        DeclarePtrProperty(qTitleBar, p, TitleBar)
        DeclarePtrProperty(qStatusBar, p, StatusBar)

        private:
            qPtrList<qWin>  m_lstLeftChilds;
            qPtrList<qWin>  m_lstRightChilds;
            qPtrList<qWin>  m_lstTopChilds;
            qPtrList<qWin>  m_lstBottomChilds;

        public:
            qLayoutMainWin();
            virtual ~qLayoutMainWin();

            void                        AddLeftChild(qWin *_pChild);
            void                        AddRightChild(qWin *_pChild);
            void                        AddTopChild(qWin *_pChild);
            void                        AddBottomChild(qWin *_pChild);


        /*******************************************************************************
        * qLayoutBase interface
        *******************************************************************************/
        public:
            virtual qDimension2D<s32>   GetMinSize() const override;
            virtual void                ArangeChilds(const qRect2D<s32> &_parentRect) override;

    }; // class qLayoutMainWin

} // namespace qLib
