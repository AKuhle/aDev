/*******************************************************************************
* \file FaderInfo.cpp
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
#include "faderInfo.h"
#include "mainWin.h"

using namespace aFrame;


/*******************************************************************************
* FaderInfo::FaderInfo
*******************************************************************************/
FaderInfo::FaderInfo(QWidget *_pParent)
: QLabel(_pParent)
{
} // FaderInfo::FaderInfo


/*******************************************************************************
* FaderInfo::~FaderInfo
*******************************************************************************/
FaderInfo::~FaderInfo()
{
} // FaderInfo::~FaderInfo


/*******************************************************************************
* FaderInfo::init
*******************************************************************************/
void FaderInfo::init(QString _sFaderNr)
{
    m_sFaderNr = _sFaderNr;
} // FaderInfo::init


/*******************************************************************************
* FaderInfo::setInfo
*******************************************************************************/
void FaderInfo::setInfo(QString _sInfo)
{
    if (MainWin::instance()->isShowValues())
    {
        QLabel::setText(_sInfo);
    }
    else
    {
        QLabel::setText(m_sFaderNr);
    }
} // FaderInfo::setInfo
