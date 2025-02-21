/*******************************************************************************
* \file ImageBar.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "photoLab_defs.h"

#include "mainWin.h"
#include "ImageBar.h"
#include "aToolButton.h"
#include "aLayoutHoriVert.h"


/*******************************************************************************
* ImageBar::ImageBar
*******************************************************************************/
ImageBar::ImageBar(aBaseWin     *_pParent   /*= nullptr*/)
: aCtrlBar(_pParent)
{
} // ImageBar::ImageBar


/*******************************************************************************
* ImageBar::~ImageBar
*******************************************************************************/
ImageBar::~ImageBar()
{
} // ImageBar::~ImageBar


/*******************************************************************************
* ImageBar::onRegisterCtrl
*******************************************************************************/
void ImageBar::onRegisterCtrl()
{
    // get the layout
    aLayoutHoriVert *pLayout    = layoutHoriVert();
    CHECK_PRE_CONDITION_VOID(pLayout != nullptr);

    MainWin         &mw         = getMainWin();
    aToolButton     *pBtn;

    // flip hori
    pBtn = new aToolButton(this, ID_IMAGE_FLIP_HORI);
    pBtn->create();
    pBtn->setPixmap("PhotoLab/flipHori.png");
    pLayout->addChild(pBtn);
    mw.registerCtrl(pBtn);

    // flip vert
    pBtn = new aToolButton(this, ID_IMAGE_FLIP_VERT);
    pBtn->create();
    pBtn->setPixmap("PhotoLab/flipVert.png");
    pLayout->addChild(pBtn);
    mw.registerCtrl(pBtn);

    // rotate ccw
    pBtn = new aToolButton(this, ID_IMAGE_ROTATE_CCW);
    pBtn->create();
    pBtn->setPixmap("PhotoLab/rotateCCW.png");
    pLayout->addChild(pBtn);
    mw.registerCtrl(pBtn);

    // rotate cw
    pBtn = new aToolButton(this, ID_IMAGE_ROTATE_CW);
    pBtn->create();
    pBtn->setPixmap("PhotoLab/rotateCW.png");
    pLayout->addChild(pBtn);
    mw.registerCtrl(pBtn);

    // rotate 180°
    pBtn = new aToolButton(this, ID_IMAGE_ROTATE_180);
    pBtn->create();
    pBtn->setPixmap("PhotoLab/rotate180.png");
    pLayout->addChild(pBtn);
    mw.registerCtrl(pBtn);

    // invert
    pBtn = new aToolButton(this, ID_IMAGE_FLIP_INVERT);
    pBtn->create();
    pBtn->setPixmap("PhotoLab/invert.png");
    pLayout->addChild(pBtn);
    mw.registerCtrl(pBtn);

} // ImageBar::onRegisterCtrl


/*******************************************************************************
* ImageBar::onUpdateCtrl
*******************************************************************************/
void ImageBar::onUpdateCtrl(aCtrl */*_pCtrl*/)
{

} // ImageBar::onUpdateCtrl


/*******************************************************************************
* ImageBar::onCtrlClicked
*******************************************************************************/
void ImageBar::onCtrlClicked(aCtrl */*_pCtrl*/)
{
} // ImageBar::onCtrlClicked
