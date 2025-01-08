/*******************************************************************************
* \file qStyleBorderSolid.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qStyleBorderSolid.h"
#include "qPainter.h"
#include "qPen.h"



namespace qLib
{
    /*******************************************************************************
    * qStyleBorderSolid::qStyleBorderSolid
    *******************************************************************************/
    qStyleBorderSolid::qStyleBorderSolid(const qColor    &_color)
    : qStyleBorderBase(),
      m_rgbaColor(_color)
	{
    } // qStyleBorderSolid::qStyleBorderSolid


    /*******************************************************************************
    * qStyleBorderSolid::~qStyleBorderSolid
    *******************************************************************************/
    qStyleBorderSolid::~qStyleBorderSolid()
	{
    } // qStyleBorderSolid::~qStyleBorderSolid


    /*******************************************************************************
    * qStyleBorderSolid::Draw
    *******************************************************************************/
    void qStyleBorderSolid::Draw(qPainter           &_painter,
                                 const qRect2D<s32> &_boundingRect,
                                 const qEdges       &_edges)
    {
        qPen            pen(GetColor());
        s32             i;

        s32             l = _boundingRect.l();
        s32             r = _boundingRect.r1();
        s32             t = _boundingRect.t();
        s32             b = _boundingRect.b1();

        _painter.SetPen(pen);

        // top border
        for (i = 0; i <  _edges.t; i++)
        {
            _painter.DrawLine(l, t + i, r, t + i);
        }

        // bottom border
        for (i = 0; i <  _edges.b; i++)
        {
            _painter.DrawLine(l, b - i, r, b - i);
        }

        // left border
        for (i = 0; i <  _edges.l; i++)
        {
            _painter.DrawLine(l + i, t, l + i, b);
        }

        // right border
        for (i = 0; i <  _edges.r; i++)
        {
            _painter.DrawLine(r - i, t, r - i, b);
        }
    } // qStyleBorderSolid::Draw

} // namespace qLib
