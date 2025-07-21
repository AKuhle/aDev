/*******************************************************************************
* \file qBaseDefs.h
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
#include <QObject>

#include "aFrame_def.h"
#include "aUtil_def.h"

#include "aProgressMgrI.h"
#include "aString.h"

using namespace aFrame;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aProgressMgr
*******************************************************************************/
class aProgressMgr : public QObject,
                     public aProgressMgrI
{
    Q_OBJECT

    private:
        aProgressCb         *m_pProgressCb              { nullptr };
        bool                m_bJustText					{ false };	//! true => progress is just a text without a value
        bool                m_bOpen						{ false };	//! true => progressBar has been opened
        bool                m_bInvert					{ false };

        s64                 m_s64Min					{ 0 };		//! Minimum value of the progress
        s64                 m_s64Max					{ 0 };      //! Maximum value of the progress

        aString             m_sCurrentInfoText;						//! The current info text

        s64                 m_s64CurrentValue			{ 0 };		//! current value
        u16                 m_u16CurrentValue_pml		{ 0 };		//! current value in per mill
        u16                 m_u16UpdateDisplayDelta_pml	{ 50 };		//! value for updateStep per mill, e.g. 50%% (=default) means: update the bar each 50%%=5%


    protected:
        aProgressMgr();


    public:
        virtual ~aProgressMgr();

        void                setProgressCb(aProgressCb *_pProgressCb) override;


    public slots:
        // member for displaying a progress text
        bool                openDisplay(const aString &_sInfoText) override;

        // member for displaying a progress text and a value
        bool                openDisplay(const aString &_sInfoText,
                                        s64             _s64MinValue,
                                        s64             _s64MaxValue) override;

        void                closeDisplay() override;

        // changes the values while the display is open
        void                changeValues(s64   _s64MinValue,
                                         s64   _s64MaxValue,
                                         s64   _s64CurrentValue) override;

        void                setInfo(const QString &_sInfoText) override;

        void                setProgress(s64 _s64CurrentValue) override;

        void                incrementProgress(s64 _s64Step = 1) override;

        void                setUpdateDisplayDelta_pml(s16 _u16UpdateDisplayDelta_pml) override;

    signals:
        void                signalOpenProgressDisplay();
        void                signalCloseProgressDisplay();
        void                signalUpdateProgressDisplay(const QString &_sInfoText);
        void                signalUpdateProgressDisplay(u16 _u16Progress_pml);
}; // class aProgressMgr


} // namespace aUtil
} // namespace aFrame

