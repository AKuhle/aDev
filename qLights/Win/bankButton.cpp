/*******************************************************************************
* includes
*******************************************************************************/
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDropEvent>

#include "mainWin.h"
#include "bankButton.h"
#include "fixture.h"

using namespace std;


/*******************************************************************************
* BankButton::BankButton
*******************************************************************************/
BankButton::BankButton(QWidget *parent)
: QPushButton(parent)
{
    setAcceptDrops(true);

    connect(this, &QPushButton::clicked, this, &BankButton::onClicked);
} // BankButton::BankButton


/*******************************************************************************
* BankButton::~BankButton
*******************************************************************************/
BankButton::~BankButton()
{
} // BankButton::~BankButtonß


/*******************************************************************************
* BankButton::setFixture
*******************************************************************************/
void BankButton::setFixture(shared_ptr<Fixture> _pFixture)
{
    setFixedHeight(32);
    setIconSize(QSize(30, 30));

    m_pFixture = _pFixture;

    if (m_pFixture)
    {
        setIcon(QIcon(m_pFixture->device()->pixmap()));
        setText(m_pFixture->name());
    }
    else
    {
        setIcon(QIcon());
        setText("");
    }
} // BankButton::setFixture


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

        MainWin::instance()->assignFixture(this, sFixtureName);
    }
} // BankButton::dropEvent


/*******************************************************************************
* BankButton::onClicked
*******************************************************************************/
void BankButton::onClicked()
{
    if (m_pFixture)
    {
        MainWin::instance()->assignFaders(m_pFixture);
    }
} // BankButton::onClicked
