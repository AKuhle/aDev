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
#include "aLib_def.h"

#include "aRect2D.h"
#include "aLayerStack.h"

using namespace aLib;
using namespace aLib::aMath;
using namespace aLib::aPic;


/*******************************************************************************
* class Tile
*******************************************************************************/
class Tile
{
    private:
        const aLayerI   *m_pPreLayer;
        aLayerI         *m_pPostLayer;
        aRect2D<s32>    m_r2dTile;

    public:
        Tile(const aLayerI      *_pPreLayer,
             aLayerI            *_pPostLayer,
             const aRect2D<s32> &_r2dTile);
        virtual ~Tile();

        // layers
        const aLayerI*  preLayer() const    { return m_pPreLayer; }
        aLayerI*        postLayer() const   { return m_pPostLayer; }

        s32             minX() const		{ return m_r2dTile.l(); }
        s32             maxX() const		{ return m_r2dTile.r1(); }
        s32             minY() const		{ return m_r2dTile.t(); }
        s32             maxY() const		{ return m_r2dTile.b1(); }
        s32             w() const			{ return m_r2dTile.w(); }
        s32             h() const			{ return m_r2dTile.h(); }
}; // class Tile
