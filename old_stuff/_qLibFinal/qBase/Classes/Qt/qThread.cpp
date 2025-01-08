/*******************************************************************************
* \file qThread.cpp
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
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "qThread.h"

using namespace std;


namespace qLib
{
    /*******************************************************************************
    * qThread::qThread
    *******************************************************************************/
    qThread::qThread(u32        _u32ThreadID,
                     qThreadCb  *_pThreadCb /*= nullptr*/)
        : m_u32ThreadID(_u32ThreadID),
          m_pThreadCb(_pThreadCb)
    {
        if (m_pThreadCb != nullptr)
        {
            connect(this, SIGNAL(started()), this, SLOT(SlotThreadStarted()));
            connect(this, SIGNAL(finished()), this, SLOT(SlotThreadFinished()));

            connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
        }
    } // qThread::qThread


    /*******************************************************************************
    * qThread::~qThread
    *******************************************************************************/
    qThread::~qThread()
    {
    } // qThread::~qThread


    /*******************************************************************************
    * qThread::GetThreadID
    *******************************************************************************/
    u32 qThread::GetThreadID() const
    {
        return m_u32ThreadID;
    } // qThread::GetThreadID


    /*******************************************************************************
    * qThread::Sleep_ms
    *******************************************************************************/
    void qThread::Sleep_ms(u32	_u32SleepTime_ms) const
    {
        msleep(_u32SleepTime_ms);
    } // qThread::Sleep_ms


    /*******************************************************************************
    * qThread::GetHardwareConcurrency
    *******************************************************************************/
    u32 qThread::GetHardwareConcurrency()
    {
        return thread::hardware_concurrency();
    } // qThread::GetHardwareConcurrency


    /*******************************************************************************
    * qThread::StartThread
    *******************************************************************************/
    void qThread::StartThread()
    {
        start();
    } // qThread::StartThread


    /*******************************************************************************
    * qThread::run
    *******************************************************************************/
    void qThread::run()
    {
        OnRun();
    } // qThread::run


    /*******************************************************************************
    * qThread::SlotThreadStarted
    *******************************************************************************/
    void qThread::SlotThreadStarted()
    {
        if (m_pThreadCb != nullptr)
        {
            m_pThreadCb->OnThreadStarted(m_u32ThreadID);
        }
    } // qThread::SlotThreadStarted


    /*******************************************************************************
    * qThread::SlotThreadFinished
    *******************************************************************************/
    void qThread::SlotThreadFinished()
    {
        if (m_pThreadCb != nullptr)
        {
            m_pThreadCb->OnThreadFinished(m_u32ThreadID);
        }
    } // qThread::SlotThreadFinished

} // namespace qLib

#endif // _USE_QT_
