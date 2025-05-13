/*******************************************************************************
* \file aDialog.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aDialog.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aDialog::aDialog
*******************************************************************************/
aDialog::aDialog(SysWin *_pParent)
: aBaseWin<QDialog>(_pParent /*= nullptr*/)
{
    // connect the handlers
    connect(this, SIGNAL(accepted()),
            this, SLOT(slotAccepted()));
} // aDialog::_isVisible


/*******************************************************************************
* aDialog::~aDialog
*******************************************************************************/
aDialog::~aDialog()
{
} // aDialog::~aDialog


/*******************************************************************************
* aDialog::ShowModal
*******************************************************************************/
DialogReturn aDialog::showModal()
{
    switch (exec())
    {
        case QDialog::DialogCode::Accepted:
            return DialogReturn::accepted;

        case QDialog::DialogCode::Rejected:
            return DialogReturn::rejected;
    }

    return DialogReturn::rejected;
} // aDialog::ShowModal


/*******************************************************************************
* aDialog::slotAccepted
*******************************************************************************/
void aDialog::slotAccepted()
{
    onAccepted();
} // aDialog::slotAccepted


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
