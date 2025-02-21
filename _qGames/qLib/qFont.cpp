/*******************************************************************************
* \file qFont.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "qFont.h"



namespace qLib
{
    /*******************************************************************************
    * qFont::qFont
    *******************************************************************************/
    qFont::qFont(qString16         _sFamily,
                 s32               _s32PointSize    /*= 12*/,
                 enumFontWeight    _eWeight         /*= enumFontWeight::Normal*/,
                 bool              _bItalic         /*= false*/)
    : QFont(_sFamily.ToQString(), _s32PointSize)
	{
        switch (_eWeight)
        {
            case enumFontWeight::Thin:
                setWeight(QFont::Thin);
                break;

            case enumFontWeight::ExtraLight:
                setWeight(QFont::ExtraLight);
                break;

            case enumFontWeight::Light:
                setWeight(QFont::Light);
                break;

            case enumFontWeight::Normal:
                setWeight(QFont::Normal);
                break;

            case enumFontWeight::Medium:
                setWeight(QFont::Medium);
                break;

            case enumFontWeight::DemiBold:
                setWeight(QFont::DemiBold);
                break;

            case enumFontWeight::Bold:
                setWeight(QFont::Bold);
                break;

            case enumFontWeight::ExtraBold:
                setWeight(QFont::ExtraBold);
                break;

            case enumFontWeight::Black:
                setWeight(QFont::Black);
                break;
        } // switch (_eWeight)

        setItalic(_bItalic);
    } // qFont::qFont


    /*******************************************************************************
    * qFont::qFont
    *******************************************************************************/
    qFont::qFont(const qFont &_font)
    : QFont(_font)
    {
    } // qFont::qFont


    /*******************************************************************************
    * qFont::qFont
    *******************************************************************************/
    qFont::qFont()
    : QFont()
    {
    } // qFont::qFont


    /*******************************************************************************
    * qFont::~qFont
    *******************************************************************************/
    qFont::~qFont()
	{
    } // qFont::~qFont


    /*******************************************************************************
    * qFont::SetFont
    *******************************************************************************/
    void qFont::SetFont(const QFont &_font)
    {
        QFont::operator=(_font);
    } // qFont::SetFont


    /*******************************************************************************
    * qFont::operator=
    *******************************************************************************/
    qFont& qFont::operator=(const qFont &_font)
    {
        QFont::operator=(_font);

        return *this;
    } // operator=


    /*******************************************************************************
    * qFont::GetFamily
    *******************************************************************************/
    qString16 qFont::GetFamily() const
    {
        return qString16::FromQString(family());
    } // qFont::GetFamily


    /*******************************************************************************
    * qFont::SetPointSize
    *******************************************************************************/
    void qFont::SetPointSize(s32 _s32PointSize)
    {
        setPointSize(_s32PointSize);
    } // qFont::SetPointSize


    /*******************************************************************************
    * qFont::SetPixelSize
    *******************************************************************************/
    void qFont::SetPixelSize(s32 _s32PixelSize)
    {
        setPixelSize(_s32PixelSize);
    } // qFont::SetPixelSize


    /*******************************************************************************
    * qFont::SetBold
    *******************************************************************************/
    void qFont::SetBold(bool _bBold)
    {
        setBold(_bBold);
    } // qFont::SetBold


    /*******************************************************************************
    * qCursor::ToQFont
    *******************************************************************************/
    const QFont& qFont::ToQFont() const
    {
        return *this;
    } // qCursor::ToQFont


    /*******************************************************************************
    * qCursor::ToQFont
    *******************************************************************************/
    QFont& qFont::ToQFont()
    {
        return *this;
    } // qCursor::ToQFont

} // namespace qLib
