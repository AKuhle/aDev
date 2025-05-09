/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "QDockWidget"

#include "aWin_def.h"
#include "aDockWinI.h"
#include "aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aDockWin
*******************************************************************************/
class aDockWin : public aBaseWin<QDockWidget>,
                 public aDockWinI
{
    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aDockWin(SysWin *_pParent = nullptr);
        ~aDockWin();

        void                setObjectName(const aString  &_sName) override;
        void                setWindowTitle(const aString  &_sTile) override;

    public:
        void                setCentralWin(SysWin *_pWin) override;
        SysWin*             centralWin() override;

        void                setAllowedAreas(u16 _u16Areas) override;

}; // class aDockWin


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
