/*******************************************************************************
* includes
*******************************************************************************/
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDropEvent>

#include "mainWin.h"
#include "MasterButton.h"
#include "fixture.h"

using namespace std;


/*******************************************************************************
* MasterButton::MasterButton
*******************************************************************************/
MasterButton::MasterButton(QWidget *parent)
: QPushButton(parent)
{
    connect(this, &QPushButton::clicked, this, &MasterButton::onClicked);
} // MasterButton::MasterButton


/*******************************************************************************
* MasterButton::~MasterButton
*******************************************************************************/
MasterButton::~MasterButton()
{
} // MasterButton::~MasterButtonß


/*******************************************************************************
* MasterButton::onClicked
*******************************************************************************/
void MasterButton::onClicked()
{
    u8 u8Bright = MainWin::instance()->masterBrightness();

    u8Bright = ((u8Bright) == 0)?   255 : 0;

    MainWin::instance()->setMasterBrightness(u8Bright, true);

} // MasterButton::onClicked
