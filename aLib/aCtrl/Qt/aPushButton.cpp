/*******************************************************************************
* \file aPushButton.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aPushButton.h"
#include "aColor.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* aPushButton::aPushButton
*******************************************************************************/
aPushButton::aPushButton(SysWin *_pParent)
: aButton<QPushButton>(_pParent)
{
    // connect the handlers
    connect(this, SIGNAL(clicked(bool)),
            this, SLOT(slotClicked(bool)));
} // aPushButton::_isVisible


/*******************************************************************************
* aPushButton::~aPushButton
*******************************************************************************/
aPushButton::~aPushButton()
{
} // aPushButton::~aPushButton


/*******************************************************************************
* aPushButton::setText
*******************************************************************************/
void aPushButton::setText(const aString &_sText)
{
    QPushButton::setText(_sText.toQString());
} // aPushButton::setText


/*******************************************************************************
* aPushButton::setText
*******************************************************************************/
void aPushButton::setText(const QString &_sText)
{
    QPushButton::setText(_sText);
} // aPushButton::setText


/*******************************************************************************
* aPushButton::setBackgroundColor
*******************************************************************************/
void aPushButton::setBackgroundColor(const aColor &_color)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Button, _color.toQColor());
    QPushButton::setAutoFillBackground(true);
    QPushButton::setPalette(pal);
    QPushButton::update();
} // aPushButton::setBackgroundColor


/*******************************************************************************
* aPushButton::backgroundColor
*******************************************************************************/
aColor aPushButton::backgroundColor() const
{
    QPalette pal = palette();

    return pal.color(QPalette::Button);
} // aPushButton::backgroundColor


/*******************************************************************************
* aPushButton::slotClicked
*******************************************************************************/
void aPushButton::slotClicked(bool /*_bChecked*/)
{
    //Control2VarPool();

    if (ctrlMgr() != nullptr)
    {
        ctrlMgr()->sendCtrlMessage(this, MSG_CLICKED);
    }
} // aPushButton::slotClicked


} // namespace aWin
} // namespace aLib

#endif //_USE_QT_
