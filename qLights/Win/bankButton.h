#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QPushButton>



/*******************************************************************************
* class BankButton
*******************************************************************************/
class BankButton : public QPushButton
{
    Q_OBJECT

    public:
        BankButton(QWidget *parent = nullptr);
        ~BankButton();

    protected:
        void        dragEnterEvent(QDragEnterEvent *_pEvent) override;
        void        dropEvent(QDropEvent *_pEvent) override;

}; // class MainWin
