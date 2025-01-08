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
#include "qBaseDefs.h"
#include "qString16.h"


namespace qLib
{
    /*******************************************************************************
    * class qProgress
    *******************************************************************************/
    class qProgress
	{
		private:
            bool			m_bJustText					{ false };	//! true => progress is just a text without a value
            bool			m_bOpen						{ false };	//! true => progressBar has been opened
			bool			m_bInvert					{ false };

			s64				m_s64Min					{ 0 };		//! Minimum value of the progress
            s64				m_s64Max					{ 0 };      //! Maximum value of the progress

            qString16       m_sCurrentInfoText;						//! The current info text

            s64				m_s64CurrentValue			{ 0 };		//! current value
            u16				m_u16CurrentValue_pml		{ 0 };		//! current value in per mill
			u16				m_u16UpdateDisplayDelta_pml	{ 50 };		//! value for updateStep per mill, e.g. 50%% (=default) means: update the bar each 50%%=5%

        protected:
            qProgress();

        public:
            virtual ~qProgress();

			// member for displaying a progress text
            bool                OpenProgressDisplay(const qString16 &_sInfoText);

			// member for displaying a progress text and a value
            bool                OpenProgressDisplay(const qString16 &_sInfoText,
                                                    s64             _s64MinValue,
                                                    s64             _s64MaxValue);

            void                CloseProgressDisplay();

            // changes the values while the display is open
            void                ChangeProgressValues(s64   _s64MinValue,
                                                     s64   _s64MaxValue,
                                                     s64   _s64CurrentValue);

            void                SetProgressInfo(const qString16 &_sInfoText);

            void                SetProgressValue(s64 _s64CurrentValue);

            void                IncrementProgressValue(s64 _s64Step);

            void                SetUpdateDisplayDelta_pml(s16 _u16UpdateDisplayDelta_pml);

		protected:
            // interface for derived classes
            virtual void		OnOpenProgressDisplay();
            virtual void		OnCloseProgressDisplay();
            virtual void		OnUpdateProgressDisplay(const qString16 &_sInfoText);
            virtual void		OnUpdateProgressDisplay(u16 _u16Progress_pml);


    }; // class qProgress

} // namespace qLib
