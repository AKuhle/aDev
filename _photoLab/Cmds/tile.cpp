/*******************************************************************************
* \file tile.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "tile.h"


/*******************************************************************************
* Tile::Tile
*******************************************************************************/
Tile::Tile(const aLayerI        *_pPreLayer,
           aLayerI              *_pPostLayer,
           const aRect2D<s32>   &_r2dTile)
: m_pPreLayer(_pPreLayer),
  m_pPostLayer(_pPostLayer),
  m_r2dTile(_r2dTile)
{
} // Tile::Tile



/*******************************************************************************
* Tile::~Tile
*******************************************************************************/
Tile::~Tile()
{
} // Tile::~Tile
