/*******************************************************************************
* includes
*******************************************************************************/
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDropEvent>

#include "bankButton.h"

using namespace std;


/*******************************************************************************
* BankButton::BankButton
*******************************************************************************/
BankButton::BankButton(QWidget *parent)
: QPushButton(parent)
{
    setAcceptDrops(true);
} // BankButton::BankButton


/*******************************************************************************
* BankButton::~BankButton
*******************************************************************************/
BankButton::~BankButton()
{
} // BankButton::~BankButton


/*******************************************************************************
* BankButton::dragEnterEvent
*******************************************************************************/
void BankButton::dragEnterEvent(QDragEnterEvent *_pEvent)
{
    if (_pEvent->mimeData()->hasText())
    {
        _pEvent->acceptProposedAction();
    }
} // BankButton::dragEnterEvent


/*******************************************************************************
* BankButton::dropEvent
*******************************************************************************/
void BankButton::dropEvent(QDropEvent *_pEvent)
{
    if (_pEvent->mimeData()->hasText())
    {
        QString     sFixtureName = _pEvent->mimeData()->text();

        // show fixture name on button
        setText(sFixtureName);
        _pEvent->acceptProposedAction();
    }
} // BankButton::dropEvent
