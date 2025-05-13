/*******************************************************************************
* \file aLineEdit.cpp
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
#include "aLineEdit.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aLineEdit::aLineEdit
*******************************************************************************/
aLineEdit::aLineEdit(SysWin *_pParent)
: aCtrl<QLineEdit>(_pParent)
{
    // connect the handlers
    //connect(this, SIGNAL(clicked(bool)),
    //        this, SLOT(slotClicked(bool)));
} // aLineEdit::_isVisible


/*******************************************************************************
* aLineEdit::~aLineEdit
*******************************************************************************/
aLineEdit::~aLineEdit()
{
} // aLineEdit::~aLineEdit


/*******************************************************************************
* aLineEdit::editText
*******************************************************************************/
aString aLineEdit::editText() const
{
    return aString::fromQString(QLineEdit::text());
} // aLineEdit::editText


/*******************************************************************************
* aLineEdit::slotClicked
*******************************************************************************/
// void aLineEdit::slotClicked(bool /*_bChecked*/)
// {
//     //Control2VarPool();

//     if (ctrlMgr() != nullptr)
//     {
//         ctrlMgr()->sendCtrlMessage(this, MSG_CLICKED);
//     }
// } // aLineEdit::slotClicked


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
