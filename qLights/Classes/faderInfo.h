/*******************************************************************************
* \file FaderInfo.h
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
#include <QLabel>

#include "aFrame_def.h"

using namespace std;
using namespace aFrame;



/*******************************************************************************
* class FaderInfo
*******************************************************************************/
class FaderInfo : public QLabel
{
    Q_OBJECT

    private:
        QString     m_sFaderNr;

    public:
        FaderInfo(QWidget *_pParent);
        ~FaderInfo();

        void            init(QString _sFaderNr);

        void            setInfo(QString _sInfo);
}; // class FaderInfo
