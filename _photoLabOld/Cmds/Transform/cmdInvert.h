/*******************************************************************************
* \file cmdInvert.h
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
* class CmdInvert
*******************************************************************************/
class CmdInvert : public CmdBase4EqualTiles
{
    public:
        CmdInvert(shared_ptr<SynchronizedLS>    _pPreLS,
                  aProgressCb                   *_pProgressCb = nullptr);

        ~CmdInvert() override;


    /*******************************************************************************
    * interface for CmdBase4Tiles
    *******************************************************************************/
    protected:
        virtual bool    calculateTile(Tile *_pTile) override;

}; // class CmdInvert
