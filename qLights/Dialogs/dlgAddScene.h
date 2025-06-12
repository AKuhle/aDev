/*******************************************************************************
* includes
*******************************************************************************/
#pragma once

#include "aDialog.h"

using namespace aLib::aWin;


namespace Ui {
class DlgAddScene;
}


/*******************************************************************************
* class DlgAddScene
*******************************************************************************/
class DlgAddScene : public aDialog,
                    public aCtrlMgr
{
    Q_OBJECT

    private:
        Ui::DlgAddScene     *m_pUi                  { nullptr };
        aString             &m_sSceneName;

    public:
        explicit DlgAddScene(QWidget     *_pParent,
                             aString     &_sSceneName);
        ~DlgAddScene();

        aString             sceneName() const       { return m_sSceneName; }


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

}; // class DlgAddScene
