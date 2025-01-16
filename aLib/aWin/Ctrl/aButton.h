/*******************************************************************************
* \file aButton.h
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



/*******************************************************************************
* includes
*******************************************************************************/
#include "aWin/aWin_def.h"

#include "aWin/Ctrl/aCtrl.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aButton
*******************************************************************************/
class aButton : public aCtrl
{
    // DeclareTypeProperty(enumButtonStyle, e, ButtonStyle, enumButtonStyle::MASKED_MODE)
    // DeclareBoolProperty(Selectable, false)
    // DeclareBoolProperty(Selected, false)

    private:
        // unique_ptr<qPixmap>         m_pPixmap       { nullptr };


    public:
        aButton(aBaseWin    *_pParent,
                u32         _u32Id);
        virtual ~aButton();

        // qPixmap*                GetPixmap() const;
        // void                    SetPixmap(const char    *_pRscName);


    /*******************************************************************************
    * qWin interface
    *******************************************************************************/
    public:
        virtual bool            onSysCreate() override;

}; // class aButton


} // namespace aWin
} // namespace aLib
