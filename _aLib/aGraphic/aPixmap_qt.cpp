/*******************************************************************************
* \file aPixmapQt.cpp
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
#include <QBitmap>

#include "aMath/Obj2D/aDimension2D.h"

#include "aUtil/aString.h"
#include "aUtil/aColor.h"

#include "aGraphic/aGraphic_def.h"
#include "aGraphic/aPixmap.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {
namespace SysQt {


/*******************************************************************************
* aPixmapQt::aPixmapQt
*******************************************************************************/
aPixmapQt::aPixmapQt(const aString &_rscName)
: QPixmap(QString(":/%1").arg(_rscName.c_str()))
{
} // aPixmapQt::aPixmapQt


/*******************************************************************************
* aPixmapQt::aPixmapQt
*******************************************************************************/
aPixmapQt::aPixmapQt(const char *_rscName)
: QPixmap(QString(":/%1").arg(_rscName))
{
} // aPixmapQt::aPixmapQt


/*******************************************************************************
* aPixmapQt::aPixmapQt
*******************************************************************************/
aPixmapQt::aPixmapQt(const QPixmap &_pixmap)
: QPixmap(_pixmap)
{
} // aPixmapQt::aPixmapQt


/*******************************************************************************
* aPixmapQt::~aPixmapQt
*******************************************************************************/
aPixmapQt::~aPixmapQt()
{
} // aPixmapQt::~aPixmapQt


/*******************************************************************************
* aPixmapQt::scale
*******************************************************************************/
aPixmap aPixmapQt::scale(const aDimension2D<s32>   &_d)
{
    return aPixmap(QPixmap::scaled(_d.w(), _d.h(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
} // aPixmapQt::scale


/*******************************************************************************
* aPixmapQt::fill
*******************************************************************************/
void aPixmapQt::fill(const aColor &_col)
{
    // save the mask
    QBitmap bmpMask = mask();

    QPixmap::fill(QColor::fromRgbF(_col.r(), _col.g(), _col.b(), _col.a()));

    // restore the mask
    setMask(bmpMask);
} // aPixmapQt::fill


} // namespace SysQt
} // namespace aGraphic
} // namespace aLib

#endif // _USE_QT_
