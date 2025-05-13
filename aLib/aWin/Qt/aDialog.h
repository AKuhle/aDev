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
#include <QDialog>

#include "aWin_def.h"
#include "aBaseWin.h"
#include "aDialogI.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aDialog
*******************************************************************************/
class aDialog : public aBaseWin<QDialog>,
                public aDialogI
{
    Q_OBJECT

    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aDialog(SysWin *_pParent = nullptr);
        virtual ~aDialog();

    public:
        DialogReturn        showModal() override;

    private slots:
        void                slotAccepted();
}; // class aDialog


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
