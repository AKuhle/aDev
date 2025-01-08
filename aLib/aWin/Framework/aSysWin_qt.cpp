/*******************************************************************************
* \file aSysWinQt.cpp
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
#include <QResizeEvent>
#include <QPaintEvent>

#include "aWin/Framework/aSysWin_qt.h"

#include "aMath/Obj2D/aDimension2D.h"

/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {
namespace SysQt {


/*******************************************************************************
* aSysWinQt::aSysWinQt
*******************************************************************************/
aSysWinQt::aSysWinQt(aSysWinQt  *_pParent  /* = nullptr */)
: QWidget(_pParent)
{
    // delete the window when it is beeing closed
    setAttribute(Qt::WA_DeleteOnClose);

    // no frames
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

    // no default background painting
    //setAttribute(Qt::WA_NoSystemBackground, true);
    //setAttribute(Qt::WA_TranslucentBackground, true);
    //setAttribute(Qt::WA_TransparentForMouseEvents, true);
} // aSysWinQt::aSysWinQt


/*******************************************************************************
* aSysWinQt::~aSysWinQt
*******************************************************************************/
aSysWinQt::~aSysWinQt()
{
} // aSysWinQt::~aSysWinQt


/*******************************************************************************
* aSysWinQt::_show
*******************************************************************************/
void aSysWinQt::_show()
{
    show();
} // aSysWinQt::_show


/*******************************************************************************
* aSysWinQt::_hide
*******************************************************************************/
void aSysWinQt::_hide()
{
    hide();
} // aSysWinQt::_hide


/*******************************************************************************
* aSysWinQt::_isVisible
*******************************************************************************/
bool aSysWinQt::_isVisible() const
{
    return isVisible();
} // aSysWinQt::_isVisible


/*******************************************************************************
* aSysWinQt::_setGeometry
*******************************************************************************/
void aSysWinQt::_setGeometry(s32    _x,
                             s32    _y,
                             s32    _w,
                             s32    _h)
{
    setGeometry(_x, _y, _w, _h);
} // aSysWinQt::_setGeometry


/*******************************************************************************
* aSysWinQt::resizeEvent
*******************************************************************************/
void aSysWinQt::resizeEvent(QResizeEvent *_pEvent)
{
    onResizeEvent(aDimension2D<s32> (_pEvent->oldSize().width(), _pEvent->oldSize().height()),
                  aDimension2D<s32> (_pEvent->size().width(), _pEvent->size().height()));
} // aSysWinQt::resizeEvent


/*******************************************************************************
* aSysWinQt::paintEvent
*******************************************************************************/
void aSysWinQt::paintEvent(QPaintEvent */*_pEvent*/)
{
    onPaintEvent();
} // aSysWinQt::paintEvent


} // namespace SysQt
} // namespace aWin
} // namespace aLib


#endif // _USE_QT_
