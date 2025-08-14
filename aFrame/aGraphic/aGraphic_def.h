/*******************************************************************************
* \file qlBaseDefs.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aGraphic {


/*******************************************************************************
* enums
*******************************************************************************/
enum class enumCursorShape
{
    // standard cursors:
    ArrowCursor,          // Standard-Pfeil
    UpArrowCursor,        // Pfeil nach oben
    CrossCursor,          // Kreuz/Fadenkreuz
    WaitCursor,           // Sanduhr/Spinner (Warten)
    IBeamCursor,          // Text-Cursor (I-Balken)
    SizeVerCursor,        // Vertikale Größenänderung (↕)
    SizeHorCursor,        // Horizontale Größenänderung (↔)
    SizeBDiagCursor,      // Diagonale Größenänderung (/)
    SizeFDiagCursor,      // Diagonale Größenänderung (\)
    SizeAllCursor,        // Alle Richtungen (✛)
    BlankCursor,          // Unsichtbarer Cursor}; // enumCursorShape

    // interactive cursors:
    SplitVCursor,         // Vertikaler Splitter
    SplitHCursor,         // Horizontaler Splitter
    PointingHandCursor,   // Hand (klickbar)
    ForbiddenCursor,      // Verboten/Nicht erlaubt (🚫)
    WhatsThisCursor,      // Fragezeichen
    BusyCursor,           // Beschäftigt (Pfeil + Sanduhr)

    // extended cursors:
    OpenHandCursor,       // Offene Hand
    ClosedHandCursor,     // Geschlossene Hand (ziehen)
    DragCopyCursor,       // Drag & Drop Kopieren
    DragMoveCursor,       // Drag & Drop Verschieben
    DragLinkCursor        // Drag & Drop Verknüpfen
}; // enumCursorShape


enum class enumFontWeight
{
    Thin,
    ExtraLight,
    Light,
    Normal,
    Medium,
    DemiBold,
    Bold,
    ExtraBold,
    Black
}; // enumFontWeight


enum class enumAlignmentHori
{
    AlignLeft,
    AlignHCenter,
    AlignRight
}; // enumAlignmentHori


enum class enumAlignmentVert
{
    AlignTop,
    AlignVCenter,
    AlignBottom
}; // enumAlignmentVert


/*******************************************************************************
* classes
*******************************************************************************/
class aBrush;
class aPen;
class aPainter;
class aPixmap;
class aCursor;

} // namespace aGraphic
} // namespace aFrame
