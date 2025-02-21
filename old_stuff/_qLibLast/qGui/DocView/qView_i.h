/*******************************************************************************
* \file qViewI.h
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
    class qDocI;


    /*******************************************************************************
    * class qViewI
    *******************************************************************************/
    class qViewI : public qWin
    {
        private:
            std::shared_ptr<qDocI>       m_pDoc;

        protected:
            qViewI(SysWin_t *_pParent);

            qViewI(SysWin_t                     *_pParent,
                   const std::shared_ptr<qDocI> &_pDoc);

        public:
            virtual ~qViewI();

            void                        SetDoc(const std::shared_ptr<qDocI> &_pDoc);
            std::shared_ptr<qDocI>      Doc() const;
            bool                        HasDoc() const;

        private:
            qViewI(const qViewI& _rhs) = delete;
            qViewI(qViewI&& _rhs) = delete;
            qViewI& operator=(const qViewI& _rhs) = delete;
            qViewI& operator=(qViewI&& _rhs) = delete;
    }; // class qViewI

} // namespace qLib
