/*******************************************************************************
* \file qJsonValue.h
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

#ifdef _USE_QT_

/*******************************************************************************
* includes
*******************************************************************************/
#include <QJsonObject>
#include "qString16.h"
#include "qUniquePtrVec.h"
#include "qVec.h"


namespace qLib
{
    /*******************************************************************************
    * class qJsonValue
    *******************************************************************************/
    class qJsonValue
    {
        private:
            qString16       m_sKey;

            bool            m_bIsBool       { false };
            bool            m_bValue        { false };

            bool            m_bIsS32        { false };
            s32             m_s32Value      { 0 };

        public:
            qJsonValue(qString16    _sKey,
                       bool         _bValue);

            qJsonValue(qString16    _sKey,
                       s32          _s32Value);

            virtual ~qJsonValue();

            const qString16&        Key() const;

            bool                    IsBool() const;
            bool                    ToBool() const;

            bool                    IsS32() const;
            s32                     ToS32() const;

    }; // class qJsonValueI

} // namespace qLib

#endif // _USE_QT_
