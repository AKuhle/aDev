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
* thread for tile generation
*******************************************************************************/
void GenerateTiles(CmdBase4Tiles            *_pCmd,
                   qUniquePtrDeque<Tile>    *_pDeqTiles,
                   std::mutex               *_pTileMutex,
                   condition_variable       *_pCvTile)
{
    _pCmd->OnCreateTiles(_pDeqTiles, _pTileMutex, _pCvTile);

    // all tiles are calculated => push end-tile on stack and inform all
    unique_ptr<Tile> pEndTile = make_unique<Tile> (nullptr, nullptr, qRect2D<s32>());
    _pTileMutex->lock();
    _pDeqTiles->push_back(std::move(pEndTile));
    _pTileMutex->unlock();
    _pCvTile->notify_all();
} // GenerateTiles


/*******************************************************************************
* thread for one tile calculation
*******************************************************************************/
void CalcTile(CmdBase4Tiles         *_pCmd,
              qUniquePtrDeque<Tile> *_pDeqTiles,
              std::mutex            *_pTileMutex,
              condition_variable    *_pCvTile)
{
    while (true)
    {
        std::unique_lock<std::mutex>    uLock(*_pTileMutex);

        _pCvTile->wait(uLock, [&] { return _pDeqTiles->size() > 0; } );

        const unique_ptr<Tile> &pTile = _pDeqTiles->front();

        if (pTile->PostLayer() == nullptr)
        {
            // we found the last tile => finish this thread without deleting it from the
            // queue for the other tasks
            uLock.unlock();

            return;
        }
        else
        {
            // not the last tile => get it, remove it from the queue
            unique_ptr<Tile> pTile = _pDeqTiles->GetAndPopFront();
            uLock.unlock();

            _pCmd->CalculateTile(pTile.get());

        }
    } // while (true)
} // CalcTile


/*******************************************************************************
* CmdBase4Tiles::CmdBase4Tiles
*******************************************************************************/
CmdBase4Tiles::CmdBase4Tiles(s32                        _s32CmdID,
                             const qString16            &_sCmdName,
                             enumCmdType                _eCmdType,
                             shared_ptr<qLayerStack>    _pPreLS,
                             qProgress                  *_pProgress)
: CmdBase(_s32CmdID, _sCmdName, _eCmdType, _pPreLS, _pProgress)
{
} // CmdBase4Tiles::CmdBase4Tiles


/*******************************************************************************
* CmdBase4Tiles::Do
*******************************************************************************/
bool CmdBase4Tiles::Do()
{
    std::vector<unique_ptr<std::thread>>  lstThreads;

    // create the tiles
    std::thread generator{ GenerateTiles, this, &m_deqTiles, &m_tileMutex, &m_cvTile };

    for (u32 i = 0; i < qThread::HardwareConcurrency(); i++)
    {
        lstThreads.push_back(unique_ptr<std::thread> (new std::thread { CalcTile, this, &m_deqTiles, &m_tileMutex, &m_cvTile }));
    }

    // wait, until all worker threads have finished
    generator.join();
    for (unique_ptr<std::thread> &pT : lstThreads)
    {
        pT->join();
    }

    return true;
} // CmdBase4Tiles::Do
