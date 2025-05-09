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
        CmdRotate180(shared_ptr<SynchronizedLS> _pPreLS,
                     aProgressCb                *_pProgressCb = nullptr);

        ~CmdRotate180() override;


    /*******************************************************************************
    * interface for CmdBase4Tiles
    *******************************************************************************/
    protected:
        virtual bool    calculateTile(Tile *_pTile) override;

}; // class CmdRotate180
