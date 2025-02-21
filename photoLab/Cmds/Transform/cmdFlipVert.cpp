/*******************************************************************************
* \file cmdFlipVert.h
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
#include "cmdFlipVert.h"
#include "aLayer_i.h"
#include "aColor.h"



/*******************************************************************************
* CmdFlipVert::CmdFlipVert
*******************************************************************************/
CmdFlipVert::CmdFlipVert(shared_ptr<SynchronizedLS> _pPreLS,
                         aProgressCb                *_pProgressCb /*= nullptr*/)
: CmdBase4EqualTiles(ID_IMAGE_FLIP_VERT,  "Flip Vertically", enumCmdType::CMD_TYPE_UNDO, _pPreLS, _pProgressCb)
{
} // CmdFlipVert::CmdFlipVert


/*******************************************************************************
* CmdFlipVert::~CmdFlipVert
*******************************************************************************/
CmdFlipVert::~CmdFlipVert()
{
} // CmdFlipVert::~CmdFlipVert


/*******************************************************************************
* CmdFlipVert::calculateTile
*******************************************************************************/
bool CmdFlipVert::calculateTile(Tile *_pTile)
{
    // get the tile parameter
    const aLayerI   *pPre       = _pTile->preLayer();
    aLayerI         *pPost      = _pTile->postLayer();
    CHECK_PRE_CONDITION(pPre != nullptr && pPost != nullptr, false)

    s32				s32PostMinX	= _pTile->minX();
    s32				s32PostMinY = _pTile->minY();
    s32				s32PostMaxX = _pTile->maxX();
    s32				s32PostMaxY	= _pTile->maxY();
    s32             s32PreH     = pPre->h() - 1;

    aColor          pix;


    // iter over all rows
    for (s32 y = s32PostMinY; y <= s32PostMaxY; y++)
    {
        // invert the pixels in the buffer for this current row
        for (s32 x = s32PostMinX; x <= s32PostMaxX; x++)
        {
            pPre->pixel(x, y, pix);

            pPost->setPixel(x, s32PreH - y, pix);
        } // for...

    } // for (s32Row....

    return true;
} // CmdFlipVert::calculateTile
