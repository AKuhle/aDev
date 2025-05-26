/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include <QPushButton>
#include "aButton.h"
#include "aPushButtonI.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aPushButton
*******************************************************************************/
class aPushButton : public aButton<QPushButton>,
                    public aPushButtonI
{
    Q_OBJECT

    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    public:
        aPushButton(SysWin *_pParent);
        virtual ~aPushButton();

        void            setText(const aString &_sText);
        void            setText(const QString &_sText);

        void            setBackgroundColor(const aColor &_color);
        aColor          backgroundColor() const;


    /*******************************************************************************
    * slots
    *******************************************************************************/
    private slots:
        void            slotClicked(bool _bChecked);

}; // class aPushButtonI


} // namespace aWin
} // namespace aLib


#endif //_USE_QT_
