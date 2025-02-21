/*******************************************************************************
* \file qPixmap.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qPixmap.h"
#include "qColor.h"
#include "qString16.h"


namespace qLib
{
    /*******************************************************************************
    * qPixmap::qPixmap
    *******************************************************************************/
    qPixmap::qPixmap(const qString16 &_rscName)
    : QPixmap(QString(":/%1").arg(_rscName.c_str()))
	{
    } // qPixmap::qPixmap


    /*******************************************************************************
    * qPixmap::qPixmap
    *******************************************************************************/
    qPixmap::qPixmap(const char *_rscName)
    : QPixmap(QString(":/%1").arg(_rscName))
    {
    } // qPixmap::qPixmap


    /*******************************************************************************
    * qPixmap::qPixmap
    *******************************************************************************/
    qPixmap::qPixmap(const QPixmap &_pixmap)
    : QPixmap(_pixmap)
    {
    } // qPixmap::qPixmap


    /*******************************************************************************
    * qPixmap::~qPixmap
    *******************************************************************************/
    qPixmap::~qPixmap()
    {
    } // qPixmap::~qPixmap


    /*******************************************************************************
    * qPixmap::Scale
    *******************************************************************************/
    qPixmap qPixmap::Scale(const qDimension2D<s32>   &_d)
    {
        return qPixmap(scaled(_d.w, _d.h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    } // qPixmap::Scale


    /*******************************************************************************
    * qPixmap::Fill
    *******************************************************************************/
    void qPixmap::Fill(const qColor &_col)
    {
        // save the mask
        QBitmap bmpMask = mask();

        fill(QColor::fromRgbF(_col.r, _col.g, _col.b, _col.a));

        // restore the mask
        setMask(bmpMask);
    } // qPixmap::Fill

} // namespace qLib
