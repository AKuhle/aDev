/*******************************************************************************
* \file cmdInvert.h
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
#include "cmdInvert.h"
#include "aLayer_i.h"
#include "aColor.h"



/*******************************************************************************
* CmdInvert::CmdInvert
*******************************************************************************/
CmdInvert::CmdInvert(shared_ptr<SynchronizedLS> _pPreLS,
                     aProgressCb                *_pProgressCb /*= nullptr*/)
: CmdBase4EqualTiles(ID_IMAGE_FLIP_INVERT,  "Invert Colors", enumCmdType::CMD_TYPE_UNDO, _pPreLS, _pProgressCb)
{
} // CmdInvert::CmdInvert


/*******************************************************************************
* CmdInvert::~CmdInvert
*******************************************************************************/
CmdInvert::~CmdInvert()
{
} // CmdInvert::~CmdInvert


/*******************************************************************************
* CmdInvert::calculateTile
*******************************************************************************/
bool CmdInvert::calculateTile(Tile *_pTile)
{
    // get the tile parameter
    const aLayerI   *pPre       = _pTile->preLayer();
    aLayerI         *pPost      = _pTile->postLayer();
    CHECK_PRE_CONDITION(pPre != nullptr && pPost != nullptr, false)

    s32				s32PostMinX	= _pTile->minX();
    s32				s32PostMinY = _pTile->minY();
    s32				s32PostMaxX = _pTile->maxX();
    s32				s32PostMaxY	= _pTile->maxY();

    aColor          pix;

    // iter over all rows
    for (s32 y = s32PostMinY; y <= s32PostMaxY; y++)
    {
        // invert the pixels in the buffer for this current row
        for (s32 x = s32PostMinX; x <= s32PostMaxX; x++)
        {
            pPre->pixel(x, y, pix);

            pix.invert();

            pPost->setPixel(x, y, pix);
        } // for...

    } // for (s32Row....

    return true;
} // CmdInvert::calculateTile
