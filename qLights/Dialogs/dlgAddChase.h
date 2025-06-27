/*******************************************************************************
* includes
*******************************************************************************/
#pragma once

#include <QStringListModel>
#include <QStyledItemDelegate>

#include "aDialog.h"

class Chase;

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
        aString             m_sChaseName;

        QStringList         m_lstData           { 5 };
        QStringListModel    m_model             { m_lstData };

        shared_ptr<Chase>   m_pChase;

    public:
        explicit DlgAddChase(QWidget        *_pParent,
                             const aString  &_sChaseName);
        ~DlgAddChase();

        aString             chaseName() const       { return m_sChaseName; }
        shared_ptr<Chase>   chase() const           { return m_pChase; }


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
