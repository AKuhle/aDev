/*******************************************************************************
* \file cmdRotateCW.h
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
#include "cmdRotateCW.h"
#include "aLayer_i.h"
#include "aColor.h"



/*******************************************************************************
* CmdRotateCW::CmdRotateCW
*******************************************************************************/
CmdRotateCW::CmdRotateCW(shared_ptr<SynchronizedLS> _pPreLS,
                         aProgressCb                *_pProgressCb /*= nullptr*/)
: CmdBase4EqualTiles(ID_IMAGE_ROTATE_CW, "Rotate clockwise", enumCmdType::CMD_TYPE_UNDO, _pPreLS, _pProgressCb)
{
} // CmdRotateCW::CmdRotateCW


/*******************************************************************************
* CmdRotateCW::~CmdRotateCW
*******************************************************************************/
CmdRotateCW::~CmdRotateCW()
{
} // CmdRotateCW::~CmdRotateCW


/*******************************************************************************
* CmdRotateCW::prepare
*******************************************************************************/
bool CmdRotateCW::prepare()
{
    // swap w/h instead of a 1:1 copy without imagae data, as done in the bas class
    if (m_pPreLS != nullptr)
    {
        SharedLS        pPreLS(*m_pPreLS);

        m_pPostLS = make_shared<aSynchronized<shared_ptr<LayerStack>>> ();
        ExclusiveLS     pPostLS(*m_pPostLS);

        pPostLS.get() = make_shared<LayerStack> ();
        pPostLS.get()->createClone(pPreLS.get(), pPreLS.get()->h(), pPreLS.get()->w());
    }

    return true;
} // CmdRotateCW::prepare


/*******************************************************************************
* CmdRotateCW::calculateTile
*******************************************************************************/
bool CmdRotateCW::calculateTile(Tile *_pTile)
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
            pPre->pixel(y, s32PreH - x, pix);

            pPost->setPixel(x, y, pix);
        } // for...

    } // for (s32Row....

    return true;
} // CmdRotateCW::calculateTile
