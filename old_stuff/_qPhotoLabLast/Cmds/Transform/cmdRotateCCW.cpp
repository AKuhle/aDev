/*******************************************************************************
* \file cmdRotateCCW.h
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
#include "cmdRotateCCW.h"
#include "tile.h"



/*******************************************************************************
* CmdRotateCCW::CmdRotateCCW
*******************************************************************************/
CmdRotateCCW::CmdRotateCCW(shared_ptr<qLayerStack>  _pPreLS,
                           qProgress                *_pProgress)
: CmdBase4EqualTiles(ID_ROTATE_CCW,  "Rotate counter-clockwise", enumCmdType::CMD_TYPE_UNDO, _pPreLS, _pProgress)
{
} // CmdRotateCCW::CmdRotateCCW


/*******************************************************************************
* CmdRotateCCW::~CmdRotateCCW
*******************************************************************************/
CmdRotateCCW::~CmdRotateCCW()
{
} // CmdRotateCCW::~CmdRotateCCW


/*******************************************************************************
* CmdRotateCCW::Prepare
*******************************************************************************/
bool CmdRotateCCW::Prepare()
{
    // swap w/h instead of a 1:1 copy without imagae data, as done in the bas class
    if (m_pPreLS != nullptr)
    {
        m_pPostLS = m_pPreLS->CreateCloneSwapWH(true);
    }

    return true;
} // CmdRotateCCW::Prepare


/*******************************************************************************
* CmdRotateCCW::CalculateTile
*******************************************************************************/
bool CmdRotateCCW::CalculateTile(Tile *_pTile)
{
    // get the tile parameter
    const qLayerI   *pPre       = _pTile->PreLayer();
    qLayerI         *pPost      = _pTile->PostLayer();
    CHECK_PRE_CONDITION(pPre != nullptr && pPost != nullptr, false)

    s32				s32PostMinX	= _pTile->MinX();
    s32				s32PostMinY = _pTile->MinY();
    s32				s32PostMaxX = _pTile->MaxX();
    s32				s32PostMaxY	= _pTile->MaxY();
    s32             s32PreW     = pPre->w() - 1;

    qLib::qRgba     rgba;


    // iter over all rows
    for (s32 y = s32PostMinY; y <= s32PostMaxY; y++)
    {
        // invert the pixels in the buffer for this current row
        for (s32 x = s32PostMinX; x <= s32PostMaxX; x++)
        {
            pPre->Pixel(s32PreW - y, x, rgba);

            pPost->SetPixel(x, y, rgba);
        } // for...

    } // for (s32Row....

    return true;
} // CmdRotateCCW::CalculateTile
