/*******************************************************************************
* \file qSlider.cpp
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
#include "qSlider.h"


namespace qLib
{
    /*******************************************************************************
    * qSlider::qSlider
    *******************************************************************************/
    qSlider::qSlider(SysWin_t *_pParent /*= nullptr*/)
    : qSysWin<QSlider>(_pParent)
    {
        connect(this, SIGNAL(sliderMoved(int)),
                this, SLOT(SlotSliderMoved(int)));
    } // qSlider::qSlider


    /*******************************************************************************
    * qSlider::~qSlider
    *******************************************************************************/
    qSlider::~qSlider()
    {
    } // qSlider::~qSlider


    /*******************************************************************************
    * qSlider::SetOrientation
    *******************************************************************************/
    void qSlider::SetOrientation(enumOrientation  _eOrientation)
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
    } // qSlider::SetOrientation


    /*******************************************************************************
    * qSlider::Orientation
    *******************************************************************************/
    enumOrientation qSlider::Orientation() const
    {
        if (orientation() == Qt::Orientation::Horizontal)
        {
            return enumOrientation::Horizontal;
        }
        else
        {
            return enumOrientation::Vertical;
        }
    } // qSlider::Orientation


    /*******************************************************************************
    * qSlider::SetRange
    *******************************************************************************/
    void qSlider::SetRange(s32    _s32Min,
                           s32    _s32Max)
    {
        setRange(_s32Min, _s32Max);
    } // qSlider::SetRange


    /*******************************************************************************
    * qSlider::SetValue
    *******************************************************************************/
    void qSlider::SetValue(s32 _s32Value)
    {
        setValue(_s32Value);
    } // qSlider::SetValue


    /*******************************************************************************
    * qSlider::Value
    *******************************************************************************/
    s32 qSlider::Value() const
    {
       return value();
    } // qSlider::Value


    /*******************************************************************************
    * qSlider::SetCtrlEnabled
    *******************************************************************************/
    void qSlider::SetCtrlEnabled(bool _bEnabled)
    {
        setEnabled(_bEnabled);
    } // qSlider::SetCtrlEnabled


    /*******************************************************************************
    * qSlider::IsCtrlEnabled
    *******************************************************************************/
    bool qSlider::IsCtrlEnabled() const
    {
        return isEnabled();
    } // qSlider::IsCtrlEnabled


    /*******************************************************************************
    * qSlider::SlotSliderMoved
    *******************************************************************************/
    void qSlider::SlotSliderMoved(int _iValue)
    {
        if (CtrlMgr() != nullptr)
        {
            CtrlMgr()->OnCtrlMessage(this, MsgSliderMoved, _iValue);
        }

    } // qSlider::SlotSliderMoved

} // namespace qLib

#endif // _USE_QT_
