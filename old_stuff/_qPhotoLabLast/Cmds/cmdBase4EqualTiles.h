/*******************************************************************************
* \file cmdBase4EqualTiles.h
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
#include "cmdBase4Tiles.h"



/*******************************************************************************
* class CmdBase4EqualTiles
*******************************************************************************/
class CmdBase4EqualTiles : public CmdBase4Tiles
{
    protected:
        CmdBase4EqualTiles(s32                      _s32CmdID,
                           const qString16          &_sCmdName,
                           enumCmdType              _eCmdType,
                           shared_ptr<qLayerStack>  _pPreLS,
                           qProgress                *_pProgress);


    /*******************************************************************************
    * interface for CmdBase4Tiles
    *******************************************************************************/
    protected:
        bool            OnCreateTiles(qUniquePtrDeque<Tile> *_pDeqTiles,
                                      std::mutex            *_pTileMutex,
                                      condition_variable    *_pCvTile) override;

}; // class CmdBase4EqualTiles
