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


/*******************************************************************************
* includes
*******************************************************************************/
#include <QJsonObject>
#include "qString16.h"
#include "qUniquePtrVec.h"
#include "qVec.h"
#include "qColor.h"


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

            bool            m_bIsDbl        { false };
            dbl             m_dblValue      { 0 };

            bool            m_bIsColor      { false };
            qColor          m_colValue;

            bool            m_bIsString     { false };
            qString16       m_sValue;

    public:
            qJsonValue(qString16    _sKey,
                       bool         _bValue);

            qJsonValue(qString16    _sKey,
                       s32          _s32Value);

            qJsonValue(qString16    _sKey,
                       dbl          _dblValue);

            qJsonValue(qString16    _sKey,
                       const qColor &_colValue);

            qJsonValue(qString16        _sKey,
                       const qString16  &_sValue);

            virtual ~qJsonValue();

            const qString16&        Key() const;

            bool                    IsBool() const;
            bool                    ToBool() const;

            bool                    IsS32() const;
            s32                     ToS32() const;

            bool                    IsDbl() const;
            dbl                     ToDbl() const;

            bool                    IsColor() const;
            qColor                  ToColor() const;

            bool                    IsString() const;
            qString16               ToString() const;
    }; // class qJsonValueI

} // namespace qLib
