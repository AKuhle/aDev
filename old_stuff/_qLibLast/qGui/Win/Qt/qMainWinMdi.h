/*******************************************************************************
* \file qMainWinMdi.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "qMainWin.h"
#include "qList.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qMdiArea;
    class qMdiWin;


    /*******************************************************************************
    * class qMainWinMdi
    *******************************************************************************/
    class qMainWinMdi : public qMainWin
    {
        Q_OBJECT

        protected:
            qMainWinMdi(SysWin_t  *_pParent = nullptr);
            ~qMainWinMdi();

        public:
            void                AddMdiWin(qMdiWin *_pMdiWin);

            void                GetMdiWinList(qPtrList<qMdiWin> &_lstMdiWin) const;

            qMdiWin*            ActiveMdiWin();
            qMdiWin*            ActiveOrTopmostMdiWin();

        protected:
            virtual void        OnMdiWinActivated(qMdiWin *_pMdiWin);

        private:
            qMdiArea*           MdiArea();
            const qMdiArea*     MdiArea() const;

        /*******************************************************************************
        * slots
        *******************************************************************************/
        private slots:
            void                SlotSubWindowActivated(QMdiSubWindow *);


        /*******************************************************************************
        * qSysWin interface
        *******************************************************************************/        protected:
        protected:
            virtual bool        OnSysCreate();

    }; // class qMainWinMdi

} // namespace aLib

#endif // _USE_QT_
