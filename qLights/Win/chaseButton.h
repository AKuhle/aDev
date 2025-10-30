#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QPushButton>

#include "aFrame_def.h"
#include "chase.h"

using namespace std;


/*******************************************************************************
* class ChaseButton
*******************************************************************************/
class ChaseButton : public QPushButton
{
    Q_OBJECT

    private:
        shared_ptr<Chase>     m_pChase;

    public:
        ChaseButton(QWidget *parent = nullptr);
        ~ChaseButton();

        void                init();

        void                setChase(shared_ptr<Chase> _pChase);
        shared_ptr<Chase>   chase()     { return m_pChase; }

    private slots:
        void                showContextMenu(const QPoint &_pos);
        void                onAssignChase();
        void                onRemoveChase();
        void                onClicked();
}; // class MainWin
