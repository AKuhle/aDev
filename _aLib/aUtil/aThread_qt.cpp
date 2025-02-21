/*******************************************************************************
* \file aThreadQt.cpp
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
#include "aUtil/aThread_qt.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {
namespace SysQt {


/*******************************************************************************
* aThreadQt::aThreadQt
*******************************************************************************/
aThreadQt::aThreadQt(u32        _u32Id,
                     aThreadCb  *_pCb /*= nullptr*/)
: m_u32Id(_u32Id),
  m_pCb(_pCb)
{
    if (_pCb != nullptr)
    {
        connect(this, SIGNAL(started()), this, SLOT(slotThreadStarted()));
        connect(this, SIGNAL(finished()), this, SLOT(slotThreadFinished()));

        connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
    }
} // aThreadQt::aThreadQt


/*******************************************************************************
* aThreadQt::~aThreadQt
*******************************************************************************/
aThreadQt::~aThreadQt()
{
} // aThreadQt::~aThreadQt


/*******************************************************************************
* aThreadQt::id
*******************************************************************************/
u32 aThreadQt::id() const
{
    return m_u32Id;
} // aThreadQt::id


/*******************************************************************************
* aThreadQt::sleep_ms
*******************************************************************************/
void aThreadQt::sleep_ms(u32	_u32SleepTime_ms) const
{
    msleep(_u32SleepTime_ms);
} // aThreadQt::sleep_ms


/*******************************************************************************
* aThreadQt::hardwareConcurrency
*******************************************************************************/
u32 aThreadQt::hardwareConcurrency()
{
    return thread::hardware_concurrency();
} // aThreadQt::hardwareConcurrency


/*******************************************************************************
* aThreadQt::startThread
*******************************************************************************/
void aThreadQt::startThread()
{
    start();
} // aThreadQt::startThread


/*******************************************************************************
* aThreadQt::run
*******************************************************************************/
void aThreadQt::run()
{
    onRun();
} // aThreadQt::run


/*******************************************************************************
* aThreadQt::slotThreadStarted
*******************************************************************************/
void aThreadQt::slotThreadStarted()
{
    if (m_pCb != nullptr)
    {
        m_pCb->onThreadStarted(m_u32Id);
    }
} // aThreadQt::slotThreadStarted


/*******************************************************************************
* aThreadQt::slotThreadFinished
*******************************************************************************/
void aThreadQt::slotThreadFinished()
{
    if (m_pCb != nullptr)
    {
        m_pCb->onThreadFinished(m_u32Id);
    }
} // aThreadQt::slotThreadFinished


} // namespace SysQt
} // namespace aUtil
} // namespace aLib

#endif // _USE_QT_
