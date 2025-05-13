/*******************************************************************************
* \file fader.h
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
#include "aScrollBar.h"

using namespace aLib::aWin;


/*******************************************************************************
* class Fader
*******************************************************************************/
class Fader : public aScrollBar
{
    private:

    public:
        Fader(SysWin *_pParent = nullptr);
        ~Fader();

}; // class Fader
