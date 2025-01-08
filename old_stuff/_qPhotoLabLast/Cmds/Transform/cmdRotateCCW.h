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
        CmdRotateCCW(shared_ptr<qLayerStack>    _pPreLS,
                     qProgress                  *_pProgress);

        virtual ~CmdRotateCCW();


    /*******************************************************************************
    * interface for CmdBase4Tiles
    *******************************************************************************/
    protected:
        virtual bool    CalculateTile(Tile *_pTile) override;


    /*******************************************************************************
    * interface of Cmd
    *******************************************************************************/
    public:
        virtual bool    Prepare() override;

}; // class CmdRotateCCW
