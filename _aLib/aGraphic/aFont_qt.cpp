/*******************************************************************************
* \file aFontQt.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFont_qt.h"


namespace aLib {
namespace aGraphic {
namespace SysQt {


/*******************************************************************************
* aFontQt::aFontQt
*******************************************************************************/
aFontQt::aFontQt()
: QFont()
{
} // aFontQt::aFontQt


/*******************************************************************************
* aFontQt::aFontQt
*******************************************************************************/
aFontQt::aFontQt(const QFont &_font)
: QFont(_font)
{
} // aFontQt::aFontQt


/*******************************************************************************
* aFontQt::aFontQt
*******************************************************************************/
aFontQt::aFontQt(const aString    &_sFamily,
                   s32              _s32PointSize,
                   enumFontWeight   _eWeight,
                   bool             _bItalic)
: QFont(_sFamily.toQString(), _s32PointSize, -1, _bItalic)
{
    switch (_eWeight)
    {
        case enumFontWeight::Thin:
            setWeight(aFontQt::Thin);
            break;

        case enumFontWeight::ExtraLight:
            setWeight(aFontQt::ExtraLight);
            break;

        case enumFontWeight::Light:
            setWeight(aFontQt::Light);
            break;

        case enumFontWeight::Normal:
            setWeight(aFontQt::Normal);
            break;

        case enumFontWeight::Medium:
            setWeight(aFontQt::Medium);
            break;

        case enumFontWeight::DemiBold:
            setWeight(aFontQt::DemiBold);
            break;

        case enumFontWeight::Bold:
            setWeight(aFontQt::Bold);
            break;

        case enumFontWeight::ExtraBold:
            setWeight(aFontQt::ExtraBold);
            break;

        case enumFontWeight::Black:
            setWeight(aFontQt::Black);
            break;
    } // switch (_eWeight)
} // aFontQt::aFontQt


/*******************************************************************************
* aFontQt::~aFontQt
*******************************************************************************/
aFontQt::~aFontQt()
{
} // aFontQt::~aFontQt


/*******************************************************************************
* aFontQt::setPointSize
*******************************************************************************/
void aFontQt::setPointSize(s32 _s32PointSize)
{
    aFontQt::setPointSize(_s32PointSize);
} // setPointSize


/*******************************************************************************
* aFontQt::setBold
*******************************************************************************/
void aFontQt::setBold(bool _bBold)
{
    aFontQt::setBold(_bBold);
} // aFontQt::setBold


} // namespace SysQt
} // namespace aGraphic
} // namespace aLib

#endif // _USE_QT_
