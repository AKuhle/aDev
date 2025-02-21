/*******************************************************************************
* \file tile.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "qLib.h"


/*******************************************************************************
* forwards
*******************************************************************************/
using namespace std;
using namespace qLib;


/*******************************************************************************
* class psCmd
*******************************************************************************/
class Tile
{
    private:
        const qLayerI       *m_pPreLayer;
        qLayerI             *m_pPostLayer;
        qRect2D<s32>        m_r2dTile;

    public:
        Tile(const qLayerI      *_pPreLayer,
             qLayerI            *_pPostLayer,
             const qRect2D<s32> &_r2dTile);
        virtual ~Tile();

        // layers
        const qLayerI*      PreLayer() const    { return m_pPreLayer; }
        qLayerI*            PostLayer() const   { return m_pPostLayer; }

        s32                 MinX() const		{ return m_r2dTile.l(); }
        s32                 MaxX() const		{ return m_r2dTile.r1(); }
        s32                 MinY() const		{ return m_r2dTile.t(); }
        s32                 MaxY() const		{ return m_r2dTile.b1(); }
        s32                 w() const			{ return m_r2dTile.w(); }
        s32                 h() const			{ return m_r2dTile.h(); }
}; // class psCmd
