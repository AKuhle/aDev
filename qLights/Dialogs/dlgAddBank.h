#ifndef DLGADDBANK_H
#define DLGADDBANK_H

#include "aDialog.h"

using namespace aLib::aWin;


namespace Ui {
class DlgAddBank;
}


/*******************************************************************************
* CtrlPanel::CtrlPanel
*******************************************************************************/
class DlgAddBank : public aDialog,
                   public aCtrlMgr
{
    Q_OBJECT

    private:
        Ui::DlgAddBank      *m_pUi          { nullptr };
        aString             &m_sBankName;

    public:
        explicit DlgAddBank(QWidget     *_pParent,
                            aString     &_sBankName);
        ~DlgAddBank();


    /*******************************************************************************
    * aDialog interface
    *******************************************************************************/
    public:
        void                onAccepted() override;


    /*******************************************************************************
    * aCtrlMgr interface
    *******************************************************************************/
    public:
        void                onRegisterCtrl() override;
        void                onUpdateCtrl(aCtrlI *_pCtrl) override;


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        virtual bool        onCreateWin() override;

};

#endif // DLGADDBANK_H
