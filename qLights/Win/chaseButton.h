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

        void            init();
}; // class MainWin
