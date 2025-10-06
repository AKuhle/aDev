/*******************************************************************************
* \file ScribbleStrip.cpp
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "scribbleStrip.h"

using namespace aFrame;


/*******************************************************************************
* ScribbleStrip::ScribbleStrip
*******************************************************************************/
ScribbleStrip::ScribbleStrip(QWidget *_pParent)
: QLabel(_pParent)
{
} // ScribbleStrip::ScribbleStrip


/*******************************************************************************
* ScribbleStrip::~ScribbleStrip
*******************************************************************************/
ScribbleStrip::~ScribbleStrip()
{
} // ScribbleStrip::~ScribbleStrip


/*******************************************************************************
* ScribbleStrip::setPixmap
*******************************************************************************/
void ScribbleStrip::setPixmap(const QPixmap &_pix)
{
    QPixmap scaledPixmap = _pix.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    if (!scaledPixmap.isNull())
        QLabel::setPixmap(scaledPixmap);
} // ScribbleStrip::setPixmap
