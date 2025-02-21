/*******************************************************************************
* \file qStyleFillGradient.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qStyleFillGradient.h"
#include "qPainter.h"



namespace qLib
{
    /*******************************************************************************
    * qStyleFillGradient::qStyleFillGradient
    *******************************************************************************/
    qStyleFillGradient::qStyleFillGradient(const qColor &_colStart,
                                           const qColor &_colEnd)
    : m_rgbaColorStart(_colStart),
      m_rgbaColorEnd(_colEnd)
	{
    } // qStyleFillGradient::qStyleFillGradient


    /*******************************************************************************
    * qStyleFillGradient::~qStyleFillGradient
    *******************************************************************************/
    qStyleFillGradient::~qStyleFillGradient()
	{
    } // qStyleFillGradient::~qStyleFillGradient


    /*******************************************************************************
    * qStyleFillGradient::Draw
    *******************************************************************************/
    void qStyleFillGradient::Draw(qPainter             &_painter,
                                  const qRect2D<s32>   &_boundingRect)
    {
        // _pEdges ignored because just a rect is drawn

        _painter.DrawGradientRect(_boundingRect,
                                  _boundingRect.lb(), _boundingRect.lt(),
                                  m_rgbaColorStart, m_rgbaColorEnd);
    } // qStyleFillGradient::Draw

} // namespace qLib
