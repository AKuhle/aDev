#pragma once

/*******************************************************************************
* includes
*******************************************************************************/
#include <QTableWidget>



/*******************************************************************************
* class FixtureTable
*******************************************************************************/
class FixtureTable : public QTableWidget
{
    Q_OBJECT

    public:
        FixtureTable(QWidget *parent = nullptr);
        ~FixtureTable();

    protected:
        void            mouseMoveEvent(QMouseEvent *pEvent) override;

}; // class MainWin
