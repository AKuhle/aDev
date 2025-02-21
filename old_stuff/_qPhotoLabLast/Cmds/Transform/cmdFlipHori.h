/*******************************************************************************
* \file cmdFlipHori.h
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
#include "cmdBase4EqualTiles.h"
#include "tile.h"



/*******************************************************************************
* class CmdFlipHori
*******************************************************************************/
class CmdFlipHori : public CmdBase4EqualTiles
{
    public:
        CmdFlipHori(shared_ptr<qLayerStack> _pPreLS,
                    qProgress               *_pProgress);

        virtual ~CmdFlipHori();

    /*******************************************************************************
    * interface for CmdBase4Tiles
    *******************************************************************************/
    protected:
        virtual bool    CalculateTile(Tile *_pTile) override;

}; // class CmdFlipHori
