#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QDialog>

#include "qLights_def.h"

using namespace std;

class Controller;
class SceneButton;


namespace Ui {
class DlgScene;
}


/*******************************************************************************
* class DlgScene
*******************************************************************************/
class DlgDevice;
class Scene;


/*******************************************************************************
* class DlgScene
*******************************************************************************/
class DlgScene : public QDialog
{
    Q_OBJECT

    private:
        Ui::DlgScene        *m_pUi          { nullptr };

    public:
        explicit DlgScene(SceneButton       *_pParent,
                          shared_ptr<Scene> _pScene);
        ~DlgScene();

        QString             name() const;

        bool                isBlackStart() const;


    private:
        void                setCtrls(const shared_ptr<Scene> _pScene);

        virtual void        accept();
        virtual void        reject();

}; // class DlgScene
