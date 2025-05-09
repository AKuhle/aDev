/*******************************************************************************
* \file cmdcotateCCW.h
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
* class CmdRotateCCW
*******************************************************************************/
class CmdRotateCCW : public CmdBase4EqualTiles
{
    public:
        CmdRotateCCW(shared_ptr<SynchronizedLS> _pPreLS,
                     aProgressCb                *_pProgressCb = nullptr);

        ~CmdRotateCCW() override;


    /*******************************************************************************
    * interface for CmdBase4Tiles
    *******************************************************************************/
    protected:
        virtual bool    calculateTile(Tile *_pTile) override;


    /*******************************************************************************
    * interface of Cmd
    *******************************************************************************/
    public:
        virtual bool    prepare() override;

}; // class CmdRotateCCW
