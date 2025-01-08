/*******************************************************************************
* \file aPenQt.cpp
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
#include "aUtil/aColor.h"

#include "aPen_qt.h"


namespace aLib {
namespace aGraphic {
namespace SysQt {


/*******************************************************************************
* aPenQt::aPenQt
*******************************************************************************/
aPenQt::aPenQt(const aColor &_color)
: QPen(QColor::fromRgbF(_color.r(), _color.g(), _color.b(), _color.a()))
{
} // aPenQt::aPenQt


/*******************************************************************************
* aPenQt::~aPenQt
*******************************************************************************/
aPenQt::~aPenQt()
{
} // aPenQt::~aPenQt


/*******************************************************************************
* aPenQt::Color
*******************************************************************************/
aColor aPenQt::color() const
{
    const QColor    &col = QPen::color();

    return aColor(col.redF(), col.greenF(), col.blueF(), col.alphaF());
} // aPenQt::Color


} // namespace SysQt
} // namespace aGraphic
} // namespace aLib


#endif // _USE_QT_
