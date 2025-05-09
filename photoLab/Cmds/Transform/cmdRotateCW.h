/*******************************************************************************
* \file cmdcotateCW.h
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
* class CmdRotateCW
*******************************************************************************/
class CmdRotateCW : public CmdBase4EqualTiles
{
    public:
        CmdRotateCW(shared_ptr<SynchronizedLS>  _pPreLS,
                    aProgressCb                *_pProgressCb = nullptr);

        ~CmdRotateCW() override;


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

}; // class CmdRotateCW
