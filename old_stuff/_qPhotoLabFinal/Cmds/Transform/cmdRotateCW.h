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
        CmdRotateCW(shared_ptr<qLayerStack>    _pPreLS,
                    qProgress                  *_pProgress);
                    //qlProgressCallback    *_pProgressCallback);

        virtual ~CmdRotateCW();


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

}; // class CmdRotateCW
