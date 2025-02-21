/*******************************************************************************
* \file qCursor.cpp
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
#include "qCursor.h"



namespace qLib
{
    /*******************************************************************************
    * qCursor::qCursor
    *******************************************************************************/
    qCursor::qCursor(enumCursorShape _eCursorShape)
	{
        switch (_eCursorShape)
        {
            case enumCursorShape::Arrow:        setShape(Qt::ArrowCursor);          break;
            case enumCursorShape::Cross:        setShape(Qt::CrossCursor);          break;
            case enumCursorShape::Wait:         setShape(Qt::WaitCursor);           break;
            case enumCursorShape::IBeam:        setShape(Qt::IBeamCursor);          break;
            case enumCursorShape::SizeVer:      setShape(Qt::SizeVerCursor);        break;
            case enumCursorShape::SizeHor:      setShape(Qt::SizeHorCursor);        break;
            case enumCursorShape::Size_TL_BR:   setShape(Qt::SizeFDiagCursor);      break;
            case enumCursorShape::Size_TR_BL:   setShape(Qt::SizeBDiagCursor);      break;
            case enumCursorShape::PointingHand: setShape(Qt::PointingHandCursor);   break;
            case enumCursorShape::OpenHand:     setShape(Qt::OpenHandCursor);       break;
            case enumCursorShape::ClosedHand:   setShape(Qt::ClosedHandCursor);     break;
            case enumCursorShape::Busy:         setShape(Qt::BusyCursor);           break;
        } // switch (_eCursorShape)
    } // qCursor::qCursor


    /*******************************************************************************
    * qCursor::~qCursor
    *******************************************************************************/
    qCursor::~qCursor()
    {
    } // qCursor::~qCursor


    /*******************************************************************************
    * qCursor::ToQCursor
    *******************************************************************************/
    const QCursor& qCursor::ToQCursor() const
    {
        return *this;
    } // qCursor::ToQCursor


    /*******************************************************************************
    * qCursor::ToQCursor
    *******************************************************************************/
    QCursor& qCursor::ToQCursor()
	{
        return *this;
    } // qCursor::ToQCursor

} // namespace qLib


#endif // _USE_QT_
