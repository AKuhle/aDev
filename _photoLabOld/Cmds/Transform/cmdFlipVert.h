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
        CmdFlipVert(shared_ptr<SynchronizedLS>  _pPreLS,
                    aProgressCb                 *_pProgressCb = nullptr);

        ~CmdFlipVert() override;

    /*******************************************************************************
    * interface for CmdBase4Tiles
    *******************************************************************************/
    protected:
        virtual bool    calculateTile(Tile *_pTile) override;

}; // class CmdFlipVert
