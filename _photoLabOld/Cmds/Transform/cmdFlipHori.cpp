/*******************************************************************************
* \file cmdFlipHori.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "photoLab_defs.h"
#include "cmdFlipHori.h"
#include "aLayer_i.h"
#include "aColor.h"



/*******************************************************************************
* CmdFlipHori::CmdFlipHori
*******************************************************************************/
CmdFlipHori::CmdFlipHori(shared_ptr<SynchronizedLS> _pPreLS,
                         aProgressCb                *_pProgressCb /*= nullptr*/)
: CmdBase4EqualTiles(ID_IMAGE_FLIP_HORI,  "Flip Horizontally", enumCmdType::CMD_TYPE_UNDO, _pPreLS, _pProgressCb)
{
} // CmdFlipHori::CmdFlipHori


/*******************************************************************************
* CmdFlipHori::~CmdFlipHori
*******************************************************************************/
CmdFlipHori::~CmdFlipHori()
{
} // CmdFlipHori::~CmdFlipHoriB


/*******************************************************************************
* CmdFlipHori::calculateTile
*******************************************************************************/
bool CmdFlipHori::calculateTile(Tile *_pTile)
{
    // get the tile parameter
    const aLayerI   *pPre       = _pTile->preLayer();
    aLayerI         *pPost      = _pTile->postLayer();
    CHECK_PRE_CONDITION(pPre != nullptr && pPost != nullptr, false);

    s32				s32PostMinX	= _pTile->minX();
    s32				s32PostMinY = _pTile->minY();
    s32				s32PostMaxX = _pTile->maxX();
    s32				s32PostMaxY	= _pTile->maxY();
    s32             s32PreW     = pPre->w() - 1;

    aColor          pix;

    // iter over all rows
    for (s32 y = s32PostMinY; y <= s32PostMaxY; y++)
    {
        // invert the pixels in the buffer for this current row
        for (s32 x = s32PostMinX; x <= s32PostMaxX; x++)
        {
            pPre->pixel(s32PreW - x, y, pix);

            pPost->setPixel(x, y, pix);
        } // for...

    } // for (s32Row....

    return true;
} // CmdFlipHori::calculateTile
