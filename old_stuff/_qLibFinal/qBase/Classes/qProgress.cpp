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


/*******************************************************************************
* includes
*******************************************************************************/
#include "qProgress.h"
#include "qMathUtil.h"


namespace qLib
{
    /*******************************************************************************
    * qProgress::qProgress
    *******************************************************************************/
    qProgress::qProgress()
	{
    } // qProgress::qProgress


    /*******************************************************************************
    * qProgress::~qProgress
    *******************************************************************************/
    qProgress::~qProgress()
	{
    } // qProgress::~qProgress


    /*******************************************************************************
    * qProgress::OpenProgressDisplay
    *******************************************************************************/
    bool qProgress::OpenProgressDisplay(const qString16 &_sInfoText)
	{
        CHECK_PRE_CONDITION(!m_bOpen, false);

        m_bJustText 			= true;
        m_bOpen 				= true;
        m_bInvert				= false;

        m_s64Min		   		= 0;
        m_s64Max		   		= 0;

        m_sCurrentInfoText		= _sInfoText;

        m_s64CurrentValue		= 0;
        m_u16CurrentValue_pml	= 0;

        // open the display
        OnOpenProgressDisplay();

        // update just the progress text without a value
        OnUpdateProgressDisplay(m_sCurrentInfoText);
	
        return true;
    } // qProgress::OpenProgressDisplay


    /*******************************************************************************
    * qProgress::OpenProgressDisplay
    *******************************************************************************/
    bool qProgress::OpenProgressDisplay(const qString16&    _sInfoText,
                                        s64                 _s64MinValue,
                                        s64                 _s64MaxValue)
	{
        CHECK_PRE_CONDITION(!m_bOpen, false);

        m_bJustText				= false;
        m_bOpen					= true;
        m_bInvert				= (_s64MinValue > _s64MaxValue);

        m_s64Min		   		= MU<s64>::Min(_s64MinValue, _s64MaxValue);
        m_s64Max		   		= MU<s64>::Max(_s64MinValue, _s64MaxValue);

        m_sCurrentInfoText		= _sInfoText;

        m_s64CurrentValue	   	= _s64MinValue;
        m_u16CurrentValue_pml	= 0;

        // open the display
        OnOpenProgressDisplay();

        // update the progress text with the actual value = 0%
        OnUpdateProgressDisplay(m_u16CurrentValue_pml);
        OnUpdateProgressDisplay(m_sCurrentInfoText);

        return true;
    } // qProgress::OpenProgressDisplay


    /*******************************************************************************
    * qProgress::CloseProgressDisplay
    *******************************************************************************/
    void qProgress::CloseProgressDisplay()
	{
		if (m_bOpen)
		{
			m_bOpen = false;
            m_sCurrentInfoText = "";
			OnCloseProgressDisplay();
		}
    } // qProgress::CloseProgressDisplay


    /*******************************************************************************
    * qProgress::ChangeProgressValues
    *******************************************************************************/
    void qProgress::ChangeProgressValues(s64   _s64MinValue,
                                         s64   _s64MaxValue,
                                         s64   _s64CurrentValue)
    {
        if (m_bOpen)
        {
            m_bJustText				= false;
            m_bInvert				= (_s64MinValue > _s64MaxValue);

            m_s64Min		   		= MU<s64>::Min(_s64MinValue, _s64MaxValue);
            m_s64Max		   		= MU<s64>::Max(_s64MinValue, _s64MaxValue);

            m_u16CurrentValue_pml	= 0;

            SetProgressValue(_s64CurrentValue);
        }
    } // qProgress::ChangeProgressValues


    /*******************************************************************************
    * qProgress::SetProgressInfo
    *******************************************************************************/
    void qProgress::SetProgressInfo(const qString16& _sInfoText)
	{
		if (m_bOpen)
		{
			m_sCurrentInfoText = _sInfoText;

			OnUpdateProgressDisplay(m_sCurrentInfoText);
		}
    } // qProgress::SetProgressInfo


    /*******************************************************************************
    * qProgress::SetProgressValue
    *******************************************************************************/
    void qProgress::SetProgressValue(s64 _s64NewValue)
	{
        if (m_bOpen && !m_bJustText && (_s64NewValue != m_s64CurrentValue))
		{
            m_s64CurrentValue = (m_bInvert)?   m_s64Max - _s64NewValue : _s64NewValue;
            u16 u16NewValue_pml = (u16) (1000 * (((dbl) (m_s64CurrentValue - m_s64Min)) / ((dbl) (m_s64Max - m_s64Min))));

            if (u16NewValue_pml - m_u16CurrentValue_pml >= m_u16UpdateDisplayDelta_pml)
			{
                m_u16CurrentValue_pml = u16NewValue_pml;

				OnUpdateProgressDisplay(m_u16CurrentValue_pml);
			}
        }
    } // qProgress::SetProgressValue


    /*******************************************************************************
    * qProgress::IncrementProgressValue
    *******************************************************************************/
    void qProgress::IncrementProgressValue(s64 _s64Step)
	{
        SetProgressValue((m_bInvert)?   m_s64CurrentValue - _s64Step :
                                        m_s64CurrentValue + _s64Step);
    } // qProgress::IncrementProgressValue


    /*******************************************************************************
    * qProgress::SetUpdateDisplayDelta_pml
    *******************************************************************************/
    void qProgress::SetUpdateDisplayDelta_pml(s16	_u16UpdateDisplayDelta_pml)
    {
        m_u16UpdateDisplayDelta_pml = _u16UpdateDisplayDelta_pml;
    } // qProgress::SetUpdateDisplayDelta_pml


    /*******************************************************************************
    * qProgress::OnOpenProgressDisplay
    *******************************************************************************/
    void qProgress::OnOpenProgressDisplay()
    {
    }


    /*******************************************************************************
    * qProgress::OnCloseProgressDisplay
    *******************************************************************************/
    void qProgress::OnCloseProgressDisplay()
    {
    }


    /*******************************************************************************
    * qProgress::OnUpdateProgressDisplay
    *******************************************************************************/
    void qProgress::OnUpdateProgressDisplay(const qString16& /*_sInfoText*/)
    {
    }


    /*******************************************************************************
    * qProgress::OnUpdateProgressDisplay
    *******************************************************************************/
    void qProgress::OnUpdateProgressDisplay(u16 /*_u16Progress_pml*/)
    {
    }
} // namespace qLib
