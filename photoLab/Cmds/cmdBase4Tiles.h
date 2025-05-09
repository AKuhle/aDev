/*******************************************************************************
* \file CmdBase4Tiles.h
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
#include "aLib_def.h"
#include "aUtil_def.h"

#include "aUniquePtrDeque.h"

#include "cmdBase.h"
#include "tile.h"

using namespace aLib::aUtil;

using SynchronizedTileDeque = aSynchronized<aUniquePtrDeque<Tile>>;
using ExclusiveTileDeque    = aExclusiveAccessor<SynchronizedTileDeque>;



/*******************************************************************************
* class CmdBase4Tiles
*******************************************************************************/
class CmdBase4Tiles : public CmdBase
{
    protected:
        SynchronizedTileDeque   m_syncDequeTiles;

        CmdBase4Tiles(s32                           _s32CmdID,
                      const aString                 &_sCmdName,
                      enumCmdType                   _eCmdType,
                      shared_ptr<SynchronizedLS>    _pPreLS,
                      aProgressCb                   *_pProgressCb);


    /*******************************************************************************
    * interface for specialized classes
    *******************************************************************************/
    public:
        virtual bool    calculateTile(Tile  *_pTile) = 0;

        virtual bool    onCreateTiles(aUniquePtrDeque<Tile>         &_dequeTiles,
                                      const shared_ptr<LayerStack>  &_pPreLS,
                                      shared_ptr<LayerStack>        &_pPostLS) = 0;


    /*******************************************************************************
    * interface of aCmdI
    *******************************************************************************/
    public:
        virtual bool    execute();

}; // class CmdBase4Tiles
