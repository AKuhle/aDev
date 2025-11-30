/*******************************************************************************
* \file aPicBuffer.h
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/



/*******************************************************************************
* includes
*******************************************************************************/
#include "aPicBuffer.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aPic {


/*******************************************************************************
* aPicBuffer::aPicBuffer
*******************************************************************************/
aPicBuffer::aPicBuffer(enumPicBufferFormat  _ePicBufferFormat)
: m_ePicBufferFormat(_ePicBufferFormat)
{
} // aPicBuffer::aPicBuffer


/*******************************************************************************
* aPicBuffer::~aPicBuffer
*******************************************************************************/
aPicBuffer::~aPicBuffer()
{
    delete m_pData;
} // aPicBuffer::~aPicBuffer


/*******************************************************************************
* aPicBuffer::setSize
*******************************************************************************/
void aPicBuffer::setSize(s32 _s32W,
                         s32 _s32H)
{
    switch (m_ePicBufferFormat)
    {
        default:
            break;

        case enumPicBufferFormat::Format_RGB888:
            m_s32W          = _s32W;
            m_s32H          = _s32H;
            m_s32RowSize    = 3 * _s32W;
            break;
    }

    s32 s32BufSize = m_s32RowSize * m_s32H;

    // resize the buffer, if new size > max size
    if (s32BufSize > s32MaxSize)
    {
        s32MaxSize = s32BufSize;
        delete m_pData;
        m_pData = new unsigned char[s32MaxSize];
    }
} // aPicBuffer::setSize


} // namespace aPic
} // namespace aFrame
