/*******************************************************************************
* \file aChannel.h
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
#include "aLib_def.h"
#include "aMath_def.h"

#include "aDimension2D.h"

using namespace aLib::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aPic {


/*******************************************************************************
* class aChannel
*******************************************************************************/
template <class T>
class aChannel
{
    friend class aLayerRgb8;

    private:
        T           *m_pData                { nullptr };
        s32         m_s32W                  { 0 };		// width of the aChannel
        s32         m_s32H                  { 0 };		// height of the aChannel
        u64         m_u64ChannelSize_byte   { 0 };

    public:
        aChannel(const aDimension2D<s32> &_d2d);

        aChannel(s32	_w,
                 s32    _h);

        aChannel(const aChannel &_rhs);

        virtual ~aChannel();

        void            clear();

        void            copyFromChannel(const std::unique_ptr<aChannel> &_pChannel);

        void            setChannelValue(T _tVal); // !!! slow
}; // class aChannel


} // namespace aPic
} // namespace aLib

#include "aChannel.inl"
