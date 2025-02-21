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
#include "cmdBase.h"
#include "tile.h"

using namespace qLib;


/*******************************************************************************
* class CmdBase4Tiles
*******************************************************************************/
class CmdBase4Tiles : public CmdBase
{
    protected:
        qUniquePtrDeque<Tile>   m_deqTiles;
        std::mutex              m_tileMutex;
        condition_variable      m_cvTile;

        CmdBase4Tiles(s32                       _s32CmdID,
                      const qString16           &_sCmdName,
                      enumCmdType               _eCmdType,
                      shared_ptr<qLayerStack>   _pPreLS,
                      qProgress                 *_pProgress);


    /*******************************************************************************
    * interface for specialized classes
    *******************************************************************************/
    public:
        virtual bool    CalculateTile(Tile  *_pTile) = 0;

        virtual bool    OnCreateTiles(qUniquePtrDeque<Tile>     *_pDeqTiles,
                                      std::mutex                *_pTileMutex,
                                      condition_variable        *_pCvTile) = 0;


    /*******************************************************************************
    * interface of aCmdI
    *******************************************************************************/
    public:
        virtual bool    Do();

}; // class CmdBase4Tiles
