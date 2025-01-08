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
#include "defsPl.h"
#include "cmdRotateCW.h"
#include "tile.h"



/*******************************************************************************
* CmdRotateCW::CmdRotateCW
*******************************************************************************/
CmdRotateCW::CmdRotateCW(shared_ptr<qLayerStack>  _pPreLS,
                         qProgress                *_pProgress)
: CmdBase4EqualTiles(ID_ROTATE_CW,  "Rotate clockwise", enumCmdType::CMD_TYPE_UNDO, _pPreLS, _pProgress)
{
} // CmdRotateCW::CmdRotateCW


/*******************************************************************************
* CmdRotateCW::~CmdRotateCW
*******************************************************************************/
CmdRotateCW::~CmdRotateCW()
{
} // CmdRotateCW::~CmdRotateCW


/*******************************************************************************
* CmdRotateCW::Prepare
*******************************************************************************/
bool CmdRotateCW::Prepare()
{
    // swap w/h instead of a 1:1 copy without imagae data, as done in the bas class
    if (m_pPreLS != nullptr)
    {
        m_pPostLS = m_pPreLS->CreateCloneSwapWH(true);
    }

    return true;
} // CmdRotateCW::Prepare


/*******************************************************************************
* CmdRotateCW::CalculateTile
*******************************************************************************/
bool CmdRotateCW::CalculateTile(Tile *_pTile)
{
    // get the tile parameter
    const qLayerI   *pPre       = _pTile->PreLayer();
    qLayerI         *pPost      = _pTile->PostLayer();
    CHECK_PRE_CONDITION(pPre != nullptr && pPost != nullptr, false)

    s32				s32PostMinX	= _pTile->MinX();
    s32				s32PostMinY = _pTile->MinY();
    s32				s32PostMaxX = _pTile->MaxX();
    s32				s32PostMaxY	= _pTile->MaxY();
    s32             s32PreH     = pPre->h() - 1;

    qLib::qRgba     rgba;


    // iter over all rows
    for (s32 y = s32PostMinY; y <= s32PostMaxY; y++)
    {
        // invert the pixels in the buffer for this current row
        for (s32 x = s32PostMinX; x <= s32PostMaxX; x++)
        {
            pPre->Pixel(y, s32PreH - x, rgba);

            pPost->SetPixel(x, y, rgba);
        } // for...

    } // for (s32Row....

    return true;
} // CmdRotateCW::CalculateTile
