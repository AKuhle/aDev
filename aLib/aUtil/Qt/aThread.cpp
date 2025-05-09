/*******************************************************************************
* \file aThread.cpp
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
#include "aThread.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aThread::aThread
*******************************************************************************/
aThread::aThread(u32            _u32Id,
                 aThreadCb_i    *_pCb /*= nullptr*/)
: m_u32Id(_u32Id),
  m_pCb(_pCb)
{
    if (_pCb != nullptr)
    {
        connect(this, SIGNAL(started()), this, SLOT(slotThreadStarted()));
        connect(this, SIGNAL(finished()), this, SLOT(slotThreadFinished()));

        connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
    }
} // aThread::aThread


/*******************************************************************************
* aThread::~aThread
*******************************************************************************/
aThread::~aThread()
{
} // aThread::~aThread


/*******************************************************************************
* aThread::id
*******************************************************************************/
u32 aThread::id() const
{
    return m_u32Id;
} // aThread::id


/*******************************************************************************
* aThread::sleep_ms
*******************************************************************************/
void aThread::sleep_ms(u32	_u32SleepTime_ms) const
{
    msleep(_u32SleepTime_ms);
} // aThread::sleep_ms


/*******************************************************************************
* aThread::startThread
*******************************************************************************/
void aThread::startThread()
{
    start();
} // aThread::startThread


/*******************************************************************************
* aThread::run
*******************************************************************************/
void aThread::run()
{
    onRun();
} // aThread::run


/*******************************************************************************
* aThread::slotThreadStarted
*******************************************************************************/
void aThread::slotThreadStarted()
{
    if (m_pCb != nullptr)
    {
        m_pCb->onThreadStarted(m_u32Id);
    }
} // aThread::slotThreadStarted


/*******************************************************************************
* aThread::slotThreadFinished
*******************************************************************************/
void aThread::slotThreadFinished()
{
    if (m_pCb != nullptr)
    {
        m_pCb->onThreadFinished(m_u32Id);
    }
} // aThread::slotThreadFinished


} // namespace aUtil
} // namespace aLib

#endif // _USE_QT_
