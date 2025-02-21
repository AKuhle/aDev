/*******************************************************************************
* \file qFont.cpp
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
#include "qFont.h"



namespace qLib
{
    /*******************************************************************************
    * qFont::qFont
    *******************************************************************************/
    qFont::qFont(qString16         _sFamily,
                 s32               _s32PointSize,
                 enumFontWeight    _eWeight,
                 bool              _bItalic)
    : QFont(_sFamily.ToQString(), _s32PointSize, -1, _bItalic)
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
    * qFont::operator=
    *******************************************************************************/
    qFont& qFont::operator=(const qFont &_font)
    {
        QFont::operator=(_font);

        return *this;
    } // operator=


    /*******************************************************************************
    * qFont::SetPointSize
    *******************************************************************************/
    void qFont::SetPointSize(s32 _s32PointSize)
    {
        setPointSize(_s32PointSize);
    } // SetPointSize


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


#endif // _USE_QT_
