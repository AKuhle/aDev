/*******************************************************************************
* \file CmdBase4Tiles.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "cmdBase4Tiles.h"



/*******************************************************************************
* thread for one tile calculation
*******************************************************************************/
void calcTile(CmdBase4Tiles         *_pCmd,
              SynchronizedTileDeque *_pSyncDequeTiles)
{
    unique_ptr<Tile>    pTile;// = _pDeqTiles->getAndPopFront();

    while (true)
    {
        {
            pTile = nullptr;

            ExclusiveTileDeque deque(*_pSyncDequeTiles);

            if (!deque->empty())
            {
                const unique_ptr<Tile> &pFront = deque->front();

                if (pFront.get()->postLayer() == nullptr)
                {
                    // last element found => finish task
                    return;
                }
                else
                {
                    pTile = deque->getAndPopFront();
                }

            }
        }

        if (pTile != nullptr)
        {
            _pCmd->calculateTile(pTile.get());
            _pCmd->incrementProgress();
        }

    } // while (true)

} // calcTile


/*******************************************************************************
* CmdBase4Tiles::CmdBase4Tiles
*******************************************************************************/
CmdBase4Tiles::CmdBase4Tiles(s32                        _s32CmdID,
                             const aString              &_sCmdName,
                             enumCmdType                _eCmdType,
                             shared_ptr<SynchronizedLS> _pPreLS,
                             aProgressCb                *_pProgressCb)
: CmdBase(_s32CmdID, _sCmdName, _eCmdType, _pPreLS, _pProgressCb)
{
} // CmdBase4Tiles::CmdBase4Tiles


/*******************************************************************************
* CmdBase4Tiles::execute
*******************************************************************************/
bool CmdBase4Tiles::execute()
{
    SharedLS                                pPreLS(*m_pPreLS);
    ExclusiveLS                             pPostLS(*m_pPostLS);

    const shared_ptr<LayerStack>            &pPre = pPreLS.get();
    shared_ptr<LayerStack>                  &pPost = pPostLS.get();

    std::vector<unique_ptr<std::thread>>    lstThreads;

    {
        ExclusiveTileDeque deque(m_syncDequeTiles);

        // generate the tiles
        onCreateTiles(deque.get(), pPre, pPost);

        // add the end tile
        unique_ptr<Tile> pEndTile = make_unique<Tile> (nullptr, nullptr, aRect2D<s32>());
        deque->push_back(std::move(pEndTile));

        // open the display
        openDisplay(name(), 0, deque->size());
    }

    // generate the threads
    for (u32 i = 0; i < aUtil::hardwareConcurrency(); i++)
    {
        lstThreads.push_back(unique_ptr<std::thread> (new std::thread { calcTile, this, &m_syncDequeTiles }));
    }

    // wait, until all worker threads have finished
    for (unique_ptr<std::thread> &pT : lstThreads)
    {
        pT->join();
    }

    // close the progress display
    closeDisplay();

    return true;
} // CmdBase4Tiles::execute
