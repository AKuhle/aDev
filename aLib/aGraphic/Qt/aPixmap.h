/*******************************************************************************
* \file aPixmap.h
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


/*******************************************************************************
* includes
*******************************************************************************/
#include <QPixmap>

#include "aUtil_def.h"
#include "aWin_def.h"
#include "aPixmapI.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {


/*******************************************************************************
* class aPixmap
*******************************************************************************/
class aPixmap : private QPixmap,
                public aPixmapI
{
    friend class aPainter;

    public:
        aPixmap();
        aPixmap(const QPixmap &_lhs);
        aPixmap(const aString &_sFileName);
        virtual ~aPixmap();


    /*******************************************************************************
    * aPixmapI interface
    *******************************************************************************/
    public:
        bool                isValid() const override;
        void                scale(s32    _s32W,
                                  s32    _s32H) override;
}; // aPixmap


} // namespace aGraphic
} // namespace aLib

#endif // _USE_QT_
