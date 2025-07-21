/*******************************************************************************
* \file aThread.h
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

#include "aThread_i.h"
#include "aThreadCb_i.h"

using namespace aFrame;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aThread
*******************************************************************************/
class aThread : private QThread,
                public aThread_i

{
    Q_OBJECT

    private:
        u32         m_u32Id;
        aThreadCb_i *m_pCb;

    protected:
        aThread(u32         _u32Id,
                aThreadCb_i *_pCb = nullptr);

    public:
        virtual ~aThread();

        u32                     id() const override;
        void                    sleep_ms(u32	_u32SleepTime_ms) const override;

        void                    startThread() override;

    private:
        virtual void			run() override;

    private slots:
        void                    slotThreadStarted();
        void                    slotThreadFinished();
}; // class aThread


} // namespace aUtil
} // namespace aFrame

#endif // _USE_QT_
