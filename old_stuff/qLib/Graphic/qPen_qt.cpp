/*******************************************************************************
* \file qPenQt.cpp
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
#include "qPen_qt.h"


namespace qLib {
namespace Graphic {
namespace SysQt {


/*******************************************************************************
* qPenQt::qPenQt
*******************************************************************************/
qPenQt::qPenQt(const qColor &_color)
: QPen(QColor::fromRgbF(_color.r(), _color.g(), _color.b(), _color.a()))
{
} // qPenQt::qPenQt


/*******************************************************************************
* qPenQt::~qPenQt
*******************************************************************************/
qPenQt::~qPenQt()
{
} // qPenQt::~qPenQt


/*******************************************************************************
* qPenQt::Color
*******************************************************************************/
qColor qPenQt::color() const
{
    const QColor    &col = QPen::color();

    return qRgba(col.redF(), col.greenF(), col.blueF(), col.alphaF());
} // qPenQt::Color


} // namespace SysQt
} // namespace Graphic
} // namespace qLib


#endif // _USE_QT_
