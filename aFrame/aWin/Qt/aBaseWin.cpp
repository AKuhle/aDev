/*******************************************************************************
* \file aBaseWin.cpp
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
#include "aBaseWin.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aBaseWin::aBaseWin
*******************************************************************************/
aBaseWin::aBaseWin(SysWin *_pParent)
: QWidget(_pParent),
  aBaseWin_i(this)
{
    // delete the window when it is beeing closed
    setAttribute(Qt::WA_DeleteOnClose);

    // no background painting
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);

    // Optional: Fenster im Vordergrund halten
    // setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);

    // install the event filter
    installEventFilter(this);
} // aBaseWin::aBaseWin


/*******************************************************************************
* aBaseWin::~aBaseWin
*******************************************************************************/
aBaseWin::~aBaseWin()
{
} // aBaseWin::~aBaseWin


/*******************************************************************************
* aBaseWin::setParent
*******************************************************************************/
void aBaseWin::setParent(SysWin *_pParent)
{
    QWidget::setParent(_pParent);
} // aBaseWin::setParent


/*******************************************************************************
* aBaseWin::parent
*******************************************************************************/
SysWin* aBaseWin::parent() const
{
    return QWidget::parentWidget();
} // aBaseWin::parent


/*******************************************************************************
* aBaseWin::update
*******************************************************************************/
void aBaseWin::update()
{
    QWidget::update();
} // aBaseWin::update


/*******************************************************************************
* aBaseWin::repaint
*******************************************************************************/
void aBaseWin::repaint()
{
    QWidget::repaint();
} // aBaseWin::repaint


/*******************************************************************************
* aBaseWin::setVisible
*******************************************************************************/
void aBaseWin::setVisible(bool _bVisible)
{
    QWidget::setVisible(_bVisible);
} // aBaseWin::setVisible


/*******************************************************************************
* aBaseWin::isVisible
*******************************************************************************/
bool aBaseWin::isVisible() const
{
    return QWidget::isVisible();
} // aBaseWin::isVisible


/*******************************************************************************
* aBaseWin::isMinimized
*******************************************************************************/
bool aBaseWin::isMinimized() const
{
    return QWidget::isMinimized();
} // aBaseWin::isMinimized


/*******************************************************************************
* aBaseWin::isMaximized
*******************************************************************************/
bool aBaseWin::isMaximized() const
{
    return QWidget::isMaximized();
} // aBaseWin::isMaximized


/*******************************************************************************
* aBaseWin::showMinimized
*******************************************************************************/
void aBaseWin::showMinimized()
{
    return QWidget::showMinimized();
} // aBaseWin::showMaximized


/*******************************************************************************
* aBaseWin::showMaximized
*******************************************************************************/
void aBaseWin::showMaximized()
{
    return QWidget::showMaximized();
} // aBaseWin::showMaximized


/*******************************************************************************
* aBaseWin::setMouseTracking
*******************************************************************************/
void aBaseWin::setMouseTracking(bool _bEnable)
{
    return QWidget::setMouseTracking(_bEnable);
} // aBaseWin::setMouseTracking


/*******************************************************************************
* aBaseWin::setMinW
*******************************************************************************/
void aBaseWin::setMinW(s32 _s32MinW)
{
    QWidget::setMinimumWidth(_s32MinW);
} // aBaseWin::setMinW


/*******************************************************************************
* aBaseWin::setMinH
*******************************************************************************/
void aBaseWin::setMinH(s32 _s32MinH)
{
    QWidget::setMinimumHeight(_s32MinH);
} // aBaseWin::setMinH


/*******************************************************************************
* aBaseWin::setMaxW
*******************************************************************************/
void aBaseWin::setMaxW(s32 _s32MaxW)
{
    QWidget::setMaximumWidth(_s32MaxW);
} // aBaseWin::setMaxW


/*******************************************************************************
* aBaseWin::setMaxH
*******************************************************************************/
void aBaseWin::setMaxH(s32 _s32MaxH)
{
    QWidget::setMaximumHeight(_s32MaxH);
} // aBaseWin::setMaxH


/*******************************************************************************
* aBaseWin::setGeometry
*******************************************************************************/
void aBaseWin::setGeometry(s32 _s32X,
                           s32 _s32Y,
                           s32 _s32W,
                           s32 _s32H)
{
    QWidget::setGeometry(_s32X, _s32Y, _s32W, _s32H);
} // aBaseWin::setGeometry


/*******************************************************************************
* aBaseWin::geometryRect
*******************************************************************************/
aRect aBaseWin::geometryRect() const
{
    QRect r = QWidget::frameGeometry();

    return aRect(r.left(), r.right(), r.width(), r.height());
} // aBaseWin::geometryRect


/*******************************************************************************
* aBaseWin::geometryW
*******************************************************************************/
s32 aBaseWin::geometryW() const
{
    return QWidget::frameGeometry().width();
} // aBaseWin::geometryW


/*******************************************************************************
* aBaseWin::geometryH
*******************************************************************************/
s32 aBaseWin::geometryH() const
{
    return QWidget::frameGeometry().height();
} // aBaseWin::geometryH



} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_











// /*******************************************************************************
// * aBaseWin::closeWin
// *******************************************************************************/
// template<class T>
// bool aBaseWin::closeWin()
// {
//     if (onCloseWin())
//     {
//         T::close();

//         return true;
//     }

//     return false;
// } // aBaseWin::closeWin



// /*******************************************************************************
// * aBaseWin::setWinTitle
// *******************************************************************************/
// template<class T>
// void aBaseWin::setWinTitle(const aString &_sTitle)
// {
//     T::setWindowTitle(_sTitle.toQString());
// } // aBaseWin::setWinTitle



// /*******************************************************************************
// * aBaseWin::setMinSize
// *******************************************************************************/
// template<class T>
// void aBaseWin::setMinSize(const aDimension2D<s32> &_dim)
// {
//     T::setMinimumSize(_dim.w(), _dim.h());
// } // aBaseWin::setMinSize


// /*******************************************************************************
// * aBaseWin::setMinSize
// *******************************************************************************/
// template<class T>
// void aBaseWin::setMinSize(s32  _s32W,
//                              s32  _s32H)
// {
//     T::setMinimumSize(_s32W, _s32H);
// } // aBaseWin::setMinSize


// /*******************************************************************************
// * aBaseWin::setMinW
// *******************************************************************************/
// template<class T>
// void aBaseWin::setMinW(s32  _s32W)
// {
//     T::setMinimumWidth(_s32W);
// } // aBaseWin::setMinW


// /*******************************************************************************
// * aBaseWin::setMinH
// *******************************************************************************/
// template<class T>
// void aBaseWin::setMinH(s32  _s32H)
// {
//     T::setMinimumHeight(_s32H);
// } // aBaseWin::setMinH


// /*******************************************************************************
// * aBaseWin::setFixedW
// *******************************************************************************/
// template<class T>
// void aBaseWin::setFixedW(s32  _s32W)
// {
//     T::setFixedWidth(_s32W);
// } // aBaseWin::setFixedW


// /*******************************************************************************
// * aBaseWin::setFixedH
// *******************************************************************************/
// template<class T>
// void aBaseWin::setFixedH(s32  _s32H)
// {
//     T::setFixedHeight(_s32H);
// } // aBaseWin::setFixedH


// /*******************************************************************************
// * aBaseWin::clientRect
// *******************************************************************************/
// template<class T>
// aRect2D<s32> aBaseWin::clientRect() const
// {
//     QRect r = T::geometry();

//     aRect2D<s32>    r2d(0, 0,r.width(), r.height());

//     return r2d;
// } // aBaseWin::clientRect


// /*******************************************************************************
// * aBaseWin::clientW
// *******************************************************************************/
// template<class T>
// s32 aBaseWin::clientW() const
// {
//     return T::geometry().width();
// } // aBaseWin::clientW


// /*******************************************************************************
// * aBaseWin::clientH
// *******************************************************************************/
// template<class T>
// s32 aBaseWin::clientH() const
// {
//     return T::geometry().height();
// } // aBaseWin::clientH
