/*******************************************************************************
* \file qViewBase.h
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
#include "qWin.h"

namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qDocBase;


    /*******************************************************************************
    * class qViewBase
    *******************************************************************************/
    class qViewBase : public qWin
    {
        DeclareSharedPtrProperty(qDocBase, p, Doc)

        protected:
            qViewBase(qWin *_pParent);

            qViewBase(qWin                             *_pParent,
                      const std::shared_ptr<qDocBase>  &_pDoc);

        public:
            virtual ~qViewBase();

        private:
            qViewBase(const qViewBase& _rhs) = delete;
            qViewBase(qViewBase&& _rhs) = delete;
            qViewBase& operator=(const qViewBase& _rhs) = delete;
            qViewBase& operator=(qViewBase&& _rhs) = delete;
    }; // class qViewBase

} // namespace qLib
