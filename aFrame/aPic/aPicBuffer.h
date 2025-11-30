/*******************************************************************************
* \file mathDefs.h
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
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "aPic_def.h"
#include "aDimension.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aPic {


/*******************************************************************************
* const
*******************************************************************************/


/*******************************************************************************
* macros
*******************************************************************************/


/*******************************************************************************
* class aPicBuffer
*******************************************************************************/
class aPicBuffer
{
    protected:
        enumPicBufferFormat m_ePicBufferFormat      { enumPicBufferFormat::None };
        s32                 m_s32W                  { 0 };
        s32                 m_s32H                  { 0 };
        s32                 m_s32RowSize            { 0 };
        unsigned char       *m_pData                { nullptr };
        s32                 s32MaxSize              { 0 };


    public:
        aPicBuffer(enumPicBufferFormat  _ePicBufferFormat);

        virtual ~aPicBuffer();

        void                    setSize(s32 _s32W,
                                        s32 _s32H);

        enumPicBufferFormat     picBufferFormat() const { return m_ePicBufferFormat; }
        s32                     w() const               { return m_s32W; }
        s32                     h() const               { return m_s32H; }
        s32                     rowSize() const         { return m_s32RowSize; }
        unsigned char*          dats()                  { return m_pData; }
        const unsigned char*    dats() const            { return m_pData; }

}; // class aPicBuffer


} // namespace aPic
} // namespace aFrame
