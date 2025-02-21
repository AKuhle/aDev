/*******************************************************************************
* \file qEdges.h
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


namespace qLib
{
    /*******************************************************************************
    * \class qEdges
    * \brief baseclass for 2D math objects
    *******************************************************************************/
    class qEdges
    {
    public:
            s32     l  { 0 };
            s32     r  { 0 };
            s32     t  { 0 };
            s32     b  { 0 };

        public:
            qEdges();

            qEdges(s32 _lrtb);

            qEdges(s32  _lr,
                   s32  _tb);

            qEdges(s32  _l,
                   s32  _r,
                   s32  _t,
                   s32  _b);

            virtual ~qEdges();

            void    Set(s32  _lrtb);

            void    Set(s32  _l,
                        s32  _r,
                        s32  _t,
                        s32  _b);

            s32     w() const;  // l + r
            s32     h() const;  // t + b
    }; // class qEdges

} // namespace qLib
