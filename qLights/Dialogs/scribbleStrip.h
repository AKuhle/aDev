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


/*******************************************************************************
* includes
*******************************************************************************/
#pragma once

#include "aPlainWin.h"
#include "aPixmap.h"


using namespace aLib;
using namespace aLib::aGraphic;
using namespace aLib::aWin;


/*******************************************************************************
* forwards
*******************************************************************************/


/*******************************************************************************
* globals
*******************************************************************************/


/*******************************************************************************
* class ScribbleStrip
*******************************************************************************/
class ScribbleStrip : public aPlainWin
{
    private:
        aPixmap             m_pixmap;
        static aPixmap      *m_pixmapUnused;

    public:
        ScribbleStrip(SysWin *_pParent = nullptr);
        ~ScribbleStrip();

        void                    setIcon(const aString   &_sIcon);


    /*******************************************************************************
    * aBaseWinI interface
    *******************************************************************************/
    protected:
        bool                    onPaint() override;

}; // class ScribbleStrip
