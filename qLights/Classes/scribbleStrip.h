/*******************************************************************************
* \file ScribbleStrip.h
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
* class ScribbleStrip
*******************************************************************************/
class ScribbleStrip : public QLabel
{
    private:

    public:
        ScribbleStrip(QWidget *_pParent);

        ~ScribbleStrip();

        void            setPixmap(const QPixmap &_pix);
}; // class ScribbleStrip
