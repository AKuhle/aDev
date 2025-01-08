/*******************************************************************************
* \file qStyleFillSolid.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qStyleFillSolid.h"
#include "qPainter.h"



namespace qLib
{
    /*******************************************************************************
    * qStyleFillSolid::qStyleFillSolid
    *******************************************************************************/
    qStyleFillSolid::qStyleFillSolid(const qColor &_color)
    : m_rgbaColor(_color)
	{
    } // qStyleFillSolid::qStyleFillSolid


    /*******************************************************************************
    * qStyleFillSolid::~qStyleFillSolid
    *******************************************************************************/
    qStyleFillSolid::~qStyleFillSolid()
	{
    } // qStyleFillSolid::~qStyleFillSolid


    /*******************************************************************************
    * qStyleFillSolid::Draw
    *******************************************************************************/
    void qStyleFillSolid::Draw(qPainter             &_painter,
                               const qRect2D<s32>   &_boundingRect)
    {
        // _pEdges ignored because just a rect is drawn

        qBrush brush(GetColor());

        _painter.DrawFilledRect(_boundingRect, &brush);
    } // qStyleFillSolid::Draw

} // namespace qLib
