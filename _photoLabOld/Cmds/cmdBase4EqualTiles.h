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
        CmdBase4EqualTiles(s32                          _s32CmdID,
                           const aString                &_sCmdName,
                           enumCmdType                  _eCmdType,
                           shared_ptr<SynchronizedLS>   _pPreLS,
                           aProgressCb                  *_pProgressCb);


    /*******************************************************************************
    * interface for CmdBase4Tiles
    *******************************************************************************/
    protected:
        bool            onCreateTiles(aUniquePtrDeque<Tile>         &_dequeTiles,
                                      const shared_ptr<LayerStack>  &_pPreLS,
                                      shared_ptr<LayerStack>        &_pPostLS) override;

}; // class CmdBase4EqualTiles
