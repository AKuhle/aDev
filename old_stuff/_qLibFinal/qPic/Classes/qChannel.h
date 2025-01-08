/*******************************************************************************
* \file qChannel.h
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
#include "qBaseDefs.h"
#include "qDimension2D.h"


namespace qLib
{
    /*******************************************************************************
    * class qChannel
    *******************************************************************************/
    template <class T>
    class qChannel
    {
        friend class qLayerRgb8;

        private:
            T       *m_pData                { nullptr };
            s32		m_s32W                  { 0 };		// width of the qChannel
            s32		m_s32H                  { 0 };		// height of the qChannel
            u64     m_u64ChannelSize_byte   { 0 };

        public:
            qChannel(const qDimension2D<s32> &_d2d);

            qChannel(s32	_s32W,
                     s32    _s32H);

            qChannel(const qChannel &_rhs);

            virtual ~qChannel();

            void ClearChannel();

            void CopyFromChannel(const std::unique_ptr<qChannel> &_pChannel);

            void SetChannelValue(T _tVal);
    }; // class qChannel

} // namespace qLib

#include "qChannel.inl"
