/*******************************************************************************
* \file cmdRotate180.h
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
* class CmdRotate180
*******************************************************************************/
class CmdRotate180 : public CmdBase4EqualTiles
{
    public:
        CmdRotate180(shared_ptr<qLayerStack>    _pPreLS,
                     qProgress                  *_pProgress);

        virtual ~CmdRotate180();

    /*******************************************************************************
    * interface for CmdBase4Tiles
    *******************************************************************************/
    protected:
        virtual bool    CalculateTile(Tile *_pTile) override;

}; // class CmdRotate180
