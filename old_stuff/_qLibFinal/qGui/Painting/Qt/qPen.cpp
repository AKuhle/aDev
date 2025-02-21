/*******************************************************************************
* \file qPen.cpp
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
#include "qPen.h"
#include "qColor.h"



namespace qLib
{
    /*******************************************************************************
    * qPen::qPen
    *******************************************************************************/
    qPen::qPen(const qColor &_col)
    : QPen(QColor::fromRgbF(_col.r, _col.g, _col.b, _col.a))
	{
    } // qPen::qPen


    /*******************************************************************************
    * qPen::~qPen
    *******************************************************************************/
    qPen::~qPen()
	{
    } // qPen::~qPen


    /*******************************************************************************
    * qPen::GetColor
    *******************************************************************************/
    qColor qPen::GetColor() const
    {
        const QColor    &col = color();

        return qColor(col.redF(), col.greenF(), col.blueF(), col.alphaF());
    } // qPen::GetColor

} // namespace qLib


#endif // _USE_QT_
