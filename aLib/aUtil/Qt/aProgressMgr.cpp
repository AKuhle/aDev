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
#include "aHelper.h"
#include "aProgressMgr.h"
#include "aProgressCb.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aUtil {


/*******************************************************************************
* aProgressMgrMgr::aProgressMgr
*******************************************************************************/
aProgressMgr::aProgressMgr()
{
} // aProgressMgr::aProgressMgr


/*******************************************************************************
* aProgressMgr::~aProgressMgr
*******************************************************************************/
aProgressMgr::~aProgressMgr()
{
} // aProgressMgr::~aProgressMgr


/*******************************************************************************
* aProgressMgr::setProgressCb
*******************************************************************************/
void aProgressMgr::setProgressCb(aProgressCb *_pProgressCb)
{
    m_pProgressCb = _pProgressCb;

    // disconnect previous connections
    disconnect(this, SIGNAL(signalOpenProgressDisplay()), 0, 0);
    disconnect(this, SIGNAL(signalCloseProgressDisplay()), 0, 0);
    disconnect(this, SIGNAL(signalUpdateProgressDisplay(QString)), 0, 0);
    disconnect(this, SIGNAL(signalUpdateProgressDisplay(u16)), 0, 0);

    // connect to new callback
    if (_pProgressCb != nullptr)
    {
        connect(this, SIGNAL(signalOpenProgressDisplay()), _pProgressCb, SLOT(slotOpenProgressDisplay()));
        connect(this, SIGNAL(signalCloseProgressDisplay()), _pProgressCb, SLOT(slotCloseProgressDisplay()));
        connect(this, SIGNAL(signalUpdateProgressDisplay(QString)), _pProgressCb, SLOT(slotUpdateProgressDisplay(QString)));
        connect(this, SIGNAL(signalUpdateProgressDisplay(u16)), _pProgressCb, SLOT(slotUpdateProgressDisplay(u16)));
    }

} // aProgressMgr::setProgressCb


/*******************************************************************************
* aProgressMgr::openDisplay
*******************************************************************************/
bool aProgressMgr::openDisplay(const aString &_sInfoText)
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
    emit signalOpenProgressDisplay();

    // update just the progress text without a value
    emit signalUpdateProgressDisplay(m_sCurrentInfoText.toQString());

    return true;
} // aProgressMgr::openDisplay


/*******************************************************************************
* aProgressMgr::openDisplay
*******************************************************************************/
bool aProgressMgr::openDisplay(const aString    &_sInfoText,
                               s64             _s64MinValue,
                               s64             _s64MaxValue)
{
    CHECK_PRE_CONDITION(!m_bOpen, false);

    m_bJustText				= false;
    m_bOpen					= true;
    m_bInvert				= (_s64MinValue > _s64MaxValue);

    m_s64Min		   		= aUtil::min<s64>(_s64MinValue, _s64MaxValue);
    m_s64Max		   		= aUtil::max<s64>(_s64MinValue, _s64MaxValue);

    m_sCurrentInfoText		= _sInfoText;

    m_s64CurrentValue	   	= _s64MinValue;
    m_u16CurrentValue_pml	= 0;

    // open the display
    emit signalOpenProgressDisplay();

    // update the progress text with the actual value = 0%
    emit signalUpdateProgressDisplay(m_sCurrentInfoText.toQString());
    emit signalUpdateProgressDisplay(m_u16CurrentValue_pml);

    return true;
} // aProgressMgr::openDisplay


/*******************************************************************************
* aProgressMgr::closeDisplay
*******************************************************************************/
void aProgressMgr::closeDisplay()
{
    if (m_bOpen)
    {
        m_bOpen = false;
        m_sCurrentInfoText = "";

        emit signalUpdateProgressDisplay("");
        emit signalCloseProgressDisplay();
    }
} // aProgressMgr::closeDisplay


/*******************************************************************************
* aProgressMgr::changeValues
*******************************************************************************/
void aProgressMgr::changeValues(s64   _s64MinValue,
                                s64   _s64MaxValue,
                                s64   _s64CurrentValue)
{
    if (m_bOpen)
    {
        m_bJustText				= false;
        m_bInvert				= (_s64MinValue > _s64MaxValue);

        m_s64Min		   		= aUtil::min<s64>(_s64MinValue, _s64MaxValue);
        m_s64Max		   		= aUtil::max<s64>(_s64MinValue, _s64MaxValue);

        m_u16CurrentValue_pml	= 0;

        setProgress(_s64CurrentValue);
    }
} // aProgressMgr::changeValues


/*******************************************************************************
* aProgressMgr::setInfo
*******************************************************************************/
void aProgressMgr::setInfo(const QString& _sInfoText)
{
    if (m_bOpen)
    {
        m_sCurrentInfoText = aString::fromQString(_sInfoText);

        emit signalUpdateProgressDisplay(m_sCurrentInfoText.toQString());
    }
} // aProgressMgr::setInfo


/*******************************************************************************
* aProgressMgr::setProgress
*******************************************************************************/
void aProgressMgr::setProgress(s64 _s64NewValue)
{
    if (m_bOpen && !m_bJustText && (_s64NewValue != m_s64CurrentValue))
    {
        m_s64CurrentValue = (m_bInvert)?   m_s64Max - _s64NewValue : _s64NewValue;
        u16 u16NewValue_pml = (u16) (1000 * (((dbl) (m_s64CurrentValue - m_s64Min)) / ((dbl) (m_s64Max - m_s64Min))));

        if (u16NewValue_pml - m_u16CurrentValue_pml >= m_u16UpdateDisplayDelta_pml)
        {
            m_u16CurrentValue_pml = u16NewValue_pml;

            emit signalUpdateProgressDisplay(m_u16CurrentValue_pml);
        }
    }
} // aProgressMgr::setProgress


/*******************************************************************************
* aProgressMgr::incrementProgress
*******************************************************************************/
void aProgressMgr::incrementProgress(s64 _s64Step /*= 1*/)
{
    setProgress((m_bInvert)?   m_s64CurrentValue - _s64Step :
                               m_s64CurrentValue + _s64Step);
} // aProgressMgr::incrementProgress


/*******************************************************************************
* aProgressMgr::setUpdateDisplayDelta_pml
*******************************************************************************/
void aProgressMgr::setUpdateDisplayDelta_pml(s16	_u16UpdateDisplayDelta_pml)
{
    m_u16UpdateDisplayDelta_pml = _u16UpdateDisplayDelta_pml;
} // aProgressMgr::setUpdateDisplayDelta_pml



} // namespace aUtil
} // namespace aLib

