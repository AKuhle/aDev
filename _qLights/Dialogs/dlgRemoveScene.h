/*******************************************************************************
* includes
*******************************************************************************/
#pragma once

#include "aDialog.h"

using namespace aLib::aWin;


namespace Ui {
class DlgRemoveScene;
}


/*******************************************************************************
* class DlgRemoveScene
*******************************************************************************/
class DlgRemoveScene : public aDialog,
                       public aCtrlMgr
{
    Q_OBJECT

    private:
        Ui::DlgRemoveScene     *m_pUi                  { nullptr };
        aString             m_sSceneName;

    public:
        explicit DlgRemoveScene(QWidget        *_pParent,
                                const aString  &_sSceneName);
        ~DlgRemoveScene();


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

}; // class DlgRemoveScene
