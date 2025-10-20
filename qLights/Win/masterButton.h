#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QPushButton>

#include "fixture.h"


/*******************************************************************************
* class MasterButton
*******************************************************************************/
class MasterButton : public QPushButton
{
    Q_OBJECT

    public:
        MasterButton(QWidget *parent = nullptr);
        ~MasterButton();


    private slots:
        void        onClicked();

}; // class MainWin
