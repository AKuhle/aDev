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
        CmdFlipHori(shared_ptr<SynchronizedLS>  _pPreLS,
                    aProgressCb                 *_pProgressCb = nullptr);

        ~CmdFlipHori() override;


    /*******************************************************************************
    * interface for CmdBase4Tiles
    *******************************************************************************/
    protected:
        bool        calculateTile(Tile *_pTile) override;

}; // class CmdFlipHori
