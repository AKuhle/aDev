/*******************************************************************************
* includes
*******************************************************************************/
#pragma once

#include <QStringListModel>
#include <QStyledItemDelegate>

#include "aDialog.h"

class Chase;

using namespace aLib;
using namespace aLib::aWin;


namespace Ui {
class DlgAddChase;
}


/*******************************************************************************
* class DlgAddChase
*******************************************************************************/
class DlgAddChase : public aDialog,
                    public aCtrlMgr
{
    Q_OBJECT

    private:
        Ui::DlgAddChase     *m_pUi              { nullptr };
        s32                 m_s32ChaseBtnIdx    { -1 };
        aString             m_sChaseName;

        QStringList         m_lstData           { 5 };
        QStringListModel    m_model             { m_lstData };


    public:
        explicit DlgAddChase(QWidget        *_pParent,
                             s32            _s32ChaseBtnIdx,
                             const aString  &_sChaseName);
        ~DlgAddChase();

        //aString             chaseName() const       { return m_sChaseName; }
        aString             chaseName() const       { return "m_sChaseName"; }


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

}; // class DlgAddChase
