#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QPushButton>

#include "fixture.h"


/*******************************************************************************
* class BankButton
*******************************************************************************/
class BankButton : public QPushButton
{
    Q_OBJECT

    private:
        shared_ptr<Fixture>     m_pFixture;

    public:
        BankButton(QWidget *parent = nullptr);
        ~BankButton();

        void        setFixture(shared_ptr<Fixture> _pFixture);


    protected:
        void        dragEnterEvent(QDragEnterEvent *_pEvent) override;
        void        dropEvent(QDropEvent *_pEvent) override;


    private slots:
        void        onClicked();

}; // class MainWin
