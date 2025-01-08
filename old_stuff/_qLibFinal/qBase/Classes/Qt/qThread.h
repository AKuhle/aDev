/*******************************************************************************
* \file qThread.h
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

#ifdef _USE_QT_

/*******************************************************************************
* includes
*******************************************************************************/
#include <QThread>
#include "qBaseDefs.h"
#include "qThreadCb.h"


namespace qLib
{
    /*******************************************************************************
    * class qThread
    *******************************************************************************/
    class qThread : public QThread
    {
        Q_OBJECT

        private:
            u32         m_u32ThreadID;
            qThreadCb*  m_pThreadCb;

        protected:
            qThread(u32         _u32ThreadID,
                    qThreadCb*  _pThreadCb = nullptr);

        public:
            virtual ~qThread();

            qThread() = delete;
            qThread(const qThread  &) = delete;
            qThread(const qThread  &&) = delete;

            u32                     GetThreadID() const;
            void                    Sleep_ms(u32	_u32SleepTime_ms) const;

            static u32				GetHardwareConcurrency();

            void                    StartThread();

            virtual void            OnRun() = 0;

        private:
            virtual void			run() override;

        private slots:
            void                    SlotThreadStarted();
            void                    SlotThreadFinished();
    }; // class qThread

} // namespace qLib

#endif // _USE_QT_
