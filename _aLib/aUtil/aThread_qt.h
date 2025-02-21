/*******************************************************************************
* \file aThreadQt.h
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

#include "aWin/aWin_def.h"

#include "aUtil/aThread_cb.h"

using namespace aLib;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {
namespace SysQt {


/*******************************************************************************
* class aThreadQt
*******************************************************************************/
class aThreadQt : public QThread
{
    Q_OBJECT

    private:
        u32         m_u32Id;
        aThreadCb*  m_pCb;

    protected:
        aThreadQt(u32       _u32Id,
                  aThreadCb *_pCb = nullptr);

    public:
        virtual ~aThreadQt();

        aThreadQt() = delete;
        aThreadQt(const aThreadQt  &) = delete;
        aThreadQt(const aThreadQt  &&) = delete;

        u32                     id() const;
        void                    sleep_ms(u32	_u32SleepTime_ms) const;

        static u32				hardwareConcurrency();

        void                    startThread();

    protected:
        virtual void            onRun() = 0;

    private:
        virtual void			run() override;

    private slots:
        void                    slotThreadStarted();
        void                    slotThreadFinished();
}; // class aThreadQt


} // namespace SysQt
} // namespace aUtil
} // namespace aLib

#endif // _USE_QT_
