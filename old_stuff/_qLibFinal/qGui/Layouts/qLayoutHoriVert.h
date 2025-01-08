/*******************************************************************************
* \file qLayoutHoriVert.h
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
    * \class qLayoutHoriVert
    *******************************************************************************/
    class qLayoutHoriVert : public qLayoutObj
	{
        private:
            qPtrList<qLayoutObj>  m_lstChilds;

            struct structDim
            {
                qLayoutObj          *pLO;
                qDimension2D<s32>   minDim;     // multiple use => calculate just one time
                s32                 s32Size;

                structDim(qLayoutObj        *_pLO,
                          qDimension2D<s32> _minDim)
                {
                    pLO     = _pLO;
                    minDim  = _minDim;
                    s32Size = 0;
                }
            }; // structDim


        public:
            qLayoutHoriVert();
            virtual ~qLayoutHoriVert();

            void                        AddChild(qLayoutObj *_pChild);

        private:
            qDimension2D<s32>           GetMinSizeHori() const;
            qDimension2D<s32>           GetMinSizeVert() const;

            void                        ArangeChildsHori(qRect2D<s32> _parentRect);
            void                        ArangeChildsVert(qRect2D<s32> _parentRect);


        /*******************************************************************************
        * qLayoutBase interface
        *******************************************************************************/
        public:
            virtual qDimension2D<s32>   GetMinSize() const override;
            virtual void                ArangeChilds(const qRect2D<s32> &_parentRect) override;
    }; // class qLayoutHoriVert

} // namespace qLib
