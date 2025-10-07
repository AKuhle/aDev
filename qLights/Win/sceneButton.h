#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QPushButton>

#include "fixture.h"

class Scene;


/*******************************************************************************
* class SceneButton
*******************************************************************************/
class SceneButton : public QPushButton
{
    Q_OBJECT

    private:
        shared_ptr<Scene>     m_pScene;

    public:
        SceneButton(QWidget *parent = nullptr);
        ~SceneButton();

        void                init();

        void                setScene(shared_ptr<Scene> _pScene);
        shared_ptr<Scene>   scene()     { return m_pScene; }


    private slots:
        void                showContextMenu(const QPoint &_pos);
        void                onAssignScene();
        void                onClicked();
}; // class MainWin
