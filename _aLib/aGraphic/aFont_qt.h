/*******************************************************************************
* \file aFontQt.h
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
#include <QFont>

#include "aGraphic/aGraphic_def.h"
#include "aWin/aWin_def.h"

#include "aUtil/aString.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aGraphic {
namespace SysQt {


/*******************************************************************************
* forwards
*******************************************************************************/
class qRgba;


/*******************************************************************************
* class aFontQt
*******************************************************************************/
class aFontQt : private QFont
{
    friend class aLib::aWin::SysQt::aSysWinQt;
    friend class aLib::aGraphic::SysQt::aPainterQt;

    public:
        aFontQt();

        aFontQt(const QFont &_font);

        aFontQt(const aString   &_sFamily,
                 s32            _s32PointSize,
                 enumFontWeight _eWeight,
                 bool           _bItalic);

        virtual ~aFontQt();

        void                setPointSize(s32 _s32PointSize);
        void                setBold(bool _bBold);
}; // class aFontQt


} // namespace SysQt
} // namespace aGraphic
} // namespace aLib

#endif // _USE_QT_
