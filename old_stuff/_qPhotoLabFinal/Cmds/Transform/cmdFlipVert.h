/*******************************************************************************
* \file cmdFlipVert.h
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
* class CmdFlipVert
*******************************************************************************/
class CmdFlipVert : public CmdBase4EqualTiles
{
    public:
        CmdFlipVert(shared_ptr<qLayerStack> _pPreLS,
                    qProgress               *_pProgress);

        virtual ~CmdFlipVert();

    /*******************************************************************************
    * interface for CmdBase4Tiles
    *******************************************************************************/
    protected:
        virtual bool    CalculateTile(Tile *_pTile) override;

}; // class CmdFlipVert
