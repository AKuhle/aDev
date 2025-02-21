/*******************************************************************************
* \file cmdRotate180.h
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
#include "cmdRotate180.h"
#include "aLayer_i.h"
#include "aColor.h"



/*******************************************************************************
* CmdRotate180::CmdRotate180
*******************************************************************************/
CmdRotate180::CmdRotate180(shared_ptr<SynchronizedLS>   _pPreLS,
                           aProgressCb                  *_pProgressCb /*= nullptr*/)
: CmdBase4EqualTiles(ID_IMAGE_ROTATE_180,  "Rotate 180°", enumCmdType::CMD_TYPE_UNDO, _pPreLS, _pProgressCb)
{
} // CmdRotate180::CmdRotate180


/*******************************************************************************
* CmdRotate180::~CmdRotate180
*******************************************************************************/
CmdRotate180::~CmdRotate180()
{
} // CmdRotate180::~CmdRotate180


/*******************************************************************************
* CmdRotate180::calculateTile
*******************************************************************************/
bool CmdRotate180::calculateTile(Tile *_pTile)
{
    // get the tile parameter
    const aLayerI   *pPre       = _pTile->preLayer();
    aLayerI         *pPost      = _pTile->postLayer();
    CHECK_PRE_CONDITION(pPre != nullptr && pPost != nullptr, false)

    s32             s32PostMinX	= _pTile->minX();
    s32             s32PostMinY = _pTile->minY();
    s32             s32PostMaxX = _pTile->maxX();
    s32             s32PostMaxY	= _pTile->maxY();
    s32             s32PreW     = pPre->w() - 1;
    s32             s32PreH     = pPre->h() - 1;

    aColor          pix;


    // iter over all rows
    for (s32 y = s32PostMinY; y <= s32PostMaxY; y++)
    {
        // invert the pixels in the buffer for this current row
        for (s32 x = s32PostMinX; x <= s32PostMaxX; x++)
        {
            pPre->pixel(x, y, pix);
            pPost->setPixel(s32PreW - x, s32PreH - y, pix);
        } // for...

    } // for (s32Row....

    return true;
} // CmdRotate180::calculateTile
