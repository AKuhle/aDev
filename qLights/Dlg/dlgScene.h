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


/*******************************************************************************
* class DlgScene
*******************************************************************************/
class DlgScene : public QDialog
{
    Q_OBJECT

    private:
        Ui::DlgScene        *m_pUi          { nullptr };

    public:
        explicit DlgScene(SceneButton *_pParent);
        ~DlgScene();

        QString             name() const;

    private:
        virtual void        accept();
        virtual void        reject();
}; // class DlgScene
