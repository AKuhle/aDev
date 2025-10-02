/*******************************************************************************
* includes
*******************************************************************************/
#include <QMimeData>
#include <QDrag>

#include "fixtureTable.h"

using namespace std;


/*******************************************************************************
* FixtureTable::FixtureTable
*******************************************************************************/
FixtureTable::FixtureTable(QWidget *parent)
: QTableWidget(parent)
{
    setDragEnabled(true);
    setSelectionBehavior(QAbstractItemView::SelectRows);
} // FixtureTable::FixtureTable


/*******************************************************************************
* FixtureTable::~FixtureTable
*******************************************************************************/
FixtureTable::~FixtureTable()
{
} // FixtureTable::~FixtureTable


/*******************************************************************************
* FixtureTable::mouseMoveEvent
*******************************************************************************/
void FixtureTable::mouseMoveEvent(QMouseEvent */*pEvent*/)
{
    if (selectedItems().isEmpty())
        return;

    QMimeData* mimeData = new QMimeData;

    // second column (index 1) holds the fixture name
    mimeData->setText(selectedItems().at(1)->text());

    QDrag *pDrag = new QDrag(this);
    pDrag->setMimeData(mimeData);
    pDrag->exec(Qt::CopyAction);
} // FixtureTable::mouseMoveEvent
