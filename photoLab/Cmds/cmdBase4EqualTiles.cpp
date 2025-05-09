/*******************************************************************************
* \file cmdBase4EqualTiles.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "cmdBase4EqualTiles.h"
#include "tile.h"
#include "aLayer_i.h"



/*******************************************************************************
* CmdBase4EqualTiles::CmdBase4EqualTiles
*******************************************************************************/
CmdBase4EqualTiles::CmdBase4EqualTiles(s32                          _s32CmdID,
                                       const aString                &_sCmdName,
                                       enumCmdType                  _eCmdType,
                                       shared_ptr<SynchronizedLS>   _pPreLS,
                                       aProgressCb                  *_pProgressCb)
: CmdBase4Tiles(_s32CmdID, _sCmdName, _eCmdType, _pPreLS, _pProgressCb)
{
} // CmdBase4EqualTiles::CmdBase4EqualTiles


/*******************************************************************************
* CmdBase4EqualTiles::onCreateTiles
*******************************************************************************/
bool CmdBase4EqualTiles::onCreateTiles(aUniquePtrDeque<Tile>            &_dequeTiles,
                                       const shared_ptr<LayerStack>     &_pPreLS,
                                       shared_ptr<LayerStack>           &_pPostLS)
{
    // the layers must exist
    CHECK_PRE_CONDITION(_pPreLS != nullptr, false);
    CHECK_PRE_CONDITION(_pPostLS != nullptr, false);

    const s32   s32Parts = sqrt(aUtil::hardwareConcurrency()) + 1;

    for (s32 i = 0; i < _pPreLS->size(); i++)
    {
        const s32   s32TileMinSize  = 50;
        aLayerI     *pPre           = _pPreLS->at(i).get();
        aLayerI     *pPost          = _pPostLS->at(i).get();

        // minimum tilesize is s32TileSize x s32TileSize pixel or max w/h to avoid a huge number of threads with just few pixels
        s32         s32PostW		= pPost->w();
        s32         s32PostH		= pPost->h();
        s32         s32TileW		= aUtil::min<s32>(aUtil::max<s32> (s32PostW / s32Parts, s32TileMinSize), s32PostW);
        s32         s32TileH		= aUtil::min<s32>(aUtil::max<s32> (s32PostH / s32Parts, s32TileMinSize), s32PostH);
        s32         s32DoneW		= 0;
        s32         s32DoneH		= 0;

        while (s32DoneH < s32PostH)
        {
            // last tile may be smaller
            s32 s32CurrentTileH = aUtil::min<s32>(s32PostH - s32DoneH, s32TileH);

            s32DoneW = 0;
            while (s32DoneW < s32PostW)
            {
                // last tile may be smaller
                s32 s32CurrentTileW = aUtil::min<s32>(s32PostW - s32DoneW, s32TileW);

                unique_ptr<Tile> pTile = make_unique<Tile> (pPre, pPost,
                                                            aRect2D<s32>(s32DoneW, s32DoneH,
                                                                         s32CurrentTileW, s32CurrentTileH));

                // add the next tile to the deque
                {
                    _dequeTiles.push_back(std::move(pTile));
                }

                // next tile col
                s32DoneW += s32CurrentTileW;
            }

            // next tile row
            s32DoneH += s32CurrentTileH;
        }
    } // for...

    return true;
} // CmdBase4EqualTiles::onCreateTiles
