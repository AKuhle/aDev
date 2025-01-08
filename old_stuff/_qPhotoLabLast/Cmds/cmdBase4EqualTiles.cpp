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


using namespace qLib;



/*******************************************************************************
* CmdBase4EqualTiles::CmdBase4EqualTiles
*******************************************************************************/
CmdBase4EqualTiles::CmdBase4EqualTiles(s32                      _s32CmdID,
                                       const qString16          &_sCmdName,
                                       enumCmdType              _eCmdType,
                                       shared_ptr<qLayerStack>  _pPreLS,
                                       qProgress                *_pProgress)
: CmdBase4Tiles(_s32CmdID, _sCmdName, _eCmdType, _pPreLS, _pProgress)
{
} // CmdBase4EqualTiles::CmdBase4EqualTiles


/*******************************************************************************
* CmdBase4EqualTiles::OnCreateTiles
*******************************************************************************/
bool CmdBase4EqualTiles::OnCreateTiles(qUniquePtrDeque<Tile>     *_pDeqTiles,
                                       std::mutex                *_pTileMutex,
                                       condition_variable        *_pCvTile)
{
    const s32   s32Parts = sqrt(qThread::HardwareConcurrency()) + 1;

    for (const unique_ptr<qLayerI> &pPreLayer : *m_pPreLS)
    {
        // find the empty clone of the layer
        qLayerI *pPostLayer = m_pPostLS->FindLayer(pPreLayer->Id());

        // the layer must exist
        CHECK_PRE_CONDITION(pPostLayer != nullptr, false);

        const s32   s32TileMinSize  = 50;

        // minimum tilesize is s32TileSize x s32TileSize pixel or max w/h to avoid a huge number of threads with just few pixels
        s32         s32PostW		= pPostLayer->w();
        s32         s32PostH		= pPostLayer->h();
        s32         s32TileW		= Min(Max<s32> (s32PostW / s32Parts, s32TileMinSize), s32PostW);
        s32         s32TileH		= Min(Max<s32> (s32PostH / s32Parts, s32TileMinSize), s32PostH);
        s32         s32DoneW		= 0;
        s32         s32DoneH		= 0;

        while (s32DoneH < s32PostH)
        {
            // last tile may be smaller
            s32 s32CurrentTileH = min(s32PostH - s32DoneH, s32TileH);

            s32DoneW = 0;
            while (s32DoneW < s32PostW)
            {
                // last tile may be smaller
                s32 s32CurrentTileW = min(s32PostW - s32DoneW, s32TileW);

                unique_ptr<Tile> pTile = make_unique<Tile> (pPreLayer.get(), pPostLayer,
                                                            qRect2D<s32>(s32DoneW, s32DoneH,
                                                            s32CurrentTileW, s32CurrentTileH));

                // add the next tile to the deque
                _pTileMutex->lock();
                _pDeqTiles->push_back(std::move(pTile));
                _pTileMutex->unlock();
                _pCvTile->notify_one();

                // next tile col
                s32DoneW += s32CurrentTileW;
            }

            // next tile row
            s32DoneH += s32CurrentTileH;
        }
    } // for (const shared_ptr<qlLayer> &pPreLayer : *m_pPreLS)

    return true;
} // CmdBase4EqualTiles::OnCreateTiles
