/*******************************************************************************
* \file qScrollBar.cpp
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
#include "qScrollBar.h"


namespace qLib
{
    /*******************************************************************************
    * qScrollBar::qScrollBar
    *******************************************************************************/
    qScrollBar::qScrollBar(enumOrientation  _eOrientation,
                           SysWin_t         *_pParent /*= nullptr*/)
    : qSysWin<QScrollBar>(_pParent)
    {
        SetOrientation(_eOrientation);

        connect(this, SIGNAL(valueChanged(int)),
                this, SLOT(SlotValueChanged(int)));
    } // qScrollBar::qScrollBar


    /*******************************************************************************
    * qScrollBar::~qScrollBar
    *******************************************************************************/
    qScrollBar::~qScrollBar()
    {
    } // qScrollBar::~qScrollBar


    /*******************************************************************************
    * qScrollBar::SetOrientation
    *******************************************************************************/
    void qScrollBar::SetOrientation(enumOrientation  _eOrientation)
    {
        switch (_eOrientation)
        {
            case enumOrientation::Horizontal:
                setOrientation(Qt::Orientation::Horizontal);
                break;

            case enumOrientation::Vertical:
                setOrientation(Qt::Orientation::Vertical);
                break;
        } // switch (_eOrientation)
    } // qScrollBar::SetOrientation


    /*******************************************************************************
    * qScrollBar::Orientation
    *******************************************************************************/
    enumOrientation qScrollBar::Orientation() const
    {
        if (orientation() == Qt::Orientation::Horizontal)
        {
            return enumOrientation::Horizontal;
        }
        else
        {
            return enumOrientation::Vertical;
        }
    } // qScrollBar::Orientation


    /*******************************************************************************
    * qScrollBar::SetRange
    *******************************************************************************/
    void qScrollBar::SetRange(s32    _s32Min,
                              s32    _s32Max)
    {
        setRange(_s32Min, _s32Max);
    } // qScrollBar::SetRange


    /*******************************************************************************
    * qScrollBar::SetValue
    *******************************************************************************/
    void qScrollBar::SetValue(s32 _s32Value)
    {
        setValue(_s32Value);
    } // qScrollBar::SetValue


    /*******************************************************************************
    * qScrollBar::Value
    *******************************************************************************/
    s32 qScrollBar::Value() const
    {
       return value();
    } // qScrollBar::Value


    /*******************************************************************************
    * qScrollBar::SetCtrlEnabled
    *******************************************************************************/
    void qScrollBar::SetCtrlEnabled(bool _bEnabled)
    {
        setEnabled(_bEnabled);
    } // qScrollBar::SetCtrlEnabled


    /*******************************************************************************
    * qScrollBar::IsCtrlEnabled
    *******************************************************************************/
    bool qScrollBar::IsCtrlEnabled() const
    {
        return isEnabled();
    } // qScrollBar::IsCtrlEnabled


    /*******************************************************************************
    * qScrollBar::SlotValueChanged
    *******************************************************************************/
    void qScrollBar::SlotValueChanged(int /*_iValue*/)
    {
        if (CtrlMgr() != nullptr)
        {
            CtrlMgr()->OnCtrlMessage(this, MsgValueChanged);
        }

    } // qScrollBar::SlotValueChanged

} // namespace qLib

#endif // _USE_QT_

