/*******************************************************************************
* \file qSpacer.h
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
#include "qCtrlBase.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qPixmap;


    /*******************************************************************************
    * class qSpacer
    *******************************************************************************/
    class qSpacer : public qCtrlBase
    {
        DeclareTypeProperty(enumOrientation, e, Orientation, enumOrientation::Hori)

        public:
            qSpacer(qWin  *_pParent,
                    u32    _u32Id = SYS_ID_SPACER);
            virtual ~qSpacer();


    }; // class qSpacer

} // namespace qLib
